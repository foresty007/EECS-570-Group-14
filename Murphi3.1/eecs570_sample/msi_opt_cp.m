-- MSI Directory Protocol (Corrected Version)
-- Based on Primer Chapter 8, Tables 8.1 and 8.2
-- Fixed: Directory transient states for forwarding, Inv source bug

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  ProcCount: 3;
  ValueCount: 2;
  VC0: 0;   -- request channel
  VC1: 1;   -- forward channel
  VC2: 2;   -- response channel
  NumVCs: VC2 - VC0 + 1;
  QMax: 2;
  NetMax: ProcCount+2;

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);
  Value: scalarset(ValueCount);
  Home: enum { HomeType };
  Node: union { Home, Proc };
  VCType: VC0..NumVCs-1;

  MessageType: enum {
    GetS,           -- Request shared copy
    GetM,           -- Request modified copy
    PutS,           -- Voluntary release of shared copy
    PutM,           -- Voluntary writeback of modified copy
    PutE,           -- Voluntary writeback of exclusive copy (not used in MSI)
    
    Data,           -- Data response
    Data_E,         -- Exclusive Data response 
    Fwd_GetS,       -- Forwarded GetS to owner
    Fwd_GetM,       -- Forwarded GetM to owner
    Fwd_GetM_A,     -- Forwarded GetM with Ack to directory
    Inv,            -- Invalidation request
    Put_Ack,        -- Acknowledgment for Put
    Inv_Ack         -- Acknowledgment for Invalidation
  };

  Message:
    Record
      mtype: MessageType;
      src: Node;
      vc: VCType;
      val: Value;
      ackCount: (1-ProcCount)..ProcCount-1;  -- For Data messages, number of acks expected, negative value indicates not arrived counts
    End;

  HomeState:
    Record
      state: enum {
        H_I,          -- Invalid (no cached copies)
        H_S,          -- Shared (one or more sharers)
        H_M,          -- Modified (one owner)
        H_E,          -- Exclusive 
        H_MtoS_D,     -- M->S, sent Fwd-GetS, waiting for Data from owner
        H_MtoM_A,     -- M->M, sent Fwd-GetM, waiting for transfer complete
        H_StoM_A,     -- S->M, sent invalidations, waiting for Acks
        H_EtoM_A,     -- E->M, sent Fwd-GetM, waiting for transfer complete
        H_EtoS_A      -- E->S, sent Fwd-GetS, waiting for ack from owner
      };
      owner: Node;
      sharers: multiset [ProcCount] of Node;
      val: Value;
      pending_req: Node;  -- Requester during forwarding
      wait_invs: 0..ProcCount;
    End;

  ProcState:
    Record
      state: enum {
        P_I,          -- Invalid
        P_S,          -- Shared
        P_M,          -- Modified
        P_E,          -- Exclusive
        
        P_ISD,        -- Invalid to Shared, waiting for Data
        P_IMAD,       -- Invalid to Modified, waiting for Acks and Data
        P_IMA,        -- Invalid to Modified, have Data, waiting for Acks
        P_SMAD,       -- Shared to Modified, waiting for Acks and Data
        P_SMA,        -- Shared to Modified, have Data, waiting for Acks
        P_MIA,        -- Modified to Invalid, waiting for Put_Ack
        P_EIA,        -- Exclusive to Invalid, waiting for Put_Ack
        P_SIA,        -- Shared to Invalid, waiting for Put_Ack
        P_IIA         -- Invalid to Invalid, waiting for Put_Ack
      };
      val: Value;
      acksExpected: (1-ProcCount)..ProcCount-1;
      acksReceived: (1-ProcCount)..ProcCount-1;
    End;

----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
  HomeNode: HomeState;
  Procs: array [Proc] of ProcState;
  Net: array [Node] of multiset [NetMax] of Message;
  InBox: array [Node] of array [VCType] of Message;
  msg_processed: boolean;
  LastWrite: Value;

----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------

Procedure Send(mtype: MessageType;
               dst: Node;
               src: Node;
               vc: VCType;
               val: Value;
               cnt: 0..ProcCount);
var msg: Message;
Begin
  Assert (MultiSetCount(i:Net[dst], true) < NetMax) "Too many messages";
  msg.mtype := mtype;
  msg.src := src;
  msg.vc := vc;
  msg.val := val;
  msg.ackCount := cnt;
  MultiSetAdd(msg, Net[dst]);
End;

Procedure ErrorUnhandledMsg(msg: Message; n: Node);
Begin
  error "Unhandled message type!";
End;

Procedure ErrorUnhandledState();
Begin
  error "Unhandled state!";
End;

Procedure AddToSharersList(n: Node);
Begin
  if MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) = 0
  then
    MultiSetAdd(n, HomeNode.sharers);
  endif;
End;

Function IsSharer(n: Node): Boolean;
Begin
  return MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) > 0
End;

Procedure RemoveFromSharersList(n: Node);
Begin
  MultiSetRemovePred(i:HomeNode.sharers, HomeNode.sharers[i] = n);
End;

Function CountSharers(): 0..ProcCount;
Begin
  return MultiSetCount(i:HomeNode.sharers, true);
End;

Procedure SendInvReqToSharers(rqst:Node);
Begin
  for n:Node do
    if (IsMember(n, Proc) &
        MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) != 0)
    then
      if n != rqst
      then 
        Send(Inv, n, rqst, VC1, UNDEFINED, 0);
      endif;
    endif;
  endfor;
End;

----------------------------------------------------------------------
-- Home/Directory Receive (Table 8.2 + Transient States)
----------------------------------------------------------------------

Procedure HomeReceive(msg: Message);
var cnt: 0..ProcCount;
Begin
  msg_processed := true;

  switch HomeNode.state

  case H_I:
    switch msg.mtype
    
    case GetS:
      HomeNode.state := H_E;
      HomeNode.owner := msg.src; -- Exclusive state
      Send(Data_E, msg.src, HomeType, VC2, HomeNode.val, 0);
    
    case GetM:
      HomeNode.state := H_M;
      HomeNode.owner := msg.src;
      Send(Data, msg.src, HomeType, VC2, HomeNode.val, 0);
    
    case PutS:
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
    
    case PutM:
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
      --HomeNode.val := msg.val;

    case PutE:
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case H_S:
    Assert (CountSharers() > 0) "Sharers list empty in H_S";
    switch msg.mtype
    case GetS:
      AddToSharersList(msg.src);
      Send(Data, msg.src, HomeType, VC2, HomeNode.val, 0);
    
    case GetM:
      cnt := CountSharers();
      if IsSharer(msg.src) then
        RemoveFromSharersList(msg.src);
        cnt := cnt - 1;
        if cnt = 0 then
          HomeNode.state := H_M;
          HomeNode.owner := msg.src;
          undefine HomeNode.sharers;
          Send(Data, msg.src, HomeType, VC2, HomeNode.val, 0);
        else
          -- Send invalidations to all sharers
          -- FIXED: Send Inv with src=msg.src (requester), not HomeType
          -- for n: Node do
          --   if IsMember(n, Proc) & IsSharer(n) then
          --     Send(Inv, n, msg.src, VC2, UNDEFINED, 0);
          --   endif;
          -- endfor;
          --RemoveFromSharersList(msg.src);
          HomeNode.state := H_StoM_A;
          HomeNode.owner := msg.src;
          HomeNode.wait_invs := cnt; -- + 1 because requester is also a sharer being removed and will send back the ack
          SendInvReqToSharers(msg.src);
          undefine HomeNode.sharers;
          Send(Data, msg.src, HomeType, VC2, HomeNode.val, cnt);
        endif;
      else 
        -- Requester not a sharer
        -- Send invalidations to all sharers
        -- for n: Node do
        --   if IsMember(n, Proc) & IsSharer(n) then
        --     Send(Inv, n, msg.src, VC2, UNDEFINED, 0);
        --   endif;
        -- endfor;
        HomeNode.state := H_StoM_A;
        HomeNode.owner := msg.src;
        HomeNode.wait_invs := cnt;
        SendInvReqToSharers(msg.src);
        undefine HomeNode.sharers;
        Send(Data, msg.src, HomeType, VC2, HomeNode.val, cnt);
      endif;
    case PutS:
      RemoveFromSharersList(msg.src);
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
      if CountSharers() = 0 then
        HomeNode.state := H_I;
        undefine HomeNode.sharers;
      endif;
    case PutM:
      RemoveFromSharersList(msg.src);
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
      cnt := CountSharers();
      if cnt = 0 then
        HomeNode.state := H_I;
        undefine HomeNode.sharers;
      endif;
    case PutE:
      RemoveFromSharersList(msg.src);
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
      cnt := CountSharers();
      if cnt = 0 then
        HomeNode.state := H_I;
        undefine HomeNode.sharers;
      endif;  
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case H_M:
    Assert (!IsUndefined(HomeNode.owner)) "Owner undefined in H_M";
    
    switch msg.mtype
    
    case GetS:
      -- Forward to owner and go to transient state
      HomeNode.state := H_MtoS_D;
      HomeNode.pending_req := msg.src;
      Send(Fwd_GetS, HomeNode.owner, msg.src, VC1, UNDEFINED, 0); -- the src is set to requester because the owner needs to know who to send data to, and home will receive a ack later
      -- Will wait for Data from owner before completing to H_S
    
    case GetM:
      -- Forward to owner and go to transient state
      HomeNode.state := H_MtoM_A;
      HomeNode.pending_req := msg.src;
      Send(Fwd_GetM, HomeNode.owner, msg.src, VC1, UNDEFINED, 0);
      -- Will wait for transfer to complete before updating owner

    case PutS:
      RemoveFromSharersList(msg.src);
      -- if CountSharers() = 0 then
      --   HomeNode.val := msg.val;
      --   undefine HomeNode.owner;
      --   HomeNode.state := H_I;
      -- endif;
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);

    case PutE:
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
    
    case PutM:
      if msg.src = HomeNode.owner then
        HomeNode.val := msg.val;
        undefine HomeNode.owner;
        HomeNode.state := H_I;
      else 
        RemoveFromSharersList(msg.src);
      endif;
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;


  case H_E:
    switch msg.mtype
    
    case GetS:
      HomeNode.state := H_EtoS_A;
      HomeNode.pending_req := msg.src;
      Send(Fwd_GetS, HomeNode.owner, msg.src, VC1, UNDEFINED, 0);
    --   undefine HomeNode.owner;
    --   AddToSharersList(msg.src);
    
    case GetM:
      HomeNode.state := H_EtoM_A;
      HomeNode.pending_req := msg.src;
      Send(Fwd_GetM, HomeNode.owner, msg.src, VC1, UNDEFINED, 0);

    case PutS:
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);

    case PutM:
      if msg.src = HomeNode.owner then
        HomeNode.val := msg.val;
        undefine HomeNode.owner;
        HomeNode.state := H_I;
      else 
        RemoveFromSharersList(msg.src);
      endif;
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
    
    case PutE:
      if msg.src = HomeNode.owner then
        undefine HomeNode.owner;
        HomeNode.state := H_I;
      endif;
      Send(Put_Ack, msg.src, HomeType, VC2, UNDEFINED, 0);
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case H_MtoS_D:
    -- Waiting for Data from owner after Fwd-GetS
    switch msg.mtype
    
    case Data:
      -- Owner sent data back, complete transition to H_S
      Assert (msg.src = HomeNode.owner) "Data from non-owner in H_MtoS_D";
      HomeNode.val := msg.val;
      AddToSharersList(HomeNode.pending_req);
      AddToSharersList(msg.src);  -- Old owner is now a sharer
      undefine HomeNode.owner;
      undefine HomeNode.pending_req;
      HomeNode.state := H_S;
    
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case PutE:
      -- Stall all other requests until forwarding completes
      msg_processed := false;
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case H_MtoM_A:
    -- Waiting for M->M transfer to complete after Fwd-GetM
    switch msg.mtype
    case Fwd_GetM_A:
      -- Owner sent ack back, complete transition to H_M
      Assert (msg.src = HomeNode.owner) "Fwd_GetM_A from non-owner in H_MtoM_A";
      HomeNode.owner := HomeNode.pending_req;
      undefine HomeNode.pending_req;
      HomeNode.state := H_M;
    case Data:  
      msg_processed := false;
    case PutM:   
      msg_processed := false;
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutE:
      -- Stall all other requests
      msg_processed := false;
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;


  case H_StoM_A:
    -- Waiting for invalidation Acks after sending Inv
    switch msg.mtype
    case Inv_Ack:
      HomeNode.wait_invs := HomeNode.wait_invs - 1;
      if HomeNode.wait_invs = 0 then
        -- All invalidation Acks received, complete transition to M
        HomeNode.state := H_M;
      endif;   
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case PutE:
      -- Stall all other requests
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch; 

  case H_EtoS_A:
    -- Waiting for Data from owner after Fwd-GetS
    switch msg.mtype

    case Data:
      -- Owner sent data back, complete transition to H_S
      Assert (msg.src = HomeNode.owner) "Data from non-owner in H_EtoS_A";
      HomeNode.val := msg.val;
      AddToSharersList(HomeNode.pending_req);
      AddToSharersList(msg.src);  -- Old owner is now a sharer
      undefine HomeNode.owner;
      undefine HomeNode.pending_req;
      HomeNode.state := H_S;

    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutM:
      msg_processed := false;
    case PutE:
      -- Stall all other requests until forwarding completes
      msg_processed := false;

    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case H_EtoM_A:
    -- Waiting for M->M transfer to complete after Fwd-GetM
    switch msg.mtype
    case Fwd_GetM_A:
      -- Owner sent ack back, complete transition to H_M
      Assert (msg.src = HomeNode.owner) "Fwd_GetM_A from non-owner in H_EtoM_A";
      HomeNode.owner := HomeNode.pending_req;
      undefine HomeNode.pending_req;
      HomeNode.state := H_M;
    case Data:  
      msg_processed := false;
    case PutM:   
      msg_processed := false;
    case GetS:
      msg_processed := false;
    case GetM:
      msg_processed := false;
    case PutS:
      msg_processed := false;
    case PutE:
      -- Stall all other requests
      msg_processed := false;
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;                                               

  endswitch;
End;

----------------------------------------------------------------------
-- Processor/Cache Receive (Table 8.1)
----------------------------------------------------------------------

Procedure ProcReceive(msg: Message; p: Proc);
Begin
  msg_processed := true;
  
  alias ps: Procs[p].state do
  alias pv: Procs[p].val do
  alias pa: Procs[p].acksExpected do
  alias pr: Procs[p].acksReceived do

  switch ps

  case P_I:
      ErrorUnhandledMsg(msg, p);
    

  case P_S:
    switch msg.mtype
    case Inv:
      Send(Inv_Ack, msg.src, p, VC2, UNDEFINED, 0);
      Send(Inv_Ack, HomeType, p, VC2, UNDEFINED, 0); -- Ack to directory as well
      undefine pv;
      ps := P_I;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_M:
    switch msg.mtype
    case Fwd_GetS:
      -- Forward data to requester AND directory
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Data, HomeType, p, VC2, pv, 0);
      ps := P_S;
    
    case Fwd_GetM:
      -- Forward data to requester only
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Fwd_GetM_A, HomeType, p, VC2, UNDEFINED, 0);
      undefine pv;
      ps := P_I;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_E:
    switch msg.mtype
    case Fwd_GetS:
      -- Forward data to requester AND directory
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Data, HomeType, p, VC2, pv, 0);
      ps := P_S;
    
    case Fwd_GetM:
      -- Forward data to requester only
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Fwd_GetM_A, HomeType, p, VC2, UNDEFINED, 0);
      undefine pv;
      ps := P_I;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_ISD:
    switch msg.mtype
    case Inv:
      msg_processed := false;

    case Fwd_GetS:
      msg_processed := false;

    case Fwd_GetM:
      msg_processed := false; -- additional stall for forwarded GetM, differenct from book table because of out-of-order messages
    
    case Data:
      pv := msg.val;
      ps := P_S;
    
    case Data_E:
      pv := msg.val;
      ps := P_E;
      
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_IMAD:
    switch msg.mtype
    case Fwd_GetS:
      msg_processed := false;
    
    case Fwd_GetM:
      msg_processed := false;
    
    case Data:
      pv := msg.val;
      if msg.ackCount = 0 then -- if from the previous owner, then msg.ackCount = 0 which can be handled the same way for if msg from directory, and msg.ackCount is 0.
        ps := P_M;
        LastWrite := pv;  -- Update LastWrite on successful store
      else
        pa := msg.ackCount;  -- total expected Inv_Acks
        -- If some Inv_Acks already arrived early, pr will be > 0.
        if pr = pa then
          -- All acks already collected, done.
          ps := P_M;
          LastWrite := pv;
          pa := 0;
          pr := 0;
        else
          -- Need to wait for the remaining acks.
          ps := P_IMA;
        endif;
      endif;
    
    case Inv_Ack:
      pr := pr + 1;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_IMA:
    switch msg.mtype
    case Fwd_GetS:
      msg_processed := false;
    
    case Fwd_GetM:
      msg_processed := false;
    
    case Inv_Ack:
      pr := pr + 1;
      if pr = pa then
        ps := P_M;
        pr := 0;
        pa := 0;
        LastWrite := pv;  -- Update LastWrite on successful store
      endif;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_SMAD:
    switch msg.mtype
    case Fwd_GetS:
      msg_processed := false;
    
    case Fwd_GetM:
      msg_processed := false;

    case Inv:
      ps:= P_IMAD;
      Send(Inv_Ack, msg.src, p, VC2, UNDEFINED, 0);
      Send(Inv_Ack, HomeType, p, VC2, UNDEFINED, 0); -- Ack to directory as well
      undefine pv;
    
    case Data:
      pv := msg.val;
      if msg.ackCount = 0 then
        ps := P_M;
        LastWrite := pv;  -- Update LastWrite on successful store
      else
        pa := msg.ackCount;
        if pr = pa then
          ps := P_M;
          LastWrite := pv;
          pa := 0;
          pr := 0;
        else
          ps := P_SMA;
        endif;
      endif;
    
    case Inv_Ack:
      pr := pr + 1;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_SMA:
    switch msg.mtype
    case Fwd_GetS:
      msg_processed := false;
    
    case Fwd_GetM:
      msg_processed := false;
    
    case Inv_Ack:
      pr := pr + 1;
      if pr = pa then
        ps := P_M;
        pr := 0;
        pa := 0;
        LastWrite := pv;  -- Update LastWrite on successful store
      endif;
  
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_MIA:
    switch msg.mtype
    case Fwd_GetS:
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Data, HomeType, p, VC2, pv, 0);
      ps := P_SIA;
    
    case Fwd_GetM:
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Fwd_GetM_A, HomeType, p, VC2, UNDEFINED, 0);
      undefine pv;
      ps := P_IIA;
    
    case Put_Ack:
      undefine pv;
      ps := P_I;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_EIA:
    switch msg.mtype
    case Fwd_GetS:
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Data, HomeType, p, VC2, pv, 0);
      ps := P_SIA;
    
    case Fwd_GetM:
      Send(Data, msg.src, p, VC2, pv, 0);
      Send(Fwd_GetM_A, HomeType, p, VC2, UNDEFINED, 0);
      undefine pv;
      ps := P_IIA;
    
    case Put_Ack:
      undefine pv;
      ps := P_I;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_SIA:
    switch msg.mtype
    case Inv:
      Send(Inv_Ack, msg.src, p, VC2, UNDEFINED, 0);
      Send(Inv_Ack, HomeType, p, VC2, UNDEFINED, 0); -- Ack to directory as well
      ps := P_IIA;
    
    case Put_Ack:
      ps := P_I;
      undefine pv;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_IIA:
    switch msg.mtype
    case Put_Ack:
      ps := P_I;
      undefine pv;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  else
    ErrorUnhandledState();
  endswitch;

  endalias;
  endalias;
  endalias;
  endalias;
End;

----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

ruleset n: Proc do
  alias p: Procs[n] do

  ruleset v: Value do
    rule "store"
      (p.state = P_M)
    ==>
      p.val := v;
      LastWrite := v;
    endrule;
  endruleset;

  ruleset v: Value do
    rule "store hit from E"
      (p.state = P_E)
    ==>
      p.val := v;
      LastWrite := v;
      p.state := P_M;
    endrule;
  endruleset;

  rule "load miss from I"
    (p.state = P_I)
  ==>
    Send(GetS, HomeType, n, VC0, UNDEFINED, 0);
    p.state := P_ISD;
  endrule;

  ruleset v: Value do  
    rule "store miss from I"
      (p.state = P_I)
    ==>
      p.val:= v;
      Send(GetM, HomeType, n, VC0, UNDEFINED, 0);
      p.state := P_IMAD;
    endrule;
  endruleset;

  ruleset v: Value do  
    rule "store miss from S"
      (p.state = P_S)
    ==>
      p.val:= v;
      Send(GetM, HomeType, n, VC0, UNDEFINED, 0);
      p.state := P_SMAD;
    endrule;
  endruleset;

  rule "replacement from S"
    (p.state = P_S)
  ==>
    Send(PutS, HomeType, n, VC0, UNDEFINED, 0);
    p.state := P_SIA;
    undefine p.val;
  endrule;

  rule "replacement from M"
    (p.state = P_M)
  ==>
    Send(PutM, HomeType, n, VC0, p.val, 0);
    p.state := P_MIA;
  endrule;

  rule "replacement from E"
      (p.state = P_E)
  ==>
      Send(PutE, HomeType, n, VC0, UNDEFINED, 0);
      p.state := P_EIA;
  endrule;

  endalias;
endruleset;

----------------------------------------------------------------------
-- Message Delivery
----------------------------------------------------------------------

ruleset n: Node do
  choose midx: Net[n] do
    alias chan: Net[n] do
    alias msg: chan[midx] do
    alias box: InBox[n] do

    rule "receive"
      (isundefined(box[msg.vc].mtype))
    ==>
      if IsMember(n, Home) then
        HomeReceive(msg);
      else
        ProcReceive(msg, n);
      endif;

      if !msg_processed then
        box[msg.vc] := msg;
      endif;

      MultiSetRemove(midx, chan);
    endrule;

    endalias;
    endalias;
    endalias;
  endchoose;

  ruleset vc: VCType do
    rule "receive blocked"
      (!isundefined(InBox[n][vc].mtype))
    ==>
      if IsMember(n, Home) then
        HomeReceive(InBox[n][vc]);
      else
        ProcReceive(InBox[n][vc], n);
      endif;

      if msg_processed then
        undefine InBox[n][vc];
      endif;
    endrule;
  endruleset;

endruleset;

----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------

startstate
  for v: Value do
    HomeNode.state := H_I;
    undefine HomeNode.owner;
    undefine HomeNode.sharers;
    undefine HomeNode.pending_req;
    HomeNode.val := v;
    HomeNode.wait_invs := 0;
  endfor;
  LastWrite := HomeNode.val;

  for i: Proc do
    Procs[i].state := P_I;
    undefine Procs[i].val;
    Procs[i].acksExpected := 0;
    Procs[i].acksReceived := 0;
  endfor;

  undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "Invalid implies empty owner"
  HomeNode.state = H_I -> IsUndefined(HomeNode.owner);

invariant "Modified implies defined owner"
  HomeNode.state = H_M -> !IsUndefined(HomeNode.owner);

invariant "Shared implies empty owner"
  HomeNode.state = H_S -> IsUndefined(HomeNode.owner);

invariant "value in memory matches last write when invalid"
  HomeNode.state = H_I -> HomeNode.val = LastWrite;

invariant "value is undefined while invalid"
  Forall n: Proc do
    Procs[n].state = P_I -> IsUndefined(Procs[n].val)
  end;

invariant "modified implies no sharers"
  HomeNode.state = H_M -> MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "invalid implies no sharers"
  HomeNode.state = H_I -> MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "value in shared state matches memory"
  Forall n: Proc do
    HomeNode.state = H_S & Procs[n].state = P_S -> HomeNode.val = Procs[n].val
  end;

invariant "modified value matches last write"
  Forall n: Proc do
    Procs[n].state = P_M -> Procs[n].val = LastWrite
  end;

invariant "at most one modified"
  Forall n1: Proc do
    Forall n2: Proc do
      (n1 != n2 & Procs[n1].state = P_M) -> Procs[n2].state != P_M
    end
  end;

invariant "sharer list soundness (no I/M)"
  Forall p: Proc do
    IsSharer(p) -> !(Procs[p].state = P_I | Procs[p].state = P_M)
  end;

invariant "P_S not with H_M"
  Forall p: Proc do
    Procs[p].state = P_S -> HomeNode.state != H_M
  end;
  
invariant "H_I implies no cache has valid data"
  HomeNode.state = H_I ->
    Forall p: Proc do
      !(Procs[p].state = P_S | Procs[p].state = P_M)
    end;

invariant "at most one cache in E"
  Forall p1: Proc do
    Forall p2: Proc do
      (p1 != p2 & Procs[p1].state = P_E) ->
        Procs[p2].state != P_E
    end
  end;

invariant "Exclusive implies no sharers"
  HomeNode.state = H_E ->
    MultiSetCount(i:HomeNode.sharers, true) = 0;

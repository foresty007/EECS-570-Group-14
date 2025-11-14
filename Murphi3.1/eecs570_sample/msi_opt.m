
-- two-state 4-hop VI protocol

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  ProcCount: 3;          -- number processors
  ValueCount:   2;       -- number of data values.
  VC0: 0;                -- low priority
  VC1: 1;
  VC2: 2;
  QMax: 3;
  NumVCs: VC2 - VC0 + 1;
  NetMax: ProcCount*2+1;
  

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);   -- unordered range of processors
  Value: scalarset(ValueCount); -- arbitrary values for tracking coherence
  Home: enum { HomeType };      -- need enumeration for IsMember calls
  Node: union { Home , Proc };

  VCType: VC0..NumVCs-1;
  SharerNum: 0..ProcCount;
  MessageType: enum {  ReadReq,         -- request for data / exclusivity
                       ReadAck,         -- read ack (w/ data)
                       ReadReqX,    
								       WBReq,           -- writeback request (w/ data)
                       WBShared,
                       WBFwd,
								       WBAck,           -- writeback ack 
                       SMAck,   
                       FwdSReq,
                       FwdMReq,
                       InvalidReq,
                       InvalidAck,
                       PutS
                    };

  Message:
    Record
      mtype: MessageType;
      src: Node;
      -- do not need a destination for verification; the destination is indicated by which array entry in the Net the message is placed
      vc: VCType;
      val: Value;
      fwd_dst: Node;  -- for InvalidateReq and FwdMReq
      num_sharer: SharerNum; -- optional, tells requester how many InvalidateAcks to expect
    End;

  HomeState:
    Record
      -- state: enum { H_Valid, H_Invalid, 					--stable states
      -- 							HT_Pending }; 								--transient states during recall
      state: enum { H_Invalid, H_Shared, H_Modified, 					--stable states
							HT_MPending, HT_SPending, HT_SMPENDING, HT_IIPENDING}; 								--transient states during recall
      owner: Node;	
      sharers: multiset [ProcCount] of Node;    --No need for sharers in this protocol, but this is a good way to represent them
      val: Value; 
      -- sharers: multiset [ProcCount] of Node;      -- sharer
    End;

  ProcState:
    Record
      -- state: enum { P_Valid, P_Invalid,
      --             PT_Pending, PT_WritebackPending
      --             };
      state: enum { P_Invalid, P_Shared, P_Modified,
            PT_IM_IA, PT_IM_I, PT_SM_IA, PT_SM_I, PT_IS_A, PT_WritebackPending, PT_Clean_Eviction
            };
      val: Value;
      PendingInvAcks: SharerNum;
    End;

----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
  HomeNode:  HomeState;
  Procs: array [Proc] of ProcState;
  Net:   array [Node] of multiset [NetMax] of Message;  -- One multiset for each destination - messages are arbitrarily reordered by the multiset
  InBox: array [Node] of array [VCType] of Message; -- If a message is not processed, it is placed in InBox, blocking that virtual channel
  msg_processed: boolean;
  LastWrite: Value; -- Used to confirm that writes are not lost; this variable would not exist in real hardware

----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure Send(mtype:MessageType;
	       dst:Node;
	       src:Node;
         vc:VCType;
         val:Value;
         fwd_dst: Node;
         num_sharer: SharerNum;
         );
var msg:Message;
Begin
  Assert (MultiSetCount(i:Net[dst], true) < NetMax) "Too many messages";
  msg.mtype := mtype;
  msg.src   := src;
  msg.vc    := vc;
  msg.val   := val;
  msg.fwd_dst := fwd_dst;
  msg.num_sharer := num_sharer;
  MultiSetAdd(msg, Net[dst]);
End;

Procedure ErrorUnhandledMsg(msg:Message; n:Node);
Begin
  error "Unhandled message type!";
End;

Procedure ErrorUnhandledState();
Begin
  error "Unhandled state!";
End;

/*
-- These aren't needed for Valid/Invalid protocol, but this is a good way of writing these functions
*/
Procedure AddToSharersList(n:Node);
Begin
  if MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) = 0
  then
    MultiSetAdd(n, HomeNode.sharers);
  endif;
End;

Function IsSharer(n:Node) : Boolean;
Begin
  return MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) > 0
End;

Procedure RemoveFromSharersList(n:Node);
Begin
  MultiSetRemovePred(i:HomeNode.sharers, HomeNode.sharers[i] = n);
End;

-- Sends a message to all sharers except rqst
Procedure SendInvReqToSharers(rqst:Node);
Begin
  for n:Node do
    if (IsMember(n, Proc) &
        MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) != 0)
    then
      RemoveFromSharersList(n);
      if n != rqst
      then 
        -- Send invalidation message here 
        Send(InvalidReq, n, HomeType, VC1, UNDEFINED, rqst, UNDEFINED);
        
      endif;
    endif;
  endfor;
End;



Procedure HomeReceive(msg:Message);
var cnt:0..ProcCount;  -- for counting sharers
Begin
-- Debug output may be helpful:
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at home -- "; put HomeNode.state;

  -- The line below is not needed in Valid/Invalid protocol.  However, the 
  -- compiler barfs if we put this inside a switch, so it is useful to
  -- pre-calculate the sharer count here
  cnt := MultiSetCount(i:HomeNode.sharers, true);
  -- num_sharer := MultiSetCount(i:HomeNode.sharers, true);

  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  switch HomeNode.state
  case H_Invalid:
    switch msg.mtype

    case ReadReq:
      HomeNode.state := H_Shared;
      AddToSharersList(msg.src);
      Send(ReadAck, msg.src, HomeType, VC2, HomeNode.val, UNDEFINED, UNDEFINED);
    case ReadReqX:
      HomeNode.state := H_Modified;
      HomeNode.owner := msg.src;
      Send(ReadAck, msg.src, HomeType, VC2, HomeNode.val, UNDEFINED, 0);
    else
      ErrorUnhandledMsg(msg, HomeType);
    

    endswitch;


  case H_Shared: 
    Assert (IsUndefined(HomeNode.owner) = true) 
       "HomeNode has owner, but line is Shared";
    Assert (cnt != 0) 
       "HomeNode has no sharer, but line is Shared";

    switch msg.mtype
    case ReadReq:
      if (IsSharer(msg.src) = false) then
        Send(ReadAck, msg.src, HomeType, VC2, HomeNode.val, UNDEFINED, UNDEFINED);
        AddToSharersList(msg.src);
      else 
        msg_processed := false;
      endif;
    case ReadReqX:
      if (IsSharer(msg.src)) then
        Send(ReadAck, msg.src, HomeType, VC2, HomeNode.val, UNDEFINED, cnt-1);
        if cnt = 1 then 
          HomeNode.state := H_Modified;
        else 
          HomeNode.state := HT_SMPENDING;
        endif;
        HomeNode.owner := msg.src; --remember who the new owner will be
        SendInvReqToSharers(msg.src);
      else
        HomeNode.state := HT_SMPENDING;
        Send(ReadAck, msg.src, HomeType, VC2, HomeNode.val, UNDEFINED, cnt);

        HomeNode.owner := msg.src; --remember who the new owner will be
        SendInvReqToSharers(msg.src);
      endif;

    case PutS:
      Send(WBAck, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED, UNDEFINED);
      if IsSharer(msg.src) = true then
        RemoveFromSharersList(msg.src);

        if cnt = 1 then -- originally 1 but reduced 1
          HomeNode.state := H_Invalid;
        else  
          HomeNode.state := H_Shared;
        endif;
      endif;
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HT_SMPENDING:
    switch msg.mtype
    case SMAck:
      HomeNode.state := H_Modified;
    case PutS:
      Send(InvalidAck, HomeNode.owner, HomeType, VC2, UNDEFINED, UNDEFINED, UNDEFINED);
    case ReadReq:
    	msg_processed := false; -- stall message in InBox
    case ReadReqX:
    	msg_processed := false; -- stall message in InBox
    case WBReq:
      HomeNode.state := HT_IIPENDING;
      undefine HomeNode.owner;
      HomeNode.val := msg.val;
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;
  
  case HT_IIPENDING:
    switch msg.mtype
    case SMAck:
      HomeNode.state := H_Invalid;
    case ReadReq:
    	msg_processed := false; -- stall message in InBox
    case ReadReqX:
    	msg_processed := false; -- stall message in InBox
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;
  
  case H_Modified:
    Assert (IsUndefined(HomeNode.owner) = false) 
       "HomeNode has no owner, but line is Modified";

    switch msg.mtype
    case ReadReq:
      Assert(HomeNode.owner != msg.src)
        "ProcNode is already an owner but sending readreq";
      HomeNode.state := HT_SPending;     
      Send(FwdSReq, HomeNode.owner, HomeType, VC1, UNDEFINED, msg.src, UNDEFINED);
      AddToSharersList(HomeNode.owner);
      AddToSharersList(msg.src);
      undefine HomeNode.owner;

    case ReadReqX: 
      Assert(HomeNode.owner != msg.src)
        "ProcNode is already an owner but sending readreqx";
      HomeNode.state := HT_MPending; 
      Send(FwdMReq, HomeNode.owner, HomeType, VC1, UNDEFINED, msg.src, UNDEFINED);
      HomeNode.owner := msg.src;
    case WBReq:
      Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";
      if (msg.src = HomeNode.owner) then
        HomeNode.state := H_Invalid;
        HomeNode.val := msg.val;
        Send(WBAck, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED, UNDEFINED);
        undefine HomeNode.owner;
      endif;

    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HT_MPending:
    switch msg.mtype
   
    case WBReq:
      Assert (!IsUnDefined(HomeNode.owner)) "owner undefined";
      if(HomeNode.owner = msg.src) then
        Send(WBAck, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED, UNDEFINED);
        HomeNode.val := msg.val;
        undefine HomeNode.owner;
      else 
        HomeNode.state := H_Modified;
        HomeNode.val := msg.val;
        Send(ReadAck, HomeNode.owner, HomeType, VC2, HomeNode.val, UNDEFINED, 0);
      endif;
    case WBFwd:
      if (IsUnDefined(HomeNode.owner)) then
        HomeNode.state := H_Invalid;
      else 
        HomeNode.state := H_Modified;
        HomeNode.val := msg.val;
      endif;
    case ReadReq:
    	msg_processed := false; -- stall message in InBox
    case ReadReqX:
    	msg_processed := false; -- stall message in InBox
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HT_SPending:
    switch msg.mtype
   
    case WBReq:
      Assert (IsUnDefined(HomeNode.owner)&(cnt !=0)) "owner and sharer all undefined";
      HomeNode.state := H_Shared;
      HomeNode.val := msg.val;
      
      RemoveFromSharersList(msg.src);
      
      for n:Node do
        if (IsMember(n, Proc) & IsSharer(n)) then
          Send(ReadAck, n, HomeType, VC2, HomeNode.val, UNDEFINED, UNDEFINED);
        endif;
      endfor;

    case WBShared:
      if (cnt != 0) then
        HomeNode.state := H_Shared;
        HomeNode.val := msg.val;
      else 
        HomeNode.state := H_Invalid;
        HomeNode.val := msg.val;
      endif;

    case ReadReq:
    	msg_processed := false; -- stall message in InBox

    case ReadReqX:
    	msg_processed := false; -- stall message in InBox
    case PutS:
      Send(WBAck, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED, UNDEFINED);
      if(IsSharer(msg.src)) then
        RemoveFromSharersList(msg.src);
      endif;
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;
  endswitch;
End;


Procedure ProcReceive(msg:Message; p:Proc);
Begin
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at proc "; put p; put "\n";

  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  alias ps:Procs[p].state do
  alias pv:Procs[p].val do
  alias p_pendinvack :Procs[p].PendingInvAcks do
  switch ps
  case P_Invalid:
  case P_Shared:

    switch msg.mtype
    case InvalidReq:
      Send(InvalidAck, msg.fwd_dst, p, VC2, UNDEFINED, UNDEFINED, UNDEFINED);
      Undefine pv;
      ps := P_Invalid;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case P_Modified:

    switch msg.mtype
    case FwdMReq:
      Send(ReadAck, msg.fwd_dst, p, VC2, pv, UNDEFINED, 0);
      Send(WBFwd, msg.src, p, VC1, pv, UNDEFINED, UNDEFINED);
      ps := P_Invalid;
    case FwdSReq:
      Send(ReadAck, msg.fwd_dst, p, VC2, pv, UNDEFINED, UNDEFINED);
      Send(WBShared, msg.src, p, VC1, pv, UNDEFINED, UNDEFINED);
      ps := P_Shared;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_IM_IA:

    switch msg.mtype
    case ReadAck:
      Assert(!IsUnDefined(p_pendinvack))
        "pending inv ack not defined";
      pv := msg.val;
      p_pendinvack := msg.num_sharer - p_pendinvack;
      if msg.num_sharer = 0 then
        undefine p_pendinvack;
        ps := P_Modified;
      elsif p_pendinvack = 0 then
        undefine p_pendinvack;
        ps := P_Modified;
        Send(SMAck, HomeType, p, VC2, UNDEFINED, UNDEFINED, UNDEFINED);
      else 
        ps := PT_IM_I;
      endif;
    case InvalidAck:
      p_pendinvack := p_pendinvack +1;
    case FwdMReq:
      msg_processed := false; -- stall message in InBox
    case FwdSReq:
    	msg_processed := false; -- stall message in InBox
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_IM_I:

    switch msg.mtype
    case InvalidAck:
      p_pendinvack := p_pendinvack -1;
      switch p_pendinvack
        case 0:
          undefine p_pendinvack;
          ps := P_Modified;
          Send(SMAck, HomeType, p, VC2, UNDEFINED, UNDEFINED, UNDEFINED);

        else
          ps := PT_IM_I;
      endswitch;
    case FwdMReq:
      msg_processed := false; -- stall message in InBox

    case FwdSReq:
    	msg_processed := false; -- stall message in InBox
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;


  case PT_SM_IA:

    switch msg.mtype
    case ReadAck:
      Assert(!IsUnDefined(p_pendinvack))
        "pending inv ack not defined";
      p_pendinvack := msg.num_sharer - p_pendinvack;
      if msg.num_sharer = 0 then
        undefine p_pendinvack;
        ps := P_Modified;
      elsif p_pendinvack = 0 then
        undefine p_pendinvack;
        ps := P_Modified;
        Send(SMAck, HomeType, p, VC2, UNDEFINED, UNDEFINED, UNDEFINED);
      else 
        ps := PT_IM_I;
      endif;
    case InvalidAck:
      p_pendinvack := p_pendinvack +1;
    case InvalidReq:
      Send(InvalidAck, msg.fwd_dst, p, VC1, UNDEFINED, UNDEFINED, UNDEFINED);
      Undefine pv;
      ps := PT_IM_IA;
    case FwdMReq:
      msg_processed := false; -- stall message in InBox

    case FwdSReq:
    	msg_processed := false; -- stall message in InBox
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_SM_I:

    switch msg.mtype
    case InvalidAck:
      p_pendinvack := p_pendinvack -1;
      switch p_pendinvack
        case 0:
          undefine p_pendinvack;
          ps := P_Modified;
          Send(SMAck, HomeType, p, VC2, UNDEFINED, UNDEFINED, UNDEFINED);

        else
          ps := PT_SM_I;
      endswitch;
    case FwdMReq:
      msg_processed := false; -- stall message in InBox

    case FwdSReq:
    	msg_processed := false; -- stall message in InBox
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  case PT_IS_A:

    switch msg.mtype
    case ReadAck:
      pv := msg.val;
      ps := P_Shared;
    case InvalidReq:
    	msg_processed := false; -- stall message in InBox
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_Clean_Eviction:
    switch msg.mtype
    case InvalidReq:
      ps := P_Invalid;
      undefine pv;
    case WBAck:
      ps := P_Invalid;
      undefine pv;
    else
      ErrorUnhandledMsg(msg, p);
		endswitch;

  case PT_WritebackPending:    

    switch msg.mtype
    case WBAck:
      ps := P_Invalid;
      undefine pv;
    
    case FwdMReq:
      ps := P_Invalid;
      undefine pv;
    case FwdSReq:
      ps := P_Invalid;
      undefine pv;
    else
      ErrorUnhandledMsg(msg, p);
		endswitch;

  ----------------------------
  -- Error catch
  ----------------------------
  else
    ErrorUnhandledState();

  endswitch;
  
  endalias;
  endalias;
  endalias;
End;

----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- Processor actions (affecting coherency)

ruleset n:Proc Do
  alias p:Procs[n] Do

	ruleset v:Value Do
  	rule "store new value"
   	 (p.state = P_Modified)
    	==>
 		   p.val := v;      
 		   LastWrite := v;  --We use LastWrite to sanity check that reads receive the value of the last write
  	endrule;
	endruleset;

  rule "read exclusive request invalid"
    p.state = P_Invalid 
  ==>
    Send(ReadReqX, HomeType, n, VC0, UNDEFINED, UNDEFINED, UNDEFINED);
    p.state := PT_IM_IA;
    p.PendingInvAcks := 0;
  endrule;

  rule "read exclusive request shared"
    p.state = P_Shared
  ==>
    Send(ReadReqX, HomeType, n, VC0, UNDEFINED, UNDEFINED, UNDEFINED);
    p.state := PT_SM_IA;
    p.PendingInvAcks := 0;
  endrule;

  rule "read request"
    p.state = P_Invalid 
  ==>
    Send(ReadReq, HomeType, n, VC0, UNDEFINED, UNDEFINED, UNDEFINED);
    p.state := PT_IS_A;
  endrule;


  rule "clean eviction"
    (p.state = P_Shared)
  ==>
    Send(PutS, HomeType, n, VC1, p.val, UNDEFINED, UNDEFINED); 
    -- p.state := P_Invalid;
    p.state := PT_Clean_Eviction;
    undefine p.val;
  endrule;

  rule "dirty eviction"
    (p.state = P_Modified)
  ==>
    Send(WBReq, HomeType, n, VC1, p.val, UNDEFINED, UNDEFINED); 
    p.state := PT_WritebackPending;
    -- undefine p.val;
  endrule;

  endalias;
endruleset;

-- Message delivery rules
ruleset n:Node do
  choose midx:Net[n] do
    alias chan:Net[n] do
    alias msg:chan[midx] do
    alias box:InBox[n] do

		-- Pick a random message in the network and delivier it
    rule "receive-net"
			(isundefined(box[msg.vc].mtype))
    ==>

      if IsMember(n, Home)
      then
        HomeReceive(msg);
      else
        ProcReceive(msg, n);
			endif;

			if ! msg_processed
			then
				-- The node refused the message, stick it in the InBox to block the VC.
	  		box[msg.vc] := msg;
			endif;
	  
		  MultiSetRemove(midx, chan);
	  
    endrule;
  
    endalias
    endalias;
    endalias;
  endchoose;  

	-- Try to deliver a message from a blocked VC; perhaps the node can handle it now
	ruleset vc:VCType do
    rule "receive-blocked-vc"
			(! isundefined(InBox[n][vc].mtype))
    ==>
      if IsMember(n, Home)
      then
        HomeReceive(InBox[n][vc]);
      else
        ProcReceive(InBox[n][vc], n);
			endif;

			if msg_processed
			then
				-- Message has been handled, forget it
	  		undefine InBox[n][vc];
			endif;
	  
    endrule;
  endruleset;

endruleset;

----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------
startstate

	For v:Value do
  -- home node initialization
  HomeNode.state := H_Invalid;
  undefine HomeNode.owner;
  undefine HomeNode.sharers;
  HomeNode.val := v;
	endfor;
	LastWrite := HomeNode.val;
  
  -- processor initialization
  for i:Proc do
    Procs[i].state := P_Invalid;
    undefine Procs[i].val;
    undefine Procs[i].PendingInvAcks;
  endfor;

  -- network initialization
  undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "Invalid implies empty owner"
  HomeNode.state = H_Invalid
    ->
      IsUndefined(HomeNode.owner);

invariant "value in memory matches value of last write, when invalid"
     HomeNode.state = H_Invalid 
    ->
			HomeNode.val = LastWrite;

-- Here are some invariants that are helpful for validating shared state.

invariant "modified implies empty sharers list"
  HomeNode.state = H_Modified
    ->
      MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "Invalid implies empty sharer list"
  HomeNode.state = H_Invalid
    ->
      MultiSetCount(i:HomeNode.sharers, true) = 0;

invariant "values in memory matches value of last write, when shared or invalid"
  Forall n : Proc Do	
     HomeNode.state = H_Shared | HomeNode.state = H_Invalid
    ->
			HomeNode.val = LastWrite
	end;

invariant "values in shared state match memory"
  Forall n : Proc Do	
     HomeNode.state = H_Shared & Procs[n].state = P_Shared
    ->
			HomeNode.val = Procs[n].val
	end;


-- two-state 4-hop VI protocol

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  ProcCount: 6;          -- number processors, def:P0 & P1 are home
  HomeCount: 2;          -- number home
  ValueCount: 2;         -- number of data values.
  AddrCount: 2;          -- number of adddress
  D2H_REQ: 0;
  H2D_REQ: 1;
  D2H_DATA: 2;
  D2H_RSP: 3;
  H2D_DATA: 4;
  H2D_RSP: 5;
  QMax: 6;
  NumVCs: 6;
  NetMax: ProcCount*2+1;


  MaxUQID: 1; --Mingjian Li
  

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);   -- unordered range of processors
  Home: enum{ Home0, Home1 };   -- 
  
  CQIDType: 0..MaxUQID;
  UQIDType: 0..MaxUQID;         --Mingjian Li
  MESIType: enum { M, E, S, I };
  RspData: union { uq: UQIDType; mesi: MESIType };
  
  Value: scalarset(ValueCount); -- arbitrary values for tracking coherence
  Address: scalarset{AddrCount}; 
  -- Home: enum { HomeType };      -- need enumeration for IsMember calls
  Node: union { Home , Proc };

  VCType: VC0..NumVCs-1;
  SharerNum: 0..ProcCount;
  MessageType: enum { 
                      --D2H_REQUEST
                      RdCurr,
                      RdOwn,
                      RdShared,
                      RdAny,
                      RdOwnNoData,
                      ItoMWr,
                      WrCur,
                      CLFlush,
                      CleanEvict,
                      DirtyEvict,
                      CleanEvictNoData,
                      -- WOWrInv,
                      -- WOWrInvF,
                      WrInv,
                      CacheFlushed,
                      -- D2H_RESPONSE
                      RspIHitI,
                      RspVHitV,
                      RspIHitSE,
                      RspSHitSE,
                      RspSFwdM,
                      RspIFwdM,
                      RspVFwdV,
                      -- H2D_RESPONSE
                      WritePull,
                      GO,
                      GO_WritePull,
                      ExtCmp,
                      GO_WritePull_Drop,
                      Reserved,
                      Fast_GO_WritePull,
                      GO_ERR_WritePull,
                      -- H2D_REQUEST
                      SnpData,
                      SnpInv,
                      SnpCur,
                      -- DATA
                      Data
                    };

  Message:
    Record
      valid: 0..1;      -- exclusive to D2H_REQ, H2D_RSP, H2D_REQ, D2H_RSP
      
      mtype: MessageType;
      src: Node;        -- do not need a destination for verification; the destination is indicated by which array entry in the Net the message is placed
      vc: VCType;

      cqid:  CQIDType;  -- exclusive to D2H_REQ, H2D_RSP, H2D_DATA

      uqid:  UQIDType;  -- exclusive to D2H_RSP, D2H_DATA, H2D_REQ
      
      nt:    0..1;      -- exclusive to D2H_REQ

      chunkvalid: 0..1; -- exclusive to D2H_DATA, H2D_DATA
      poison:     0..1; -- exclusive to D2H_DATA, H2D_DATA
      
      bogus:      0..1; -- exclusive to D2H_DATA
      
      go_err:     0..1; -- exclusive to H2D_DATA
      
      rspdata: RspData; -- exclusive to H2D_RSP  -- MESI is defined as enum of {M, E, S, I}
      rsp_pre:    0..3; -- exclusive to H2D_RSP

      val: Value;       -- exclusive to D2H_DATA, H2D_DATA
      
      addr: Address;    -- exclusive to D2H_REQ, H2D_REQ

      -- Example Send:
      -- Send(valid?, ReadReq, src, )
      

      -- fwd_dst: Node;  -- for InvalidateReq and FwdMReq
      -- num_sharer: SharerNum; -- optional, tells requester how many InvalidateAcks to expect
    End;

  HomeState:
    Record
      -- state: enum { H_Valid, H_Invalid, 					--stable states
      -- 							HT_Pending }; 								--transient states during recall
      state: enum { 
              -- steady state
              H_M, 
              H_E, 
              H_S, 
              H_I, 					
              
              -- transient state
							HT_SI_A,
              HT_SE_A,
              HT_II_D,
              HT_IS_A,  --Added on 11/20/2025 
              HT_MM_D,
              HT_MI_AD, -- only for CLFlush
              HT_MI_D,
              HT_MI_A,
              HT_ME_AD,
              HT_ME_A,
              HT_ME_D,
              HT_EI_AD,
              HT_EI_A,
              HT_EI_D,
              HT_EE_AD,
              HT_EE_A,
              HT_EE_D,
              HT_ES_AD,
              HT_ES_A,
              HT_ES_D,
              
              HT_SE_A,
              HT_MS_AD,
              HT_MS_D,
              HT_MS_A
              }; 								
      owner: Node;	
      sharers: multiset [ProcCount] of Node;    --No need for sharers in this protocol, but this is a good way to represent them
      val: Value; 
      -- sharers: multiset [ProcCount] of Node;      -- sharer
      
      requester: Node;    -- Mingjian 
      request_type: MessageType;
      request_pre: 0..1;

      flag: enum{
              flag_EM_D, -- eg. if flag = 1 then at H_E, stop processing transactions, wait for data and then transition to M
              flag_EI_D,
              flag_EE_D,
              flag_ES_D
              };
    End;

  ProcState:
    Record
      -- state: enum { P_Valid, P_Invalid,
      --             PT_Pending, PT_WritebackPending
      --             };
      state: enum { 
              -- steady state
              P_M, 
              P_E, 
              P_S, 
              P_I, 					
              
              -- transient state
							PT_MI_GP,
              PT_IM_D,
              PT_IM_DA,
              PT_MI_A,
              PT_II_GOI,
              P_II_WP,
              P_II_GO,
              P_IE_GP,
              P_EI_GOI,
              P_EI_GP,
              P_SE_GOE,
              P_IS_D,
              P_IS_DA,
              P_IS_A,
              P_SI_GOI,
              P_SI_GP
              };
      val: Value;
      addr: Value; -- addr only 0 or 1 for simplicity
      PendingInvAcks: SharerNum;
    End;

----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
  HomeNodes:  array [Home] of HomeState;
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
         addr:Address;

         cqid: CQIDType;
         uqid: UQIDType;
         nt:  0..1;
         chunkvalid: 0..1;
         poison:    0..1;
         bogus:     0..1;
         go_err:    0..1;

         rspdata: RspData;
         rsp_pre: 0..3;

         );
var msg:Message;
Begin
  Assert (MultiSetCount(i:Net[dst], true) < NetMax) "Too many messages";
  msg.valid := 1;
  msg.mtype := mtype;
  msg.src   := src;
  msg.vc    := vc;
  msg.val         := val;
  msg.addr        := addr;
  
  msg.cqid  := cqid;
  msg.uqid  := uqid;

  msg.nt    := nt;
  msg.chunkvalid  := chunkvalid;    
  msg.poison      := poison;
  msg.bogus       := bogus;
  msg.go_err      := go_err;

  msg.rspdata     := rspdata;
  msg.rsp_pre     := rsp_pre;
  
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
-- modified by Jiahe, 2 address
Procedure AddToSharersList(n:Node, h: Home);
Begin
    if MultiSetCount(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n) = 0 then
      MultiSetAdd(n, HomeNodes[h].sharers);
    endif;
End;

-- modified by Jiahe, 2 address
Function IsSharer(n:Node, h: Home) : Boolean;
Begin
    return MultiSetCount(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n) > 0;
End;

Function IsSharerListEmpty(h: Home): Boolean;
Begin
  return MultiSetCount(i:HomeNode[h].sharers, true) = 0
End;

Procedure RemoveFromSharersList(n:Node, h: Home);
Begin
  if addr = 0 then
    MultiSetRemovePred(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n);
  else  
    MultiSetRemovePred(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n);
  endif
End;

-- Sends a message to all sharers except rqst
-- modified by Jiahe, 2 address
Procedure SendInvReqToSharers(rqst:Node, h: Home);
Begin
  for n:Node do
    if (IsMember(n, Proc) &
        MultiSetCount(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n) != 0)
    then
      RemoveFromSharersList(n, h);
      if n != rqst
      then 
        -- Send invalidation message here 
        Send(InvalidReq, n, h, VC1, UNDEFINED, rqst, UNDEFINED);
        
      endif;
    endif;
  endfor;
End;



Procedure HomeReceive(msg:Message, h:Home); --TODO:
var cnt:0..ProcCount;  -- for counting sharers
Begin
alias hs:HomeNodes[h].state do
alias hv:HomeNodes[h].val do

-- Debug output may be helpful:
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at home -- "; put HomeNodes.state;

  -- The line below is not needed in Valid/Invalid protocol.  However, the 
  -- compiler barfs if we put this inside a switch, so it is useful to
  -- pre-calculate the sharer count here
  cnt := MultiSetCount(i:HomeNodes[h].sharers, true);
  -- num_sharer := MultiSetCount(i:HomeNodes.sharers, true);

  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  switch HomeNodes.state
  case H_I:  -- Author: Yi Dong 11/20/2025
    switch msg.mtype 

    -- case ReadReq:
    --   HomeNodes.state := H_Shared;
    --   AddToSharersList(msg.src);
    --   Send(ReadAck, msg.src, HomeType, VC2, HomeNodes.val, UNDEFINED, UNDEFINED);
    -- case ReadReqX:
    --   HomeNodes.state := H_Modified;
    --   HomeNodes.owner := msg.src;
    --   Send(ReadAck, msg.src, HomeType, VC2, HomeNodes.val, UNDEFINED, 0);
    case RdCurr: --get the most current data, not change the existing state in any cache
      HomeNodes.state := H_I;
      Send(Data, msg.src, hs, H2D_DATA, hv, UNDEFINED, UNDEFINED);
    
    case CLFlush: --invalidate the cacheline specifiedin the address field. The typical response is GO-I
      HomeModes.state := H_I;
      Send(GO, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, I);
    
    case ItoMWr: --requests exclusive ownership of the cacheline address, writes the cacehline back to the Host. typical response is GO_WritePull
      HomeNodes.state := HT_II_D;
      HomeNodes.flag := flag_EI_D;
      Send(GO_WritePull, msg.src, H2D_RSP, UNDEFINED, UNDEFINED, UNDEFINED);
    
    case RdShared: --requests from the device for lines to be cached in Shared state.a
      HomeNodes.state := H_S; -- need to wait for notification when transfer from I to S 
      if (IsSharerListEmpty(hs)) then
        Send(GO, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, M);
      else
        Send(GO, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, S);
      endif;
      Send(Data, msg.src, hs, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, hs);

    case RdAny: --requests from the device for lines to be cached in Shared state.a
      HomeNodes.state := H_S; -- need to wait for notification when transfer from I to S 
      if (IsSharerListEmpty(hs)) then
        Send(GO, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, M);
      else
        Send(GO, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, S);
      endif;
      Send(Data, msg.src, hs, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, hs);
    
    case RdOwnNoData: --requests exclusive ownership of the cacheline address, no data transfer back to the device. typical response is GO_WritePull
      HomeNodes.state := H_E;
      HomeNodes.owner := msg.src;
      Send(GO, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, E);
    
    case WrCur: --requests exclusive ownership of the cacheline address, writes the cacehline back to the Host. typical response is GO_WritePull
      HomeNodes.state := H_E;
      HomeNodes.flag := flag_EI_D;
      Send(GO_WritePull, msg.src, H2D_RSP, UNDEFINED, UNDEFINED, UNDEFINED);
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_II_D:
    switch msg.mtype
    case Data:
      hs := H_I;
      hv := msg.val;
      Send(Data, requester, HomeType, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      undefine requester;
    case RspIFwdM:
      msg_processed := false;
    case RdCurr:
      msg_processed := false;
    case RdOwn:
      msg_processed := false;
    case RdShared:
      msg_processed := false;
    case RdAny:
      msg_processed := false;
    case RdOwnNoData:
      msg_processed := false;
    case ItoMWr:
      msg_processed := false;
    case WrCur:
      msg_processed := false;
    case CLFlush:
      msg_processed := false;
    case CleanEvict:
      msg_processed := false;
    case DirtyEvict:
      msg_processed := false;
    case CleanEvictNoData:
      msg_processed := false;
    case WOWrInv:
      msg_processed := false;
    case WOWrInvF:
      msg_processed := false;
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    case RspIHitI:
      msg_processed := false;
    case RspVHitV: 
      msg_processed := false;
    case RspIHitSE:
      msg_processed := false;
    case RspSHitSE:
      msg_processed := false;
    case RspSFwdM:
      msg_processed := false;
    case RspIFwdM:
      msg_processed := false;
    case RspVFwdV:
      msg_processed := false;
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;
  
  
  -- Mingjian
  '''
  RdCurr,
  RdOwn,
  RdShared,
  RdAny,
  RdOwnNoData,
  ItoMWr,
  WrCur,
  CLFlush,
  CleanEvict,
  DirtyEvict,
  CleanEvictNoData,
  -- WOWrInv,
  -- WOWrInvF,
  WrInv,
  CacheFlushed,
  '''

  case H_E:
    Assert (!IsUndefined(HomeNodes[h].owner)) 
       "HomeNodes has no owner, but line is Exclusive";
    Assert (cnt = 0) 
       "HomeNodes has sharer, but line is Exclusive";
    switch msg.mtype
    case RdCurr:
      -- read the current line, the requester could not cache it (Proc still in P_I)
      -- no rsp from host, only data
      hs := HT_EE_DA;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      Send(SnpCur, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);

    case RdOwn:
      hs := HT_EE_DA;
      HomeNodes[h].requester  := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;
      
      HomeNodes[h].owner      := msg.src;
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);

    case RdShared:
      hs := HT_ES_DA;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      AddToSharersList(msg.src, h);
      AddToSharersList(HomeNodes[h].owner, h);
      undefine HomeNodes[h].owner;
      Send(SnpData, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    
    case RdAny:
      hs := HT_ES_DA;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      AddToSharersList(msg.src, h);
      AddToSharersList(HomeNodes[h].owner, h);
      undefine HomeNodes[h].owner;
      Send(SnpData, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);

    case RdOwnNoData:
      

    case ItoMWr:
      hs := HT_EE_DA;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      HomeNodes[h].owner      := msg.src;
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case WrCur:
      hs := HT_EE_DA;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      HomeNodes[h].owner      := msg.src;
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case CLFlush:
      hs := HT_EI_DA;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      undefine HomeNodes[h].owner;
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case CleanEvict:
      hs := HT_EI_D;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;

      Send(GO_WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.cqid, 1);
      -- undefine HomeNodes[h].owner;
    case DirtyEvict:
      hs := HT_EI_D;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;

      Send(GO_WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.cqid, 1);
    case CleanEvictNoData:
      hs := H_I;

      Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);
    case WrInv:
      hs := HT_EI_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      '''
      Send(WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.cqid, 1);
      '''
    case CacheFlushed:
      hs := HT_EI_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      '''
      Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);
      '''
      
  case HT_EI_AD:
    switch msg.type
    case RspIHitSE:
      switch HomeNodes[h].request_type
      case CLFlush:
        hs  := H_I;
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case WrInv:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre := 0;

        Send(WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      case CacheFlushed:
        hs  := H_I;
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;

        Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
      else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

    case RspIFwdM:
      switch HomeNodes[h].request_type
      case CLFlush:
        hs  := HT_EI_D;
        '''
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        '''
      case WrInv:
        hs  := HT_EI_D;
        '''
        Send(WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
        '''
      case CacheFlushed:
        hs  := HT_EI_D;
        '''
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
        '''
      else
        ErrorUnhandledMsg(msg, HomeType);
      endswitch;
    
    case Data:
      switch HomeNodes[h].request_type
      case CLFlush:
        hs  := HT_EI_A;
        hv  := msg.val;
      case WrInv:
        hs  := HT_EI_A;
        hv  := msg.val;
      case CacheFlushed:
        hs  := HT_EI_A;
        hv  := msg.val;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endswitch;
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_EI_A:
    switch msg.type
    case RspIFwdM:
      switch HomeNodes[h].request_type
      case CLFlush:
        hs  := H_I;
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case WrInv:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre := 0;

        Send(WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      case CacheFlushed:
        hs  := H_I;
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;

        Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
      else
      ErrorUnhandledMsg(msg, HomeType);
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;
  
  case HT_EI_D:
    switch msg.type
    case Data:
      switch HomeNodes[h].request_type
      case CLFlush:
        hs  := H_I;
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case WrInv:
        if (HomeNodes[h].request_pre = 1) then
          hs  := HT_EI_D;
          HomeNodes[h].request_pre := 0;

          Send(WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          msg.uqid, 1);
        else 
          hs  := H_I;
          hv  := msg.val;

          Send(GO, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          I, 1);
          undefine HomeNodes[h].request_type;
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_pre;
        endif;
      case CacheFlushed:
        hs  := H_I;
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;

        Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
      case ItoMWr:
          hs  := H_I;
          hv  := msg.val;

          undefine HomeNodes[h].request_type;
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_pre;
      case WrCur:
        hs  := H_I;
          hv  := msg.val;

          undefine HomeNodes[h].request_type;
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_pre;
      else
        ErrorUnhandledMsg(msg, HomeType);
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_EE_AD:
    switch msg.type
    case RspIHitSE:
      switch HomeNodes[h].request_type
      case RdCurr:
        hs  := H_E;
        '''
        RdCur has no H2D_RSP
        '''
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case RdOwn:
        hs  := H_E;

        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        E, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case ItoMWr:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre  := 0;

        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
        
      case WrCur:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre  := 0;

        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

    case RspIFwdM:
      switch HomeNodes[h].request_type
      case RdCurr:
        hs  := HT_EE_D;
      case RdOwn:
        hs  := HT_EE_D;
      case ItoMWr:
        hs  := HT_EE_D;
      case WrCur:
        hs  := HT_EE_D;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endswitch;
    
    case Data:
      switch HomeNodes[h].request_type
      case RdCur:
        hs  := HT_EE_A;
        hv  := msg.val;
      case RdOwn:
        hs  := HT_EE_A;
        hv  := msg.val;
      case ItoMWr:
        hs  := HT_EE_A;
        hv  := msg.val;
      case WrCur:
        hs  := HT_EE_A;
        hv  := msg.val;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endswitch;
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_EE_A:
    switch msg.type
    case RspIFwdM:
      switch HomeNodes[h].request_type
      case RdCur:
        hs  := H_E;
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case RdOwn:
        hs  := H_E;

        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        E, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case ItoMWr:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre  := 0;

        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      case WrCur:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre  := 0;

        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      else
      ErrorUnhandledMsg(msg, HomeType);
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_EE_D:
    switch msg.type
    case Data:
      switch HomeNodes[h].request_type
      case RdCur:
        hs  := H_E;
        HomeNodes[h].val  := msg.val;

        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case RdOwn:
        hs  := H_E;
        HomeNodes[h].val  := msg.val;

        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        E, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case ItoMWr:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre  := 0;
        HomeNodes[h].val  := msg.val;

        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
        
      case WrCur:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre  := 0;
        HomeNodes[h].val  := msg.val;

        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      else
        ErrorUnhandledMsg(msg, HomeType);
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_ES_AD:
    switch msg.type
    case RspIHitSE:
      switch HomeNodes[h].request_type
      case RdShared:
        hs  := H_S;
        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        S, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case RdAny:
        hs  := H_S;

        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        S, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      '''
      case ItoMWr:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre  := 0;

        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
        
      case WrCur:
        hs  := HT_EI_D;
        HomeNodes[h].request_pre  := 0;

        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      '''
      else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

    case RspIFwdM:
      switch HomeNodes[h].request_type
      case RdShared:
        hs  := HT_ES_D;
      case RdAny:
        hs  := HT_ES_D;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endswitch;
    
    case Data:
      switch HomeNodes[h].request_type
      case RdShared:
        hs  := HT_ES_A;
        hv  := msg.val;
      case RdAny:
        hs  := HT_ES_A;
        hv  := msg.val;
      else
        ErrorUnhandledMsg(msg, HomeType);
      endswitch;
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_ES_A:
    case RspIFwdM:
      switch HomeNodes[h].request_type
      case RdShared:
        hs  := H_S;
        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        S, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case RdAny:
        hs  := H_S;
        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        S, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      else
      ErrorUnhandledMsg(msg, HomeType);
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_ES_D:
    case RspIFwdM:
      switch HomeNodes[h].request_type
      case RdShared:
        hs  := H_S;
        hv  := msg.val;

        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        S, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      case RdAny:
        hs  := H_S;
        hv  := msg.val;

        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        S, 1);
        Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
        UNDEFINED, UNDEFINED);
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_pre;
      else
      ErrorUnhandledMsg(msg, HomeType);
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;
  
  -- Jiahe
  case H_S: 
    Assert (IsUndefined(HomeNodes[h].owner) = true) 
       "HomeNodes has owner, but line is Shared";
    Assert (cnt != 0) 
       "HomeNodes has no sharer, but line is Shared";
    switch msg.mtype
    case RdShared:
      -- whether requester is a sharer or not, it can receive the data
      Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, UNDEFINED, S);
      Send(DATA, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[n].val, UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, h);
    
    case RdAny:
      -- define: RdAny receive a S-state cacheline
      -- whether requester is a sharer or not, it can receive the data
      Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, UNDEFINED, S);
      Send(DATA, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[n].val, UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, h);

    case RdCur:
      -- read the current line, the requester could not cache it (Proc still in P_I)
      -- no rsp from host, only data
      Send(DATA, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[n].val, UNDEFINED, UNDEFINED);
      
  
    case RdOwnNoData:
      -- upgrade the requester to E
      -- sharer or not, requester can receive the data
      if (cnt = 1) & IsSharer(msg.src, h) then
        Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, UNDEFINED, E);
        Send(DATA, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[n].val, UNDEFINED, UNDEFINED);
        AddToSharersList(msg.src, h);


      if (IsSharer(msg.src)) then
        Send(ReadAck, msg.src, HomeType, VC2, HomeNodes.val, UNDEFINED, cnt-1);
        if cnt = 1 then 
          HomeNodes.state := H_Modified;
        else 
          HomeNodes.state := HT_SMPENDING;
        endif;
        HomeNodes.owner := msg.src; --remember who the new owner will be
        SendInvReqToSharers(msg.src);
      else
        HomeNodes.state := HT_SMPENDING;
        Send(ReadAck, msg.src, HomeType, VC2, HomeNodes.val, UNDEFINED, cnt);

        HomeNodes.owner := msg.src; --remember who the new owner will be
        SendInvReqToSharers(msg.src);
      endif;

    case PutS:
      Send(WBAck, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED, UNDEFINED);
      if IsSharer(msg.src) = true then
        RemoveFromSharersList(msg.src);

        if cnt = 1 then -- originally 1 but reduced 1
          HomeNodes.state := H_Invalid;
        else  
          HomeNodes.state := H_Shared;
        endif;
      endif;
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;
    

    switch msg.mtype
    case RdShared:
      -- whether requester is a sharer or not, it can receive the data
      Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, UNDEFINED, S);
      Send(DATA, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[n].val, UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, h);
    
    case RdAny:
      -- define: RdAny receive a S-state cacheline
      -- whether requester is a sharer or not, it can receive the data
      Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, UNDEFINED, S);
      Send(DATA, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[n].val, UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, h);

    case RdCur:
      -- read the current line, the requester could not cache it (Proc still in P_I)
      -- no rsp from host, only data
      Send(DATA, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[n].val, UNDEFINED, UNDEFINED);
      
  
    case RdOwnNoData:
      -- upgrade the requester to E
      -- sharer or not, requester can receive the data
      if (cnt = 1) & IsSharer(msg.src, h) then
        Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, UNDEFINED, E);
        Send(DATA, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[n].val, UNDEFINED, UNDEFINED);
        AddToSharersList(msg.src, h);


      if (IsSharer(msg.src)) then
        Send(ReadAck, msg.src, HomeType, VC2, HomeNodes.val, UNDEFINED, cnt-1);
        if cnt = 1 then 
          HomeNodes.state := H_Modified;
        else 
          HomeNodes.state := HT_SMPENDING;
        endif;
        HomeNodes.owner := msg.src; --remember who the new owner will be
        SendInvReqToSharers(msg.src);
      else
        HomeNodes.state := HT_SMPENDING;
        Send(ReadAck, msg.src, HomeType, VC2, HomeNodes.val, UNDEFINED, cnt);

        HomeNodes.owner := msg.src; --remember who the new owner will be
        SendInvReqToSharers(msg.src);
      endif;

    case PutS:
      Send(WBAck, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED, UNDEFINED);
      if IsSharer(msg.src) = true then
        RemoveFromSharersList(msg.src);

        if cnt = 1 then -- originally 1 but reduced 1
          HomeNodes.state := H_Invalid;
        else  
          HomeNodes.state := H_Shared;
        endif;
      endif;
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HT_SMPENDING:
    switch msg.mtype
    case SMAck:
      HomeNodes.state := H_Modified;
    case PutS:
      Send(InvalidAck, HomeNodes.owner, HomeType, VC2, UNDEFINED, UNDEFINED, UNDEFINED);
    case ReadReq:
    	msg_processed := false; -- stall message in InBox
    case ReadReqX:
    	msg_processed := false; -- stall message in InBox
    case WBReq:
      HomeNodes.state := HT_IIPENDING;
      undefine HomeNodes.owner;
      HomeNodes.val := msg.val;
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;
  
  case HT_IIPENDING:
    switch msg.mtype
    case SMAck:
      HomeNodes.state := H_Invalid;
    case ReadReq:
    	msg_processed := false; -- stall message in InBox
    case ReadReqX:
    	msg_processed := false; -- stall message in InBox
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;
  
case H_M: -- Author: Ruihan 11/20
    Assert (IsUndefined(HomeNodes.owner) = false) 
       "HomeNodes has no owner, but line is Modified";

    switch msg.mtype
    case RdCurr: --updated
      hs := HT_MM_D;
      --Send(Data, msg.src, HomeType, H2D_DATA, hv, UNDEFINED, 0);
      Send(SnpCur, HomeNodes[h].owner, hs, H2D_REQ, UNDEFINED, UNDEFINED, UNDEFINED);

    case CLFlush: --updated
      hs := HT_MI_D;
      Send(SnpInv, HomeNodes[h].owner, hs, H2D_REQ, UNDEFINED, UNDEFINED, UNDEFINED);
      undefine HomeNodes[h].owner;

    case DirtyEvict: --updated
      assert (msg.src = HomeNodes[h].owner)
        "only owner can send DirtyEvict"
      hs := HT_MI_D;
      Send(GO_WritePull, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, 0, msg.cqid);  
      undefine HomeNodes[h].owner;

    case WrInv: --updated
      if (msg.src = HomeNodes[h].owner)
        hs := HT_MI_D;
        Send(WritePull, msg.src, hs, H2D_RSP); 
      else
        hs := HT_MI_DD;
        Send(SnpInv, HomeNodes[h].owner, hs, H2D_REQ, UNDEFINED, UNDEFINED, UNDEFINED); --get dirty copy back first
      endif;
      undefine HomeNodes[h].owner;

    case ItoMWr:
      hs := HT_ME_AD;
      HomeNodes[h].flag := flag_EI_D;
      Send(GO_WritePull, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, 0, msg.cqid);
      Send(SnpInv, HomeNodes[h].owner, hs, H2D_REQ, UNDEFINED, UNDEFINED, UNDEFINED); 
      homeNodes[h].owner := msg.src;

    case RdOwn:
      hs := HT_ME_AD;
      Send(GO_WritePull, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, 0, msg.cqid);
      Send(SnpInv, HomeNodes[h].owner, hs, H2D_REQ, UNDEFINED, UNDEFINED, UNDEFINED); -- even though it's a read req, the line should be in a writable state so treat as a write
      HomeNodes[h].owner := msg.src;

    case WrCur:
      hs := HT_ME_AD;
      Send(GO_WritePull, msg.src, hs, H2D_RSP, UNDEFINED, UNDEFINED, 0, msg.cqid);
      Send(SnpInv, HomeNodes[h].owner, hs, H2D_REQ, UNDEFINED, UNDEFINED, UNDEFINED);
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

-- the homenode must remember the requester, and forward data to it

  case HT_MI_AD:
    switch msg.mtype
    case Data:
      hs := HT_MI_A;
      hv := msg.val;
      Send(Data, requester, HomeType, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      undefine requester;
    case RspIFwdM:
      hs := HT_MI_D;

    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HT_MI_D:
    switch msg.mtype
    case Data:
      hs := H_I;
      hv := msg.val;
      Send(Data, requester, HomeType, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      undefine requester;
    else
      ErrorUnhandledMsg(msg, HomeType);

  endswitch;
  
  case HT_MI_A:
    switch msg.mtype

    case RspIFwdM:
      hs := H_I;
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HT_ME_AD:
    switch msg.mtype
    case Data:
      hs := HT_ME_A;
      hv := msg.val;
      Send(Data, requester, HomeType, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      undefine requester;
    case RspIFwdM:
      hs := HT_ME_D;

    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HT_ME_D:
    switch msg.mtype
    case Data:
      hs := H_E;
      hv := msg.val; 
      Send(Data, requester, HomeType, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      undefine requester;
    else
      ErrorUnhandledMsg(msg, HomeType); 
    endswitch;

  case HT_ME_A:
    switch msg.mtype
    case RspIFwdM:
      hs := H_E;
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;

  case HT_MS_AD:
    switch msg.mtype
    case Data:
      hs := HT_MS_A;
      hv := msg.val;
      Send(Data, requester, HomeType, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      undefine requester;
    case RspSFwdM:
      hs := HT_MS_D;

    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HT_MS_D:
    switch msg.mtype
    case Data:
      hs := H_S;
      hv := msg.val;
      Send(Data, requester, HomeType, H2D_DATA, hv, UNDEFINED, UNDEFINED);
      undefine requester;
    else
      ErrorUnhandledMsg(msg, HomeType); 
    endswitch;

  case HT_MS_A:
    switch msg.mtype
    case RspSFwdM:
      hs := H_S;
    
    else
      ErrorUnhandledMsg(msg, HomeType);
    endswitch;


  case HT_MPending:
    switch msg.mtype
   
    case WBReq:
      Assert (!IsUnDefined(HomeNodes.owner)) "owner undefined";
      if(HomeNodes.owner = msg.src) then
        Send(WBAck, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED, UNDEFINED);
        HomeNodes.val := msg.val;
        undefine HomeNodes.owner;
      else 
        HomeNodes.state := H_Modified;
        HomeNodes.val := msg.val;
        Send(ReadAck, HomeNodes.owner, HomeType, VC2, HomeNodes.val, UNDEFINED, 0);
      endif;
    case WBFwd:
      if (IsUnDefined(HomeNodes.owner)) then
        HomeNodes.state := H_Invalid;
      else 
        HomeNodes.state := H_Modified;
        HomeNodes.val := msg.val;
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
      Assert (IsUnDefined(HomeNodes.owner)&(cnt !=0)) "owner and sharer all undefined";
      HomeNodes.state := H_Shared;
      HomeNodes.val := msg.val;
      
      RemoveFromSharersList(msg.src);
      
      for n:Node do
        if (IsMember(n, Proc) & IsSharer(n)) then
          Send(ReadAck, n, HomeType, VC2, HomeNodes.val, UNDEFINED, UNDEFINED);
        endif;
      endfor;

    case WBShared:
      if (cnt != 0) then
        HomeNodes.state := H_Shared;
        HomeNodes.val := msg.val;
      else 
        HomeNodes.state := H_Invalid;
        HomeNodes.val := msg.val;
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
  endalias;
  endalias;
End;


Procedure ProcReceive(msg:Message; p:Proc);
Begin
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at proc "; put p; put "\n";
  home.
  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  alias ps:Procs[p].state do
  alias pv:Procs[p].val do
  alias p_pendinvack :Procs[p].PendingInvAcks do
  switch ps
  case P_Invalid:
    switch msg.mtype
    case ReadAck:
      pv := msg.val;
      ps := P_Shared;
    case ReadAckX:
      pv := msg.val;
      ps := P_Modified;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;




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
  HomeNodes.state := H_Invalid;
  undefine HomeNodes.owner;
  undefine HomeNodes.sharers;
  HomeNodes.val := v;
	endfor;
	LastWrite := HomeNodes.val;
  
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
  HomeNodes.state = H_Invalid
    ->
      IsUndefined(HomeNodes.owner);

invariant "value in memory matches value of last write, when invalid"
     HomeNodes.state = H_Invalid 
    ->
			HomeNodes.val = LastWrite;

-- Here are some invariants that are helpful for validating shared state.

invariant "modified implies empty sharers list"
  HomeNodes.state = H_Modified
    ->
      MultiSetCount(i:HomeNodes.sharers, true) = 0;

invariant "Invalid implies empty sharer list"
  HomeNodes.state = H_Invalid
    ->
      MultiSetCount(i:HomeNodes.sharers, true) = 0;

invariant "values in memory matches value of last write, when shared or invalid"
  Forall n : Proc Do	
     HomeNodes.state = H_Shared | HomeNodes.state = H_Invalid
    ->
			HomeNodes.val = LastWrite
	end;

invariant "values in shared state match memory"
  Forall n : Proc Do	
     HomeNodes.state = H_Shared & Procs[n].state = P_Shared
    ->
			HomeNodes.val = Procs[n].val
	end;

invariant "at most one flag = 1"
-- TODO

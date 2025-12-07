
-- two-state 4-hop VI protocol
-- very useful
/*
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
    case Data:
      msg_processed := false;
*/

/*
    case WritePull:
      msg_processed := false;
    case GO:
      msg_processed := false;
    case GO_WritePull:
      msg_processed := false;
    case ExtCmp:
      msg_processed := false;
    case GO_WritePull_Drop:
      msg_processed := false;
    case Reserved:
      msg_processed := false;
    case Fast_GO_WritePull:
      msg_processed := false;
    case GO_ERR_WritePull:
      msg_processed := false;
    case Data:
      msg_processed := false;
    case SnpData:
      msg_processed := false;
    case SnpInv:
      msg_processed := false;
    case SnpCur:
      msg_processed := false;
*/
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
  
  -- CQIDType: scalarset(MaxUQID);
  UQIDType: scalarset(MaxUQID);         --Mingjian Li
  MESIType: enum { M, E, S, I };
  RspData: union {UQIDType, MESIType };
  
  Value: 0..ValueCount; -- arbitrary values for tracking coherence
  Address: 0..AddrCount; 
  -- Home: enum { HomeType };      -- need enumeration for IsMember calls
  Node: union { Home , Proc };

  VCType: 0..NumVCs-1;
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
                      CacheFlushed, -- TODO: the processor can cache both addr 0 and 1, only send this when both addr are I
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
                      -- Data
                      Data
                    };

  Message:
    Record
      valid: 0..1;      -- exclusive to D2H_REQ, H2D_RSP, H2D_REQ, D2H_RSP
      
      mtype: MessageType;
      src: Node;        -- do not need a destination for verification; the destination is indicated by which array entry in the Net the message is placed
      vc: VCType;
      val: Value;       -- exclusive to D2H_DATA, H2D_DATA
      addr: Address;    -- exclusive to D2H_REQ, H2D_REQ

      cqid:  UQIDType;  -- exclusive to D2H_REQ, H2D_RSP, H2D_DATA
      uqid:  UQIDType;  -- exclusive to D2H_RSP, D2H_DATA, H2D_REQ
      nt:    0..1;      -- exclusive to D2H_REQ
      chunkvalid: 0..1; -- exclusive to D2H_DATA, H2D_DATA
      poison:     0..1; -- exclusive to D2H_DATA, H2D_DATA
      bogus:      0..1; -- exclusive to D2H_DATA
      go_err:     0..1; -- exclusive to H2D_DATA
      
      rspdata: RspData; -- exclusive to H2D_RSP  -- MESI is defined as enum of {M, E, S, I}
      rsp_pre:    0..3; -- exclusive to H2D_RSP
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
              HT_SI_D,
              HT_SI_AD,
              HT_SE_AD,
              HT_SE_D,
              HT_II_A,
              HT_II_D,
              HT_II_AD,
              HT_IS_A,  --Added on 11/20/2025 
              HT_IE_AD,
              HT_IE_D,
              HT_MM_AD,
              HT_MM_A,
              HT_MM_D,
              HT_MI_AD, -- only for CLFlush
              HT_MI_D,
              HT_MI_A,
              HT_MI_AD1,
              HT_MI_A1,
              HT_MI_D1,
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
              
              -- HT_SE_A,
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
              flag_ES_D,
              flag_SI_A
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

              PT_IM_A,
              PT_IM_D,
              PT_IM_AD,
              
              PT_MI_A,
              PT_II_GOI,
              PT_II_WP,
              PT_II_GO,
              PT_IE_GP,
              PT_EI_GOI,
              PT_EI_GP,
              PT_SE_GOE,
              
              PT_IS_A,
              PT_IS_D,
              PT_IS_AD,
              
              PT_SI_GOI,
              PT_SI_GP,
              PT_IE_AD,
              PT_IE_D, 
              PT_IE_A,
              PT_II_GP,
              PT_II_D,
              --todo
              PT_SE_A,
              PT_SM_GOE
              };
      val: Value;
      addr: Address; -- addr only 0 or 1 for simplicity
      -- PendingInvAcks: SharerNum;
      mem_write_val: Value;
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
  LastWrite0: Value; -- Used to confirm that writes to addr 0 are not lost;
  LastWrite1: Value; -- Used to confirm that writes to addr 1 are not lost;
----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure Send(mtype:MessageType;
	       dst:Node;
	       src:Node;
         vc:VCType;
         val:Value;
         addr:Address;

         cqid: UQIDType;
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
Procedure AddToSharersList(n:Node; h: Home);
Begin
    if MultiSetCount(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n) = 0 then
      MultiSetAdd(n, HomeNodes[h].sharers);
    endif;
End;

-- modified by Jiahe, 2 address
Function IsSharer(n:Node; h: Home) : Boolean;
Begin
    return MultiSetCount(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n) > 0;
End;

Function IsSharerListEmpty(h: Home): Boolean;
Begin
  return MultiSetCount(i:HomeNodes[h].sharers, true) = 0
End;

Procedure RemoveFromSharersList(n:Node; h: Home);
Begin
  -- if addr = 0 then
    MultiSetRemovePred(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n);
  -- else  
    -- MultiSetRemovePred(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n);
  -- endif
End;

-- Sends a message to all sharers except rqst
-- modified by Jiahe, 2 address
Procedure SendInvReqToSharers(rqst:Node; h: Home; msg: Message);
Begin
  for n:Node do
    if (IsMember(n, Proc) &
        MultiSetCount(i:HomeNodes[h].sharers, HomeNodes[h].sharers[i] = n) != 0)
    then
      RemoveFromSharersList(n, h);
      if n != rqst
      then 
        -- Send invalidation message here 
        --Send(InvalidReq, n, h, VC1, UNDEFINED, rqst, UNDEFINED);
        if h = Home0 then
          Send(SnpInv, n , h, H2D_REQ, UNDEFINED, 0, 
          UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          UNDEFINED, UNDEFINED);
        else
          Send(SnpInv, n , h, H2D_REQ, UNDEFINED, 1, 
          UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          UNDEFINED, UNDEFINED);
        endif;
      endif;
    endif;
  endfor;
End;



Procedure HomeReceive(msg:Message; h:Home); --TODO:
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

  switch HomeNodes[h].state
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
      hs := H_I;
      Send(Data, msg.src , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
    
    case RdOwn: --requests exclusive ownership of the cacheline address, writes the cacehline back to the Host. typical response is GO
        hs := HT_IE_AD;

        HomeNodes[h].requester := msg.src;
        HomeNodes[h].request_type := msg.mtype;
        HomeNodes[h].request_pre  := 1;
        
        HomeNodes[h].owner := msg.src;
        Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        E, 1);
        HomeNodes[h].owner := msg.src;

    case DirtyEvict: --evicts a dirty cacheline from the device to the home. typical response is GO_WritePull
      hs := HT_II_D;
      Send(GO_WritePull, msg.src , h, H2D_REQ, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;
    
    case CleanEvict: --evicts a clean cacheline from the device to the home. typical response is GO_I
      hs := HT_II_D;
      Send(GO_WritePull, msg.src , h, H2D_REQ, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;

    case CleanEvictNoData:
      hs := H_I;
      Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);

    case CLFlush: --invalidate the cacheline specifiedin the address field. The typical response is GO-I
      hs := H_I;
      Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);
    case ItoMWr: --requests exclusive ownership of the cacheline address, writes the cacehline back to the Host. typical response is GO
      hs := HT_II_D;
      --HomeNodes.flag := flag_EI_D; 
      Send(GO_WritePull, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1);
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;
    
    case RdShared: --requests from the device for lines to be cached in Shared state.a
       -- need to wait for notification when transfer from I to S 
      if (IsSharerListEmpty(h)) then
        hs := H_E;
        Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        E, 1);
        HomeNodes[h].owner := msg.src;
      else -- TODO: ccheck if this is necessary since in I state there should be no sharers
        hs := H_S;
        Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        S, 1);
        AddToSharersList(msg.src, h);
      endif;
      Send(Data, msg.src, h, H2D_DATA, hv, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0, 
      UNDEFINED, UNDEFINED);

    case RdAny: --requests from the device for lines to be cached in Shared state.a
       -- need to wait for notification when transfer from I to S 
      if (IsSharerListEmpty(h)) then
        hs := H_M;
        Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        M, 1);
        HomeNodes[h].owner := msg.src;
      else -- TODO: ccheck if this is necessary since in I state there should be no sharers
        hs := H_S;
        Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        S, 1);
        AddToSharersList(msg.src, h);
      endif;
      Send(Data, msg.src, h, H2D_DATA, hv, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
      
    
    case RdOwnNoData: --requests exclusive ownership of the cacheline address, no data transfer back to the device. typical response is GO
      hs := H_E;
      HomeNodes[h].owner := msg.src;
      Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      E, 1);


    case WrCur: --requests exclusive ownership of the cacheline address, writes the cacehline back to the Host. typical response is GO_WritePull
      -- hs := H_E;

      hs := HT_II_D;
      --HomeNodes.flag := flag_EI_D; 
      Send(GO_WritePull, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1);
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;
    
    
    case CacheFlushed:
      hs := H_I;
      -- HomeNodes[h].requester := msg.src;   -- TODO: TODO
      -- HomeNodes[h].request_type := msg.mtype;
      -- HomeNodes[h].request_pre  := 1;

      Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);

    case WrInv:
      hs := HT_II_D;
      Send(WritePull, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1);
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;
    else
      
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_II_AD:
    switch msg.mtype
    case RspIHitI:
      switch HomeNodes[h].request_type
      case ItoMWr:
      hs := HT_II_D;
      HomeNodes[h].owner := msg.src;
      Send(GO_WritePull, HomeNodes[h].owner, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1);
      case WrInv:
      hs := HT_II_D;
      Send(GO_WritePull, HomeNodes[h].owner, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1);
      else 
        ErrorUnhandledMsg(msg,  h);
      endswitch;

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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    case RspVHitV: 
      msg_processed := false;
    case RspIHitSE:
      msg_processed := false;
    case RspSHitSE:
      msg_processed := false;
    case RspSFwdM:
      msg_processed := false;
    case RspVFwdV:
      msg_processed := false;
    
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_IE_AD:
    switch msg.mtype
    case RspIHitSE:
      hs := HT_IE_D;
      Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1); 
      undefine HomeNodes[h].request_type;
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_pre;

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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    case RspIHitI:
      msg_processed := false;
    case RspVHitV: 
      msg_processed := false;
    case RspSHitSE:
      msg_processed := false;
    case RspSFwdM:
      msg_processed := false;
    case RspVFwdV:
      msg_processed := false;
    
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_IE_D:
    switch msg.mtype
    case Data:
      hs := H_E;
      HomeNodes[h].val  := msg.val;
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
    case RspIHitSE:
      msg_processed := false;
    case CLFlush:
      msg_processed := false;
    case CleanEvict:
      msg_processed := false;
    case DirtyEvict:
      msg_processed := false;
    case CleanEvictNoData:
      msg_processed := false;
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    case RspIHitI:
      msg_processed := false;
    case RspVHitV: 
      msg_processed := false;
    case RspSHitSE:
      msg_processed := false;
    case RspSFwdM:
      msg_processed := false;
    case RspVFwdV:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;
  
  case HT_II_D:
    switch msg.mtype
    case Data:
      hs := H_I;
      hv := msg.val;
      switch HomeNodes[h].request_type
        case ItoMWr:
          Assert (HomeNodes[h].request_pre = 0) "HT_II_D Data received, request_pre should be 0";
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_type;
          undefine HomeNodes[h].request_pre;
        case WrCur:
          Assert (HomeNodes[h].request_pre = 0) "HT_II_D Data received, request_pre should be 0";
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_type;
          undefine HomeNodes[h].request_pre;
        case WrInv:
          Assert (HomeNodes[h].request_pre = 0) "HT_II_D Data received, request_pre should be 0";
          Send(GO, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          I, 1);
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_type;
          undefine HomeNodes[h].request_pre;
        case CleanEvict:
          Assert (HomeNodes[h].request_pre = 0) "HT_II_D Data received, request_pre should be 0";
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_type;
          undefine HomeNodes[h].request_pre;
        case DirtyEvict:
          Assert (HomeNodes[h].request_pre = 0) "HT_II_D Data received, request_pre should be 0";
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_type;
          undefine HomeNodes[h].request_pre;
        else
          ErrorUnhandledMsg(msg,  h);
      endswitch;
      /*
      Send(Data, HomeNodes[h].requester, h, H2D_DATA, hv, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0, 
      UNDEFINED, UNDEFINED);
      undefine HomeNodes[h].requester;
      */
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
    case RspVFwdV:
      msg_processed := false;
    
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;
  
  
  -- Mingjian
  /*
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
  */

  case H_E:
    Assert (!IsUndefined(HomeNodes[h].owner)) 
       "HomeNodes has no owner, but line is Exclusive";
    Assert (cnt = 0) 
       "HomeNodes has sharer, but line is Exclusive";
    switch msg.mtype
    case RdCurr:
      -- read the current line, the requester could not cache it (Proc still in P_I)
      -- no rsp from host, only data
      hs := HT_EE_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      Send(SnpCur, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);

    case RdOwn:
      hs := HT_EE_AD;
      HomeNodes[h].requester  := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;
      
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      HomeNodes[h].owner      := msg.src;


    case RdShared:
      hs := HT_ES_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      AddToSharersList(msg.src, h);
      AddToSharersList(HomeNodes[h].owner, h);
      Send(SnpData, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      undefine HomeNodes[h].owner;

    
    case RdAny:
      hs := HT_ES_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      AddToSharersList(msg.src, h);
      AddToSharersList(HomeNodes[h].owner, h);
      Send(SnpData, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      undefine HomeNodes[h].owner;


    case RdOwnNoData:
      
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;
      Assert (HomeNodes[h].requester != HomeNodes[h].owner) "H_E should not receive RdOwnNoData from its owner";
      hs := HT_EE_AD;
      Send(SnpData, HomeNodes[h].owner, h, H2D_REQ, UNDEFINED, msg.addr,
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);

    case ItoMWr:
      hs := HT_EE_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      HomeNodes[h].owner      := msg.src;
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case WrCur:
      hs := HT_EE_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;

      HomeNodes[h].owner      := msg.src;
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case CLFlush:
      hs := HT_EI_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 1;
      
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      undefine HomeNodes[h].owner;
    case CleanEvict:
      hs := HT_EI_D;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;

      Send(GO_WritePull, HomeNodes[h].owner, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1);
      -- undefine HomeNodes[h].owner;
    case DirtyEvict:
      hs := HT_EI_D;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      HomeNodes[h].request_pre  := 0;

      Send(GO_WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1);
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
      /*
      Send(WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.cqid, 1);
      */
    case CacheFlushed:
      assert (msg.src != HomeNodes[h].owner) "CacheFlushed msg from owner";
      hs := H_E;
      -- HomeNodes[h].requester := msg.src;   -- TODO: TODO
      -- HomeNodes[h].request_type := msg.mtype;
      -- HomeNodes[h].request_pre  := 1;

      Send(GO, msg.src , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);
      /*
      Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);
      */
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;
      
  case HT_EI_AD:
    switch msg.mtype
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
      -- case CacheFlushed:
      --   hs  := H_I;
      --   undefine HomeNodes[h].request_type;
      --   undefine HomeNodes[h].requester;
      --   undefine HomeNodes[h].request_pre;

      --   Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      --   msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      --   I, 1);
      else
    
        ErrorUnhandledMsg(msg,  h);
      endswitch;

    case RspIFwdM:
      switch HomeNodes[h].request_type
      case CLFlush:
        hs  := HT_EI_D;
        /*
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        */
      case WrInv:
        hs  := HT_EI_D;
        /*
        Send(WritePull, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
        */
      -- case CacheFlushed:
      --   hs  := HT_EI_D;
        /*
        undefine HomeNodes[h].request_type;
        undefine HomeNodes[h].requester;
        Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
        */
      else
        ErrorUnhandledMsg(msg,  h);
      endswitch;
    
    case Data:
      switch HomeNodes[h].request_type
      case CLFlush:
        hs  := HT_EI_A;
        hv  := msg.val;
      case WrInv:
        hs  := HT_EI_A;
        hv  := msg.val;
      -- case CacheFlushed:
      --   hs  := HT_EI_A;
      --   hv  := msg.val;
      else
        ErrorUnhandledMsg(msg,  h);
      endswitch;
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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_EI_A:
    switch msg.mtype
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
      -- case CacheFlushed:
      --   hs  := H_I;
      --   undefine HomeNodes[h].request_type;
      --   undefine HomeNodes[h].requester;
      --   undefine HomeNodes[h].request_pre;

      --   Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      --   msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      --   I, 1);
      else
      ErrorUnhandledMsg(msg,  h);
      endswitch;
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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;
  
  case HT_EI_D:
    switch msg.mtype
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
      -- case CacheFlushed:
      --   hs  := H_I;
      --   undefine HomeNodes[h].request_type;
      --   undefine HomeNodes[h].requester;
      --   undefine HomeNodes[h].request_pre;

      --   Send(GO, HomeNodes[h].owner , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      --   msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      --   I, 1);
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
        ErrorUnhandledMsg(msg,  h);
      endswitch;
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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_EE_AD:
    switch msg.mtype
    case RspIHitSE:
      switch HomeNodes[h].request_type
      case RdCurr:
        
        hs  := H_E;
        
        -- RdCur has no H2D_RSP
        
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
        

      case RdOwnNoData:
      
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
      ErrorUnhandledMsg(msg,  h);
    endswitch;

    case RspIFwdM:
      switch HomeNodes[h].request_type
      case RdCurr:
        hs  := HT_EE_D;
      case RdOwn:
        hs  := HT_EE_D;
      case RdOwnNoData:
        hs  := HT_EE_D
      case ItoMWr:
        hs  := HT_EE_D;
      case WrCur:
        hs  := HT_EE_D;
      else
        ErrorUnhandledMsg(msg,  h);
      endswitch;
    
    case Data:
      switch HomeNodes[h].request_type
      case RdCurr:
        hs  := HT_EE_A;
        hv  := msg.val;
      case RdOwn:
        hs  := HT_EE_A;
        hv  := msg.val;
      case RdOwnNoData:
        hs  := HT_EE_A;
        hv  := msg.val; 
      case ItoMWr:
        hs  := HT_EE_A;
        hv  := msg.val;
      case WrCur:
        hs  := HT_EE_A;
        hv  := msg.val;
      else
        ErrorUnhandledMsg(msg,  h);
      endswitch;
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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_EE_A:
    switch msg.mtype
    case RspIFwdM:
      switch HomeNodes[h].request_type
      case RdCurr:
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
        ErrorUnhandledMsg(msg,  h);
      endswitch;
    case RdCurr:
      msg_processed := false;
    case RdShared:
      msg_processed := false;
    case RdAny:
      msg_processed := false;
    case RdOwnNoData:
      msg_processed := false;
    case CLFlush:
      msg_processed := false;
    case CleanEvict:
      msg_processed := false;
    case DirtyEvict:
      msg_processed := false;
    case CleanEvictNoData:
      msg_processed := false;
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_EE_D:
    switch msg.mtype
    case Data:
      switch HomeNodes[h].request_type
      case RdCurr:
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
      case RdOwnNoData:
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
        ErrorUnhandledMsg(msg,  h);
      endswitch;
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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_ES_AD:
    switch msg.mtype
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
      /*
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
      */
      else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

    case RspIFwdM:
      switch HomeNodes[h].request_type
      case RdShared:
        hs  := HT_ES_D;
      case RdAny:
        hs  := HT_ES_D;
      else
        ErrorUnhandledMsg(msg,  h);
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
        ErrorUnhandledMsg(msg,  h);
      endswitch;
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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_ES_A:
    switch msg.mtype
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
        ErrorUnhandledMsg(msg,  h);
      endswitch;
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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_ES_D:
    switch msg.mtype
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
        ErrorUnhandledMsg(msg,  h);
      endswitch;
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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    else
      ErrorUnhandledMsg(msg,  h);
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
      Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      S, 1);
      Send(Data, msg.src, h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, h);
    
    case RdAny:
      -- define: RdAny receive a S-state cacheline
      -- whether requester is a sharer or not, it can receive the data
      Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      S, 1);
      Send(Data, msg.src, h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, h);

    case RdCurr:
      -- read the current line, the requester could not cache it (Proc still in P_I)
      -- no rsp from host, only data
      Send(Data, msg.src, h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
      
  
    case RdOwnNoData:
      -- upgrade the requester to E
      -- sharer or not, requester can receive the data
      if IsSharer(msg.src, h) then
        if cnt = 1 then -- the only sharer request upgrade
          Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          E, 1);
          RemoveFromSharersList(msg.src, h);
          -- Send(Data, msg.src, h, H2D_DATA, UNDEFINED, HomeNode[h].val, UNDEFINED, UNDEFINED);
          hs := H_E;
          HomeNodes[h].owner := msg.src;
        else 
          SendInvReqToSharers(msg.src, h, msg);
          RemoveFromSharersList(msg.src, h);
          hs := HT_SE_AD;
          HomeNodes[h].requester := msg.src;
          HomeNodes[h].request_type := msg.mtype;
        endif
      else -- requester is not sharer
        if cnt = 0 then -- no sharer, impossible but write it defensively
          Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          E, 1);
          hs := H_E;
        else
          SendInvReqToSharers(msg.src, h, msg);
          hs := HT_SE_AD;
          HomeNodes[h].requester := msg.src;
          HomeNodes[h].request_type := msg.mtype;
        endif
      endif
    
    case RdOwn:
      -- upgrade the requester to E
      -- sharer or not, requester can receive the data
      if IsSharer(msg.src, h) then
        if cnt = 1 then -- the only sharer request upgrade
          Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          E, 1);
          RemoveFromSharersList(msg.src, h);
          Send(Data, msg.src, h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
          UNDEFINED, UNDEFINED);
          hs := H_E;
          HomeNodes[h].owner := msg.src;
        else 
          SendInvReqToSharers(msg.src, h, msg);
          RemoveFromSharersList(msg.src, h);
          hs := HT_SE_AD;
          HomeNodes[h].requester := msg.src;
          HomeNodes[h].request_type := msg.mtype;
        endif
      else -- requester is not sharer
        if cnt = 0 then -- no sharer, impossible but write it defensively
          Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          E, 1);
          Send(Data, msg.src, h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
          UNDEFINED, UNDEFINED);
          hs := H_E;
        else
          SendInvReqToSharers(msg.src, h, msg);
          hs := HT_SE_AD;
          HomeNodes[h].requester := msg.src;
          HomeNodes[h].request_type := msg.mtype;
        endif
      endif

    case WrCur:
      -- request from device(I)
      -- home inv all sharer, receive response, then grant the requester, request write into memory
      hs := HT_SI_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      SendInvReqToSharers(HomeNodes[h].owner, h, msg);
    
    case ItoMWr:
      -- request from device(I)
      -- home inv all sharer, receive response, then grant the requester, request write into memory
      hs := HT_SI_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      SendInvReqToSharers(HomeNodes[h].owner, h, msg);

    case CleanEvictNoData: 
      -- request from device(E/S)
      -- home send GO-I
      if cnt = 1 then -- the requester is the only sharer
        hs := H_I;
        Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
        RemoveFromSharersList(msg.src, h);
      else
        Send(GO, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
        RemoveFromSharersList(msg.src, h);
      endif

    case CLFlush:
      -- request from device(I)
      -- home send GO-I/GO-Err
      hs := HT_SI_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      SendInvReqToSharers(HomeNodes[h].owner, h, msg);

    case WrInv:
      -- request from devive(I)
      -- home inv other sharers, send WritePull to request, requester send data to home, home send GO-I/GO-Err
      hs := HT_SI_AD;
      HomeNodes[h].requester := msg.src;
      HomeNodes[h].request_type := msg.mtype;
      SendInvReqToSharers(HomeNodes[h].owner, h, msg);

    case CacheFlushed:
      assert(!IsSharer(msg.src, h)) "CacheFlushed from sharer";
      hs := H_S;
      -- HomeNodes[h].requester := msg.src;   -- TODO: TODO
      -- HomeNodes[h].request_type := msg.mtype;
      -- HomeNodes[h].request_pre  := 1;

      Send(GO, msg.src , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);

    else
      ErrorUnhandledMsg(msg,  h);

    endswitch;

  case HT_SI_AD:
    switch msg.mtype

    case RspIHitSE:
      if cnt = 0 then
        switch HomeNodes[h].request_type

        case CLFlush:
          hs := H_I;
          Send(GO, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          I, 1);
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_type;
          
        case WrInv:
          hs := HT_SI_D;
          Send(WritePull, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          msg.uqid, 1);
        
        case WrCur:
          hs := HT_SI_D;
          Send(GO_WritePull, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          msg.uqid, 1);

        case ItoMWr:
          hs := HT_SI_D;
          Send(GO_WritePull, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          msg.uqid, 1);

        else
          ErrorUnhandledMsg(msg,  h);
        endswitch
      endif

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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    case RspIHitI:
      msg_processed := false;
    case RspVHitV:
      msg_processed := false;
    -- case RspIHitSE:
    --   msg_processed := false;
    case RspSHitSE:
      msg_processed := false;
    case RspSFwdM:
      msg_processed := false;
    case RspIFwdM:
      msg_processed := false;
    case RspVFwdV:
      msg_processed := false;
    -- case Data:
    --  msg_processed := false;
      
    else
      ErrorUnhandledMsg(msg,  h);

    endswitch;
  
  case HT_SI_D:
    switch msg.mtype

    case Data:
      switch HomeNodes[h].request_type
      case WrInv:
        hs := H_I;
        HomeNodes[h].val := msg.val;
        Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
            msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
            I, 1);
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_type;

      case WrCur:
        hs := H_I;
        HomeNodes[h].val := msg.val;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_type;
        
      case ItoMWr:
        hs := H_I;
        HomeNodes[h].val := msg.val;
        undefine HomeNodes[h].requester;
        undefine HomeNodes[h].request_type;
        
      else
        ErrorUnhandledMsg(msg,  h);
      endswitch

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
    -- case Data:
    --  msg_processed := false;
      
    else
      ErrorUnhandledMsg(msg,  h);

    endswitch

  case HT_SE_AD:
    switch msg.mtype

    case RspIHitSE:
      --Assert (HomeNodes[h].request_type != UNDEFINED) "In HT_SE_AD, request_type should be defined";
      Assert (IsUndefined(HomeNodes[h].request_type) = false) "In HT_SE_AD, request_type should be defined"; 
      if cnt = 0 then
        switch HomeNodes[h].request_type

        case RdOwn:
          hs := H_E;
          Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          E, 1);
          Send(Data, HomeNodes[h].requester, h, H2D_DATA, HomeNodes[h].val, UNDEFINED,
          msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
          UNDEFINED, UNDEFINED);
          HomeNodes[h].owner := HomeNodes[h].requester;
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_type;

        case RdOwnNoData:
          Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          E, 1);
          -- Send(Data, HomeNodes[h].requester, h, H2D_DATA, UNDEFINED, HomeNode[h].val, UNDEFINED, UNDEFINED);
          HomeNodes[h].owner := HomeNodes[h].requester;
          undefine HomeNodes[h].requester;
          undefine HomeNodes[h].request_type;
        
        endswitch
      endif

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
    case WrInv:
      msg_processed := false;
    case CacheFlushed:
      msg_processed := false;
    case RspIHitI:
      msg_processed := false;
    case RspVHitV:
      msg_processed := false;
    -- case RspIHitSE:
    --  msg_processed := false;
    case RspSHitSE:
      msg_processed := false;
    case RspSFwdM:
      msg_processed := false;
    case RspIFwdM:
      msg_processed := false;
    case RspVFwdV:
      msg_processed := false;
    case Data:
      msg_processed := false;

    else
      ErrorUnhandledMsg(msg,  h);
    
    endswitch
  
  
case H_M: -- Author: Ruihan 11/20
    Assert (IsUndefined(HomeNodes[h].owner) = false) 
       "HomeNodes has no owner, but line is Modified";

    HomeNodes[h].requester := msg.src;
    HomeNodes[h].request_type := msg.mtype;

    switch msg.mtype
    case RdCurr: --updated
      assert (msg.src != HomeNodes[h].owner)
        "owner should not request RdCurr";
      hs := HT_MM_AD; --waiting for data and snoop rsp from owner, update memory, send data but no GO
      Send(SnpCur, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      
    case CLFlush: --updated
      hs := HT_MI_AD; --waiting for data and snoop rsp from owner, update memory, send GO_I
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      undefine HomeNodes[h].owner;

    case DirtyEvict: --updated
      assert (msg.src = HomeNodes[h].owner)
        "only owner can request DirtyEvict";
      -- assert "only one DirtyEvict per device cacheline"
      hs := HT_MI_D; --waiting for data from owner=requester, update memory
      Send(GO_WritePull, msg.src, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      msg.uqid, 1);
      undefine HomeNodes[h].owner;

    case WrInv: --updated
      assert (msg.src != HomeNodes[h].owner)
        "owner should not request WrInv";
      hs := HT_MI_AD1; --waiting for data and snoop rsp from owner, update memory, send WritePull to requester, wait for data from requester, update memory, send GO_I
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      undefine HomeNodes[h].owner;

    case ItoMWr:
      assert (msg.src != HomeNodes[h].owner)
        "owner should not request ItoMWr";
      hs := HT_MI_AD1; --waiting for data and snoop rsp from owner, update memory, send GO_WritePull to requester, wait for data from requester, update memory
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      HomeNodes[h].owner := msg.src; -- grant exclusive ownership to requester until it sends the data back 

    case RdOwn:
      assert (msg.src != HomeNodes[h].owner)
        "owner should not request RdOwn";
      hs := HT_ME_AD; --waiting for data and snop rsp from owner, update memory, send GO and data to requester
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED); -- even though it s a read req, the line should be in a writable state so treat as a write
      HomeNodes[h].owner := msg.src;

    case WrCur:
      assert (msg.src != HomeNodes[h].owner)
        "owner should not request WrCur";
      hs := HT_MI_AD1; --waiting for data and snoop rsp from owner, update memory, send GO_WritePull to requester, wait for data from requester, update memory
      Send(SnpInv, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);


    case RdShared:
      assert (msg.src != HomeNodes[h].owner)
        "owner should not request RdShared";
      hs := HT_MS_AD; --waiting for data and snoop rsp from owner, update memory, send GO and data to requester
      Send(SnpData, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, h);
      undefine HomeNodes[h].owner;

    case RdAny:
      assert (msg.src != HomeNodes[h].owner)
        "owner should not request RdAny";
      hs := HT_MS_AD; --waiting for data and snoop rsp from owner, update memory, send GO and data to requester
      Send(SnpData, HomeNodes[h].owner , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      AddToSharersList(msg.src, h);
      undefine HomeNodes[h].owner;

    case CacheFlushed:
      assert (msg.src != HomeNodes[h].owner) "CacheFlushed msg from non-owner";
      hs := H_M;
      -- HomeNodes[h].requester := msg.src;   -- TODO: TODO
      -- HomeNodes[h].request_type := msg.mtype;
      -- HomeNodes[h].request_pre  := 1;

      Send(GO, msg.src , h, H2D_REQ, UNDEFINED, msg.addr, 
      UNDEFINED, msg.cqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);

    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MM_AD:
    switch msg.mtype
    case Data:
      hs := HT_MM_A; 
      Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED); --send here or send after getting snp rsp?
    case RspVFwdV:
      hs := HT_MM_D;    

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

    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MM_A:
    switch msg.mtype
    case RspVFwdV:
      hs := H_M;
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type;

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
    case Data:
      msg_processed := false;

    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MM_D:
    switch msg.mtype
    case Data:
      hs := H_M;
      Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type;

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
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MI_AD1: -- 1 suffix means it is receiving data from owner, there will be one more *_D in the future for requester
    switch msg.mtype
    case Data:
      hs := HT_MI_A1; 
      hv := msg.val;
    case RspIFwdM: -- any other possible message here?
      hs := HT_MI_D1;   

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
    case RspVFwdV:
      msg_processed := false;
 
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MI_A1:
    switch msg.mtype
    case RspIFwdM:
      hs := HT_MI_D;
      switch HomeNodes[h].request_type
      case WrInv:
        Send(WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      case ItoMWr:
        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      case WrCur:
        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      else
        ErrorUnhandledState();
      endswitch;
  
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
    case RspVFwdV:
      msg_processed := false;
    case Data:
      msg_processed := false;

    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MI_D1:
    switch msg.mtype
    case Data:
      hs := HT_MI_D; 
      hv := msg.val;
      switch HomeNodes[h].request_type
      case WrInv:
          Send(WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
          msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
          msg.uqid, 1);
      case ItoMWr:
        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      case WrCur:
        Send(GO_WritePull, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        msg.uqid, 1);
      else  
        ErrorUnhandledState();
      endswitch;

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
      ErrorUnhandledMsg(msg,  h);
    endswitch;  

  case HT_MI_AD:
    assert (HomeNodes[h].request_type = CLFlush)
      "only CLFlush should be here";
    switch msg.mtype
    case Data:
      hs := HT_MI_A;
      hv := msg.val;
      Send(GO, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      I, 1);
    case RspIFwdM:
      hs := HT_MI_D;   

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
    case RspVFwdV:
      msg_processed := false;
 
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MI_A:
    switch msg.mtype
    case RspIFwdM:
      hs := H_I;
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type; 

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
    case RspVFwdV:
      msg_processed := false;
    case Data:
      msg_processed := false;

    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;  

  case HT_MI_D:
    switch msg.mtype
    case Data:
      hs := H_I;
      hv := msg.val;
      switch HomeNodes[h].request_type
      case DirtyEvict:
        -- nothing to send back
      case WrInv:
        Send(GO, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
      case CLFlush:
        Send(GO, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
        msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        I, 1);
      else
        ErrorUnhandledState();
      endswitch;
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type;

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
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_ME_AD:
    switch msg.mtype
    case Data:
      hs := HT_ME_A;
      hv := msg.val;
      Send(GO, HomeNodes[h].requester , h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      E, 1);
      Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
    case RspIFwdM:
      hs := HT_ME_D;   

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
    case RspVFwdV:
      msg_processed := false;
 
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_ME_A:
    switch msg.mtype
    case RspIFwdM:
      hs := H_M;
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type;

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
    case RspVFwdV:
      msg_processed := false;
    case Data:
      msg_processed := false;

    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_ME_D:
    switch msg.mtype
    case Data:
      hs := H_M;
      hv := msg.val;
      Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
      Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      E, 1);
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type;

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
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MS_AD:
    switch msg.mtype
    case Data:
      hs := HT_MS_A;
      hv := msg.val;
      Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      S, 1);
      Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
    case RspIFwdM:
      hs := HT_MS_D; 

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
    case RspVFwdV:
      msg_processed := false;
   
    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  case HT_MS_A:
    switch msg.mtype
    case RspIFwdM:
      hs := H_S;
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type;

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
    case RspVFwdV:
      msg_processed := false;
    case Data:
      msg_processed := false;

    else
      ErrorUnhandledMsg(msg,  h);
    endswitch;    

  case HT_MS_D:  
    switch msg.mtype
    case Data:
      hs := H_S;
      hv := msg.val;
      Send(Data, HomeNodes[h].requester , h, H2D_DATA, HomeNodes[h].val, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, 0, 0, UNDEFINED, 0,
      UNDEFINED, UNDEFINED);
      Send(GO, HomeNodes[h].requester, h, H2D_RSP, UNDEFINED, UNDEFINED, 
      msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      S, 1);
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type;

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
      ErrorUnhandledMsg(msg,  h);
    endswitch;

  endswitch;
  endalias;
  endalias;
End;


Procedure ProcReceive(msg:Message; p:Proc);
Begin
--  put "Receiving "; put msg.mtype; put " on VC"; put msg.vc; 
--  put " at proc "; put p; put "\n";
  -- home.
  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  alias ps:Procs[p].state do
  alias pv:Procs[p].val do
  alias paddr:Procs[p].addr do
  -- alias p_pendinvack :Procs[p].PendingInvAcks do
  switch ps
  case P_I:
    switch msg.mtype
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_IS_AD:
    switch msg.mtype
    case GO:
      if msg.rspdata = S then 
        ps  := PT_IS_D;
      elsif msg.rspdata = E then
        ps  := PT_IE_D;
      else 
        msg_processed := false;
      endif;
    case Data:
        pv := msg.val;
        ps := PT_IS_A;
    
    -- impossible to receive other message in I state

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_IS_A:
    switch msg.mtype
    case GO:
      if msg.rspdata = S then 
        ps  := P_S;
      elsif msg.rspdata = E then
        ps  := P_E;
      else 
        msg_processed := false;
      endif;

    -- impossible to receive other message in I state
  
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
    
  case PT_IS_D:
    switch msg.mtype
    case Data:
      pv := msg.val;
      ps := P_S;
      
    -- impossible to receive other message in I state

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  case PT_IM_AD:
    switch msg.mtype
    case GO:
      if msg.rspdata = M then
        ps := PT_IM_D;
      else
        msg_processed := false;
      endif;
    case Data:
      pv := msg.val;
      ps := PT_IM_A;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_IM_D:
    switch msg.mtype
    case Data:
      pv := msg.val;
      ps := P_M;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_IM_A:
    switch msg.mtype
    case GO:
      if msg.rspdata = M then
        ps := P_M;
      else
        msg_processed := false;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  case PT_SI_GOI:
    switch msg.mtype
    case GO:
      Assert (msg.rspdata = I) "The GO received should be GO-I";
      ps := P_I;
      undefine paddr;
      undefine pv;
      
    case SnpInv:
      ps := PT_II_GOI;
      Send(RspIHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED ,
        UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      undefine paddr;
      undefine pv;

    case SnpCur:
      Send(RspSHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED ,
          UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
          UNDEFINED, UNDEFINED);
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED,
        UNDEFINED, msg.uqid, UNDEFINED, 0, 0, 0, UNDEFINED, 
        UNDEFINED, UNDEFINED);
        
    case SnpData:
      Send(RspSHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED ,
        UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);

    -- impossible to receive other message in I state
    
    else
      ErrorUnhandledMsg(msg, p);

    endswitch;
      
  case PT_II_D:
    switch msg.mtype
    case Data:
      pv := msg.val;
      ps := P_I;

    -- impossible to receive other message in I state

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  
  case PT_II_GOI:
    switch msg.mtype
    case GO:
      Assert (msg.rspdata = I) "The GO received should be GO-I";
      ps := P_I;

    -- impossible to receive other message in I state

    else
      ErrorUnhandledMsg(msg, p);

    endswitch;
      
  case PT_II_WP:
    switch msg.mtype
    case WritePull:
      ps  := PT_II_GO;
      Send(Data, msg.src, p, D2H_DATA, Procs[p].mem_write_val, UNDEFINED,
      UNDEFINED, msg.cqid, UNDEFINED, 0, 0, 0, UNDEFINED, 
      UNDEFINED, UNDEFINED);
      undefine Procs[p].mem_write_val;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
      
  case PT_II_GO:
    switch msg.mtype
    case GO:
      if msg.rspdata = I then
        ps  := P_I;
      else
        msg_processed   := false;
      endif;
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_II_GP:
    switch msg.mtype
    
    case GO_WritePull:
      ps := P_I;
    
    else
      ErrorUnhandledMsg(msg, p);

    endswitch;

  case PT_IE_GP:
    switch msg.mtype
    
    case GO_WritePull:
      ps := P_E;
      Send(Data, msg.src, p, D2H_DATA, Procs[p].mem_write_val, UNDEFINED,
        UNDEFINED, msg.cqid, UNDEFINED, 0, 0, 0, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      undefine Procs[p].mem_write_val;
    else
      ErrorUnhandledMsg(msg, p);

    endswitch;  
  
  case P_E:
    switch msg.mtype
    case SnpCur:
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspVFwdV, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case SnpData:
      ps  := P_S;
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspSHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case SnpInv:
      ps  := P_I;
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspIHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  case PT_EI_GOI:
    switch msg.mtype
    case GO:
      if msg.rspdata = I then
        ps  := P_I;
        undefine pv;
        undefine paddr;
      else
        msg_processed := false;
      endif;
    case SnpCur:
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspVFwdV, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case SnpData:
      ps  := PT_SI_GOI;
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspSHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case SnpInv:
      ps  := PT_II_GOI;
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspIHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  case PT_EI_GP:
    switch msg.mtype
    case GO_WritePull:
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      ps  := P_I;
      undefine pv;
      undefine paddr;
    case SnpCur:
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspVFwdV, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case SnpData:
      ps  := PT_SI_GP;
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspSHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case SnpInv:
      ps  := PT_II_GP;
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspIHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  
  case PT_MI_GP:
    switch msg.mtype
    case GO_WritePull:
      assert (msg.rspdata = I) "The GO received should be GO-I";
      ps := P_I;
      Send(Data, msg.src, p, D2H_DATA, pv, Procs[p].addr, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      undefine paddr;
      undefine pv;
    case SnpCur:
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspVFwdV, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case SnpData:
      ps  := PT_SI_GP;
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspSHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    case SnpInv:
      ps  := PT_II_GP;
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspIHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
    
  case PT_SE_A:
    switch msg.mtype
    
    case GO:
      assert (msg.rspdata = E) "The GO received should be GO-E";
      ps := P_E;

    case SnpCur:
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspSHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);

    -- impossible to receice SnpData

    case SnpInv:
      ps  := PT_IE_AD;
      Send(RspIHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      undefine paddr;
      undefine pv;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;



  case PT_SM_GOE:
    switch msg.mtype
    
    case GO:
      assert (msg.rspdata = E) "The GO received should be GO-E";
      ps := P_E;

    case SnpCur:
      Send(Data, msg.src, p, D2H_DATA, pv, UNDEFINED, 
      UNDEFINED, msg.uqid, 0, 0, UNDEFINED, 0, UNDEFINED,
      UNDEFINED, UNDEFINED);
      Send(RspVFwdV, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);

    -- impossible to receice SnpData

    case SnpInv:
      ps  := PT_IE_AD;
      Send(RspIHitSE, msg.src, p, D2H_RSP, UNDEFINED, UNDEFINED, 
      UNDEFINED, msg.uqid, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
      UNDEFINED, UNDEFINED);
      undefine paddr;
      undefine pv;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  case PT_IE_AD:
    switch msg.mtype

    case Data:
      ps := PT_IE_A;
      paddr := msg.addr;
      pv := msg.val

    case GO:
      Assert (msg.rspdata = E) "The GO received should be GO-E";
      ps := PT_IE_D;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;
  
  case PT_IE_A:
    switch msg.mtype

    case GO:
      Assert (msg.rspdata = E) "The GO received should be GO-E";
      ps := P_E;
    
    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PT_IE_D:
    switch msg.mtype

    case Data:
      ps := P_E;
      paddr := msg.addr;
      pv := msg.val
    
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
ruleset ad: Address do  
  alias p:Procs[n] Do
  
  ruleset id: UQIDType Do
  rule "device in state I, send RdOwn"
    p.state = P_I
  ==>
    p.state := PT_IM_AD;   
    p.addr  := ad;   
      if ad = 0 then
        
        Send(RdOwn, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(RdOwn, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  rule "device in state I, send RdAny"
    p.state = P_I
  ==>
    p.state := PT_IM_AD;   
    p.addr  := ad;     
      if ad = 0 then
        Send(RdAny, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(RdAny, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  ruleset v:Value Do
  rule "device in state I, send WrInv"
    p.state = P_I
  ==>
    p.state := PT_II_WP;   
    p.mem_write_val := v;   
      if ad = 0 then
        Send(WrInv, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(WrInv, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;
  endruleset;

  rule "device in state E, send CleanEvict"
    p.state = P_E
  ==>
    p.state := PT_EI_GP;      
      if ad = 0 then
        Send(CleanEvict, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(CleanEvict, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  rule "device in state E, send CleanEvictNoData"
    p.state = P_E
  ==>
    p.state := PT_EI_GOI;    
      if ad = 0 then
        Send(CleanEvictNoData, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(CleanEvictNoData, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
    undefine p.val;
    undefine p.addr; 
  endrule;

  rule "device in state I, send WrCur"
    (p.state = P_I)
    ==>
      p.state := PT_IE_GP;      
      if ad = 0 then
        Send(WrCur, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(WrCur, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  ruleset v:Value Do
    rule "device in state I, send ItoMWr"
      (p.state = P_I)
      ==>
        p.state := PT_IE_GP; 
        p.mem_write_val := v;
        if ad = 0 then
          Send(ItoMWr, Home0, n, D2H_REQ, UNDEFINED, ad,
          id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
          UNDEFINED, UNDEFINED);
        else
          Send(ItoMWr, Home1, n, D2H_REQ, UNDEFINED, ad,
          id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
          UNDEFINED, UNDEFINED);
        endif;
    endrule;
  endruleset;

  rule "device in state I, send RdShared"
    (p.state = P_I)
    ==>
      p.state := PT_IS_AD;      
      if ad = 0 then
        Send(RdShared, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(RdShared, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  rule "device in state I, send RdCurr"
    (p.state = P_I)
    ==>
      p.state := PT_II_D;
      if ad = 0 then
        Send(RdCurr, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(RdCurr, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  rule "device in state S, send CleanEvict"
    (p.state = P_S)
    ==>
      p.state := PT_SI_GP;
      if ad = 0 then
        Send(CleanEvict, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(CleanEvict, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  rule "device in state S, send CleanEvictNoData"
    (p.state = P_S)
    ==>
      p.state := PT_SI_GOI;
      if ad = 0 then
        Send(CleanEvictNoData, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(CleanEvictNoData, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  rule "device in state S, send RdOwnNoData"
    (p.state = P_S)
    ==>
      p.state := PT_SE_A;      
      if ad = 0 then
        Send(RdOwnNoData, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(RdOwnNoData, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  -- rule "device in state S, send RdOwnNoData"
  --   (p.state = P_S)
  --   ==>
  --     p.state := PT_SM_GOE;      
  --     if ad = 0 then
  --       Send(RdOwnNoData, Home0, n, D2H_REQ, UNDEFINED, ad,
  --       id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
  --       UNDEFINED, UNDEFINED);
  --       Send(RdOwnNoData, Home1, n, D2H_REQ, UNDEFINED, ad,
  --       id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
  --       UNDEFINED, UNDEFINED);
  --     endif;
  -- endrule;

  



  
  rule "device in state I, send CLFlush"
    (p.state = P_I)
    ==>
      p.state := PT_II_GOI;      
      if ad = 0 then
        Send(CLFlush, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(CLFlush, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  rule "device in state I, send CacheFlushed"
    (p.state = P_I) & (IsUndefined(p.val))
    ==>
      p.state := PT_II_GOI;      
      if ad = 0 then
        Send(CacheFlushed, Home0, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      else
        Send(CacheFlushed, Home1, n, D2H_REQ, UNDEFINED, ad,
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, 
        UNDEFINED, UNDEFINED);
      endif;
  endrule;

  rule "device in state M, send DirtyEvict"
    (p.state = P_M)
    ==>
      p.state := PT_MI_GP;
      if ad = 0 then
        Send(DirtyEvict, Home0, n, D2H_REQ, p.val, ad, 
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        UNDEFINED, UNDEFINED);
      else
        Send(DirtyEvict, Home1, n, D2H_REQ, p.val, ad, 
        id, UNDEFINED, 0, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED,
        UNDEFINED, UNDEFINED);
      endif;
      undefine p.val;
  endrule;
  endruleset;
  

  ruleset v:Value Do
    rule "device in state E, store data"
      p.state = P_E
    ==>
      p.state := P_M;      
      p.val   := v;
    endrule;
  endruleset;

  

  endalias;
endruleset;
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
        HomeReceive(msg, n);
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
        HomeReceive(InBox[n][vc], n);
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

	For h:Home do
      -- home node initialization
      HomeNodes[h].state := H_I;
      undefine HomeNodes[h].owner;
      undefine HomeNodes[h].sharers;
      undefine HomeNodes[h].requester;
      undefine HomeNodes[h].request_type;
      HomeNodes[h].val := 0;
	endfor;
	LastWrite0 := HomeNodes[Home0].val;
  LastWrite1 := HomeNodes[Home1].val;
  
  -- processor initialization
  for i:Proc do
    Procs[i].state := P_I;
    undefine Procs[i].val;
    undefine Procs[i].addr;
    undefine Procs[i].mem_write_val;
    -- undefine Procs[i].PendingInvAcks;
  endfor;

  -- network initialization
  undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "Invalid implies empty owner"
  Forall h : Home Do	
      HomeNodes[h].state = H_I
    ->
      IsUndefined(HomeNodes[h].owner)
  end;

invariant "value in addr0 matches value of last write, when invalid"
  -- Forall h : Home Do	
      HomeNodes[Home0].state = H_I | HomeNodes[Home0].state = H_S
    ->
			HomeNodes[Home0].val = LastWrite0;
  -- end;

invariant "value in addr1 matches value of last write, when invalid"
  -- Forall h : Home Do	
      HomeNodes[Home1].state = H_I | HomeNodes[Home1].state = H_S
    ->
			HomeNodes[Home1].val = LastWrite1;
  -- end;

-- Here are some invariants that are helpful for validating shared state.

invariant "modified implies empty sharers list"
  Forall h : Home Do	
      HomeNodes[h].state = H_M
    ->
      MultiSetCount(i:HomeNodes[h].sharers, true) = 0
  end;

invariant "Invalid implies empty sharer list"
  Forall h : Home Do	
      HomeNodes[h].state = H_I
    ->
      MultiSetCount(i:HomeNodes[h].sharers, true) = 0
  end;
/*
invariant "values in memory matches value of last write, when shared or invalid"
  Forall n : Proc Do	
     HomeNodes.state = H_S | HomeNodes.state = H_I
    ->
			HomeNodes.val = LastWrite
	end;
*/
invariant "addr 0 values in shared state match memory"
  Forall n : Proc Do	
     HomeNodes[Home0].state = H_S & Procs[n].state = P_S & Procs[n].addr = 0
    ->
			HomeNodes[Home0].val = Procs[n].val
	end;

invariant "addr 1 values in shared state match memory"
  Forall n : Proc Do	
     HomeNodes[Home1].state = H_S & Procs[n].state = P_S & Procs[n].addr = 1
    ->
			HomeNodes[Home1].val = Procs[n].val
	end;


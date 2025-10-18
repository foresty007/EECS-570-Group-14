// This is the definition header
// 6 channel 
// D2H: request, response, data
// H2D: request, response, data
// define a struct for each transaction
// sys_defs.svh

// For PACKET define, 68B Flit is used in Width(Bits) from 
// TODO: difference between 68B/256B/PBR Flit for packet width

`ifndef __SYS_DEFS_SVH__
`define __SYS_DEFS_SVH__
// all files should `include "sys_defs.svh" to at least define the timescale
`timescale 1ns/100ps


typedef struct packed{
    logic valid;
    logic [4:0] opcode; // operation of the request (15 types of opcode in total)
    logic [11:0] cqid;  // Common Queue ID: ThisThe CQID field contains the ID of the tracker
                        // entry that is associated with the request. When the response and
                        // data are returned for this request, the CQID is sent in the response
                        // or data message indicating to the device which tracker entry
                        // originated this request.
    logic nt;           // For cacheable reads, the NonTemporal bit is used as a hint to
                        // indicate to the host how it should be cached.
                        // 0: default behavior, this h
                        // 1: requested line should be moved to least recently used(LR)
    // logic cacheID 0bit not supported in 68B flit message
    
    logic [45:0] address; // 46-bit address space
    // logic spid;          // source PID not supported in 68B/256B
    // logic dpid;          // destination PID not supported in 68B/256B
    logic [13:0] rsvd;      // 68B flit, 7 bits in 256B/PBR Flit

} D2H_REQUEST_PACKET;

typedef struct packed{
    logic           valid;
    logic [4:0]     opcode;
    logic [11:0]    uqid;       // Unique Queue ID: This is a relection of the UQID field sent in the
                                // original request. It allows the device to identify which
                                // request this response is associated with.i
    logic [1:0]     rsvd;       // Reserved bits/fields used for alignment or future features. Always write 0, ignore on read, never use or depend on them.
} D2H_RESPONSE_PACKET;

typedef struct packed{
    logic           valid;
    logic [11:0]    uqid;
    logic           chunkvalid; // In case of 64B cacheline, this bit indicates which 32B chunk is valid.
                                // 0: lower 32B valid
                                // 1: upper 32B valid
    logic           bogus;      // Indicates that the data associated with this evict message was returned to a snoop
                                // after the D2H request wasa sent from the device, but before a WritePull was received for the evict
                                // This data is no longer the most current so it should be dropped by the Host
    logic           poison;     // Indicates that the data associated with this evict message has been corrupted and should not be used by the Host
    logic           rsvd;       
} D2H_DATA_PACKET;

//H2D Packet Structs
// A) H2D Request (Host -> Device : Snoops)
//    opcode: SnpData / SnpInv / SnpCur
typedef struct packed {
    logic            valid;
    logic [2:0]      opcode;     // 3'b001 DATA, 3'b010 INV, 3'b011 CUR
    logic [45:0]     address;    // 
    logic [11:0]     uqid;       //
    logic [1:0]      rsvd;       //
} H2D_REQUEST_PACKET;

// B) H2D Response (Host -> Device : GO / WritePull / ExtCmp / etc.)
//    rspdata interpretation depends on opcode:
//      - GO:                  MESI in rspdata[3:0]
//      - WritePull variants:  UQID echoed in rspdata[11:0] (destination tag)
typedef struct packed {
    logic             valid;
    logic [3:0]       opcode;     // GO / WritePull / GO_WritePull / ExtCmp / GOERR_WritePull
    logic [11:0]      rspdata;    // depending on OPcode, it can either contain the quid or the MESI information in bits[3:0]
    logic [1:0]       rsp_pre;    // carries perormance monitoring information
    logic [11:0]      cqid;
    logic             rsvd;       //
} H2D_RESPONSE_PACKET;

// C) H2D Data (Host -> Device : Read return data)
//    always a full 64B cacheline (you can model 32B halves via chunk_valid)
typedef struct packed {
    logic            valid;
    logic [11:0]     cqid;       // device tracker target for this data
    logic            chunk_valid;// 0=lower 32B, 1=upper 32B (set 0 if unused)
    logic            poison;     // host indicates data corrupted
    logic            go_err;     // error in coherence resolution for this data
    logic [7:0]      rsvd;       // 64B cacheline packed
} H2D_DATA_PACKET;


/// sys_defs.sv
// CXL.cache mini-project system definitions (spec focus: §3.2.3 & §3.2.4)
// Drop into rtl/ as your common package and import wherever needed.
// -----------------------------------------------------------------------------



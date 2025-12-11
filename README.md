# Formal Verification of a CXL.cache-Based CPU–Accelerator Cache Coherence Protocol

This repository contains a CMurphi model and verification environment for a CXL.cache-based directory coherence protocol that enables cache-coherent memory sharing between CPUs and accelerators over a PCIe-based CXL interconnect. :contentReference[oaicite:1]{index=1}  

We model a heterogeneous system with two home/directory nodes and one device processor, supporting MESI cache states and all six CXL.cache communication channels, and we formally verify key coherence properties via exhaustive state-space exploration.

---

## 1. Motivation

Modern heterogeneous systems pair CPUs with GPUs, FPGAs, and custom accelerators. Sharing data across PCIe via explicit memcopies is expensive and error-prone. CXL addresses this by adding cache-coherent sub-protocols over the PCIe physical layer:

- **CXL.io** – PCIe-compatible I/O
- **CXL.cache** – device-initiated coherent access to host memory
- **CXL.mem** – host-initiated access to device-attached memory :contentReference[oaicite:2]{index=2}  

CXL.cache is particularly tricky to design correctly because of races, reordered messages, and many transient states. This project builds an executable CXL.cache-style coherence model in Murphi and uses model checking to exhaustively validate its correctness.

---

## 2. Protocol & System Model

We implement a directory-based coherence protocol inspired by the CXL.cache specification, with:

- **Nodes**
  - 2 × **Home Nodes (H0, H1)**  
    - Each is both a **directory controller** for one memory region and a **processor** capable of issuing loads/stores.
  - 1 × **Device Processor (D2)**  
    - A CXL device that accesses host memory via CXL.cache.
- **Addresses**
  - 2 logical addresses:  
    - Address 0 is homed at **H0**  
    - Address 1 is homed at **H1** :contentReference[oaicite:3]{index=3}  
- **Coherence States**
  - MESI for both home and device:
    - **M, E, S, I** at the homes
    - **M, E, S, I** at the device caches

### 2.1 CXL.cache Channels & Message Set

We model all six CXL.cache channels:

| Channel       | Direction    | Purpose                          |
|--------------|--------------|----------------------------------|
| D2H Request  | Device → Host | Read/write requests              |
| D2H Response | Device → Host | Snoop responses                  |
| D2H Data     | Device → Host | Writeback / eviction data        |
| H2D Request  | Host → Device | Snoop requests                   |
| H2D Response | Host → Device | GO / WritePull responses         |
| H2D Data     | Host → Device | Read data returns                | :contentReference[oaicite:4]{index=4}  

Modeled request / response opcodes include (non-exhaustive):

- **D2H Requests:** `RdCurr`, `RdOwn`, `RdShared`, `RdAny`, `RdOwnNoData`, `ItoMWr`, `WrCur`, `CLFlush`, `CleanEvict`, `DirtyEvict`, `CleanEvictNoData`, `WrInv`, `CacheFlushed`
- **D2H Responses:** `RspIHitI`, `RspVHitV`, `RspIHitSE`, `RspSHitSE`, `RspSFwdM`, `RspIFwdM`, `RspVFwdV`
- **H2D Requests:** `SnpData`, `SnpInv`, `SnpCur`
- **H2D Responses:** `GO`, `WritePull`, `GO_WritePull`, `GO_WritePull_Drop`, `GO_ERR_WritePull`, `Fast_GO_WritePull`, `ExtCmp` :contentReference[oaicite:5]{index=5}  

### 2.2 State Machines

We implement two interacting state machines:

- **Home (Directory) State Machine**
  - Stable states: `H_I`, `H_S`, `H_E`, `H_M`
  - Rich set of transient states using a naming convention `HT_XY_Z`, where:
    - `X` = source stable state
    - `Y` = target stable state
    - `Z` = pending events (`A` = ack/response, `D` = data, etc.)
  - Example: `HT_IE_AD` = transitioning from `I` to `E` while waiting for both an acknowledgment and data. :contentReference[oaicite:6]{index=6}  

- **Device (Processor Cache) State Machine**
  - Stable states: `P_I`, `P_S`, `P_E`, `P_M`
  - Transient states: `PT_XY_Z` with similar naming (e.g., `PT_IM_AD`, `PT_MI_GP` for dirty eviction handling). :contentReference[oaicite:7]{index=7}  

The protocol supports representative flows like:

- **RdOwn from Invalid**
- **DirtyEvict from Modified**
- **SnpInv-based invalidations**

These flows combine D2H/H2D requests, responses, and data transfers across the six channels.

---

## 3. Murphi Model & Verification

### 3.1 Model Structure

The CMurphi model is about **4,300 lines** of code and includes: :contentReference[oaicite:8]{index=8}  

- **Constants & Types**
  - Number of processors, addresses, distinct data values, channels, etc.
- **Message Record**
  - Encodes all CXL.cache fields we model: opcode, source, destination, virtual channel, address, value, CQID/UQID, MESI bits, chunk validity, poison/bogus bits, etc.
- **State Records**
  - Separate `HomeState` and `ProcState` records, tracking:
    - Local MESI state
    - Cached data value
    - Owner and sharer lists
    - Pending request metadata
- **Network Model**
  - Multiset-based per-destination message queues to allow arbitrary reordering and asynchronous delivery.
  - An “inbox” mechanism handles messages that cannot be processed immediately.
- **Transition Rules**
  - Guarded commands on both homes and devices for:
    - CPU/device-initiated requests
    - Directory snoops
    - Handling replies and data
    - Delivering messages from the network

To keep the state space tractable, the final configuration used for exhaustive verification has: :contentReference[oaicite:9]{index=9}  

- 2 home/directory nodes  
- 1 device processor  
- 2 addresses  
- A **single data value** (reduced value domain)  

### 3.2 Invariants

We check several coherence invariants in **every reachable state**: :contentReference[oaicite:10]{index=10}  

1. **Single-Writer Property**  
   - If the home is in `H_M` for an address, then **exactly one** device owns the line and **no other device** holds a valid copy.

2. **Data Consistency**  
   - When the home is in `H_I` or `H_S` (memory up-to-date), the memory value must match the most recent write.

3. **Sharer Consistency**  
   - For any device in `S` state when the home is `H_S`, the device’s cached data must match memory.

4. **Owner Validity**  
   - When the home is `H_I`, there must be **no defined owner**.

5. **Sharer List Validity**  
   - When the home is in `H_I` or `H_M`, the sharer list must be **empty**.

Any invariant violation or deadlock would halt the model checker with a counterexample.

### 3.3 Verification Results

With CMurphi on a 64-bit machine, the full state space for this configuration was explored exhaustively:

- **States explored:** 10,430,695  
- **Rules fired:** 40,662,942  
- **Peak memory usage:** ~50 GB  
- **Runtime:** ~344.35 s 

---

## 4. Repository Layout

Adjust this section to match your actual directory names:

- `murphi/`
  - Core CMurphi model(s) for the CXL.cache protocol (e.g., `cxl_cache.m`)
  - Supporting type / constant definitions
- `scripts/`
  - Helper scripts to compile and run CMurphi (`mu` wrapper, run scripts, log collectors)
- `results/`
  - Logs and statistics from verification runs
- `docs/`
  - Final report PDF (`EECS570_Final_Report.pdf`)
  - Slides or diagrams (home/device state diagrams, protocol flow charts)

---

## 5. Building & Running the Model

### 5.1 Prerequisites

- **CMurphi** (64-bit variant)
- C/C++ toolchain (e.g., `gcc` or `clang`)
- A machine with **≥ 50 GB of RAM** if you want to reproduce the full verification run described above.

### 5.2 Typical Flow

Assuming you have the standard `mu` script from CMurphi and your main model file is `cxl_cache.m`:

```bash
#Option 1:

# 1. Compile the Murphi model to C++, then to a binary
./mu cxl_cache.m

# 2. Run the generated binary
./cxl_cache > results/run.log

# 3. (Optional) Grep for invariant violations or deadlocks
grep -i "Invariant" results/run.log
grep -i "deadlock"  results/run.log

# Option2:

simply run ./runopt under eecs570_sample/

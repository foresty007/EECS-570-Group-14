============================================================
ECE 570: Cache Coherence Protocol Verification
Yi Dong
============================================================

PROJECT TITLE:
Verification of MSI and MESI Directory-Based Cache Coherence Protocols Using Murphi

------------------------------------------------------------
1. FILE LIST
------------------------------------------------------------
msi.m              - Baseline MSI directory protocol model
msi_opt.m          - Optimized MESI (MSI with Exclusive state) model
msi.out            - Murphi verification output for MSI
msi_opt.out        - Murphi verification output for MESI
report.pdf         - Final 2-page report (main text + figures page)
README.txt         - This file

------------------------------------------------------------
2. COMPILATION AND EXECUTION
------------------------------------------------------------
Murphi Version: 3.1  (EECS 570 standard environment)

Example commands (Linux / CAEN):

  # Step 1: Compile the model
  ./mu msi.m
  make msi

  # Step 2: Run verification
  ./msi -tv > msi.out

  # Step 3: For optimized version
  ./mu msi_opt.m
  make msi_opt
  ./msi_opt -tv > msi_opt.out

------------------------------------------------------------
3. MODEL OVERVIEW
------------------------------------------------------------
Baseline Protocol: MSI
----------------------
States:
  Cache: P_I, P_S, P_M and transient variants (P_ISD, P_IMAD, P_IMA, P_SMAD, etc.)
  Directory: H_I, H_S, H_M with transient states (H_MtoS_D, H_MtoM_A, H_StoM_A)

Messages:
  GetS, GetM, PutS, PutM, Data, Fwd_GetS, Fwd_GetM, Inv, Inv_Ack, Put_Ack

Virtual Channels:
  VC0 - Request messages
  VC1 - Forward/Invalidation messages
  VC2 - Response/Ack messages

Optimized Protocol: MESI (msi_opt)
----------------------------------
Added State:
  Cache: P_E (Exclusive)
  Directory: H_E (Exclusive)
New Message:
  Data_E (exclusive data response)
Transient States:
  H_EtoS_A, H_EtoM_A, P_EIA

Purpose:
  Reduces invalidation traffic and hop count for private data,
  allowing silent E→M upgrades without coherence messages.

------------------------------------------------------------
4. INVARIANTS CHECKED
------------------------------------------------------------
✓ Data coherence:
    Modified value always equals LastWrite.
✓ Exclusivity:
    At most one cache in M or E state globally.
✓ Directory correctness:
    - H_I ⇒ no valid sharers or owners
    - H_S ⇒ all sharers hold identical value
    - H_M/H_E ⇒ defined owner, no sharers
✓ State consistency:
    Invalid implies undefined cache value.
✓ Sharer soundness:
    Sharer list never includes I or M caches.
✓ VC discipline:
    Each message type restricted to legal VC lane.

All invariants passed for both models.

============================================================
END OF FILE
============================================================

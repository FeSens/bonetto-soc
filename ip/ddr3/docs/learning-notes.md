# DDR3 Reference Learning Notes

These are design notes from reading LiteDRAM and UberDDR3 as references for the
Bonetto clean-sheet controller. They are not copied implementation plans.

## LiteDRAM Lessons

LiteDRAM splits the controller into clear layers:

- bank machines track one bank's open row and decide when ACT, PRE, RD, and WR
  are required;
- a multiplexer arbitrates between bank-machine commands, refresh, and data
  direction;
- global timing such as tRRD, tFAW, tCCD, and tWTR is enforced outside the
  individual bank machines;
- refresh is a first-class requester that asks all bank machines to reach an
  idle/precharged point before issuing PRECHARGE-ALL and REFRESH.

What we should copy conceptually:

- keep row tracking local per bank;
- keep cross-bank timing and read/write turnaround in one global scheduler;
- make refresh arbitration explicit instead of hiding it inside the data path;
- keep the data path independent from row/command scheduling where possible.

What we should avoid:

- generating opaque RTL from a large Python object graph;
- spreading timing behavior across many generated helper classes that are hard
  to inspect in the final Verilog.

## UberDDR3 Lessons

UberDDR3 is useful because it is compact handwritten RTL and has a broad
simulation/demo surface. The strongest ideas are:

- compute JEDEC timing waits from ps/tCK values instead of hand-editing magic
  cycle constants;
- encode reset/init/refresh as an explicit command script or ROM-like sequence;
- keep per-bank active-row state and per-bank delay counters visible;
- include model-oriented shortcuts only behind explicit simulation parameters;
- use formal-visible timing constants so proofs can inspect the derived waits.

What we should copy conceptually:

- derived timing constants should be observable and testable;
- init should be a readable sequence: reset, CKE, MR2, MR3, MR1, MR0, ZQCL,
  DLL wait, refresh, normal operation;
- per-bank timers are easier to audit than a single monolithic state variable.

What we should avoid:

- a single very large controller module;
- mixing calibration, ECC, Wishbone, reset, refresh, and PHY serialization in
  one file;
- board demos that become the specification by accident.

## Micron Model Lessons

The vendored Micron DDR3 model is the simulation authority for protocol bring-up.

Important constraints:

- compile with the intended density, speed grade, and organization defines;
- run at ps timescale;
- use a valid DDR3 clock period; the model's 2Gb `-125` parameters reject
  clocks slower than `TCK_MAX = 3300 ps` with DLL enabled, so DDR3-800 is the
  slowest normal bring-up point;
- the model notes that DLL-off mode is not fully modeled, so do not use a
  DLL-off simulation as signoff for the normal controller.

Required future simulation stages:

1. Micron model smoke: compile and run the model. This exists now.
2. Reference init script: drive reset/CKE/MRS/ZQ/REF until the model accepts a
   DDR3-800 initialization path. This exists now and should be kept as the
   known-good script.
3. Init-only controller: drive reset/CKE/MRS/ZQ/DLL wait until the model accepts
   init completion.
4. Command-only runtime: ACT/RD/WR/PRE/REF against one x8 model.
5. Full byte lane: DQS/DQ write and read loopback with one x8 model.
6. Full channel: eight x8 models for 64-bit data, then optional ECC lane.
7. Dual channel: two independent full-channel model stacks.

## Architecture Direction

Build the new controller as small modules:

- `ddr3_init_seq`: JEDEC initialization only;
- `ddr3_bank`: one-bank row state and local timing;
- `ddr3_scheduler`: cross-bank command selection, refresh, and turnaround;
- `ddr3_wb_frontend`: Wishbone request packing and BL8 word selection;
- `ddr3_phy_*`: board-specific PHY and calibration, isolated from scheduling.

The first hardware goal remains DDR3-800 full-width validation. Do not chase
DDR3-1600 until the same RTL passes hardware at DDR3-800, DDR3-1066, and
DDR3-1333.

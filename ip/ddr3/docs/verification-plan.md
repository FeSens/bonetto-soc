# DDR3 Verification Plan

This directory is now verification-first. New RTL is not done when it
elaborates; it is done when the relevant formal, simulation, route, and hardware
gate has evidence.

## Current Live Gates

```sh
make -C ip/ddr3 formal
make -C ip/ddr3 sim
```

Current coverage:

- `formal`: proves the reusable DDR3 command timing monitor is internally
  consistent on a legal ACT/RD/PRE/REF/WR/ZQ trace, and proves the
  controller-owned init sequencer emits reset, MRS, ZQCL, and REF in order with
  minimum waits plus the post-DLL-lock wait. It also proves the single-bank
  runtime slices emit ACT, READ, PRE, REF and ACT, WRITE, READ, PRE, REF in
  order through the monitor. The bank-machine proof wraps arbitrary serialized
  bank requests with the same monitor to prove open-row decisions and local
  timing waits. The scheduler proof wraps the shared command bus and proves the
  first cross-bank tRRD/tFAW/tCCD/write-to-read arbitration slice for bounded
  traffic on two active banks.
- `sim`: compiles and runs the vendored Micron x8 2Gb DDR3 model at a valid
  DDR3-800 clock, then drives both a handwritten reset/MRS/ZQ/REF reference
  script and the RTL init sequencer through the model. It also drives the RTL
  init sequencer into one single-bank READ command sequence and one single-bank
  WRITE/READ loopback using an ideal x8 DQS/DQ testbench agent. The protocol
  benches fail if the model reports timing or protocol errors or warnings.

Current non-coverage:

- no controller-owned data-capture path, real write datapath,
  scheduler-owned refresh, real runtime controller integration, Wishbone
  frontend, dual-channel wrapper, or full memory data path exists yet;
- no PHY, board DQS/DQ, leveling, or hardware DDR3 path is validated by these
  gates.

## Formal Ladder

Every new RTL slice should add or extend one of these harnesses:

| Stage | Required proof |
|---|---|
| Command definitions | All command encodings decode uniquely; NOP/DES are harmless. |
| Init sequencer | Reset, CKE, MRS, ZQCL, DLL wait, and first REF occur in order with minimum waits. |
| Bank machine | No ACT/RD/WR/PRE violates tRC, tRAS, tRP, tRCD, tWR, tRTP, tCCD, or write-to-read wait. |
| Global scheduler | No cross-bank violation of tRRD, tFAW, tCCD, or tWTR. First bounded proof exists. |
| Refresh scheduler | No tRFC violation and no refresh deadline miss. |
| Wishbone frontend | ZipCPU `fwb_slave` contract; no ack without accepted request; no lost request. |
| Read/write merge | Byte enables update exactly the selected 32-bit word inside one BL8 line. |
| Dual channel decode | Channel select bit routes to exactly one channel and preserves local address. |

The command timing monitor in `formal/ddr3_cmd_timing_monitor.sv` is the first
reusable assertion block. Future controller proofs should instantiate it around
the actual command bus instead of reimplementing these assertions locally.

## Micron Simulation Ladder

Use the real Micron model for protocol validation:

| Stage | Model stack | Pass condition |
|---|---|---|
| Smoke | one x8 model, held in reset | model compiles and clocks with selected defines |
| Reference init | handwritten script + one x8 model | reset/MRS/ZQ/REF completes without model timing errors |
| Controller init | controller + one x8 model | controller init completes without model timing errors |
| Single READ command | controller + one x8 model | ACT/READ/PRE/REF command sequence completes without model errors or warnings |
| Single WRITE/READ command | controller + one x8 model + ideal DQS/DQ agent | deterministic BL8 x8 write/read pattern passes |
| Runtime x8 | controller + one x8 model | controller-owned DQS/DQ write/read patterns pass |
| Full channel | controller + eight x8 models | every 64 data bits and byte lane pass |
| Dual channel | two full-channel stacks | both channels pass independent and interleaved traffic |

Compile defines for the YPCB-00338 part:

```text
-Dden2048Mb -Dsg125 -Dx8
```

The Micron model must run with `timescale 1ps / 1ps`. DDR3-800 uses a 400 MHz
CK (`tCK = 2500 ps`) and is the slowest normal hardware target because the
model rejects clocks slower than `TCK_MAX = 3300 ps` with DLL enabled.

## Hardware Ladder

Each speed step must have a separate evidence note:

1. DDR3-800
2. DDR3-1066
3. DDR3-1333
4. DDR3-1600

For each step record:

- exact commit;
- board target and route seed;
- final nextpnr timing lines for system and DDR clocks;
- programming command and `done` status;
- JTAG/Wishbone validator command;
- boundary, walking, lane, window, checksum, random, and soak results;
- final status flags and error counters.

Do not promote a speed grade because simulation passed. Hardware validation is
the gate.

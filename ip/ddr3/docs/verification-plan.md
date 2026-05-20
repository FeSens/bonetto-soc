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
  minimum waits.
- `sim`: compiles and runs the vendored Micron x8 2Gb DDR3 model at a valid
  DDR3-800 clock, then drives both a handwritten reset/MRS/ZQ/REF reference
  script and the RTL init sequencer through the model. The make target fails if
  the model reports timing or protocol errors.

Current non-coverage:

- no runtime controller, bank scheduler, Wishbone frontend, dual-channel wrapper,
  or memory data path exists yet;
- no PHY, DQS, DQ, leveling, or hardware DDR3 path is validated by these gates.

## Formal Ladder

Every new RTL slice should add or extend one of these harnesses:

| Stage | Required proof |
|---|---|
| Command definitions | All command encodings decode uniquely; NOP/DES are harmless. |
| Init sequencer | Reset, CKE, MRS, ZQCL, DLL wait, and first REF occur in order with minimum waits. |
| Bank machine | No ACT/RD/WR/PRE violates tRC, tRAS, tRP, tRCD, tWR, or tRTP. |
| Global scheduler | No cross-bank violation of tRRD, tFAW, tCCD, tWTR, tRFC, or refresh deadline. |
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
| Runtime x8 | controller + one x8 model | deterministic write/read patterns pass |
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

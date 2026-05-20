# DDR3 Clean-Sheet Design

This is the current design direction after the DDR3 RTL reset. It intentionally
describes the target architecture, not an existing implementation.

## Goals

- Two independent DDR3 channels on YPCB-00338.
- Full 64-bit data width per channel, with the ECC byte lane reserved for a
  later ECC mode or optional ninth data/debug lane.
- Full installed data capacity exposed through a clean global address map.
- Hardware-paced bring-up: DDR3-800, DDR3-1066, DDR3-1333, then DDR3-1600.
- Human-readable RTL with small modules and explicit timing contracts.

## Non-Goals For The First RTL Slice

- No DDR3-1600 timing chase before DDR3-800 hardware works.
- No ECC datapath until the 64-bit data path is stable.
- No out-of-order command reordering until the in-order path is proven.
- No board-specific PHY code inside the scheduler.

## Proposed Module Split

| Module | Responsibility |
|---|---|
| `ddr3_cmd` | Command encoding/decoding helpers and mode-register fields. |
| `ddr3_init_seq` | JEDEC reset, CKE, MRS, ZQCL, DLL wait, and first refresh. |
| `ddr3_bank` | One bank's open-row state and local timing waits. |
| `ddr3_scheduler` | Cross-bank arbitration, refresh, tRRD/tFAW/tCCD/tWTR, command issue. |
| `ddr3_wb_frontend` | Wishbone request acceptance, BL8 packing, byte-enable merge. |
| `ddr3_ctrl` | Integrates init, frontend, scheduler, and PHY command/data ports. |
| `ddr3_phy_xilinx7` | Xilinx 7-series clocking, DQS/DQ IO, delay, and leveling. |

The scheduler emits one command per controller cycle. The PHY decides how that
command is serialized onto the physical CK/DQS timing for each operating point.

## Address Plan

Per-channel DDR3 geometry for MT41K256M8DA-125:

- 8 banks (`BANK_BITS=3`)
- 32K rows (`ROW_BITS=15`)
- 1K columns (`COL_BITS=10`)
- BL8 command granularity

A full 64-bit channel transfers 64 bytes per BL8 command, or sixteen 32-bit
Wishbone words. The global 32-bit-word address should eventually be:

```text
global[29]      channel select
global[28:25]   word inside BL8 line
global[24:22]   bank
global[21:7]    row
global[6:0]     column[9:3]
```

The exact bit placement can be tuned for locality, but it must be documented
and formally checked before hardware validation.

## Timing Contract

The command scheduler must never issue a command that violates:

- local bank timing: tRCD, tRP, tRAS, tRC, tWR, tRTP;
- global timing: tRRD, tFAW, tCCD, tWTR, tRFC, tREFI;
- init timing: reset low, CKE wait, tXPR, tMRD, tMOD, tZQinit, tDLLK.

`formal/ddr3_cmd_timing_monitor.sv` is the first reusable assertion block for
runtime command timing. Extend it instead of scattering ad hoc asserts.

## Bring-Up Order

1. Micron model smoke and command monitor self-check.
2. Init-only RTL accepted by one Micron x8 model.
3. Single-bank runtime against one Micron x8 model.
4. One full x8 byte lane with DQS/DQ write/read.
5. One 64-bit channel.
6. Two 64-bit channels.
7. Speed ladder: DDR3-800, DDR3-1066, DDR3-1333, DDR3-1600.

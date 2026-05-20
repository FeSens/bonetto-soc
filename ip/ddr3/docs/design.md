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
| `ddr3_addr_decode` | Full-capacity global word-address split into channel, bank, row, BL8 column, line address, and word index. This exists now. |
| `ddr3_cmd` | Command encoding/decoding helpers and mode-register fields. |
| `ddr3_init_seq` | JEDEC reset, CKE, MRS, ZQCL, first refresh, and DLL-lock release wait. |
| `ddr3_single_read_seq` | Temporary command-only ACT/READ/PRE/REF slice for Micron and formal timing bring-up. |
| `ddr3_single_write_read_seq` | Temporary ACT/WRITE/READ/PRE/REF slice for Micron x8 loopback and turnaround timing bring-up. |
| `ddr3_bank` | One bank's open-row state and local timing waits. This exists now for one request at a time and supports command backpressure plus close requests from the scheduler. |
| `ddr3_scheduler` | Cross-bank arbitration, tRRD/tFAW/tCCD/tWTR command issue, and request-driven refresh after all banks are precharged. A first slice exists now. |
| `ddr3_refresh` | Periodic tREFI accounting and early refresh requests into the scheduler. Idle and focused active-traffic deadline proofs exist now. |
| `ddr3_channel_sched` | Single-channel adapter from BL8 line requests into refresh plus scheduler command issue. This exists now and separates request acceptance from the later RD/WR data-transfer start. |
| `ddr3_byte_lane` | Controller-side x8 BL8 data packetizer. This exists now and proves write data/mask ordering plus read capture ordering before a board-specific DQS/DQ PHY is added. |
| `ddr3_channel_line` | Full 64-bit-channel BL8 line packetizer that composes eight x8 byte lanes into one 512-bit line plus 64 byte-mask bits. This exists now. |
| `ddr3_wb_frontend` | Wishbone request acceptance, BL8 word packing, byte-mask generation, and read word selection. This exists now as a single-outstanding frontend slice. |
| `ddr3_wb_channel` | Bus/data integration slice tying the line-level Wishbone bridge to the full-channel line packetizer and emitting one scheduler-facing BL8 line command. This exists now, presents a complete write line before scheduler command acceptance, and waits for an explicit transfer-start pulse before launching the data packetizer. |
| `ddr3_wb_dual_channel` | Full-capacity bus-facing dispatch slice tying the global address decoder to two full-channel Wishbone bridges. This exists now as a single-outstanding dual-channel compatibility slice. |
| `ddr3_wb_dual_channel_line` | Full-capacity bus-facing dispatch slice with the hardware-facing line-level PHY contract: one 512-bit write line plus 64 mask bits per accepted write, and one 512-bit returned line per read. This exists now and can select a no-DM read-modify-write path for board PHYs without exposed mask pins. |
| `ddr3_ctrl` | Init-gated dual-channel controller shell. This exists now and connects the global Wishbone dispatch bridge to two init sequencers and two scheduler adapters, with packetized PHY-side data ports for compatibility benches. |
| `ddr3_ctrl_line` | Init-gated dual-channel controller shell with the line-level PHY boundary intended for the real Xilinx 7-series DQ/DQS PHY. This exists now. |
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
Wishbone words. The global 32-bit-word address map is:

```text
global[29]      channel select
global[28:26]   bank
global[25:11]   row
global[10:4]    column[9:3]
global[3:0]     word inside BL8 line
```

This exposes 30 word-address bits: two channels times 8 banks times 32K rows
times 128 BL8 column slots times 16 Wishbone words per BL8 line, or 4 GiB total
across both channels. `rtl/ddr3_addr_decode.sv` implements this map and
`formal/addr_decode_wrapper.sv` proves the split, recomposition, line alignment,
and no-alias property for matching `{channel, line, word}` fields.

The low word-index bits intentionally match `ddr3_wb_line_channel` and
`ddr3_wb_channel`: consecutive 32-bit Wishbone addresses fill one 64-byte BL8
line before the BL8 column address increments.

`rtl/ddr3_wb_dual_channel.sv` is the compatibility user of this map. It decodes
the global address, routes the request to exactly one of two
`ddr3_wb_channel` instances, and presents the selected channel's response on
the global Wishbone bus. `rtl/ddr3_wb_dual_channel_line.sv` uses the same map
but routes each channel into `ddr3_wb_line_channel` directly, making the 512-bit
BL8 line contract explicit for a real PHY. Both slices are deliberately
single-outstanding until hardware data evidence exists.

`rtl/ddr3_channel_sched.sv` consumes the same `{bank, row, column[9:3]}` line
address. It accepts a line request when the scheduler accepts the bank request,
then later pulses `o_xfer_start` when the matching RD or WR command actually
issues on the DDR3 command bus.

`rtl/ddr3_ctrl.sv` is the packetized compatibility integration boundary.
`rtl/ddr3_ctrl_line.sv` is the hardware-facing pre-PHY boundary. Both hold the
Wishbone slave stalled until both channel init sequencers report done, mux init
commands onto each channel's DDR3 command pins before handoff, then let the two
scheduler adapters own runtime ACT/RD/WR/PRE/REF commands. The line-level
controller presents complete write lines when a request is accepted and waits
for complete read lines after the scheduler reaches the RD data window.

## Timing Contract

The command scheduler must never issue a command that violates:

- local bank timing: tRCD, tRP, tRAS, tRC, tWR, tRTP;
- global timing: tRRD, tFAW, tCCD, tWTR, tRFC, tREFI;
- init timing: reset low, CKE wait, tXPR, tMRD, tMOD, tZQinit, tDLLK.

`formal/ddr3_cmd_timing_monitor.sv` is the first reusable assertion block for
runtime command timing. Extend it instead of scattering ad hoc asserts.

## Bring-Up Order

1. Full-capacity dual-channel address decoder. This exists now and is formally
   checked against the documented 4 GiB word-address map.
2. Micron model smoke and command monitor self-check.
3. Init-only RTL accepted by one Micron x8 model.
4. Single-bank runtime commands against one Micron x8 model.
5. One x8 BL8 write/read loopback against the Micron model using an ideal
   testbench DQS/DQ agent. This exists now and validates command/data phasing in
   simulation only.
6. One reusable bank machine with open-row tracking and local timing waits.
   This exists now and is formally wrapped by the command timing monitor.
7. Global scheduler over eight bank machines and cross-bank timing. A first
   no-refresh slice exists now and is formally wrapped by the command timing
   monitor.
8. Scheduler-owned request-driven refresh/precharge-all path. This exists now.
9. Periodic refresh requester and idle deadline proof. This exists now.
10. Focused active-traffic refresh-deadline proof. This exists now.
11. One controller-side x8 BL8 byte-lane packetizer. This exists now.
12. One full 64-bit-channel BL8 line packetizer composed from eight x8 lanes.
    This exists now and verifies 512-bit data plus 64 byte-mask placement before
    a board PHY is attached.
13. One single-outstanding Wishbone-to-BL8 frontend. This exists now and proves
    protocol, address split, write data/mask placement, and read word
    selection before it is connected to the scheduler/data path.
14. One Wishbone-to-full-channel bridge. This exists now and proves the
    line-level integration between one Wishbone word request, one BL8 line
    command, and the eight byte-lane data packetizers.
15. One full-capacity dual-channel Wishbone dispatch bridge. This exists now
    and proves channel selection plus local address preservation before either
    channel owns a PHY.
16. No-DM line-write safety. The YPCB-00338 constraints expose DQ/DQS but no
    DM pins, so the line bridge now has a read-modify-write mode that reads the
    old BL8 line, merges selected Wishbone bytes, and writes a full all-active
    line before this behavior is trusted in hardware.
17. One single-channel BL8 scheduler adapter. This exists now and proves that
    scheduler acceptance and RD/WR data-transfer start are separate events.
18. One init-gated dual-channel controller shell. This exists now in both the
    packetized compatibility form and the line-level hardware-facing form. Both
    have focused pre-init gate proofs and post-init write/read scheduler
    integration simulations. Micron regressions run both the compatibility shell
    and the line-level shell through sixteen x8 models, one full 64-bit
    write/read loopback per channel, using the simulation-only x8 timing agents.
19. One controller-owned x8 PHY bridge with real DQS/DQ write/read timing. A
    reusable simulation-only x8 timing agent exists now to keep Micron DQS/DQ/DM
    phasing and active-high DM merge behavior in regression while this RTL is
    still pending.
20. One 64-bit channel integrated through scheduler, frontend, and PHY.
21. Two 64-bit channels with the dispatch bridge driving independent
    scheduler/PHY stacks.
22. Speed ladder: DDR3-800, DDR3-1066, DDR3-1333, DDR3-1600.

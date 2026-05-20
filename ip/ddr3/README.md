# ddr3

Clean-sheet DDR3 controller workspace for Bonetto SoC.

The previous controller/PHY RTL was intentionally removed. Keep this directory
small and verification-first until the new design has a proven command core,
Micron-model simulation, and hardware evidence at each speed step.

The active board-level hardware baseline is now the YPCB-00338 line-controller
command-probe image. It keeps the BRAM-only JTAG/Wishbone proof alive, routes
JTAG/Wishbone traffic through the clean dual-channel DDR3 line controller and
scheduler, drives the board command/reset/CKE/ODT/address pins, and still
returns data through a fabric BL8 line-loopback path. External DDR3 DQ/DQS is
still not connected.

## Status

| Area | State |
|---|---|
| Controller RTL | Full-capacity two-channel address decoder, DDR3-800 init sequencer, temporary single-bank command slices, one-bank row/timing machine, global scheduler timing/refresh slice, periodic refresh requester, controller-side x8 BL8 byte-lane packetizer, full 64-bit-channel BL8 line packetizer, single-outstanding line-level Wishbone bridge, line-backed Wishbone-to-full-channel bridge, dual-channel Wishbone dispatch bridge, single-channel BL8 scheduler adapter, and an init-gated dual-channel controller shell; no controller-owned PHY |
| Formal | Live full-capacity address-map proof, command timing monitor self-check, init sequencer proof, single-read proof, single-write/read proof, bank-machine proof, scheduler timing/refresh proof, periodic idle-refresh proof, bounded active-traffic refresh proof, byte-lane packet proof, full-channel line packet proof, Wishbone frontend proof, line-level Wishbone proof including no-DM read-modify-write mode, Wishbone-to-channel bridge proof, dual-channel dispatch proof, BL8 line scheduler-adapter proof, and controller init-gate proof |
| Simulation | Live full-capacity address-map unit test, Micron DDR3 model smoke, byte-lane unit test, full-channel line unit test, Wishbone frontend unit test, Wishbone-to-channel bridge unit test, line-level Wishbone unit tests for mask-preserving and no-DM read-modify-write modes, dual-channel dispatch unit test, BL8 line scheduler-adapter unit test, init-gated dual-channel controller unit test, reference init, RTL init, RTL single-read command, x8 write/read loopback using the byte-lane packetizer, reusable x8 DQS/DQ/DM timing-agent coverage, and dual-channel full-width controller loopback through sixteen Micron x8 models |
| Reference notes | LiteDRAM/UberDDR3 lessons captured in `docs/learning-notes.md` |
| Active hardware gate | YPCB-00338 JTAG/Wishbone BRAM proof plus DDR3 line-controller loopback and command-probe; not external DDR3 storage |

## Live Gates

Run these from the repo root:

```sh
make -C ip/ddr3 formal
make -C ip/ddr3 sim
make validate-jtag-bram BOARD=ypcb-00338
make -C boards/ypcb-00338 ddr3-ctrl-line-loopback-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-loopback-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-loopback
make -C boards/ypcb-00338 ddr3-ctrl-line-cmdprobe-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-line-cmdprobe-ddr800
make -C boards/ypcb-00338 validate-ddr3-ctrl-line-cmdprobe
```

What these mean today:

- `formal` proves the full-capacity address map for two 64-bit channels and
  proves the reusable DDR3 command timing monitor against a legal
  trace and proves the controller-owned init sequencer emits reset, MRS, ZQCL,
  REF, and post-DLL-lock wait in order with minimum waits. It also proves the
  single-bank runtime slices emit ACT/READ/PRE/REF and
  ACT/WRITE/READ/PRE/REF in order through the same timing monitor. The
  reusable bank-machine proof accepts arbitrary one-at-a-time read/write
  requests and proves emitted ACT/PRE/RD/WR commands stay inside the monitor's
  local row/timing contract. The scheduler proof wraps the shared command bus
  and proves the first cross-bank tRRD/tFAW/tCCD/write-to-read arbitration
  slice for bounded traffic on two active banks, plus request-driven refresh
  after all banks are precharged and tRP-safe. The refresh proofs connect the
  periodic tREFI requester to the scheduler in both an idle path and a focused
  two-bank active-traffic path, enabling the monitor's refresh-deadline check
  while requests may still be in flight when the refresh window opens.
- The byte-lane proof and unit simulation cover the controller-side BL8 x8
  packet boundary: writes emit eight ordered data/mask beats, and reads capture
  eight ordered data beats into one 64-bit line. The Micron write/read loopback
  now uses this packetizer for the BL8 payload before the ideal testbench DQS/DQ
  agent drives or samples the model pins.
- The full-channel line proof and unit simulation compose eight x8 lanes into
  one 512-bit BL8 line with 64 byte-mask bits. The proof checks lane data/mask
  mapping and read-line reassembly with all lanes advancing together; the unit
  bench adds independent per-lane stalls before the future DQS/DQ PHY.
- The Wishbone frontend proof checks the ZipCPU `fwb_slave` contract for a
  single-outstanding request adapter, stable backend request fields under
  backpressure, abort handling, write acknowledgement on backend acceptance, and
  read data/error return from the selected 32-bit word inside a BL8 line. Its
  unit simulation checks address decode, active-high DDR3 DM mask placement
  from Wishbone byte enables, write data placement, and read word selection.
- The line-level Wishbone proof checks that write command acceptance is gated
  until the complete 512-bit/64-mask BL8 line is available, and that reads wait
  for transfer-start plus a complete returned line before acknowledging the bus.
  The no-DM variant first reads the target BL8 line, merges the selected
  Wishbone bytes, and then writes a full all-active line so boards without DM
  pins do not corrupt neighboring bytes.
- The Wishbone-to-channel bridge proof connects that line bridge to the full
  eight-lane line packetizer. It checks that a Wishbone request emits the
  expected BL8 line command, holds that command stable under backpressure, maps
  the selected 32-bit write word and inverted byte enables into the
  active-high 512-bit/64-mask channel line before command acceptance, and
  returns the selected read word from a completed channel line. Its unit
  simulation exercises one full-width write and one full-width read through all
  eight lanes.
- The dual-channel dispatch proof composes two full-channel bridges behind the
  global word-address decoder. It checks that channel bit 29 routes each
  accepted Wishbone request to exactly one channel and preserves the lower
  29-bit local address as the scheduler-facing BL8 line address. Its unit
  simulation drives a channel-0 write and a channel-1 read through independent
  command/data ports.
- The BL8 line scheduler-adapter proof connects one channel command port to the
  refresh requester plus scheduler. It checks that request acceptance is
  separate from the data-transfer start, that `o_xfer_start` only pulses when
  the matching RD/WR command issues, and that bank/column command fields match
  the accepted line address. Its unit simulation drives write/read/write
  traffic through different banks and rows.
- The controller shell proof checks the top-level init gate: Wishbone requests
  are stalled and cannot acknowledge or start PHY-side packet traffic until both
  channel init sequencers are done. Its unit simulation then runs post-init
  channel-0 write and channel-1 read traffic through the real scheduler command
  stream and verifies the line data path starts only on the issued RD/WR.
- The dual-channel Micron controller simulation wires `ddr3_ctrl` through
  sixteen x8 Micron models using the reusable timing agent. It performs a
  full-width write/read loopback on each channel and caught the scheduler's
  one-cycle replay hazard on registered bank-machine command outputs.
- `sim` compiles the vendored Micron DDR3 model, runs a smoke bench, and runs a
  DDR3-800 reset/MRS/ZQ/REF reference script plus the RTL init sequencer against
  the model. It also runs the RTL init sequencer followed by one single-bank
  READ command sequence, one single-bank WRITE/READ loopback, and a reusable x8
  DQS/DQ/DM timing-agent bench that performs two writes with active-high DDR3
  DM masking and reads the merged line back through the byte-lane packetizer.
  The controller-level Micron bench then runs channel-0 and channel-1
  write/read loopbacks through the full Wishbone, scheduler, and packetized data
  path. Model errors, and warnings on the protocol benches, are promoted to make
  failures. This is not board PHY validation yet; it keeps the real Micron BFM,
  initialization assumptions, runtime command timing, and full-width data
  loopback coverage in the live gate.
- `validate-jtag-bram` remains the narrow hardware confidence check for
  JTAG/Wishbone and the board BRAM target.
- `ddr3-ctrl-line-loopback-ddr800-bitstream` routes the clean line-controller
  board image with the full CH0 + CH1 DDR3 pinout constrained. The controller,
  scheduler, JTAG bridge, Wishbone bus, and fabric loopback PHY run in the
  50 MHz board-clock domain; CK is generated, DQ/DQS are high-Z, and external
  DDR3 reset is held low.
- `program-ddr3-ctrl-line-loopback-ddr800` and
  `validate-ddr3-ctrl-line-loopback` are the current hardware gate for the
  clean controller fabric path. Passing them proves live JTAG/Wishbone writes
  and reads through the two-channel line controller and scheduled BL8 line
  boundary. It is not DDR3-800 speed signoff because no external DQ/DQS PHY or
  real memory storage is validated yet.
- `ddr3-ctrl-line-cmdprobe-ddr800-bitstream` enables the next board-facing
  probe: reset, CKE, ODT, CK, command, bank, and address pins are driven on both
  physical DDR3 channels while DQ/DQS stay high-Z and read data returns through
  the internal line loopback. This routes with `--timing-allow-fail` because
  `nextpnr-xilinx` has one global frequency setting for both the real 50 MHz
  SYS_CLK domain and the 400 MHz DDR command-pin domain. The latest route
  reported `clk_dq` at 368.73 MHz against the artificial 400 MHz target, so this
  is a command-path smoke gate, not a DDR3-800 timing signoff.
- `program-ddr3-ctrl-line-cmdprobe-ddr800` and
  `validate-ddr3-ctrl-line-cmdprobe` are the current hardware gate for the
  clean controller plus board command-pin path. Passing them proves live
  JTAG/Wishbone writes and reads through the line controller, scheduler,
  command-pin CDC, and scheduled BL8 line boundary on the real FPGA. External
  DDR3 storage remains unvalidated until a real DQ/DQS PHY is connected and
  timing-closed.

## Directory Map

| Path | Role |
|---|---|
| `rtl/ddr3_params.vh` | Shared command encodings, mode registers, geometry, and DDR3-800 waits. |
| `rtl/ddr3_addr_decode.sv` | Full-capacity two-channel word-address decoder for channel, bank, row, column, BL8 line, and word index. |
| `rtl/ddr3_init_seq.sv` | DDR3-800 reset/MRS/ZQ/REF initialization sequencer. |
| `rtl/ddr3_single_read_seq.sv` | Command-only single-bank ACT/READ/PRE/REF runtime slice. |
| `rtl/ddr3_single_write_read_seq.sv` | Single-bank ACT/WRITE/READ/PRE/REF runtime slice for timing and x8 model bring-up. |
| `rtl/ddr3_bank.sv` | Reusable one-bank open-row and local timing machine. |
| `rtl/ddr3_scheduler.sv` | First global command scheduler slice for cross-bank timing gates and request-driven refresh. |
| `rtl/ddr3_refresh.sv` | Periodic tREFI refresh requester that feeds the scheduler. |
| `rtl/ddr3_channel_sched.sv` | Single-channel adapter from BL8 line requests into refresh plus scheduler command issue, with an explicit transfer-start pulse. |
| `rtl/ddr3_byte_lane.sv` | Controller-side x8 BL8 byte-lane packetizer for ordered write/read data beats. |
| `rtl/ddr3_channel_line.sv` | Full 64-bit-channel BL8 line packetizer composed from eight x8 byte lanes. |
| `rtl/ddr3_wb_frontend.sv` | Single-outstanding Wishbone-to-BL8 frontend for 32-bit word packing, byte masks, and read word selection; retained for focused frontend proof coverage. |
| `rtl/ddr3_wb_line_channel.sv` | Line-level Wishbone bridge that presents a complete write line before scheduler command acceptance and acknowledges reads only after a returned line; optional no-DM mode performs read-modify-write before full-line writes. |
| `rtl/ddr3_wb_channel.sv` | Integration slice tying the line-level Wishbone bridge to the full-channel line packetizer and exposing one BL8 line command. |
| `rtl/ddr3_wb_dual_channel.sv` | Full-capacity dual-channel Wishbone dispatch bridge built from two channel bridges and the global address decoder. |
| `rtl/ddr3_ctrl.sv` | Init-gated dual-channel controller shell connecting Wishbone dispatch, two init sequencers, two scheduler adapters, command pins, and packetized PHY-side data ports. |
| `rtl/ddr3_wb_dual_channel_line.sv` | Line-level dual-channel Wishbone dispatch bridge for a controller-owned BL8 line PHY boundary. |
| `rtl/ddr3_ctrl_line.sv` | Init-gated dual-channel controller shell that exposes complete BL8 write/read lines instead of byte-lane DQ/DQS packets. |
| `formal/ddr3_cmd_timing_monitor.sv` | Reusable JEDEC command/timing assertion block. |
| `formal/addr_decode_wrapper.sv` | Formal harness for the full-capacity two-channel address map and alias checks. |
| `formal/timing_monitor_wrapper.sv` | Self-check harness for the timing monitor. |
| `formal/init_seq_wrapper.sv` | Formal harness for init sequencer ordering and waits. |
| `formal/single_read_wrapper.sv` | Formal harness for the single-bank runtime command slice. |
| `formal/single_write_read_wrapper.sv` | Formal harness for the single-bank write/read runtime command slice. |
| `formal/bank_wrapper.sv` | Formal harness for the one-bank row/timing machine. |
| `formal/scheduler_wrapper.sv` | Formal harness for the scheduler timing/refresh slice. |
| `formal/refresh_wrapper.sv` | Formal harness for periodic idle refresh through the scheduler and timing monitor. |
| `formal/refresh_traffic_wrapper.sv` | Formal harness for periodic refresh with bounded in-flight scheduler traffic. |
| `formal/byte_lane_wrapper.sv` | Formal harness for BL8 x8 byte-lane data/mask ordering and read capture. |
| `formal/channel_line_wrapper.sv` | Formal harness for full-channel lane composition, byte-mask mapping, and read-line reassembly. |
| `formal/wb_frontend_wrapper.sv` | Formal harness for Wishbone protocol, backend request stability, and BL8 word mapping. |
| `formal/wb_line_channel_wrapper.sv` | Formal harness for the line-level Wishbone bridge contract. |
| `formal/wb_channel_wrapper.sv` | Formal harness for the Wishbone-to-full-channel bridge command/data mapping. |
| `formal/wb_dual_channel_wrapper.sv` | Formal harness for global Wishbone channel selection and local address preservation. |
| `formal/channel_sched_wrapper.sv` | Formal harness for BL8 line request acceptance, scheduler command issue, and transfer-start timing. |
| `formal/ctrl_wrapper.sv` | Formal harness for the controller-level init gate and pre-init Wishbone/data quiescence. |
| `formal/ctrl_line_wrapper.sv` | Formal harness for the line-level controller init gate and pre-init PHY-line quiescence. |
| `sim/vendor/` | Vendored Micron DDR3 model and parameters. |
| `sim/tb_addr_decode.sv` | Unit bench for boundary and mixed full-capacity address decoding. |
| `sim/tb_byte_lane.sv` | Unit bench for the byte-lane packetizer. |
| `sim/tb_channel_line.sv` | Unit bench for the full-channel BL8 line packetizer with per-lane stalls. |
| `sim/tb_wb_frontend.sv` | Unit bench for the Wishbone-to-BL8 frontend. |
| `sim/tb_wb_line_channel.sv` | Unit bench for the line-level Wishbone bridge. |
| `sim/tb_wb_channel.sv` | Unit bench for the Wishbone-to-full-channel bridge. |
| `sim/tb_wb_dual_channel.sv` | Unit bench for channel-0 write dispatch and channel-1 read dispatch. |
| `sim/tb_channel_sched.sv` | Unit bench for BL8 line requests issuing through the scheduler adapter. |
| `sim/tb_ctrl.sv` | Unit bench for init-gated dual-channel controller integration through scheduler-issued RD/WR transfer starts. |
| `sim/tb_ctrl_line.sv` | Unit bench for init-gated line-level controller integration through scheduler-issued RD/WR transfer starts. |
| `sim/ddr3_x8_phy_agent.sv` | Simulation-only reusable x8 DQS/DQ/DM timing agent that bridges byte-lane packets to a Micron x8 model. |
| `sim/tb_micron_model_smoke.sv` | Minimal Micron model compile/run smoke bench. |
| `sim/tb_micron_init_script.sv` | Handwritten DDR3-800 reset/MRS/ZQ/REF script against the Micron model. |
| `sim/tb_micron_init_seq.sv` | RTL init sequencer bench against the Micron model. |
| `sim/tb_micron_single_read.sv` | RTL init plus single-bank READ command bench against the Micron model. |
| `sim/tb_micron_single_write_read.sv` | RTL init plus single-bank WRITE/READ x8 loopback bench using the byte-lane packetizer and an ideal testbench DQS/DQ agent. |
| `sim/tb_micron_x8_phy_agent.sv` | Regression for the reusable x8 timing agent, including active-high DM masked write merge through the Micron model. |
| `sim/tb_micron_ctrl_dual_channel.sv` | Dual-channel full-width `ddr3_ctrl` loopback through sixteen Micron x8 models using the reusable timing agents. |
| `docs/verification-plan.md` | Required formal and simulation ladder for new RTL. |
| `docs/learning-notes.md` | Reference lessons from LiteDRAM and UberDDR3. |

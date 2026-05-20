# ddr3

Clean-sheet DDR3 controller workspace for Bonetto SoC.

The previous controller/PHY RTL was intentionally removed. Keep this directory
small and verification-first until the new design has a proven command core,
Micron-model simulation, and hardware evidence at each speed step.

The active board-level hardware baseline remains the BRAM-only JTAG/Wishbone
proof under `boards/ypcb-00338`. Do not regress that path while rebuilding DDR3.

## Status

| Area | State |
|---|---|
| Controller RTL | DDR3-800 init sequencer, temporary single-bank command slices, one-bank row/timing machine, global scheduler timing/refresh slice, and periodic refresh requester; no controller-owned PHY |
| Formal | Live command timing monitor self-check, init sequencer proof, single-read proof, single-write/read proof, bank-machine proof, scheduler timing/refresh proof, and periodic idle-refresh proof |
| Simulation | Live Micron DDR3 model smoke, reference init, RTL init, RTL single-read command, and x8 write/read loopback targets |
| Reference notes | LiteDRAM/UberDDR3 lessons captured in `docs/learning-notes.md` |
| Active hardware gate | BRAM JTAG/Wishbone proof, not DDR3 |

## Live Gates

Run these from the repo root:

```sh
make -C ip/ddr3 formal
make -C ip/ddr3 sim
make validate-jtag-bram BOARD=ypcb-00338
```

What these mean today:

- `formal` proves the reusable DDR3 command timing monitor against a legal
  trace and proves the controller-owned init sequencer emits reset, MRS, ZQCL,
  REF, and post-DLL-lock wait in order with minimum waits. It also proves the
  single-bank runtime slices emit ACT/READ/PRE/REF and
  ACT/WRITE/READ/PRE/REF in order through the same timing monitor. The
  reusable bank-machine proof accepts arbitrary one-at-a-time read/write
  requests and proves emitted ACT/PRE/RD/WR commands stay inside the monitor's
  local row/timing contract. The scheduler proof wraps the shared command bus
  and proves the first cross-bank tRRD/tFAW/tCCD/write-to-read arbitration
  slice for bounded traffic on two active banks, plus request-driven refresh
  after all banks are precharged and tRP-safe. The refresh proof connects the
  periodic tREFI requester to the scheduler in an idle path and enables the
  monitor's refresh-deadline check.
- `sim` compiles the vendored Micron DDR3 model, runs a smoke bench, and runs a
  DDR3-800 reset/MRS/ZQ/REF reference script plus the RTL init sequencer against
  the model. It also runs the RTL init sequencer followed by one single-bank
  READ command sequence and one single-bank WRITE/READ loopback through an
  ideal x8 DQS/DQ testbench agent. Model errors, and warnings on the protocol
  benches, are promoted to make failures. This is not board PHY validation yet;
  it keeps the real Micron BFM, initialization assumptions, first runtime
  command timing, and one byte-lane data loopback in the live gate.
- `validate-jtag-bram` is still the hardware confidence check for JTAG/Wishbone.

## Directory Map

| Path | Role |
|---|---|
| `rtl/ddr3_params.vh` | Shared command encodings, mode registers, geometry, and DDR3-800 waits. |
| `rtl/ddr3_init_seq.sv` | DDR3-800 reset/MRS/ZQ/REF initialization sequencer. |
| `rtl/ddr3_single_read_seq.sv` | Command-only single-bank ACT/READ/PRE/REF runtime slice. |
| `rtl/ddr3_single_write_read_seq.sv` | Single-bank ACT/WRITE/READ/PRE/REF runtime slice for timing and x8 model bring-up. |
| `rtl/ddr3_bank.sv` | Reusable one-bank open-row and local timing machine. |
| `rtl/ddr3_scheduler.sv` | First global command scheduler slice for cross-bank timing gates and request-driven refresh. |
| `rtl/ddr3_refresh.sv` | Periodic tREFI refresh requester that feeds the scheduler. |
| `formal/ddr3_cmd_timing_monitor.sv` | Reusable JEDEC command/timing assertion block. |
| `formal/timing_monitor_wrapper.sv` | Self-check harness for the timing monitor. |
| `formal/init_seq_wrapper.sv` | Formal harness for init sequencer ordering and waits. |
| `formal/single_read_wrapper.sv` | Formal harness for the single-bank runtime command slice. |
| `formal/single_write_read_wrapper.sv` | Formal harness for the single-bank write/read runtime command slice. |
| `formal/bank_wrapper.sv` | Formal harness for the one-bank row/timing machine. |
| `formal/scheduler_wrapper.sv` | Formal harness for the scheduler timing/refresh slice. |
| `formal/refresh_wrapper.sv` | Formal harness for periodic idle refresh through the scheduler and timing monitor. |
| `sim/vendor/` | Vendored Micron DDR3 model and parameters. |
| `sim/tb_micron_model_smoke.sv` | Minimal Micron model compile/run smoke bench. |
| `sim/tb_micron_init_script.sv` | Handwritten DDR3-800 reset/MRS/ZQ/REF script against the Micron model. |
| `sim/tb_micron_init_seq.sv` | RTL init sequencer bench against the Micron model. |
| `sim/tb_micron_single_read.sv` | RTL init plus single-bank READ command bench against the Micron model. |
| `sim/tb_micron_single_write_read.sv` | RTL init plus single-bank WRITE/READ x8 loopback bench with an ideal testbench DQS/DQ agent. |
| `docs/verification-plan.md` | Required formal and simulation ladder for new RTL. |
| `docs/learning-notes.md` | Reference lessons from LiteDRAM and UberDDR3. |

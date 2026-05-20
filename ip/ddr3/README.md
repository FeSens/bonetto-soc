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
| Controller RTL | DDR3-800 init sequencer plus one command-only single-bank ACT/READ/PRE/REF slice; no data path or PHY |
| Formal | Live command timing monitor self-check, init sequencer proof, and single-read command proof |
| Simulation | Live Micron DDR3 model smoke, reference init, RTL init, and RTL single-read command targets |
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
  command-only single-bank runtime slice emits ACT, READ, PRE, and REF in order
  through the same timing monitor.
- `sim` compiles the vendored Micron DDR3 model, runs a smoke bench, and runs a
  DDR3-800 reset/MRS/ZQ/REF reference script plus the RTL init sequencer against
  the model. It also runs the RTL init sequencer followed by one single-bank
  READ command sequence. Model errors, and warnings on the protocol benches, are
  promoted to make failures. This is not data-path or PHY validation yet; it
  keeps the real Micron BFM, initialization assumptions, and first runtime
  command timing in the live gate.
- `validate-jtag-bram` is still the hardware confidence check for JTAG/Wishbone.

## Directory Map

| Path | Role |
|---|---|
| `rtl/ddr3_params.vh` | Shared command encodings, mode registers, geometry, and DDR3-800 waits. |
| `rtl/ddr3_init_seq.sv` | DDR3-800 reset/MRS/ZQ/REF initialization sequencer. |
| `rtl/ddr3_single_read_seq.sv` | Command-only single-bank ACT/READ/PRE/REF runtime slice. |
| `formal/ddr3_cmd_timing_monitor.sv` | Reusable JEDEC command/timing assertion block. |
| `formal/timing_monitor_wrapper.sv` | Self-check harness for the timing monitor. |
| `formal/init_seq_wrapper.sv` | Formal harness for init sequencer ordering and waits. |
| `formal/single_read_wrapper.sv` | Formal harness for the single-bank runtime command slice. |
| `sim/vendor/` | Vendored Micron DDR3 model and parameters. |
| `sim/tb_micron_model_smoke.sv` | Minimal Micron model compile/run smoke bench. |
| `sim/tb_micron_init_script.sv` | Handwritten DDR3-800 reset/MRS/ZQ/REF script against the Micron model. |
| `sim/tb_micron_init_seq.sv` | RTL init sequencer bench against the Micron model. |
| `sim/tb_micron_single_read.sv` | RTL init plus single-bank READ command bench against the Micron model. |
| `docs/verification-plan.md` | Required formal and simulation ladder for new RTL. |
| `docs/learning-notes.md` | Reference lessons from LiteDRAM and UberDDR3. |

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
| Controller RTL | Reset; no active DDR3 controller or PHY |
| Formal | Live DDR3 command timing monitor self-check |
| Simulation | Live Micron DDR3 model smoke and DDR3-800 init-script targets |
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
  trace. Future controller RTL must be wired into this monitor before it can be
  considered reviewable.
- `sim` compiles the vendored Micron DDR3 model, runs a smoke bench, and runs a
  DDR3-800 reset/MRS/ZQ/REF initialization script with model errors promoted to
  make failures. This is not controller validation yet; it keeps the real Micron
  BFM and initialization assumptions in the live gate.
- `validate-jtag-bram` is still the hardware confidence check for JTAG/Wishbone.

## Directory Map

| Path | Role |
|---|---|
| `rtl/` | Empty controller/PHY implementation area; add new RTL here only after a matching formal/sim harness exists. |
| `formal/ddr3_cmd_timing_monitor.sv` | Reusable JEDEC command/timing assertion block. |
| `formal/timing_monitor_wrapper.sv` | Self-check harness for the timing monitor. |
| `sim/vendor/` | Vendored Micron DDR3 model and parameters. |
| `sim/tb_micron_model_smoke.sv` | Minimal Micron model compile/run smoke bench. |
| `sim/tb_micron_init_script.sv` | Handwritten DDR3-800 reset/MRS/ZQ/REF script against the Micron model. |
| `docs/verification-plan.md` | Required formal and simulation ladder for new RTL. |
| `docs/learning-notes.md` | Reference lessons from LiteDRAM and UberDDR3. |

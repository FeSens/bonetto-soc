# wishbone

Wishbone B4 pipelined primitives shared across the SoC: signal-bundle macros (`WB_SLAVE_PORTS`, `WB_MASTER_PORTS`), and the upcoming arbiter / crossbar / address-decoder modules.

Iteration 1: just the header `rtl/wb_types.vh`. Arbiter + crossbar arrive in iteration 2 when the SoC has more than one master.

## Files

- `rtl/wb_types.vh` — port-bundle macros and default widths.
- `docs/interface.md` — contract for any future module added here.

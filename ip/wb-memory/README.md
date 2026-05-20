# wb-memory

BRAM-backed Wishbone B4 pipelined slave. Parameterised by data width and word-address width. Used as the DDR3 stand-in during iteration 1 — the [`ddr3`](../ddr3/) IP will expose the same port set so the SoC top-level swaps implementations without rewiring.

## Files

- `rtl/wb_memory.v` — the implementation.
- `docs/interface.md` — port contract (per INVARIANTS #4).
- `formal/wrapper.sv` — SymbiYosys wrapper instantiating the DUT alongside `fwb_slave.v`.
- `formal/wb_memory.sby` — SymbiYosys task definitions.
- `Makefile` — `make formal` and `make sim` targets.

## Run formal

From the repo root:

```sh
make formal-wb-memory
```

`cover` is the fast smoke check. The full `prove` task uses `smtbmc z3` and can
be solver-heavy because it runs the `fwb_slave` contract over BRAM state.

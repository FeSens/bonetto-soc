# boards/ypcb-00338

Top-level integration for the Inspur YPCB-00338 (Kintex-7 `xc7k480t-ffg1156-2`). Iteration 1 instantiates a Wishbone-master memory tester (`memtest_lite`) against the BRAM-backed `wb_memory` slave and reports results on the three on-card LEDs.

## Files

- `rtl/top.v` — wires `memtest_lite` (master) to `wb_memory` (slave).
- `rtl/memtest_lite.v` — minimal write/read/compare FSM, drives LEDs with `{any_err, heartbeat, last_ok}`.
- `constraints/ypcb-00338.xdc` — clock + LED pin map. From the LiteX board file.
- `Makefile` — synth (yosys) → PnR (nextpnr-xilinx) → bitstream (fasm + xc7frames2bit) → program (openFPGALoader with the XPCU patch + Inspur CPLD chain hack).

## Use

```sh
# from this directory (or `make fpga BOARD=ypcb-00338` from the repo root)
make bitstream
make program
```

LED readout after `make program`:

| LED | Meaning | Healthy state |
|---|---|---|
| `led[0]` (red, P30) | `last_ok` — most recent compare matched | **on** (solid) |
| `led[1]` (green, M30) | heartbeat (~3 Hz toggle) | **blinking** |
| `led[2]` (yellow, N30) | `sticky_error` (set forever after first mismatch) | **off** |

If `led[0]` flickers or `led[2]` lights, the wb_memory IP has a bug — see `ip/wb-memory/formal/` for the contract it must satisfy.

## Iteration 2 plan

- Swap `wb_memory` for `ddr3_ctrl` behind the same Wishbone slave port set.
- Add `jtag_uart` to the bus so the memory tester reports detailed pass/fail counts over JTAG instead of just three LEDs.
- Address-decode crossbar so all three slaves (BRAM, DDR3, UART) coexist.

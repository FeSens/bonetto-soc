# bonetto-soc

A growing SoC fabric for the Inspur YPCB-00338 (Kintex-7 `xc7k480t`) and other 7-series boards. Wishbone B4 pipelined throughout. Every IP gates on **formal verification + simulation + hardware witness** before it crosses the line.

> **Status:** iteration 1 — scaffold and Wishbone foundation. DDR3 controller is a stub that satisfies the Wishbone contract so the bus + JTAG-UART + memory-test loop can be verified end-to-end. The stub gets replaced with a real DDR3 controller behind the same port set in the next iteration.

## Repository layout

```
bonetto-soc/
├── INVARIANTS.md             # numbered contracts every IP must satisfy
├── ARCHITECTURE.md           # system overview, address map, bus contract
├── flake.nix                 # Nix dev shell (yosys / nextpnr-xilinx / verilator / sby / openFPGALoader-patched / cocotb)
├── Makefile                  # top-level driver — `make help` for targets
├── ip/                       # one self-contained directory per IP
│   ├── wishbone/             # bus primitives (arbiter, xbar, types)
│   ├── wb-memory/            # BRAM-backed Wishbone slave (DDR3 stand-in for now)
│   ├── jtag-uart/            # BSCANE2-based UART, primary host-debug channel
│   └── ddr3/                 # parameterised DDR3 controller (stub in iter 1)
├── boards/                   # one directory per target board
│   └── ypcb-00338/           # top-level integration + XDC for the Inspur card
├── verification/             # cross-IP test harnesses
│   ├── common/               # soc_params.vh and shared bus testbench helpers
│   ├── cocotb/               # Python cocotb runners
│   ├── verilator/            # C++ Verilator harnesses
│   └── formal/               # multi-IP formal scenarios
├── formal/vendor/            # ZipCPU's fwb_slave.v, fwb_master.v, etc. — never modified
├── tools/                    # orchestrator scripts (lint, ci, report)
├── scripts/                  # one-off scripts, hooks
└── docs/                     # design rationale, JEDEC references, notes
```

The open-closed principle is the layout: adding a new IP creates a new `ip/<name>/` subtree and touches nothing else. Adding a new board similarly creates `boards/<name>/`.

## Quick start

```sh
git clone git@github.com:FeSens/bonetto-soc.git
cd bonetto-soc
nix develop                    # 10–30 min first time; cached after
make help                      # list targets

# Per-IP verification
make formal-wishbone           # SymbiYosys + ZipCPU fwb properties
make sim-wishbone              # Verilator + cocotb
make formal-jtag-uart
make sim-jtag-uart

# Whole SoC
make ci                        # all IPs: lint + formal + sim
make fpga BOARD=ypcb-00338     # synth + PnR + bitstream
make program BOARD=ypcb-00338  # JTAG-load via patched openFPGALoader
make memtest BOARD=ypcb-00338  # run on-board memory test, results via JTAG UART
```

## Why the verification rigor

This SoC is the substrate for a tournament-style autonomous IP-improvement loop modelled on [`auto-arch-tournament`](https://github.com/FeSens/auto-arch-tournament). The eval contract is what the agents can't weaken. If the formal check passes and the sim matches the reference and the bitstream closes timing on real silicon, the IP is correct enough to compete. If any of those gates relaxes silently, the loop chases a phantom and the results are worthless.

See `INVARIANTS.md` for the hard contracts and the don't-touch list.

## Related work

- [`inspur-adventures`](https://github.com/FeSens/inspur-adventures) — original bring-up of the YPCB-00338 (openXC7 toolchain on macOS, three-LED blink).
- [`xpcu-macos`](https://github.com/FeSens/xpcu-macos) — Xilinx Platform Cable USB II support on macOS, vendored here via flake input.
- [`auto-arch-tournament`](https://github.com/FeSens/auto-arch-tournament) — verification-loop pattern this SoC's CI/orchestrator follows.

## License

RTL: MIT. Vendored upstream files keep their original licenses (see `formal/vendor/`).

# bonetto-soc

A growing SoC fabric for the Inspur YPCB-00338 (Kintex-7 `xc7k480t`) and other 7-series boards. Wishbone B4 pipelined throughout. Every IP gates on **formal verification + simulation + hardware witness** before it crosses the line.

> **Status:** DDR3 channel 0 is validated on real YPCB-00338 hardware at a DDR3-800 operating point with deterministic, random, boundary, address-walking, data-bit/byte-lane, XOR checksum, and 600-second soak evidence. See `boards/ypcb-00338/DDR3_VALIDATION.md`.

## Repository layout

```
bonetto-soc/
├── INVARIANTS.md             # numbered contracts every IP must satisfy
├── ARCHITECTURE.md           # system overview, address map, bus contract
├── flake.nix                 # Nix dev shell (yosys / nextpnr-xilinx / verilator / sby / openFPGALoader-patched / cocotb)
├── Makefile                  # top-level driver — `make help` for targets
├── ip/                       # one self-contained directory per IP
│   ├── wishbone/             # bus primitives (arbiter, xbar, types)
│   ├── wb-memory/            # BRAM-backed Wishbone slave
│   ├── jtag-uart/            # BSCANE2-based UART, primary host-debug channel
│   └── ddr3/                 # parameterized DDR3 controller and 7-series PHY
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
make xvc BOARD=ypcb-00338      # run XVC server for JTAG status/WB probes
make validate-ddr3             # run hardware DDR3 validation against XVC
```

## Why the verification rigor

This SoC is the substrate for a tournament-style autonomous IP-improvement loop modelled on [`auto-arch-tournament`](https://github.com/FeSens/auto-arch-tournament). The eval contract is what the agents can't weaken. If the formal check passes and the sim matches the reference and the bitstream closes timing on real silicon, the IP is correct enough to compete. If any of those gates relaxes silently, the loop chases a phantom and the results are worthless.

See `INVARIANTS.md` for the hard contracts and the don't-touch list.

## Related work

- [`inspur-adventures`](https://github.com/FeSens/inspur-adventures) — original bring-up of the YPCB-00338 (openXC7 toolchain on macOS, three-LED blink).
- Local `patches/openfpgaloader-*.patch` files — Xilinx DLC10 / Platform Cable USB II support on macOS, carried from `inspur-adventures` and extended for XVC/JTAG-WB access.
- [`auto-arch-tournament`](https://github.com/FeSens/auto-arch-tournament) — verification-loop pattern this SoC's CI/orchestrator follows.

## License

RTL: MIT. Vendored upstream files keep their original licenses (see `formal/vendor/`).

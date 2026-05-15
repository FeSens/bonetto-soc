# Architecture

A growing SoC for the Inspur YPCB-00338 (xc7k480t Kintex-7) — and any other 7-series board that can host a 50 MHz reference clock and a JTAG header. Built from the bottom up with one rule: **every IP is independently formal-verifiable and simulation-tested before it touches silicon.**

## Components (current and planned)

| IP | Status | Bus | Purpose |
|---|---|---|---|
| `ip/wishbone/` | scaffold | — | Wishbone B4 pipelined arbiter, crossbar, types |
| `ip/wb-memory/` | scaffold | WB slave | BRAM-backed memory; stand-in for DDR3 during early bring-up |
| `ip/jtag-uart/` | scaffold | WB slave | BSCANE2-based UART; primary host-debug channel |
| `ip/ddr3/` | placeholder | WB slave | Parameterised DDR3 controller — JEDEC-1600 first, deeper speed grades later |
| (future) `ip/cpu/` | — | WB master | RV32IM core (likely a VexRiscv variant initially) |
| (future) `ip/pwm/` | — | WB slave | PWM peripheral |
| (future) `ip/video/` | — | WB master | Framebuffer + display controller |

## Topology

```
                            ┌─────────────┐
                            │ JTAG (XPCU) │
                            └──────┬──────┘
                                   │ BSCANE2 USER1
                            ┌──────▼──────┐
                            │ jtag-uart   │  ← host-side test runner
                            │  (WB slave) │     speaks/reads here
                            └──────┬──────┘
                                   │
                                ┌──▼──┐
                  ┌─────────────┤ XBAR├─────────────┐
                  │             └──┬──┘             │
                  │                │                │
            ┌─────▼─────┐    ┌─────▼─────┐   ┌─────▼─────┐
            │ wb-memory │    │   ddr3    │   │ (future)  │
            │  (BRAM)   │    │ controller│   │           │
            └───────────┘    └───────────┘   └───────────┘
```

In **iteration 1** (the current one), the `ddr3` IP is a stub: it accepts Wishbone transactions and returns a deterministic pattern so the bus + test harness can be validated end-to-end. Once that loop is solid, the stub gets swapped out for a real DDR3 controller, behind exactly the same Wishbone port set.

## Bus contract

**Wishbone B4 pipelined** for everything that crosses an IP boundary. Signal set:

| Signal | Width | Source | Role |
|---|---|---|---|
| `cyc_o` / `cyc_i` | 1 | master | bus-cycle active |
| `stb_o` / `stb_i` | 1 | master | strobe for one transaction |
| `we_o`  / `we_i`  | 1 | master | 1 = write, 0 = read |
| `adr_o` / `adr_i` | `WB_ADDR_W` (default 30, word-addressed 32-bit) | master | address |
| `dat_o` / `dat_i` (master→slave) | `WB_DATA_W` (default 32) | master | write data |
| `sel_o` / `sel_i` | `WB_DATA_W/8` | master | byte enables |
| `dat_i` / `dat_o` (slave→master) | `WB_DATA_W` | slave | read data |
| `ack_i` / `ack_o` | 1 | slave | transaction complete |
| `stall_i` / `stall_o` | 1 | slave | 1 = busy, master must hold `stb` |
| `err_i` / `err_o` | 1 | slave | error response |

Reset is **synchronous, active-high**: `rst`. The single SoC clock is `clk`. Cross-clock domains live inside the IP that needs them (e.g., DDR3 PHY runs at its own clock and crosses to `clk` internally).

## Address map (SoC-wide, version 1)

| Range | Size | IP | Notes |
|---|---|---|---|
| `0x00000000 – 0x0FFFFFFF` | 256 MB | `wb-memory` | BRAM-backed, ~1–2 MB usable, address aliases above that |
| `0x40000000 – 0x7FFFFFFF` | 1 GB | `ddr3` | DDR3 controller window |
| `0xF0000000 – 0xF000FFFF` | 64 KB | `jtag-uart` | TX/RX FIFOs + control regs |

Address-bit count and these ranges are constants in `verification/common/soc_params.vh`. Per **Invariant 3**, this is a contract-level change.

## Verification stack (per IP)

Each IP carries its own three-stage verification:

1. **Formal** (`ip/<ip>/formal/`)
   - `wrapper.sv` adapts the IP for SymbiYosys.
   - `checks.cfg` declares BMC + induction depths per property.
   - Wishbone-facing IPs include `formal/vendor/fwb_slave.v` (or `fwb_master.v` / `fwbu_*.v`).
   - Run with `make formal-<ip>`.

2. **Simulation** (`ip/<ip>/sim/` + `verification/cocotb/` or `verification/verilator/`)
   - Cocotb for directed unit tests (Python).
   - Verilator for batch / cycle-accurate cosim and Micron DDR3 model integration.
   - Run with `make sim-<ip>`.

3. **Hardware bring-up** (`boards/<board>/`)
   - Final witness. Bitstream loaded via JTAG (XPCU patch from `xpcu-macos` flake).
   - Memory test runs on the FPGA and reports results back via `jtag-uart`.
   - Run with `make fpga && make program && make memtest`.

## Toolchain

Same Nix dev shell as the [`inspur-adventures`](https://github.com/FeSens/inspur-adventures) project, plus formal + sim tools:

- **yosys** + **nextpnr-xilinx** + **prjxray** (synth → PnR → bitstream — from openXC7)
- **openFPGALoader** patched per [`xpcu-macos`](https://github.com/FeSens/xpcu-macos) (Xilinx Platform Cable USB II support on macOS)
- **SymbiYosys** + **bitwuzla** / **boolector** (formal)
- **Verilator** (cycle-accurate sim)
- **cocotb** + **pytest** (directed tests)
- **Micron MT41K SystemVerilog model** (DDR3 sim peer)

All in `flake.nix`. `nix develop` puts everything on PATH.

## Iteration loop

Future `/goal` invocations of this project will use the same loop pattern as [`auto-arch-tournament`](https://github.com/FeSens/auto-arch-tournament): a hypothesis-driven, formal-gated, sim-witnessed, hardware-final search over IP designs. The first iteration just lays the rails.

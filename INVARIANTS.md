# INVARIANTS.md — non-negotiable contracts for every IP in this SoC

Every item below is enforced by a check that fails loudly when violated. **Do not weaken these checks** to make new RTL pass. If a check is wrong, fix the check in a focused commit. If an IP needs to relax a rule, justify it in writing and add a new numbered exception below.

The contract is the moat. The IPs are commodity.

## Hard invariants

| # | Invariant | Enforced by |
|---|---|---|
| 1 | Every IP that exposes a Wishbone B4 interface MUST pass the appropriate ZipCPU `fwb_*` formal property file (`fwb_slave.v` for slaves, `fwb_master.v` for masters, `fwbu_*.v` for pipelined). No exceptions, no `assume`s that disable handshake checks. | `make formal-<ip>` runs SymbiYosys with the IP's `formal/wrapper.sv` + `checks.cfg`. |
| 2 | Wishbone bus dialect across the whole SoC is **B4 pipelined** (`STB`, `CYC`, `ACK`, `STALL`). Classic-B3 only inside an IP's internal cells; the IP's external interface is pipelined. | Each IP's `rtl/<ip>.v` top declares pipelined-B4 ports; arbiter and crossbar assume pipelined-B4. |
| 3 | Address space and bus width are top-level constants in `verification/common/soc_params.vh`. Every IP includes that file. Changing address space is a contract-level change, not a per-IP decision. | Lint check (`make lint`) greps every IP's top for `\`include "soc_params.vh"`. |
| 4 | Every IP's `rtl/<ip>.v` has exactly one top module named `<ip>` whose port list is defined in `ip/<ip>/docs/interface.md`. Renames are contract-level changes. | `make lint` parses the top module and diffs against `interface.md`. |
| 5 | Every IP has at least one passing formal check in `ip/<ip>/formal/checks.cfg` and at least one passing simulation in `ip/<ip>/sim/`. New IPs without both don't merge. | `make ci` runs `make formal && make sim` for each IP. |
| 6 | DDR3 controller MUST honor JEDEC DDR3-1600 (or whichever speed grade `ip/ddr3/rtl/ddr3_params.vh` declares) timing parameters tRC, tRAS, tRP, tCK, tCWL, tCL, tRCD. Refresh interval (tREFI) must not exceed JEDEC max under any cycle of any formal trace. | `ip/ddr3/formal/checks.cfg` includes a refresh-deadline cover property; `ip/ddr3/sim/` runs Micron's MT41K SystemVerilog model and asserts no protocol violation. |
| 7 | JTAG UART (`ip/jtag-uart`) MUST not drop bytes: every TX byte the user-side IP writes appears on the host within 1 s; every RX byte the host writes is consumed by the user-side IP without loss. | Cocotb test under `ip/jtag-uart/sim/` plus on-board round-trip in `verification/common/loopback_test.v`. |
| 8 | Bitstream targets MUST close timing under the constraints in `boards/<board>/constraints/`. Negative slack on any clock = failure, not warning. | `make fpga` runs nextpnr-xilinx with `--report` + a Python checker that greps for `WNS < 0`. |
| 9 | No `X` or `Z` propagation across IP boundaries in simulation. Internal `Z` for tristate IO is fine; cross-module `X` is a bug. | Verilator's `--x-assign 0 --x-initial 0 --assert` settings in `verification/verilator/`. |
| 10 | Every commit that touches `rtl/` runs `make lint && make formal && make sim`. Hardware bring-up (`make fpga && make program`) is the final witness, but never a substitute for the other three. | Pre-commit hook in `scripts/pre-commit` (optional, not enforced by GitHub). |

## Don't-touch list

These files/dirs define the verification contract. Hypothesis or implementation work on a specific IP never modifies anything outside its own `ip/<ip>/` tree. The contract belongs to the project as a whole.

- `INVARIANTS.md` (this file)
- `ARCHITECTURE.md`
- `verification/common/` — SoC-wide constants, shared testbench utilities
- `formal/vendor/` — vendored upstream formal libraries (`fwb_*.v`, etc.)
- `tools/` — orchestrator scripts
- Any other IP's `ip/<other>/` directory (each IP is owned by its own author)

## What an IP MAY change inside its own directory

Inside `ip/<ip>/`:
- Rename, split, or merge any file under `rtl/`.
- Rewrite any module from scratch.
- Add or remove sub-modules.
- Add new formal checks; never remove existing ones.
- Add new simulation tests; never remove existing ones.

It may NOT:
- Change its top-module port list relative to `docs/interface.md` (rename = contract change).
- Add any `assume` to the formal harness that disables a previously-passing check.
- Edit any file outside its own `ip/<ip>/` directory.

## Working notes

`INVARIANTS.md` is the contract. `ARCHITECTURE.md` is the system overview. Each IP has its own `docs/interface.md` (port spec) and `docs/design.md` (internal architecture). Working notes for in-progress IP work go in `ip/<ip>/IMPL_NOTES.md` and are gitignored.

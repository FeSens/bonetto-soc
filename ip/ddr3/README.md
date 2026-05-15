# ddr3

Parameterizable DDR3 SDRAM controller. First target: Micron MT41K256M8DA-125 (2 Gb, x8, DDR3-1600) on the Inspur YPCB-00338. Same Wishbone B4 pipelined slave port set as [wb_memory](../wb-memory/) — a board top swaps `wb_memory` for `ddr3_ctrl` with **no other RTL changes**.

## Files

| File | Role |
|---|---|
| `rtl/ddr3_params.vh` | JEDEC timing table per part (`ifdef DDR3_PART_*`). Parameters in tCK units, plus MR0/MR1/MR2/MR3 pre-encoded constants. |
| `rtl/ddr3_cmd.vh` | DDR3 command encoding macros — NOP / ACT / PRE / READ / WRITE / MRS / REF / ZQCL. |
| `rtl/ddr3_init.v` | ~20-state init FSM. Walks the JEDEC power-up sequence: tRESET → tCKE_LOW → tXPR → MR2/MR3/MR1/MR0 → ZQCL → tDLLK → PRE-all → REF → DONE. Cycle-precise. |
| `rtl/ddr3_runtime.v` | Runtime read/write FSM, post-init. ACT → RD/WR (BL8) → PRE per transaction, with tREFI-driven refresh-priority arbitration. |
| `rtl/ddr3_ctrl.v` | Top-level: WB slave front-end + init FSM + runtime FSM + command-bus mux. |
| `formal/wrapper.sv` + `formal/build/proof.passed` | SymbiYosys-style proof: WB slave port complies with B4 pipelined protocol via ZipCPU's `fwb_slave.v`. |
| `sim/tb_ddr3_init.cpp` | Verilator standalone testbench — runs init FSM through to `init_done`. |
| `sim/tb_ddr3_init_top.sv` + `tb_ddr3_init_micron.cpp` | Verilator `--timing` testbench wiring controller to Micron's MT41K behavioural model. Sim peer for JEDEC protocol-compliance checking. |
| `sim/vendor/ddr3.v` + `sim/vendor/ddr3/2048Mb_ddr3_parameters.vh` | Micron behavioural model (164 KB) — vendored from the Elphel mirror. Asserts every JEDEC timing arc on its inputs. |
| `docs/design.md` | Production-grade design blueprint: timing table, FSM specs, calibration plan, PHY architecture, 5-iter roadmap. |
| `docs/interface.md` | Locked Wishbone slave + DDR3-side port contract. |

## Current state

| Stage | State |
|---|---|
| Power-up init RTL | ✅ real, cycle-precise per JEDEC |
| Read / write runtime RTL | ✅ real, BL8 burst, single-bank-at-a-time, refresh interleaved |
| Wishbone slave protocol | ✅ formal-proven against `fwb_slave` at BMC depth 20 — `Status: PASSED` |
| Standalone init sim | ✅ Verilator `PASS: init_done at cycle 561325 / 2000000` (~700 µs sim time at tCK 1.25 ns) |
| Sim peer against Micron model | ⏳ build works under `verilator --timing`; runtime is slow (each ps is a sim event); cap to 250 µs for gating; full sim → Icarus in iter-3 |
| PHY layer (MMCM / IDELAYE2 / OSERDES / ISERDES) | ⏳ iter-3 |
| Calibration (write/read levelling, gate training, per-bit deskew) | ⏳ iter-3 |
| ECC (SECDED Hamming 72,64) | ⏳ iter-3+ |
| Multi-rank / multi-channel | ⏳ iter-4+ |

## Run

```sh
# From repo root:
make formal-ddr3              # SymbiYosys (yosys + smtbmc + yices) — WB slave proof
make sim-ddr3                 # Verilator standalone init sim
# Micron model integration:
cd ip/ddr3 && make -C sim build_micron && ./sim/build_micron/Vtb_ddr3_init_top
```

See `docs/design.md` for the engineering rationale behind every state, timing, and structural choice.

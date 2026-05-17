# ddr3

DDR3 SDRAM controller and 7-series PHY support code for Bonetto SoC. The first
validated target is Micron MT41K256M8DA-125 on the Inspur YPCB-00338
(`xc7k480t-ffg1156-2`) at a DDR3-800 operating point.

The controller side is a Wishbone B4 pipelined slave. The PHY side is split out
so board integrations can keep placement, clocking, byte-lane maps, and debug
plumbing in the board top instead of baking those choices into the controller.

## Status

| Area | State |
|---|---|
| JEDEC init | Implemented and checked against the Micron model |
| Runtime reads/writes | Implemented as single transaction ACT -> RD/WR -> PRE with BL8 data movement |
| Refresh | Implemented with refresh-priority arbitration |
| PHY | Xilinx 7-series MMCM, OSERDES/ISERDES, IDELAY, DQS path |
| Calibration hooks | Write/read-leveling FSMs exist; YPCB-00338 validated with both calibration phases bypassed and fixed working timing/lane map |
| Hardware validation | Passing on YPCB-00338, see `../../boards/ypcb-00338/DDR3_VALIDATION.md` |
| Out of scope today | Row caching, command reordering, ECC, multi-rank, generic non-Xilinx PHY |

## Files

| File | Role |
|---|---|
| `rtl/ddr3_params.vh` | JEDEC timing and geometry table per supported part. |
| `rtl/ddr3_cmd.vh` | DDR3 command encoding macros. |
| `rtl/ddr3_init.v` | Power-up/init FSM: reset, CKE, mode registers, ZQCL, DLL wait, precharge, refresh. |
| `rtl/ddr3_runtime.v` | Post-init WB-to-DDR3 read/write/refresh FSM. |
| `rtl/ddr3_ctrl.v` | Controller wrapper: WB slave front end, init/runtime command mux, MPR/MRS debug ports. |
| `rtl/ddr3_phy*.v` | Xilinx 7-series PHY, byte-lane array, per-lane DQ/DQS primitives, leveling FSMs. |
| `sim/` | Cocotb controller tests, Micron model init test, PHY leveling tests. |
| `formal/` | WB slave and calibration-sequencer formal harnesses. |
| `docs/interface.md` | Current integration contract and parameter notes. |
| `docs/porting.md` | Checklist for moving the IP into a new board or project. |
| `docs/full-capacity-bringup.md` | Gap list and validation gates for the 2-channel DDR3-1600 target. |

## Verification

From the repo root:

```sh
nix develop
make -C ip/ddr3 cocotb
make -C ip/ddr3 sim-micron
make -C ip/ddr3 formal
make -C boards/ypcb-00338/sim -f Makefile.memtest
cd boards/ypcb-00338/formal && sby -f memtest_lite.sby
```

For hardware validation, program a timing-closed board bitstream, start XVC,
then run:

```sh
make xvc BOARD=ypcb-00338
make validate-ddr3 BOARD=ypcb-00338
```

The validation script runs deterministic boundary tests, address walking, every
data bit and byte lane, contiguous-window checks, a host-side XOR checksum sweep,
random accesses, and a timed autonomous memtest soak.

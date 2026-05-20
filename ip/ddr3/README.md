# ddr3

DDR3 controller workspace for Bonetto SoC. The previous controller/PHY RTL was
removed after the DDR3-1600 timing/debug path regressed enough that the cleaner
move is a fresh implementation.

Before new DDR3 RTL lands, the active hardware baseline is the BRAM-only
JTAG/Wishbone proof under `boards/ypcb-00338`. Keep that path passing while the
new controller is designed.

## Status

| Area | State |
|---|---|
| RTL | Reset; no active controller/PHY implementation |
| Preserved checks | Formal harnesses, simulation benches, Micron model, and bring-up notes |
| Active hardware gate | `make -C boards/ypcb-00338 program-jtag-bram`, then XVC + `validate-jtag-bram` |
| Next implementation target | Fresh DDR3 controller/PHY derived from preserved contracts and external reference lessons |

## Files

| File | Role |
|---|---|
| `rtl/README.md` | Marker for the intentional RTL reset. |
| `sim/` | Cocotb controller tests, Micron model init test, PHY leveling tests. |
| `formal/` | WB slave and calibration-sequencer formal harnesses. |
| `docs/interface.md` | Current integration contract and parameter notes. |
| `docs/porting.md` | Checklist for moving the IP into a new board or project. |
| `docs/full-capacity-bringup.md` | Gap list and validation gates for the 2-channel DDR3-1600 target. |

## Verification

From the repo root:

```sh
nix develop
make -C ip/ddr3 formal
make -C boards/ypcb-00338/sim -f Makefile.memtest
cd boards/ypcb-00338/formal && sby -f memtest_lite.sby
```

`make -C ip/ddr3 formal` is currently a harness-retention placeholder. The live
hardware gate before DDR3 work is:

```sh
nix develop
make -C boards/ypcb-00338 program-jtag-bram
make xvc BOARD=ypcb-00338
make validate-jtag-bram BOARD=ypcb-00338
```

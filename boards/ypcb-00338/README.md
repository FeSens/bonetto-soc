# boards/ypcb-00338

Top-level integration for the Inspur YPCB-00338
(`xc7k480t-ffg1156-2`). The default active bitstream is the BRAM-only
JTAG/Wishbone proof image. It integrates:

- BSCANE2 USER1 via `jtag_uart`,
- JTAG-driven Wishbone debug master,
- `wb_decode2` with two BRAM banks,
- board heartbeat/ack/error LEDs.

The first fresh DDR3 board-facing image is `top_ddr3_init_probe`. It routes the
full CH0 + CH1 DDR3 pinout at the DDR3-800 clock point, drives CK/reset/CKE
and command/address pins from per-channel init/refresh sequencers, and exposes
status over USER1 JTAG. DQ/DQS are intentionally high-Z in this image, so it is an
init/clock/constraint probe only, not a memory read/write validator.

The next fresh DDR3 hardware gates keep the full CH0 + CH1 DDR3 pinout
constrained while moving one boundary at a time. `top_ddr3_ctrl_loopback` and
`top_ddr3_ctrl_line_cmdprobe` validate JTAG/Wishbone writes and reads through
the clean dual-channel DDR3 controller, scheduler, and BL8 line packetizer using
internal loopback storage. `top_ddr3_ctrl_line_cmdlaneloop` adds the board
command/reset/CKE/ODT/CK/address pin path and the reusable `ddr3_line_to_lanes`
adapter. `top_ddr3_ctrl_line_phytimingloop` replaces the internal lane memories
with `ddr3_line_lane_phy` plus an abstract pin-pair loopback, so the next proof
boundary is transfer-start pulses, DQ rise/fall launch, read sampling, and
line reassembly. DQ/DQS remain high-Z in all of these gates, so none of them
validate external DDR3 storage.

`top_ddr3_dq_dqs_iobuf_probe` and `top_ddr3_dq_dqs_burst_probe` are route-only
full-pin DDR3-800 DQ/DQS gates. The first proves the raw 7-series ODDR/IDDR plus
IOBUF/IOBUFDS shell; the second adds one local x8 burst sequencer per physical
byte lane. Both hold the DDR3 devices in reset with CKE low, so they are timing
and pin-route evidence only.

## Historical DDR3 Configuration

The previous DDR3 controller/PHY RTL has been reset. The notes below are kept
as bring-up history and constraints/reference context for the next fresh
implementation.

| Item | Value |
|---|---|
| Part | Micron MT41K256M8DA-125 |
| Operating point | DDR3-800, 400 MHz CK, 100 MHz controller clock |
| Active data width | 32 bits |
| Logical byte lanes | 0, 1, 2, 3 |
| Physical byte lanes | 0, 1, 2, 4 |
| Reason for lane map | Physical lane 3 read as stuck zero on this board |
| Calibration | Write/read leveling bypassed; fixed route/timing/lane map validated |
| Controller address span | 25 word-address bits, 128 MiB through the 32-bit WB aperture |
| Debug address path | 30-bit board fabric, with 16 high DDR3 address bits exposed through JTAG-WB |

The old board DDR3 top and controller/PHY RTL have been removed from active
builds. Keep these values as implementation history only; a fresh controller
should re-derive the public contract from formal interfaces and the board pin
sources below.

`constraints/ddr3_ch1.xdc` records the online YPCB-00338-1P1 channel-1 DDR3 pin
reference with `ddr3_ch1_*` port names for the later dual-channel top. It is not
part of the current CH0-only `XDC_FILES` list.

The old DDR3 route/program/validation Make targets are intentionally disabled.
If one is invoked it exits successfully with a reset message instead of trying
to synthesize or program stale RTL:

```sh
DDR3 RTL is reset; use jtag-bram-bitstream until a fresh DDR3 image exists.
```

Use the explicit init-probe targets for the current fresh DDR3 pin/clock/init
hardware step:

```sh
make -C boards/ypcb-00338 ddr3-init-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-init-ddr800
make -C boards/ypcb-00338 xvc
make -C boards/ypcb-00338 validate-ddr3-init
```

That validator requires version `0xB07E0D80`, PLL lock, live generated clocks,
both channel init sequencers done, and no late refresh. It deliberately does
not validate the full DDR3 memory path.

Use the controller-loopback targets for the current fresh DDR3 controller
fabric proof:

```sh
make -C boards/ypcb-00338 ddr3-ctrl-loopback-ddr800-bitstream
make -C boards/ypcb-00338 program-ddr3-ctrl-loopback-ddr800
make -C boards/ypcb-00338 xvc
make -C boards/ypcb-00338 validate-ddr3-ctrl-loopback
```

That validator requires version `0xB07E0D81`, loopback init done, PLL lock,
BRAM sanity, deterministic dual-channel write/read patterns, byte-select
writes, randomized dual-channel write/read patterns, and nonzero loopback
counters on both channels. The command-probe validator requires version
`0xB07E0D84` and runs the same data checks with DDR3 command pins enabled and
the no-DM RMW path selected. The command plus line-to-lane validator requires
version `0xB07E0D86`. The command plus PHY-timing loopback target uses version
`0xB07E0D87`; it has been routed, programmed, and validated over XVC on
2026-05-20. None of these gates validates external DDR3 storage because DQ/DQS
remain disconnected from the controller.

`ddr3-init-ddr800-bitstream` routes with nextpnr's single global `--freq 400`
check and `--timing-allow-fail`. Read the route log per clock: the DDR launch
clocks must pass 400 MHz, while the board input/status and 100 MHz control
domains are not intended to meet a 400 MHz constraint.

`ddr3-ctrl-loopback-ddr800-bitstream` routes the controller fabric at
`--freq 50`; its route log must pass that target. Do not use this target as
evidence for DDR3-800 external timing.

`ddr3-ctrl-line-phytimingloop-ddr800-bitstream` routes with the full DDR3 board
XDC and nextpnr's single global `--freq 400` check under `--timing-allow-fail`.
The 2026-05-20 seed-1 route generated a bitstream, but `SYS_CLK` fails the
artificial 400 MHz check at 65.30 MHz and `clk_dq` estimates 381.97 MHz. Treat
this as functional pre-pin PHY-timing loopback evidence, not DDR3-800 timing,
data-eye, or storage signoff.

`ddr3-dq-dqs-burst-ddr800-bitstream` routes the full CH0 + CH1 DQ/DQS pinout
with one route-only x8 burst sequencer per physical byte lane. The 2026-05-20
seed-1 route completed without `--timing-allow-fail`; nextpnr reported `clk_dq`
at 448.43 MHz against the 400 MHz target. DDR3 reset remains asserted and CKE
low, so this target still does not validate external memory storage.

For pin work, use the public board reference archive rather than deriving pins
from the current reduced top:

| Online file | Local use |
|---|---|
| `https://github.com/TiferKing/ypcb_00338_1p1_hack/blob/main/constraints/ypcb003381p1.xdc` | Full board-level XDC source, archived locally under `constraints/vendor/` |
| `https://github.com/TiferKing/ypcb_00338_1p1_hack/blob/main/constraints/MEMORY_CH0.ucf` | CH0 DDR3 pin source |
| `https://github.com/TiferKing/ypcb_00338_1p1_hack/blob/main/constraints/MEMORY_CH1.ucf` | CH1 DDR3 pin source |
| `https://github.com/TiferKing/ypcb_00338_1p1_hack/blob/main/ypcb003381p1/1.0/mig_01.prj` | Dual-controller MIG geometry/reference |

See `DDR3_VALIDATION.md` and `ip/ddr3/docs/full-capacity-bringup.md` for the
historical DDR3 evidence and failed timing/validation experiments.

## Build And Program

```sh
nix develop
make -C boards/ypcb-00338 bitstream
make -C boards/ypcb-00338 program
```

`make program` is an alias for `program-jtag-bram` while DDR3 RTL is reset.

## JTAG/Wishbone BRAM Proof

Before changing DDR3 RTL, keep the cable, XVC, JTAG bridge, JTAG-Wishbone
master, Wishbone decoder, and BRAM slave independently validated:

```sh
nix develop
make -C boards/ypcb-00338 program-jtag-bram
make -C boards/ypcb-00338 xvc
make -C boards/ypcb-00338 validate-jtag-bram
make -C boards/ypcb-00338 bram-echo
make -C boards/ypcb-00338 bram-transform
```

Run `xvc` in a separate terminal. `bram-echo` opens an interactive Python
terminal where each line is written to BRAM through JTAG-Wishbone, read back
from the same BRAM addresses, and printed as the echo. The proof image uses
`rtl/top_jtag_bram.v`, excludes DDR3 completely, and routes against
`constraints/ypcb003381p1_active.xdc`. The full public board constraint source
is kept unchanged at `constraints/vendor/ypcb003381p1.xdc`; the active XDC is
the subset consumed by this BRAM-only top (`SYS_CLK`, `SYS_RSTN`, and LEDs).
Use `bram-transform` after experimenting with FPGA-side transformed readback;
it prints the returned bytes without requiring them to equal the input.

The validator checks proof version `0xB07EB001`, writes and reads both decoded
BRAM banks (`0x0000`..`0x3fff`, `0x4000`..`0x7fff`), and verifies that address
bit 14 isolates the two banks.

## Hardware Validation

Start XVC in one terminal:

```sh
make xvc BOARD=ypcb-00338
```

Then run validation in another:

```sh
make validate-jtag-bram BOARD=ypcb-00338
```

The BRAM validator runs direct JTAG/Wishbone accesses through XVC and requires
readback from both BRAM banks. `validate-ddr3-init` checks only the fresh
DDR3-800 init probe status. `validate-ddr3-ctrl-loopback` checks live
JTAG/Wishbone writes and reads through the clean dual-channel controller and an
internal loopback PHY. `validate-ddr3-ctrl-line-phytimingloop` checks the
abstract `ddr3_line_lane_phy` timing boundary with live JTAG/Wishbone writes
and reads after its bitstream has been programmed. Full DDR3 memory validation
remains blocked until a real DQ/DQS PHY is wired to the clean controller.

## Status Registers

Use `tools/jtag_uart_read.py` while XVC is running:

```sh
python3 tools/jtag_uart_read.py --tck-ns 2000
python3 tools/jtag_uart_read.py --reg 0x00 --tck-ns 2000
```

Key BRAM-proof registers:

| Register | Meaning |
|---|---|
| `0x00` | BRAM proof status flags, magic `0xAB00` |
| `0x02` | heartbeat counter |
| `0x10`..`0x13` | JTAG-WB debug/status, command echo, and read data |
| `0x1A` | JTAG high-address debug register |
| `0xFE` | BRAM proof version, `0xB07EB001` |
| `0xFF` | host command echo |

Key DDR3 init-probe registers:

| Register | Meaning |
|---|---|
| `0x00` | DDR3 probe status flags, magic `0xB07E`; bit 11 means both init sequencers done |
| `0x01` | packed CH1/CH0 init states plus refresh request/ack/busy/late flags |
| `0x15` | generated 100 MHz system clock liveness |
| `0x16` | generated 400 MHz DDR CK-domain liveness |
| `0x17` | generated 400 MHz +90 degree command-launch clock liveness |
| `0x18` | board reference clock liveness |
| `0x20`..`0x21` | CH0/CH1 refresh counters |
| `0xFE` | DDR3 init-probe version, `0xB07E0D80` |

Key DDR3 controller-loopback registers:

| Register | Meaning |
|---|---|
| `0x00` | Controller-loopback status flags, magic `0xB07E`; bits 15 and 11 mean loopback/init done |
| `0x01` | packed CH1/CH0 init states plus refresh flags and heartbeat bits |
| `0x03` | total loopback read/write transaction count |
| `0x04` | board gate flags: bit 3 means line-lane PHY timing path, bit 2 means line-to-lanes path, bit 1 means PHY byte-mask path, bit 0 means command pins driven |
| `0x10`..`0x13` | JTAG-WB status, address echo, data echo, and read data |
| `0x20`..`0x21` | CH0/CH1 loopback write counts |
| `0x22`..`0x23` | CH0/CH1 loopback read counts |
| `0x24`..`0x25` | CH0/CH1 last loopback line address |
| `0xFE` | DDR3 controller-loopback version, `0xB07E0D81`; command-probe version, `0xB07E0D84`; command plus line-to-lane version, `0xB07E0D86`; command plus PHY-timing version, `0xB07E0D87` |

## LEDs

The LED encoder is a coarse cable-less health indicator. In the default BRAM
proof image:

| LED | Healthy behavior |
|---|---|
| `led[0]` | Heartbeat |
| `led[1]` | Last JTAG-Wishbone operation acknowledged |
| `led[2]` | Last JTAG-Wishbone operation errored |

In the DDR3 init probe:

| LED | Healthy behavior |
|---|---|
| `led[0]` | Heartbeat |
| `led[1]` | Both DDR3 init sequencers done |
| `led[2]` | Off; lights on PLL unlock or late refresh |

Use JTAG status registers for final diagnosis; LEDs are only a first glance.

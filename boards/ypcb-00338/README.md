# boards/ypcb-00338

Top-level integration for the Inspur YPCB-00338
(`xc7k480t-ffg1156-2`). The current active bitstream is the BRAM-only
JTAG/Wishbone proof image. It integrates:

- BSCANE2 USER1 via `jtag_uart`,
- JTAG-driven Wishbone debug master,
- `wb_decode2` with two BRAM banks,
- board heartbeat/ack/error LEDs.

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

The validator runs direct JTAG/Wishbone accesses through XVC and requires
readback from both BRAM banks. DDR3 validation targets stay disabled until the
next controller has real RTL again.

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

## LEDs

The LED encoder is a coarse cable-less health indicator:

| LED | Healthy behavior |
|---|---|
| `led[0]` | Heartbeat |
| `led[1]` | Last JTAG-Wishbone operation acknowledged |
| `led[2]` | Last JTAG-Wishbone operation errored |

Use JTAG status registers for final diagnosis; LEDs are only a first glance.

# boards/ypcb-00338

Top-level integration for the Inspur YPCB-00338
(`xc7k480t-ffg1156-2`). The current bitstream integrates:

- `memtest_lite` as an autonomous Wishbone master,
- BRAM sanity target,
- `ddr3_ctrl` + `ddr3_phy` on DDR3 channel 0,
- JTAG-UART status mux and JTAG-driven Wishbone debug master,
- clock liveness probes for the generated DDR3 clocks.

## DDR3 Configuration

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

The board/debug fabric is now wide enough to carry the SoC's 30-bit
word-address contract. The current DDR3 runtime still exposes only the validated
25-bit controller-visible CH0 slice; full installed capacity requires the BL8
burst-word offset, 64-bit data lanes, and channel select to be consumed by the
DDR3 runtime/PHY before the extra address bits map to unique DRAM cells.

See `DDR3_VALIDATION.md` for the current hardware evidence.

## Build And Program

```sh
nix develop
make -C boards/ypcb-00338 bitstream
make -C boards/ypcb-00338 program
```

For the validated image, route with the recorded seed in `DDR3_VALIDATION.md`
and keep the final `clk_dq` and `clk_sys` timing lines.

## Hardware Validation

Start XVC in one terminal:

```sh
make xvc BOARD=ypcb-00338
```

Then run validation in another:

```sh
make validate-ddr3 BOARD=ypcb-00338
```

The validation script halts the autonomous memtest, runs direct JTAG/Wishbone
DDR3 checks, resumes memtest, and records a JSON evidence file under
`boards/ypcb-00338/build/`.

## Status Registers

Use `tools/jtag_uart_read.py` while XVC is running:

```sh
python3 tools/jtag_uart_read.py --tck-ns 2000
python3 tools/jtag_uart_read.py --reg 0x00 --tck-ns 2000
```

Key registers:

| Register | Meaning |
|---|---|
| `0x00` | status flags: init/cal done, clocks, memtest error |
| `0x04` | memtest error counter |
| `0x08` | DDR3 memtest pass counter |
| `0x09` | completed BRAM/DDR3 sweep counter |
| `0x0A`/`0x0B` | last sweep XOR expected/got |
| `0x0C` | checksum status |
| `0x10`..`0x13` | JTAG-WB debug master |
| `0x15`..`0x17` | clock liveness probes |
| `0x19` | PHY read-valid lanes |
| `0x1A` | JTAG high-address debug register |

## LEDs

The LED encoder is a coarse cable-less health indicator:

| LED | Healthy behavior |
|---|---|
| `led[0]` | Indicates latest compare/health state per encoder |
| `led[1]` | Heartbeat/target activity |
| `led[2]` | Off when no sticky memtest error is present |

Use JTAG status registers for final diagnosis; LEDs are only a first glance.

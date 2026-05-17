# YPCB-00338 DDR3 Validation

Validation date: 2026-05-17

## Commits Under Test

- `9ea20d4` - `ypcb-00338: use working ddr3 byte lane map`
- `e301d59` - `ddr3: add full-span checksum validation`
- `45ae949` - `ddr3: de-duplicate hardware validation cases`

## Validated Configuration

| Item | Value |
|---|---|
| FPGA | Kintex-7 `xc7k480t-ffg1156-2` |
| DDR3 part | Micron MT41K256M8DA-125 |
| DDR3 operating point | DDR3-800, 400 MHz CK |
| Controller clock | 100 MHz target |
| Active byte lanes | Logical lanes 0,1,2,3 mapped to physical lanes 0,1,2,4 |
| Calibration mode | `ddr3_cal_seq` write/read leveling bypassed |
| Route seed | 3 |
| Bitstream | `boards/ypcb-00338/build/bonetto_soc_ypcb00338.bit` |

Physical byte lane 3 is not used in this validated board image because it read
as a stuck-zero byte during bring-up. The logical upper byte is mapped onto
physical lane 4.

## Build And Timing Evidence

Route log:

```text
boards/ypcb-00338/build/nextpnr_hiaddr_seed3.log
```

Final nextpnr clock estimates:

```text
clk_sys     137.51 MHz (PASS at 100.00 MHz)
clk_dq      415.45 MHz (PASS at 100.00 MHz)
clk_phy_x4 1557.63 MHz (PASS at 100.00 MHz)
```

The route log also contains earlier pre-route estimates; use the final repeated
clock lines near the end of the log for signoff.

## Simulation And Formal Gates

Commands run:

```sh
nix develop --command make -C boards/ypcb-00338/sim -f Makefile.memtest
nix develop --command sh -c 'cd boards/ypcb-00338/formal && sby -f memtest_lite.sby'
nix develop --command make -C ip/jtag-uart/sim -f Makefile.jwb
nix develop --command make -C ip/ddr3 cocotb
nix develop --command make -C ip/ddr3 sim-micron
nix develop --command make -C ip/ddr3 formal
```

All completed with pass status before the hardware evidence run.

## Hardware Evidence

Program command:

```sh
nix develop --command make -C boards/ypcb-00338 program
```

XVC command:

```sh
nix develop --command sh -c 'cd boards/ypcb-00338 && tail -f /dev/null | openFPGALoader --xvc --port 3721 --cable xilinxPlatformCableUsb --probe-firmware firmware/xusb_xp2.hex --misc-device 0x10931093,8,inspur_cpld --freq 6000000'
```

Validation command:

```sh
nix develop --command python3 tools/ddr3_hw_validate.py \
  --tck-ns 2000 \
  --random-count 512 \
  --checksum-words 2048 \
  --soak-seconds 600 \
  --poll-interval 30 \
  --verbose \
  --json boards/ypcb-00338/build/ddr3_hw_validate_final.json
```

Final summary:

```text
DDR3_HW_VALIDATE_SUMMARY ok=1 failures=0 ddr3_pass_ctr=2274817875 err_ctr=0
```

Final status flags:

```text
0xb07e8831
cal_done=1
cal_error=0
init_done=1
init_error=0
mmcm_locked=1
idelay_ready=1
mtest_any_err=0
```

Hardware validation results:

| Test | Result | Coverage |
|---|---|---|
| `bram_sanity` | PASS | 32 BRAM words |
| `deterministic_boundary_patterns` | PASS | 24 DDR3 boundary/bank/row/column addresses |
| `address_walking` | PASS | 49 unique high/low address cases |
| `data_bit_and_byte_lanes` | PASS | every 32-bit data bit and byte lane mask |
| `contiguous_burst_alignment_windows` | PASS | 528 unique window/alignment addresses |
| `xor_checksum_sweep` | PASS | 2048 words, expected/got XOR `0xb2c6d6d9` |
| `randomized_read_write` | PASS | 512 random unique addresses |
| `memtest_soak` | PASS | 600.058 s, DDR3 pass delta `1906131711`, error counter `0` |

The JSON evidence file in `build/` records the exact initial/final status
registers, timestamps, test counts, elapsed times, and first-failure fields.

# YPCB-00338 DDR3 Validation

## Clean-Sheet DDR3 Line-Controller Command-Probe Evidence

Validation date: 2026-05-20

This is a hardware validation of the first board-pin command probe for the
clean DDR3 line-controller path:

- DLC10/XVC/USER1 JTAG transport
- JTAG-driven Wishbone master
- BRAM sanity writes and reads through the same JTAG/Wishbone bridge
- Wishbone writes and reads through the line-level dual-channel DDR3 controller
- DDR3 scheduler command generation for both logical channels
- command/reset/CKE/ODT/address pins driven on both physical DDR3 channels
- complete 512-bit BL8 write/read line boundary with 64 byte-mask bits
- both logical DDR3 channels through an internal line-loopback data path

The command-probe image keeps the controller, scheduler, JTAG bridge, and
Wishbone bus in the 50 MHz board-clock domain, then crosses controller command
pulses into the 400 MHz DDR command-pin domain. DDR CK is generated, DDR reset,
CKE, ODT, command, bank, and address pins are driven, and DQ/DQS pins remain
high-Z. Read data still returns through the internal line-loopback path, not
from external DDR3 storage.

This image is intentionally a pre-DQ/DQS probe. It proves the live
JTAG/Wishbone path can exercise the controller, scheduler, command-pin CDC, and
full BL8 line boundary on the real FPGA. It is not DDR3-800 external-memory
signoff: DQ/DQS timing, write leveling, read capture, real memory storage, and
400 MHz command-path closure are still future gates.

### Build And Timing Evidence

Build command:

```sh
nix develop --command make -C boards/ypcb-00338 ddr3-ctrl-line-cmdprobe-ddr800-bitstream
```

Route log:

```text
boards/ypcb-00338/build/ddr3_ctrl_line_cmdprobe_ddr800_seed1_route.log
```

Final nextpnr clock estimates:

```text
u_top.SYS_CLK            106.41 MHz (WARN at artificial 400.00 MHz; real requirement is 50 MHz)
u_jtag_uart.bscan_drck   487.33 MHz (PASS at 400.00 MHz)
u_jtag_uart.bscan_update 1331.56 MHz (PASS at 400.00 MHz)
clk_dq                   368.73 MHz (WARN at 400.00 MHz; command-probe timing still open)
clk_ddr                 1557.63 MHz (PASS at 400.00 MHz)
clk_sys                 1557.63 MHz (PASS at 400.00 MHz)
```

The target uses `--timing-allow-fail` because `nextpnr-xilinx` currently takes
one global `--freq`; this board image has a real 50 MHz SYS_CLK domain and a
400 MHz DDR command-pin domain. The `clk_dq` warning remains real evidence that
the pre-PHY command path is not yet closed at DDR3-800.

### Hardware Status Evidence

Program command:

```sh
nix develop --command make -C boards/ypcb-00338 program-ddr3-ctrl-line-cmdprobe-ddr800
```

Programming completed with FPGA DONE asserted:

```text
USB alternate interface 1 not present; keeping current setting
Shift IR 75
ir: 1 isc_done 1 isc_ena 0 init 1 done 1
```

XVC command:

```sh
nix develop --command make -C boards/ypcb-00338 xvc
```

Validation command:

```sh
nix develop --command make -C boards/ypcb-00338 validate-ddr3-ctrl-line-cmdprobe
```

Final summary:

```text
connected to localhost:3721 - xvcServer_v1.0:1048576
settck(2000 ns) -> 2000 ns
version=0xb07e0d83
status=0xb07e8831 magic=0xb07e cal_done=1 cal_error=0 cal_ecode=0(no error) init_done=1 init_error=0 init_ecode=0 mmcm_locked=1 idelay_ready=1 por_rst=0 mpr_busy=0 mtest_any_err=0 hb=1
state=0x023101e5
clk_sys=0xc1518034 clk_ddr=0xc152c03d clk_dq=0xc153c00f clk_ref=0xc150c02f
bram_sanity: PASS cases=4
dual_channel_boundary_patterns: PASS cases=28
same_line_partial_writes: PASS cases=32
randomized_dual_channel_loopback: PASS cases=128
loop_counts ch0_wr=86 ch1_wr=102 ch0_rd=86 ch1_rd=102
last_lines ch0=0x00000000 ch1=0x00000061
final_jwb_status=0xab100005
DDR3_CTRL_LINE_CMDPROBE_VALIDATE_SUMMARY ok=1
```

The next DDR3 hardware gate must replace the internal line loopback with a real
DQ/DQS PHY, close the 400 MHz command/data timing paths without waivers, and
validate reads and writes from external DDR3 storage.

## Clean-Sheet DDR3 Line-Controller Loopback Evidence

Validation date: 2026-05-20

This is a hardware validation of the clean DDR3 line-controller fabric path:

- DLC10/XVC/USER1 JTAG transport
- JTAG-driven Wishbone master
- BRAM sanity writes and reads through the same JTAG/Wishbone bridge
- Wishbone writes and reads through the line-level dual-channel DDR3 controller
- DDR3 scheduler command generation for both logical channels
- complete 512-bit BL8 write/read line boundary with 64 byte-mask bits
- both logical DDR3 channels through an internal line-loopback PHY

The line-controller loopback image intentionally runs the controller, JTAG
bridge, Wishbone bus, scheduler, and internal loopback PHY in the 50 MHz
board-clock domain. The full CH0 + CH1 DDR3 board pinout is constrained, the
DDR CK generator is present, and DQ/DQS pins stay high-Z, but the external DDR3
devices are held in reset. This image does not validate external DDR3 command
timing, DQ/DQS timing, read/write leveling, or real memory storage, so it is
not a DDR3-800 speed-grade signoff.

### Build And Timing Evidence

Build command:

```sh
nix develop --command make -C boards/ypcb-00338 ddr3-ctrl-line-loopback-ddr800-bitstream
```

Route log:

```text
boards/ypcb-00338/build/ddr3_ctrl_line_loopback_sys50_seed1_route.log
```

Final nextpnr clock estimates:

```text
ctrl_clk                  72.09 MHz (PASS at 50.00 MHz)
u_jtag_uart.bscan_drck   634.92 MHz (PASS at 50.00 MHz)
u_jtag_uart.bscan_update 1092.90 MHz (PASS at 50.00 MHz)
clk_sys                 1557.63 MHz (PASS at 50.00 MHz)
clk_ddr                 1557.63 MHz (PASS at 50.00 MHz)
clk_dq                  1557.63 MHz (PASS at 50.00 MHz)
```

### Hardware Status Evidence

Program command:

```sh
nix develop --command make -C boards/ypcb-00338 program-ddr3-ctrl-line-loopback-ddr800
```

Programming completed with FPGA DONE asserted:

```text
USB alternate interface 1 not present; keeping current setting
Shift IR 75
ir: 1 isc_done 1 isc_ena 0 init 1 done 1
```

XVC command:

```sh
nix develop --command make -C boards/ypcb-00338 xvc
```

Validation command:

```sh
nix develop --command make -C boards/ypcb-00338 validate-ddr3-ctrl-line-loopback
```

Final summary:

```text
connected to localhost:3721 - xvcServer_v1.0:1048576
settck(2000 ns) -> 2000 ns
version=0xb07e0d82
status=0xb07e8831 magic=0xb07e cal_done=1 cal_error=0 cal_ecode=0(no error) init_done=1 init_error=0 init_ecode=0 mmcm_locked=1 idelay_ready=1 por_rst=0 mpr_busy=0 mtest_any_err=0 hb=1
state=0x023103b2
clk_sys=0xc151c003 clk_ddr=0xc152c017 clk_dq=0xc153c025 clk_ref=0xc150c013
bram_sanity: PASS cases=4
dual_channel_boundary_patterns: PASS cases=28
same_line_partial_writes: PASS cases=32
randomized_dual_channel_loopback: PASS cases=128
loop_counts ch0_wr=86 ch1_wr=102 ch0_rd=86 ch1_rd=102
last_lines ch0=0x00000000 ch1=0x00000061
final_jwb_status=0xab100005
DDR3_CTRL_LINE_LOOPBACK_VALIDATE_SUMMARY ok=1
```

This proves the live JTAG/Wishbone path can drive real writes and reads through
the clean dual-channel line controller and scheduled BL8 line boundary in FPGA
fabric. The next DDR3 hardware gate must replace the internal line loopback
with a real DQ/DQS PHY and validate external memory reads and writes.

## Clean-Sheet DDR3 Controller Loopback Evidence

Validation date: 2026-05-20

This is a hardware validation of the clean DDR3 controller fabric path only:

- DLC10/XVC/USER1 JTAG transport
- JTAG-driven Wishbone master
- Wishbone writes and reads through the dual-channel DDR3 controller
- DDR3 scheduler command generation
- BL8 line packetizer and byte-lane write mask handling
- both logical DDR3 channels through an internal loopback PHY

The controller loopback image intentionally runs the controller, JTAG bridge,
Wishbone bus, scheduler, and internal loopback PHY in the 50 MHz board-clock
domain. The full CH0 + CH1 DDR3 board pinout is still constrained, the DDR CK
generator is present, and DQ/DQS pins stay high-Z, but external DDR3 devices
are held in reset. This image does not validate external DDR3 command timing,
DQ/DQS timing, read/write leveling, or real memory storage, so it is not a
DDR3-800 speed-grade signoff.

### Build And Timing Evidence

Build command:

```sh
nix develop --command make -C boards/ypcb-00338 ddr3-ctrl-loopback-ddr800-bitstream
```

Route log:

```text
boards/ypcb-00338/build/ddr3_ctrl_loopback_sys50_seed1_route.log
```

Final nextpnr clock estimates:

```text
ctrl_clk                 64.86 MHz (PASS at 50.00 MHz)
u_jtag_uart.bscan_drck  694.93 MHz (PASS at 50.00 MHz)
u_jtag_uart.bscan_update 1331.56 MHz (PASS at 50.00 MHz)
clk_sys                1557.63 MHz (PASS at 50.00 MHz)
clk_ddr                1557.63 MHz (PASS at 50.00 MHz)
clk_dq                 1557.63 MHz (PASS at 50.00 MHz)
```

The first attempt at routing this same loopback with the controller in the
400 MHz DDR launch domain generated a bitstream but failed timing badly
(`clk_dq` was about 68.71 MHz post-route) and the live image never asserted
both init-done bits. The committed loopback target therefore keeps this proof
honest by using a closed 50 MHz fabric clock.

### Hardware Status Evidence

Program command:

```sh
nix develop --command make -C boards/ypcb-00338 program-ddr3-ctrl-loopback-ddr800
```

Programming completed with FPGA DONE asserted:

```text
USB alternate interface 1 not present; keeping current setting
Shift IR 75
ir: 1 isc_done 1 isc_ena 0 init 1 done 1
```

XVC command:

```sh
nix develop --command make -C boards/ypcb-00338 xvc
```

Validation command:

```sh
nix develop --command make -C boards/ypcb-00338 validate-ddr3-ctrl-loopback
```

Final summary:

```text
connected to localhost:3721 - xvcServer_v1.0:1048576
settck(2000 ns) -> 2000 ns
version=0xb07e0d81
status=0xb07e8831 magic=0xb07e cal_done=1 cal_error=0 init_done=1 init_error=0 mmcm_locked=1 idelay_ready=1 por_rst=0
state=0x023101ee
clk_sys=0xc1518026 clk_ddr=0xc152c017 clk_dq=0xc1538002 clk_ref=0xc1508002
bram_sanity: PASS cases=4
dual_channel_boundary_patterns: PASS cases=28
same_line_partial_writes: PASS cases=32
randomized_dual_channel_loopback: PASS cases=128
loop_counts ch0_wr=86 ch1_wr=102 ch0_rd=86 ch1_rd=102
final_jwb_status=0xab100005
DDR3_CTRL_LOOPBACK_VALIDATE_SUMMARY ok=1
```

This proves the live JTAG/Wishbone path can drive real writes and reads through
the clean dual-channel DDR3 controller and line packetizer in FPGA fabric. The
next DDR3 hardware gate must replace the internal loopback with a real
DQ/DQS PHY and validate external memory reads and writes.

## Clean-Sheet DDR3-800 Init Probe Evidence

Validation date: 2026-05-20

Commit under test:

- `a6fe0d6` - `Add DDR3 init probe image`

This is a hardware validation of the clean-sheet DDR3-800 init, refresh, clock,
pin, and JTAG-status probe only. It does not validate DQ/DQS read/write timing,
the full Wishbone memory path, or full-capacity data storage.

### Build And Timing Evidence

Build and program command:

```sh
nix develop --command make -C boards/ypcb-00338 program-ddr3-init-ddr800
```

The first program attempt failed while an old XVC server still owned the DLC10:

```text
Doneclaim interface failed
JTAG init failed with: lowlevel init failed
```

After stopping the stale `openFPGALoader --xvc --port 3721` process, cable
detect passed:

```text
idcode 0x23751093
manufacturer xilinx
family kintex7
model  xc7k480t
irlength 6
```

Programming then completed with FPGA DONE asserted:

```text
Shift IR 75
ir: 1 isc_done 1 isc_ena 0 init 1 done 1
```

Route log:

```text
boards/ypcb-00338/build/ddr3_init_ddr800_seed1_route.log
```

Final nextpnr clock estimates:

```text
u_clocking.i_clk_50      236.02 MHz (FAIL at 400.00 MHz)
u_jtag_uart.bscan_drck   749.06 MHz (PASS at 400.00 MHz)
u_jtag_uart.bscan_update 1331.56 MHz (PASS at 400.00 MHz)
clk_dq                   692.04 MHz (PASS at 400.00 MHz)
clk_sys                  195.62 MHz (FAIL at 400.00 MHz)
clk_ddr                  1331.56 MHz (PASS at 400.00 MHz)
```

The two FAIL lines are expected for this probe because nextpnr-xilinx applies a
single global `--freq 400` target. `u_clocking.i_clk_50` is the 50 MHz board
input/status domain and `clk_sys` is the 100 MHz init/refresh control domain.
The DDR launch clocks, `clk_dq` and `clk_ddr`, pass the 400 MHz DDR3-800 gate.

### Hardware Status Evidence

XVC command:

```sh
nix develop --command make -C boards/ypcb-00338 xvc
```

Validation command:

```sh
nix develop --command make -C boards/ypcb-00338 validate-ddr3-init
```

Final summary:

```text
connected to localhost:3721 - xvcServer_v1.0:1048576
settck(2000 ns) -> 2000 ns
version=0xb07e0d80
status=0xb07e0820 init_done=1 pll_locked=1 reset_active=0 refresh_late=0
state=0x023100cc ch0_init_state=0 ch1_init_state=8
clk_sys=0xc151803a alive=1
clk_ddr=0xc152c025 alive=1
clk_dq=0xc153c029 alive=1
clk_ref=0xc1508002 alive=1
refresh0=0xf0c054b5 refresh1=0xf0c155ca
DDR3_INIT_VALIDATE_SUMMARY ok=1
```

This proves the first fresh board DDR3 image can be routed, programmed, clocked,
initialized, refreshed, and observed over JTAG at DDR3-800. The next hardware
gate is not another init-only proof; it is a real DQ/DQS PHY path with
JTAG/Wishbone memory write/read validation.

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

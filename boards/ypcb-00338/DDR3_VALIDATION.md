# YPCB-00338 DDR3 Validation

## SERDES Init-Only Hardware Evidence

This is the next live gate after the pre-PHY command plus line-to-lane loopback:
the routed `0xB07E0D89` image enables DDR3 reset/CKE/ODT/CK/address/command
pins, keeps the full x9 CH0 + CH1 SERDES/IDELAY DQ/DQS shell present, blocks
DDR Wishbone storage access, and exposes JTAG-loadable IDELAY tap status
registers.

Validation date: 2026-05-20

The first programming run failed at the DLC10/XPCU JTAG-init transport stage.
After a physical USB replug, the same bounded program target succeeded on
attempt 4 and the XVC validator passed. This validates the live init/status
gate and the host-loadable IDELAY status path; it still does not validate real
external DDR3 storage.

Program command:

```sh
nix develop --command make -C boards/ypcb-00338 program-ddr3-ctrl-line-serdes-init-ddr800
```

Initial blocked failure pattern:

```text
>> program DDR3-800 SERDES init-only attempt 1
USB alternate interface 1 not present; keeping current setting
Unable to read control request: LIBUSB_ERROR_TIMEOUT (bRequest=0x176, wValue=0x64)
JTAG init failed with: Unable to read constant.
...
>> program DDR3-800 SERDES init-only attempt 10
USB alternate interface 1 not present; keeping current setting
Unable to read control request: LIBUSB_ERROR_TIMEOUT (bRequest=0x176, wValue=0x64)
JTAG init failed with: Unable to read constant.
program failed after 10 attempts -- if all attempts after #1
showed 'Unable to read constant', the cable is wedged. Physical
unplug+replug of the USB cable from the Mac is required.
```

Successful programming after replug:

```text
>> program DDR3-800 SERDES init-only attempt 4
Open file DONE
Parse file Unknown key Generator
DONE
load program
Load SRAM: 100.00%
Done
Shift IR 7f
ir: 3 isc_done 1 isc_ena 1 init 1 done 1
```

Validation command:

```sh
nix develop --command make -C boards/ypcb-00338 validate-ddr3-ctrl-line-serdes-init
```

Final summary:

```text
connected to localhost:3721 - xvcServer_v1.0:1048576
settck(2000 ns) -> 2000 ns
version=0xb07e0d89
status=0xb07e8831 init_done=1 pll_locked=1 reset_active=0 refresh_late=0
state=0x023101d8 ch0_init_state=1 ch1_init_state=8
clk_sys=0xc151801a alive=1
clk_ddr=0xc152c007 alive=1
clk_dq=0xc153c009 alive=1
clk_ref=0xc150c013 alive=1
config=0xab040061
refresh_base=0x30 refresh0=0xf0c0497d refresh1=0xf0c14a8f
blocked_ddr_write_status=0xab100007
blocked_ddr_read_status=0xab100007 read_data=0xd15ab1ed
post_block_bram_read_status=0xab100005 read_data=0x00000000
DDR3_CTRL_LINE_SERDES_INIT_VALIDATE_SUMMARY ok=1
```

IDELAY direct physical-lane check:

```sh
python3 tools/jtag_uart_read.py --set-idelay 12 21 --tck-ns 2000
```

```text
IDELAY load requested lane=12 tap=21 channel=0
[0x26] IDELAY_CAL_REQUEST = 0xca101951 magic=0xca10 pending=0 channel=0 lane=12 tap=21 count_lo=1
[0x27] IDELAY_CAL_SEEN    = 0xca111951 magic=0xca11 lane=12 tap=21 count_lo=1
[0x28] IDELAY_CAL_COUNTS  = 0xca120101 magic=0xca12 req_count=1 seen_count=1
```

IDELAY legacy CH1 byte-lane map check:

```sh
python3 tools/jtag_uart_read.py --set-idelay 3 7 --idelay-channel 1 --tck-ns 2000
```

```text
IDELAY load requested lane=3 tap=7 channel=1
[0x26] IDELAY_CAL_REQUEST = 0xca105872 magic=0xca10 pending=0 channel=1 lane=12 tap=7 count_lo=2
[0x27] IDELAY_CAL_SEEN    = 0xca111872 magic=0xca11 lane=12 tap=7 count_lo=2
[0x28] IDELAY_CAL_COUNTS  = 0xca120202 magic=0xca12 req_count=2 seen_count=2
```

This is still not DDR3-800 external-memory validation: DDR Wishbone is
intentionally blocked, DQ/DQS read/write leveling is not live, and the
validator does not read data back from the external DDR3 devices.

## Clean-Sheet DDR3 Command Plus Line-To-Lane Loopback Evidence

Validation date: 2026-05-20

This is a hardware validation of the final pre-PHY DDR3 controller gate before
connecting real DQ/DQS storage:

- DLC10/XVC/USER1 JTAG transport
- JTAG-driven Wishbone master
- BRAM sanity writes and reads through the same JTAG/Wishbone bridge
- Wishbone writes and reads through the line-level dual-channel DDR3 controller
- DDR3 scheduler command generation for both logical channels
- command/reset/CKE/ODT/CK/address pins driven on both physical DDR3 channels
- complete 512-bit BL8 write/read line boundary with 64 byte-mask bits
- `ddr3_line_to_lanes` serialization into sixteen x8 lane streams
- both logical DDR3 channels through internal lane-loopback memories

The command plus line-to-lane loopback image combines the previous
command-probe and line-to-lane gates. The controller, scheduler, JTAG bridge,
Wishbone bus, and line-to-lane adapter are live in the FPGA; controller command
pulses cross into the 400 MHz DDR command-pin domain; DDR CK is generated; and
reset, CKE, ODT, command, bank, and address pins are driven. DQ/DQS pins remain
high-Z, and read data returns from internal lane memories instead of external
DDR3 storage.

This image is intentionally pre-DQ/DQS. It proves that live JTAG/Wishbone
traffic can exercise the clean line controller, scheduled BL8 line boundary,
line-to-lane adapter, and board command-pin path together on real hardware. It
is not DDR3-800 external-memory signoff: write leveling, DQS/DQ launch/capture,
real memory storage, and final timing closure remain future gates.

### Build And Timing Evidence

Build command:

```sh
nix develop --command make -C boards/ypcb-00338 ddr3-ctrl-line-cmdlaneloop-ddr800-bitstream
```

Route log:

```text
boards/ypcb-00338/build/ddr3_ctrl_line_cmdlaneloop_ddr800_seed1_route.log
```

Final nextpnr clock estimates:

```text
u_top.SYS_CLK             72.97 MHz (WARN at artificial 400.00 MHz; real requirement is 50 MHz)
u_jtag_uart.bscan_drck   617.67 MHz (PASS at 400.00 MHz)
u_jtag_uart.bscan_update 1062.70 MHz (PASS at 400.00 MHz)
clk_dq                   518.13 MHz (PASS at 400.00 MHz)
clk_ddr                 1557.63 MHz (PASS at 400.00 MHz)
clk_sys                 1557.63 MHz (PASS at 400.00 MHz)
```

Route completed legally with checksum `0xb8e83b9f` and `1 warning, 0 errors`.
The target uses `--timing-allow-fail` because `nextpnr-xilinx` currently takes
one global `--freq`; this board image has a real 50 MHz SYS_CLK domain and a
400 MHz DDR command-pin domain.

### Hardware Status Evidence

Program command:

```sh
nix develop --command make -C boards/ypcb-00338 program-ddr3-ctrl-line-cmdlaneloop-ddr800
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
nix develop --command make -C boards/ypcb-00338 validate-ddr3-ctrl-line-cmdlaneloop
```

Final summary:

```text
connected to localhost:3721 - xvcServer_v1.0:1048576
settck(2000 ns) -> 2000 ns
version=0xb07e0d86
status=0xb07e8831 magic=0xb07e cal_done=1 cal_error=0 cal_ecode=0(no error) init_done=1 init_error=0 init_ecode=0 mmcm_locked=1 idelay_ready=1 por_rst=0 mpr_busy=0 mtest_any_err=0 hb=1
state=0x02310050
clk_sys=0xc151c007 clk_ddr=0xc152c033 clk_dq=0xc153c019 clk_ref=0xc150c03d
bram_sanity: PASS cases=4
dual_channel_boundary_patterns: PASS cases=28
same_line_partial_writes: PASS cases=32
byte_select_writes: PASS cases=4
randomized_dual_channel_loopback: PASS cases=128
loop_counts ch0_wr=90 ch1_wr=106 ch0_rd=178 ch1_rd=210
last_lines ch0=0x00000000 ch1=0x00000061
final_jwb_status=0xab100005
DDR3_CTRL_LINE_CMDLANELOOP_VALIDATE_SUMMARY ok=1
```

This is the current pre-PHY hardware baseline for the clean DDR3 controller.
The next DDR3 hardware gate must replace the internal lane memories with a real
DQ/DQS PHY, close the relevant timing paths without waivers, and validate reads
and writes from external DDR3 storage.

## Clean-Sheet DDR3 Line-To-Lane Loopback Evidence

Validation date: 2026-05-20

This is a hardware validation of the clean DDR3 line controller through the
reusable line-to-x8-lane adapter:

- DLC10/XVC/USER1 JTAG transport
- JTAG-driven Wishbone master
- BRAM sanity writes and reads through the same JTAG/Wishbone bridge
- Wishbone writes and reads through the line-level dual-channel DDR3 controller
- DDR3 scheduler command generation for both logical channels
- complete 512-bit BL8 write/read line boundary with 64 byte-mask bits
- `ddr3_line_to_lanes` serialization into sixteen x8 lane streams
- both logical DDR3 channels through internal lane-loopback memories

The line-to-lane loopback image keeps the controller, scheduler, JTAG bridge,
Wishbone bus, line-to-lane adapter, and internal lane memories in the 50 MHz
board-clock domain. The full CH0 + CH1 DDR3 board pinout is constrained, the
DDR CK generator is present, and DQ/DQS pins stay high-Z, but the external DDR3
devices are held in reset. This image validates the synthesizable RTL boundary
that a future DQ/DQS PHY will consume; it is not DDR3-800 external-memory
signoff.

### Build And Timing Evidence

Build command:

```sh
nix develop --command make -C boards/ypcb-00338 ddr3-ctrl-line-laneloop-ddr800-bitstream
```

Route log:

```text
boards/ypcb-00338/build/ddr3_ctrl_line_laneloop_sys50_seed1_route.log
```

Final nextpnr clock estimates:

```text
u_top.SYS_CLK             74.47 MHz (PASS at 50.00 MHz)
u_jtag_uart.bscan_drck   827.13 MHz (PASS at 50.00 MHz)
u_jtag_uart.bscan_update 1331.56 MHz (PASS at 50.00 MHz)
clk_dq                  1557.63 MHz (PASS at 50.00 MHz)
clk_ddr                 1557.63 MHz (PASS at 50.00 MHz)
clk_sys                 1557.63 MHz (PASS at 50.00 MHz)
```

### Hardware Status Evidence

Program command:

```sh
nix develop --command make -C boards/ypcb-00338 program-ddr3-ctrl-line-laneloop-ddr800
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
nix develop --command make -C boards/ypcb-00338 validate-ddr3-ctrl-line-laneloop
```

Final summary:

```text
connected to localhost:3721 - xvcServer_v1.0:1048576
settck(2000 ns) -> 2000 ns
version=0xb07e0d85
status=0xb07e8831 magic=0xb07e cal_done=1 cal_error=0 cal_ecode=0(no error) init_done=1 init_error=0 init_ecode=0 mmcm_locked=1 idelay_ready=1 por_rst=0 mpr_busy=0 mtest_any_err=0 hb=1
state=0x023103cd
clk_sys=0xc151c011 clk_ddr=0xc152803e clk_dq=0xc153802a clk_ref=0xc150c009
bram_sanity: PASS cases=4
dual_channel_boundary_patterns: PASS cases=28
same_line_partial_writes: PASS cases=32
byte_select_writes: PASS cases=4
randomized_dual_channel_loopback: PASS cases=128
loop_counts ch0_wr=90 ch1_wr=106 ch0_rd=88 ch1_rd=104
last_lines ch0=0x00000000 ch1=0x00000061
final_jwb_status=0xab100005
DDR3_CTRL_LINE_LANELOOP_VALIDATE_SUMMARY ok=1
```

This proves the live JTAG/Wishbone path can drive real writes and reads through
the clean dual-channel line controller, scheduled BL8 line boundary, and
synthesizable line-to-lane adapter in FPGA fabric. The next DDR3 hardware gate
must connect those lane streams to a real DQ/DQS PHY and validate external
memory reads and writes.

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

## Clean-Sheet DDR3 Command Plus PHY-Timing Loopback Evidence

Validation date: 2026-05-20

This is a hardware validation of the next pre-pin PHY boundary only:

- DLC10/XVC/USER1 JTAG transport
- JTAG-driven Wishbone master
- Wishbone writes and reads through the dual-channel line controller
- DDR3 command/reset/CKE/ODT/CK/address board pin path
- `ddr3_line_lane_phy` transfer-start, write-launch, read-sampling, and line
  reassembly path
- abstract pin-pair loopback storage behind the PHY timing boundary

External DQ/DQS remain high-Z in this gate, so this does not validate DDR3
storage, read/write leveling, or a real data eye. The route also does not close
the global 400 MHz `clk_dq` check, so this is functional pre-pin evidence, not
DDR3-800 timing signoff.

### Build And Timing Evidence

Build command:

```sh
nix develop --command make -C boards/ypcb-00338 ddr3-ctrl-line-phytimingloop-ddr800-bitstream
```

Route log:

```text
boards/ypcb-00338/build/ddr3_ctrl_line_phytimingloop_ddr800_seed1_route.log
```

Final nextpnr clock estimates:

```text
u_top.SYS_CLK                    65.30 MHz (FAIL at 400.00 MHz)
u_top.u_jtag_uart.bscan_drck    531.91 MHz (PASS at 400.00 MHz)
u_top.u_jtag_uart.bscan_update 1331.56 MHz (PASS at 400.00 MHz)
u_top.clk_dq                    381.97 MHz (FAIL at 400.00 MHz)
u_top.clk_ddr                  1557.63 MHz (PASS at 400.00 MHz)
u_top.clk_sys                  1557.63 MHz (PASS at 400.00 MHz)
```

The design was built with `--timing-allow-fail` because nextpnr-xilinx applies a
single global timing target across board/status, JTAG, controller, and generated
DDR clocks. The `clk_dq` miss is still relevant for the future real PHY path and
must not be treated as DDR3-800 closure.

### Hardware Status Evidence

Program command:

```sh
nix develop --command make -C boards/ypcb-00338 program-ddr3-ctrl-line-phytimingloop-ddr800
```

Programming completed with FPGA DONE asserted:

```text
USB alternate interface 1 not present; keeping current setting
Shift IR 75
ir: 1 isc_done 1 isc_ena 0 init 1 done 1
```

XVC command:

```sh
nix develop --command make xvc BOARD=ypcb-00338
```

Validation command:

```sh
nix develop --command make -C boards/ypcb-00338 validate-ddr3-ctrl-line-phytimingloop
```

Final summary:

```text
connected to localhost:3721 - xvcServer_v1.0:1048576
settck(2000 ns) -> 2000 ns
version=0xb07e0d87
status=0xb07e8831 magic=0xb07e cal_done=1 cal_error=0 cal_ecode=0(no error) init_done=1 init_error=0 init_ecode=0 mmcm_locked=1 idelay_ready=1 por_rst=0 mpr_busy=0 mtest_any_err=0 hb=1
state=0x02313007
clk_sys=0xc151802a clk_ddr=0xc1528026 clk_dq=0xc153c01b clk_ref=0xc150c01f
bram_sanity: PASS cases=4
dual_channel_boundary_patterns: PASS cases=28
same_line_partial_writes: PASS cases=32
byte_select_writes: PASS cases=4
randomized_dual_channel_loopback: PASS cases=128
loop_counts ch0_wr=90 ch1_wr=106 ch0_rd=178 ch1_rd=210
last_lines ch0=0x00000000 ch1=0x00000061
final_jwb_status=0xab100005
DDR3_CTRL_LINE_PHYTIMINGLOOP_VALIDATE_SUMMARY ok=1
```

The first hardware attempt at this gate exposed a no-DM read-modify-write
handshake bug: the PHY-timing backend sampled read-line readiness on the same
cycle as the scheduler RD transfer-start pulse, while the Wishbone bridge only
asserted readiness one cycle later. The fix makes `o_phy_rd_line_ready` true on
the `i_xfer_start` edge while waiting for read data, and the focused
`tb_wb_line_channel_rmw` bench now asserts that timing edge.

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

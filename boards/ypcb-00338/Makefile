# Board-level synth → PnR → bitstream → program, mirroring the inspur-adventures
# flow but with a multi-IP source list.

PROJECT  := bonetto_soc_ypcb00338_jtag_bram
TOP      := top_jtag_bram
PART     := xc7k480tffg1156-2
DBPART   := xc7k480tffg1156
FAMILY   := kintex7

# Cable / firmware / chain — same XPCU-on-macOS setup as inspur-adventures.
CABLE    := xilinxPlatformCableUsb
FIRMWARE := firmware/xusb_xp2.hex
FIRMWARE_URL := https://raw.githubusercontent.com/bwhite/fpga-image-registration/master/edk_project/install_drivers/linux_drivers/pcusb/xusb_xp2.hex
MISC_DEV := --misc-device 0x10931093,8,inspur_cpld
FREQ_DETECT  := --freq 500000
FREQ_PROGRAM := --freq 6000000

# Active source list. DDR3 RTL has been reset; the board's default hardware
# target is the BRAM-only JTAG/Wishbone proof image.
RTL := \
    rtl/top_jtag_bram.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/wishbone/rtl/wb_decode2.v

JTAG_BRAM_PROJECT := bonetto_soc_ypcb00338_jtag_bram
JTAG_BRAM_RTL := $(RTL)

DDR3_INIT_PROBE_RTL := \
    rtl/top_ddr3_init_probe.sv \
    rtl/ddr3_board_io.sv \
    rtl/clk_liveness.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/ddr3/rtl/ddr3_init_seq.sv \
    ../../ip/ddr3/rtl/ddr3_refresh.sv

DDR3_CTRL_LOOPBACK_RTL := \
    rtl/top_ddr3_ctrl_loopback.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_ctrl_loopback_phy.sv \
    rtl/clk_liveness.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/ddr3/rtl/ddr3_addr_decode.sv \
    ../../ip/ddr3/rtl/ddr3_init_seq.sv \
    ../../ip/ddr3/rtl/ddr3_refresh.sv \
    ../../ip/ddr3/rtl/ddr3_bank.sv \
    ../../ip/ddr3/rtl/ddr3_scheduler.sv \
    ../../ip/ddr3/rtl/ddr3_channel_sched.sv \
    ../../ip/ddr3/rtl/ddr3_wb_line_channel.sv \
    ../../ip/ddr3/rtl/ddr3_byte_lane.sv \
    ../../ip/ddr3/rtl/ddr3_channel_line.sv \
    ../../ip/ddr3/rtl/ddr3_wb_channel.sv \
    ../../ip/ddr3/rtl/ddr3_wb_dual_channel.sv \
    ../../ip/ddr3/rtl/ddr3_ctrl.sv

DDR3_CTRL_LINE_LOOPBACK_RTL := \
    rtl/top_ddr3_ctrl_line_loopback.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_line_loopback_phy.sv \
    rtl/clk_liveness.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/ddr3/rtl/ddr3_addr_decode.sv \
    ../../ip/ddr3/rtl/ddr3_init_seq.sv \
    ../../ip/ddr3/rtl/ddr3_refresh.sv \
    ../../ip/ddr3/rtl/ddr3_bank.sv \
    ../../ip/ddr3/rtl/ddr3_scheduler.sv \
    ../../ip/ddr3/rtl/ddr3_channel_sched.sv \
    ../../ip/ddr3/rtl/ddr3_wb_line_channel.sv \
    ../../ip/ddr3/rtl/ddr3_wb_dual_channel_line.sv \
    ../../ip/ddr3/rtl/ddr3_ctrl_line.sv

DDR3_CTRL_LINE_CMDPROBE_RTL := \
    rtl/top_ddr3_ctrl_line_cmdprobe.sv \
    $(DDR3_CTRL_LINE_LOOPBACK_RTL)

DDR3_CTRL_LINE_LANELOOP_RTL := \
    rtl/top_ddr3_ctrl_line_laneloop.sv \
    rtl/top_ddr3_ctrl_line_loopback.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_line_loopback_phy.sv \
    rtl/ddr3_ctrl_loopback_phy.sv \
    rtl/clk_liveness.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/ddr3/rtl/ddr3_addr_decode.sv \
    ../../ip/ddr3/rtl/ddr3_init_seq.sv \
    ../../ip/ddr3/rtl/ddr3_refresh.sv \
    ../../ip/ddr3/rtl/ddr3_bank.sv \
    ../../ip/ddr3/rtl/ddr3_scheduler.sv \
    ../../ip/ddr3/rtl/ddr3_channel_sched.sv \
    ../../ip/ddr3/rtl/ddr3_wb_line_channel.sv \
    ../../ip/ddr3/rtl/ddr3_wb_dual_channel_line.sv \
    ../../ip/ddr3/rtl/ddr3_ctrl_line.sv \
    ../../ip/ddr3/rtl/ddr3_line_to_lanes.sv

DDR3_CTRL_LINE_CMDLANELOOP_RTL := \
    rtl/top_ddr3_ctrl_line_cmdlaneloop.sv \
    rtl/top_ddr3_ctrl_line_loopback.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_line_loopback_phy.sv \
    rtl/ddr3_ctrl_loopback_phy.sv \
    rtl/clk_liveness.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/ddr3/rtl/ddr3_addr_decode.sv \
    ../../ip/ddr3/rtl/ddr3_init_seq.sv \
    ../../ip/ddr3/rtl/ddr3_refresh.sv \
    ../../ip/ddr3/rtl/ddr3_bank.sv \
    ../../ip/ddr3/rtl/ddr3_scheduler.sv \
    ../../ip/ddr3/rtl/ddr3_channel_sched.sv \
    ../../ip/ddr3/rtl/ddr3_wb_line_channel.sv \
    ../../ip/ddr3/rtl/ddr3_wb_dual_channel_line.sv \
    ../../ip/ddr3/rtl/ddr3_ctrl_line.sv \
    ../../ip/ddr3/rtl/ddr3_line_to_lanes.sv

DDR3_CTRL_LINE_PHYTIMINGLOOP_RTL := \
    rtl/top_ddr3_ctrl_line_phytimingloop.sv \
    rtl/top_ddr3_ctrl_line_loopback.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_pinpair_loopback_phy.sv \
    rtl/ddr3_line_loopback_phy.sv \
    rtl/ddr3_ctrl_loopback_phy.sv \
    rtl/clk_liveness.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/ddr3/rtl/ddr3_addr_decode.sv \
    ../../ip/ddr3/rtl/ddr3_init_seq.sv \
    ../../ip/ddr3/rtl/ddr3_refresh.sv \
    ../../ip/ddr3/rtl/ddr3_bank.sv \
    ../../ip/ddr3/rtl/ddr3_scheduler.sv \
    ../../ip/ddr3/rtl/ddr3_channel_sched.sv \
    ../../ip/ddr3/rtl/ddr3_wb_line_channel.sv \
    ../../ip/ddr3/rtl/ddr3_wb_dual_channel_line.sv \
    ../../ip/ddr3/rtl/ddr3_ctrl_line.sv \
    ../../ip/ddr3/rtl/ddr3_line_to_lanes.sv \
    ../../ip/ddr3/rtl/ddr3_x8_lane_phy.sv \
    ../../ip/ddr3/rtl/ddr3_line_lane_phy.sv

DDR3_CTRL_LINE_PHYCLKLOOP_RTL := \
    rtl/top_ddr3_ctrl_line_phyclkloop.sv \
    rtl/top_ddr3_ctrl_line_loopback.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_pinpair_timing_probe.sv \
    rtl/ddr3_pinpair_loopback_phy.sv \
    rtl/ddr3_line_loopback_phy.sv \
    rtl/ddr3_ctrl_loopback_phy.sv \
    rtl/clk_liveness.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/ddr3/rtl/ddr3_addr_decode.sv \
    ../../ip/ddr3/rtl/ddr3_init_seq.sv \
    ../../ip/ddr3/rtl/ddr3_refresh.sv \
    ../../ip/ddr3/rtl/ddr3_bank.sv \
    ../../ip/ddr3/rtl/ddr3_scheduler.sv \
    ../../ip/ddr3/rtl/ddr3_channel_sched.sv \
    ../../ip/ddr3/rtl/ddr3_wb_line_channel.sv \
    ../../ip/ddr3/rtl/ddr3_wb_dual_channel_line.sv \
    ../../ip/ddr3/rtl/ddr3_ctrl_line.sv \
    ../../ip/ddr3/rtl/ddr3_line_to_lanes.sv \
    ../../ip/ddr3/rtl/ddr3_x8_lane_phy.sv \
    ../../ip/ddr3/rtl/ddr3_line_lane_phy.sv \
    ../../ip/ddr3/rtl/ddr3_line_phy_clock_bridge.sv

DDR3_CTRL_LINE_SERDES_RTL := \
    rtl/top_ddr3_ctrl_line_serdes_init.sv \
    rtl/top_ddr3_ctrl_line_serdes.sv \
    rtl/top_ddr3_ctrl_line_loopback.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_serdes_io.sv \
    rtl/ddr3_pinpair_timing_probe.sv \
    rtl/ddr3_pinpair_loopback_phy.sv \
    rtl/ddr3_line_loopback_phy.sv \
    rtl/ddr3_ctrl_loopback_phy.sv \
    rtl/clk_liveness.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/ddr3/rtl/ddr3_addr_decode.sv \
    ../../ip/ddr3/rtl/ddr3_init_seq.sv \
    ../../ip/ddr3/rtl/ddr3_refresh.sv \
    ../../ip/ddr3/rtl/ddr3_bank.sv \
    ../../ip/ddr3/rtl/ddr3_scheduler.sv \
    ../../ip/ddr3/rtl/ddr3_channel_sched.sv \
    ../../ip/ddr3/rtl/ddr3_wb_line_channel.sv \
    ../../ip/ddr3/rtl/ddr3_wb_dual_channel_line.sv \
    ../../ip/ddr3/rtl/ddr3_ctrl_line.sv \
    ../../ip/ddr3/rtl/ddr3_line_to_lanes.sv \
    ../../ip/ddr3/rtl/ddr3_x8_lane_phy.sv \
    ../../ip/ddr3/rtl/ddr3_line_lane_phy.sv \
    ../../ip/ddr3/rtl/ddr3_line_phy_clock_bridge.sv \
    ../../ip/ddr3/rtl/ddr3_line_to_bursts.sv \
    ../../ip/ddr3/rtl/ddr3_x8_to_x9_line_adapter.sv \
    ../../ip/ddr3/rtl/ddr3_x8_burst_clock_bridge.sv \
    ../../ip/ddr3/rtl/ddr3_x8_serdes_burst_lane.sv \
    ../../ip/ddr3/rtl/ddr3_line_serdes_phy.sv \
    ../../ip/ddr3/rtl/ddr3_idelay_cal_cdc.sv

DDR3_DQ_DQS_IO_PROBE_RTL := \
    rtl/top_ddr3_dq_dqs_iobuf_probe.sv \
    rtl/ddr3_board_io.sv

DDR3_DQ_DQS_BURST_PROBE_RTL := \
    rtl/top_ddr3_dq_dqs_burst_probe.sv \
    rtl/ddr3_board_io.sv \
    ../../ip/ddr3/rtl/ddr3_x8_burst_io_sequencer.sv

DDR3_DQ_DQS_SERDES_PROBE_RTL := \
    rtl/top_ddr3_dq_dqs_serdes_probe.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_serdes_io.sv

DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL := \
    rtl/top_ddr3_dq_dqs_serdes_lane_probe.sv \
    rtl/ddr3_board_io.sv \
    rtl/ddr3_serdes_io.sv

BUILD  := build
CHIPDB := $(BUILD)/chipdb

# Constraints for the active BRAM proof image.
# nextpnr-xilinx takes a single XDC file, so we cat them at build time.
XDC_FILES := constraints/ypcb003381p1_active.xdc
XDC       := $(BUILD)/$(PROJECT).xdc
DDR3_ACTIVE_DQ_MAX  ?= 39
DDR3_ACTIVE_DQS_MAX ?= 4
ALLOW_TIMING_FAILED_DDR3_EXPERIMENT ?= 0

# Shared-header include dirs are wired into read_verilog inside the
# yosys script (yosys's CLI has no -I flag — includes go via `read_verilog -I`).
INCDIRS := -I ../../verification/common -I ../../ip/wishbone/rtl -I ../../ip/ddr3/rtl

PYPY3  ?= pypy3
NEXTPNR_FREQ ?= 50
NEXTPNR_ARGS ?= --seed 1 --log build/jtag_bram_seed1_route.log
DDR3_DEFINES ?=
YOSYS_SYNTH_ARGS ?= -flatten -abc9
YOSYS_POST_SYNTH ?=
DDR3_DEFINES_FILE := $(BUILD)/$(PROJECT).defines.txt

.PHONY: bitstream program detect memtest xvc validate-jtag-bram bram-echo bram-transform ddr3-init-ddr800-json ddr3-init-ddr800-bitstream program-ddr3-init-ddr800 validate-ddr3-init ddr3-ctrl-loopback-ddr800-json ddr3-ctrl-loopback-ddr800-bitstream program-ddr3-ctrl-loopback-ddr800 validate-ddr3-ctrl-loopback ddr3-ctrl-line-loopback-ddr800-json ddr3-ctrl-line-loopback-ddr800-bitstream program-ddr3-ctrl-line-loopback-ddr800 validate-ddr3-ctrl-line-loopback ddr3-ctrl-line-cmdprobe-ddr800-json ddr3-ctrl-line-cmdprobe-ddr800-bitstream program-ddr3-ctrl-line-cmdprobe-ddr800 validate-ddr3-ctrl-line-cmdprobe ddr3-ctrl-line-laneloop-ddr800-json ddr3-ctrl-line-laneloop-ddr800-bitstream program-ddr3-ctrl-line-laneloop-ddr800 validate-ddr3-ctrl-line-laneloop ddr3-ctrl-line-cmdlaneloop-ddr800-json ddr3-ctrl-line-cmdlaneloop-ddr800-bitstream program-ddr3-ctrl-line-cmdlaneloop-ddr800 validate-ddr3-ctrl-line-cmdlaneloop validate-ddr3 validate-ddr3-ratio8-ch0 validate-ddr3-full-ch0 validate-ddr3-full-2ch jtag-bram-bitstream program-jtag-bram ratio8-ch0-ddr800-bitstream ratio8-ch0-oddrwr-ddr800-bitstream full-ch0-json full-ch0-ddr800-bitstream full-ch0-oddrwr-ddr800-bitstream full-2ch-json full-2ch-serdescmd-json full-2ch-iserdes-json full-2ch-serdescmd-iserdes-json full-2ch-iserdes-bufio-json full-2ch-ddr800-bitstream full-2ch-ddr1600-bitstream full-2ch-ddr1600-jtagonly-bitstream full-2ch-ddr1600-serdescmd-jtagonly-bitstream full-2ch-ddr1600-serdescmd-jtagonly-lateflat-json full-2ch-ddr1600-serdescmd-jtagonly-lateflat-bitstream full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-nrdata-lateflat-bitstream full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-lateflat-bitstream full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-topreq-lateflat-bitstream full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-ctrlreq-topreq-lateflat-bitstream full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-ctrlreq-topreq-router1-lateflat-bitstream program-full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-ctrlreq-topreq-router1-lateflat full-2ch-ddr1600-serdescmd-jtagdirect-bitstream full-2ch-ddr1600-serdescmd-ddronly-json full-2ch-ddr1600-serdescmd-ddronly-bitstream full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream full-2ch-ddr1600-iserdes-bufio-jtagonly-bitstream full-2ch-ddr1600-jtagdirect-bitstream clean help
.PHONY: ddr3-ctrl-line-phytimingloop-ddr800-json ddr3-ctrl-line-phytimingloop-ddr800-bitstream program-ddr3-ctrl-line-phytimingloop-ddr800 validate-ddr3-ctrl-line-phytimingloop
.PHONY: ddr3-ctrl-line-phyclkloop-ddr800-json ddr3-ctrl-line-phyclkloop-ddr800-bitstream program-ddr3-ctrl-line-phyclkloop-ddr800 validate-ddr3-ctrl-line-phyclkloop
.PHONY: ddr3-ctrl-line-serdes-ddr800-json ddr3-ctrl-line-serdes-router1-ddr800-bitstream
.PHONY: ddr3-ctrl-line-serdes-init-ddr800-json ddr3-ctrl-line-serdes-init-router1-ddr800-bitstream program-ddr3-ctrl-line-serdes-init-ddr800 validate-ddr3-ctrl-line-serdes-init
.PHONY: ddr3-dq-dqs-iobuf-ddr800-json ddr3-dq-dqs-iobuf-ddr800-bitstream
.PHONY: ddr3-dq-dqs-burst-ddr800-json ddr3-dq-dqs-burst-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-lane0-ddr800-json ddr3-dq-dqs-serdes-lane0-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-lane0-tight-ddr800-json ddr3-dq-dqs-serdes-lane0-tight-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-lane0-tight-router1-ddr800-json ddr3-dq-dqs-serdes-lane0-tight-router1-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-lane0-tight-nodelay-ddr800-json ddr3-dq-dqs-serdes-lane0-tight-nodelay-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-lane0-tight-txonly-ddr800-json ddr3-dq-dqs-serdes-lane0-tight-txonly-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-lane0-tight-rxonly-ddr800-json ddr3-dq-dqs-serdes-lane0-tight-rxonly-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-ch0-ddr800-json ddr3-dq-dqs-serdes-ch0-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-ch0-router1-ddr800-json ddr3-dq-dqs-serdes-ch0-router1-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-ch1-ddr800-json ddr3-dq-dqs-serdes-ch1-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-ch1-router1-ddr800-json ddr3-dq-dqs-serdes-ch1-router1-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-ddr800-json ddr3-dq-dqs-serdes-ddr800-bitstream
.PHONY: ddr3-dq-dqs-serdes-router1-ddr800-json ddr3-dq-dqs-serdes-router1-ddr800-bitstream
.DEFAULT_GOAL := bitstream

bitstream: $(BUILD)/$(PROJECT).bit

jtag-bram-bitstream: bitstream

$(BUILD) $(CHIPDB):
	mkdir -p $@

.PHONY: FORCE
FORCE:

$(DDR3_DEFINES_FILE): FORCE | $(BUILD)
	@tmp="$@.tmp"; \
	printf '%s\n' '$(DDR3_DEFINES)' > $$tmp; \
	if ! cmp -s $$tmp $@; then mv $$tmp $@; else rm $$tmp; fi

$(BUILD)/$(PROJECT).json: $(RTL) $(DDR3_DEFINES_FILE) | $(BUILD)
	yosys -p "read_verilog -sv $(INCDIRS) $(DDR3_DEFINES) $(RTL); synth_xilinx $(YOSYS_SYNTH_ARGS) -arch xc7 -top $(TOP); $(YOSYS_POST_SYNTH) chformal -remove; clean -purge; write_json $@"

ddr3-init-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_init_ddr800 \
	  TOP=top_ddr3_init_probe \
	  RTL="$(DDR3_INIT_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_init_ddr800.json

ddr3-init-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_init_ddr800 \
	  TOP=top_ddr3_init_probe \
	  RTL="$(DDR3_INIT_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --timing-allow-fail --log build/ddr3_init_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_init_ddr800.bit

ddr3-ctrl-loopback-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_loopback_ddr800 \
	  TOP=top_ddr3_ctrl_loopback \
	  RTL="$(DDR3_CTRL_LOOPBACK_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_loopback_ddr800.json

ddr3-ctrl-loopback-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_loopback_ddr800 \
	  TOP=top_ddr3_ctrl_loopback \
	  RTL="$(DDR3_CTRL_LOOPBACK_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=50 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_ctrl_loopback_sys50_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_loopback_ddr800.bit

ddr3-ctrl-line-loopback-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_loopback_ddr800 \
	  TOP=top_ddr3_ctrl_line_loopback \
	  RTL="$(DDR3_CTRL_LINE_LOOPBACK_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_loopback_ddr800.json

ddr3-ctrl-line-loopback-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_loopback_ddr800 \
	  TOP=top_ddr3_ctrl_line_loopback \
	  RTL="$(DDR3_CTRL_LINE_LOOPBACK_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=50 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_ctrl_line_loopback_sys50_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_loopback_ddr800.bit

ddr3-ctrl-line-cmdprobe-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdprobe_ddr800 \
	  TOP=top_ddr3_ctrl_line_cmdprobe \
	  RTL="$(DDR3_CTRL_LINE_CMDPROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdprobe_ddr800.json

ddr3-ctrl-line-cmdprobe-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdprobe_ddr800 \
	  TOP=top_ddr3_ctrl_line_cmdprobe \
	  RTL="$(DDR3_CTRL_LINE_CMDPROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --timing-allow-fail --log build/ddr3_ctrl_line_cmdprobe_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdprobe_ddr800.bit

ddr3-ctrl-line-laneloop-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_laneloop_ddr800 \
	  TOP=top_ddr3_ctrl_line_laneloop \
	  RTL="$(DDR3_CTRL_LINE_LANELOOP_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_laneloop_ddr800.json

ddr3-ctrl-line-laneloop-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_laneloop_ddr800 \
	  TOP=top_ddr3_ctrl_line_laneloop \
	  RTL="$(DDR3_CTRL_LINE_LANELOOP_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=50 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_ctrl_line_laneloop_sys50_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_laneloop_ddr800.bit

ddr3-ctrl-line-cmdlaneloop-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdlaneloop_ddr800 \
	  TOP=top_ddr3_ctrl_line_cmdlaneloop \
	  RTL="$(DDR3_CTRL_LINE_CMDLANELOOP_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdlaneloop_ddr800.json

ddr3-ctrl-line-cmdlaneloop-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdlaneloop_ddr800 \
	  TOP=top_ddr3_ctrl_line_cmdlaneloop \
	  RTL="$(DDR3_CTRL_LINE_CMDLANELOOP_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --timing-allow-fail --log build/ddr3_ctrl_line_cmdlaneloop_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdlaneloop_ddr800.bit

ddr3-ctrl-line-phytimingloop-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_phytimingloop_ddr800 \
	  TOP=top_ddr3_ctrl_line_phytimingloop \
	  RTL="$(DDR3_CTRL_LINE_PHYTIMINGLOOP_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_phytimingloop_ddr800.json

ddr3-ctrl-line-phytimingloop-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_phytimingloop_ddr800 \
	  TOP=top_ddr3_ctrl_line_phytimingloop \
	  RTL="$(DDR3_CTRL_LINE_PHYTIMINGLOOP_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --timing-allow-fail --log build/ddr3_ctrl_line_phytimingloop_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_phytimingloop_ddr800.bit

ddr3-ctrl-line-phyclkloop-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_phyclkloop_ddr800 \
	  TOP=top_ddr3_ctrl_line_phyclkloop \
	  RTL="$(DDR3_CTRL_LINE_PHYCLKLOOP_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_phyclkloop_ddr800.json

ddr3-ctrl-line-phyclkloop-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_phyclkloop_ddr800 \
	  TOP=top_ddr3_ctrl_line_phyclkloop \
	  RTL="$(DDR3_CTRL_LINE_PHYCLKLOOP_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --timing-allow-fail --log build/ddr3_ctrl_line_phyclkloop_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_phyclkloop_ddr800.bit

ddr3-ctrl-line-serdes-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_ddr800 \
	  TOP=top_ddr3_ctrl_line_serdes \
	  RTL="$(DDR3_CTRL_LINE_SERDES_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_ddr800.json

ddr3-ctrl-line-serdes-router1-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_router1_ddr800 \
	  TOP=top_ddr3_ctrl_line_serdes \
	  RTL="$(DDR3_CTRL_LINE_SERDES_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=50 \
	  NEXTPNR_ARGS="--router router1 --seed 1 --log build/ddr3_ctrl_line_serdes_router1_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_router1_ddr800.bit

ddr3-ctrl-line-serdes-init-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_init_ddr800 \
	  TOP=top_ddr3_ctrl_line_serdes_init \
	  RTL="$(DDR3_CTRL_LINE_SERDES_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_init_ddr800.json

ddr3-ctrl-line-serdes-init-router1-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_init_router1_ddr800 \
	  TOP=top_ddr3_ctrl_line_serdes_init \
	  RTL="$(DDR3_CTRL_LINE_SERDES_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=50 \
	  NEXTPNR_ARGS="--router router1 --seed 1 --log build/ddr3_ctrl_line_serdes_init_router1_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_init_router1_ddr800.bit

ddr3-dq-dqs-iobuf-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_iobuf_ddr800 \
	  TOP=top_ddr3_dq_dqs_iobuf_probe \
	  RTL="$(DDR3_DQ_DQS_IO_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_iobuf_ddr800.json

ddr3-dq-dqs-iobuf-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_iobuf_ddr800 \
	  TOP=top_ddr3_dq_dqs_iobuf_probe \
	  RTL="$(DDR3_DQ_DQS_IO_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_iobuf_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_iobuf_ddr800.bit

ddr3-dq-dqs-burst-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_burst_ddr800 \
	  TOP=top_ddr3_dq_dqs_burst_probe \
	  RTL="$(DDR3_DQ_DQS_BURST_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_burst_ddr800.json

ddr3-dq-dqs-burst-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_burst_ddr800 \
	  TOP=top_ddr3_dq_dqs_burst_probe \
	  RTL="$(DDR3_DQ_DQS_BURST_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_burst_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_burst_ddr800.bit

ddr3-dq-dqs-serdes-lane0-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_ACTIVE_LANES=1" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_ddr800.json

ddr3-dq-dqs-serdes-lane0-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_ACTIVE_LANES=1" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_serdes_lane0_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_ddr800.bit

ddr3-dq-dqs-serdes-lane0-tight-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_ddr800.json

ddr3-dq-dqs-serdes-lane0-tight-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_serdes_lane0_tight_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_ddr800.bit

ddr3-dq-dqs-serdes-lane0-tight-router1-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_router1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_router1_ddr800.json

ddr3-dq-dqs-serdes-lane0-tight-router1-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_router1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--router router1 --seed 1 --log build/ddr3_dq_dqs_serdes_lane0_tight_router1_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_router1_ddr800.bit

ddr3-dq-dqs-serdes-lane0-tight-nodelay-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_nodelay_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_USE_IDELAY=0" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_nodelay_ddr800.json

ddr3-dq-dqs-serdes-lane0-tight-nodelay-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_nodelay_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_USE_IDELAY=0" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_serdes_lane0_tight_nodelay_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_nodelay_ddr800.bit

ddr3-dq-dqs-serdes-lane0-tight-txonly-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_txonly_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_ENABLE_RX=0" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_txonly_ddr800.json

ddr3-dq-dqs-serdes-lane0-tight-txonly-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_txonly_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_ENABLE_RX=0" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_serdes_lane0_tight_txonly_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_txonly_ddr800.bit

ddr3-dq-dqs-serdes-lane0-tight-rxonly-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_rxonly_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_ENABLE_TX=0" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_rxonly_ddr800.json

ddr3-dq-dqs-serdes-lane0-tight-rxonly-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_rxonly_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_lane_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_LANE_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch0_lane0_scalar_dqs.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_ENABLE_TX=0" \
	  DDR3_ACTIVE_DQ_MAX=7 \
	  DDR3_ACTIVE_DQS_MAX=0 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_serdes_lane0_tight_rxonly_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_lane0_tight_rxonly_ddr800.bit

ddr3-dq-dqs-serdes-ch0-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch0_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_FIRST_LANE=0 -DDDR3_SERDES_ACTIVE_LANES=9" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch0_ddr800.json

ddr3-dq-dqs-serdes-ch0-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch0_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_FIRST_LANE=0 -DDDR3_SERDES_ACTIVE_LANES=9" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_serdes_ch0_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch0_ddr800.bit

ddr3-dq-dqs-serdes-ch0-router1-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch0_router1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_FIRST_LANE=0 -DDDR3_SERDES_ACTIVE_LANES=9" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch0_router1_ddr800.json

ddr3-dq-dqs-serdes-ch0-router1-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch0_router1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_FIRST_LANE=0 -DDDR3_SERDES_ACTIVE_LANES=9" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--router router1 --seed 1 --log build/ddr3_dq_dqs_serdes_ch0_router1_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch0_router1_ddr800.bit

ddr3-dq-dqs-serdes-ch1-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_FIRST_LANE=9 -DDDR3_SERDES_ACTIVE_LANES=9" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch1_ddr800.json

ddr3-dq-dqs-serdes-ch1-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_FIRST_LANE=9 -DDDR3_SERDES_ACTIVE_LANES=9" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_serdes_ch1_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch1_ddr800.bit

ddr3-dq-dqs-serdes-ch1-router1-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch1_router1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_FIRST_LANE=9 -DDDR3_SERDES_ACTIVE_LANES=9" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch1_router1_ddr800.json

ddr3-dq-dqs-serdes-ch1-router1-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch1_router1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_DEFINES="-DDDR3_SERDES_FIRST_LANE=9 -DDDR3_SERDES_ACTIVE_LANES=9" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--router router1 --seed 1 --log build/ddr3_dq_dqs_serdes_ch1_router1_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ch1_router1_ddr800.bit

ddr3-dq-dqs-serdes-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ddr800.json

ddr3-dq-dqs-serdes-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--seed 1 --log build/ddr3_dq_dqs_serdes_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_ddr800.bit

ddr3-dq-dqs-serdes-router1-ddr800-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_router1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_router1_ddr800.json

ddr3-dq-dqs-serdes-router1-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_router1_ddr800 \
	  TOP=top_ddr3_dq_dqs_serdes_probe \
	  RTL="$(DDR3_DQ_DQS_SERDES_PROBE_RTL)" \
	  XDC_FILES="constraints/ypcb003381p1_active.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=400 \
	  NEXTPNR_ARGS="--router router1 --seed 1 --log build/ddr3_dq_dqs_serdes_router1_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_ddr3_dq_dqs_serdes_router1_ddr800.bit

DDR3_DISABLED_TARGETS := \
    full-ch0-json \
    full-ch0-ddr800-bitstream \
    full-ch0-oddrwr-ddr800-bitstream \
    ratio8-ch0-ddr800-bitstream \
    ratio8-ch0-oddrwr-ddr800-bitstream \
    full-2ch-json \
    full-2ch-serdescmd-json \
    full-2ch-iserdes-json \
    full-2ch-serdescmd-iserdes-json \
    full-2ch-iserdes-bufio-json \
    full-2ch-ddr800-bitstream \
    full-2ch-ddr1600-bitstream \
    full-2ch-ddr1600-jtagonly-bitstream \
    full-2ch-ddr1600-serdescmd-jtagonly-bitstream \
    full-2ch-ddr1600-serdescmd-jtagonly-lateflat-json \
    full-2ch-ddr1600-serdescmd-jtagonly-lateflat-bitstream \
    full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-nrdata-lateflat-bitstream \
    full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-lateflat-bitstream \
    full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-topreq-lateflat-bitstream \
    full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-ctrlreq-topreq-lateflat-bitstream \
    full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-ctrlreq-topreq-router1-lateflat-bitstream \
    program-full-2ch-ddr1600-serdescmd-jtagonly-reqbuf-rmwpatch-ctrlreq-topreq-router1-lateflat \
    full-2ch-ddr1600-serdescmd-jtagdirect-bitstream \
    full-2ch-ddr1600-serdescmd-ddronly-json \
    full-2ch-ddr1600-serdescmd-ddronly-bitstream \
    full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream \
    full-2ch-ddr1600-iserdes-bufio-jtagonly-bitstream \
    full-2ch-ddr1600-jtagdirect-bitstream

$(DDR3_DISABLED_TARGETS):
	@echo "DDR3 RTL is reset; use jtag-bram-bitstream until a fresh DDR3 image exists."

$(CHIPDB)/$(DBPART).bin: | $(CHIPDB)
	@echo ">> generating chipdb for $(PART) (one-time, ~5-15 min)"
	$(PYPY3) $(NEXTPNR_XILINX_PYTHON_DIR)/bbaexport.py --device $(PART) --bba $(BUILD)/$(DBPART).bba
	bbasm -l $(BUILD)/$(DBPART).bba $@
	rm -f $(BUILD)/$(DBPART).bba

$(XDC): $(XDC_FILES) Makefile | $(BUILD)
	perl -ne 'next if /ddr3_dq\[(\d+)\]/ && $$1 > $(DDR3_ACTIVE_DQ_MAX); next if /ddr3_dqs_(?:p|n)\[(\d+)\]/ && $$1 > $(DDR3_ACTIVE_DQS_MAX); print' $(XDC_FILES) > $@

$(BUILD)/$(PROJECT).fasm: $(BUILD)/$(PROJECT).json $(CHIPDB)/$(DBPART).bin $(XDC) Makefile
	nextpnr-xilinx $(NEXTPNR_ARGS) --chipdb $(CHIPDB)/$(DBPART).bin --xdc $(XDC) --json $(BUILD)/$(PROJECT).json --freq $(NEXTPNR_FREQ) --fasm $@

$(BUILD)/$(PROJECT).frames: $(BUILD)/$(PROJECT).fasm
	# Strip ~14 FASM lines that prjxray's kintex7 DB doesn't document:
	#   - OLOGIC{0,1}_OFB route-thru muxes (nextpnr-xilinx emits them
	#     as fabric-side OBUF taps but prjxray has no segbits entry)
	#   - MMCM_CLKOUT*/MMCM_MUXED* mux selects for the CMT_TOP_R cells
	# These bits default to "00" in the bitstream — for now we accept
	# that the MMCM may need a Vivado-flow assist to fully match the
	# expected dynamic-mux configuration in real silicon. The rest of
	# the bitstream is generated byte-for-byte from the design.
	grep -E -v 'OLOGIC[0-9]_OFB\.IOI_OLOGIC[0-9]_D1' $< | \
	  grep -E -v 'MMCM_CLKOUT[0-9]' | \
	  grep -E -v 'MMCM_MUXED[0-9]' > $@.filtered.fasm.tmp
	mv $@.filtered.fasm.tmp $@.filtered.fasm
	fasm2frames --part $(PART) --db-root $(PRJXRAY_DB_DIR)/$(FAMILY) $@.filtered.fasm > $@.tmp
	mv $@.tmp $@

$(BUILD)/$(PROJECT).bit: $(BUILD)/$(PROJECT).frames
	xc7frames2bit --part_file $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART)/part.yaml --part_name $(PART) --frm_file $< --output_file $@

$(FIRMWARE):
	@mkdir -p $(@D)
	curl -fsSL -o $@ $(FIRMWARE_URL)

OFL_BASE := openFPGALoader --cable $(CABLE) --probe-firmware $(FIRMWARE) $(MISC_DEV)
RETRIES  := 1 2 3 4 5 6 7 8 9 10

detect: $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> detect attempt $$i"; \
	  $(OFL_BASE) $(FREQ_DETECT) --detect && exit 0; \
	  sleep 2; \
	done; \
	echo "detect failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program: $(BUILD)/$(PROJECT).bit $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $< && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-jtag-bram: jtag-bram-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program JTAG/BRAM proof attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/$(JTAG_BRAM_PROJECT).bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-init-ddr800: ddr3-init-ddr800-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 init probe attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_init_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-ctrl-loopback-ddr800: ddr3-ctrl-loopback-ddr800-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 controller loopback attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_ctrl_loopback_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-ctrl-line-loopback-ddr800: ddr3-ctrl-line-loopback-ddr800-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 line-controller loopback attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_ctrl_line_loopback_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-ctrl-line-cmdprobe-ddr800: ddr3-ctrl-line-cmdprobe-ddr800-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 line-controller command probe attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdprobe_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-ctrl-line-laneloop-ddr800: ddr3-ctrl-line-laneloop-ddr800-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 line-to-lane loopback attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_ctrl_line_laneloop_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-ctrl-line-cmdlaneloop-ddr800: ddr3-ctrl-line-cmdlaneloop-ddr800-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 command plus line-to-lane loopback attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_ctrl_line_cmdlaneloop_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-ctrl-line-phytimingloop-ddr800: ddr3-ctrl-line-phytimingloop-ddr800-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 abstract PHY-timing loopback attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_ctrl_line_phytimingloop_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-ctrl-line-serdes-init-ddr800: ddr3-ctrl-line-serdes-init-router1-ddr800-bitstream $(FIRMWARE)
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 SERDES init-only attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_ctrl_line_serdes_init_router1_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

program-ddr3-ctrl-line-phyclkloop-ddr800: $(FIRMWARE)
	@if [ "$(ALLOW_TIMING_FAILED_DDR3_EXPERIMENT)" != "1" ]; then \
	  echo "refusing to program DDR3 PHY-clock loopback: this target is a timing-failed experiment"; \
	  echo "last known route reached clk_dq around 107 MHz against the DDR3-800 400 MHz target"; \
	  echo "set ALLOW_TIMING_FAILED_DDR3_EXPERIMENT=1 only for explicit debug, not validation"; \
	  exit 1; \
	fi
	$(MAKE) ddr3-ctrl-line-phyclkloop-ddr800-bitstream
	@for i in $(RETRIES); do \
	  echo ">> program DDR3-800 PHY-clock loopback attempt $$i"; \
	  $(OFL_BASE) $(FREQ_PROGRAM) --index-chain 0 $(BUILD)/bonetto_soc_ypcb00338_ddr3_ctrl_line_phyclkloop_ddr800.bit && exit 0; \
	  sleep 2; \
	done; \
	echo "program failed after 10 attempts -- if all attempts after #1"; \
	echo "showed 'Unable to read constant', the cable is wedged. Physical"; \
	echo "unplug+replug of the USB cable from the Mac is required."; \
	exit 1

memtest: program
	@echo ">> active image is the BRAM-only JTAG/Wishbone proof:"
	@echo "   led[0]=heartbeat  led[1]=last JTAG-WB ack  led[2]=last JTAG-WB err"

xvc: $(FIRMWARE)
	tail -f /dev/null | $(OFL_BASE) $(FREQ_PROGRAM) --xvc --port 3721

validate-jtag-bram:
	cd ../.. && python3 tools/jtag_bram_validate.py --tck-ns 2000

validate-ddr3-init:
	cd ../.. && python3 tools/ddr3_init_validate.py --tck-ns 2000

validate-ddr3-ctrl-loopback:
	cd ../.. && python3 tools/ddr3_ctrl_loopback_validate.py --tck-ns 2000

validate-ddr3-ctrl-line-loopback:
	cd ../.. && python3 tools/ddr3_ctrl_loopback_validate.py --tck-ns 2000 --expected-version 0xB07E0D82 --gate-name DDR3_CTRL_LINE_LOOPBACK

validate-ddr3-ctrl-line-cmdprobe:
	cd ../.. && python3 tools/ddr3_ctrl_loopback_validate.py --tck-ns 2000 --expected-version 0xB07E0D84 --gate-name DDR3_CTRL_LINE_CMDPROBE

validate-ddr3-ctrl-line-laneloop:
	cd ../.. && python3 tools/ddr3_ctrl_loopback_validate.py --tck-ns 2000 --expected-version 0xB07E0D85 --gate-name DDR3_CTRL_LINE_LANELOOP

validate-ddr3-ctrl-line-cmdlaneloop:
	cd ../.. && python3 tools/ddr3_ctrl_loopback_validate.py --tck-ns 2000 --expected-version 0xB07E0D86 --gate-name DDR3_CTRL_LINE_CMDLANELOOP

validate-ddr3-ctrl-line-phytimingloop:
	cd ../.. && python3 tools/ddr3_ctrl_loopback_validate.py --tck-ns 2000 --expected-version 0xB07E0D87 --gate-name DDR3_CTRL_LINE_PHYTIMINGLOOP

validate-ddr3-ctrl-line-phyclkloop:
	cd ../.. && python3 tools/ddr3_ctrl_phyclk_validate.py --tck-ns 2000 --expected-version 0xB07E0D88 --gate-name DDR3_CTRL_LINE_PHYCLKLOOP

validate-ddr3-ctrl-line-serdes-init:
	cd ../.. && python3 tools/ddr3_init_validate.py --tck-ns 2000 --expected-version 0xB07E0D89 --gate-name DDR3_CTRL_LINE_SERDES_INIT --require-ddr-wb-blocked

bram-echo:
	cd ../.. && python3 tools/jtag_bram_echo.py

bram-transform:
	cd ../.. && python3 tools/jtag_bram_echo.py --transform

validate-ddr3:
	@echo "DDR3 RTL is reset; use validate-jtag-bram until a fresh DDR3 image exists."

validate-ddr3-ratio8-ch0:
	@echo "DDR3 RTL is reset; use validate-jtag-bram until a fresh DDR3 image exists."

validate-ddr3-full-ch0:
	@echo "DDR3 RTL is reset; use validate-jtag-bram until a fresh DDR3 image exists."

validate-ddr3-full-2ch:
	@echo "DDR3 RTL is reset; use validate-jtag-bram until a fresh DDR3 image exists."

clean:
	rm -rf $(BUILD)
	rm -rf sim/sim_build sim/sim_build_blu sim/sim_build_clkliv sim/sim_build_mt sim/results.xml sim/__pycache__
	rm -rf formal/memtest_lite_bmc formal/memtest_lite_cover

help:
	@echo "ypcb-00338 board targets:"
	@echo "  make bitstream       synth + PnR + BRAM proof bitstream"
	@echo "  make program         program BRAM proof over JTAG"
	@echo "  make jtag-bram-bitstream  route BRAM-only JTAG/Wishbone proof image"
	@echo "  make program-jtag-bram    program the BRAM-only JTAG/Wishbone proof image"
	@echo "  make validate-jtag-bram   validate BRAM access through XVC/JTAG-WB"
	@echo "  make ddr3-init-ddr800-bitstream  route the full-pin DDR3-800 init probe"
	@echo "  make program-ddr3-init-ddr800    program the DDR3-800 init probe"
	@echo "  make validate-ddr3-init          check DDR3 init probe status over XVC"
	@echo "  make ddr3-ctrl-loopback-ddr800-bitstream  route 50 MHz DDR3 controller loopback image"
	@echo "  make program-ddr3-ctrl-loopback-ddr800    program controller loopback image"
	@echo "  make validate-ddr3-ctrl-loopback          validate JTAG/WB through DDR3 controller loopback"
	@echo "  make ddr3-ctrl-line-loopback-ddr800-bitstream  route line-level DDR3 controller loopback image"
	@echo "  make program-ddr3-ctrl-line-loopback-ddr800    program line-controller loopback image"
	@echo "  make validate-ddr3-ctrl-line-loopback          validate JTAG/WB through line-level controller loopback"
	@echo "  make ddr3-ctrl-line-cmdprobe-ddr800-bitstream  route line controller with DDR command pins enabled"
	@echo "  make program-ddr3-ctrl-line-cmdprobe-ddr800    program line command-probe image"
	@echo "  make validate-ddr3-ctrl-line-cmdprobe          validate JTAG/WB through command-probe image"
	@echo "  make ddr3-ctrl-line-laneloop-ddr800-bitstream  route line-to-lane loopback image"
	@echo "  make program-ddr3-ctrl-line-laneloop-ddr800    program line-to-lane loopback image"
	@echo "  make validate-ddr3-ctrl-line-laneloop          validate JTAG/WB through line-to-lane loopback"
	@echo "  make ddr3-ctrl-line-cmdlaneloop-ddr800-bitstream  route command plus line-to-lane loopback image"
	@echo "  make program-ddr3-ctrl-line-cmdlaneloop-ddr800    program command plus line-to-lane loopback image"
	@echo "  make validate-ddr3-ctrl-line-cmdlaneloop          validate JTAG/WB through command plus line-to-lane loopback"
	@echo "  make ddr3-ctrl-line-phytimingloop-ddr800-bitstream  route command plus abstract PHY-timing loopback"
	@echo "  make program-ddr3-ctrl-line-phytimingloop-ddr800    program abstract PHY-timing loopback"
	@echo "  make validate-ddr3-ctrl-line-phytimingloop          validate JTAG/WB through PHY-timing loopback"
	@echo "  make ddr3-ctrl-line-phyclkloop-ddr800-bitstream  route timing-failed PHY-clock experiment"
	@echo "  make program-ddr3-ctrl-line-phyclkloop-ddr800    refused unless ALLOW_TIMING_FAILED_DDR3_EXPERIMENT=1"
	@echo "  make validate-ddr3-ctrl-line-phyclkloop          debug-only immediate readback through PHY-clock probe"
	@echo "  make ddr3-ctrl-line-serdes-router1-ddr800-bitstream  route-only controller-to-SERDES full x9 CH0+CH1 boundary"
	@echo "  make ddr3-ctrl-line-serdes-init-router1-ddr800-bitstream  route live DDR3 init plus full x9 SERDES shell"
	@echo "  make program-ddr3-ctrl-line-serdes-init-ddr800          program live DDR3 init plus full x9 SERDES shell"
	@echo "  make validate-ddr3-ctrl-line-serdes-init                validate init/status with DDR Wishbone blocked"
	@echo "  make ddr3-dq-dqs-iobuf-ddr800-bitstream         route-only tiny DQ/DQS I/O-shell probe"
	@echo "  make ddr3-dq-dqs-burst-ddr800-bitstream         route-only x8 burst sequencer plus DQ/DQS shell"
	@echo "  make ddr3-dq-dqs-serdes-lane0-tight-ddr800-bitstream         route-only lane0 bidirectional SERDES probe"
	@echo "  make ddr3-dq-dqs-serdes-lane0-tight-router1-ddr800-bitstream route-only lane0 bidirectional SERDES via router1"
	@echo "  make ddr3-dq-dqs-serdes-lane0-tight-nodelay-ddr800-bitstream route-only lane0 bidirectional SERDES without IDELAY"
	@echo "  make ddr3-dq-dqs-serdes-lane0-tight-txonly-ddr800-bitstream  route-only lane0 OSERDES/IOBUF split probe"
	@echo "  make ddr3-dq-dqs-serdes-lane0-tight-rxonly-ddr800-bitstream  route-only lane0 IDELAY/ISERDES split probe"
	@echo "  make ddr3-dq-dqs-serdes-ch0-router1-ddr800-bitstream         route-only CH0 SERDES via router1"
	@echo "  make ddr3-dq-dqs-serdes-ch1-router1-ddr800-bitstream         route-only CH1 SERDES via router1"
	@echo "  make ddr3-dq-dqs-serdes-router1-ddr800-bitstream             route-only CH0+CH1 SERDES via router1"
	@echo "  make bram-echo       interactive BRAM echo terminal through XVC/JTAG-WB"
	@echo "  make bram-transform  interactive transformed-read terminal"
	@echo "  make memtest         program active proof + describe LEDs"
	@echo "  make xvc             run XVC server on port 3721 for host probes"
	@echo "  make validate-ddr3   disabled until fresh DDR3 RTL exists"
	@echo "  DDR3 route/validation targets are intentionally disabled until fresh RTL exists"
	@echo "  make detect          probe JTAG chain"
	@echo "  make clean           remove build artifacts"

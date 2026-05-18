# Board-level synth → PnR → bitstream → program, mirroring the inspur-adventures
# flow but with a multi-IP source list.

PROJECT  := bonetto_soc_ypcb00338
TOP      := top
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

# Source list — all IPs feeding the top
RTL := \
    rtl/top.v \
    rtl/memtest_lite.v \
    rtl/bringup_status_led.v \
    rtl/clk_liveness.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/jtag-uart/rtl/jtag_wb_master.v \
    ../../ip/wishbone/rtl/wb_decode2.v \
    ../../ip/ddr3/rtl/ddr3_ctrl.v \
    ../../ip/ddr3/rtl/ddr3_init.v \
    ../../ip/ddr3/rtl/ddr3_runtime.v \
    ../../ip/ddr3/rtl/ddr3_phy.v \
    ../../ip/ddr3/rtl/ddr3_phy_lane_array.v \
    ../../ip/ddr3/rtl/ddr3_phy_dq.v \
    ../../ip/ddr3/rtl/ddr3_phy_wlvl.v \
    ../../ip/ddr3/rtl/ddr3_phy_rdlvl.v \
    ../../ip/ddr3/rtl/ddr3_cal_seq.v

BUILD  := build
CHIPDB := $(BUILD)/chipdb

# Constraints — base IO pins + DDR3 channel 0 pin map (iter-3a → 3d)
# nextpnr-xilinx takes a single XDC file, so we cat them at build time.
XDC_FILES := constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc
XDC       := $(BUILD)/$(PROJECT).xdc
DDR3_ACTIVE_DQ_MAX  ?= 39
DDR3_ACTIVE_DQS_MAX ?= 4

# Shared-header include dirs are wired into read_verilog inside the
# yosys script (yosys's CLI has no -I flag — includes go via `read_verilog -I`).
INCDIRS := -I ../../verification/common -I ../../ip/wishbone/rtl -I ../../ip/ddr3/rtl

PYPY3  ?= pypy3
NEXTPNR_FREQ ?= 100
NEXTPNR_ARGS ?=
DDR3_DEFINES ?=
DDR3_DEFINES_FILE := $(BUILD)/$(PROJECT).defines.txt

.PHONY: bitstream program detect memtest xvc validate-ddr3 validate-ddr3-ratio8-ch0 validate-ddr3-full-ch0 validate-ddr3-full-2ch ratio8-ch0-ddr800-bitstream ratio8-ch0-oddrwr-ddr800-bitstream full-ch0-json full-ch0-ddr800-bitstream full-ch0-oddrwr-ddr800-bitstream full-2ch-json full-2ch-serdescmd-json full-2ch-iserdes-json full-2ch-serdescmd-iserdes-json full-2ch-iserdes-bufio-json full-2ch-ddr800-bitstream full-2ch-ddr1600-bitstream full-2ch-ddr1600-jtagonly-bitstream full-2ch-ddr1600-serdescmd-jtagonly-bitstream full-2ch-ddr1600-serdescmd-ddronly-json full-2ch-ddr1600-serdescmd-ddronly-bitstream full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream full-2ch-ddr1600-iserdes-bufio-jtagonly-bitstream full-2ch-ddr1600-jtagdirect-bitstream clean help
.DEFAULT_GOAL := bitstream

bitstream: $(BUILD)/$(PROJECT).bit

$(BUILD) $(CHIPDB):
	mkdir -p $@

.PHONY: FORCE
FORCE:

$(DDR3_DEFINES_FILE): FORCE | $(BUILD)
	@tmp="$@.tmp"; \
	printf '%s\n' '$(DDR3_DEFINES)' > $$tmp; \
	if ! cmp -s $$tmp $@; then mv $$tmp $@; else rm $$tmp; fi

$(BUILD)/$(PROJECT).json: $(RTL) $(DDR3_DEFINES_FILE) | $(BUILD)
	yosys -p "read_verilog $(INCDIRS) $(DDR3_DEFINES) $(RTL); synth_xilinx -flatten -abc9 -arch xc7 -top $(TOP); chformal -remove; clean -purge; write_json $@"

full-ch0-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_ch0 \
	  DDR3_DEFINES="-DDDR3_FULL_CH0" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_full_ch0.json

full-ch0-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_ch0_ddr800 \
	  DDR3_DEFINES="-DDDR3_FULL_CH0" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=100 \
	  NEXTPNR_ARGS="--seed 2 --log build/full_ch0_ddr800_seed2_route.log" \
	  build/bonetto_soc_ypcb00338_full_ch0_ddr800.bit

full-ch0-oddrwr-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_ch0_oddrwr_ddr800 \
	  DDR3_DEFINES="-DDDR3_FULL_CH0 -DDDR3_RATIO8_ODDR_WR" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=100 \
	  NEXTPNR_ARGS="--seed 3 --log build/full_ch0_oddrwr_ddr800_seed3_route.log" \
	  build/bonetto_soc_ypcb00338_full_ch0_oddrwr_ddr800.bit

ratio8-ch0-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ratio8_ch0_ddr800 \
	  DDR3_DEFINES="-DDDR3_RATIO8_CH0" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc" \
	  DDR3_ACTIVE_DQ_MAX=39 \
	  DDR3_ACTIVE_DQS_MAX=4 \
	  NEXTPNR_FREQ=100 \
	  NEXTPNR_ARGS="--seed 2 --log build/ratio8_ch0_ddr800_seed2_route.log" \
	  build/bonetto_soc_ypcb00338_ratio8_ch0_ddr800.bit

ratio8-ch0-oddrwr-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_ratio8_ch0_oddrwr_ddr800 \
	  DDR3_DEFINES="-DDDR3_RATIO8_CH0 -DDDR3_RATIO8_ODDR_WR" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc" \
	  DDR3_ACTIVE_DQ_MAX=39 \
	  DDR3_ACTIVE_DQS_MAX=4 \
	  NEXTPNR_FREQ=100 \
	  NEXTPNR_ARGS="--seed 2 --log build/ratio8_ch0_oddrwr_ddr800_seed2_route.log" \
	  build/bonetto_soc_ypcb00338_ratio8_ch0_oddrwr_ddr800.bit

full-2ch-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_full_2ch.json

full-2ch-serdescmd-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_serdescmd \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_SERDES_CMD" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_full_2ch_serdescmd.json

full-2ch-iserdes-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_iserdes \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_RATIO8_ISERDES_RD" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_full_2ch_iserdes.json

full-2ch-serdescmd-iserdes-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_serdescmd_iserdes \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_SERDES_CMD -DDDR3_RATIO8_ISERDES_RD" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_full_2ch_serdescmd_iserdes.json

full-2ch-iserdes-bufio-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_iserdes_bufio \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_RATIO8_ISERDES_RD -DDDR3_RATIO8_ISERDES_BUFIO_RDCLK" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_full_2ch_iserdes_bufio.json

full-2ch-ddr800-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr800 \
	  DDR3_DEFINES="-DDDR3_FULL_2CH" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=100 \
	  NEXTPNR_ARGS="--seed 1 --log build/full_2ch_ddr800_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr800.bit

full-2ch-ddr1600-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr1600 \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=200 \
	  NEXTPNR_ARGS="--seed 1 --log build/full_2ch_ddr1600_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr1600.bit

full-2ch-ddr1600-jtagonly-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr1600_jtagonly \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_JTAG_ONLY" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=200 \
	  NEXTPNR_ARGS="--seed 1 --log build/full_2ch_ddr1600_jtagonly_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr1600_jtagonly.bit

full-2ch-ddr1600-serdescmd-jtagonly-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr1600_serdescmd_jtagonly \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_JTAG_ONLY -DDDR3_SERDES_CMD" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=200 \
	  NEXTPNR_ARGS="--seed 1 --log build/full_2ch_ddr1600_serdescmd_jtagonly_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr1600_serdescmd_jtagonly.bit

full-2ch-ddr1600-serdescmd-ddronly-json:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr1600_serdescmd_ddronly \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_JTAG_ONLY -DDDR3_SERDES_CMD -DDDR3_JTAG_DDR_ONLY" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr1600_serdescmd_ddronly.json

full-2ch-ddr1600-serdescmd-ddronly-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr1600_serdescmd_ddronly \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_JTAG_ONLY -DDDR3_SERDES_CMD -DDDR3_JTAG_DDR_ONLY" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=200 \
	  NEXTPNR_ARGS="--seed 1 --log build/full_2ch_ddr1600_serdescmd_ddronly_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr1600_serdescmd_ddronly.bit

full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr1600_serdescmd_iserdes_jtagonly \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_JTAG_ONLY -DDDR3_SERDES_CMD -DDDR3_RATIO8_ISERDES_RD" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=200 \
	  NEXTPNR_ARGS="--seed 1 --log build/full_2ch_ddr1600_serdescmd_iserdes_jtagonly_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr1600_serdescmd_iserdes_jtagonly.bit

full-2ch-ddr1600-iserdes-bufio-jtagonly-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr1600_iserdes_bufio_jtagonly \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_JTAG_ONLY -DDDR3_RATIO8_ISERDES_RD -DDDR3_RATIO8_ISERDES_BUFIO_RDCLK" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=200 \
	  NEXTPNR_ARGS="--seed 1 --log build/full_2ch_ddr1600_iserdes_bufio_jtagonly_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr1600_iserdes_bufio_jtagonly.bit

full-2ch-ddr1600-jtagdirect-bitstream:
	$(MAKE) PROJECT=bonetto_soc_ypcb00338_full_2ch_ddr1600_jtagdirect \
	  DDR3_DEFINES="-DDDR3_FULL_2CH -DDDR3_RATE_1600 -DDDR3_JTAG_ONLY -DDDR3_DIRECT_WRITE_NO_RMW" \
	  XDC_FILES="constraints/ypcb-00338.xdc constraints/ddr3_ch0.xdc constraints/ddr3_ch1.xdc" \
	  DDR3_ACTIVE_DQ_MAX=71 \
	  DDR3_ACTIVE_DQS_MAX=8 \
	  NEXTPNR_FREQ=200 \
	  NEXTPNR_ARGS="--seed 1 --log build/full_2ch_ddr1600_jtagdirect_seed1_route.log" \
	  build/bonetto_soc_ypcb00338_full_2ch_ddr1600_jtagdirect.bit

$(CHIPDB)/$(DBPART).bin: | $(CHIPDB)
	@echo ">> generating chipdb for $(PART) (one-time, ~5-15 min)"
	$(PYPY3) $(NEXTPNR_XILINX_PYTHON_DIR)/bbaexport.py --device $(PART) --bba $(BUILD)/$(DBPART).bba
	bbasm -l $(BUILD)/$(DBPART).bba $@
	rm -f $(BUILD)/$(DBPART).bba

$(XDC): $(XDC_FILES) Makefile | $(BUILD)
	perl -ne 'next if /ddr3_dq\[(\d+)\]/ && $$1 > $(DDR3_ACTIVE_DQ_MAX); next if /ddr3_dqs_[pn]\[(\d+)\]/ && $$1 > $(DDR3_ACTIVE_DQS_MAX); print' $(XDC_FILES) > $@

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
	  grep -E -v 'MMCM_MUXED[0-9]' > $@.filtered.fasm
	fasm2frames --part $(PART) --db-root $(PRJXRAY_DB_DIR)/$(FAMILY) $@.filtered.fasm > $@

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

memtest: program
	@echo ">> memtest runs on the FPGA; observe the LEDs:"
	@echo "   led[0]=last_ok (should be on)  led[1]=heartbeat (blinking)  led[2]=sticky_err (should be OFF)"

xvc: $(FIRMWARE)
	tail -f /dev/null | $(OFL_BASE) $(FREQ_PROGRAM) --xvc --port 3721

validate-ddr3:
	cd ../.. && python3 tools/ddr3_hw_validate.py \
	  --tck-ns 2000 \
	  --random-count 512 \
	  --checksum-words 2048 \
	  --soak-seconds 600 \
	  --poll-interval 30 \
	  --json boards/ypcb-00338/build/ddr3_hw_validate_latest.json

validate-ddr3-ratio8-ch0:
	cd ../.. && python3 tools/ddr3_hw_validate.py \
	  --addr-bits 25 \
	  --tck-ns 2000 \
	  --random-count 1024 \
	  --checksum-words 4096 \
	  --soak-seconds 600 \
	  --poll-interval 30 \
	  --json boards/ypcb-00338/build/ddr3_hw_validate_ratio8_ch0_latest.json

validate-ddr3-full-ch0:
	cd ../.. && python3 tools/ddr3_hw_validate.py \
	  --addr-bits 29 \
	  --tck-ns 2000 \
	  --random-count 1024 \
	  --checksum-words 4096 \
	  --soak-seconds 600 \
	  --poll-interval 30 \
	  --json boards/ypcb-00338/build/ddr3_hw_validate_full_ch0_latest.json

validate-ddr3-full-2ch:
	cd ../.. && python3 tools/ddr3_hw_validate.py \
	  --addr-bits 30 \
	  --tck-ns 2000 \
	  --random-count 1024 \
	  --checksum-words 4096 \
	  --soak-seconds 600 \
	  --poll-interval 30 \
	  --json boards/ypcb-00338/build/ddr3_hw_validate_full_2ch_latest.json

clean:
	rm -rf $(BUILD)
	rm -rf sim/sim_build sim/sim_build_blu sim/sim_build_clkliv sim/sim_build_mt sim/results.xml sim/__pycache__
	rm -rf formal/memtest_lite_bmc formal/memtest_lite_cover

help:
	@echo "ypcb-00338 board targets:"
	@echo "  make bitstream       synth + PnR + bitstream"
	@echo "  make program         program FPGA SRAM over JTAG"
	@echo "  make memtest         program + observe LEDs"
	@echo "  make xvc             run XVC server on port 3721 for host probes"
	@echo "  make validate-ddr3   run hardware DDR3 validation against XVC"
	@echo "  make validate-ddr3-ratio8-ch0  validate 25-bit CH0 map with RATIO8 PHY"
	@echo "  make validate-ddr3-full-ch0  validate 29-bit full-width CH0 map"
	@echo "  make validate-ddr3-full-2ch  validate 30-bit global DDR3 address map"
	@echo "  make ratio8-ch0-ddr800-bitstream  route 4-lane CH0 with RATIO8 PHY"
	@echo "  make ratio8-ch0-oddrwr-ddr800-bitstream  route RATIO8 CH0 with legacy repeated ODDR writes"
	@echo "  make full-ch0-json   synth build-only 64-bit CH0 / BL8 image"
	@echo "  make full-ch0-ddr800-bitstream  route seeded 64-bit CH0 DDR3-800 image"
	@echo "  make full-ch0-oddrwr-ddr800-bitstream  route full CH0 with legacy ODDR writes, seed 3"
	@echo "  make full-2ch-json   synth build-only 2-channel 4 GiB DDR3-1600 image"
	@echo "  make full-2ch-serdescmd-json  synth hard-serialized command/address image"
	@echo "  make full-2ch-iserdes-json  synth experimental ISERDES read-capture image"
	@echo "  make full-2ch-serdescmd-iserdes-json  synth hard-serialized command/address + ISERDES image"
	@echo "  make full-2ch-iserdes-bufio-json  synth ISERDES read path with BUFIO clock diagnostic"
	@echo "  make full-2ch-ddr800-bitstream  route seeded 2-channel DDR3-800 staging image"
	@echo "  make full-2ch-ddr1600-bitstream  route seeded 2-channel DDR3-1600 target image"
	@echo "  make full-2ch-ddr1600-jtagonly-bitstream  route target image without autonomous memtest"
	@echo "  make full-2ch-ddr1600-serdescmd-jtagonly-bitstream  route hard-command diagnostic"
	@echo "  make full-2ch-ddr1600-serdescmd-ddronly-json  synth hard-command DDR-only diagnostic"
	@echo "  make full-2ch-ddr1600-serdescmd-ddronly-bitstream  route hard-command diagnostic without BRAM/memtest bus mux"
	@echo "  make full-2ch-ddr1600-serdescmd-iserdes-jtagonly-bitstream  route hard-command/ISERDES diagnostic"
	@echo "  make full-2ch-ddr1600-iserdes-bufio-jtagonly-bitstream  route BUFIO/ISERDES diagnostic"
	@echo "  make full-2ch-ddr1600-jtagdirect-bitstream  route JTAG-only target with direct writes and no RMW"
	@echo "  make detect          probe JTAG chain"
	@echo "  make clean           remove build artifacts"

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
FREQ     := --freq 6000000

# Source list — all IPs feeding the top
RTL := \
    rtl/top.v \
    rtl/memtest_lite.v \
    ../../ip/wb-memory/rtl/wb_memory.v \
    ../../ip/jtag-uart/rtl/jtag_uart.v \
    ../../ip/wishbone/rtl/wb_decode2.v
XDC := constraints/ypcb-00338.xdc

# Shared-header include dirs are wired into read_verilog inside the
# yosys script (yosys's CLI has no -I flag — includes go via `read_verilog -I`).
INCDIRS := -I ../../verification/common -I ../../ip/wishbone/rtl

BUILD  := build
CHIPDB := $(BUILD)/chipdb

PYPY3  ?= pypy3

.PHONY: bitstream program detect memtest clean help
.DEFAULT_GOAL := bitstream

bitstream: $(BUILD)/$(PROJECT).bit

$(BUILD) $(CHIPDB):
	mkdir -p $@

$(BUILD)/$(PROJECT).json: $(RTL) | $(BUILD)
	yosys -p "read_verilog $(INCDIRS) $(RTL); synth_xilinx -flatten -abc9 -arch xc7 -top $(TOP); write_json $@"

$(CHIPDB)/$(DBPART).bin: | $(CHIPDB)
	@echo ">> generating chipdb for $(PART) (one-time, ~5-15 min)"
	$(PYPY3) $(NEXTPNR_XILINX_PYTHON_DIR)/bbaexport.py --device $(PART) --bba $(BUILD)/$(DBPART).bba
	bbasm -l $(BUILD)/$(DBPART).bba $@
	rm -f $(BUILD)/$(DBPART).bba

$(BUILD)/$(PROJECT).fasm: $(BUILD)/$(PROJECT).json $(CHIPDB)/$(DBPART).bin $(XDC)
	nextpnr-xilinx --chipdb $(CHIPDB)/$(DBPART).bin --xdc $(XDC) --json $(BUILD)/$(PROJECT).json --fasm $@

$(BUILD)/$(PROJECT).frames: $(BUILD)/$(PROJECT).fasm
	fasm2frames --part $(PART) --db-root $(PRJXRAY_DB_DIR)/$(FAMILY) $< > $@

$(BUILD)/$(PROJECT).bit: $(BUILD)/$(PROJECT).frames
	xc7frames2bit --part_file $(PRJXRAY_DB_DIR)/$(FAMILY)/$(PART)/part.yaml --part_name $(PART) --frm_file $< --output_file $@

$(FIRMWARE):
	@mkdir -p $(@D)
	curl -fsSL -o $@ $(FIRMWARE_URL)

OFL := openFPGALoader --cable $(CABLE) --probe-firmware $(FIRMWARE) $(FREQ) $(MISC_DEV)

detect: $(FIRMWARE)
	@for i in 1 2 3 4 5; do echo ">> detect $$i"; $(OFL) --detect && exit 0; sleep 2; done; \
	echo "detect failed"; exit 1

program: $(BUILD)/$(PROJECT).bit $(FIRMWARE)
	@for i in 1 2 3 4 5; do echo ">> program $$i"; $(OFL) --index-chain 0 $< && exit 0; sleep 2; done; \
	echo "program failed"; exit 1

memtest: program
	@echo ">> memtest runs on the FPGA; observe the LEDs:"
	@echo "   led[0]=last_ok (should be on)  led[1]=heartbeat (blinking)  led[2]=sticky_err (should be OFF)"

clean:
	rm -rf $(BUILD)

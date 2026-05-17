.PHONY: formal sim cocotb clean

# Formal: prove jtag_wb_master is a compliant WB B4 pipelined master.
formal:
	@echo "[jtag-uart] formal: jtag_wb_master against fwb_master"
	cd formal && sby -f jtag_wb_master.sby

# Cocotb tests for jtag_uart (host↔FPGA register IO) + jtag_wb_master
# (WB master command path).
cocotb:
	@$(MAKE) -C sim -f Makefile.cocotb
	@$(MAKE) -C sim -f Makefile.jwb

sim: cocotb

clean:
	rm -rf formal/jtag_wb_master_bmc formal/jtag_wb_master_cover sim/sim_build sim/sim_build_jwb

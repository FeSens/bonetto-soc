.PHONY: formal sim clean

# Formal: prove wb_decode2 satisfies fwb_slave on its master-facing
# port for any well-behaved slave responses on either side.
BUILD := formal/build
SOLVER ?= yices

formal: $(BUILD)/proof.passed

$(BUILD):
	@mkdir -p $@

$(BUILD)/wb_decode2.smt2: rtl/wb_decode2.v ../../formal/vendor/fwb_slave.v formal/wrapper.sv | $(BUILD)
	yosys -q -p "\
	  read_verilog -formal -DFORMAL rtl/wb_decode2.v ../../formal/vendor/fwb_slave.v formal/wrapper.sv; \
	  prep -top wb_decode2_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/proof.passed: $(BUILD)/wb_decode2.smt2
	@echo "[wishbone] formal proof (BMC depth 20, solver=$(SOLVER))"
	yosys-smtbmc --presat -s $(SOLVER) -t 20 $<
	@touch $@

sim:
	@$(MAKE) -C sim -f Makefile.cocotb

clean:
	rm -rf $(BUILD)

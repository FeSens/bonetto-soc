# wb-memory IP Makefile. Driven by top-level via `make formal-wb-memory`
# / `make sim-wb-memory`.
#
# Formal: yosys + yosys-smtbmc directly (no `sby` wrapper). Equivalent
# to an sby `prove` task with bitwuzla/yices/z3 — whichever is on PATH.
# We avoid `pkgs.symbiyosys` because its closure pulls in ghdl-mcode
# which fails to build on aarch64-darwin.

.PHONY: formal sim clean

BUILD := formal/build
SOLVER ?= yices

formal: $(BUILD)/proof.passed

$(BUILD):
	@mkdir -p $@

$(BUILD)/wb_memory.smt2: rtl/wb_memory.v ../../formal/vendor/fwb_slave.v formal/wrapper.sv | $(BUILD)
	yosys -q -p "\
	  read_verilog -formal -DFORMAL rtl/wb_memory.v ../../formal/vendor/fwb_slave.v formal/wrapper.sv; \
	  prep -top wb_memory_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/proof.passed: $(BUILD)/wb_memory.smt2
	@echo "[wb-memory] formal proof (BMC depth 20, solver=$(SOLVER))"
	yosys-smtbmc --presat -s $(SOLVER) -t 20 $<
	@touch $@

sim:
	@$(MAKE) -C sim -f Makefile.cocotb

clean:
	rm -rf $(BUILD)

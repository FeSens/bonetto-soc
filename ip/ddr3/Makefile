.PHONY: formal sim sim-init clean

BUILD := formal/build

# ----- Formal -----
# WB slave protocol compliance: same fwb_slave pattern as ip/wb-memory.
# Init FSM correctness is covered by sim (full traversal needs ~600k
# cycles — sim is way faster than BMC at that depth).

SOLVER ?= yices
DEPTH  ?= 20

formal: $(BUILD)/proof.passed

$(BUILD):
	@mkdir -p $@

$(BUILD)/ddr3_ctrl.smt2: rtl/ddr3_ctrl.v rtl/ddr3_init.v rtl/ddr3_params.vh rtl/ddr3_cmd.vh ../../formal/vendor/fwb_slave.v formal/wrapper.sv | $(BUILD)
	yosys -q -p "\
	  read_verilog -formal -DFORMAL -I rtl rtl/ddr3_ctrl.v rtl/ddr3_init.v ../../formal/vendor/fwb_slave.v formal/wrapper.sv; \
	  prep -top ddr3_ctrl_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/proof.passed: $(BUILD)/ddr3_ctrl.smt2
	@echo "[ddr3] formal: WB slave protocol against fwb_slave (depth $(DEPTH), solver=$(SOLVER))"
	yosys-smtbmc --presat -s $(SOLVER) -t $(DEPTH) $<
	@touch $@

# ----- Sim -----
sim: sim-init

sim-init: sim/build/Vddr3_ctrl
	@./sim/build/Vddr3_ctrl

sim/build/Vddr3_ctrl: sim/tb_ddr3_init.cpp rtl/ddr3_ctrl.v rtl/ddr3_init.v rtl/ddr3_params.vh rtl/ddr3_cmd.vh
	verilator --cc --trace --build --exe -j 0 \
	  --top-module ddr3_ctrl \
	  --Mdir sim/build \
	  -Irtl \
	  -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC -Wno-UNUSEDSIGNAL -Wno-UNUSEDPARAM \
	  rtl/ddr3_ctrl.v rtl/ddr3_init.v \
	  sim/tb_ddr3_init.cpp

clean:
	rm -rf $(BUILD) sim/build ddr3_init.vcd

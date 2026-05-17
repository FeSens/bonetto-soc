.PHONY: formal sim sim-init clean

BUILD := formal/build

# ----- Formal -----
# WB slave protocol compliance: same fwb_slave pattern as ip/wb-memory.
# Init FSM correctness is covered by sim (full traversal needs ~600k
# cycles — sim is way faster than BMC at that depth).

SOLVER ?= yices
DEPTH  ?= 20

formal: $(BUILD)/proof.passed formal-cal-seq

# Cal sequencer FSM safety + cover proofs via SymbiYosys.
.PHONY: formal-cal-seq
formal-cal-seq:
	@echo "[ddr3] formal: cal_seq BMC + cover"
	cd formal/cal_seq && sby -f cal_seq.sby

$(BUILD):
	@mkdir -p $@

$(BUILD)/ddr3_ctrl.smt2: rtl/ddr3_ctrl.v rtl/ddr3_init.v rtl/ddr3_runtime.v rtl/ddr3_params.vh rtl/ddr3_cmd.vh ../../formal/vendor/fwb_slave.v formal/wrapper.sv | $(BUILD)
	yosys -q -p "\
	  read_verilog -formal -DFORMAL -I rtl rtl/ddr3_ctrl.v rtl/ddr3_init.v rtl/ddr3_runtime.v ../../formal/vendor/fwb_slave.v formal/wrapper.sv; \
	  prep -top ddr3_ctrl_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/proof.passed: $(BUILD)/ddr3_ctrl.smt2
	@echo "[ddr3] formal: WB slave protocol against fwb_slave (depth $(DEPTH), solver=$(SOLVER))"
	yosys-smtbmc --presat -s $(SOLVER) -t $(DEPTH) $<
	@touch $@

# ----- Sim -----
# Three flavours:
#   sim-init    = Verilator standalone, cycle-counter view of the init FSM
#                 (fastest, no Micron model — proves the state machine).
#   sim-micron  = Icarus with the Micron MT41K behavioural model wired in.
#                 The model declares "Initialization Sequence is complete"
#                 when our controller drives the JEDEC sequence correctly.
#   cocotb      = Icarus + cocotb test suite. Drives WB transactions after
#                 init_done and asserts the runtime FSM issues correct
#                 ACT/RD/WR/PRE sequences on the DDR3 command bus.
sim: sim-init sim-micron

cocotb:
	@$(MAKE) -C sim -f Makefile.cocotb

sim-init: sim/build/Vddr3_ctrl
	@./sim/build/Vddr3_ctrl

sim/build/Vddr3_ctrl: sim/tb_ddr3_init.cpp rtl/ddr3_ctrl.v rtl/ddr3_init.v rtl/ddr3_runtime.v rtl/ddr3_cal_seq.v rtl/ddr3_params.vh rtl/ddr3_cmd.vh
	verilator --cc --trace --build --exe -j 0 \
	  --top-module ddr3_ctrl \
	  --Mdir sim/build \
	  -Irtl \
	  -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC -Wno-UNUSEDSIGNAL -Wno-UNUSEDPARAM -Wno-SELRANGE \
	  rtl/ddr3_ctrl.v rtl/ddr3_init.v rtl/ddr3_runtime.v rtl/ddr3_cal_seq.v \
	  sim/tb_ddr3_init.cpp

sim-micron: sim/build/ddr3_with_micron.vvp
	@vvp $<

sim/build/ddr3_with_micron.vvp: rtl/ddr3_ctrl.v rtl/ddr3_init.v rtl/ddr3_runtime.v rtl/ddr3_cal_seq.v rtl/ddr3_params.vh rtl/ddr3_cmd.vh sim/vendor/ddr3.v sim/tb_ddr3_init_top.sv
	@mkdir -p sim/build
	iverilog -o $@ -g2012 -Dden2048Mb -Dsg125 -Dx8 -DWITH_MICRON \
	  -Irtl -Isim/vendor \
	  rtl/ddr3_ctrl.v rtl/ddr3_init.v rtl/ddr3_runtime.v rtl/ddr3_cal_seq.v \
	  sim/vendor/ddr3.v sim/tb_ddr3_init_top.sv

clean:
	rm -rf $(BUILD) sim/build ddr3_init.vcd

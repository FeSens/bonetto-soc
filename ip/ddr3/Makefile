.PHONY: formal formal-timing formal-init formal-single-read sim sim-micron-smoke sim-micron-init sim-micron-init-rtl sim-micron-single-read cocotb clean

BUILD        := formal/build
SIM_BUILD    := sim/build
SOLVER       ?= z3
SMTBMC_DEPTH ?= 80

YOSYS        ?= yosys
YOSYS_SMTBMC ?= yosys-smtbmc
IVERILOG     ?= iverilog
VVP          ?= vvp

# The DDR3 implementation was intentionally reset. The active targets below
# keep verification infrastructure live while the clean-sheet controller is
# designed.

formal: formal-timing formal-init formal-single-read

formal-timing: $(BUILD)/timing_monitor.proof

formal-init: $(BUILD)/init_seq.proof

formal-single-read: $(BUILD)/single_read.proof

$(BUILD):
	mkdir -p $@

$(SIM_BUILD):
	mkdir -p $@

$(BUILD)/timing_monitor.smt2: formal/ddr3_cmd_timing_monitor.sv formal/timing_monitor_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL formal/ddr3_cmd_timing_monitor.sv formal/timing_monitor_wrapper.sv; \
	  prep -top ddr3_timing_monitor_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/init_seq.smt2: rtl/ddr3_params.vh rtl/ddr3_init_seq.sv formal/init_seq_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_init_seq.sv formal/init_seq_wrapper.sv; \
	  prep -top ddr3_init_seq_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/single_read.smt2: rtl/ddr3_params.vh rtl/ddr3_single_read_seq.sv formal/ddr3_cmd_timing_monitor.sv formal/single_read_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_single_read_seq.sv formal/ddr3_cmd_timing_monitor.sv formal/single_read_wrapper.sv; \
	  prep -top ddr3_single_read_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/timing_monitor.proof: $(BUILD)/timing_monitor.smt2
	@echo "[ddr3] formal: DDR3 command timing monitor self-check, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/init_seq.proof: $(BUILD)/init_seq.smt2
	@echo "[ddr3] formal: DDR3 init sequencer command order and waits, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/single_read.proof: $(BUILD)/single_read.smt2
	@echo "[ddr3] formal: DDR3 single-bank ACT/READ/PRE/REF sequence, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

sim: sim-micron-smoke sim-micron-init sim-micron-init-rtl sim-micron-single-read

cocotb:
	@echo "[ddr3] cocotb disabled until Wishbone/runtime controller RTL exists; run 'make sim' for Micron init coverage."

sim-micron-smoke: $(SIM_BUILD)/micron_model_smoke.vvp
	@echo "[ddr3] sim: Micron DDR3 model smoke"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data

sim-micron-init: $(SIM_BUILD)/micron_init_script.vvp
	@echo "[ddr3] sim: Micron DDR3-800 initialization script"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data > $(SIM_BUILD)/micron_init_script.log
	cat $(SIM_BUILD)/micron_init_script.log
	@if grep -q "ERROR:" $(SIM_BUILD)/micron_init_script.log; then \
		echo "Micron model reported timing/protocol errors"; \
		exit 1; \
	fi
	@if grep -q "WARNING:" $(SIM_BUILD)/micron_init_script.log; then \
		echo "Micron model reported timing/protocol warnings"; \
		exit 1; \
	fi

sim-micron-init-rtl: $(SIM_BUILD)/micron_init_seq.vvp
	@echo "[ddr3] sim: RTL DDR3-800 init sequencer against Micron model"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data > $(SIM_BUILD)/micron_init_seq.log
	cat $(SIM_BUILD)/micron_init_seq.log
	@if grep -q "ERROR:" $(SIM_BUILD)/micron_init_seq.log; then \
		echo "Micron model reported timing/protocol errors"; \
		exit 1; \
	fi
	@if grep -q "WARNING:" $(SIM_BUILD)/micron_init_seq.log; then \
		echo "Micron model reported timing/protocol warnings"; \
		exit 1; \
	fi

sim-micron-single-read: $(SIM_BUILD)/micron_single_read.vvp
	@echo "[ddr3] sim: RTL init plus single-bank READ command sequence against Micron model"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data > $(SIM_BUILD)/micron_single_read.log
	cat $(SIM_BUILD)/micron_single_read.log
	@if grep -q "ERROR:" $(SIM_BUILD)/micron_single_read.log; then \
		echo "Micron model reported timing/protocol errors"; \
		exit 1; \
	fi
	@if grep -q "WARNING:" $(SIM_BUILD)/micron_single_read.log; then \
		echo "Micron model reported timing/protocol warnings"; \
		exit 1; \
	fi

$(SIM_BUILD)/micron_model_smoke.vvp: sim/tb_micron_model_smoke.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_model_smoke \
	  -o $@ sim/tb_micron_model_smoke.sv sim/vendor/ddr3.v

$(SIM_BUILD)/micron_init_script.vvp: sim/tb_micron_init_script.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_init_script \
	  -o $@ sim/tb_micron_init_script.sv sim/vendor/ddr3.v

$(SIM_BUILD)/micron_init_seq.vvp: rtl/ddr3_params.vh rtl/ddr3_init_seq.sv sim/tb_micron_init_seq.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_init_seq \
	  -o $@ rtl/ddr3_init_seq.sv sim/tb_micron_init_seq.sv sim/vendor/ddr3.v

$(SIM_BUILD)/micron_single_read.vvp: rtl/ddr3_params.vh rtl/ddr3_init_seq.sv rtl/ddr3_single_read_seq.sv sim/tb_micron_single_read.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_single_read \
	  -o $@ rtl/ddr3_init_seq.sv rtl/ddr3_single_read_seq.sv sim/tb_micron_single_read.sv sim/vendor/ddr3.v

clean:
	rm -rf $(BUILD) $(SIM_BUILD) sim/sim_build sim/sim_build_* sim/build_micron
	rm -rf sim/__pycache__
	rm -f sim/results.xml sim/results_*.xml ddr3_init.vcd ddr3_init_micron.vcd

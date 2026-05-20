.PHONY: formal formal-timing sim sim-micron-smoke sim-micron-init cocotb clean

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

formal: formal-timing

formal-timing: $(BUILD)/timing_monitor.proof

$(BUILD):
	mkdir -p $@

$(SIM_BUILD):
	mkdir -p $@

$(BUILD)/timing_monitor.smt2: formal/ddr3_cmd_timing_monitor.sv formal/timing_monitor_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL formal/ddr3_cmd_timing_monitor.sv formal/timing_monitor_wrapper.sv; \
	  prep -top ddr3_timing_monitor_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/timing_monitor.proof: $(BUILD)/timing_monitor.smt2
	@echo "[ddr3] formal: DDR3 command timing monitor self-check, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

sim: sim-micron-smoke sim-micron-init

cocotb:
	@echo "[ddr3] cocotb disabled until the clean-sheet controller RTL exists; run 'make sim' for live Micron model smoke coverage."

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

clean:
	rm -rf $(BUILD) $(SIM_BUILD) sim/sim_build sim/sim_build_* sim/build_micron
	rm -rf sim/__pycache__
	rm -f sim/results.xml sim/results_*.xml ddr3_init.vcd ddr3_init_micron.vcd

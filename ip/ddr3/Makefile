.PHONY: formal formal-timing formal-init formal-single-read formal-single-write-read formal-bank formal-scheduler formal-refresh formal-refresh-traffic formal-byte-lane formal-channel-line formal-wb-frontend formal-wb-channel sim sim-byte-lane sim-channel-line sim-wb-frontend sim-wb-channel sim-micron-smoke sim-micron-init sim-micron-init-rtl sim-micron-single-read sim-micron-single-write-read cocotb clean

BUILD        := formal/build
SIM_BUILD    := sim/build
SOLVER       ?= z3
SMTBMC_DEPTH ?= 80
SCHED_SMTBMC_DEPTH ?= 36
REFRESH_SMTBMC_DEPTH ?= 80
REFRESH_TRAFFIC_SMTBMC_DEPTH ?= 72
CHANNEL_LINE_SMTBMC_DEPTH ?= 24
WB_CHANNEL_SMTBMC_DEPTH ?= 36

YOSYS        ?= yosys
YOSYS_SMTBMC ?= yosys-smtbmc
IVERILOG     ?= iverilog
VVP          ?= vvp

# The DDR3 implementation was intentionally reset. The active targets below
# keep verification infrastructure live while the clean-sheet controller is
# designed.

formal: formal-timing formal-init formal-single-read formal-single-write-read formal-bank formal-scheduler formal-refresh formal-refresh-traffic formal-byte-lane formal-channel-line formal-wb-frontend formal-wb-channel

formal-timing: $(BUILD)/timing_monitor.proof

formal-init: $(BUILD)/init_seq.proof

formal-single-read: $(BUILD)/single_read.proof

formal-single-write-read: $(BUILD)/single_write_read.proof

formal-bank: $(BUILD)/bank.proof

formal-scheduler: $(BUILD)/scheduler.proof

formal-refresh: $(BUILD)/refresh.proof

formal-refresh-traffic: $(BUILD)/refresh_traffic.proof

formal-byte-lane: $(BUILD)/byte_lane.proof

formal-channel-line: $(BUILD)/channel_line.proof

formal-wb-frontend: $(BUILD)/wb_frontend.proof

formal-wb-channel: $(BUILD)/wb_channel.proof

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

$(BUILD)/single_write_read.smt2: rtl/ddr3_params.vh rtl/ddr3_single_write_read_seq.sv formal/ddr3_cmd_timing_monitor.sv formal/single_write_read_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_single_write_read_seq.sv formal/ddr3_cmd_timing_monitor.sv formal/single_write_read_wrapper.sv; \
	  prep -top ddr3_single_write_read_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/bank.smt2: rtl/ddr3_params.vh rtl/ddr3_bank.sv formal/ddr3_cmd_timing_monitor.sv formal/bank_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_bank.sv formal/ddr3_cmd_timing_monitor.sv formal/bank_wrapper.sv; \
	  prep -top ddr3_bank_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/scheduler.smt2: rtl/ddr3_params.vh rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv formal/ddr3_cmd_timing_monitor.sv formal/scheduler_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv formal/ddr3_cmd_timing_monitor.sv formal/scheduler_wrapper.sv; \
	  prep -top ddr3_scheduler_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/refresh.smt2: rtl/ddr3_params.vh rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv formal/ddr3_cmd_timing_monitor.sv formal/refresh_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv formal/ddr3_cmd_timing_monitor.sv formal/refresh_wrapper.sv; \
	  prep -top ddr3_refresh_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/refresh_traffic.smt2: rtl/ddr3_params.vh rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv formal/ddr3_cmd_timing_monitor.sv formal/refresh_traffic_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv formal/ddr3_cmd_timing_monitor.sv formal/refresh_traffic_wrapper.sv; \
	  prep -top ddr3_refresh_traffic_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/byte_lane.smt2: rtl/ddr3_byte_lane.sv formal/byte_lane_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_byte_lane.sv formal/byte_lane_wrapper.sv; \
	  prep -top ddr3_byte_lane_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/channel_line.smt2: rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv formal/channel_line_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv formal/channel_line_wrapper.sv; \
	  prep -top ddr3_channel_line_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/wb_frontend.smt2: rtl/ddr3_wb_frontend.sv ../../formal/vendor/fwb_slave.v formal/wb_frontend_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_wb_frontend.sv ../../formal/vendor/fwb_slave.v formal/wb_frontend_wrapper.sv; \
	  prep -top ddr3_wb_frontend_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/wb_channel.smt2: rtl/ddr3_wb_frontend.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_channel_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_wb_frontend.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_channel_wrapper.sv; \
	  prep -top ddr3_wb_channel_wrapper; \
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

$(BUILD)/single_write_read.proof: $(BUILD)/single_write_read.smt2
	@echo "[ddr3] formal: DDR3 single-bank ACT/WRITE/READ/PRE/REF sequence, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/bank.proof: $(BUILD)/bank.smt2
	@echo "[ddr3] formal: DDR3 one-bank row machine, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/scheduler.proof: $(BUILD)/scheduler.smt2
	@echo "[ddr3] formal: DDR3 scheduler refresh/global timing slice, depth=$(SCHED_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SCHED_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/refresh.proof: $(BUILD)/refresh.smt2
	@echo "[ddr3] formal: DDR3 periodic refresh requester and idle scheduler path, depth=$(REFRESH_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(REFRESH_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/refresh_traffic.proof: $(BUILD)/refresh_traffic.smt2
	@echo "[ddr3] formal: DDR3 periodic refresh with in-flight scheduler traffic, depth=$(REFRESH_TRAFFIC_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(REFRESH_TRAFFIC_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/byte_lane.proof: $(BUILD)/byte_lane.smt2
	@echo "[ddr3] formal: DDR3 x8 byte-lane BL8 packetizer, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/channel_line.proof: $(BUILD)/channel_line.smt2
	@echo "[ddr3] formal: DDR3 full-channel BL8 line packetizer, depth=$(CHANNEL_LINE_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(CHANNEL_LINE_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/wb_frontend.proof: $(BUILD)/wb_frontend.smt2
	@echo "[ddr3] formal: DDR3 Wishbone-to-BL8 frontend, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/wb_channel.proof: $(BUILD)/wb_channel.smt2
	@echo "[ddr3] formal: DDR3 Wishbone-to-full-channel bridge, depth=$(WB_CHANNEL_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(WB_CHANNEL_SMTBMC_DEPTH) $<
	@touch $@

sim: sim-byte-lane sim-channel-line sim-wb-frontend sim-wb-channel sim-micron-smoke sim-micron-init sim-micron-init-rtl sim-micron-single-read sim-micron-single-write-read

cocotb:
	@echo "[ddr3] cocotb disabled until Wishbone/runtime controller RTL exists; run 'make sim' for Micron init coverage."

sim-micron-smoke: $(SIM_BUILD)/micron_model_smoke.vvp
	@echo "[ddr3] sim: Micron DDR3 model smoke"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data

sim-byte-lane: $(SIM_BUILD)/byte_lane.vvp
	@echo "[ddr3] sim: DDR3 x8 byte-lane packetizer"
	$(VVP) $<

sim-channel-line: $(SIM_BUILD)/channel_line.vvp
	@echo "[ddr3] sim: DDR3 full-channel BL8 line packetizer"
	$(VVP) $<

sim-wb-frontend: $(SIM_BUILD)/wb_frontend.vvp
	@echo "[ddr3] sim: DDR3 Wishbone-to-BL8 frontend"
	$(VVP) $<

sim-wb-channel: $(SIM_BUILD)/wb_channel.vvp
	@echo "[ddr3] sim: DDR3 Wishbone-to-full-channel bridge"
	$(VVP) $<

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

sim-micron-single-write-read: $(SIM_BUILD)/micron_single_write_read.vvp
	@echo "[ddr3] sim: RTL init plus single-bank WRITE/READ x8 loopback against Micron model"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data > $(SIM_BUILD)/micron_single_write_read.log
	cat $(SIM_BUILD)/micron_single_write_read.log
	@if grep -q "ERROR:" $(SIM_BUILD)/micron_single_write_read.log; then \
		echo "Micron model reported timing/protocol errors"; \
		exit 1; \
	fi
	@if grep -q "WARNING:" $(SIM_BUILD)/micron_single_write_read.log; then \
		echo "Micron model reported timing/protocol warnings"; \
		exit 1; \
	fi

$(SIM_BUILD)/micron_model_smoke.vvp: sim/tb_micron_model_smoke.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_model_smoke \
	  -o $@ sim/tb_micron_model_smoke.sv sim/vendor/ddr3.v

$(SIM_BUILD)/byte_lane.vvp: rtl/ddr3_byte_lane.sv sim/tb_byte_lane.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_byte_lane \
	  -o $@ rtl/ddr3_byte_lane.sv sim/tb_byte_lane.sv

$(SIM_BUILD)/channel_line.vvp: rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv sim/tb_channel_line.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_channel_line \
	  -o $@ rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv sim/tb_channel_line.sv

$(SIM_BUILD)/wb_frontend.vvp: rtl/ddr3_wb_frontend.sv sim/tb_wb_frontend.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_wb_frontend \
	  -o $@ rtl/ddr3_wb_frontend.sv sim/tb_wb_frontend.sv

$(SIM_BUILD)/wb_channel.vvp: rtl/ddr3_wb_frontend.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv sim/tb_wb_channel.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_wb_channel \
	  -o $@ rtl/ddr3_wb_frontend.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv sim/tb_wb_channel.sv

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

$(SIM_BUILD)/micron_single_write_read.vvp: rtl/ddr3_params.vh rtl/ddr3_init_seq.sv rtl/ddr3_single_write_read_seq.sv rtl/ddr3_byte_lane.sv sim/tb_micron_single_write_read.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_single_write_read \
	  -o $@ rtl/ddr3_init_seq.sv rtl/ddr3_single_write_read_seq.sv rtl/ddr3_byte_lane.sv sim/tb_micron_single_write_read.sv sim/vendor/ddr3.v

clean:
	rm -rf $(BUILD) $(SIM_BUILD) sim/sim_build sim/sim_build_* sim/build_micron
	rm -rf sim/__pycache__
	rm -f sim/results.xml sim/results_*.xml ddr3_init.vcd ddr3_init_micron.vcd

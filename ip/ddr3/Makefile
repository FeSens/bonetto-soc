.PHONY: formal formal-addr-decode formal-timing formal-init formal-single-read formal-single-write-read formal-bank formal-scheduler formal-refresh formal-refresh-traffic formal-byte-lane formal-channel-line formal-line-to-lanes formal-line-to-bursts formal-x8-to-x9-line-adapter formal-x8-lane-phy formal-x8-burst-io-sequencer formal-x8-serdes-burst-lane formal-x8-burst-clock-bridge formal-line-burst-phy formal-line-serdes-phy formal-line-lane-phy formal-line-phy-clock-bridge formal-idelay-cal-cdc formal-wb-frontend formal-wb-channel formal-wb-line-channel formal-wb-line-channel-rmw formal-wb-dual-channel formal-wb-dual-channel-line formal-channel-sched formal-ctrl formal-ctrl-line sim sim-addr-decode sim-byte-lane sim-channel-line sim-line-to-lanes sim-line-to-bursts sim-x8-to-x9-line-adapter sim-x8-lane-phy sim-x8-burst-io-sequencer sim-x8-serdes-burst-lane sim-x8-burst-clock-bridge sim-line-burst-phy sim-line-serdes-phy sim-line-lane-phy sim-line-phy-clock-bridge sim-idelay-cal-cdc sim-wb-frontend sim-wb-channel sim-wb-line-channel sim-wb-line-channel-rmw sim-wb-dual-channel sim-wb-dual-channel-line sim-channel-sched sim-ctrl sim-ctrl-line sim-micron-smoke sim-micron-init sim-micron-init-rtl sim-micron-single-read sim-micron-single-write-read sim-micron-x8-agent sim-micron-ctrl-dual-channel sim-micron-ctrl-line-dual-channel cocotb clean

BUILD        := formal/build
SIM_BUILD    := sim/build
SOLVER       ?= z3
SMTBMC_DEPTH ?= 80
SCHED_SMTBMC_DEPTH ?= 36
REFRESH_SMTBMC_DEPTH ?= 80
REFRESH_TRAFFIC_SMTBMC_DEPTH ?= 72
CHANNEL_LINE_SMTBMC_DEPTH ?= 24
LINE_TO_LANES_SMTBMC_DEPTH ?= 18
LINE_TO_BURSTS_SMTBMC_DEPTH ?= 12
LINE_TO_BURSTS_SOLVER ?= yices
X8_TO_X9_LINE_ADAPTER_SMTBMC_DEPTH ?= 2
X8_LANE_PHY_SMTBMC_DEPTH ?= 10
X8_BURST_IO_SEQUENCER_SMTBMC_DEPTH ?= 14
X8_SERDES_BURST_LANE_SMTBMC_DEPTH ?= 14
X8_BURST_CLOCK_BRIDGE_SMTBMC_DEPTH ?= 32
LINE_BURST_PHY_SMTBMC_DEPTH ?= 96
LINE_SERDES_PHY_SMTBMC_DEPTH ?= 96
LINE_LANE_PHY_WRITE_SMTBMC_DEPTH ?= 26
LINE_LANE_PHY_READ_SMTBMC_DEPTH ?= 30
LINE_LANE_PHY_SOLVER ?= yices
LINE_PHY_CLOCK_BRIDGE_SMTBMC_DEPTH ?= 36
IDELAY_CAL_CDC_SMTBMC_DEPTH ?= 64
WB_CHANNEL_SMTBMC_DEPTH ?= 36
WB_LINE_RMW_SMTBMC_DEPTH ?= 18
WB_DUAL_CHANNEL_SMTBMC_DEPTH ?= 36
CHANNEL_SCHED_SMTBMC_DEPTH ?= 48
CTRL_SMTBMC_DEPTH ?= 24

YOSYS        ?= yosys
YOSYS_SMTBMC ?= yosys-smtbmc
IVERILOG     ?= iverilog
VVP          ?= vvp

# The DDR3 implementation was intentionally reset. The active targets below
# keep verification infrastructure live while the clean-sheet controller is
# designed.

formal: formal-addr-decode formal-timing formal-init formal-single-read formal-single-write-read formal-bank formal-scheduler formal-refresh formal-refresh-traffic formal-byte-lane formal-channel-line formal-line-to-lanes formal-line-to-bursts formal-x8-to-x9-line-adapter formal-x8-lane-phy formal-x8-burst-io-sequencer formal-x8-serdes-burst-lane formal-x8-burst-clock-bridge formal-line-burst-phy formal-line-serdes-phy formal-line-lane-phy formal-line-phy-clock-bridge formal-idelay-cal-cdc formal-wb-frontend formal-wb-channel formal-wb-line-channel formal-wb-line-channel-rmw formal-wb-dual-channel formal-wb-dual-channel-line formal-channel-sched formal-ctrl formal-ctrl-line

formal-addr-decode: $(BUILD)/addr_decode.proof

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

formal-line-to-lanes: $(BUILD)/line_to_lanes.proof

formal-line-to-bursts: $(BUILD)/line_to_bursts.proof

formal-x8-to-x9-line-adapter: $(BUILD)/x8_to_x9_line_adapter.proof

formal-x8-lane-phy: $(BUILD)/x8_lane_phy.proof

formal-x8-burst-io-sequencer: $(BUILD)/x8_burst_io_sequencer.proof

formal-x8-serdes-burst-lane: $(BUILD)/x8_serdes_burst_lane.proof

formal-x8-burst-clock-bridge: $(BUILD)/x8_burst_clock_bridge.proof

formal-line-burst-phy: $(BUILD)/line_burst_phy.proof

formal-line-serdes-phy: $(BUILD)/line_serdes_phy.proof

formal-line-lane-phy: $(BUILD)/line_lane_phy_write.proof $(BUILD)/line_lane_phy_read.proof

formal-line-phy-clock-bridge: $(BUILD)/line_phy_clock_bridge.proof

formal-idelay-cal-cdc: $(BUILD)/idelay_cal_cdc.proof

formal-wb-frontend: $(BUILD)/wb_frontend.proof

formal-wb-channel: $(BUILD)/wb_channel.proof

formal-wb-line-channel: $(BUILD)/wb_line_channel.proof

formal-wb-line-channel-rmw: $(BUILD)/wb_line_channel_rmw.proof

formal-wb-dual-channel: $(BUILD)/wb_dual_channel.proof

formal-wb-dual-channel-line: $(BUILD)/wb_dual_channel_line.proof

formal-channel-sched: $(BUILD)/channel_sched.proof

formal-ctrl: $(BUILD)/ctrl.proof

formal-ctrl-line: $(BUILD)/ctrl_line.proof

$(BUILD):
	mkdir -p $@

$(SIM_BUILD):
	mkdir -p $@

$(BUILD)/addr_decode.smt2: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv formal/addr_decode_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_addr_decode.sv formal/addr_decode_wrapper.sv; \
	  prep -top ddr3_addr_decode_wrapper; \
	  write_smt2 -wires $@"

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

$(BUILD)/line_to_lanes.smt2: rtl/ddr3_line_to_lanes.sv formal/line_to_lanes_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_line_to_lanes.sv formal/line_to_lanes_wrapper.sv; \
	  prep -top ddr3_line_to_lanes_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/line_to_bursts.smt2: rtl/ddr3_line_to_bursts.sv formal/line_to_bursts_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_line_to_bursts.sv formal/line_to_bursts_wrapper.sv; \
	  prep -top ddr3_line_to_bursts_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/x8_to_x9_line_adapter.smt2: rtl/ddr3_x8_to_x9_line_adapter.sv formal/x8_to_x9_line_adapter_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_x8_to_x9_line_adapter.sv formal/x8_to_x9_line_adapter_wrapper.sv; \
	  prep -top ddr3_x8_to_x9_line_adapter_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/x8_lane_phy.smt2: rtl/ddr3_x8_lane_phy.sv formal/x8_lane_phy_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_x8_lane_phy.sv formal/x8_lane_phy_wrapper.sv; \
	  prep -top ddr3_x8_lane_phy_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/x8_burst_io_sequencer.smt2: rtl/ddr3_x8_burst_io_sequencer.sv formal/x8_burst_io_sequencer_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_x8_burst_io_sequencer.sv formal/x8_burst_io_sequencer_wrapper.sv; \
	  prep -top ddr3_x8_burst_io_sequencer_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/x8_serdes_burst_lane.smt2: rtl/ddr3_x8_serdes_burst_lane.sv formal/x8_serdes_burst_lane_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_x8_serdes_burst_lane.sv formal/x8_serdes_burst_lane_wrapper.sv; \
	  prep -top ddr3_x8_serdes_burst_lane_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/x8_burst_clock_bridge.smt2: rtl/ddr3_x8_burst_clock_bridge.sv formal/x8_burst_clock_bridge_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_x8_burst_clock_bridge.sv formal/x8_burst_clock_bridge_wrapper.sv; \
	  prep -top ddr3_x8_burst_clock_bridge_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/line_burst_phy.smt2: rtl/ddr3_line_to_bursts.sv rtl/ddr3_x8_burst_clock_bridge.sv rtl/ddr3_x8_burst_io_sequencer.sv rtl/ddr3_line_burst_phy.sv formal/line_burst_phy_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_line_to_bursts.sv rtl/ddr3_x8_burst_clock_bridge.sv rtl/ddr3_x8_burst_io_sequencer.sv rtl/ddr3_line_burst_phy.sv formal/line_burst_phy_wrapper.sv; \
	  prep -top ddr3_line_burst_phy_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/line_serdes_phy.smt2: rtl/ddr3_line_to_bursts.sv rtl/ddr3_x8_burst_clock_bridge.sv rtl/ddr3_x8_serdes_burst_lane.sv rtl/ddr3_line_serdes_phy.sv formal/line_serdes_phy_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_line_to_bursts.sv rtl/ddr3_x8_burst_clock_bridge.sv rtl/ddr3_x8_serdes_burst_lane.sv rtl/ddr3_line_serdes_phy.sv formal/line_serdes_phy_wrapper.sv; \
	  prep -top ddr3_line_serdes_phy_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/line_lane_phy_write.smt2: rtl/ddr3_line_to_lanes.sv rtl/ddr3_x8_lane_phy.sv rtl/ddr3_line_lane_phy.sv formal/line_lane_phy_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_line_to_lanes.sv rtl/ddr3_x8_lane_phy.sv rtl/ddr3_line_lane_phy.sv formal/line_lane_phy_wrapper.sv; \
	  prep -top ddr3_line_lane_phy_write_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/line_lane_phy_read.smt2: rtl/ddr3_line_to_lanes.sv rtl/ddr3_x8_lane_phy.sv rtl/ddr3_line_lane_phy.sv formal/line_lane_phy_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_line_to_lanes.sv rtl/ddr3_x8_lane_phy.sv rtl/ddr3_line_lane_phy.sv formal/line_lane_phy_wrapper.sv; \
	  prep -top ddr3_line_lane_phy_read_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/line_phy_clock_bridge.smt2: rtl/ddr3_line_phy_clock_bridge.sv formal/line_phy_clock_bridge_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_line_phy_clock_bridge.sv formal/line_phy_clock_bridge_wrapper.sv; \
	  prep -top ddr3_line_phy_clock_bridge_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/idelay_cal_cdc.smt2: rtl/ddr3_idelay_cal_cdc.sv formal/idelay_cal_cdc_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_idelay_cal_cdc.sv formal/idelay_cal_cdc_wrapper.sv; \
	  prep -top ddr3_idelay_cal_cdc_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/wb_frontend.smt2: rtl/ddr3_wb_frontend.sv ../../formal/vendor/fwb_slave.v formal/wb_frontend_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_wb_frontend.sv ../../formal/vendor/fwb_slave.v formal/wb_frontend_wrapper.sv; \
	  prep -top ddr3_wb_frontend_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/wb_channel.smt2: rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_channel_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_channel_wrapper.sv; \
	  prep -top ddr3_wb_channel_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/wb_line_channel.smt2: rtl/ddr3_wb_line_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_line_channel_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_wb_line_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_line_channel_wrapper.sv; \
	  prep -top ddr3_wb_line_channel_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/wb_line_channel_rmw.smt2: rtl/ddr3_wb_line_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_line_channel_rmw_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -formal -sv -DFORMAL rtl/ddr3_wb_line_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_line_channel_rmw_wrapper.sv; \
	  prep -top ddr3_wb_line_channel_rmw_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/wb_dual_channel.smt2: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_dual_channel_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_addr_decode.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv ../../formal/vendor/fwb_slave.v formal/wb_dual_channel_wrapper.sv; \
	  prep -top ddr3_wb_dual_channel_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/wb_dual_channel_line.smt2: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv ../../formal/vendor/fwb_slave.v formal/wb_dual_channel_line_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_addr_decode.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv ../../formal/vendor/fwb_slave.v formal/wb_dual_channel_line_wrapper.sv; \
	  prep -top ddr3_wb_dual_channel_line_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/channel_sched.smt2: rtl/ddr3_params.vh rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv formal/ddr3_cmd_timing_monitor.sv formal/channel_sched_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv formal/ddr3_cmd_timing_monitor.sv formal/channel_sched_wrapper.sv; \
	  prep -top ddr3_channel_sched_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/ctrl.smt2: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv rtl/ddr3_ctrl.sv formal/ctrl_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv rtl/ddr3_ctrl.sv formal/ctrl_wrapper.sv; \
	  prep -top ddr3_ctrl_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/ctrl_line.smt2: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv rtl/ddr3_ctrl_line.sv formal/ctrl_line_wrapper.sv | $(BUILD)
	$(YOSYS) -q -p "\
	  read_verilog -Irtl -formal -sv -DFORMAL rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv rtl/ddr3_ctrl_line.sv formal/ctrl_line_wrapper.sv; \
	  prep -top ddr3_ctrl_line_wrapper; \
	  write_smt2 -wires $@"

$(BUILD)/addr_decode.proof: $(BUILD)/addr_decode.smt2
	@echo "[ddr3] formal: DDR3 full-capacity address decoder, solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t 1 $<
	@touch $@

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

$(BUILD)/line_to_lanes.proof: $(BUILD)/line_to_lanes.smt2
	@echo "[ddr3] formal: DDR3 line-to-x8-lane adapter, depth=$(LINE_TO_LANES_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(LINE_TO_LANES_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/line_to_bursts.proof: $(BUILD)/line_to_bursts.smt2
	@echo "[ddr3] formal: DDR3 line-to-x8-burst adapter, depth=$(LINE_TO_BURSTS_SMTBMC_DEPTH), solver=$(LINE_TO_BURSTS_SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(LINE_TO_BURSTS_SOLVER) -t $(LINE_TO_BURSTS_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/x8_to_x9_line_adapter.proof: $(BUILD)/x8_to_x9_line_adapter.smt2
	@echo "[ddr3] formal: DDR3 x8-data to x9-physical line adapter, depth=$(X8_TO_X9_LINE_ADAPTER_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(X8_TO_X9_LINE_ADAPTER_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/x8_lane_phy.proof: $(BUILD)/x8_lane_phy.smt2
	@echo "[ddr3] formal: DDR3 x8 lane PHY timing core, depth=$(X8_LANE_PHY_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(X8_LANE_PHY_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/x8_burst_io_sequencer.proof: $(BUILD)/x8_burst_io_sequencer.smt2
	@echo "[ddr3] formal: DDR3 x8 fast burst I/O sequencer, depth=$(X8_BURST_IO_SEQUENCER_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(X8_BURST_IO_SEQUENCER_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/x8_serdes_burst_lane.proof: $(BUILD)/x8_serdes_burst_lane.smt2
	@echo "[ddr3] formal: DDR3 x8 SERDES BL8 lane adapter, depth=$(X8_SERDES_BURST_LANE_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(X8_SERDES_BURST_LANE_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/x8_burst_clock_bridge.proof: $(BUILD)/x8_burst_clock_bridge.smt2
	@echo "[ddr3] formal: DDR3 x8 burst clock bridge, depth=$(X8_BURST_CLOCK_BRIDGE_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(X8_BURST_CLOCK_BRIDGE_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/line_burst_phy.proof: $(BUILD)/line_burst_phy.smt2
	@echo "[ddr3] formal: DDR3 line-to-fast-burst PHY shell, depth=$(LINE_BURST_PHY_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(LINE_BURST_PHY_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/line_serdes_phy.proof: $(BUILD)/line_serdes_phy.smt2
	@echo "[ddr3] formal: DDR3 line-to-SERDES PHY shell, depth=$(LINE_SERDES_PHY_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(LINE_SERDES_PHY_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/line_lane_phy_write.proof: $(BUILD)/line_lane_phy_write.smt2
	@echo "[ddr3] formal: DDR3 line-to-lane PHY write bridge, depth=$(LINE_LANE_PHY_WRITE_SMTBMC_DEPTH), solver=$(LINE_LANE_PHY_SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(LINE_LANE_PHY_SOLVER) -t $(LINE_LANE_PHY_WRITE_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/line_lane_phy_read.proof: $(BUILD)/line_lane_phy_read.smt2
	@echo "[ddr3] formal: DDR3 line-to-lane PHY read bridge, depth=$(LINE_LANE_PHY_READ_SMTBMC_DEPTH), solver=$(LINE_LANE_PHY_SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(LINE_LANE_PHY_SOLVER) -t $(LINE_LANE_PHY_READ_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/line_phy_clock_bridge.proof: $(BUILD)/line_phy_clock_bridge.smt2
	@echo "[ddr3] formal: DDR3 controller-to-PHY line clock bridge protocol, depth=$(LINE_PHY_CLOCK_BRIDGE_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(LINE_PHY_CLOCK_BRIDGE_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/idelay_cal_cdc.proof: $(BUILD)/idelay_cal_cdc.smt2
	@echo "[ddr3] formal: DDR3 IDELAY calibration command CDC, depth=$(IDELAY_CAL_CDC_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(IDELAY_CAL_CDC_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/wb_frontend.proof: $(BUILD)/wb_frontend.smt2
	@echo "[ddr3] formal: DDR3 Wishbone-to-BL8 frontend, depth=$(SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/wb_channel.proof: $(BUILD)/wb_channel.smt2
	@echo "[ddr3] formal: DDR3 Wishbone-to-full-channel bridge, depth=$(WB_CHANNEL_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(WB_CHANNEL_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/wb_line_channel.proof: $(BUILD)/wb_line_channel.smt2
	@echo "[ddr3] formal: DDR3 line-level Wishbone-to-PHY bridge, depth=$(WB_CHANNEL_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(WB_CHANNEL_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/wb_line_channel_rmw.proof: $(BUILD)/wb_line_channel_rmw.smt2
	@echo "[ddr3] formal: DDR3 no-DM Wishbone line read-modify-write bridge, depth=$(WB_LINE_RMW_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(WB_LINE_RMW_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/wb_dual_channel.proof: $(BUILD)/wb_dual_channel.smt2
	@echo "[ddr3] formal: DDR3 dual-channel Wishbone dispatch, depth=$(WB_DUAL_CHANNEL_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(WB_DUAL_CHANNEL_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/wb_dual_channel_line.proof: $(BUILD)/wb_dual_channel_line.smt2
	@echo "[ddr3] formal: DDR3 line-level dual-channel Wishbone dispatch, depth=$(WB_DUAL_CHANNEL_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(WB_DUAL_CHANNEL_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/channel_sched.proof: $(BUILD)/channel_sched.smt2
	@echo "[ddr3] formal: DDR3 BL8 line scheduler adapter, depth=$(CHANNEL_SCHED_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(CHANNEL_SCHED_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/ctrl.proof: $(BUILD)/ctrl.smt2
	@echo "[ddr3] formal: DDR3 init-gated dual-channel controller shell, depth=$(CTRL_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(CTRL_SMTBMC_DEPTH) $<
	@touch $@

$(BUILD)/ctrl_line.proof: $(BUILD)/ctrl_line.smt2
	@echo "[ddr3] formal: DDR3 init-gated line-level controller shell, depth=$(CTRL_SMTBMC_DEPTH), solver=$(SOLVER)"
	$(YOSYS_SMTBMC) --presat -s $(SOLVER) -t $(CTRL_SMTBMC_DEPTH) $<
	@touch $@

sim: sim-addr-decode sim-byte-lane sim-channel-line sim-line-to-lanes sim-line-to-bursts sim-x8-to-x9-line-adapter sim-x8-lane-phy sim-x8-burst-io-sequencer sim-x8-serdes-burst-lane sim-x8-burst-clock-bridge sim-line-burst-phy sim-line-serdes-phy sim-line-lane-phy sim-line-phy-clock-bridge sim-idelay-cal-cdc sim-wb-frontend sim-wb-channel sim-wb-line-channel sim-wb-line-channel-rmw sim-wb-dual-channel sim-wb-dual-channel-line sim-channel-sched sim-ctrl sim-ctrl-line sim-micron-smoke sim-micron-init sim-micron-init-rtl sim-micron-single-read sim-micron-single-write-read sim-micron-x8-agent sim-micron-ctrl-dual-channel sim-micron-ctrl-line-dual-channel

cocotb:
	@echo "[ddr3] cocotb disabled until Wishbone/runtime controller RTL exists; run 'make sim' for Micron init coverage."

sim-micron-smoke: $(SIM_BUILD)/micron_model_smoke.vvp
	@echo "[ddr3] sim: Micron DDR3 model smoke"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data

sim-byte-lane: $(SIM_BUILD)/byte_lane.vvp
	@echo "[ddr3] sim: DDR3 x8 byte-lane packetizer"
	$(VVP) $<

sim-addr-decode: $(SIM_BUILD)/addr_decode.vvp
	@echo "[ddr3] sim: DDR3 full-capacity address decoder"
	$(VVP) $<

sim-channel-line: $(SIM_BUILD)/channel_line.vvp
	@echo "[ddr3] sim: DDR3 full-channel BL8 line packetizer"
	$(VVP) $<

sim-line-to-lanes: $(SIM_BUILD)/line_to_lanes.vvp
	@echo "[ddr3] sim: DDR3 line-to-x8-lane adapter"
	$(VVP) $<

sim-line-to-bursts: $(SIM_BUILD)/line_to_bursts.vvp
	@echo "[ddr3] sim: DDR3 line-to-x8-burst adapter"
	$(VVP) $<

sim-x8-to-x9-line-adapter: $(SIM_BUILD)/x8_to_x9_line_adapter.vvp
	@echo "[ddr3] sim: DDR3 x8-data to x9-physical line adapter"
	$(VVP) $<

sim-x8-lane-phy: $(SIM_BUILD)/x8_lane_phy.vvp
	@echo "[ddr3] sim: DDR3 x8 lane PHY timing core"
	$(VVP) $<

sim-x8-burst-io-sequencer: $(SIM_BUILD)/x8_burst_io_sequencer.vvp
	@echo "[ddr3] sim: DDR3 x8 fast burst I/O sequencer"
	$(VVP) $<

sim-x8-serdes-burst-lane: $(SIM_BUILD)/x8_serdes_burst_lane.vvp
	@echo "[ddr3] sim: DDR3 x8 SERDES BL8 lane adapter"
	$(VVP) $<

sim-x8-burst-clock-bridge: $(SIM_BUILD)/x8_burst_clock_bridge.vvp
	@echo "[ddr3] sim: DDR3 x8 burst clock bridge"
	$(VVP) $<

sim-line-burst-phy: $(SIM_BUILD)/line_burst_phy.vvp
	@echo "[ddr3] sim: DDR3 line-to-fast-burst PHY shell"
	$(VVP) $<

sim-line-serdes-phy: $(SIM_BUILD)/line_serdes_phy.vvp
	@echo "[ddr3] sim: DDR3 line-to-SERDES PHY shell"
	$(VVP) $<

sim-line-lane-phy: $(SIM_BUILD)/line_lane_phy.vvp
	@echo "[ddr3] sim: DDR3 line-to-lane PHY timing bridge"
	$(VVP) $<

sim-line-phy-clock-bridge: $(SIM_BUILD)/line_phy_clock_bridge.vvp
	@echo "[ddr3] sim: DDR3 controller-to-PHY clock bridge"
	$(VVP) $<

sim-idelay-cal-cdc: $(SIM_BUILD)/idelay_cal_cdc.vvp
	@echo "[ddr3] sim: DDR3 IDELAY calibration command CDC"
	$(VVP) $<

sim-wb-frontend: $(SIM_BUILD)/wb_frontend.vvp
	@echo "[ddr3] sim: DDR3 Wishbone-to-BL8 frontend"
	$(VVP) $<

sim-wb-channel: $(SIM_BUILD)/wb_channel.vvp
	@echo "[ddr3] sim: DDR3 Wishbone-to-full-channel bridge"
	$(VVP) $<

sim-wb-line-channel: $(SIM_BUILD)/wb_line_channel.vvp
	@echo "[ddr3] sim: DDR3 line-level Wishbone-to-PHY bridge"
	$(VVP) $<

sim-wb-line-channel-rmw: $(SIM_BUILD)/wb_line_channel_rmw.vvp
	@echo "[ddr3] sim: DDR3 no-DM Wishbone line read-modify-write bridge"
	$(VVP) $<

sim-wb-dual-channel: $(SIM_BUILD)/wb_dual_channel.vvp
	@echo "[ddr3] sim: DDR3 dual-channel Wishbone dispatch"
	$(VVP) $<

sim-wb-dual-channel-line: $(SIM_BUILD)/wb_dual_channel_line.vvp
	@echo "[ddr3] sim: DDR3 line-level dual-channel Wishbone dispatch"
	$(VVP) $<

sim-channel-sched: $(SIM_BUILD)/channel_sched.vvp
	@echo "[ddr3] sim: DDR3 BL8 line scheduler adapter"
	$(VVP) $<

sim-ctrl: $(SIM_BUILD)/ctrl.vvp
	@echo "[ddr3] sim: DDR3 init-gated dual-channel controller shell"
	$(VVP) $<

sim-ctrl-line: $(SIM_BUILD)/ctrl_line.vvp
	@echo "[ddr3] sim: DDR3 init-gated line-level controller shell"
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

sim-micron-x8-agent: $(SIM_BUILD)/micron_x8_phy_agent.vvp
	@echo "[ddr3] sim: reusable x8 DQS/DQ timing agent against Micron model"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data > $(SIM_BUILD)/micron_x8_phy_agent.log
	cat $(SIM_BUILD)/micron_x8_phy_agent.log
	@if grep -q "ERROR:" $(SIM_BUILD)/micron_x8_phy_agent.log; then \
		echo "Micron model reported timing/protocol errors"; \
		exit 1; \
	fi
	@if grep -q "WARNING:" $(SIM_BUILD)/micron_x8_phy_agent.log; then \
		echo "Micron model reported timing/protocol warnings"; \
		exit 1; \
	fi

sim-micron-ctrl-dual-channel: $(SIM_BUILD)/micron_ctrl_dual_channel.vvp
	@echo "[ddr3] sim: dual-channel controller through sixteen Micron x8 models"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data > $(SIM_BUILD)/micron_ctrl_dual_channel.log
	cat $(SIM_BUILD)/micron_ctrl_dual_channel.log
	@if grep -q "ERROR:" $(SIM_BUILD)/micron_ctrl_dual_channel.log; then \
		echo "Micron model reported timing/protocol errors"; \
		exit 1; \
	fi
	@if grep -q "WARNING:" $(SIM_BUILD)/micron_ctrl_dual_channel.log; then \
		echo "Micron model reported timing/protocol warnings"; \
		exit 1; \
	fi

sim-micron-ctrl-line-dual-channel: $(SIM_BUILD)/micron_ctrl_line_dual_channel.vvp
	@echo "[ddr3] sim: line-level dual-channel controller through sixteen Micron x8 models"
	mkdir -p $(SIM_BUILD)/micron_model_data
	$(VVP) $< +model_data+$(SIM_BUILD)/micron_model_data > $(SIM_BUILD)/micron_ctrl_line_dual_channel.log
	cat $(SIM_BUILD)/micron_ctrl_line_dual_channel.log
	@if grep -q "ERROR:" $(SIM_BUILD)/micron_ctrl_line_dual_channel.log; then \
		echo "Micron model reported timing/protocol errors"; \
		exit 1; \
	fi
	@if grep -q "WARNING:" $(SIM_BUILD)/micron_ctrl_line_dual_channel.log; then \
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

$(SIM_BUILD)/line_to_lanes.vvp: rtl/ddr3_line_to_lanes.sv sim/tb_line_to_lanes.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_line_to_lanes \
	  -o $@ rtl/ddr3_line_to_lanes.sv sim/tb_line_to_lanes.sv

$(SIM_BUILD)/line_to_bursts.vvp: rtl/ddr3_line_to_bursts.sv sim/tb_line_to_bursts.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_line_to_bursts \
	  -o $@ rtl/ddr3_line_to_bursts.sv sim/tb_line_to_bursts.sv

$(SIM_BUILD)/x8_to_x9_line_adapter.vvp: rtl/ddr3_x8_to_x9_line_adapter.sv sim/tb_x8_to_x9_line_adapter.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_x8_to_x9_line_adapter \
	  -o $@ rtl/ddr3_x8_to_x9_line_adapter.sv sim/tb_x8_to_x9_line_adapter.sv

$(SIM_BUILD)/x8_lane_phy.vvp: rtl/ddr3_x8_lane_phy.sv sim/tb_x8_lane_phy.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_x8_lane_phy \
	  -o $@ rtl/ddr3_x8_lane_phy.sv sim/tb_x8_lane_phy.sv

$(SIM_BUILD)/x8_burst_io_sequencer.vvp: rtl/ddr3_x8_burst_io_sequencer.sv sim/tb_x8_burst_io_sequencer.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_x8_burst_io_sequencer \
	  -o $@ rtl/ddr3_x8_burst_io_sequencer.sv sim/tb_x8_burst_io_sequencer.sv

$(SIM_BUILD)/x8_serdes_burst_lane.vvp: rtl/ddr3_x8_serdes_burst_lane.sv sim/tb_x8_serdes_burst_lane.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_x8_serdes_burst_lane \
	  -o $@ rtl/ddr3_x8_serdes_burst_lane.sv sim/tb_x8_serdes_burst_lane.sv

$(SIM_BUILD)/x8_burst_clock_bridge.vvp: rtl/ddr3_x8_burst_clock_bridge.sv sim/tb_x8_burst_clock_bridge.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_x8_burst_clock_bridge \
	  -o $@ rtl/ddr3_x8_burst_clock_bridge.sv sim/tb_x8_burst_clock_bridge.sv

$(SIM_BUILD)/line_burst_phy.vvp: rtl/ddr3_line_to_bursts.sv rtl/ddr3_x8_burst_clock_bridge.sv rtl/ddr3_x8_burst_io_sequencer.sv rtl/ddr3_line_burst_phy.sv sim/tb_line_burst_phy.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_line_burst_phy \
	  -o $@ rtl/ddr3_line_to_bursts.sv rtl/ddr3_x8_burst_clock_bridge.sv rtl/ddr3_x8_burst_io_sequencer.sv rtl/ddr3_line_burst_phy.sv sim/tb_line_burst_phy.sv

$(SIM_BUILD)/line_serdes_phy.vvp: rtl/ddr3_line_to_bursts.sv rtl/ddr3_x8_burst_clock_bridge.sv rtl/ddr3_x8_serdes_burst_lane.sv rtl/ddr3_line_serdes_phy.sv sim/tb_line_serdes_phy.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_line_serdes_phy \
	  -o $@ rtl/ddr3_line_to_bursts.sv rtl/ddr3_x8_burst_clock_bridge.sv rtl/ddr3_x8_serdes_burst_lane.sv rtl/ddr3_line_serdes_phy.sv sim/tb_line_serdes_phy.sv

$(SIM_BUILD)/line_lane_phy.vvp: rtl/ddr3_line_to_lanes.sv rtl/ddr3_x8_lane_phy.sv rtl/ddr3_line_lane_phy.sv sim/tb_line_lane_phy.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_line_lane_phy \
	  -o $@ rtl/ddr3_line_to_lanes.sv rtl/ddr3_x8_lane_phy.sv rtl/ddr3_line_lane_phy.sv sim/tb_line_lane_phy.sv

$(SIM_BUILD)/line_phy_clock_bridge.vvp: rtl/ddr3_line_phy_clock_bridge.sv sim/tb_line_phy_clock_bridge.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_line_phy_clock_bridge \
	  -o $@ rtl/ddr3_line_phy_clock_bridge.sv sim/tb_line_phy_clock_bridge.sv

$(SIM_BUILD)/idelay_cal_cdc.vvp: rtl/ddr3_idelay_cal_cdc.sv sim/tb_idelay_cal_cdc.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_idelay_cal_cdc \
	  -o $@ rtl/ddr3_idelay_cal_cdc.sv sim/tb_idelay_cal_cdc.sv

$(SIM_BUILD)/addr_decode.vvp: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv sim/tb_addr_decode.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_addr_decode \
	  -o $@ rtl/ddr3_addr_decode.sv sim/tb_addr_decode.sv

$(SIM_BUILD)/wb_frontend.vvp: rtl/ddr3_wb_frontend.sv sim/tb_wb_frontend.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_wb_frontend \
	  -o $@ rtl/ddr3_wb_frontend.sv sim/tb_wb_frontend.sv

$(SIM_BUILD)/wb_channel.vvp: rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv sim/tb_wb_channel.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_wb_channel \
	  -o $@ rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv sim/tb_wb_channel.sv

$(SIM_BUILD)/wb_line_channel.vvp: rtl/ddr3_wb_line_channel.sv sim/tb_wb_line_channel.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_wb_line_channel \
	  -o $@ rtl/ddr3_wb_line_channel.sv sim/tb_wb_line_channel.sv

$(SIM_BUILD)/wb_line_channel_rmw.vvp: rtl/ddr3_wb_line_channel.sv sim/tb_wb_line_channel_rmw.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_wb_line_channel_rmw \
	  -o $@ rtl/ddr3_wb_line_channel.sv sim/tb_wb_line_channel_rmw.sv

$(SIM_BUILD)/wb_dual_channel.vvp: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv sim/tb_wb_dual_channel.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_wb_dual_channel \
	  -o $@ rtl/ddr3_addr_decode.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv sim/tb_wb_dual_channel.sv

$(SIM_BUILD)/wb_dual_channel_line.vvp: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv sim/tb_wb_dual_channel_line.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_wb_dual_channel_line \
	  -o $@ rtl/ddr3_addr_decode.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv sim/tb_wb_dual_channel_line.sv

$(SIM_BUILD)/channel_sched.vvp: rtl/ddr3_params.vh rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv sim/tb_channel_sched.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_channel_sched \
	  -o $@ rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv sim/tb_channel_sched.sv

$(SIM_BUILD)/ctrl.vvp: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv rtl/ddr3_ctrl.sv sim/tb_ctrl.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_ctrl \
	  -o $@ rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv rtl/ddr3_ctrl.sv sim/tb_ctrl.sv

$(SIM_BUILD)/ctrl_line.vvp: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv rtl/ddr3_ctrl_line.sv sim/tb_ctrl_line.sv | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl \
	  -s tb_ctrl_line \
	  -o $@ rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv rtl/ddr3_ctrl_line.sv sim/tb_ctrl_line.sv

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

$(SIM_BUILD)/micron_x8_phy_agent.vvp: rtl/ddr3_params.vh rtl/ddr3_init_seq.sv rtl/ddr3_byte_lane.sv sim/ddr3_x8_phy_agent.sv sim/tb_micron_x8_phy_agent.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_x8_phy_agent \
	  -o $@ rtl/ddr3_init_seq.sv rtl/ddr3_byte_lane.sv sim/ddr3_x8_phy_agent.sv sim/tb_micron_x8_phy_agent.sv sim/vendor/ddr3.v

$(SIM_BUILD)/micron_ctrl_dual_channel.vvp: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv rtl/ddr3_ctrl.sv sim/ddr3_x8_phy_agent.sv sim/tb_micron_ctrl_dual_channel.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_ctrl_dual_channel \
	  -o $@ rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_byte_lane.sv rtl/ddr3_channel_line.sv rtl/ddr3_wb_channel.sv rtl/ddr3_wb_dual_channel.sv rtl/ddr3_ctrl.sv sim/ddr3_x8_phy_agent.sv sim/tb_micron_ctrl_dual_channel.sv sim/vendor/ddr3.v

$(SIM_BUILD)/micron_ctrl_line_dual_channel.vvp: rtl/ddr3_params.vh rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv rtl/ddr3_ctrl_line.sv rtl/ddr3_line_to_lanes.sv sim/ddr3_x8_phy_agent.sv sim/tb_micron_ctrl_line_dual_channel.sv sim/vendor/ddr3.v sim/vendor/ddr3/2048Mb_ddr3_parameters.vh | $(SIM_BUILD)
	$(IVERILOG) -g2012 -I rtl -I sim/vendor \
	  -Dden2048Mb -Dsg125 -Dx8 \
	  -s tb_micron_ctrl_line_dual_channel \
	  -o $@ rtl/ddr3_addr_decode.sv rtl/ddr3_init_seq.sv rtl/ddr3_refresh.sv rtl/ddr3_bank.sv rtl/ddr3_scheduler.sv rtl/ddr3_channel_sched.sv rtl/ddr3_wb_line_channel.sv rtl/ddr3_wb_dual_channel_line.sv rtl/ddr3_ctrl_line.sv rtl/ddr3_line_to_lanes.sv sim/ddr3_x8_phy_agent.sv sim/tb_micron_ctrl_line_dual_channel.sv sim/vendor/ddr3.v

clean:
	rm -rf $(BUILD) $(SIM_BUILD) sim/sim_build sim/sim_build_* sim/build_micron
	rm -rf sim/__pycache__
	rm -f sim/results.xml sim/results_*.xml ddr3_init.vcd ddr3_init_micron.vcd

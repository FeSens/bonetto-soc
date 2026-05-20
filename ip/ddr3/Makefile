.PHONY: formal formal-cal-seq sim sim-init sim-runtime-addr sim-micron synth-phy-dq-ratio8 cocotb clean

BUILD := formal/build

# The previous DDR3 RTL was intentionally removed. Keep these targets as stable
# placeholders so aggregate repo checks do not pretend an obsolete controller is
# still the active implementation.

formal: formal-cal-seq
	@echo "[ddr3] RTL reset: controller/PHY proofs are retained as harnesses only"

formal-cal-seq:
	@echo "[ddr3] skipped: cal_seq RTL is reset; formal/cal_seq remains as the next implementation harness"

sim sim-init sim-runtime-addr sim-micron synth-phy-dq-ratio8 cocotb:
	@echo "[ddr3] skipped: RTL is reset; rebuild the controller before running DDR3 simulation/synthesis"

clean:
	rm -rf $(BUILD) sim/build ddr3_init.vcd

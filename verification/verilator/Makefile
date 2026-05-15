# Verilator testbench for the iter-1 SoC integration.
# Runs the same memtest_lite + wb_memory combo that the board top
# instantiates and checks LED outputs for pass / fail.
#
# Uses the Verilator binary from PATH — Felipe's oss-cad-suite or any
# brew-installed verilator works. Not in the Nix devShell because the
# pinned nixpkgs revision blocks verilator on aarch64-darwin via the
# gnat-bootstrap closure.

TOP := top
RTL := \
    ../../boards/ypcb-00338/rtl/top.v \
    ../../boards/ypcb-00338/rtl/memtest_lite.v \
    ../../ip/wb-memory/rtl/wb_memory.v

VERILATOR_FLAGS := \
    --cc --trace --build --exe -j 0 \
    --top-module $(TOP) \
    -Wno-WIDTHEXPAND -Wno-WIDTHTRUNC -Wno-UNUSEDSIGNAL

SIM_BIN := obj_dir/V$(TOP)

.PHONY: sim clean

sim: $(SIM_BIN)
	@./$(SIM_BIN)

$(SIM_BIN): tb_memtest.cpp $(RTL)
	verilator $(VERILATOR_FLAGS) $(RTL) tb_memtest.cpp

clean:
	rm -rf obj_dir memtest.vcd

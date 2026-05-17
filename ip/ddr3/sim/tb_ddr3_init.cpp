// tb_ddr3_init.cpp — Verilator testbench for the DDR3 init sequence.
//
// Instantiates the ddr3_ctrl (which contains ddr3_init) and runs it for
// enough sim cycles to traverse the full JEDEC init sequence. The
// pass criteria:
//   1. init_done asserts within MAX_INIT_CYCLES.
//   2. init_error stays low throughout.
//   3. (when wired to Micron model) no JEDEC protocol violations printed.
//
// For the initial harness we drive ddr3_ctrl alone and watch init_done /
// init_state. Once that's solid, the Micron model is added as a sim peer
// in a follow-up turn (the model uses SystemVerilog time / fork-join that
// Verilator without --timing chokes on; Icarus is the easier first peer).

#include "Vddr3_ctrl.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>

// MT41K256M8DA-125 -125 init takes ≈ 200 µs + 500 µs + tXPR + 4·tMRD +
// tMOD + tZQinit + tDLLK + tRP + tRFC. Worst-case ≈ 1 ms.
// With our 1.25 ns tCK (800 MHz DDR clock), that's 800 000 cycles.
// We give a 2× safety margin for the test.
static constexpr uint64_t MAX_INIT_CYCLES = 2'000'000;

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    const bool trace = std::getenv("TRACE") != nullptr;
    auto *dut = new Vddr3_ctrl;
    VerilatedVcdC *tfp = nullptr;
    if (trace) {
        Verilated::traceEverOn(true);
        tfp = new VerilatedVcdC;
        dut->trace(tfp, 99);
        tfp->open("ddr3_init.vcd");
    }

    // Drive the inputs.
    dut->i_clk     = 0;
    dut->i_clk_phy = 0;
    dut->i_rst     = 1;
    dut->i_wb_cyc  = 0;
    dut->i_wb_stb  = 0;
    dut->i_wb_we   = 0;
    dut->i_wb_adr  = 0;
    dut->i_wb_dat  = 0;
    dut->i_wb_sel  = 0;
    for (int i = 0; i < 9; i++) dut->i_phy_rd_data[i] = 0;
    dut->i_phy_rd_valid = 1;

    uint64_t cycle = 0;
    auto tick = [&]() {
        // Both clocks rise together for this skeleton; iter-3 separates them.
        dut->i_clk     = 1;
        dut->i_clk_phy = 1;
        dut->eval();
        if (tfp) tfp->dump(cycle * 2);
        dut->i_clk     = 0;
        dut->i_clk_phy = 0;
        dut->eval();
        if (tfp) tfp->dump(cycle * 2 + 1);
        cycle++;
    };

    // Hold reset for 10 cycles.
    for (int i = 0; i < 10; i++) tick();
    dut->i_rst = 0;

    uint8_t  last_state    = 255;
    bool     init_done_seen = false;
    bool     init_err_seen  = false;

    for (; cycle < MAX_INIT_CYCLES && !Verilated::gotFinish(); ) {
        tick();
        uint8_t cur_state = dut->o_init_state & 0x1F;
        if (cur_state != last_state) {
            std::cout << "cycle " << cycle << "  state=" << (int)cur_state << std::endl;
            last_state = cur_state;
        }
        if (dut->o_init_done && !init_done_seen) {
            init_done_seen = true;
            std::cout << "init_done at cycle " << cycle << std::endl;
            break;
        }
        if (dut->o_init_error && !init_err_seen) {
            init_err_seen = true;
            std::cout << "init_error at cycle " << cycle
                      << ", code=" << (int)dut->o_init_error_code << std::endl;
            break;
        }
    }

    if (tfp) { tfp->close(); delete tfp; }
    delete dut;

    if (init_err_seen) {
        std::cout << "FAIL: ddr3_init asserted init_error" << std::endl;
        return 1;
    }
    if (!init_done_seen) {
        std::cout << "FAIL: ddr3_init did not assert init_done within "
                  << MAX_INIT_CYCLES << " cycles" << std::endl;
        return 1;
    }
    std::cout << "PASS: init_done at cycle " << cycle
              << " / " << MAX_INIT_CYCLES << std::endl;
    return 0;
}

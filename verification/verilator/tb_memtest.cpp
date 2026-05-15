// tb_memtest.cpp — Verilator testbench for the iter-1 SoC top.
//
// Instantiates `top.v` (memtest_lite + wb_memory) and clocks it. Reads
// LED bits each cycle:
//   led[0] = last_ok
//   led[1] = heartbeat
//   led[2] = sticky_error
//
// Pass criteria:
//   - sticky_error never asserts.
//   - last_ok is high for at least MIN_OK_HIGH_CYCLES cycles (proves the
//     FSM made progress; last_ok stays high while tests keep passing).
//
// Exit code 0 on PASS, 1 on FAIL.

#include "Vtop.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

static constexpr uint64_t SIM_CYCLES = 200000;        // ~4 ms at 50 MHz
static constexpr uint64_t MIN_OK_HIGH_CYCLES = 10000; // last_ok must be high
                                                      // for >= this many cycles

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    const bool trace = std::getenv("TRACE") != nullptr;
    Vtop *top = new Vtop;
    VerilatedVcdC *tfp = nullptr;
    if (trace) {
        Verilated::traceEverOn(true);
        tfp = new VerilatedVcdC;
        top->trace(tfp, 99);
        tfp->open("memtest.vcd");
    }

    uint64_t cycles = 0;
    uint64_t ok_high_cycles = 0;
    bool any_err_observed = false;
    uint64_t first_err_cycle = 0;

    top->clk_50 = 0;

    while (cycles < SIM_CYCLES * 2 && !Verilated::gotFinish()) {
        top->clk_50 = !top->clk_50;
        top->eval();
        if (tfp) tfp->dump(cycles);

        if (top->clk_50) {                           // rising edge only
            const uint8_t led = top->led & 0x7;
            const bool last_ok  = (led >> 0) & 1;
            const bool sticky_e = (led >> 2) & 1;

            if (last_ok) ok_high_cycles++;

            if (sticky_e && !any_err_observed) {
                any_err_observed = true;
                first_err_cycle  = cycles / 2;
            }
        }
        cycles++;
    }

    if (tfp) { tfp->close(); delete tfp; }
    delete top;

    const uint64_t sim_cycles = cycles / 2;
    std::cout << "tb_memtest: sim_cycles=" << sim_cycles
              << " last_ok_high_for=" << ok_high_cycles
              << " sticky_err=" << (any_err_observed ? "1" : "0");
    if (any_err_observed)
        std::cout << " first_err_at_cycle=" << first_err_cycle;
    std::cout << std::endl;

    if (any_err_observed) {
        std::cout << "FAIL: memtest_lite reported a mismatch — wb_memory bug" << std::endl;
        return 1;
    }
    if (ok_high_cycles < MIN_OK_HIGH_CYCLES) {
        std::cout << "FAIL: last_ok was only high for " << ok_high_cycles
                  << " cycles (need >= " << MIN_OK_HIGH_CYCLES
                  << "). FSM may be stuck." << std::endl;
        return 1;
    }
    std::cout << "PASS: last_ok high for "
              << ok_high_cycles << "/" << sim_cycles
              << " cycles (" << (100 * ok_high_cycles / sim_cycles)
              << "%), no errors." << std::endl;
    return 0;
}

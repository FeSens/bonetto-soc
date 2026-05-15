// tb_ddr3_init_micron.cpp — C++ harness for the SystemVerilog top tb
// `tb_ddr3_init_top` instantiating ddr3_ctrl + Micron MT41K model.
//
// Clock generation, reset, and stop condition live INSIDE the SV top
// (Verilator --timing handles the #delays). The C++ side just runs
// the simulation until $finish.

#include "Vtb_ddr3_init_top.h"
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    const bool trace = std::getenv("TRACE") != nullptr;
    auto *top = new Vtb_ddr3_init_top;
    VerilatedVcdC *tfp = nullptr;
    if (trace) {
        Verilated::traceEverOn(true);
        tfp = new VerilatedVcdC;
        top->trace(tfp, 99);
        tfp->open("ddr3_init_micron.vcd");
    }

    // With --timing, simulation drives itself. We just call eval()
    // until $finish stops it (the SV top has $finish inside its
    // initial blocks).
    while (!Verilated::gotFinish()) {
        top->eval();
    }

    if (tfp) { tfp->close(); delete tfp; }
    delete top;

    std::cout << "[harness] sim exited via $finish" << std::endl;
    return 0;
}

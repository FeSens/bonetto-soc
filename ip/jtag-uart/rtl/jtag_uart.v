// jtag_uart — BSCANE2-based UART, exposed as a Wishbone B4 pipelined slave.
//
// ITERATION 1 STUB. The full implementation lands in iteration 2.
// This file is here so:
//   1. The top-level board file has something to instantiate during scaffolding.
//   2. INVARIANTS #4 / #5 are satisfied (every IP has a top module + a passing
//      formal/sim, even if trivial).
//
// The stub satisfies the Wishbone slave contract — registers fire ack one cycle
// after stb, never stalls, returns 0 on reads. It will be replaced with the real
// BSCANE2 + FIFO implementation behind exactly this port set.

`default_nettype none

module jtag_uart #(
    parameter integer WB_DATA_W = 32,
    parameter integer WB_ADDR_W = 2
) (
    input  wire                     i_clk,
    input  wire                     i_rst,

    input  wire                     i_wb_cyc,
    input  wire                     i_wb_stb,
    input  wire                     i_wb_we,
    input  wire [WB_ADDR_W-1:0]     i_wb_adr,
    input  wire [WB_DATA_W-1:0]     i_wb_dat,
    input  wire [WB_DATA_W/8-1:0]   i_wb_sel,
    output wire                     o_wb_stall,
    output reg                      o_wb_ack,
    output wire [WB_DATA_W-1:0]     o_wb_dat,
    output wire                     o_wb_err
);
    assign o_wb_stall = 1'b0;
    assign o_wb_err   = 1'b0;
    assign o_wb_dat   = {WB_DATA_W{1'b0}};

    wire accept = i_wb_cyc && i_wb_stb && !o_wb_stall;

    always @(posedge i_clk) begin
        if (i_rst)          o_wb_ack <= 1'b0;
        else if (!i_wb_cyc) o_wb_ack <= 1'b0;
        else                o_wb_ack <= accept;
    end

    // Hush "unused" warnings for the stub.
    /* verilator lint_off UNUSED */
    wire _unused = &{1'b0, i_wb_we, i_wb_adr, i_wb_dat, i_wb_sel, 1'b0};
    /* verilator lint_on UNUSED */
endmodule

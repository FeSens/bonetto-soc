// ddr3_ctrl — parameterised DDR3 controller.
//
// ITERATION 1 STUB. Satisfies the Wishbone B4 pipelined slave contract
// so the board top-level can drop it in next to wb_memory and route the
// real DDR3 pins out of the FPGA — but the controller is internally a
// no-op (acks every transaction with zero, never touches the pins).
//
// The real PHY + state machine arrive in iteration 2. The Wishbone port
// set is locked here per INVARIANTS #4 so future swap-in is one-file.

`default_nettype none

module ddr3_ctrl #(
    parameter integer WB_DATA_W   = 32,
    parameter integer WB_ADDR_W   = 28,
    parameter         DDR3_PART   = "MT41K256M8DA-125",
    parameter integer SPEED_GRADE = 1600
) (
    input  wire                     i_clk,
    input  wire                     i_rst,

    // Wishbone B4 pipelined slave
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

    // DDR3-side pins arrive in iter 2 — for now the YPCB-00338 top file
    // ties them to weak pulls so nothing on the PCB floats.
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

    /* verilator lint_off UNUSED */
    wire _unused = &{1'b0, i_wb_we, i_wb_adr, i_wb_dat, i_wb_sel,
                     DDR3_PART[0], SPEED_GRADE[0], 1'b0};
    /* verilator lint_on UNUSED */
endmodule

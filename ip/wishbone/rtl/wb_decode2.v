// wb_decode2 — 1-master, 2-slave Wishbone B4 pipelined address decoder.
//
// Routes a single master to one of two slaves based on a parameterised
// address bit. Strictly combinational — no buffering, no arbitration
// (single master, no contention). One-cycle slave-side latency is
// preserved.
//
// Selection rule:
//   adr[SEL_BIT] == 0  →  slave 0
//   adr[SEL_BIT] == 1  →  slave 1
//
// Use cases:
//   * Map a memtest_lite-style master to BRAM (slave 0) and jtag_uart
//     (slave 1), so the on-board test reports results to the host over
//     JTAG-UART.
//   * Build larger fabrics by chaining wb_decode2 nodes.

`default_nettype none

module wb_decode2 #(
    parameter integer WB_DATA_W = 32,
    parameter integer WB_ADDR_W = 30,
    parameter integer SEL_BIT   = 14         // bit of i_wb_adr that picks slave
) (
    input  wire                     i_clk,
    input  wire                     i_rst,

    // ----- Master facing the decoder -----
    input  wire                     i_wb_cyc,
    input  wire                     i_wb_stb,
    input  wire                     i_wb_we,
    input  wire [WB_ADDR_W-1:0]     i_wb_adr,
    input  wire [WB_DATA_W-1:0]     i_wb_dat,
    input  wire [WB_DATA_W/8-1:0]   i_wb_sel,
    output wire                     o_wb_stall,
    output wire                     o_wb_ack,
    output wire [WB_DATA_W-1:0]     o_wb_dat,
    output wire                     o_wb_err,

    // ----- Slave 0 -----
    output wire                     o_s0_cyc,
    output wire                     o_s0_stb,
    output wire                     o_s0_we,
    output wire [WB_ADDR_W-1:0]     o_s0_adr,
    output wire [WB_DATA_W-1:0]     o_s0_dat,
    output wire [WB_DATA_W/8-1:0]   o_s0_sel,
    input  wire                     i_s0_stall,
    input  wire                     i_s0_ack,
    input  wire [WB_DATA_W-1:0]     i_s0_dat,
    input  wire                     i_s0_err,

    // ----- Slave 1 -----
    output wire                     o_s1_cyc,
    output wire                     o_s1_stb,
    output wire                     o_s1_we,
    output wire [WB_ADDR_W-1:0]     o_s1_adr,
    output wire [WB_DATA_W-1:0]     o_s1_dat,
    output wire [WB_DATA_W/8-1:0]   o_s1_sel,
    input  wire                     i_s1_stall,
    input  wire                     i_s1_ack,
    input  wire [WB_DATA_W-1:0]     i_s1_dat,
    input  wire                     i_s1_err
);
    // -------- Select the active slave from the address --------
    wire sel = i_wb_adr[SEL_BIT];

    // -------- Pending-xact tracker so ack/dat mux back to master correctly --
    // For B4 pipelined we need to know which slave the master is currently
    // waiting on. Track the last-issued slave; mux ack/dat from that one.
    reg sel_q;
    always @(posedge i_clk) begin
        if (i_rst)
            sel_q <= 1'b0;
        else if (i_wb_cyc && i_wb_stb && !o_wb_stall)
            sel_q <= sel;
    end

    // -------- Master → slaves (combinational) --------
    // CYC is shared; STB gates by selection. Address/data forwarded as-is.
    assign o_s0_cyc = i_wb_cyc;
    assign o_s0_stb = i_wb_stb && (sel == 1'b0);
    assign o_s0_we  = i_wb_we;
    assign o_s0_adr = i_wb_adr;
    assign o_s0_dat = i_wb_dat;
    assign o_s0_sel = i_wb_sel;

    assign o_s1_cyc = i_wb_cyc;
    assign o_s1_stb = i_wb_stb && (sel == 1'b1);
    assign o_s1_we  = i_wb_we;
    assign o_s1_adr = i_wb_adr;
    assign o_s1_dat = i_wb_dat;
    assign o_s1_sel = i_wb_sel;

    // -------- Slaves → master (mux on current selection for stall,
    //                          on last-issued for ack/dat) ----------
    assign o_wb_stall = (sel == 1'b0) ? i_s0_stall : i_s1_stall;
    assign o_wb_ack   = (sel_q == 1'b0) ? i_s0_ack   : i_s1_ack;
    assign o_wb_dat   = (sel_q == 1'b0) ? i_s0_dat   : i_s1_dat;
    assign o_wb_err   = (sel_q == 1'b0) ? i_s0_err   : i_s1_err;
endmodule

// wb_memory — BRAM-backed Wishbone B4 pipelined slave.
//
// Iteration 1: stand-in for the DDR3 controller. Exposes the exact same
// port set ddr3_ctrl will expose, so the SoC top-level wires-in a single
// `memory` slave today and swaps the implementation behind it tomorrow.
//
// Latency: 1 cycle (registered BRAM read).
// Stalls:  never (single-port BRAM accepts one xact per cycle).
// Width:   parameterised by WB_DATA_W and WB_ADDR_W (word-addressed).
//
// Per INVARIANTS #1 #2: pipelined B4, formal-checked against fwb_slave.v.

`default_nettype none

module wb_memory #(
    parameter integer WB_DATA_W = 32,
    parameter integer WB_ADDR_W = 14,            // 1<<WB_ADDR_W = depth in words
    parameter         INIT_FILE = ""             // optional $readmemh init
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
    output reg  [WB_DATA_W-1:0]     o_wb_dat,
    output wire                     o_wb_err
);
    localparam integer DEPTH = 1 << WB_ADDR_W;

    reg [WB_DATA_W-1:0] mem [0:DEPTH-1];

    // Single-port BRAM never stalls; never errs.
    assign o_wb_stall = 1'b0;
    assign o_wb_err   = 1'b0;

    wire accept = i_wb_cyc && i_wb_stb && !o_wb_stall;

    initial begin
        o_wb_ack = 1'b0;
        o_wb_dat = {WB_DATA_W{1'b0}};
    end

    // Byte-enabled write path: one always block per byte lane → infers BRAM.
    genvar gi;
    generate
        for (gi = 0; gi < WB_DATA_W/8; gi = gi + 1) begin : g_byte_wr
            always @(posedge i_clk) begin
                if (accept && i_wb_we && i_wb_sel[gi])
                    mem[i_wb_adr][gi*8 +: 8] <= i_wb_dat[gi*8 +: 8];
            end
        end
    endgenerate

    // Registered read.
    always @(posedge i_clk) begin
        if (accept && !i_wb_we)
            o_wb_dat <= mem[i_wb_adr];
    end

    // ACK fires one cycle after a successful accept. Drops to 0 when CYC
    // drops (per fwb_slave's F_OPT_DISCONTINUOUS handling).
    always @(posedge i_clk) begin
        if (i_rst)
            o_wb_ack <= 1'b0;
        else if (!i_wb_cyc)
            o_wb_ack <= 1'b0;
        else
            o_wb_ack <= accept;
    end

    // Optional init at simulation time (synthesisers usually ignore).
    initial begin
        if (INIT_FILE != "") $readmemh(INIT_FILE, mem);
    end
endmodule

// Single-channel Wishbone-to-DDR3 BL8 data bridge.
//
// This block is the first integration point between the bus-facing frontend and
// the full 64-bit-channel data packetizer. It accepts one 32-bit Wishbone word
// request at a time, emits one aligned BL8 line command for the future
// scheduler, and starts the eight-lane data packetizer on that same command
// acceptance.

`default_nettype none

module ddr3_wb_channel #(
    parameter integer WB_ADDR_W = 8,
    parameter integer LANES     = 8,
    parameter integer WB_DATA_W = 32,
    localparam integer LINE_BYTES    = LANES * 8,
    localparam integer LINE_DATA_W   = LINE_BYTES * 8,
    localparam integer LINE_MASK_W   = LINE_BYTES,
    localparam integer WORDS_PER_LINE = LINE_BYTES / (WB_DATA_W / 8),
    localparam integer WORD_INDEX_W  = (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE),
    localparam integer LINE_ADDR_W   = WB_ADDR_W - WORD_INDEX_W
) (
    input wire                     i_clk,
    input wire                     i_rst,

    input wire                     i_wb_cyc,
    input wire                     i_wb_stb,
    input wire                     i_wb_we,
    input wire [WB_ADDR_W-1:0]     i_wb_adr,
    input wire [WB_DATA_W-1:0]     i_wb_dat,
    input wire [(WB_DATA_W/8)-1:0] i_wb_sel,
    output wire                    o_wb_stall,
    output wire                    o_wb_ack,
    output wire [WB_DATA_W-1:0]    o_wb_dat,
    output wire                    o_wb_err,

    output wire                    o_cmd_valid,
    input wire                     i_cmd_ready,
    output wire                    o_cmd_write,
    output wire [LINE_ADDR_W-1:0]  o_cmd_line_addr,

    output wire                    o_busy,
    output wire                    o_line_done,
    output wire                    o_line_rd_valid,

    output wire [LANES-1:0]        o_phy_wr_valid,
    input wire [LANES-1:0]         i_phy_wr_ready,
    output wire [(LANES*8)-1:0]    o_phy_wr_data,
    output wire [LANES-1:0]        o_phy_wr_mask,
    output wire [LANES-1:0]        o_phy_wr_last,

    output wire [LANES-1:0]        o_phy_rd_ready,
    input wire [LANES-1:0]         i_phy_rd_valid,
    input wire [(LANES*8)-1:0]     i_phy_rd_data
);
    wire                    frontend_stall;
    wire                    req_valid;
    wire                    req_ready;
    wire                    req_write;
    wire [LINE_ADDR_W-1:0]  req_line_addr;
    wire [WORD_INDEX_W-1:0] req_word_index_unused;
    wire [LINE_DATA_W-1:0]  req_wr_data;
    wire [LINE_MASK_W-1:0]  req_wr_mask;

    wire                    line_ready;
    wire                    line_busy;
    wire [LINE_DATA_W-1:0]  line_rd_data;

    wire wb_line_block = !line_ready;
    wire frontend_stb = i_wb_stb && !wb_line_block;
    wire line_start = req_valid && req_ready;

    assign req_ready = line_ready && i_cmd_ready;

    assign o_wb_stall = frontend_stall || wb_line_block;
    assign o_cmd_valid = req_valid && line_ready;
    assign o_cmd_write = req_write;
    assign o_cmd_line_addr = req_line_addr;
    assign o_busy = line_busy || req_valid;

    ddr3_wb_frontend #(
        .WB_ADDR_W(WB_ADDR_W),
        .LINE_BYTES(LINE_BYTES),
        .WB_DATA_W(WB_DATA_W)
    ) u_frontend (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_wb_cyc(i_wb_cyc),
        .i_wb_stb(frontend_stb),
        .i_wb_we(i_wb_we),
        .i_wb_adr(i_wb_adr),
        .i_wb_dat(i_wb_dat),
        .i_wb_sel(i_wb_sel),
        .o_wb_stall(frontend_stall),
        .o_wb_ack(o_wb_ack),
        .o_wb_dat(o_wb_dat),
        .o_wb_err(o_wb_err),
        .o_req_valid(req_valid),
        .i_req_ready(req_ready),
        .o_req_write(req_write),
        .o_req_line_addr(req_line_addr),
        .o_req_word_index(req_word_index_unused),
        .o_req_wr_data(req_wr_data),
        .o_req_wr_mask(req_wr_mask),
        .i_rsp_valid(o_line_rd_valid),
        .i_rsp_data(line_rd_data),
        .i_rsp_err(1'b0)
    );

    ddr3_channel_line #(
        .LANES(LANES)
    ) u_line (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_start(line_start),
        .o_ready(line_ready),
        .i_write(req_write),
        .i_wr_data(req_wr_data),
        .i_wr_mask(req_wr_mask),
        .o_busy(line_busy),
        .o_done(o_line_done),
        .o_rd_valid(o_line_rd_valid),
        .o_rd_data(line_rd_data),
        .o_phy_wr_valid(o_phy_wr_valid),
        .i_phy_wr_ready(i_phy_wr_ready),
        .o_phy_wr_data(o_phy_wr_data),
        .o_phy_wr_mask(o_phy_wr_mask),
        .o_phy_wr_last(o_phy_wr_last),
        .o_phy_rd_ready(o_phy_rd_ready),
        .i_phy_rd_valid(i_phy_rd_valid),
        .i_phy_rd_data(i_phy_rd_data)
    );
endmodule

`default_nettype wire

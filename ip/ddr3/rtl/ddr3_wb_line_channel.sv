// Wishbone-to-DDR3 line bridge with a line-level PHY contract.
//
// A real DDR3 PHY cannot accept one byte per slow controller cycle after the
// WR command has already issued. This bridge keeps the bus and scheduler
// contract single-outstanding, but presents the whole BL8 channel line to the
// PHY at command-accept time. The PHY can then serialize the line in the DDR
// clock domain when the scheduler later reaches the WR data window.

`default_nettype none

module ddr3_wb_line_channel #(
    parameter integer WB_ADDR_W  = 8,
    parameter integer LANES      = 8,
    parameter integer WB_DATA_W  = 32,
    localparam integer LINE_BYTES     = LANES * 8,
    localparam integer LINE_DATA_W    = LINE_BYTES * 8,
    localparam integer WORDS_PER_LINE = LINE_BYTES / (WB_DATA_W / 8),
    localparam integer WORD_INDEX_W   =
        (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE),
    localparam integer LINE_ADDR_W    = WB_ADDR_W - WORD_INDEX_W
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
    output reg                     o_wb_ack,
    output reg [WB_DATA_W-1:0]     o_wb_dat,
    output reg                     o_wb_err,

    output wire                    o_cmd_valid,
    input wire                     i_cmd_ready,
    output wire                    o_cmd_write,
    output wire [LINE_ADDR_W-1:0]  o_cmd_line_addr,
    input wire                     i_xfer_start,

    output wire                    o_phy_wr_line_valid,
    input wire                     i_phy_wr_line_ready,
    output wire [LINE_DATA_W-1:0]  o_phy_wr_line_data,
    output wire [LINE_BYTES-1:0]   o_phy_wr_line_mask,

    output wire                    o_phy_rd_line_ready,
    input wire                     i_phy_rd_line_valid,
    input wire [LINE_DATA_W-1:0]   i_phy_rd_line_data,
    input wire                     i_phy_rd_line_err
);
    localparam integer WB_BYTES = WB_DATA_W / 8;

    localparam [1:0]
        ST_IDLE         = 2'd0,
        ST_CMD          = 2'd1,
        ST_WAIT_RD_XFER = 2'd2,
        ST_WAIT_RD_DATA = 2'd3;

    reg [1:0] state;
    reg req_write;
    reg [LINE_ADDR_W-1:0] req_line_addr;
    reg [WORD_INDEX_W-1:0] req_word_index;
    reg [LINE_DATA_W-1:0] req_wr_data;
    reg [LINE_BYTES-1:0] req_wr_mask;

    wire wb_accept = i_wb_cyc && i_wb_stb && !o_wb_stall;
    wire cmd_can_issue = !req_write || i_phy_wr_line_ready;
    wire cmd_accept = o_cmd_valid && i_cmd_ready;

    assign o_wb_stall = (state != ST_IDLE);
    assign o_cmd_valid = (state == ST_CMD) && cmd_can_issue;
    assign o_cmd_write = req_write;
    assign o_cmd_line_addr = req_line_addr;

    assign o_phy_wr_line_valid = cmd_accept && req_write;
    assign o_phy_wr_line_data = req_wr_data;
    assign o_phy_wr_line_mask = req_wr_mask;

    assign o_phy_rd_line_ready = (state == ST_WAIT_RD_DATA) && i_wb_cyc;

    function [LINE_DATA_W-1:0] place_word_data;
        input [WB_DATA_W-1:0] data;
        input [WORD_INDEX_W-1:0] word_index;
        integer i;
        begin
            place_word_data = {LINE_DATA_W{1'b0}};
            for (i = 0; i < WB_BYTES; i = i + 1)
                place_word_data[(word_index * WB_DATA_W) + (i * 8) +: 8] =
                    data[(i * 8) +: 8];
        end
    endfunction

    function [LINE_BYTES-1:0] place_word_mask;
        input [(WB_DATA_W/8)-1:0] sel;
        input [WORD_INDEX_W-1:0] word_index;
        integer i;
        begin
            place_word_mask = {LINE_BYTES{1'b1}};
            for (i = 0; i < WB_BYTES; i = i + 1)
                place_word_mask[(word_index * WB_BYTES) + i] = ~sel[i];
        end
    endfunction

    function [WB_DATA_W-1:0] pick_word_data;
        input [LINE_DATA_W-1:0] data;
        input [WORD_INDEX_W-1:0] word_index;
        begin
            pick_word_data = data[word_index * WB_DATA_W +: WB_DATA_W];
        end
    endfunction

    always @(posedge i_clk) begin
        if (i_rst) begin
            state <= ST_IDLE;
            req_write <= 1'b0;
            req_line_addr <= {LINE_ADDR_W{1'b0}};
            req_word_index <= {WORD_INDEX_W{1'b0}};
            req_wr_data <= {LINE_DATA_W{1'b0}};
            req_wr_mask <= {LINE_BYTES{1'b1}};
            o_wb_ack <= 1'b0;
            o_wb_dat <= {WB_DATA_W{1'b0}};
            o_wb_err <= 1'b0;
        end else begin
            o_wb_ack <= 1'b0;
            o_wb_err <= 1'b0;

            case (state)
                ST_IDLE: begin
                    if (wb_accept) begin
                        req_write <= i_wb_we;
                        req_line_addr <= i_wb_adr[WB_ADDR_W-1:WORD_INDEX_W];
                        req_word_index <= i_wb_adr[WORD_INDEX_W-1:0];
                        req_wr_data <= place_word_data(
                            i_wb_dat, i_wb_adr[WORD_INDEX_W-1:0]);
                        req_wr_mask <= place_word_mask(
                            i_wb_sel, i_wb_adr[WORD_INDEX_W-1:0]);
                        state <= ST_CMD;
                    end
                end

                ST_CMD: begin
                    if (!i_wb_cyc) begin
                        state <= ST_IDLE;
                    end else if (cmd_accept) begin
                        if (req_write) begin
                            o_wb_ack <= 1'b1;
                            state <= ST_IDLE;
                        end else begin
                            state <= i_xfer_start ? ST_WAIT_RD_DATA
                                                   : ST_WAIT_RD_XFER;
                        end
                    end
                end

                ST_WAIT_RD_XFER: begin
                    if (!i_wb_cyc)
                        state <= ST_IDLE;
                    else if (i_xfer_start)
                        state <= ST_WAIT_RD_DATA;
                end

                ST_WAIT_RD_DATA: begin
                    if (!i_wb_cyc) begin
                        state <= ST_IDLE;
                    end else if (i_phy_rd_line_valid) begin
                        o_wb_ack <= 1'b1;
                        o_wb_err <= i_phy_rd_line_err;
                        o_wb_dat <= pick_word_data(
                            i_phy_rd_line_data, req_word_index);
                        state <= ST_IDLE;
                    end
                end

                default: begin
                    state <= ST_IDLE;
                end
            endcase
        end
    end
endmodule

`default_nettype wire

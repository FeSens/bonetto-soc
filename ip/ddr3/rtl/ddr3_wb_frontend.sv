// Wishbone-to-BL8 line frontend for the clean-sheet DDR3 controller.
//
// This slice accepts one 32-bit Wishbone request at a time and translates it
// into one aligned BL8 line request for the scheduler/data path. Full-channel
// DDR3 will use LINE_BYTES=64; the default LINE_BYTES=8 matches the current
// single x8 byte-lane bring-up slice.

`default_nettype none

module ddr3_wb_frontend #(
    parameter integer WB_ADDR_W  = 8,
    parameter integer LINE_BYTES = 8,
    parameter integer WB_DATA_W  = 32,
    localparam integer LINE_DATA_W    = LINE_BYTES * 8,
    localparam integer WORDS_PER_LINE = LINE_BYTES / (WB_DATA_W / 8),
    localparam integer WORD_INDEX_W   = (WORDS_PER_LINE <= 1) ? 1 : $clog2(WORDS_PER_LINE),
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

    output reg                     o_req_valid,
    input wire                     i_req_ready,
    output reg                     o_req_write,
    output reg [LINE_ADDR_W-1:0]   o_req_line_addr,
    output reg [WORD_INDEX_W-1:0]  o_req_word_index,
    output reg [LINE_DATA_W-1:0]   o_req_wr_data,
    output reg [LINE_BYTES-1:0]    o_req_wr_mask,

    input wire                     i_rsp_valid,
    input wire [LINE_DATA_W-1:0]   i_rsp_data,
    input wire                     i_rsp_err
);
    localparam integer WB_BYTES = WB_DATA_W / 8;

    localparam [1:0]
        ST_IDLE  = 2'd0,
        ST_REQ   = 2'd1,
        ST_RSP   = 2'd2,
        ST_DRAIN = 2'd3;

    reg [1:0] state;

    wire wb_accept = i_wb_cyc && i_wb_stb && !o_wb_stall;
    wire req_accept = o_req_valid && i_req_ready;

    assign o_wb_stall = (state != ST_IDLE);

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
            place_word_mask = {LINE_BYTES{1'b0}};
            for (i = 0; i < WB_BYTES; i = i + 1)
                place_word_mask[(word_index * WB_BYTES) + i] = sel[i];
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
            state            <= ST_IDLE;
            o_wb_ack         <= 1'b0;
            o_wb_dat         <= {WB_DATA_W{1'b0}};
            o_wb_err         <= 1'b0;
            o_req_valid      <= 1'b0;
            o_req_write      <= 1'b0;
            o_req_line_addr  <= {LINE_ADDR_W{1'b0}};
            o_req_word_index <= {WORD_INDEX_W{1'b0}};
            o_req_wr_data    <= {LINE_DATA_W{1'b0}};
            o_req_wr_mask    <= {LINE_BYTES{1'b0}};
        end else begin
            o_wb_ack <= 1'b0;
            o_wb_err <= 1'b0;

            case (state)
                ST_IDLE: begin
                    o_req_valid <= 1'b0;

                    if (wb_accept) begin
                        o_req_valid      <= 1'b1;
                        o_req_write      <= i_wb_we;
                        o_req_line_addr  <= i_wb_adr[WB_ADDR_W-1:WORD_INDEX_W];
                        o_req_word_index <= i_wb_adr[WORD_INDEX_W-1:0];
                        o_req_wr_data    <= place_word_data(
                            i_wb_dat, i_wb_adr[WORD_INDEX_W-1:0]);
                        o_req_wr_mask    <= place_word_mask(
                            i_wb_sel, i_wb_adr[WORD_INDEX_W-1:0]);
                        state <= ST_REQ;
                    end
                end

                ST_REQ: begin
                    if (!i_wb_cyc) begin
                        o_req_valid <= 1'b0;
                        state <= ST_IDLE;
                    end else if (req_accept) begin
                        o_req_valid <= 1'b0;
                        if (o_req_write) begin
                            o_wb_ack <= 1'b1;
                            state <= ST_IDLE;
                        end else begin
                            state <= ST_RSP;
                        end
                    end
                end

                ST_RSP: begin
                    if (!i_wb_cyc) begin
                        state <= ST_DRAIN;
                    end else if (i_rsp_valid) begin
                        o_wb_ack <= 1'b1;
                        o_wb_err <= i_rsp_err;
                        o_wb_dat <= pick_word_data(i_rsp_data, o_req_word_index);
                        state <= ST_IDLE;
                    end
                end

                ST_DRAIN: begin
                    if (i_rsp_valid)
                        state <= ST_IDLE;
                end

                default: begin
                    state <= ST_IDLE;
                    o_req_valid <= 1'b0;
                end
            endcase
        end
    end
endmodule

`default_nettype wire

// Abstract DDR3 PHY-clock timing probe for board bring-up.
//
// This module is deliberately not an addressable memory model. It lives in the
// fast PHY clock domain and checks the pin-pair contract around ACT/READ/WRITE,
// DQ/DM/DQS launch, and read-capture replay. It keeps only the most recently
// written line per channel, which is enough for immediate write/read hardware
// smoke tests while avoiding a large debug RAM on the DQ clock path.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_pinpair_timing_probe_channel #(
    parameter integer LANES = 8,
    parameter integer ROW_BITS = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer COL_BITS = `DDR3_COL_BITS,
    localparam integer BANKS = (1 << BANK_BITS),
    localparam integer COL_LINE_BITS = COL_BITS - 3,
    localparam integer LINE_ADDR_W = BANK_BITS + ROW_BITS + COL_LINE_BITS,
    localparam integer LINE_DATA_W = LANES * 64
) (
    input  wire                     i_clk,
    input  wire                     i_rst,

    input  wire                     i_cmd_valid,
    input  wire                     i_cs_n,
    input  wire                     i_ras_n,
    input  wire                     i_cas_n,
    input  wire                     i_we_n,
    input  wire [BANK_BITS-1:0]     i_ba,
    input  wire [ROW_BITS-1:0]      i_addr,

    input  wire [LANES-1:0]         i_dq_oe,
    input  wire [LANES-1:0]         i_dm_oe,
    input  wire [LANES-1:0]         i_dqs_oe,
    input  wire [(LANES*8)-1:0]     i_dq_rise,
    input  wire [(LANES*8)-1:0]     i_dq_fall,
    input  wire [LANES-1:0]         i_dm_rise,
    input  wire [LANES-1:0]         i_dm_fall,
    input  wire [LANES-1:0]         i_dqs_rise,
    input  wire [LANES-1:0]         i_dqs_fall,

    input  wire [LANES-1:0]         i_rd_capturing,
    output wire [LANES-1:0]         o_rd_sample_valid,
    output reg  [(LANES*8)-1:0]     o_dq_rise,
    output reg  [(LANES*8)-1:0]     o_dq_fall,

    output reg                      o_error,
    output reg [31:0]               o_wr_count,
    output reg [31:0]               o_rd_count,
    output reg [LINE_ADDR_W-1:0]    o_last_line_addr
);
    reg [ROW_BITS-1:0] open_row [0:BANKS-1];

    reg last_line_valid;
    reg [LINE_DATA_W-1:0] last_line;
    reg [LINE_DATA_W-1:0] rd_line;

    reg wr_active;
    reg [1:0] wr_pair;
    reg rd_active;
    reg [1:0] rd_pair;

    wire cmd_active = i_cmd_valid && !i_cs_n;
    wire cmd_act = cmd_active && !i_ras_n && i_cas_n && i_we_n;
    wire cmd_wr = cmd_active && i_ras_n && !i_cas_n && !i_we_n;
    wire cmd_rd = cmd_active && i_ras_n && !i_cas_n && i_we_n;

    wire [COL_LINE_BITS-1:0] cmd_col_line = i_addr[COL_BITS-1:3];
    wire [LINE_ADDR_W-1:0] cmd_line_addr =
        {i_ba, open_row[i_ba], cmd_col_line};

    wire any_write_pair = |i_dq_oe;
    wire any_read_pair = |i_rd_capturing;

    assign o_rd_sample_valid = rd_active ? i_rd_capturing
                                         : {LANES{1'b0}};

    task automatic capture_write_pair;
        input [1:0] pair_index;
        integer lane_i;
        begin
            for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1) begin
                case (pair_index)
                    2'd0: begin
                        last_line[(lane_i * 64) +: 8] <=
                            i_dq_rise[lane_i*8 +: 8];
                        last_line[(lane_i * 64) + 8 +: 8] <=
                            i_dq_fall[lane_i*8 +: 8];
                    end

                    2'd1: begin
                        last_line[(lane_i * 64) + 16 +: 8] <=
                            i_dq_rise[lane_i*8 +: 8];
                        last_line[(lane_i * 64) + 24 +: 8] <=
                            i_dq_fall[lane_i*8 +: 8];
                    end

                    2'd2: begin
                        last_line[(lane_i * 64) + 32 +: 8] <=
                            i_dq_rise[lane_i*8 +: 8];
                        last_line[(lane_i * 64) + 40 +: 8] <=
                            i_dq_fall[lane_i*8 +: 8];
                    end

                    default: begin
                        last_line[(lane_i * 64) + 48 +: 8] <=
                            i_dq_rise[lane_i*8 +: 8];
                        last_line[(lane_i * 64) + 56 +: 8] <=
                            i_dq_fall[lane_i*8 +: 8];
                    end
                endcase
            end
        end
    endtask

    task automatic drive_read_pair;
        input [LINE_DATA_W-1:0] line;
        input [1:0] pair_index;
        integer lane_i;
        begin
            for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1) begin
                case (pair_index)
                    2'd0: begin
                        o_dq_rise[lane_i*8 +: 8] <=
                            line[(lane_i * 64) +: 8];
                        o_dq_fall[lane_i*8 +: 8] <=
                            line[(lane_i * 64) + 8 +: 8];
                    end

                    2'd1: begin
                        o_dq_rise[lane_i*8 +: 8] <=
                            line[(lane_i * 64) + 16 +: 8];
                        o_dq_fall[lane_i*8 +: 8] <=
                            line[(lane_i * 64) + 24 +: 8];
                    end

                    2'd2: begin
                        o_dq_rise[lane_i*8 +: 8] <=
                            line[(lane_i * 64) + 32 +: 8];
                        o_dq_fall[lane_i*8 +: 8] <=
                            line[(lane_i * 64) + 40 +: 8];
                    end

                    default: begin
                        o_dq_rise[lane_i*8 +: 8] <=
                            line[(lane_i * 64) + 48 +: 8];
                        o_dq_fall[lane_i*8 +: 8] <=
                            line[(lane_i * 64) + 56 +: 8];
                    end
                endcase
            end
        end
    endtask

    integer init_i;
    initial begin
        last_line_valid = 1'b0;
        last_line = {LINE_DATA_W{1'b0}};
        rd_line = {LINE_DATA_W{1'b0}};
        wr_active = 1'b0;
        wr_pair = 2'd0;
        rd_active = 1'b0;
        rd_pair = 2'd0;
        o_dq_rise = {(LANES*8){1'b0}};
        o_dq_fall = {(LANES*8){1'b0}};
        o_error = 1'b0;
        o_wr_count = 32'd0;
        o_rd_count = 32'd0;
        o_last_line_addr = {LINE_ADDR_W{1'b0}};
        for (init_i = 0; init_i < BANKS; init_i = init_i + 1)
            open_row[init_i] = {ROW_BITS{1'b0}};
    end

    integer bank_i;

    always @(posedge i_clk) begin
        if (i_rst) begin
            for (bank_i = 0; bank_i < BANKS; bank_i = bank_i + 1)
                open_row[bank_i] <= {ROW_BITS{1'b0}};

            last_line_valid <= 1'b0;
            last_line <= {LINE_DATA_W{1'b0}};
            rd_line <= {LINE_DATA_W{1'b0}};
            wr_active <= 1'b0;
            wr_pair <= 2'd0;
            rd_active <= 1'b0;
            rd_pair <= 2'd0;
            o_error <= 1'b0;
            o_wr_count <= 32'd0;
            o_rd_count <= 32'd0;
            o_last_line_addr <= {LINE_ADDR_W{1'b0}};
        end else begin
            if (cmd_act)
                open_row[i_ba] <= i_addr[ROW_BITS-1:0];

            if (cmd_wr) begin
                if (wr_active) begin
                    o_error <= 1'b1;
                end else begin
                    wr_active <= 1'b1;
                    wr_pair <= 2'd0;
                    if (!last_line_valid)
                        last_line <= {LINE_DATA_W{1'b0}};
                    o_last_line_addr <= cmd_line_addr;
                end
            end

            if (cmd_rd) begin
                if (rd_active) begin
                    o_error <= 1'b1;
                end else begin
                    rd_active <= 1'b1;
                    rd_pair <= 2'd0;
                    rd_line <= last_line_valid ? last_line
                                               : {LINE_DATA_W{1'b0}};
                    drive_read_pair(last_line_valid ? last_line
                                                    : {LINE_DATA_W{1'b0}},
                                    2'd0);
                    o_last_line_addr <= cmd_line_addr;
                end
            end

            if (wr_active && any_write_pair) begin
                capture_write_pair(wr_pair);

                if (wr_pair == 2'd3) begin
                    last_line_valid <= 1'b1;
                    wr_active <= 1'b0;
                    wr_pair <= 2'd0;
                    o_wr_count <= o_wr_count + 32'd1;
                end else begin
                    wr_pair <= wr_pair + 2'd1;
                end
            end else if (!wr_active && any_write_pair) begin
                o_error <= 1'b1;
            end

            if (rd_active && any_read_pair) begin
                if (rd_pair == 2'd3) begin
                    rd_active <= 1'b0;
                    rd_pair <= 2'd0;
                    o_rd_count <= o_rd_count + 32'd1;
                end else begin
                    drive_read_pair(rd_line, rd_pair + 2'd1);
                    rd_pair <= rd_pair + 2'd1;
                end
            end else if (!rd_active && any_read_pair) begin
                o_error <= 1'b1;
            end
        end
    end
endmodule

module ddr3_pinpair_timing_probe_phy #(
    parameter integer CHANNELS = 2,
    parameter integer LANES = 8,
    parameter integer ROW_BITS = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer COL_BITS = `DDR3_COL_BITS,
    localparam integer PHY_LANES = CHANNELS * LANES,
    localparam integer LINE_ADDR_W = BANK_BITS + ROW_BITS + (COL_BITS - 3)
) (
    input  wire                         i_clk,
    input  wire                         i_rst,

    input  wire [CHANNELS-1:0]          i_cmd_valid,
    input  wire [CHANNELS-1:0]          i_cs_n,
    input  wire [CHANNELS-1:0]          i_ras_n,
    input  wire [CHANNELS-1:0]          i_cas_n,
    input  wire [CHANNELS-1:0]          i_we_n,
    input  wire [CHANNELS*BANK_BITS-1:0] i_ba,
    input  wire [CHANNELS*ROW_BITS-1:0] i_addr,

    input  wire [PHY_LANES-1:0]         i_dq_oe,
    input  wire [PHY_LANES-1:0]         i_dm_oe,
    input  wire [PHY_LANES-1:0]         i_dqs_oe,
    input  wire [(PHY_LANES*8)-1:0]     i_dq_rise,
    input  wire [(PHY_LANES*8)-1:0]     i_dq_fall,
    input  wire [PHY_LANES-1:0]         i_dm_rise,
    input  wire [PHY_LANES-1:0]         i_dm_fall,
    input  wire [PHY_LANES-1:0]         i_dqs_rise,
    input  wire [PHY_LANES-1:0]         i_dqs_fall,

    input  wire [PHY_LANES-1:0]         i_rd_capturing,
    output wire [PHY_LANES-1:0]         o_rd_sample_valid,
    output wire [(PHY_LANES*8)-1:0]     o_dq_rise,
    output wire [(PHY_LANES*8)-1:0]     o_dq_fall,

    output wire [CHANNELS-1:0]          o_error,
    output wire [CHANNELS*32-1:0]       o_wr_count,
    output wire [CHANNELS*32-1:0]       o_rd_count,
    output wire [CHANNELS*LINE_ADDR_W-1:0] o_last_line_addr
);
    genvar ch;
    generate
        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_channel
            localparam integer PHY_BASE = ch * LANES;

            ddr3_pinpair_timing_probe_channel #(
                .LANES(LANES),
                .ROW_BITS(ROW_BITS),
                .BANK_BITS(BANK_BITS),
                .COL_BITS(COL_BITS)
            ) u_probe (
                .i_clk(i_clk),
                .i_rst(i_rst),
                .i_cmd_valid(i_cmd_valid[ch]),
                .i_cs_n(i_cs_n[ch]),
                .i_ras_n(i_ras_n[ch]),
                .i_cas_n(i_cas_n[ch]),
                .i_we_n(i_we_n[ch]),
                .i_ba(i_ba[ch*BANK_BITS +: BANK_BITS]),
                .i_addr(i_addr[ch*ROW_BITS +: ROW_BITS]),
                .i_dq_oe(i_dq_oe[PHY_BASE +: LANES]),
                .i_dm_oe(i_dm_oe[PHY_BASE +: LANES]),
                .i_dqs_oe(i_dqs_oe[PHY_BASE +: LANES]),
                .i_dq_rise(i_dq_rise[PHY_BASE*8 +: LANES*8]),
                .i_dq_fall(i_dq_fall[PHY_BASE*8 +: LANES*8]),
                .i_dm_rise(i_dm_rise[PHY_BASE +: LANES]),
                .i_dm_fall(i_dm_fall[PHY_BASE +: LANES]),
                .i_dqs_rise(i_dqs_rise[PHY_BASE +: LANES]),
                .i_dqs_fall(i_dqs_fall[PHY_BASE +: LANES]),
                .i_rd_capturing(i_rd_capturing[PHY_BASE +: LANES]),
                .o_rd_sample_valid(o_rd_sample_valid[PHY_BASE +: LANES]),
                .o_dq_rise(o_dq_rise[PHY_BASE*8 +: LANES*8]),
                .o_dq_fall(o_dq_fall[PHY_BASE*8 +: LANES*8]),
                .o_error(o_error[ch]),
                .o_wr_count(o_wr_count[ch*32 +: 32]),
                .o_rd_count(o_rd_count[ch*32 +: 32]),
                .o_last_line_addr(
                    o_last_line_addr[ch*LINE_ADDR_W +: LINE_ADDR_W])
            );
        end
    endgenerate
endmodule

`default_nettype wire

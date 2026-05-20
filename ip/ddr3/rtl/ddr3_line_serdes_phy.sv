// DDR3 line-to-SERDES PHY boundary.
//
// This is the reusable RTL shell immediately before board-specific Xilinx
// OSERDES/ISERDES/IDELAY glue. Slow fabric owns complete BL8 line assembly,
// masks, arbitration, and command timing. The fast side sees one preloaded x8
// BL8 burst per physical byte lane, one write/read start pulse, and one
// returned 64-bit SERDES read word per lane.

`default_nettype none

module ddr3_line_serdes_phy #(
    parameter integer CHANNELS = 2,
    parameter integer LANES = 8,
    parameter integer WRITE_LATENCY = 5,
    parameter integer READ_LATENCY = 6,
    localparam integer PHY_LANES = CHANNELS * LANES,
    localparam integer LINE_BYTES = LANES * 8,
    localparam integer LINE_DATA_W = LINE_BYTES * 8,
    localparam integer LANE_DATA_W = 64,
    localparam integer LANE_MASK_W = 8
) (
    input wire i_ctrl_clk,
    input wire i_ctrl_rst,
    input wire i_phy_clk,
    input wire i_phy_rst,

    input wire [CHANNELS-1:0]                i_wr_line_valid,
    output wire [CHANNELS-1:0]               o_wr_line_ready,
    output reg [CHANNELS-1:0]                o_wr_line_loaded,
    input wire [(CHANNELS*LINE_DATA_W)-1:0]  i_wr_line_data,
    input wire [(CHANNELS*LINE_BYTES)-1:0]   i_wr_line_mask,
    input wire [CHANNELS-1:0]                i_start_write,
    input wire [CHANNELS-1:0]                i_start_read,
    input wire [CHANNELS-1:0]                i_rd_line_ready,
    output wire [CHANNELS-1:0]               o_rd_line_valid,
    output wire [(CHANNELS*LINE_DATA_W)-1:0] o_rd_line_data,
    output wire [CHANNELS-1:0]               o_rd_line_err,
    output reg [CHANNELS-1:0]                o_error,
    output reg [CHANNELS-1:0]                o_busy,

    output wire [(PHY_LANES*LANE_DATA_W)-1:0] o_serdes_dq_bits,
    output wire [(PHY_LANES*8)-1:0]           o_serdes_dqs_bits,
    output wire [(PHY_LANES*4)-1:0]           o_serdes_dq_oe,
    output wire [(PHY_LANES*4)-1:0]           o_serdes_dqs_oe,
    input wire [(PHY_LANES*LANE_DATA_W)-1:0]  i_serdes_dq_bits
);
    wire [CHANNELS-1:0] line_rd_err;

    wire [PHY_LANES-1:0] lane_wr_valid;
    wire [PHY_LANES-1:0] lane_wr_ready;
    wire [(PHY_LANES*LANE_DATA_W)-1:0] lane_wr_data;
    wire [(PHY_LANES*LANE_MASK_W)-1:0] lane_wr_mask;
    wire [PHY_LANES-1:0] lane_rd_ready;
    wire [PHY_LANES-1:0] lane_rd_valid;
    wire [(PHY_LANES*LANE_DATA_W)-1:0] lane_rd_data;
    wire [PHY_LANES-1:0] lane_rd_err;

    wire [PHY_LANES-1:0] bridge_ctrl_error;
    wire [PHY_LANES-1:0] bridge_ctrl_busy;
    wire [PHY_LANES-1:0] bridge_phy_error;
    wire [PHY_LANES-1:0] bridge_phy_busy;

    wire [PHY_LANES-1:0] phy_wr_valid;
    wire [PHY_LANES-1:0] phy_wr_ready;
    wire [(PHY_LANES*LANE_DATA_W)-1:0] phy_wr_data;
    wire [(PHY_LANES*LANE_MASK_W)-1:0] phy_wr_mask;
    wire [PHY_LANES-1:0] phy_start_write;
    wire [PHY_LANES-1:0] phy_start_read;
    wire [PHY_LANES-1:0] phy_rd_ready;
    wire [PHY_LANES-1:0] phy_rd_valid;
    wire [(PHY_LANES*LANE_DATA_W)-1:0] phy_rd_data;
    wire [PHY_LANES-1:0] phy_rd_err;

    wire [PHY_LANES-1:0] serdes_busy;
    wire [PHY_LANES-1:0] serdes_error;
    wire [PHY_LANES-1:0] serdes_wr_loaded;

    reg [CHANNELS-1:0] lane_rd_err_seen;
    reg [CHANNELS-1:0] lane_phy_error_seen;
    reg [PHY_LANES-1:0] phy_error_meta;
    reg [PHY_LANES-1:0] phy_error_sync;
    reg [PHY_LANES-1:0] phy_busy_meta;
    reg [PHY_LANES-1:0] phy_busy_sync;
    reg [PHY_LANES-1:0] phy_wr_loaded_meta;
    reg [PHY_LANES-1:0] phy_wr_loaded_sync;

    wire [PHY_LANES-1:0] phy_error_async = bridge_phy_error | serdes_error;
    wire [PHY_LANES-1:0] phy_busy_async =
        bridge_phy_busy | serdes_busy | serdes_wr_loaded;

    ddr3_line_to_bursts #(
        .CHANNELS(CHANNELS),
        .LANES(LANES)
    ) u_line_to_bursts (
        .i_clk(i_ctrl_clk),
        .i_rst(i_ctrl_rst),
        .i_wr_line_valid(i_wr_line_valid),
        .o_wr_line_ready(o_wr_line_ready),
        .i_wr_line_data(i_wr_line_data),
        .i_wr_line_mask(i_wr_line_mask),
        .i_rd_line_ready(i_rd_line_ready),
        .o_rd_line_valid(o_rd_line_valid),
        .o_rd_line_data(o_rd_line_data),
        .o_rd_line_err(line_rd_err),
        .o_lane_wr_valid(lane_wr_valid),
        .i_lane_wr_ready(lane_wr_ready),
        .o_lane_wr_data(lane_wr_data),
        .o_lane_wr_mask(lane_wr_mask),
        .o_lane_rd_ready(lane_rd_ready),
        .i_lane_rd_valid(lane_rd_valid),
        .i_lane_rd_data(lane_rd_data)
    );

    assign o_rd_line_err = line_rd_err | lane_rd_err_seen;

    genvar phy_g;
    generate
        for (phy_g = 0; phy_g < PHY_LANES; phy_g = phy_g + 1) begin : gen_lane
            localparam integer CH_INDEX = phy_g / LANES;

            ddr3_x8_burst_clock_bridge u_bridge (
                .i_ctrl_clk(i_ctrl_clk),
                .i_ctrl_rst(i_ctrl_rst),
                .i_phy_clk(i_phy_clk),
                .i_phy_rst(i_phy_rst),
                .i_ctrl_wr_valid(lane_wr_valid[phy_g]),
                .o_ctrl_wr_ready(lane_wr_ready[phy_g]),
                .i_ctrl_wr_data(lane_wr_data[phy_g*LANE_DATA_W +: LANE_DATA_W]),
                .i_ctrl_wr_mask(lane_wr_mask[phy_g*LANE_MASK_W +: LANE_MASK_W]),
                .i_ctrl_start_write(i_start_write[CH_INDEX]),
                .i_ctrl_start_read(i_start_read[CH_INDEX]),
                .i_ctrl_rd_ready(lane_rd_ready[phy_g]),
                .o_ctrl_rd_valid(lane_rd_valid[phy_g]),
                .o_ctrl_rd_data(lane_rd_data[phy_g*LANE_DATA_W +: LANE_DATA_W]),
                .o_ctrl_rd_err(lane_rd_err[phy_g]),
                .o_ctrl_error(bridge_ctrl_error[phy_g]),
                .o_ctrl_busy(bridge_ctrl_busy[phy_g]),
                .o_phy_wr_valid(phy_wr_valid[phy_g]),
                .i_phy_wr_ready(phy_wr_ready[phy_g]),
                .o_phy_wr_data(phy_wr_data[phy_g*LANE_DATA_W +: LANE_DATA_W]),
                .o_phy_wr_mask(phy_wr_mask[phy_g*LANE_MASK_W +: LANE_MASK_W]),
                .o_phy_start_write(phy_start_write[phy_g]),
                .o_phy_start_read(phy_start_read[phy_g]),
                .o_phy_rd_ready(phy_rd_ready[phy_g]),
                .i_phy_rd_valid(phy_rd_valid[phy_g]),
                .i_phy_rd_data(phy_rd_data[phy_g*LANE_DATA_W +: LANE_DATA_W]),
                .i_phy_rd_err(phy_rd_err[phy_g]),
                .o_phy_error(bridge_phy_error[phy_g]),
                .o_phy_busy(bridge_phy_busy[phy_g])
            );

            ddr3_x8_serdes_burst_lane #(
                .WRITE_LATENCY(WRITE_LATENCY),
                .READ_LATENCY(READ_LATENCY)
            ) u_serdes_lane (
                .i_clk(i_phy_clk),
                .i_rst(i_phy_rst),
                .i_wr_valid(phy_wr_valid[phy_g]),
                .o_wr_ready(phy_wr_ready[phy_g]),
                .i_wr_data(phy_wr_data[phy_g*LANE_DATA_W +: LANE_DATA_W]),
                .o_wr_loaded(serdes_wr_loaded[phy_g]),
                .i_start_write(phy_start_write[phy_g]),
                .i_start_read(phy_start_read[phy_g]),
                .o_busy(serdes_busy[phy_g]),
                .o_error(serdes_error[phy_g]),
                .o_serdes_dq_bits(o_serdes_dq_bits[
                    phy_g*LANE_DATA_W +: LANE_DATA_W]),
                .o_serdes_dqs_bits(o_serdes_dqs_bits[phy_g*8 +: 8]),
                .o_serdes_dq_oe(o_serdes_dq_oe[phy_g*4 +: 4]),
                .o_serdes_dqs_oe(o_serdes_dqs_oe[phy_g*4 +: 4]),
                .i_serdes_dq_bits(i_serdes_dq_bits[
                    phy_g*LANE_DATA_W +: LANE_DATA_W]),
                .o_rd_valid(phy_rd_valid[phy_g]),
                .i_rd_ready(phy_rd_ready[phy_g]),
                .o_rd_data(phy_rd_data[phy_g*LANE_DATA_W +: LANE_DATA_W])
            );

            assign phy_rd_err[phy_g] = serdes_error[phy_g];
        end
    endgenerate

    integer seq_ch_i;
    integer seq_phy_i;
    integer comb_ch_i;
    integer comb_lane_i;
    integer comb_phy_i;

    always @(posedge i_ctrl_clk) begin
        if (i_ctrl_rst) begin
            lane_rd_err_seen <= {CHANNELS{1'b0}};
            lane_phy_error_seen <= {CHANNELS{1'b0}};
            phy_error_meta <= {PHY_LANES{1'b0}};
            phy_error_sync <= {PHY_LANES{1'b0}};
            phy_busy_meta <= {PHY_LANES{1'b0}};
            phy_busy_sync <= {PHY_LANES{1'b0}};
            phy_wr_loaded_meta <= {PHY_LANES{1'b0}};
            phy_wr_loaded_sync <= {PHY_LANES{1'b0}};
        end else begin
            phy_error_meta <= phy_error_async;
            phy_error_sync <= phy_error_meta;
            phy_busy_meta <= phy_busy_async;
            phy_busy_sync <= phy_busy_meta;
            phy_wr_loaded_meta <= serdes_wr_loaded;
            phy_wr_loaded_sync <= phy_wr_loaded_meta;

            for (seq_ch_i = 0; seq_ch_i < CHANNELS;
                 seq_ch_i = seq_ch_i + 1) begin
                if (!i_rd_line_ready[seq_ch_i])
                    lane_rd_err_seen[seq_ch_i] <= 1'b0;
            end

            for (seq_phy_i = 0; seq_phy_i < PHY_LANES;
                 seq_phy_i = seq_phy_i + 1) begin
                if (lane_rd_valid[seq_phy_i] && lane_rd_ready[seq_phy_i] &&
                    lane_rd_err[seq_phy_i])
                    lane_rd_err_seen[seq_phy_i / LANES] <= 1'b1;

                if (phy_error_sync[seq_phy_i])
                    lane_phy_error_seen[seq_phy_i / LANES] <= 1'b1;
            end
        end
    end

    always @(*) begin
        o_error = lane_rd_err_seen | lane_phy_error_seen;
        o_busy = {CHANNELS{1'b0}};
        o_wr_line_loaded = {CHANNELS{1'b0}};

        for (comb_ch_i = 0; comb_ch_i < CHANNELS;
             comb_ch_i = comb_ch_i + 1) begin
            o_wr_line_loaded[comb_ch_i] = 1'b1;

            for (comb_lane_i = 0; comb_lane_i < LANES;
                 comb_lane_i = comb_lane_i + 1) begin
                comb_phy_i = (comb_ch_i * LANES) + comb_lane_i;

                o_error[comb_ch_i] = o_error[comb_ch_i] ||
                    bridge_ctrl_error[comb_phy_i];
                o_busy[comb_ch_i] = o_busy[comb_ch_i] ||
                    bridge_ctrl_busy[comb_phy_i] ||
                    phy_busy_sync[comb_phy_i];
                o_wr_line_loaded[comb_ch_i] =
                    o_wr_line_loaded[comb_ch_i] &&
                    phy_wr_loaded_sync[comb_phy_i];
            end
        end
    end

    wire _unused = &{1'b0, phy_wr_mask, 1'b0};
endmodule

`default_nettype wire

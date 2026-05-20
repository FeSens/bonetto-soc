// Route-only DDR3 x8 burst sequencer plus DQ/DQS I/O-shell probe.
//
// This top intentionally keeps both DDR3 devices in reset with CKE low. It is
// not a memory-controller image. Its job is to prove that autonomous per-lane
// fast-domain burst sequencers can sit directly in front of the board DQ/DQS
// primitive shell and still route at the DDR3-800 bit clock. Read reassembly is
// covered by the sequencer's focused sim/formal tests; this board probe stresses
// the full-width write-launch path into all physical DQ/DQS pins.

`default_nettype none

module top_ddr3_dq_dqs_burst_probe (
    input  wire        SYS_CLK,
    input  wire        SYS_RSTN,
    output wire [2:0]  led_3bits_tri_o,

    output wire [14:0] ddr3_addr,
    output wire [2:0]  ddr3_ba,
    output wire        ddr3_ras_n,
    output wire        ddr3_cas_n,
    output wire        ddr3_we_n,
    output wire        ddr3_cs_n,
    output wire        ddr3_cke,
    output wire        ddr3_odt,
    output wire        ddr3_reset_n,
    output wire        ddr3_ck_p,
    output wire        ddr3_ck_n,
    inout  wire [71:0] ddr3_dq,
    inout  wire [8:0]  ddr3_dqs_p,
    inout  wire [8:0]  ddr3_dqs_n,

    output wire [14:0] ddr3_ch1_addr,
    output wire [2:0]  ddr3_ch1_ba,
    output wire        ddr3_ch1_ras_n,
    output wire        ddr3_ch1_cas_n,
    output wire        ddr3_ch1_we_n,
    output wire        ddr3_ch1_cs_n,
    output wire        ddr3_ch1_cke,
    output wire        ddr3_ch1_odt,
    output wire        ddr3_ch1_reset_n,
    output wire        ddr3_ch1_ck_p,
    output wire        ddr3_ch1_ck_n,
    inout  wire [71:0] ddr3_ch1_dq,
    inout  wire [8:0]  ddr3_ch1_dqs_p,
    inout  wire [8:0]  ddr3_ch1_dqs_n
);
    localparam integer LANES_PER_CH = 9;
    localparam integer TOTAL_LANES  = 18;
    localparam integer DQ_PER_LANE  = 8;
    localparam integer DQ_PER_CH    = LANES_PER_CH * DQ_PER_LANE;
    localparam integer TOTAL_DQ     = TOTAL_LANES * DQ_PER_LANE;

    wire clk_sys;
    wire clk_ddr;
    wire clk_dq;
    wire pll_locked;

    ddr3_800_clocking u_clocking (
        .i_clk_50(SYS_CLK),
        .i_rst(!SYS_RSTN),
        .o_clk_sys(clk_sys),
        .o_clk_ddr(clk_ddr),
        .o_clk_dq(clk_dq),
        .o_locked(pll_locked)
    );

    // This is a pure route probe. Avoid distributing a reset through the
    // 400 MHz DQ fabric; the external DDR3 devices are held reset/CKE-low.
    wire dq_route_rst = 1'b0;

    ddr3_ck_out_7series u_ck_ch0 (
        .i_clk_ddr(clk_ddr),
        .i_rst(dq_route_rst),
        .o_ck_p(ddr3_ck_p),
        .o_ck_n(ddr3_ck_n)
    );

    ddr3_ck_out_7series u_ck_ch1 (
        .i_clk_ddr(clk_ddr),
        .i_rst(dq_route_rst),
        .o_ck_p(ddr3_ch1_ck_p),
        .o_ck_n(ddr3_ch1_ck_n)
    );

    assign ddr3_addr       = 15'd0;
    assign ddr3_ba         = 3'd0;
    assign ddr3_ras_n      = 1'b1;
    assign ddr3_cas_n      = 1'b1;
    assign ddr3_we_n       = 1'b1;
    assign ddr3_cs_n       = 1'b1;
    assign ddr3_cke        = 1'b0;
    assign ddr3_odt        = 1'b0;
    assign ddr3_reset_n    = 1'b0;

    assign ddr3_ch1_addr    = 15'd0;
    assign ddr3_ch1_ba      = 3'd0;
    assign ddr3_ch1_ras_n   = 1'b1;
    assign ddr3_ch1_cas_n   = 1'b1;
    assign ddr3_ch1_we_n    = 1'b1;
    assign ddr3_ch1_cs_n    = 1'b1;
    assign ddr3_ch1_cke     = 1'b0;
    assign ddr3_ch1_odt     = 1'b0;
    assign ddr3_ch1_reset_n = 1'b0;

    wire [DQ_PER_CH-1:0] dq_sample_rise_ch0;
    wire [DQ_PER_CH-1:0] dq_sample_fall_ch0;
    wire [LANES_PER_CH-1:0] dqs_sample_rise_ch0;
    wire [LANES_PER_CH-1:0] dqs_sample_fall_ch0;
    wire [DQ_PER_CH-1:0] dq_sample_rise_ch1;
    wire [DQ_PER_CH-1:0] dq_sample_fall_ch1;
    wire [LANES_PER_CH-1:0] dqs_sample_rise_ch1;
    wire [LANES_PER_CH-1:0] dqs_sample_fall_ch1;

    wire [TOTAL_LANES-1:0] lane_dq_oe;
    wire [TOTAL_LANES-1:0] lane_dqs_oe;
    wire [TOTAL_LANES-1:0] lane_dqs_rise;
    wire [TOTAL_LANES-1:0] lane_dqs_fall;
    wire [TOTAL_LANES-1:0] lane_activity;
    wire [TOTAL_LANES-1:0] lane_error;
    wire [TOTAL_DQ-1:0] lane_dq_rise;
    wire [TOTAL_DQ-1:0] lane_dq_fall;

    genvar lane_i;
    generate
        for (lane_i = 0; lane_i < TOTAL_LANES; lane_i = lane_i + 1) begin : gen_lane_driver
            localparam integer CH = lane_i / LANES_PER_CH;
            localparam integer LANE = lane_i % LANES_PER_CH;
            localparam integer DQ_BASE = lane_i * DQ_PER_LANE;

            wire [DQ_PER_LANE-1:0] sample_rise =
                (CH == 0) ? dq_sample_rise_ch0[(LANE*DQ_PER_LANE) +: DQ_PER_LANE] :
                            dq_sample_rise_ch1[(LANE*DQ_PER_LANE) +: DQ_PER_LANE];
            wire [DQ_PER_LANE-1:0] sample_fall =
                (CH == 0) ? dq_sample_fall_ch0[(LANE*DQ_PER_LANE) +: DQ_PER_LANE] :
                            dq_sample_fall_ch1[(LANE*DQ_PER_LANE) +: DQ_PER_LANE];

            ddr3_x8_lane_route_driver #(
                .LANE_ID(lane_i),
                .WRITE_LATENCY(0),
                .READ_LATENCY(0)
            ) u_lane_driver (
                .i_clk(clk_dq),
                .i_rst(dq_route_rst),
                .i_dq_rise(sample_rise),
                .i_dq_fall(sample_fall),
                .o_dq_oe(lane_dq_oe[lane_i]),
                .o_dqs_oe(lane_dqs_oe[lane_i]),
                .o_dq_rise(lane_dq_rise[DQ_BASE +: DQ_PER_LANE]),
                .o_dq_fall(lane_dq_fall[DQ_BASE +: DQ_PER_LANE]),
                .o_dqs_rise(lane_dqs_rise[lane_i]),
                .o_dqs_fall(lane_dqs_fall[lane_i]),
                .o_activity(lane_activity[lane_i]),
                .o_error(lane_error[lane_i])
            );
        end
    endgenerate

    wire [DQ_PER_CH-1:0] dq_rise_ch0 = lane_dq_rise[0 +: DQ_PER_CH];
    wire [DQ_PER_CH-1:0] dq_fall_ch0 = lane_dq_fall[0 +: DQ_PER_CH];
    wire [LANES_PER_CH-1:0] dqs_rise_ch0 = lane_dqs_rise[0 +: LANES_PER_CH];
    wire [LANES_PER_CH-1:0] dqs_fall_ch0 = lane_dqs_fall[0 +: LANES_PER_CH];
    wire [LANES_PER_CH-1:0] dq_oe_ch0 = lane_dq_oe[0 +: LANES_PER_CH];
    wire [LANES_PER_CH-1:0] dqs_oe_ch0 = lane_dqs_oe[0 +: LANES_PER_CH];

    wire [DQ_PER_CH-1:0] dq_rise_ch1 = lane_dq_rise[DQ_PER_CH +: DQ_PER_CH];
    wire [DQ_PER_CH-1:0] dq_fall_ch1 = lane_dq_fall[DQ_PER_CH +: DQ_PER_CH];
    wire [LANES_PER_CH-1:0] dqs_rise_ch1 = lane_dqs_rise[LANES_PER_CH +: LANES_PER_CH];
    wire [LANES_PER_CH-1:0] dqs_fall_ch1 = lane_dqs_fall[LANES_PER_CH +: LANES_PER_CH];
    wire [LANES_PER_CH-1:0] dq_oe_ch1 = lane_dq_oe[LANES_PER_CH +: LANES_PER_CH];
    wire [LANES_PER_CH-1:0] dqs_oe_ch1 = lane_dqs_oe[LANES_PER_CH +: LANES_PER_CH];

    ddr3_dq_dqs_io_7series u_dq_dqs_ch0 (
        .i_clk_dq(clk_dq),
        .i_rst(dq_route_rst),
        .i_dq_oe(dq_oe_ch0),
        .i_dqs_oe(dqs_oe_ch0),
        .i_dq_rise(dq_rise_ch0),
        .i_dq_fall(dq_fall_ch0),
        .i_dqs_rise(dqs_rise_ch0),
        .i_dqs_fall(dqs_fall_ch0),
        .o_dq_rise(dq_sample_rise_ch0),
        .o_dq_fall(dq_sample_fall_ch0),
        .o_dqs_rise(dqs_sample_rise_ch0),
        .o_dqs_fall(dqs_sample_fall_ch0),
        .io_dq(ddr3_dq),
        .io_dqs_p(ddr3_dqs_p),
        .io_dqs_n(ddr3_dqs_n)
    );

    ddr3_dq_dqs_io_7series u_dq_dqs_ch1 (
        .i_clk_dq(clk_dq),
        .i_rst(dq_route_rst),
        .i_dq_oe(dq_oe_ch1),
        .i_dqs_oe(dqs_oe_ch1),
        .i_dq_rise(dq_rise_ch1),
        .i_dq_fall(dq_fall_ch1),
        .i_dqs_rise(dqs_rise_ch1),
        .i_dqs_fall(dqs_fall_ch1),
        .o_dq_rise(dq_sample_rise_ch1),
        .o_dq_fall(dq_sample_fall_ch1),
        .o_dqs_rise(dqs_sample_rise_ch1),
        .o_dqs_fall(dqs_sample_fall_ch1),
        .io_dq(ddr3_ch1_dq),
        .io_dqs_p(ddr3_ch1_dqs_p),
        .io_dqs_n(ddr3_ch1_dqs_n)
    );

    reg [23:0] led_div = 24'd0;
    always @(posedge clk_dq) begin
        led_div <= led_div + 24'd1;
    end

    assign led_3bits_tri_o = {
        lane_error[0] | lane_error[LANES_PER_CH],
        lane_activity[0] ^ lane_activity[LANES_PER_CH] ^ led_div[23],
        pll_locked
    };

    wire _unused = &{1'b0, clk_sys, dqs_sample_rise_ch0, dqs_sample_fall_ch0,
                     dqs_sample_rise_ch1, dqs_sample_fall_ch1, 1'b0};
endmodule

module ddr3_x8_lane_route_driver #(
    parameter integer LANE_ID = 0,
    parameter integer WRITE_LATENCY = 2,
    parameter integer READ_LATENCY = 2
) (
    input  wire       i_clk,
    input  wire       i_rst,
    input  wire [7:0] i_dq_rise,
    input  wire [7:0] i_dq_fall,
    output wire       o_dq_oe,
    output wire       o_dqs_oe,
    output wire [7:0] o_dq_rise,
    output wire [7:0] o_dq_fall,
    output wire       o_dqs_rise,
    output wire       o_dqs_fall,
    output reg        o_activity,
    output wire       o_error
);
    localparam [1:0]
        ST_LOAD        = 2'd0,
        ST_START_WRITE = 2'd1,
        ST_WAIT_WRITE  = 2'd2,
        ST_WRITE_GAP   = 2'd3;

    localparam [7:0] LANE_TAG = LANE_ID;

    reg [1:0] lane_state = ST_LOAD;
    reg [7:0] lane_ctr = LANE_TAG;
    reg [3:0] gap_ctr = 4'd0;
    reg [3:0] burst_ctr = 4'd0;
    reg wr_valid = 1'b0;
    reg start_write = 1'b0;

    wire [7:0] payload_b0 = lane_ctr;
    wire [7:0] payload_b1 = lane_ctr ^ LANE_TAG;
    wire [7:0] payload_b2 = lane_ctr + LANE_TAG;
    wire [7:0] payload_b3 = 8'h3c ^ LANE_TAG;
    wire [7:0] payload_b4 = ~lane_ctr;
    wire [7:0] payload_b5 = 8'ha5 ^ LANE_TAG;
    wire [7:0] payload_b6 = lane_ctr + (LANE_TAG << 1);
    wire [7:0] payload_b7 = 8'h5a ^ lane_ctr ^ LANE_TAG;
    wire [63:0] payload = {payload_b7, payload_b6, payload_b5, payload_b4,
                           payload_b3, payload_b2, payload_b1, payload_b0};

    always @(posedge i_clk) begin
        wr_valid <= 1'b0;
        start_write <= 1'b0;

        if (i_rst) begin
            lane_state <= ST_LOAD;
            lane_ctr <= LANE_TAG;
            gap_ctr <= 4'd0;
            burst_ctr <= 4'd0;
            o_activity <= 1'b0;
        end else begin
            case (lane_state)
                ST_LOAD: begin
                    wr_valid <= 1'b1;
                    lane_state <= ST_START_WRITE;
                end

                ST_START_WRITE: begin
                    start_write <= 1'b1;
                    burst_ctr <= 4'd7;
                    lane_state <= ST_WAIT_WRITE;
                end

                ST_WAIT_WRITE: begin
                    if (burst_ctr == 4'd0) begin
                        o_activity <= ~o_activity;
                        gap_ctr <= 4'd8;
                        lane_state <= ST_WRITE_GAP;
                    end else begin
                        burst_ctr <= burst_ctr - 4'd1;
                    end
                end

                ST_WRITE_GAP: begin
                    if (gap_ctr == 4'd0) begin
                        lane_ctr <= lane_ctr + 8'd1;
                        lane_state <= ST_LOAD;
                    end else begin
                        gap_ctr <= gap_ctr - 4'd1;
                    end
                end

                default: begin
                    lane_state <= ST_LOAD;
                end
            endcase
        end
    end

    ddr3_x8_burst_io_sequencer #(
        .WRITE_LATENCY(WRITE_LATENCY),
        .READ_LATENCY(READ_LATENCY),
        .FAST_ROUTE_ACCEPT(1)
    ) u_seq (
        .i_clk(i_clk),
        .i_rst(1'b0),
        .i_wr_valid(wr_valid),
        .o_wr_ready(),
        .i_wr_data(payload),
        .o_wr_loaded(),
        .i_start_write(start_write),
        .i_start_read(1'b0),
        .o_busy(),
        .o_error(o_error),
        .o_dq_oe(o_dq_oe),
        .o_dqs_oe(o_dqs_oe),
        .o_dq_rise(o_dq_rise),
        .o_dq_fall(o_dq_fall),
        .o_dqs_rise(o_dqs_rise),
        .o_dqs_fall(o_dqs_fall),
        .o_rd_capturing(),
        .i_rd_sample_valid(1'b0),
        .i_dq_rise(8'h00),
        .i_dq_fall(8'h00),
        .o_rd_valid(),
        .i_rd_ready(1'b1),
        .o_rd_data()
    );

    wire _unused = &{1'b0, i_dq_rise, i_dq_fall, 1'b0};
endmodule

`default_nettype wire

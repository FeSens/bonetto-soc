// ddr3_phy_lane_array — replicate ddr3_phy_dq N times for the full data path.
//
// Iter-4: split DQS-output and DQS-input cal interfaces. wlvl drives the
// per-lane ODELAYE2 (output) via `i_cal_dqs_out_*` and `i_cal_dqs_toggle_en_lane`;
// rdlvl drives the per-lane IDELAYE2 (input) via `i_cal_dqs_in_*`.

`default_nettype none

module ddr3_phy_lane_array #(
    parameter integer NUM_BYTE_LANES = 9,
    parameter integer DQ_BITS        = 8,
    parameter integer RATIO          = 4,
    parameter integer WR_DQS_DELAY_CK = 4,
    parameter integer RD_VALID_REQUIRE_ALL = 1
) (
    // -------- Clocks --------
    input  wire                              i_clk_sys,
    input  wire                              i_clk_phy_x4,
    input  wire                              i_clk_dq,
    input  wire                              i_clk_ref_200,
    input  wire                              i_rst,

    // -------- Write side --------
    input  wire                              i_wr_en,
    input  wire [NUM_BYTE_LANES*DQ_BITS*RATIO-1:0] i_wr_data,
    input  wire                              i_wr_dqs_en,

    // -------- Read side --------
    input  wire                              i_rd_capture,
    output wire [NUM_BYTE_LANES*DQ_BITS*RATIO-1:0] o_rd_data,
    output wire [NUM_BYTE_LANES-1:0]         o_rd_valid_lane,
    output wire                              o_rd_valid_all,

    // -------- Calibration: per-bit DQ IDELAYE2 (rdlvl per-bit, future) ---
    input  wire [NUM_BYTE_LANES-1:0]         i_cal_dq_load_lane,
    input  wire [DQ_BITS-1:0]                i_cal_dq_sel,
    input  wire [4:0]                        i_cal_dq_tap,

    // -------- Calibration: DQS IDELAYE2 input (rdlvl) ---------------
    input  wire [NUM_BYTE_LANES-1:0]         i_cal_dqs_in_load_lane,
    input  wire [4:0]                        i_cal_dqs_in_tap,

    // -------- Calibration: DQS ODELAYE2 output (wlvl) ---------------
    input  wire [NUM_BYTE_LANES-1:0]         i_cal_dqs_out_load_lane,
    input  wire [4:0]                        i_cal_dqs_out_tap,
    input  wire [NUM_BYTE_LANES-1:0]         i_cal_dqs_toggle_en_lane,

    // -------- IDELAYCTRL ready --------
    output wire                              o_idelay_ready,

    // -------- DDR3 chip-side pins --------
    inout  wire [NUM_BYTE_LANES*DQ_BITS-1:0] io_ddr3_dq,
    inout  wire [NUM_BYTE_LANES-1:0]         io_ddr3_dqs_p,
    inout  wire [NUM_BYTE_LANES-1:0]         io_ddr3_dqs_n,
    output wire [NUM_BYTE_LANES-1:0]         o_ddr3_dm
);

`ifdef BONETTO_SOC_SIM
    assign io_ddr3_dq      = {(NUM_BYTE_LANES*DQ_BITS){1'bz}};
    assign io_ddr3_dqs_p   = {NUM_BYTE_LANES{1'bz}};
    assign io_ddr3_dqs_n   = {NUM_BYTE_LANES{1'bz}};
    assign o_ddr3_dm       = {NUM_BYTE_LANES{1'b0}};
    assign o_rd_data       = {(NUM_BYTE_LANES*DQ_BITS*RATIO){1'b0}};
    assign o_rd_valid_lane = {NUM_BYTE_LANES{1'b0}};
    assign o_rd_valid_all  = 1'b0;
    assign o_idelay_ready  = ~i_rst;

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_clk_sys, i_clk_phy_x4, i_clk_dq, i_clk_ref_200,
                i_wr_en, i_wr_data, i_wr_dqs_en, i_rd_capture,
                i_cal_dq_load_lane, i_cal_dq_sel, i_cal_dq_tap,
                i_cal_dqs_in_load_lane, i_cal_dqs_in_tap,
                i_cal_dqs_out_load_lane, i_cal_dqs_out_tap,
                i_cal_dqs_toggle_en_lane,
                1'b0};
    /* verilator lint_on UNUSED */
`else
    // The current YPCB-00338 bring-up lane uses fabric I/O rather than
    // IDELAYE2/ISERDESE2 resources, so no IDELAYCTRL is required.
    assign o_idelay_ready = ~i_rst;

    reg [NUM_BYTE_LANES-1:0] rd_capture_lane = {NUM_BYTE_LANES{1'b0}};
    always @(posedge i_clk_sys or posedge i_rst) begin
        if (i_rst)
            rd_capture_lane <= {NUM_BYTE_LANES{1'b0}};
        else
            rd_capture_lane <= {NUM_BYTE_LANES{i_rd_capture}};
    end

    genvar bl;
    generate
        for (bl = 0; bl < NUM_BYTE_LANES; bl = bl + 1) begin : g_lane
            ddr3_phy_dq #(
                .DQ_BITS (DQ_BITS),
                .RATIO   (RATIO),
                .WR_DQS_DELAY_CK (WR_DQS_DELAY_CK)
            ) u_lane (
                .i_clk_sys           (i_clk_sys),
                .i_clk_phy_x4        (i_clk_phy_x4),
                .i_clk_dq            (i_clk_dq),
                .i_rst               (i_rst),

                .i_wr_en             (i_wr_en),
                .i_wr_data           (i_wr_data[bl*DQ_BITS*RATIO +: DQ_BITS*RATIO]),
                .i_wr_dqs_en         (i_wr_dqs_en),
                .i_rd_capture        (rd_capture_lane[bl]),

                .o_rd_data           (o_rd_data[bl*DQ_BITS*RATIO +: DQ_BITS*RATIO]),
                .o_rd_valid          (o_rd_valid_lane[bl]),

                .i_cal_dq_load       (i_cal_dq_load_lane[bl]),
                .i_cal_dq_sel        (i_cal_dq_sel),
                .i_cal_dq_tap        (i_cal_dq_tap),

                .i_cal_dqs_in_load   (i_cal_dqs_in_load_lane[bl]),
                .i_cal_dqs_in_tap    (i_cal_dqs_in_tap),

                .i_cal_dqs_out_load  (i_cal_dqs_out_load_lane[bl]),
                .i_cal_dqs_out_tap   (i_cal_dqs_out_tap),
                .i_cal_dqs_toggle_en (i_cal_dqs_toggle_en_lane[bl]),

                .io_ddr3_dq          (io_ddr3_dq[bl*DQ_BITS +: DQ_BITS]),
                .io_ddr3_dqs_p       (io_ddr3_dqs_p[bl]),
                .io_ddr3_dqs_n       (io_ddr3_dqs_n[bl]),
                .o_ddr3_dm           (o_ddr3_dm[bl])
            );
        end
    endgenerate

    assign o_rd_valid_all = RD_VALID_REQUIRE_ALL ? (&o_rd_valid_lane) : (|o_rd_valid_lane);

    /* verilator lint_off UNUSED */
    wire _u_lane_array = &{1'b0, i_clk_ref_200,
                           i_cal_dq_load_lane, i_cal_dq_sel, i_cal_dq_tap,
                           i_cal_dqs_in_load_lane, i_cal_dqs_in_tap,
                           i_cal_dqs_out_load_lane, i_cal_dqs_out_tap,
                           i_cal_dqs_toggle_en_lane, 1'b0};
    /* verilator lint_on UNUSED */
`endif
endmodule

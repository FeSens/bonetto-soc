// DDR3-800 line-controller board proof image for YPCB-00338.
//
// This is the next hardware gate after the BRAM-only JTAG/Wishbone proof and
// the full-pin DDR3 init probe. It routes host JTAG/Wishbone traffic through the
// clean dual-channel DDR3 line controller and scheduler, then selects one
// internal proof backend: whole-line loopback, line-to-x8-lane loopback, or the
// abstract line-lane PHY timing loopback.
//
// The controller loopback intentionally runs in the 50 MHz board-clock domain.
// That keeps this debug image timing-honest in openXC7 while the real DDR PHY is
// still under construction. The full DDR3 board pinout remains constrained, CK
// is generated, and DQ/DQS are high-Z. Passing one of these images proves only
// the selected internal boundary; it does not validate external DQ/DQS timing or
// real storage.

`default_nettype none

`include "ddr3_params.vh"

module top_ddr3_ctrl_line_loopback #(
    parameter integer DRIVE_DDR3_COMMANDS = 0,
    parameter integer PHY_HAS_BYTE_MASK = 1,
    parameter integer USE_LINE_TO_LANES = 0,
    parameter integer USE_LINE_LANE_PHY = 0,
    parameter [31:0] GATE_VERSION = 32'hB07E_0D82,
    parameter [23:0] DEFAULT_MAGIC = 24'hD3AD82
) (
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
    function integer div_ceil;
        input integer value;
        input integer divisor;
        begin
            div_ceil = (value + divisor - 1) / divisor;
        end
    endfunction

    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer JWB_ADDR_W = 15;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer CTRL_DIV = DRIVE_DDR3_COMMANDS ? 8 : 1;
    localparam integer ADDR_BITS = `DDR3_ADDR_BITS;
    localparam integer BANK_BITS = `DDR3_BANK_BITS;
    localparam integer LINE_ADDR_W =
        `DDR3_BANK_BITS + `DDR3_ROW_BITS + (`DDR3_COL_BITS - 3);
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;

    reg [13:0] por_ctr = 14'h3fff;
    always @(posedge SYS_CLK) begin
        if (!SYS_RSTN)
            por_ctr <= 14'h3fff;
        else if (por_ctr != 14'd0)
            por_ctr <= por_ctr - 14'd1;
    end
    wire por_rst = !SYS_RSTN || (por_ctr != 14'd0);

    wire clk_sys;
    wire clk_ddr;
    wire clk_dq;
    wire pll_locked;

    ddr3_800_clocking u_clocking (
        .i_clk_50(SYS_CLK),
        .i_rst(por_rst),
        .o_clk_sys(clk_sys),
        .o_clk_ddr(clk_ddr),
        .o_clk_dq(clk_dq),
        .o_locked(pll_locked)
    );

    wire ctrl_clk = SYS_CLK;
    wire cmd_pin_clk = DRIVE_DDR3_COMMANDS ? clk_dq : ctrl_clk;

    reg [2:0] pll_locked_ctrl_sr = 3'b000;
    always @(posedge ctrl_clk) begin
        pll_locked_ctrl_sr <= {pll_locked_ctrl_sr[1:0], pll_locked};
    end
    wire pll_locked_ctrl = pll_locked_ctrl_sr[2];

    reg [2:0] pll_locked_cmd_sr = 3'b000;
    always @(posedge cmd_pin_clk) begin
        pll_locked_cmd_sr <= {pll_locked_cmd_sr[1:0], pll_locked};
    end
    wire pll_locked_cmd = pll_locked_cmd_sr[2];

    reg [4:0] ctrl_rst_sr = 5'b1_1111;
    always @(posedge ctrl_clk) begin
        if (por_rst || (DRIVE_DDR3_COMMANDS && !pll_locked_ctrl))
            ctrl_rst_sr <= 5'b1_1111;
        else
            ctrl_rst_sr <= {ctrl_rst_sr[3:0], 1'b0};
    end
    wire ctrl_rst = ctrl_rst_sr[4];

    reg [4:0] cmd_pin_rst_sr = 5'b1_1111;
    always @(posedge cmd_pin_clk) begin
        if (DRIVE_DDR3_COMMANDS && !pll_locked_cmd)
            cmd_pin_rst_sr <= 5'b1_1111;
        else
            cmd_pin_rst_sr <= {cmd_pin_rst_sr[3:0], 1'b0};
    end
    wire cmd_pin_rst = cmd_pin_rst_sr[4];

    reg [23:0] heartbeat = 24'd0;
    always @(posedge ctrl_clk) begin
        if (ctrl_rst)
            heartbeat <= 24'd0;
        else
            heartbeat <= heartbeat + 24'd1;
    end

    wire [31:0] host_to_fpga;
    wire        host_to_fpga_valid;
    reg [31:0] status_word = 32'd0;

    jtag_uart #(
        .WB_DATA_W(32),
        .WB_ADDR_W(2),
        .USER_CHAIN(1)
    ) u_jtag_uart (
        .i_clk(ctrl_clk),
        .i_rst(ctrl_rst),
        .i_wb_cyc(1'b0),
        .i_wb_stb(1'b0),
        .i_wb_we(1'b0),
        .i_wb_adr(2'b00),
        .i_wb_dat(32'd0),
        .i_wb_sel(4'h0),
        .o_wb_stall(),
        .o_wb_ack(),
        .o_wb_dat(),
        .o_wb_err(),
        .i_fpga_to_host(status_word),
        .o_host_to_fpga(host_to_fpga),
        .o_host_to_fpga_valid(host_to_fpga_valid)
    );

    wire                    jwb_cyc;
    wire                    jwb_stb;
    wire                    jwb_we;
    wire [JWB_ADDR_W-1:0]   jwb_adr;
    wire [WB_DATA_W-1:0]    jwb_dat_w;
    wire [WB_DATA_W/8-1:0]  jwb_sel;
    wire                    jwb_stall;
    wire                    jwb_ack;
    wire [WB_DATA_W-1:0]    jwb_dat_r;
    wire                    jwb_err;
    wire                    jwb_busy;
    wire                    jwb_last_ack;
    wire                    jwb_last_err;
    wire [JWB_ADDR_W-1:0]   jwb_addr_echo;
    wire [15:0]             jwb_addr_hi_echo;
    wire [WB_DATA_W-1:0]    jwb_data_echo;
    wire [WB_DATA_W-1:0]    jwb_rd_data;
    wire                    jwb_halt_others;
    wire [PHY_LANES-1:0]    jwb_cal_load_lane;
    wire [4:0]              jwb_cal_tap;
    wire                    jwb_cal_channel;
    wire                    jwb_phase_req;
    wire                    jwb_phase_inc;

    jtag_wb_master #(
        .WB_ADDR_W(JWB_ADDR_W),
        .WB_DATA_W(WB_DATA_W),
        .NUM_BYTE_LANES(PHY_LANES)
    ) u_jtag_wb_master (
        .i_clk(ctrl_clk),
        .i_rst(ctrl_rst),
        .i_cmd_word(host_to_fpga),
        .i_cmd_valid(host_to_fpga_valid),
        .o_wb_cyc(jwb_cyc),
        .o_wb_stb(jwb_stb),
        .o_wb_we(jwb_we),
        .o_wb_adr(jwb_adr),
        .o_wb_dat(jwb_dat_w),
        .o_wb_sel(jwb_sel),
        .i_wb_stall(jwb_stall),
        .i_wb_ack(jwb_ack),
        .i_wb_dat(jwb_dat_r),
        .i_wb_err(jwb_err),
        .o_busy(jwb_busy),
        .o_last_ack(jwb_last_ack),
        .o_last_err(jwb_last_err),
        .o_addr(jwb_addr_echo),
        .o_addr_hi(jwb_addr_hi_echo),
        .o_data(jwb_data_echo),
        .o_rd_data(jwb_rd_data),
        .o_halt_others(jwb_halt_others),
        .o_cal_load_lane(jwb_cal_load_lane),
        .o_cal_tap(jwb_cal_tap),
        .o_cal_channel(jwb_cal_channel),
        .o_phase_req(jwb_phase_req),
        .o_phase_inc(jwb_phase_inc)
    );

    wire bram_sel = !jwb_adr[14];
    wire ddr_sel = jwb_adr[14];

    wire bram_cyc = jwb_cyc && bram_sel;
    wire bram_stb = jwb_stb && bram_sel;
    wire bram_stall;
    wire bram_ack;
    wire bram_err;
    wire [31:0] bram_dat_r;

    wb_memory #(
        .WB_DATA_W(WB_DATA_W),
        .WB_ADDR_W(14)
    ) u_bram (
        .i_clk(ctrl_clk),
        .i_rst(ctrl_rst),
        .i_wb_cyc(bram_cyc),
        .i_wb_stb(bram_stb),
        .i_wb_we(jwb_we),
        .i_wb_adr(jwb_adr[13:0]),
        .i_wb_dat(jwb_dat_w),
        .i_wb_sel(jwb_sel),
        .o_wb_stall(bram_stall),
        .o_wb_ack(bram_ack),
        .o_wb_dat(bram_dat_r),
        .o_wb_err(bram_err)
    );

    wire ddr_cyc = jwb_cyc && ddr_sel;
    wire ddr_stb = jwb_stb && ddr_sel;
    wire ddr_stall;
    wire ddr_ack;
    wire ddr_err;
    wire [31:0] ddr_dat_r;
    wire [GLOBAL_WORD_ADDR_W-1:0] ddr_adr =
        {jwb_addr_hi_echo, jwb_adr[13:0]};

    assign jwb_stall = bram_sel ? bram_stall : ddr_stall;
    assign jwb_ack = bram_sel ? bram_ack : ddr_ack;
    assign jwb_err = bram_sel ? bram_err : ddr_err;
    assign jwb_dat_r = bram_sel ? bram_dat_r : ddr_dat_r;

    wire [CHANNELS-1:0] init_done;
    wire [CHANNELS-1:0] init_busy;
    wire [CHANNELS*5-1:0] init_state;
    wire init_all_done;
    wire [CHANNELS-1:0] sched_req_pending;
    wire [CHANNELS-1:0] refresh_req;
    wire [CHANNELS-1:0] refresh_ack;
    wire [CHANNELS-1:0] refresh_busy;
    wire [CHANNELS-1:0] refresh_late;
    wire [CHANNELS*16-1:0] refresh_count;
    wire [CHANNELS*(1 << BANK_BITS)-1:0] bank_busy;
    wire [CHANNELS*(1 << BANK_BITS)-1:0] bank_open;

    wire [CHANNELS-1:0] ddr_reset_n_w;
    wire [CHANNELS-1:0] ddr_cke_w;
    wire [CHANNELS-1:0] ddr_odt_w;
    wire [CHANNELS-1:0] ddr_cmd_valid_w;
    wire [CHANNELS-1:0] ddr_cs_n_w;
    wire [CHANNELS-1:0] ddr_ras_n_w;
    wire [CHANNELS-1:0] ddr_cas_n_w;
    wire [CHANNELS-1:0] ddr_we_n_w;
    wire [CHANNELS*BANK_BITS-1:0] ddr_ba_w;
    wire [CHANNELS*ADDR_BITS-1:0] ddr_addr_w;

    wire [CHANNELS-1:0] phy_wr_line_valid;
    wire [CHANNELS-1:0] phy_wr_line_ready;
    wire [CHANNELS*LINE_DATA_W-1:0] phy_wr_line_data;
    wire [CHANNELS*LINE_BYTES-1:0] phy_wr_line_mask;
    wire [CHANNELS-1:0] phy_rd_line_ready;
    wire [CHANNELS-1:0] phy_rd_line_valid;
    wire [CHANNELS*LINE_DATA_W-1:0] phy_rd_line_data;
    wire [CHANNELS-1:0] phy_rd_line_err;
    wire [CHANNELS-1:0] phy_start_write;
    wire [CHANNELS-1:0] phy_start_read;

    ddr3_ctrl_line #(
        .INIT_RESET_LOW_CYCLES(
            div_ceil(`DDR3_800_RESET_LOW_CYCLES, CTRL_DIV)),
        .INIT_RESET_CKE_CYCLES(
            div_ceil(`DDR3_800_RESET_CKE_CYCLES, CTRL_DIV)),
        .INIT_TXPR_CYCLES(div_ceil(`DDR3_800_TXPR_CYCLES, CTRL_DIV)),
        .INIT_TMRD_CYCLES(div_ceil(`DDR3_800_TMRD_CYCLES, CTRL_DIV)),
        .INIT_TMOD_CYCLES(div_ceil(`DDR3_800_TMOD_CYCLES, CTRL_DIV)),
        .INIT_TZQINIT_CYCLES(
            div_ceil(`DDR3_800_TZQINIT_CYCLES, CTRL_DIV)),
        .INIT_TRFC_CYCLES(div_ceil(`DDR3_800_TRFC_CYCLES, CTRL_DIV)),
        .INIT_TDLLK_CYCLES(div_ceil(`DDR3_800_TDLLK_CYCLES, CTRL_DIV)),
        .T_RP(div_ceil(`DDR3_800_TRP_CYCLES, CTRL_DIV)),
        .T_RCD(div_ceil(`DDR3_800_TRCD_CYCLES, CTRL_DIV)),
        .T_RAS(div_ceil(`DDR3_800_TRAS_CYCLES, CTRL_DIV)),
        .T_RC(div_ceil(`DDR3_800_TRC_CYCLES, CTRL_DIV)),
        .T_RFC(div_ceil(`DDR3_800_TRFC_CYCLES, CTRL_DIV)),
        .T_WR(div_ceil(`DDR3_800_TWR_CMD_CYCLES, CTRL_DIV)),
        .T_WTR(div_ceil(`DDR3_800_TWTR_CMD_CYCLES, CTRL_DIV)),
        .T_RTP(div_ceil(`DDR3_800_TRTP_CYCLES, CTRL_DIV)),
        .T_RRD(div_ceil(`DDR3_800_TRRD_CYCLES, CTRL_DIV)),
        .T_FAW(div_ceil(`DDR3_800_TFAW_CYCLES, CTRL_DIV)),
        .T_CCD(div_ceil(`DDR3_800_TCCD_CYCLES, CTRL_DIV)),
        .T_REFI(div_ceil(`DDR3_800_TREFI_CYCLES, CTRL_DIV)),
        .T_MARGIN(div_ceil(`DDR3_800_REFRESH_MARGIN_CYCLES, CTRL_DIV)),
        .PHY_HAS_BYTE_MASK(PHY_HAS_BYTE_MASK)
    ) u_ctrl (
        .i_clk(ctrl_clk),
        .i_rst(ctrl_rst),
        .i_init_start(1'b1),
        .i_wb_cyc(ddr_cyc),
        .i_wb_stb(ddr_stb),
        .i_wb_we(jwb_we),
        .i_wb_dat(jwb_dat_w),
        .i_wb_sel(jwb_sel),
        .i_wb_adr(ddr_adr),
        .o_wb_stall(ddr_stall),
        .o_wb_ack(ddr_ack),
        .o_wb_err(ddr_err),
        .o_wb_dat(ddr_dat_r),
        .o_init_done(init_done),
        .o_init_busy(init_busy),
        .o_init_state(init_state),
        .o_init_all_done(init_all_done),
        .o_sched_req_pending(sched_req_pending),
        .o_refresh_req(refresh_req),
        .o_refresh_ack(refresh_ack),
        .o_refresh_busy(refresh_busy),
        .o_refresh_late(refresh_late),
        .o_refresh_count(refresh_count),
        .o_bank_busy(bank_busy),
        .o_bank_open(bank_open),
        .o_ddr_reset_n(ddr_reset_n_w),
        .o_ddr_cke(ddr_cke_w),
        .o_ddr_odt(ddr_odt_w),
        .o_ddr_cmd_valid(ddr_cmd_valid_w),
        .o_ddr_cs_n(ddr_cs_n_w),
        .o_ddr_ras_n(ddr_ras_n_w),
        .o_ddr_cas_n(ddr_cas_n_w),
        .o_ddr_we_n(ddr_we_n_w),
        .o_ddr_ba(ddr_ba_w),
        .o_ddr_addr(ddr_addr_w),
        .o_phy_wr_line_valid(phy_wr_line_valid),
        .i_phy_wr_line_ready(phy_wr_line_ready),
        .o_phy_wr_line_data(phy_wr_line_data),
        .o_phy_wr_line_mask(phy_wr_line_mask),
        .o_phy_start_write(phy_start_write),
        .o_phy_start_read(phy_start_read),
        .o_phy_rd_line_ready(phy_rd_line_ready),
        .i_phy_rd_line_valid(phy_rd_line_valid),
        .i_phy_rd_line_data(phy_rd_line_data),
        .i_phy_rd_line_err(phy_rd_line_err)
    );

    wire [CHANNELS*32-1:0] loop_wr_count;
    wire [CHANNELS*32-1:0] loop_rd_count;
    wire [CHANNELS*LINE_ADDR_W-1:0] loop_last_line_addr;
    wire [CHANNELS-1:0] phy_loop_error;

    genvar ch;
    generate
        if (USE_LINE_LANE_PHY) begin : gen_line_lane_phy_loopback
            wire [CHANNELS-1:0] line_lane_channel_busy;
            wire [CHANNELS-1:0] line_lane_channel_error;
            wire [CHANNELS-1:0] line_lane_lane_error_any;
            wire [PHY_LANES-1:0] line_lane_lane_busy;
            wire [PHY_LANES-1:0] line_lane_lane_error;
            wire [PHY_LANES-1:0] line_lane_dq_oe;
            wire [PHY_LANES-1:0] line_lane_dm_oe;
            wire [PHY_LANES-1:0] line_lane_dqs_oe;
            wire [PHY_LANES*8-1:0] line_lane_dq_rise;
            wire [PHY_LANES*8-1:0] line_lane_dq_fall;
            wire [PHY_LANES-1:0] line_lane_dm_rise;
            wire [PHY_LANES-1:0] line_lane_dm_fall;
            wire [PHY_LANES-1:0] line_lane_dqs_rise;
            wire [PHY_LANES-1:0] line_lane_dqs_fall;
            wire [PHY_LANES-1:0] line_lane_rd_capturing;
            wire [PHY_LANES-1:0] line_lane_rd_sample_valid;
            wire [PHY_LANES*8-1:0] line_lane_dq_in_rise;
            wire [PHY_LANES*8-1:0] line_lane_dq_in_fall;
            wire [CHANNELS-1:0] pinpair_loop_error;

            ddr3_line_lane_phy #(
                .CHANNELS(CHANNELS),
                .LANES(LANES)
            ) u_line_lane_phy (
                .i_clk(ctrl_clk),
                .i_rst(ctrl_rst),
                .i_wr_line_valid(phy_wr_line_valid),
                .o_wr_line_ready(phy_wr_line_ready),
                .i_wr_line_data(phy_wr_line_data),
                .i_wr_line_mask(phy_wr_line_mask),
                .i_start_write(phy_start_write),
                .i_start_read(phy_start_read),
                .i_rd_line_ready(phy_rd_line_ready),
                .o_rd_line_valid(phy_rd_line_valid),
                .o_rd_line_data(phy_rd_line_data),
                .o_rd_line_err(phy_rd_line_err),
                .o_channel_busy(line_lane_channel_busy),
                .o_channel_error(line_lane_channel_error),
                .o_lane_busy(line_lane_lane_busy),
                .o_lane_error(line_lane_lane_error),
                .o_dq_oe(line_lane_dq_oe),
                .o_dm_oe(line_lane_dm_oe),
                .o_dqs_oe(line_lane_dqs_oe),
                .o_dq_rise(line_lane_dq_rise),
                .o_dq_fall(line_lane_dq_fall),
                .o_dm_rise(line_lane_dm_rise),
                .o_dm_fall(line_lane_dm_fall),
                .o_dqs_rise(line_lane_dqs_rise),
                .o_dqs_fall(line_lane_dqs_fall),
                .o_rd_capturing(line_lane_rd_capturing),
                .i_rd_sample_valid(line_lane_rd_sample_valid),
                .i_dq_rise(line_lane_dq_in_rise),
                .i_dq_fall(line_lane_dq_in_fall)
            );

            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_lane_error
                assign line_lane_lane_error_any[ch] =
                    |line_lane_lane_error[ch*LANES +: LANES];
            end

            ddr3_pinpair_loopback_phy #(
                .CHANNELS(CHANNELS),
                .LANES(LANES)
            ) u_pinpair_loop (
                .i_clk(ctrl_clk),
                .i_rst(ctrl_rst),
                .i_cmd_valid(ddr_cmd_valid_w),
                .i_cs_n(ddr_cs_n_w),
                .i_ras_n(ddr_ras_n_w),
                .i_cas_n(ddr_cas_n_w),
                .i_we_n(ddr_we_n_w),
                .i_ba(ddr_ba_w),
                .i_addr(ddr_addr_w),
                .i_dq_oe(line_lane_dq_oe),
                .i_dm_oe(line_lane_dm_oe),
                .i_dqs_oe(line_lane_dqs_oe),
                .i_dq_rise(line_lane_dq_rise),
                .i_dq_fall(line_lane_dq_fall),
                .i_dm_rise(line_lane_dm_rise),
                .i_dm_fall(line_lane_dm_fall),
                .i_dqs_rise(line_lane_dqs_rise),
                .i_dqs_fall(line_lane_dqs_fall),
                .i_rd_capturing(line_lane_rd_capturing),
                .o_rd_sample_valid(line_lane_rd_sample_valid),
                .o_dq_rise(line_lane_dq_in_rise),
                .o_dq_fall(line_lane_dq_in_fall),
                .o_error(pinpair_loop_error),
                .o_wr_count(loop_wr_count),
                .o_rd_count(loop_rd_count),
                .o_last_line_addr(loop_last_line_addr)
            );

            assign phy_loop_error =
                pinpair_loop_error |
                line_lane_channel_error |
                line_lane_lane_error_any;

            wire _line_lane_unused =
                &{1'b0, line_lane_channel_busy, line_lane_lane_busy, 1'b0};
        end else if (USE_LINE_TO_LANES) begin : gen_lane_loopback
            wire [PHY_LANES-1:0] lane_wr_valid;
            wire [PHY_LANES-1:0] lane_wr_ready;
            wire [PHY_LANES*8-1:0] lane_wr_data;
            wire [PHY_LANES-1:0] lane_wr_mask;
            wire [PHY_LANES-1:0] lane_wr_last;
            wire [PHY_LANES-1:0] lane_rd_ready;
            wire [PHY_LANES-1:0] lane_rd_valid;
            wire [PHY_LANES*8-1:0] lane_rd_data;

            ddr3_line_to_lanes #(
                .CHANNELS(CHANNELS),
                .LANES(LANES)
            ) u_line_to_lanes (
                .i_clk(ctrl_clk),
                .i_rst(ctrl_rst),
                .i_wr_line_valid(phy_wr_line_valid),
                .o_wr_line_ready(phy_wr_line_ready),
                .i_wr_line_data(phy_wr_line_data),
                .i_wr_line_mask(phy_wr_line_mask),
                .i_rd_line_ready(phy_rd_line_ready),
                .o_rd_line_valid(phy_rd_line_valid),
                .o_rd_line_data(phy_rd_line_data),
                .o_rd_line_err(phy_rd_line_err),
                .o_lane_wr_valid(lane_wr_valid),
                .i_lane_wr_ready(lane_wr_ready),
                .o_lane_wr_data(lane_wr_data),
                .o_lane_wr_mask(lane_wr_mask),
                .o_lane_wr_last(lane_wr_last),
                .o_lane_rd_ready(lane_rd_ready),
                .i_lane_rd_valid(lane_rd_valid),
                .i_lane_rd_data(lane_rd_data)
            );

            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_lane_loop
                localparam integer PHY_BASE = ch * LANES;
                localparam integer PHY_DATA_W = LANES * 8;

                ddr3_ctrl_loopback_phy #(
                    .LANES(LANES)
                ) u_loop (
                    .i_clk(ctrl_clk),
                    .i_rst(ctrl_rst),
                    .i_cmd_valid(ddr_cmd_valid_w[ch]),
                    .i_cs_n(ddr_cs_n_w[ch]),
                    .i_ras_n(ddr_ras_n_w[ch]),
                    .i_cas_n(ddr_cas_n_w[ch]),
                    .i_we_n(ddr_we_n_w[ch]),
                    .i_ba(ddr_ba_w[ch*BANK_BITS +: BANK_BITS]),
                    .i_addr(ddr_addr_w[ch*ADDR_BITS +: ADDR_BITS]),
                    .i_phy_wr_valid(lane_wr_valid[PHY_BASE +: LANES]),
                    .o_phy_wr_ready(lane_wr_ready[PHY_BASE +: LANES]),
                    .i_phy_wr_data(lane_wr_data[PHY_BASE*8 +: PHY_DATA_W]),
                    .i_phy_wr_mask(lane_wr_mask[PHY_BASE +: LANES]),
                    .i_phy_wr_last(lane_wr_last[PHY_BASE +: LANES]),
                    .i_phy_rd_ready(lane_rd_ready[PHY_BASE +: LANES]),
                    .o_phy_rd_valid(lane_rd_valid[PHY_BASE +: LANES]),
                    .o_phy_rd_data(lane_rd_data[PHY_BASE*8 +: PHY_DATA_W]),
                    .o_wr_count(loop_wr_count[ch*32 +: 32]),
                    .o_rd_count(loop_rd_count[ch*32 +: 32]),
                    .o_last_line_addr(
                        loop_last_line_addr[ch*LINE_ADDR_W +: LINE_ADDR_W])
                );
            end
            assign phy_loop_error = {CHANNELS{1'b0}};
        end else begin : gen_line_loopback
            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_loopback
                ddr3_line_loopback_phy #(
                    .LANES(LANES)
                ) u_loop (
                    .i_clk(ctrl_clk),
                    .i_rst(ctrl_rst),
                    .i_cmd_valid(ddr_cmd_valid_w[ch]),
                    .i_cs_n(ddr_cs_n_w[ch]),
                    .i_ras_n(ddr_ras_n_w[ch]),
                    .i_cas_n(ddr_cas_n_w[ch]),
                    .i_we_n(ddr_we_n_w[ch]),
                    .i_ba(ddr_ba_w[ch*BANK_BITS +: BANK_BITS]),
                    .i_addr(ddr_addr_w[ch*ADDR_BITS +: ADDR_BITS]),
                    .i_wr_line_valid(phy_wr_line_valid[ch]),
                    .o_wr_line_ready(phy_wr_line_ready[ch]),
                    .i_wr_line_data(
                        phy_wr_line_data[ch*LINE_DATA_W +: LINE_DATA_W]),
                    .i_wr_line_mask(
                        phy_wr_line_mask[ch*LINE_BYTES +: LINE_BYTES]),
                    .i_rd_line_ready(phy_rd_line_ready[ch]),
                    .o_rd_line_valid(phy_rd_line_valid[ch]),
                    .o_rd_line_data(
                        phy_rd_line_data[ch*LINE_DATA_W +: LINE_DATA_W]),
                    .o_rd_line_err(phy_rd_line_err[ch]),
                    .o_wr_count(loop_wr_count[ch*32 +: 32]),
                    .o_rd_count(loop_rd_count[ch*32 +: 32]),
                    .o_last_line_addr(
                        loop_last_line_addr[ch*LINE_ADDR_W +: LINE_ADDR_W])
                );
            end
            assign phy_loop_error = {CHANNELS{1'b0}};
        end
    endgenerate

    wire [CHANNELS-1:0] board_reset_n;
    wire [CHANNELS-1:0] board_cke;
    wire [CHANNELS-1:0] board_odt;
    wire [CHANNELS-1:0] board_cmd_valid;
    wire [CHANNELS-1:0] board_cs_n;
    wire [CHANNELS-1:0] board_ras_n;
    wire [CHANNELS-1:0] board_cas_n;
    wire [CHANNELS-1:0] board_we_n;
    wire [CHANNELS*BANK_BITS-1:0] board_ba;
    wire [CHANNELS*ADDR_BITS-1:0] board_addr;

    generate
        if (DRIVE_DDR3_COMMANDS) begin : gen_cmd_drive
            for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_cmd_cdc
                ddr3_cmd_cdc_7series #(
                    .ADDR_BITS(ADDR_BITS),
                    .BANK_BITS(BANK_BITS)
                ) u_cmd_cdc (
                    .i_clk_ctrl(ctrl_clk),
                    .i_rst_ctrl(ctrl_rst),
                    .i_clk_dq(clk_dq),
                    .i_rst_dq(cmd_pin_rst),
                    .i_reset_n(ddr_reset_n_w[ch]),
                    .i_cke(ddr_cke_w[ch]),
                    .i_odt(ddr_odt_w[ch]),
                    .i_cmd_valid(ddr_cmd_valid_w[ch]),
                    .i_cs_n(ddr_cs_n_w[ch]),
                    .i_ras_n(ddr_ras_n_w[ch]),
                    .i_cas_n(ddr_cas_n_w[ch]),
                    .i_we_n(ddr_we_n_w[ch]),
                    .i_ba(ddr_ba_w[ch*BANK_BITS +: BANK_BITS]),
                    .i_addr(ddr_addr_w[ch*ADDR_BITS +: ADDR_BITS]),
                    .o_reset_n(board_reset_n[ch]),
                    .o_cke(board_cke[ch]),
                    .o_odt(board_odt[ch]),
                    .o_cmd_valid(board_cmd_valid[ch]),
                    .o_cs_n(board_cs_n[ch]),
                    .o_ras_n(board_ras_n[ch]),
                    .o_cas_n(board_cas_n[ch]),
                    .o_we_n(board_we_n[ch]),
                    .o_ba(board_ba[ch*BANK_BITS +: BANK_BITS]),
                    .o_addr(board_addr[ch*ADDR_BITS +: ADDR_BITS])
                );
            end
        end else begin : gen_cmd_safe
            assign board_reset_n = {CHANNELS{1'b0}};
            assign board_cke = {CHANNELS{1'b0}};
            assign board_odt = {CHANNELS{1'b0}};
            assign board_cmd_valid = {CHANNELS{1'b1}};
            assign board_cs_n = {CHANNELS{1'b1}};
            assign board_ras_n = {CHANNELS{1'b1}};
            assign board_cas_n = {CHANNELS{1'b1}};
            assign board_we_n = {CHANNELS{1'b1}};
            assign board_ba = {(CHANNELS*BANK_BITS){1'b0}};
            assign board_addr = {(CHANNELS*ADDR_BITS){1'b0}};
        end
    endgenerate

    ddr3_cmd_pins_7series #(
        .ADDR_BITS(ADDR_BITS),
        .BANK_BITS(BANK_BITS)
    ) u_ch0_cmd (
        .i_clk_dq(cmd_pin_clk),
        .i_rst(cmd_pin_rst),
        .i_reset_n(board_reset_n[0]),
        .i_cke(board_cke[0]),
        .i_odt(board_odt[0]),
        .i_cmd_valid(board_cmd_valid[0]),
        .i_cs_n(board_cs_n[0]),
        .i_ras_n(board_ras_n[0]),
        .i_cas_n(board_cas_n[0]),
        .i_we_n(board_we_n[0]),
        .i_ba(board_ba[0*BANK_BITS +: BANK_BITS]),
        .i_addr(board_addr[0*ADDR_BITS +: ADDR_BITS]),
        .o_reset_n(ddr3_reset_n),
        .o_cke(ddr3_cke),
        .o_odt(ddr3_odt),
        .o_cs_n(ddr3_cs_n),
        .o_ras_n(ddr3_ras_n),
        .o_cas_n(ddr3_cas_n),
        .o_we_n(ddr3_we_n),
        .o_ba(ddr3_ba),
        .o_addr(ddr3_addr)
    );

    ddr3_cmd_pins_7series #(
        .ADDR_BITS(ADDR_BITS),
        .BANK_BITS(BANK_BITS)
    ) u_ch1_cmd (
        .i_clk_dq(cmd_pin_clk),
        .i_rst(cmd_pin_rst),
        .i_reset_n(board_reset_n[1]),
        .i_cke(board_cke[1]),
        .i_odt(board_odt[1]),
        .i_cmd_valid(board_cmd_valid[1]),
        .i_cs_n(board_cs_n[1]),
        .i_ras_n(board_ras_n[1]),
        .i_cas_n(board_cas_n[1]),
        .i_we_n(board_we_n[1]),
        .i_ba(board_ba[1*BANK_BITS +: BANK_BITS]),
        .i_addr(board_addr[1*ADDR_BITS +: ADDR_BITS]),
        .o_reset_n(ddr3_ch1_reset_n),
        .o_cke(ddr3_ch1_cke),
        .o_odt(ddr3_ch1_odt),
        .o_cs_n(ddr3_ch1_cs_n),
        .o_ras_n(ddr3_ch1_ras_n),
        .o_cas_n(ddr3_ch1_cas_n),
        .o_we_n(ddr3_ch1_we_n),
        .o_ba(ddr3_ch1_ba),
        .o_addr(ddr3_ch1_addr)
    );

    ddr3_ck_out_7series u_ch0_ck (
        .i_clk_ddr(clk_ddr),
        .i_rst(1'b0),
        .o_ck_p(ddr3_ck_p),
        .o_ck_n(ddr3_ck_n)
    );

    ddr3_ck_out_7series u_ch1_ck (
        .i_clk_ddr(clk_ddr),
        .i_rst(1'b0),
        .o_ck_p(ddr3_ch1_ck_p),
        .o_ck_n(ddr3_ch1_ck_n)
    );

    ddr3_hiz_lanes_7series u_ch0_hiz (
        .io_dq(ddr3_dq),
        .io_dqs_p(ddr3_dqs_p),
        .io_dqs_n(ddr3_dqs_n)
    );

    ddr3_hiz_lanes_7series u_ch1_hiz (
        .io_dq(ddr3_ch1_dq),
        .io_dqs_p(ddr3_ch1_dqs_p),
        .io_dqs_n(ddr3_ch1_dqs_n)
    );

    wire clk_ref_alive;
    wire clk_ref_bit;
    wire [5:0] clk_ref_ticks;
    wire clk_sys_alive;
    wire clk_sys_bit;
    wire [5:0] clk_sys_ticks;
    wire clk_ddr_alive;
    wire clk_ddr_bit;
    wire [5:0] clk_ddr_ticks;
    wire clk_dq_alive;
    wire clk_dq_bit;
    wire [5:0] clk_dq_ticks;

    clk_liveness u_ref_live (
        .i_clk(SYS_CLK),
        .i_clk_obs(ctrl_clk),
        .o_alive(clk_ref_alive),
        .o_synced_bit(clk_ref_bit),
        .o_ticks_lo(clk_ref_ticks)
    );

    clk_liveness u_sys_live (
        .i_clk(clk_sys),
        .i_clk_obs(ctrl_clk),
        .o_alive(clk_sys_alive),
        .o_synced_bit(clk_sys_bit),
        .o_ticks_lo(clk_sys_ticks)
    );

    clk_liveness u_ddr_live (
        .i_clk(clk_ddr),
        .i_clk_obs(ctrl_clk),
        .o_alive(clk_ddr_alive),
        .o_synced_bit(clk_ddr_bit),
        .o_ticks_lo(clk_ddr_ticks)
    );

    clk_liveness u_dq_live (
        .i_clk(clk_dq),
        .i_clk_obs(ctrl_clk),
        .o_alive(clk_dq_alive),
        .o_synced_bit(clk_dq_bit),
        .o_ticks_lo(clk_dq_ticks)
    );

    wire refresh_any_late = |refresh_late;
    wire phy_any_error = |phy_loop_error;
    wire [31:0] status_flags = {
        16'hB07E,
        init_all_done,       // loopback "cal done"
        phy_any_error,       // abstract PHY loop error
        2'b00,
        init_all_done,
        1'b0,
        4'b0000,
        pll_locked,
        1'b1,                // no IDELAYCTRL in this image
        ctrl_rst,
        1'b0,
        phy_any_error,
        1'b1                 // target=DDR3-controller path
    };

    wire [31:0] state_bits = {
        6'd0,
        init_state[1*5 +: 5],
        init_state[0*5 +: 5],
        refresh_late,
        refresh_busy,
        refresh_req,
        heartbeat[9:0]
    };

    wire [31:0] clk_ref_status = {16'hC150, clk_ref_alive, clk_ref_bit, 8'd0,
                                  clk_ref_ticks};
    wire [31:0] clk_sys_status = {16'hC151, clk_sys_alive, clk_sys_bit, 8'd0,
                                  clk_sys_ticks};
    wire [31:0] clk_ddr_status = {16'hC152, clk_ddr_alive, clk_ddr_bit, 8'd0,
                                  clk_ddr_ticks};
    wire [31:0] clk_dq_status = {16'hC153, clk_dq_alive, clk_dq_bit, 8'd0,
                                 clk_dq_ticks};

    wire [31:0] loop_total =
        loop_wr_count[0 +: 32] + loop_wr_count[32 +: 32] +
        loop_rd_count[0 +: 32] + loop_rd_count[32 +: 32];

    always @(*) begin
        case (host_to_fpga[7:0])
            8'h00: status_word = status_flags;
            8'h01: status_word = state_bits;
            8'h02: status_word = {8'h00, heartbeat};
            8'h03: status_word = loop_total;
            8'h04: status_word = {16'hAB04, 12'd0,
                                   (USE_LINE_LANE_PHY != 0),
                                   (USE_LINE_TO_LANES != 0),
                                   (PHY_HAS_BYTE_MASK != 0),
                                   (DRIVE_DDR3_COMMANDS != 0)};
            8'h08: status_word = loop_rd_count[0 +: 32] + loop_rd_count[32 +: 32];
            8'h10: status_word = {16'hAB10, 12'd0,
                                   jwb_busy, jwb_last_ack,
                                   jwb_last_err, jwb_halt_others};
            8'h11: status_word = {17'd0, jwb_addr_echo};
            8'h12: status_word = jwb_data_echo;
            8'h13: status_word = jwb_rd_data;
            8'h15: status_word = clk_sys_status;
            8'h16: status_word = clk_ddr_status;
            8'h17: status_word = clk_dq_status;
            8'h18: status_word = clk_ref_status;
            8'h1A: status_word = {16'hAB1A, jwb_addr_hi_echo};
            8'h1C: status_word = {16'hAB1C, 8'd0,
                                   ddr_cyc, ddr_stb, jwb_we, ddr_ack,
                                   ddr_stall, ddr_err, |phy_start_write,
                                   |phy_start_read};
            8'h20: status_word = loop_wr_count[0 +: 32];
            8'h21: status_word = loop_wr_count[32 +: 32];
            8'h22: status_word = loop_rd_count[0 +: 32];
            8'h23: status_word = loop_rd_count[32 +: 32];
            8'h24: status_word = {7'd0, loop_last_line_addr[0 +: LINE_ADDR_W]};
            8'h25: status_word = {7'd0,
                                   loop_last_line_addr[LINE_ADDR_W +: LINE_ADDR_W]};
            8'h30: status_word = {16'hF0C0, refresh_count[0*16 +: 16]};
            8'h31: status_word = {16'hF0C1, refresh_count[1*16 +: 16]};
            8'hFE: status_word = GATE_VERSION;
            8'hFF: status_word = host_to_fpga;
            default: status_word = {DEFAULT_MAGIC, host_to_fpga[7:0]};
        endcase
    end

    assign led_3bits_tri_o[0] = heartbeat[23];
    assign led_3bits_tri_o[1] = init_all_done;
    assign led_3bits_tri_o[2] =
        !pll_locked || refresh_any_late || jwb_last_err || phy_any_error;

    wire _unused = &{1'b0, init_done, init_busy, sched_req_pending,
                     refresh_ack, bank_busy, bank_open, jwb_cal_load_lane,
                     jwb_cal_tap, jwb_cal_channel, jwb_phase_req,
                     jwb_phase_inc, phy_wr_line_valid, phy_rd_line_valid,
                     1'b0};
endmodule

`default_nettype wire

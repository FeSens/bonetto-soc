// DDR3-800 controller-loopback image for YPCB-00338.
//
// This is the next hardware gate after the BRAM-only JTAG/Wishbone proof and
// the full-pin DDR3 init probe. It routes host JTAG/Wishbone traffic through
// the clean dual-channel DDR3 controller, scheduler, and BL8 line packetizer,
// while a small internal loopback PHY returns read data.
//
// The controller loopback intentionally runs in the 50 MHz board-clock domain.
// That keeps this debug image timing-honest in openXC7 while the real DDR PHY is
// still under construction. The full DDR3 board pinout remains constrained, CK
// is generated, and DQ/DQS are high-Z, but the external DDR3 devices are held in
// reset. Passing this image proves the live JTAG/Wishbone/controller fabric path;
// it does not validate external command timing, DQ/DQS timing, or real storage.

`default_nettype none

`include "ddr3_params.vh"

module top_ddr3_ctrl_loopback (
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
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer JWB_ADDR_W = 15;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer ADDR_BITS = `DDR3_ADDR_BITS;
    localparam integer BANK_BITS = `DDR3_BANK_BITS;
    localparam integer LINE_ADDR_W =
        `DDR3_BANK_BITS + `DDR3_ROW_BITS + (`DDR3_COL_BITS - 3);
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer PHY_DATA_W = LANES * 8;

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
        .o_clk_idelay_ref(),
        .o_locked(pll_locked)
    );

    wire ctrl_clk = SYS_CLK;
    wire ctrl_rst = por_rst;

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

    wire [CHANNELS-1:0] line_done;
    wire [CHANNELS-1:0] line_rd_valid;
    wire [PHY_LANES-1:0] phy_wr_valid;
    wire [PHY_LANES-1:0] phy_wr_ready;
    wire [PHY_LANES*8-1:0] phy_wr_data;
    wire [PHY_LANES-1:0] phy_wr_mask;
    wire [PHY_LANES-1:0] phy_wr_last;
    wire [PHY_LANES-1:0] phy_rd_ready;
    wire [PHY_LANES-1:0] phy_rd_valid;
    wire [PHY_LANES*8-1:0] phy_rd_data;

    ddr3_ctrl u_ctrl (
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
        .o_line_done(line_done),
        .o_line_rd_valid(line_rd_valid),
        .o_phy_wr_valid(phy_wr_valid),
        .i_phy_wr_ready(phy_wr_ready),
        .o_phy_wr_data(phy_wr_data),
        .o_phy_wr_mask(phy_wr_mask),
        .o_phy_wr_last(phy_wr_last),
        .o_phy_rd_ready(phy_rd_ready),
        .i_phy_rd_valid(phy_rd_valid),
        .i_phy_rd_data(phy_rd_data)
    );

    wire [CHANNELS*32-1:0] loop_wr_count;
    wire [CHANNELS*32-1:0] loop_rd_count;
    wire [CHANNELS*LINE_ADDR_W-1:0] loop_last_line_addr;

    genvar ch;
    generate
        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_loopback
            localparam integer PHY_BASE = ch * LANES;
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
                .i_phy_wr_valid(phy_wr_valid[PHY_BASE +: LANES]),
                .o_phy_wr_ready(phy_wr_ready[PHY_BASE +: LANES]),
                .i_phy_wr_data(phy_wr_data[PHY_BASE*8 +: PHY_DATA_W]),
                .i_phy_wr_mask(phy_wr_mask[PHY_BASE +: LANES]),
                .i_phy_wr_last(phy_wr_last[PHY_BASE +: LANES]),
                .i_phy_rd_ready(phy_rd_ready[PHY_BASE +: LANES]),
                .o_phy_rd_valid(phy_rd_valid[PHY_BASE +: LANES]),
                .o_phy_rd_data(phy_rd_data[PHY_BASE*8 +: PHY_DATA_W]),
                .o_wr_count(loop_wr_count[ch*32 +: 32]),
                .o_rd_count(loop_rd_count[ch*32 +: 32]),
                .o_last_line_addr(loop_last_line_addr[ch*LINE_ADDR_W +: LINE_ADDR_W])
            );
        end
    endgenerate

    ddr3_cmd_pins_7series u_ch0_cmd (
        .i_clk_dq(ctrl_clk),
        .i_rst(ctrl_rst),
        .i_reset_n(1'b0),
        .i_cke(1'b0),
        .i_odt(1'b0),
        .i_cmd_valid(1'b1),
        .i_cs_n(1'b1),
        .i_ras_n(1'b1),
        .i_cas_n(1'b1),
        .i_we_n(1'b1),
        .i_ba({BANK_BITS{1'b0}}),
        .i_addr({ADDR_BITS{1'b0}}),
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

    ddr3_cmd_pins_7series u_ch1_cmd (
        .i_clk_dq(ctrl_clk),
        .i_rst(ctrl_rst),
        .i_reset_n(1'b0),
        .i_cke(1'b0),
        .i_odt(1'b0),
        .i_cmd_valid(1'b1),
        .i_cs_n(1'b1),
        .i_ras_n(1'b1),
        .i_cas_n(1'b1),
        .i_we_n(1'b1),
        .i_ba({BANK_BITS{1'b0}}),
        .i_addr({ADDR_BITS{1'b0}}),
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
        .i_rst(ctrl_rst),
        .o_ck_p(ddr3_ck_p),
        .o_ck_n(ddr3_ck_n)
    );

    ddr3_ck_out_7series u_ch1_ck (
        .i_clk_ddr(clk_ddr),
        .i_rst(ctrl_rst),
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
    wire [31:0] status_flags = {
        16'hB07E,
        init_all_done,       // loopback "cal done"
        1'b0,                // no loopback cal error
        2'b00,
        init_all_done,
        1'b0,
        4'b0000,
        pll_locked,
        1'b1,                // no IDELAYCTRL in this image
        ctrl_rst,
        1'b0,
        1'b0,
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
            8'h04: status_word = 32'd0;
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
                                   ddr_stall, ddr_err, |line_done,
                                   |line_rd_valid};
            8'h20: status_word = loop_wr_count[0 +: 32];
            8'h21: status_word = loop_wr_count[32 +: 32];
            8'h22: status_word = loop_rd_count[0 +: 32];
            8'h23: status_word = loop_rd_count[32 +: 32];
            8'h24: status_word = {7'd0, loop_last_line_addr[0 +: LINE_ADDR_W]};
            8'h25: status_word = {7'd0,
                                   loop_last_line_addr[LINE_ADDR_W +: LINE_ADDR_W]};
            8'h30: status_word = {16'hF0C0, refresh_count[0*16 +: 16]};
            8'h31: status_word = {16'hF0C1, refresh_count[1*16 +: 16]};
            8'hFE: status_word = 32'hB07E_0D81;
            8'hFF: status_word = host_to_fpga;
            default: status_word = {24'hD3AD81, host_to_fpga[7:0]};
        endcase
    end

    assign led_3bits_tri_o[0] = heartbeat[23];
    assign led_3bits_tri_o[1] = init_all_done;
    assign led_3bits_tri_o[2] = !pll_locked || refresh_any_late || jwb_last_err;

    wire _unused = &{1'b0, init_done, init_busy, sched_req_pending,
                     refresh_ack, bank_busy, bank_open, jwb_cal_load_lane,
                     jwb_cal_tap, jwb_cal_channel, jwb_phase_req,
                     jwb_phase_inc, ddr_reset_n_w, ddr_cke_w, ddr_odt_w,
                     1'b0};
endmodule

`default_nettype wire

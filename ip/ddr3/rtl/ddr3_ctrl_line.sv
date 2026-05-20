// Init-gated dual-channel DDR3 controller with a line-level PHY boundary.
//
// This module is the intended integration point for a real 7-series DQ/DQS PHY.
// The scheduler still owns command timing, while the bus bridge exposes full
// BL8 write/read lines so the PHY can serialize data in the DDR clock domain.

`default_nettype none

`include "ddr3_params.vh"

module ddr3_ctrl_line #(
    parameter integer LANES = 8,
    parameter integer WB_DATA_W = 32,
    parameter integer ROW_BITS = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer COL_BITS = `DDR3_COL_BITS,
    parameter integer ADDR_BITS = `DDR3_ADDR_BITS,
    parameter integer PHY_HAS_BYTE_MASK = 1,
    localparam integer CHANNELS = 2,
    parameter integer LINE_ADDR_W = ROW_BITS + BANK_BITS + (COL_BITS - 3),
    parameter integer LOCAL_LINE_ADDR_W = LINE_ADDR_W,
    parameter integer GLOBAL_LINE_ADDR_W = LOCAL_LINE_ADDR_W + 1,
    localparam integer LINE_BYTES = LANES * 8,
    localparam integer LINE_DATA_W = LINE_BYTES * 8,
    parameter integer INIT_RESET_LOW_CYCLES = `DDR3_800_RESET_LOW_CYCLES,
    parameter integer INIT_RESET_CKE_CYCLES = `DDR3_800_RESET_CKE_CYCLES,
    parameter integer INIT_TXPR_CYCLES = `DDR3_800_TXPR_CYCLES,
    parameter integer INIT_TMRD_CYCLES = `DDR3_800_TMRD_CYCLES,
    parameter integer INIT_TMOD_CYCLES = `DDR3_800_TMOD_CYCLES,
    parameter integer INIT_TZQINIT_CYCLES = `DDR3_800_TZQINIT_CYCLES,
    parameter integer INIT_TRFC_CYCLES = `DDR3_800_TRFC_CYCLES,
    parameter integer INIT_TDLLK_CYCLES = `DDR3_800_TDLLK_CYCLES,
    parameter [ADDR_BITS-1:0] INIT_MR0 = `DDR3_MR0_DDR800,
    parameter [ADDR_BITS-1:0] INIT_MR1 = `DDR3_MR1_DDR800,
    parameter [ADDR_BITS-1:0] INIT_MR2 = `DDR3_MR2_DDR800,
    parameter [ADDR_BITS-1:0] INIT_MR3 = `DDR3_MR3_DDR800,
    parameter integer T_RP = `DDR3_800_TRP_CYCLES,
    parameter integer T_RCD = `DDR3_800_TRCD_CYCLES,
    parameter integer T_RAS = `DDR3_800_TRAS_CYCLES,
    parameter integer T_RC = `DDR3_800_TRC_CYCLES,
    parameter integer T_RFC = `DDR3_800_TRFC_CYCLES,
    parameter integer T_WR = `DDR3_800_TWR_CMD_CYCLES,
    parameter integer T_WTR = `DDR3_800_TWTR_CMD_CYCLES,
    parameter integer T_RTP = `DDR3_800_TRTP_CYCLES,
    parameter integer T_RRD = `DDR3_800_TRRD_CYCLES,
    parameter integer T_FAW = `DDR3_800_TFAW_CYCLES,
    parameter integer T_CCD = `DDR3_800_TCCD_CYCLES,
    parameter integer T_REFI = `DDR3_800_TREFI_CYCLES,
    parameter integer T_MARGIN = `DDR3_800_REFRESH_MARGIN_CYCLES
) (
    input  wire i_clk,
    input  wire i_rst,
    input  wire i_init_start,

    input  wire                  i_wb_cyc,
    input  wire                  i_wb_stb,
    input  wire                  i_wb_we,
    input  wire [WB_DATA_W-1:0]  i_wb_dat,
    input  wire [WB_DATA_W/8-1:0] i_wb_sel,
    input  wire [GLOBAL_LINE_ADDR_W+3:0] i_wb_adr,
    output wire                  o_wb_stall,
    output wire                  o_wb_ack,
    output wire                  o_wb_err,
    output wire [WB_DATA_W-1:0]  o_wb_dat,

    output wire [CHANNELS-1:0] o_init_done,
    output wire [CHANNELS-1:0] o_init_busy,
    output wire [CHANNELS*5-1:0] o_init_state,
    output wire                 o_init_all_done,

    output wire [CHANNELS-1:0] o_sched_req_pending,
    output wire [CHANNELS-1:0] o_refresh_req,
    output wire [CHANNELS-1:0] o_refresh_ack,
    output wire [CHANNELS-1:0] o_refresh_busy,
    output wire [CHANNELS-1:0] o_refresh_late,
    output wire [CHANNELS*16-1:0] o_refresh_count,
    output wire [CHANNELS*(1 << BANK_BITS)-1:0] o_bank_busy,
    output wire [CHANNELS*(1 << BANK_BITS)-1:0] o_bank_open,

    output wire [CHANNELS-1:0] o_ddr_reset_n,
    output wire [CHANNELS-1:0] o_ddr_cke,
    output wire [CHANNELS-1:0] o_ddr_odt,
    output wire [CHANNELS-1:0] o_ddr_cmd_valid,
    output wire [CHANNELS-1:0] o_ddr_cs_n,
    output wire [CHANNELS-1:0] o_ddr_ras_n,
    output wire [CHANNELS-1:0] o_ddr_cas_n,
    output wire [CHANNELS-1:0] o_ddr_we_n,
    output wire [CHANNELS*BANK_BITS-1:0] o_ddr_ba,
    output wire [CHANNELS*ADDR_BITS-1:0] o_ddr_addr,

    output wire [CHANNELS-1:0] o_phy_wr_line_valid,
    input  wire [CHANNELS-1:0] i_phy_wr_line_ready,
    input  wire [CHANNELS-1:0] i_phy_wr_line_loaded,
    output wire [CHANNELS*LINE_DATA_W-1:0] o_phy_wr_line_data,
    output wire [CHANNELS*LINE_BYTES-1:0] o_phy_wr_line_mask,

    output wire [CHANNELS-1:0] o_phy_start_write,
    output wire [CHANNELS-1:0] o_phy_start_read,

    output wire [CHANNELS-1:0] o_phy_rd_line_ready,
    input  wire [CHANNELS-1:0] i_phy_rd_line_valid,
    input  wire [CHANNELS*LINE_DATA_W-1:0] i_phy_rd_line_data,
    input  wire [CHANNELS-1:0] i_phy_rd_line_err
);
    localparam integer BANKS = (1 << BANK_BITS);

    wire all_init_done = &o_init_done;

    wire wb_stall_raw;
    wire wb_ack_raw;
    wire wb_err_raw;

    wire [CHANNELS-1:0] wb_cmd_valid;
    wire [CHANNELS-1:0] wb_cmd_ready;
    wire [CHANNELS-1:0] wb_cmd_write;
    wire [CHANNELS*LINE_ADDR_W-1:0] wb_cmd_line_addr;
    wire [CHANNELS-1:0] wb_xfer_start;
    wire [CHANNELS-1:0] sched_xfer_write;

    wire [CHANNELS-1:0] init_cmd_valid;
    wire [CHANNELS-1:0] init_reset_n;
    wire [CHANNELS-1:0] init_cke;
    wire [CHANNELS-1:0] init_odt;
    wire [CHANNELS-1:0] init_cs_n;
    wire [CHANNELS-1:0] init_ras_n;
    wire [CHANNELS-1:0] init_cas_n;
    wire [CHANNELS-1:0] init_we_n;
    wire [CHANNELS*BANK_BITS-1:0] init_ba;
    wire [CHANNELS*ADDR_BITS-1:0] init_addr;

    wire [CHANNELS-1:0] sched_cmd_valid;
    wire [CHANNELS-1:0] sched_cs_n;
    wire [CHANNELS-1:0] sched_ras_n;
    wire [CHANNELS-1:0] sched_cas_n;
    wire [CHANNELS-1:0] sched_we_n;
    wire [CHANNELS*BANK_BITS-1:0] sched_ba;
    wire [CHANNELS*ADDR_BITS-1:0] sched_addr;

    assign o_init_all_done = all_init_done;
    assign o_phy_start_write = wb_xfer_start & sched_xfer_write;
    assign o_phy_start_read = wb_xfer_start & ~sched_xfer_write;

    assign o_wb_stall = !all_init_done || wb_stall_raw;
    assign o_wb_ack = all_init_done && wb_ack_raw;
    assign o_wb_err = all_init_done && wb_err_raw;

    ddr3_wb_dual_channel_line #(
        .LANES(LANES),
        .WB_DATA_W(WB_DATA_W),
        .PHY_HAS_BYTE_MASK(PHY_HAS_BYTE_MASK)
    ) u_wb (
        .i_clk(i_clk),
        .i_rst(i_rst),
        .i_wb_cyc(i_wb_cyc && all_init_done),
        .i_wb_stb(i_wb_stb && all_init_done),
        .i_wb_we(i_wb_we),
        .i_wb_dat(i_wb_dat),
        .i_wb_sel(i_wb_sel),
        .i_wb_adr(i_wb_adr),
        .o_wb_stall(wb_stall_raw),
        .o_wb_ack(wb_ack_raw),
        .o_wb_err(wb_err_raw),
        .o_wb_dat(o_wb_dat),
        .o_cmd_valid(wb_cmd_valid),
        .i_cmd_ready(wb_cmd_ready),
        .o_cmd_write(wb_cmd_write),
        .o_cmd_line_addr(wb_cmd_line_addr),
        .i_xfer_start(wb_xfer_start),
        .o_phy_wr_line_valid(o_phy_wr_line_valid),
        .i_phy_wr_line_ready(i_phy_wr_line_ready),
        .i_phy_wr_line_loaded(i_phy_wr_line_loaded),
        .o_phy_wr_line_data(o_phy_wr_line_data),
        .o_phy_wr_line_mask(o_phy_wr_line_mask),
        .o_phy_rd_line_ready(o_phy_rd_line_ready),
        .i_phy_rd_line_valid(i_phy_rd_line_valid),
        .i_phy_rd_line_data(i_phy_rd_line_data),
        .i_phy_rd_line_err(i_phy_rd_line_err)
    );

    genvar ch;
    generate
        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_channel
            ddr3_init_seq #(
                .ADDR_BITS(ADDR_BITS),
                .BANK_BITS(BANK_BITS),
                .RESET_LOW_CYCLES(INIT_RESET_LOW_CYCLES),
                .RESET_CKE_CYCLES(INIT_RESET_CKE_CYCLES),
                .TXPR_CYCLES(INIT_TXPR_CYCLES),
                .TMRD_CYCLES(INIT_TMRD_CYCLES),
                .TMOD_CYCLES(INIT_TMOD_CYCLES),
                .TZQINIT_CYCLES(INIT_TZQINIT_CYCLES),
                .TRFC_CYCLES(INIT_TRFC_CYCLES),
                .TDLLK_CYCLES(INIT_TDLLK_CYCLES),
                .MR0(INIT_MR0),
                .MR1(INIT_MR1),
                .MR2(INIT_MR2),
                .MR3(INIT_MR3)
            ) u_init (
                .i_clk(i_clk),
                .i_rst(i_rst),
                .i_start(i_init_start),
                .o_reset_n(init_reset_n[ch]),
                .o_cke(init_cke[ch]),
                .o_odt(init_odt[ch]),
                .o_cmd_valid(init_cmd_valid[ch]),
                .o_cs_n(init_cs_n[ch]),
                .o_ras_n(init_ras_n[ch]),
                .o_cas_n(init_cas_n[ch]),
                .o_we_n(init_we_n[ch]),
                .o_ba(init_ba[ch*BANK_BITS +: BANK_BITS]),
                .o_addr(init_addr[ch*ADDR_BITS +: ADDR_BITS]),
                .o_busy(o_init_busy[ch]),
                .o_done(o_init_done[ch]),
                .o_state(o_init_state[ch*5 +: 5])
            );

            ddr3_channel_sched #(
                .ADDR_BITS(ADDR_BITS),
                .BANK_BITS(BANK_BITS),
                .ROW_BITS(ROW_BITS),
                .COL_BITS(COL_BITS),
                .T_RP(T_RP),
                .T_RCD(T_RCD),
                .T_RAS(T_RAS),
                .T_RC(T_RC),
                .T_RFC(T_RFC),
                .T_WR(T_WR),
                .T_WTR(T_WTR),
                .T_RTP(T_RTP),
                .T_RRD(T_RRD),
                .T_FAW(T_FAW),
                .T_CCD(T_CCD),
                .T_REFI(T_REFI),
                .T_MARGIN(T_MARGIN)
            ) u_sched (
                .i_clk(i_clk),
                .i_rst(i_rst),
                .i_cmd_valid(wb_cmd_valid[ch]),
                .o_cmd_ready(wb_cmd_ready[ch]),
                .i_cmd_write(wb_cmd_write[ch]),
                .i_cmd_line_addr(wb_cmd_line_addr[ch*LINE_ADDR_W +: LINE_ADDR_W]),
                .o_xfer_start(wb_xfer_start[ch]),
                .o_xfer_write(sched_xfer_write[ch]),
                .i_refresh_enable(all_init_done),
                .o_req_pending(o_sched_req_pending[ch]),
                .o_refresh_req(o_refresh_req[ch]),
                .o_refresh_ack(o_refresh_ack[ch]),
                .o_refresh_busy(o_refresh_busy[ch]),
                .o_refresh_late(o_refresh_late[ch]),
                .o_refresh_count(o_refresh_count[ch*16 +: 16]),
                .o_bank_busy(o_bank_busy[ch*BANKS +: BANKS]),
                .o_bank_open(o_bank_open[ch*BANKS +: BANKS]),
                .o_cmd_valid(sched_cmd_valid[ch]),
                .o_cs_n(sched_cs_n[ch]),
                .o_ras_n(sched_ras_n[ch]),
                .o_cas_n(sched_cas_n[ch]),
                .o_we_n(sched_we_n[ch]),
                .o_ba(sched_ba[ch*BANK_BITS +: BANK_BITS]),
                .o_addr(sched_addr[ch*ADDR_BITS +: ADDR_BITS])
            );

            assign o_ddr_reset_n[ch] = init_reset_n[ch];
            assign o_ddr_cke[ch] = init_cke[ch];
            assign o_ddr_odt[ch] = o_init_done[ch] ? 1'b0 : init_odt[ch];
            assign o_ddr_cmd_valid[ch] = o_init_done[ch]
                                        ? sched_cmd_valid[ch]
                                        : init_cmd_valid[ch];
            assign o_ddr_cs_n[ch] = o_init_done[ch] ? sched_cs_n[ch] : init_cs_n[ch];
            assign o_ddr_ras_n[ch] = o_init_done[ch] ? sched_ras_n[ch] : init_ras_n[ch];
            assign o_ddr_cas_n[ch] = o_init_done[ch] ? sched_cas_n[ch] : init_cas_n[ch];
            assign o_ddr_we_n[ch] = o_init_done[ch] ? sched_we_n[ch] : init_we_n[ch];
            assign o_ddr_ba[ch*BANK_BITS +: BANK_BITS] = o_init_done[ch]
                                                        ? sched_ba[ch*BANK_BITS +: BANK_BITS]
                                                        : init_ba[ch*BANK_BITS +: BANK_BITS];
            assign o_ddr_addr[ch*ADDR_BITS +: ADDR_BITS] = o_init_done[ch]
                                                          ? sched_addr[ch*ADDR_BITS +: ADDR_BITS]
                                                          : init_addr[ch*ADDR_BITS +: ADDR_BITS];
        end
    endgenerate
endmodule

`default_nettype wire

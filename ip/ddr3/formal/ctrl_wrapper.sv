// Formal harness for the init-gated dual-channel DDR3 controller shell.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_ctrl_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer ADDR_BITS = `DDR3_ADDR_BITS;
    localparam integer BANK_BITS = `DDR3_BANK_BITS;
    localparam integer PHY_DATA_W = LANES * 8;

    wire                         wb_cyc = !init_all_done;
    wire                         wb_stb = !init_all_done;
    wire                         wb_we = 1'b0;
    wire [GLOBAL_WORD_ADDR_W-1:0] wb_adr = {GLOBAL_WORD_ADDR_W{1'b0}};
    wire [WB_DATA_W-1:0]         wb_dat_w = {WB_DATA_W{1'b0}};
    wire [(WB_DATA_W/8)-1:0]     wb_sel = {(WB_DATA_W/8){1'b1}};
    wire [(CHANNELS*PHY_DATA_W)-1:0] phy_rd_data =
        {(CHANNELS*PHY_DATA_W){1'b0}};

    wire wb_stall;
    wire wb_ack;
    wire wb_err;
    wire [WB_DATA_W-1:0] wb_dat_r;
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
    wire [CHANNELS-1:0] ddr_cmd_valid;
    wire [CHANNELS-1:0] ddr_cs_n;
    wire [CHANNELS-1:0] ddr_ras_n;
    wire [CHANNELS-1:0] ddr_cas_n;
    wire [CHANNELS-1:0] ddr_we_n;
    wire [CHANNELS*BANK_BITS-1:0] ddr_ba;
    wire [CHANNELS*ADDR_BITS-1:0] ddr_addr;
    wire [CHANNELS-1:0] line_done;
    wire [CHANNELS-1:0] line_rd_valid;
    wire [CHANNELS*LANES-1:0] phy_wr_valid;
    wire [CHANNELS*LANES-1:0] phy_wr_mask;
    wire [CHANNELS*LANES-1:0] phy_wr_last;
    wire [CHANNELS*PHY_DATA_W-1:0] phy_wr_data;
    wire [CHANNELS*LANES-1:0] phy_rd_ready;

    ddr3_ctrl #(
        .INIT_RESET_LOW_CYCLES(1),
        .INIT_RESET_CKE_CYCLES(1),
        .INIT_TXPR_CYCLES(1),
        .INIT_TMRD_CYCLES(1),
        .INIT_TMOD_CYCLES(1),
        .INIT_TZQINIT_CYCLES(1),
        .INIT_TRFC_CYCLES(1),
        .INIT_TDLLK_CYCLES(1),
        .T_RCD(2),
        .T_RP(2),
        .T_RAS(4),
        .T_RC(5),
        .T_RFC(4),
        .T_WR(3),
        .T_WTR(3),
        .T_RTP(3),
        .T_RRD(2),
        .T_FAW(6),
        .T_CCD(2),
        .T_REFI(128),
        .T_MARGIN(8)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_init_start(1'b1),
        .i_wb_cyc(wb_cyc),
        .i_wb_stb(wb_stb),
        .i_wb_we(wb_we),
        .i_wb_dat(wb_dat_w),
        .i_wb_sel(wb_sel),
        .i_wb_adr(wb_adr),
        .o_wb_stall(wb_stall),
        .o_wb_ack(wb_ack),
        .o_wb_err(wb_err),
        .o_wb_dat(wb_dat_r),
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
        .o_ddr_reset_n(),
        .o_ddr_cke(),
        .o_ddr_odt(),
        .o_ddr_cmd_valid(ddr_cmd_valid),
        .o_ddr_cs_n(ddr_cs_n),
        .o_ddr_ras_n(ddr_ras_n),
        .o_ddr_cas_n(ddr_cas_n),
        .o_ddr_we_n(ddr_we_n),
        .o_ddr_ba(ddr_ba),
        .o_ddr_addr(ddr_addr),
        .o_line_done(line_done),
        .o_line_rd_valid(line_rd_valid),
        .o_phy_wr_valid(phy_wr_valid),
        .i_phy_wr_ready({(CHANNELS*LANES){1'b1}}),
        .o_phy_wr_data(phy_wr_data),
        .o_phy_wr_mask(phy_wr_mask),
        .o_phy_wr_last(phy_wr_last),
        .o_phy_rd_ready(phy_rd_ready),
        .i_phy_rd_valid(phy_rd_ready),
        .i_phy_rd_data(phy_rd_data)
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;
    reg saw_done = 1'b0;
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        assert(init_all_done == &init_done);

        if (!init_all_done) begin
            assert(wb_stall);
            assert(!wb_ack);
            assert(!wb_err);
            assert(sched_req_pending == {CHANNELS{1'b0}});
            assert(refresh_req == {CHANNELS{1'b0}});
            assert(refresh_ack == {CHANNELS{1'b0}});
            assert(refresh_busy == {CHANNELS{1'b0}});
            assert(refresh_late == {CHANNELS{1'b0}});
            assert(phy_wr_valid == {(CHANNELS*LANES){1'b0}});
            assert(phy_rd_ready == {(CHANNELS*LANES){1'b0}});
        end

        if (wb_ack || wb_err)
            assert(init_all_done);

        if (f_past_valid && $past(init_all_done))
            assert(init_all_done);

        if (rst) begin
            saw_done <= 1'b0;
        end else begin
            if (init_all_done)
                saw_done <= 1'b1;

            cover(saw_done);
        end
    end
`endif
endmodule

`default_nettype wire

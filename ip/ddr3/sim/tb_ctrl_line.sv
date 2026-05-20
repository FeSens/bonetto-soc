`default_nettype none
`timescale 1ns/1ps

`include "ddr3_params.vh"

module tb_ctrl_line;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer ADDR_BITS = `DDR3_ADDR_BITS;
    localparam integer BANK_BITS = `DDR3_BANK_BITS;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;

    reg clk = 1'b0;
    reg rst = 1'b1;
    reg init_start = 1'b1;

    reg                         wb_cyc = 1'b0;
    reg                         wb_stb = 1'b0;
    reg                         wb_we = 1'b0;
    reg [GLOBAL_WORD_ADDR_W-1:0] wb_adr = {GLOBAL_WORD_ADDR_W{1'b0}};
    reg [WB_DATA_W-1:0]         wb_dat_w = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0]     wb_sel = {(WB_DATA_W/8){1'b0}};
    wire                        wb_stall;
    wire                        wb_ack;
    wire                        wb_err;
    wire [WB_DATA_W-1:0]        wb_dat_r;

    wire [CHANNELS-1:0]         init_done;
    wire [CHANNELS-1:0]         ddr_cmd_valid;
    wire [CHANNELS-1:0]         ddr_cs_n;
    wire [CHANNELS-1:0]         ddr_ras_n;
    wire [CHANNELS-1:0]         ddr_cas_n;
    wire [CHANNELS-1:0]         ddr_we_n;
    wire [(CHANNELS*BANK_BITS)-1:0] ddr_ba;
    wire [(CHANNELS*ADDR_BITS)-1:0] ddr_addr;

    wire [CHANNELS-1:0]         phy_wr_line_valid;
    reg [CHANNELS-1:0]          phy_wr_line_ready = {CHANNELS{1'b1}};
    wire [(CHANNELS*LINE_DATA_W)-1:0] phy_wr_line_data;
    wire [(CHANNELS*LINE_BYTES)-1:0]  phy_wr_line_mask;
    wire [CHANNELS-1:0]         phy_start_write;
    wire [CHANNELS-1:0]         phy_start_read;
    wire [CHANNELS-1:0]         phy_rd_line_ready;
    reg [CHANNELS-1:0]          phy_rd_line_valid = {CHANNELS{1'b0}};
    reg [(CHANNELS*LINE_DATA_W)-1:0] phy_rd_line_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};
    reg [CHANNELS-1:0]          phy_rd_line_err = {CHANNELS{1'b0}};

    integer i;
    reg write_ack_seen = 1'b0;
    reg write_ack_err = 1'b0;
    reg read_ack_seen = 1'b0;
    reg read_ack_err = 1'b0;
    reg [WB_DATA_W-1:0] read_ack_data = {WB_DATA_W{1'b0}};
    reg ch0_write_cmd_seen = 1'b0;
    reg ch0_write_start_seen = 1'b0;
    reg ch1_read_cmd_seen = 1'b0;
    reg ch1_read_start_seen = 1'b0;
    reg [3:0] mon_cmd0 = 4'h0;
    reg [3:0] mon_cmd1 = 4'h0;

    always #5 clk = ~clk;

    ddr3_ctrl_line #(
        .INIT_RESET_LOW_CYCLES(3),
        .INIT_RESET_CKE_CYCLES(3),
        .INIT_TXPR_CYCLES(2),
        .INIT_TMRD_CYCLES(2),
        .INIT_TMOD_CYCLES(2),
        .INIT_TZQINIT_CYCLES(3),
        .INIT_TRFC_CYCLES(3),
        .INIT_TDLLK_CYCLES(3),
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
        .i_init_start(init_start),
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
        .o_init_busy(),
        .o_init_state(),
        .o_init_all_done(),
        .o_sched_req_pending(),
        .o_refresh_req(),
        .o_refresh_ack(),
        .o_refresh_busy(),
        .o_refresh_late(),
        .o_refresh_count(),
        .o_bank_busy(),
        .o_bank_open(),
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

    task start_wb;
        input write;
        input [GLOBAL_WORD_ADDR_W-1:0] addr;
        input [WB_DATA_W-1:0] data;
        input [(WB_DATA_W/8)-1:0] sel;
        begin
            @(negedge clk);
            wb_cyc = 1'b1;
            wb_stb = 1'b1;
            wb_we = write;
            wb_adr = addr;
            wb_dat_w = data;
            wb_sel = sel;
            while (wb_stall)
                @(negedge clk);
            @(negedge clk);
            wb_stb = 1'b0;
        end
    endtask

    task finish_wb;
        begin
            @(negedge clk);
            wb_cyc = 1'b0;
            wb_we = 1'b0;
            wb_adr = {GLOBAL_WORD_ADDR_W{1'b0}};
            wb_dat_w = {WB_DATA_W{1'b0}};
            wb_sel = {(WB_DATA_W/8){1'b0}};
        end
    endtask

    initial begin
        repeat (3) @(posedge clk);
        rst = 1'b0;

        @(negedge clk);
        wb_cyc = 1'b1;
        wb_stb = 1'b1;
        wb_we = 1'b0;
        wb_adr = {GLOBAL_WORD_ADDR_W{1'b0}};
        wb_sel = 4'hF;
        #1;
        if (!wb_stall || wb_ack || wb_err) begin
            $display("[ctrl-line] pre-init Wishbone gate mismatch stall=%0b ack=%0b err=%0b",
                     wb_stall, wb_ack, wb_err);
            $fatal(1);
        end

        @(negedge clk);
        wb_cyc = 1'b0;
        wb_stb = 1'b0;

        wait (init_done == 2'b11);
        repeat (2) @(posedge clk);

        write_ack_seen = 1'b0;
        write_ack_err = 1'b0;
        ch0_write_cmd_seen = 1'b0;
        ch0_write_start_seen = 1'b0;
        start_wb(1'b1, 30'h0000_002d, 32'hCAFE_BABE, 4'b1110);
        wait (phy_wr_line_valid[0]);
        if (phy_wr_line_valid !== 2'b01) begin
            $display("[ctrl-line] write line valid mismatch valid=%b",
                     phy_wr_line_valid);
            $fatal(1);
        end
        if (phy_wr_line_data[52*8 +: 32] !== 32'hCAFE_BABE ||
            phy_wr_line_mask[55:52] !== 4'b0001) begin
            $display("[ctrl-line] write line placement mismatch data=%h mask=%b",
                     phy_wr_line_data[52*8 +: 32],
                     phy_wr_line_mask[55:52]);
            $fatal(1);
        end

        wait (write_ack_seen);
        if (write_ack_err) begin
            $display("[ctrl-line] ch0 write ack unexpectedly errored");
            $fatal(1);
        end
        wait (ch0_write_cmd_seen);
        wait (ch0_write_start_seen);
        finish_wb();

        for (i = 0; i < LINE_BYTES; i = i + 1)
            phy_rd_line_data[LINE_DATA_W + (i * 8) +: 8] = 8'h40 + i[7:0];

        read_ack_seen = 1'b0;
        read_ack_err = 1'b0;
        read_ack_data = {WB_DATA_W{1'b0}};
        ch1_read_cmd_seen = 1'b0;
        ch1_read_start_seen = 1'b0;
        start_wb(1'b0, {1'b1, 29'h0000_000e}, 32'h0, 4'hF);
        wait (ch1_read_cmd_seen);
        wait (ch1_read_start_seen);

        wait (phy_rd_line_ready[1]);
        if (phy_rd_line_ready[0]) begin
            $display("[ctrl-line] ch0 read interface active during ch1 read");
            $fatal(1);
        end

        @(negedge clk);
        phy_rd_line_valid = 2'b10;

        wait (read_ack_seen);
        if (read_ack_err || read_ack_data !== 32'h7b7a_7978) begin
            $display("[ctrl-line] ch1 read response mismatch data=%h err=%0b",
                     read_ack_data, read_ack_err);
            $fatal(1);
        end
        @(negedge clk);
        phy_rd_line_valid = 2'b00;
        finish_wb();

        $display("[ctrl-line] init-gated line-level controller passed");
        $finish;
    end

    always @(posedge clk) begin
        #1;
        if (wb_ack && wb_we) begin
            write_ack_seen = 1'b1;
            write_ack_err = wb_err;
        end

        if (wb_ack && !wb_we) begin
            read_ack_seen = 1'b1;
            read_ack_err = wb_err;
            read_ack_data = wb_dat_r;
        end

        mon_cmd0 = {ddr_cs_n[0], ddr_ras_n[0], ddr_cas_n[0], ddr_we_n[0]};
        if (ddr_cmd_valid[0] && (mon_cmd0 == `DDR3_CMD_WR)) begin
            if (ddr_ba[0 +: BANK_BITS] !== {BANK_BITS{1'b0}} ||
                ddr_addr[0 +: ADDR_BITS] !== 15'h0010) begin
                $display("[ctrl-line] ch0 WR command mismatch bank=%h addr=%h",
                         ddr_ba[0 +: BANK_BITS], ddr_addr[0 +: ADDR_BITS]);
                $fatal(1);
            end
            ch0_write_cmd_seen = 1'b1;
        end

        if (phy_start_write[0]) begin
            if (phy_start_write !== 2'b01 || phy_start_read !== 2'b00) begin
                $display("[ctrl-line] write transfer-start mismatch wr=%b rd=%b",
                         phy_start_write, phy_start_read);
                $fatal(1);
            end
            ch0_write_start_seen = 1'b1;
        end

        mon_cmd1 = {ddr_cs_n[1], ddr_ras_n[1], ddr_cas_n[1], ddr_we_n[1]};
        if (ddr_cmd_valid[1] && (mon_cmd1 == `DDR3_CMD_RD)) begin
            if (ddr_ba[BANK_BITS +: BANK_BITS] !== {BANK_BITS{1'b0}} ||
                ddr_addr[ADDR_BITS +: ADDR_BITS] !== 15'h0000) begin
                $display("[ctrl-line] ch1 RD command mismatch bank=%h addr=%h",
                         ddr_ba[BANK_BITS +: BANK_BITS],
                         ddr_addr[ADDR_BITS +: ADDR_BITS]);
                $fatal(1);
            end
            ch1_read_cmd_seen = 1'b1;
        end

        if (phy_start_read[1]) begin
            if (phy_start_write !== 2'b00 || phy_start_read !== 2'b10) begin
                $display("[ctrl-line] read transfer-start mismatch wr=%b rd=%b",
                         phy_start_write, phy_start_read);
                $fatal(1);
            end
            ch1_read_start_seen = 1'b1;
        end
    end

    initial begin
        repeat (1000) @(posedge clk);
        $display("[ctrl-line] timeout init_done=%b ack=%0b stall=%0b cmd_valid=%b",
                 init_done, wb_ack, wb_stall, ddr_cmd_valid);
        $fatal(1);
    end
endmodule

`default_nettype wire

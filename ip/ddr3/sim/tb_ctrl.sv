`default_nettype none
`timescale 1ns/1ps

`include "ddr3_params.vh"

module tb_ctrl;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer ADDR_BITS = `DDR3_ADDR_BITS;
    localparam integer BANK_BITS = `DDR3_BANK_BITS;
    localparam integer PHY_DATA_W = LANES * 8;

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

    wire [CHANNELS-1:0]         line_done;
    wire [CHANNELS-1:0]         line_rd_valid;
    wire [(CHANNELS*LANES)-1:0] phy_wr_valid;
    reg [(CHANNELS*LANES)-1:0]  phy_wr_ready = {(CHANNELS*LANES){1'b0}};
    wire [(CHANNELS*PHY_DATA_W)-1:0] phy_wr_data;
    wire [(CHANNELS*LANES)-1:0] phy_wr_mask;
    wire [(CHANNELS*LANES)-1:0] phy_wr_last;
    wire [(CHANNELS*LANES)-1:0] phy_rd_ready;
    reg [(CHANNELS*LANES)-1:0]  phy_rd_valid = {(CHANNELS*LANES){1'b0}};
    reg [(CHANNELS*PHY_DATA_W)-1:0] phy_rd_data =
        {(CHANNELS*PHY_DATA_W){1'b0}};

    integer lane;
    integer beat;
    reg write_ack_seen = 1'b0;
    reg write_ack_err = 1'b0;

    always #5 clk = ~clk;

    ddr3_ctrl #(
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

    task wait_ddr_cmd;
        input integer ch;
        input [3:0] expected_cmd;
        input [BANK_BITS-1:0] expected_bank;
        input [ADDR_BITS-1:0] expected_addr;
        reg [3:0] got_cmd;
        reg found;
        begin
            got_cmd = 4'h0;
            found = 1'b0;
            while (!found) begin
                @(posedge clk);
                #1;
                got_cmd = {ddr_cs_n[ch], ddr_ras_n[ch], ddr_cas_n[ch],
                           ddr_we_n[ch]};
                found = ddr_cmd_valid[ch] && (got_cmd == expected_cmd);
            end

            if (ddr_ba[(ch * BANK_BITS) +: BANK_BITS] !== expected_bank ||
                ddr_addr[(ch * ADDR_BITS) +: ADDR_BITS] !== expected_addr) begin
                $display("[ctrl] DDR command mismatch ch=%0d cmd=%b bank=%h addr=%h",
                         ch, got_cmd,
                         ddr_ba[(ch * BANK_BITS) +: BANK_BITS],
                         ddr_addr[(ch * ADDR_BITS) +: ADDR_BITS]);
                $fatal(1);
            end
        end
    endtask

    function [7:0] expected_write_byte;
        input integer lane_i;
        input integer beat_i;
        integer byte_index;
        begin
            byte_index = (lane_i * 8) + beat_i;
            expected_write_byte = 8'h00;
            if (byte_index == 52) expected_write_byte = 8'hBE;
            if (byte_index == 53) expected_write_byte = 8'hBA;
            if (byte_index == 54) expected_write_byte = 8'hFE;
            if (byte_index == 55) expected_write_byte = 8'hCA;
        end
    endfunction

    function expected_write_mask;
        input integer lane_i;
        input integer beat_i;
        integer byte_index;
        begin
            byte_index = (lane_i * 8) + beat_i;
            expected_write_mask = 1'b1;
            if (byte_index == 53) expected_write_mask = 1'b0;
            if (byte_index == 54) expected_write_mask = 1'b0;
            if (byte_index == 55) expected_write_mask = 1'b0;
        end
    endfunction

    task check_ch0_write_beat;
        input integer beat_i;
        begin
            if (phy_wr_valid[0 +: LANES] !== {LANES{1'b1}} ||
                phy_wr_valid[LANES +: LANES] !== {LANES{1'b0}}) begin
                $display("[ctrl] write valid mismatch beat=%0d valid=%b",
                         beat_i, phy_wr_valid);
                $fatal(1);
            end

            for (lane = 0; lane < LANES; lane = lane + 1) begin
                if (phy_wr_data[(lane * 8) +: 8] !==
                    expected_write_byte(lane, beat_i)) begin
                    $display("[ctrl] ch0 write data mismatch lane=%0d beat=%0d got=%h",
                             lane, beat_i, phy_wr_data[(lane * 8) +: 8]);
                    $fatal(1);
                end

                if (phy_wr_mask[lane] !== expected_write_mask(lane, beat_i)) begin
                    $display("[ctrl] ch0 write mask mismatch lane=%0d beat=%0d got=%0b",
                             lane, beat_i, phy_wr_mask[lane]);
                    $fatal(1);
                end

                if (phy_wr_last[lane] !== (beat_i == 7)) begin
                    $display("[ctrl] ch0 write last mismatch lane=%0d beat=%0d got=%0b",
                             lane, beat_i, phy_wr_last[lane]);
                    $fatal(1);
                end
            end
        end
    endtask

    task drive_ch1_read_beat;
        input integer beat_i;
        begin
            @(negedge clk);
            phy_rd_valid = {(CHANNELS*LANES){1'b0}};
            phy_rd_valid[LANES +: LANES] = phy_rd_ready[LANES +: LANES];
            for (lane = 0; lane < LANES; lane = lane + 1)
                phy_rd_data[PHY_DATA_W + (lane * 8) +: 8] =
                    8'h40 + (lane * 8) + beat_i;
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
            $display("[ctrl] pre-init Wishbone gate mismatch stall=%0b ack=%0b err=%0b",
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
        start_wb(1'b1, 30'h0000_002d, 32'hCAFE_BABE, 4'b1110);
        wait_ddr_cmd(0, `DDR3_CMD_WR, {BANK_BITS{1'b0}}, 15'h0010);
        phy_wr_ready[0 +: LANES] = {LANES{1'b1}};

        wait (write_ack_seen);
        if (write_ack_err) begin
            $display("[ctrl] ch0 write ack unexpectedly errored");
            $fatal(1);
        end

        wait (phy_wr_valid[0 +: LANES] == {LANES{1'b1}});
        #1;
        for (beat = 0; beat < 8; beat = beat + 1) begin
            check_ch0_write_beat(beat);
            if (beat != 7) begin
                @(posedge clk);
                #1;
            end
        end

        wait (line_done[0]);
        @(negedge clk);
        phy_wr_ready = {(CHANNELS*LANES){1'b0}};
        finish_wb();

        start_wb(1'b0, {1'b1, 29'h0000_000e}, 32'h0, 4'hF);
        wait_ddr_cmd(1, `DDR3_CMD_RD, {BANK_BITS{1'b0}}, 15'h0000);

        wait (phy_rd_ready[LANES +: LANES] == {LANES{1'b1}});
        if (phy_rd_ready[0 +: LANES] !== {LANES{1'b0}}) begin
            $display("[ctrl] ch0 read interface active during ch1 read");
            $fatal(1);
        end

        for (beat = 0; beat < 8; beat = beat + 1)
            drive_ch1_read_beat(beat);

        @(negedge clk);
        phy_rd_valid = {(CHANNELS*LANES){1'b0}};
        phy_rd_data = {(CHANNELS*PHY_DATA_W){1'b0}};

        wait (line_rd_valid[1]);
        wait (wb_ack);
        if (wb_err || wb_dat_r !== 32'h7b7a_7978) begin
            $display("[ctrl] ch1 read response mismatch data=%h err=%0b",
                     wb_dat_r, wb_err);
            $fatal(1);
        end
        finish_wb();

        $display("[ctrl] init-gated dual-channel scheduler integration passed");
        $finish;
    end

    always @(posedge clk) begin
        if (wb_ack && wb_we) begin
            write_ack_seen <= 1'b1;
            write_ack_err <= wb_err;
        end
    end

    initial begin
        repeat (1000) @(posedge clk);
        $display("[ctrl] timeout init_done=%b ack=%0b stall=%0b cmd_valid=%b",
                 init_done, wb_ack, wb_stall, ddr_cmd_valid);
        $fatal(1);
    end
endmodule

`default_nettype wire

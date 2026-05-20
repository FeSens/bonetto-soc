`default_nettype none
`timescale 1ns/1ps

module tb_wb_dual_channel;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer LINE_ADDR_W = 25;
    localparam integer PHY_DATA_W = LANES * 8;

    reg clk = 1'b0;
    reg rst = 1'b1;

    reg                         wb_cyc = 1'b0;
    reg                         wb_stb = 1'b0;
    reg                         wb_we = 1'b0;
    reg [GLOBAL_WORD_ADDR_W-1:0] wb_adr = {GLOBAL_WORD_ADDR_W{1'b0}};
    reg [WB_DATA_W-1:0]         wb_dat_w = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0]     wb_sel = {(WB_DATA_W/8){1'b0}};
    wire                        wb_stall;
    wire                        wb_ack;
    wire [WB_DATA_W-1:0]        wb_dat_r;
    wire                        wb_err;

    wire [CHANNELS-1:0]         cmd_valid;
    reg [CHANNELS-1:0]          cmd_ready = {CHANNELS{1'b0}};
    wire [CHANNELS-1:0]         cmd_write;
    wire [(CHANNELS*LINE_ADDR_W)-1:0] cmd_line_addr;
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

    always #5 clk = ~clk;

    ddr3_wb_dual_channel dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wb_cyc(wb_cyc),
        .i_wb_stb(wb_stb),
        .i_wb_we(wb_we),
        .i_wb_adr(wb_adr),
        .i_wb_dat(wb_dat_w),
        .i_wb_sel(wb_sel),
        .o_wb_stall(wb_stall),
        .o_wb_ack(wb_ack),
        .o_wb_dat(wb_dat_r),
        .o_wb_err(wb_err),
        .o_cmd_valid(cmd_valid),
        .i_cmd_ready(cmd_ready),
        .o_cmd_write(cmd_write),
        .o_cmd_line_addr(cmd_line_addr),
        .o_busy(),
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
            expected_write_mask = 1'b0;
            if (byte_index == 53) expected_write_mask = 1'b1;
            if (byte_index == 54) expected_write_mask = 1'b1;
            if (byte_index == 55) expected_write_mask = 1'b1;
        end
    endfunction

    task check_ch0_write_beat;
        input integer beat_i;
        begin
            if (phy_wr_valid[0 +: LANES] !== {LANES{1'b1}} ||
                phy_wr_valid[LANES +: LANES] !== {LANES{1'b0}}) begin
                $display("[wb-dual] write valid mismatch beat=%0d valid=%b",
                         beat_i, phy_wr_valid);
                $fatal(1);
            end

            for (lane = 0; lane < LANES; lane = lane + 1) begin
                if (phy_wr_data[(lane * 8) +: 8] !==
                    expected_write_byte(lane, beat_i)) begin
                    $display("[wb-dual] ch0 write data mismatch lane=%0d beat=%0d got=%h",
                             lane, beat_i, phy_wr_data[(lane * 8) +: 8]);
                    $fatal(1);
                end

                if (phy_wr_mask[lane] !== expected_write_mask(lane, beat_i)) begin
                    $display("[wb-dual] ch0 write mask mismatch lane=%0d beat=%0d got=%0b",
                             lane, beat_i, phy_wr_mask[lane]);
                    $fatal(1);
                end

                if (phy_wr_last[lane] !== (beat_i == 7)) begin
                    $display("[wb-dual] ch0 write last mismatch lane=%0d beat=%0d got=%0b",
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
        repeat (2) @(posedge clk);

        start_wb(1'b1, 30'h0000_002d, 32'hCAFE_BABE, 4'b1110);
        wait (cmd_valid[0]);
        if (cmd_valid !== 2'b01 || !cmd_write[0] ||
            cmd_line_addr[0 +: LINE_ADDR_W] !== 25'h0000002) begin
            $display("[wb-dual] ch0 write command mismatch valid=%b write=%b line0=%h",
                     cmd_valid, cmd_write, cmd_line_addr[0 +: LINE_ADDR_W]);
            $fatal(1);
        end

        @(negedge clk);
        cmd_ready = 2'b00;
        @(negedge clk);
        cmd_ready = 2'b01;
        phy_wr_ready[0 +: LANES] = {LANES{1'b1}};

        wait (wb_ack);
        if (wb_err) begin
            $display("[wb-dual] ch0 write ack unexpectedly errored");
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
        cmd_ready = 2'b00;
        phy_wr_ready = {(CHANNELS*LANES){1'b0}};
        finish_wb();

        start_wb(1'b0, {1'b1, 29'h0000_000e}, 32'h0, 4'hF);
        wait (cmd_valid[1]);
        if (cmd_valid !== 2'b10 || cmd_write[1] ||
            cmd_line_addr[LINE_ADDR_W +: LINE_ADDR_W] !== 25'h0000000) begin
            $display("[wb-dual] ch1 read command mismatch valid=%b write=%b line1=%h",
                     cmd_valid, cmd_write,
                     cmd_line_addr[LINE_ADDR_W +: LINE_ADDR_W]);
            $fatal(1);
        end

        @(negedge clk);
        cmd_ready = 2'b10;
        @(negedge clk);
        cmd_ready = 2'b00;

        wait (phy_rd_ready[LANES +: LANES] == {LANES{1'b1}});
        if (phy_rd_ready[0 +: LANES] !== {LANES{1'b0}}) begin
            $display("[wb-dual] ch0 read interface active during ch1 read");
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
            $display("[wb-dual] ch1 read response mismatch data=%h err=%0b",
                     wb_dat_r, wb_err);
            $fatal(1);
        end
        finish_wb();

        $display("[wb-dual] full-capacity channel dispatch passed");
        $finish;
    end

    initial begin
        repeat (400) @(posedge clk);
        $display("[wb-dual] timeout ack=%0b stall=%0b cmd_valid=%b cmd_ready=%b",
                 wb_ack, wb_stall, cmd_valid, cmd_ready);
        $fatal(1);
    end
endmodule

`default_nettype wire

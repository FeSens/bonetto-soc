`default_nettype none
`timescale 1ns/1ps

module tb_wb_channel;
    localparam integer WB_ADDR_W = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer LANES = 8;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer WORD_INDEX_W = 4;
    localparam integer LINE_ADDR_W = WB_ADDR_W - WORD_INDEX_W;

    reg clk = 1'b0;
    reg rst = 1'b1;

    reg                     wb_cyc = 1'b0;
    reg                     wb_stb = 1'b0;
    reg                     wb_we = 1'b0;
    reg [WB_ADDR_W-1:0]     wb_adr = {WB_ADDR_W{1'b0}};
    reg [WB_DATA_W-1:0]     wb_dat_w = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0] wb_sel = {(WB_DATA_W/8){1'b0}};
    wire                    wb_stall;
    wire                    wb_ack;
    wire [WB_DATA_W-1:0]    wb_dat_r;
    wire                    wb_err;

    wire                    cmd_valid;
    reg                     cmd_ready = 1'b0;
    wire                    cmd_write;
    wire [LINE_ADDR_W-1:0]  cmd_line_addr;
    reg                     xfer_start = 1'b0;
    wire                    line_done;
    wire                    line_rd_valid;

    wire [LANES-1:0]        phy_wr_valid;
    reg [LANES-1:0]         phy_wr_ready = {LANES{1'b0}};
    wire [(LANES*8)-1:0]    phy_wr_data;
    wire [LANES-1:0]        phy_wr_mask;
    wire [LANES-1:0]        phy_wr_last;
    wire [LANES-1:0]        phy_rd_ready;
    reg [LANES-1:0]         phy_rd_valid = {LANES{1'b0}};
    reg [(LANES*8)-1:0]     phy_rd_data = {(LANES*8){1'b0}};

    integer lane;
    integer beat;

    always #5 clk = ~clk;

    ddr3_wb_channel #(
        .WB_ADDR_W(WB_ADDR_W),
        .LANES(LANES),
        .WB_DATA_W(WB_DATA_W)
    ) dut (
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
        .i_xfer_start(xfer_start),
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
        input [WB_ADDR_W-1:0] addr;
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
            wb_adr = {WB_ADDR_W{1'b0}};
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
            if (byte_index == 52) expected_write_byte = 8'hDE;
            if (byte_index == 53) expected_write_byte = 8'hC0;
            if (byte_index == 54) expected_write_byte = 8'hDE;
            if (byte_index == 55) expected_write_byte = 8'hC0;
        end
    endfunction

    function expected_write_mask;
        input integer lane_i;
        input integer beat_i;
        integer byte_index;
        begin
            byte_index = (lane_i * 8) + beat_i;
            expected_write_mask = 1'b0;
            if (byte_index == 52) expected_write_mask = 1'b1;
            if (byte_index == 53) expected_write_mask = 1'b1;
            if (byte_index == 55) expected_write_mask = 1'b1;
        end
    endfunction

    task check_write_beat;
        input integer beat_i;
        begin
            if (phy_wr_valid !== {LANES{1'b1}}) begin
                $display("[wb-channel] write valid mismatch beat=%0d valid=%b",
                         beat_i, phy_wr_valid);
                $fatal(1);
            end

            for (lane = 0; lane < LANES; lane = lane + 1) begin
                if (phy_wr_data[(lane * 8) +: 8] !==
                    expected_write_byte(lane, beat_i)) begin
                    $display("[wb-channel] write data mismatch lane=%0d beat=%0d got=%h",
                             lane, beat_i, phy_wr_data[(lane * 8) +: 8]);
                    $fatal(1);
                end

                if (phy_wr_mask[lane] !== expected_write_mask(lane, beat_i)) begin
                    $display("[wb-channel] write mask mismatch lane=%0d beat=%0d got=%0b",
                             lane, beat_i, phy_wr_mask[lane]);
                    $fatal(1);
                end

                if (phy_wr_last[lane] !== (beat_i == 7)) begin
                    $display("[wb-channel] write last mismatch lane=%0d beat=%0d got=%0b",
                             lane, beat_i, phy_wr_last[lane]);
                    $fatal(1);
                end
            end
        end
    endtask

    task drive_read_beat;
        input integer beat_i;
        begin
            @(negedge clk);
            phy_rd_valid = phy_rd_ready;
            for (lane = 0; lane < LANES; lane = lane + 1)
                phy_rd_data[(lane * 8) +: 8] = 8'h80 + (lane * 8) + beat_i;
        end
    endtask

    initial begin
        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        start_wb(1'b1, 8'h2D, 32'hC0DE_C0DE, 4'b1011);
        wait (cmd_valid);
        if (!cmd_write || cmd_line_addr !== 4'h2) begin
            $display("[wb-channel] write command mismatch write=%0b line=%h",
                     cmd_write, cmd_line_addr);
            $fatal(1);
        end

        @(negedge clk);
        cmd_ready = 1'b0;
        @(negedge clk);
        cmd_ready = 1'b1;
        xfer_start = 1'b1;
        phy_wr_ready = {LANES{1'b1}};
        @(negedge clk);
        cmd_ready = 1'b0;
        xfer_start = 1'b0;

        wait (wb_ack);
        if (wb_err) begin
            $display("[wb-channel] write ack unexpectedly errored");
            $fatal(1);
        end

        wait (phy_wr_valid == {LANES{1'b1}});
        #1;
        for (beat = 0; beat < 8; beat = beat + 1) begin
            check_write_beat(beat);
            if (beat != 7) begin
                @(posedge clk);
                #1;
            end
        end

        wait (line_done);
        @(negedge clk);
        cmd_ready = 1'b0;
        phy_wr_ready = {LANES{1'b0}};
        finish_wb();

        start_wb(1'b0, 8'h0E, 32'h0, 4'hF);
        wait (cmd_valid);
        if (cmd_write || cmd_line_addr !== 4'h0) begin
            $display("[wb-channel] read command mismatch write=%0b line=%h",
                     cmd_write, cmd_line_addr);
            $fatal(1);
        end

        @(negedge clk);
        cmd_ready = 1'b1;
        xfer_start = 1'b1;
        @(negedge clk);
        cmd_ready = 1'b0;
        xfer_start = 1'b0;

        wait (phy_rd_ready == {LANES{1'b1}});
        for (beat = 0; beat < 8; beat = beat + 1)
            drive_read_beat(beat);

        @(negedge clk);
        phy_rd_valid = {LANES{1'b0}};
        phy_rd_data = {(LANES*8){1'b0}};

        wait (line_rd_valid);
        wait (wb_ack);
        if (wb_err || wb_dat_r !== 32'hBBBA_B9B8) begin
            $display("[wb-channel] read response mismatch data=%h err=%0b",
                     wb_dat_r, wb_err);
            $fatal(1);
        end
        finish_wb();

        $display("[wb-channel] Wishbone command bridge and full-width data mapping passed");
        $finish;
    end

    initial begin
        repeat (300) @(posedge clk);
        $display("[wb-channel] timeout ack=%0b stall=%0b cmd_valid=%0b cmd_ready=%0b",
                 wb_ack, wb_stall, cmd_valid, cmd_ready);
        $fatal(1);
    end
endmodule

`default_nettype wire

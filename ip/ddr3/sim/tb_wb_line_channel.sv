`default_nettype none
`timescale 1ns/1ps

module tb_wb_line_channel;
    localparam integer WB_ADDR_W = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer LANES = 8;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
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

    wire                    wr_line_valid;
    reg                     wr_line_ready = 1'b0;
    wire [LINE_DATA_W-1:0]  wr_line_data;
    wire [LINE_BYTES-1:0]   wr_line_mask;

    wire                    rd_line_ready;
    reg                     rd_line_valid = 1'b0;
    reg [LINE_DATA_W-1:0]   rd_line_data = {LINE_DATA_W{1'b0}};
    reg                     rd_line_err = 1'b0;

    always #5 clk = ~clk;

    ddr3_wb_line_channel #(
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
        .o_phy_wr_line_valid(wr_line_valid),
        .i_phy_wr_line_ready(wr_line_ready),
        .i_phy_wr_line_loaded(1'b1),
        .o_phy_wr_line_data(wr_line_data),
        .o_phy_wr_line_mask(wr_line_mask),
        .o_phy_rd_line_ready(rd_line_ready),
        .i_phy_rd_line_valid(rd_line_valid),
        .i_phy_rd_line_data(rd_line_data),
        .i_phy_rd_line_err(rd_line_err)
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

    function [7:0] line_byte;
        input [LINE_DATA_W-1:0] line;
        input integer index;
        begin
            line_byte = line[index * 8 +: 8];
        end
    endfunction

    integer i;

    initial begin
        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        start_wb(1'b1, 8'h2d, 32'hc0de_55aa, 4'b1011);
        @(negedge clk);
        cmd_ready = 1'b1;
        wr_line_ready = 1'b0;
        @(negedge clk);
        if (cmd_valid !== 1'b0 || wr_line_valid !== 1'b1) begin
            $display("[wb-line] write line was not offered before command cmd=%0b wr_valid=%0b",
                     cmd_valid, wr_line_valid);
            $fatal(1);
        end

        wr_line_ready = 1'b1;
        wait (wr_line_valid);
        #1;
        if (cmd_valid || !wr_line_valid) begin
            $display("[wb-line] command issued before write line loaded");
            $fatal(1);
        end
        if (wr_line_data[52*8 +: 32] !== 32'hc0de_55aa) begin
            $display("[wb-line] placed write word mismatch got=%h",
                     wr_line_data[52*8 +: 32]);
            $fatal(1);
        end
        if (wr_line_mask[55:52] !== 4'b0100) begin
            $display("[wb-line] write mask mismatch got=%b",
                     wr_line_mask[55:52]);
            $fatal(1);
        end
        @(negedge clk);
        wait (cmd_valid);
        if (!cmd_write || cmd_line_addr !== 4'h2) begin
            $display("[wb-line] write command mismatch write=%0b line=%h",
                     cmd_write, cmd_line_addr);
            $fatal(1);
        end
        #1;
        if (!cmd_valid || wr_line_valid || !cmd_write) begin
            $display("[wb-line] write command did not wait for preload");
            $fatal(1);
        end
        wait (wb_ack);
        if (wb_err) begin
            $display("[wb-line] write ack errored");
            $fatal(1);
        end

        @(negedge clk);
        cmd_ready = 1'b0;
        wr_line_ready = 1'b0;
        finish_wb();

        for (i = 0; i < LINE_BYTES; i = i + 1)
            rd_line_data[i * 8 +: 8] = 8'h40 + i[7:0];

        start_wb(1'b0, 8'h0e, 32'h0, 4'hf);
        wait (cmd_valid);
        if (cmd_write || cmd_line_addr !== 4'h0) begin
            $display("[wb-line] read command mismatch write=%0b line=%h",
                     cmd_write, cmd_line_addr);
            $fatal(1);
        end

        @(negedge clk);
        cmd_ready = 1'b1;
        @(negedge clk);
        cmd_ready = 1'b0;
        repeat (3) @(negedge clk);
        xfer_start = 1'b1;
        @(negedge clk);
        xfer_start = 1'b0;

        wait (rd_line_ready);
        @(negedge clk);
        rd_line_valid = 1'b1;
        @(negedge clk);
        rd_line_valid = 1'b0;
        wait (wb_ack);
        if (wb_err || wb_dat_r !== 32'h7b7a_7978) begin
            $display("[wb-line] read response mismatch data=%h err=%0b",
                     wb_dat_r, wb_err);
            $fatal(1);
        end
        finish_wb();

        $display("[wb-line] line-level Wishbone channel bridge passed");
        $finish;
    end

    initial begin
        repeat (200) @(posedge clk);
        $display("[wb-line] timeout cmd_valid=%0b cmd_ready=%0b wr_valid=%0b wr_ready=%0b ack=%0b stall=%0b rd_valid=%0b rd_ready=%0b",
                 cmd_valid, cmd_ready, wr_line_valid, wr_line_ready,
                 wb_ack, wb_stall, rd_line_valid, rd_line_ready);
        $fatal(1);
    end
endmodule

`default_nettype wire

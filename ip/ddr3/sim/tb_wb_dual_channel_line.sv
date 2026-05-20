`default_nettype none
`timescale 1ns/1ps

module tb_wb_dual_channel_line;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer LINE_ADDR_W = 25;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;

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
    reg [CHANNELS-1:0]          xfer_start = {CHANNELS{1'b0}};

    wire [CHANNELS-1:0]         wr_line_valid;
    reg [CHANNELS-1:0]          wr_line_ready = {CHANNELS{1'b0}};
    wire [(CHANNELS*LINE_DATA_W)-1:0] wr_line_data;
    wire [(CHANNELS*LINE_BYTES)-1:0]  wr_line_mask;

    wire [CHANNELS-1:0]         rd_line_ready;
    reg [CHANNELS-1:0]          rd_line_valid = {CHANNELS{1'b0}};
    reg [(CHANNELS*LINE_DATA_W)-1:0] rd_line_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};
    reg [CHANNELS-1:0]          rd_line_err = {CHANNELS{1'b0}};

    integer i;
    integer stage = 0;

    always #5 clk = ~clk;

    ddr3_wb_dual_channel_line dut (
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
        .o_phy_wr_line_data(wr_line_data),
        .o_phy_wr_line_mask(wr_line_mask),
        .o_phy_rd_line_ready(rd_line_ready),
        .i_phy_rd_line_valid(rd_line_valid),
        .i_phy_rd_line_data(rd_line_data),
        .i_phy_rd_line_err(rd_line_err)
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
        repeat (2) @(posedge clk);

        stage = 1;
        start_wb(1'b1, 30'h0000_002d, 32'hCAFE_BABE, 4'b1110);
        @(negedge clk);
        cmd_ready = 2'b01;
        if (cmd_valid[0] || wr_line_valid[0]) begin
            $display("[wb-dual-line] write command issued before line ready");
            $fatal(1);
        end
        wr_line_ready = 2'b01;
        wait (cmd_valid[0]);
        stage = 2;
        if (cmd_valid !== 2'b01 || !cmd_write[0] ||
            cmd_line_addr[0 +: LINE_ADDR_W] !== 25'h0000002) begin
            $display("[wb-dual-line] ch0 write command mismatch valid=%b write=%b line0=%h",
                     cmd_valid, cmd_write, cmd_line_addr[0 +: LINE_ADDR_W]);
            $fatal(1);
        end

        #1;
        if (wr_line_valid !== 2'b01) begin
            $display("[wb-dual-line] write line valid mismatch valid=%b",
                     wr_line_valid);
            $fatal(1);
        end
        if (wr_line_data[52*8 +: 32] !== 32'hCAFE_BABE) begin
            $display("[wb-dual-line] write data placement mismatch got=%h",
                     wr_line_data[52*8 +: 32]);
            $fatal(1);
        end
        if (wr_line_mask[55:52] !== 4'b0001) begin
            $display("[wb-dual-line] write mask placement mismatch got=%b",
                     wr_line_mask[55:52]);
            $fatal(1);
        end

        @(negedge clk);
        cmd_ready = 2'b00;
        wr_line_ready = 2'b00;

        stage = 3;
        wait (wb_ack);
        if (wb_err) begin
            $display("[wb-dual-line] ch0 write ack unexpectedly errored");
            $fatal(1);
        end
        finish_wb();

        for (i = 0; i < LINE_BYTES; i = i + 1)
            rd_line_data[LINE_DATA_W + (i * 8) +: 8] = 8'h40 + i[7:0];

        stage = 4;
        start_wb(1'b0, {1'b1, 29'h0000_000e}, 32'h0, 4'hF);
        wait (cmd_valid[1]);
        stage = 5;
        if (cmd_valid !== 2'b10 || cmd_write[1] ||
            cmd_line_addr[LINE_ADDR_W +: LINE_ADDR_W] !== 25'h0000000) begin
            $display("[wb-dual-line] ch1 read command mismatch valid=%b write=%b line1=%h",
                     cmd_valid, cmd_write,
                     cmd_line_addr[LINE_ADDR_W +: LINE_ADDR_W]);
            $fatal(1);
        end

        @(negedge clk);
        cmd_ready = 2'b10;
        xfer_start = 2'b10;
        @(negedge clk);
        cmd_ready = 2'b00;
        xfer_start = 2'b00;

        stage = 6;
        wait (rd_line_ready[1]);
        if (rd_line_ready[0]) begin
            $display("[wb-dual-line] ch0 read interface active during ch1 read");
            $fatal(1);
        end

        @(negedge clk);
        rd_line_valid = 2'b10;
        @(negedge clk);
        rd_line_valid = 2'b00;

        stage = 7;
        wait (wb_ack);
        if (wb_err || wb_dat_r !== 32'h7b7a_7978) begin
            $display("[wb-dual-line] ch1 read response mismatch data=%h err=%0b",
                     wb_dat_r, wb_err);
            $fatal(1);
        end
        finish_wb();

        $display("[wb-dual-line] full-capacity line dispatch passed");
        $finish;
    end

    initial begin
        repeat (300) @(posedge clk);
        $display("[wb-dual-line] timeout stage=%0d ack=%0b stall=%0b cmd_valid=%b rd_ready=%b owner_valid=%0b",
                 stage, wb_ack, wb_stall, cmd_valid, rd_line_ready,
                 dut.owner_valid);
        $fatal(1);
    end
endmodule

`default_nettype wire

`default_nettype none
`timescale 1ns/1ps

module tb_wb_frontend;
    localparam integer WB_ADDR_W = 5;
    localparam integer WB_DATA_W = 32;
    localparam integer LINE_BYTES = 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer WORD_INDEX_W = 1;
    localparam integer LINE_ADDR_W = WB_ADDR_W - WORD_INDEX_W;

    reg clk = 1'b0;
    reg rst = 1'b1;

    reg                    wb_cyc = 1'b0;
    reg                    wb_stb = 1'b0;
    reg                    wb_we = 1'b0;
    reg [WB_ADDR_W-1:0]    wb_adr = {WB_ADDR_W{1'b0}};
    reg [WB_DATA_W-1:0]    wb_dat_w = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0] wb_sel = {(WB_DATA_W/8){1'b0}};
    wire                   wb_stall;
    wire                   wb_ack;
    wire [WB_DATA_W-1:0]   wb_dat_r;
    wire                   wb_err;

    wire                    req_valid;
    reg                     req_ready = 1'b0;
    wire                    req_write;
    wire [LINE_ADDR_W-1:0]  req_line_addr;
    wire [WORD_INDEX_W-1:0] req_word_index;
    wire [LINE_DATA_W-1:0]  req_wr_data;
    wire [LINE_BYTES-1:0]   req_wr_mask;
    reg                     rsp_valid = 1'b0;
    reg [LINE_DATA_W-1:0]   rsp_data = {LINE_DATA_W{1'b0}};
    reg                     rsp_err = 1'b0;

    always #5 clk = ~clk;

    ddr3_wb_frontend #(
        .WB_ADDR_W(WB_ADDR_W),
        .LINE_BYTES(LINE_BYTES),
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
        .o_req_valid(req_valid),
        .i_req_ready(req_ready),
        .o_req_write(req_write),
        .o_req_line_addr(req_line_addr),
        .o_req_word_index(req_word_index),
        .o_req_wr_data(req_wr_data),
        .o_req_wr_mask(req_wr_mask),
        .i_rsp_valid(rsp_valid),
        .i_rsp_data(rsp_data),
        .i_rsp_err(rsp_err)
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

    initial begin
        repeat (3) @(posedge clk);
        rst = 1'b0;
        repeat (2) @(posedge clk);

        start_wb(1'b1, 5'h05, 32'hAA_BB_CC_DD, 4'b1011);
        wait (req_valid);
        if (!req_write || req_line_addr !== 4'h2 || req_word_index !== 1'b1) begin
            $display("[wb-frontend] write address decode mismatch write=%0b line=%h word=%h",
                     req_write, req_line_addr, req_word_index);
            $fatal(1);
        end
        if (req_wr_data !== 64'hAA_BB_CC_DD_0000_0000) begin
            $display("[wb-frontend] write data placement mismatch got=%h", req_wr_data);
            $fatal(1);
        end
        if (req_wr_mask !== 8'b1011_0000) begin
            $display("[wb-frontend] write mask placement mismatch got=%b", req_wr_mask);
            $fatal(1);
        end

        @(negedge clk);
        req_ready = 1'b0;
        @(negedge clk);
        req_ready = 1'b1;
        wait (wb_ack);
        if (wb_err) begin
            $display("[wb-frontend] write ack unexpectedly errored");
            $fatal(1);
        end
        @(negedge clk);
        req_ready = 1'b0;
        finish_wb();

        start_wb(1'b0, 5'h04, 32'h0, 4'hF);
        wait (req_valid);
        if (req_write || req_line_addr !== 4'h2 || req_word_index !== 1'b0) begin
            $display("[wb-frontend] read address decode mismatch write=%0b line=%h word=%h",
                     req_write, req_line_addr, req_word_index);
            $fatal(1);
        end

        @(negedge clk);
        req_ready = 1'b1;
        @(negedge clk);
        req_ready = 1'b0;
        repeat (2) @(negedge clk);
        rsp_data = 64'h1122_3344_5566_7788;
        rsp_err = 1'b0;
        rsp_valid = 1'b1;
        wait (wb_ack);
        if (wb_dat_r !== 32'h5566_7788 || wb_err) begin
            $display("[wb-frontend] read response mismatch data=%h err=%0b",
                     wb_dat_r, wb_err);
            $fatal(1);
        end
        @(negedge clk);
        rsp_valid = 1'b0;
        rsp_data = {LINE_DATA_W{1'b0}};
        finish_wb();

        $display("[wb-frontend] write mask/data mapping and read word select passed");
        $finish;
    end

    initial begin
        repeat (200) @(posedge clk);
        $display("[wb-frontend] timeout ack=%0b stall=%0b req_valid=%0b req_ready=%0b rsp_valid=%0b",
                 wb_ack, wb_stall, req_valid, req_ready, rsp_valid);
        $fatal(1);
    end
endmodule

`default_nettype wire

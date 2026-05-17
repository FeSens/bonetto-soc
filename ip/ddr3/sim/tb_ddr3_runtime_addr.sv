`timescale 1ns/1ps
`default_nettype none

`include "ddr3_cmd.vh"

module tb_ddr3_runtime_addr;
    localparam integer WB_DATA_W = 32;
    localparam integer WB_BYTES = WB_DATA_W / 8;
    localparam integer ROW_BITS = 15;
    localparam integer BANK_BITS = 3;
    localparam integer COL_BITS = 10;
    localparam integer DQ_BITS = 8;
    localparam integer NUM_BYTE_LANES = 8;
    localparam integer SERDES_RATIO = 8;
    localparam integer WB_BURST_WORD_BITS = 4;
    localparam integer COL_HI_BITS = COL_BITS - 3;
    localparam integer WB_ADDR_W = BANK_BITS + ROW_BITS + COL_HI_BITS + WB_BURST_WORD_BITS;
    localparam integer PHY_DATA_W = NUM_BYTE_LANES * DQ_BITS * SERDES_RATIO;

    reg clk = 1'b0;
    always #5 clk = ~clk;

    reg rst;
    reg init_done;
    reg wb_cyc;
    reg wb_stb;
    reg wb_we;
    reg [WB_ADDR_W-1:0] wb_adr;
    reg [WB_DATA_W-1:0] wb_dat;
    reg [WB_BYTES-1:0] wb_sel;
    wire wb_stall;
    wire wb_ack;
    wire [WB_DATA_W-1:0] wb_dat_r;
    wire wb_err;

    wire cmd_valid;
    wire [3:0] cmd;
    wire [BANK_BITS-1:0] cmd_ba;
    wire [ROW_BITS-1:0] cmd_addr;
    wire cmd_odt;

    wire [PHY_DATA_W-1:0] wr_data;
    wire wr_valid;
    wire rd_capture;

    reg [PHY_DATA_W-1:0] rd_data;
    reg rd_valid;

    reg mpr_req;
    reg [12:0] mpr_addr;
    wire mpr_busy;

    reg mrs_req;
    reg [BANK_BITS-1:0] mrs_ba;
    reg [ROW_BITS-1:0] mrs_addr;
    wire mrs_busy;

    ddr3_runtime #(
        .WB_DATA_W(WB_DATA_W),
        .WB_ADDR_W(WB_ADDR_W),
        .ROW_BITS(ROW_BITS),
        .BANK_BITS(BANK_BITS),
        .COL_BITS(COL_BITS),
        .DQ_BITS(DQ_BITS),
        .NUM_BYTE_LANES(NUM_BYTE_LANES),
        .SERDES_RATIO(SERDES_RATIO),
        .WB_BURST_WORD_BITS(WB_BURST_WORD_BITS)
    ) dut (
        .i_clk_phy(clk),
        .i_rst(rst),
        .i_init_done(init_done),
        .i_wb_cyc(wb_cyc),
        .i_wb_stb(wb_stb),
        .i_wb_we(wb_we),
        .i_wb_adr(wb_adr),
        .i_wb_dat(wb_dat),
        .i_wb_sel(wb_sel),
        .o_wb_stall(wb_stall),
        .o_wb_ack(wb_ack),
        .o_wb_dat(wb_dat_r),
        .o_wb_err(wb_err),
        .o_cmd_valid(cmd_valid),
        .o_cmd(cmd),
        .o_cmd_ba(cmd_ba),
        .o_cmd_addr(cmd_addr),
        .o_cmd_odt(cmd_odt),
        .i_rd_data(rd_data),
        .i_rd_valid(rd_valid),
        .o_wr_data(wr_data),
        .o_wr_valid(wr_valid),
        .o_rd_capture(rd_capture),
        .i_mpr_req(mpr_req),
        .i_mpr_addr(mpr_addr),
        .o_mpr_busy(mpr_busy),
        .i_mrs_req(mrs_req),
        .i_mrs_ba(mrs_ba),
        .i_mrs_addr(mrs_addr),
        .o_mrs_busy(mrs_busy)
    );

    function [WB_ADDR_W-1:0] make_addr;
        input [BANK_BITS-1:0] bank;
        input [ROW_BITS-1:0] row;
        input [COL_HI_BITS-1:0] col_hi;
        input [WB_BURST_WORD_BITS-1:0] offset;
        begin
            make_addr = {bank, row, col_hi, offset};
        end
    endfunction

    function [PHY_DATA_W-1:0] burst_put_word;
        input [PHY_DATA_W-1:0] burst_data;
        input integer word_offset;
        input [WB_DATA_W-1:0] word_data;
        input [WB_BYTES-1:0] word_sel;
        integer byte_idx;
        integer bit_idx;
        integer burst_byte;
        integer lane_idx;
        integer sample_idx;
        begin
            burst_put_word = burst_data;
            for (byte_idx = 0; byte_idx < WB_BYTES; byte_idx = byte_idx + 1) begin
                if (word_sel[byte_idx]) begin
                    burst_byte = (word_offset * WB_BYTES) + byte_idx;
                    lane_idx   = burst_byte % NUM_BYTE_LANES;
                    sample_idx = burst_byte / NUM_BYTE_LANES;
                    for (bit_idx = 0; bit_idx < 8; bit_idx = bit_idx + 1) begin
                        burst_put_word[lane_idx*DQ_BITS*SERDES_RATIO +
                                       bit_idx*SERDES_RATIO +
                                       sample_idx] =
                            word_data[byte_idx*8 + bit_idx];
                    end
                end
            end
        end
    endfunction

    function [WB_DATA_W-1:0] burst_get_word;
        input [PHY_DATA_W-1:0] burst_data;
        input integer word_offset;
        integer byte_idx;
        integer bit_idx;
        integer burst_byte;
        integer lane_idx;
        integer sample_idx;
        begin
            burst_get_word = {WB_DATA_W{1'b0}};
            for (byte_idx = 0; byte_idx < WB_BYTES; byte_idx = byte_idx + 1) begin
                burst_byte = (word_offset * WB_BYTES) + byte_idx;
                lane_idx   = burst_byte % NUM_BYTE_LANES;
                sample_idx = burst_byte / NUM_BYTE_LANES;
                for (bit_idx = 0; bit_idx < 8; bit_idx = bit_idx + 1) begin
                    burst_get_word[byte_idx*8 + bit_idx] =
                        burst_data[lane_idx*DQ_BITS*SERDES_RATIO +
                                   bit_idx*SERDES_RATIO +
                                   sample_idx];
                end
            end
        end
    endfunction

    function [WB_DATA_W-1:0] merge_word;
        input [WB_DATA_W-1:0] old_word;
        input [WB_DATA_W-1:0] new_word;
        input [WB_BYTES-1:0] sel;
        integer byte_idx;
        begin
            merge_word = old_word;
            for (byte_idx = 0; byte_idx < WB_BYTES; byte_idx = byte_idx + 1) begin
                if (sel[byte_idx])
                    merge_word[byte_idx*8 +: 8] = new_word[byte_idx*8 +: 8];
            end
        end
    endfunction

    task automatic issue_xact;
        input is_write;
        input [WB_ADDR_W-1:0] adr;
        input [WB_DATA_W-1:0] dat;
        input [WB_BYTES-1:0] sel;
        input [BANK_BITS-1:0] exp_bank;
        input [ROW_BITS-1:0] exp_row;
        output reg [WB_DATA_W-1:0] read_data;
        output reg [ROW_BITS-1:0] read_addr;
        output reg [ROW_BITS-1:0] write_addr;
        output reg [PHY_DATA_W-1:0] write_burst;
        output reg saw_read;
        output reg saw_write;
        integer cycle;
        reg saw_act;
        begin
            wb_cyc = 1'b1;
            wb_stb = 1'b1;
            wb_we = is_write;
            wb_adr = adr;
            wb_dat = dat;
            wb_sel = sel;

            @(posedge clk);
            #1;
            wb_stb = 1'b0;
            saw_act = 1'b0;
            saw_read = 1'b0;
            saw_write = 1'b0;
            read_data = {WB_DATA_W{1'b0}};
            read_addr = {ROW_BITS{1'b0}};
            write_addr = {ROW_BITS{1'b0}};
            write_burst = {PHY_DATA_W{1'b0}};

            for (cycle = 0; cycle < 300; cycle = cycle + 1) begin
                @(posedge clk);
                #1;
                if (cmd_valid) begin
                    if (cmd == `DDR3_CMD_ACT) begin
                        saw_act = 1'b1;
                        if (cmd_ba !== exp_bank) begin
                            $display("FAIL: ACT bank got %0d expected %0d", cmd_ba, exp_bank);
                            $finish_and_return(1);
                        end
                        if (cmd_addr !== exp_row) begin
                            $display("FAIL: ACT row got 0x%04h expected 0x%04h", cmd_addr, exp_row);
                            $finish_and_return(1);
                        end
                    end else if (cmd == `DDR3_CMD_READ) begin
                        saw_read = 1'b1;
                        if (cmd_ba !== exp_bank) begin
                            $display("FAIL: READ bank got %0d expected %0d", cmd_ba, exp_bank);
                            $finish_and_return(1);
                        end
                        read_addr = cmd_addr;
                    end else if (cmd == `DDR3_CMD_WRITE) begin
                        saw_write = 1'b1;
                        if (cmd_ba !== exp_bank) begin
                            $display("FAIL: WRITE bank got %0d expected %0d", cmd_ba, exp_bank);
                            $finish_and_return(1);
                        end
                        write_addr = cmd_addr;
                        write_burst = wr_data;
                    end
                end

                if (wb_ack) begin
                    read_data = wb_dat_r;
                    wb_cyc = 1'b0;
                    if (!saw_act) begin
                        $display("FAIL: transaction acked without ACT");
                        $finish_and_return(1);
                    end
                    return;
                end
            end

            $display("FAIL: transaction did not ack");
            $finish_and_return(1);
        end
    endtask

    integer i;
    reg [BANK_BITS-1:0] bank;
    reg [ROW_BITS-1:0] row;
    reg [COL_HI_BITS-1:0] col_hi;
    reg [COL_BITS-1:0] expected_col;
    reg [WB_DATA_W-1:0] got_read;
    reg [WB_DATA_W-1:0] old_word;
    reg [WB_DATA_W-1:0] new_word;
    reg [WB_DATA_W-1:0] expected_word;
    reg [ROW_BITS-1:0] read_addr;
    reg [ROW_BITS-1:0] write_addr;
    reg [PHY_DATA_W-1:0] captured_write_burst;
    reg saw_read;
    reg saw_write;

    initial begin
        rst = 1'b1;
        init_done = 1'b0;
        wb_cyc = 1'b0;
        wb_stb = 1'b0;
        wb_we = 1'b0;
        wb_adr = {WB_ADDR_W{1'b0}};
        wb_dat = {WB_DATA_W{1'b0}};
        wb_sel = {WB_BYTES{1'b0}};
        rd_data = {PHY_DATA_W{1'b0}};
        rd_valid = 1'b1;
        mpr_req = 1'b0;
        mpr_addr = 13'd0;
        mrs_req = 1'b0;
        mrs_ba = {BANK_BITS{1'b0}};
        mrs_addr = {ROW_BITS{1'b0}};

        for (i = 0; i < 5; i = i + 1)
            @(posedge clk);
        init_done = 1'b1;
        rst = 1'b0;
        @(posedge clk);

        bank = 3'b101;
        row = 15'h1234;
        col_hi = 7'h55;
        expected_col = {col_hi, 3'b000};

        for (i = 0; i < 16; i = i + 1)
            rd_data = burst_put_word(rd_data, i, 32'ha500_0000 + i[31:0], 4'hf);

        issue_xact(
            1'b0, make_addr(bank, row, col_hi, 4'hf), 32'h0, 4'hf, bank, row,
            got_read, read_addr, write_addr, captured_write_burst, saw_read, saw_write
        );
        if (!saw_read || saw_write) begin
            $display("FAIL: read path command sequence saw_read=%0d saw_write=%0d",
                     saw_read, saw_write);
            $finish_and_return(1);
        end
        if (read_addr[COL_BITS-1:0] !== expected_col) begin
            $display("FAIL: read column got 0x%03h expected 0x%03h",
                     read_addr[COL_BITS-1:0], expected_col);
            $finish_and_return(1);
        end
        if (got_read !== 32'ha500_000f) begin
            $display("FAIL: read offset f got 0x%08h expected 0xa500000f", got_read);
            $finish_and_return(1);
        end

        for (i = 0; i < 20; i = i + 1)
            @(posedge clk);

        old_word = burst_get_word(rd_data, 15);
        new_word = 32'h1234_5678;
        expected_word = merge_word(old_word, new_word, 4'b0101);
        issue_xact(
            1'b1, make_addr(bank, row, col_hi, 4'hf), new_word, 4'b0101, bank, row,
            got_read, read_addr, write_addr, captured_write_burst, saw_read, saw_write
        );
        if (!saw_read || !saw_write) begin
            $display("FAIL: RMW write sequence saw_read=%0d saw_write=%0d",
                     saw_read, saw_write);
            $finish_and_return(1);
        end
        if (read_addr[COL_BITS-1:0] !== expected_col ||
            write_addr[COL_BITS-1:0] !== expected_col) begin
            $display("FAIL: RMW column read=0x%03h write=0x%03h expected=0x%03h",
                     read_addr[COL_BITS-1:0], write_addr[COL_BITS-1:0], expected_col);
            $finish_and_return(1);
        end
        if (burst_get_word(captured_write_burst, 15) !== expected_word) begin
            $display("FAIL: RMW merged word got 0x%08h expected 0x%08h",
                     burst_get_word(captured_write_burst, 15), expected_word);
            $finish_and_return(1);
        end
        if (burst_get_word(captured_write_burst, 0) !== 32'ha500_0000) begin
            $display("FAIL: RMW modified unrelated offset 0: 0x%08h",
                     burst_get_word(captured_write_burst, 0));
            $finish_and_return(1);
        end
        if (write_addr[10] !== 1'b0 || read_addr[10] !== 1'b0) begin
            $display("FAIL: RMW command unexpectedly set A10 auto-precharge");
            $finish_and_return(1);
        end

        $display("PASS: BL8 word offset read select and RMW write merge");
        $finish_and_return(0);
    end

    /* verilator lint_off UNUSED */
    wire _unused = &{1'b0, wb_stall, wb_err, cmd_odt, wr_valid, rd_capture,
                     mpr_busy, mrs_busy, 1'b0};
    /* verilator lint_on UNUSED */
endmodule

`default_nettype wire

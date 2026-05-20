`default_nettype none
`timescale 1ps/1ps

`include "ddr3_params.vh"

module tb_micron_x8_phy_agent;
    localparam integer TCK_PS = `DDR3_800_TCK_PS;
    localparam [63:0] FIRST_PATTERN = 64'h8877_6655_4433_2211;
    localparam [63:0] SECOND_PATTERN = 64'haabb_ccdd_eeff_1020;
    localparam [7:0]  SECOND_MASK = 8'b1010_0101;
    localparam [63:0] MERGED_PATTERN = 64'h88bb_66dd_ee33_1011;

    reg ck = 1'b0;
    wire ck_n = ~ck;
    reg rst = 1'b1;
    reg start = 1'b1;

    wire init_done;
    wire init_reset_n;
    wire init_cke;
    wire init_odt;
    wire init_cmd_valid;
    wire init_cs_n;
    wire init_ras_n;
    wire init_cas_n;
    wire init_we_n;
    wire [2:0] init_ba;
    wire [14:0] init_addr;

    reg run_cmd_valid = 1'b0;
    reg [3:0] run_cmd = `DDR3_CMD_NOP;
    reg [2:0] run_ba = 3'd0;
    reg [14:0] run_addr = 15'd0;

    wire mux_cmd_valid = init_done ? run_cmd_valid : init_cmd_valid;
    wire mux_cs_n = init_done ? run_cmd[3] : init_cs_n;
    wire mux_ras_n = init_done ? run_cmd[2] : init_ras_n;
    wire mux_cas_n = init_done ? run_cmd[1] : init_cas_n;
    wire mux_we_n = init_done ? run_cmd[0] : init_we_n;
    wire [2:0] mux_ba = init_done ? run_ba : init_ba;
    wire [14:0] mux_addr = init_done ? run_addr : init_addr;

    reg seed_inputs = 1'b1;
    reg model_reset_n = 1'b1;
    reg model_cke = 1'b1;
    reg model_odt = 1'b0;
    reg model_cs_n = 1'b0;
    reg model_ras_n = 1'b1;
    reg model_cas_n = 1'b1;
    reg model_we_n = 1'b1;
    reg [2:0] model_ba = 3'h7;
    reg [14:0] model_addr = 15'h7fff;

    wire [7:0] dq;
    wire [0:0] dqs;
    wire [0:0] dqs_n;
    wire [0:0] dm_tdqs;
    wire [0:0] tdqs_n;

    reg lane_start = 1'b0;
    reg lane_write = 1'b0;
    reg [63:0] lane_wr_data = 64'd0;
    reg [7:0] lane_wr_mask = 8'hff;
    wire lane_ready;
    wire lane_done;
    wire lane_phy_wr_valid;
    wire lane_phy_wr_ready;
    wire [7:0] lane_phy_wr_data;
    wire lane_phy_wr_mask;
    wire lane_phy_wr_last;
    wire lane_phy_rd_ready;
    wire lane_phy_rd_valid;
    wire [7:0] lane_phy_rd_data;
    wire lane_rd_valid;
    wire [63:0] lane_rd_data;
    wire model_cmd_valid_agent = !model_cs_n &&
        ({model_cs_n, model_ras_n, model_cas_n, model_we_n} != `DDR3_CMD_NOP);

    always #(TCK_PS / 2) ck <= ~ck;

    pullup p_dm[0:0]  (dm_tdqs);
    pullup p_dq[7:0]  (dq);
    pullup p_dqs[0:0] (dqs);
    pulldown p_dqsn[0:0] (dqs_n);

    ddr3_init_seq #(
        .RESET_LOW_CYCLES(16),
        .RESET_CKE_CYCLES(20)
    ) u_init (
        .i_clk(ck),
        .i_rst(rst),
        .i_start(start),
        .o_reset_n(init_reset_n),
        .o_cke(init_cke),
        .o_odt(init_odt),
        .o_cmd_valid(init_cmd_valid),
        .o_cs_n(init_cs_n),
        .o_ras_n(init_ras_n),
        .o_cas_n(init_cas_n),
        .o_we_n(init_we_n),
        .o_ba(init_ba),
        .o_addr(init_addr),
        .o_busy(),
        .o_done(init_done),
        .o_state()
    );

    ddr3_byte_lane u_lane (
        .i_clk(ck),
        .i_rst(rst),
        .i_start(lane_start),
        .o_ready(lane_ready),
        .i_write(lane_write),
        .i_wr_data(lane_wr_data),
        .i_wr_mask(lane_wr_mask),
        .o_busy(),
        .o_done(lane_done),
        .o_phy_wr_valid(lane_phy_wr_valid),
        .i_phy_wr_ready(lane_phy_wr_ready),
        .o_phy_wr_data(lane_phy_wr_data),
        .o_phy_wr_mask(lane_phy_wr_mask),
        .o_phy_wr_last(lane_phy_wr_last),
        .o_phy_rd_ready(lane_phy_rd_ready),
        .i_phy_rd_valid(lane_phy_rd_valid),
        .i_phy_rd_data(lane_phy_rd_data),
        .o_rd_valid(lane_rd_valid),
        .o_rd_data(lane_rd_data)
    );

    ddr3_x8_phy_agent u_agent (
        .i_clk(ck),
        .i_rst(rst),
        .i_cmd_valid(model_cmd_valid_agent),
        .i_cmd({model_cs_n, model_ras_n, model_cas_n, model_we_n}),
        .i_phy_wr_valid(lane_phy_wr_valid),
        .o_phy_wr_ready(lane_phy_wr_ready),
        .i_phy_wr_data(lane_phy_wr_data),
        .i_phy_wr_mask(lane_phy_wr_mask),
        .i_phy_wr_last(lane_phy_wr_last),
        .i_phy_rd_ready(lane_phy_rd_ready),
        .o_phy_rd_valid(lane_phy_rd_valid),
        .o_phy_rd_data(lane_phy_rd_data),
        .io_dq(dq),
        .io_dqs(dqs[0]),
        .io_dqs_n(dqs_n[0]),
        .io_dm_tdqs(dm_tdqs[0])
    );

    ddr3 #(
        .SIMUL_500US(0),
        .SIMUL_200US(0)
    ) u_model (
        .rst_n(model_reset_n),
        .ck(ck),
        .ck_n(ck_n),
        .cke(model_cke),
        .cs_n(model_cs_n),
        .ras_n(model_ras_n),
        .cas_n(model_cas_n),
        .we_n(model_we_n),
        .dm_tdqs(dm_tdqs),
        .ba(model_ba),
        .addr(model_addr),
        .dq(dq),
        .dqs(dqs),
        .dqs_n(dqs_n),
        .tdqs_n(tdqs_n),
        .odt(model_odt)
    );

    always @(negedge ck) begin
        if (!seed_inputs) begin
            model_reset_n <= init_reset_n;
            model_cke     <= init_cke;
            model_odt     <= init_done ? 1'b0 : init_odt;
            model_cs_n    <= mux_cmd_valid ? mux_cs_n : 1'b1;
            model_ras_n   <= mux_ras_n;
            model_cas_n   <= mux_cas_n;
            model_we_n    <= mux_we_n;
            model_ba      <= mux_ba;
            model_addr    <= mux_addr;
        end
    end

    task issue_cmd;
        input [3:0] cmd;
        input [2:0] ba;
        input [14:0] addr;
        begin
            @(posedge ck);
            run_cmd_valid <= 1'b1;
            run_cmd <= cmd;
            run_ba <= ba;
            run_addr <= addr;
            @(posedge ck);
            run_cmd_valid <= 1'b0;
            run_cmd <= `DDR3_CMD_NOP;
            run_ba <= 3'd0;
            run_addr <= 15'd0;
        end
    endtask

    task wait_cycles;
        input integer cycles;
        integer i;
        begin
            for (i = 0; i < cycles; i = i + 1)
                @(posedge ck);
        end
    endtask

    task do_write;
        input [63:0] data;
        input [7:0] mask;
        begin
            wait (lane_ready);
            @(negedge ck);
            lane_write = 1'b1;
            lane_wr_data = data;
            lane_wr_mask = mask;
            lane_start = 1'b1;
            issue_cmd(`DDR3_CMD_WR, 3'd0, 15'h0000);
            @(negedge ck);
            lane_start = 1'b0;
            wait (lane_done);
        end
    endtask

    task do_read;
        input [63:0] expected;
        begin
            wait (lane_ready);
            @(negedge ck);
            lane_write = 1'b0;
            lane_start = 1'b1;
            issue_cmd(`DDR3_CMD_RD, 3'd0, 15'h0000);
            @(negedge ck);
            lane_start = 1'b0;
            wait (lane_rd_valid);
            if (lane_rd_data !== expected) begin
                $display("[micron-x8-agent] read mismatch expected=%h got=%h",
                         expected, lane_rd_data);
                $fatal(1);
            end
        end
    endtask

    initial begin
        #1;
        model_reset_n = 1'b0;
        model_cke = 1'b0;
        model_cs_n = 1'b1;
        model_ba = 3'd0;
        model_addr = 15'd0;
        seed_inputs = 1'b0;
        repeat (4) @(posedge ck);
        rst = 1'b0;

        wait (init_done);
        wait_cycles(4);

        issue_cmd(`DDR3_CMD_ACT, 3'd0, 15'h0123);
        wait_cycles(`DDR3_800_TRCD_CYCLES);

        do_write(FIRST_PATTERN, 8'h00);
        wait_cycles(`DDR3_800_TCCD_CYCLES);

        do_write(SECOND_PATTERN, SECOND_MASK);
        wait_cycles(`DDR3_800_TWTR_CMD_CYCLES);

        do_read(MERGED_PATTERN);

        $display("[micron-x8-agent] DQS/DQ agent write/read mask loopback passed");
        $finish;
    end

    initial begin
        repeat (1500) @(posedge ck);
        $display("[micron-x8-agent] timeout init_done=%0b lane_ready=%0b",
                 init_done, lane_ready);
        $fatal(1);
    end
endmodule

`default_nettype wire

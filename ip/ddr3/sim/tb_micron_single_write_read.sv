`default_nettype none
`timescale 1ps/1ps
`include "ddr3_params.vh"

module tb_micron_single_write_read;
    localparam integer TCK_PS = `DDR3_800_TCK_PS;
    localparam [63:0] WRITE_PATTERN = 64'h5a_c3_00_ff_96_69_3c_a5;

    reg ck = 1'b0;
    wire ck_n = ~ck;
    reg rst = 1'b1;
    reg start = 1'b1;

    wire init_done;
    wire [4:0] init_state;
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

    wire run_done;
    wire [3:0] run_state;
    wire run_cmd_valid;
    wire run_cs_n;
    wire run_ras_n;
    wire run_cas_n;
    wire run_we_n;
    wire [2:0] run_ba;
    wire [14:0] run_addr;

    wire mux_cmd_valid = init_done ? run_cmd_valid : init_cmd_valid;
    wire mux_cs_n      = init_done ? run_cs_n      : init_cs_n;
    wire mux_ras_n     = init_done ? run_ras_n     : init_ras_n;
    wire mux_cas_n     = init_done ? run_cas_n     : init_cas_n;
    wire mux_we_n      = init_done ? run_we_n      : init_we_n;
    wire [2:0] mux_ba  = init_done ? run_ba        : init_ba;
    wire [14:0] mux_addr = init_done ? run_addr    : init_addr;

    wire [0:0] dm_tdqs;
    wire [7:0] dq;
    wire [0:0] dqs;
    wire [0:0] dqs_n;
    wire [0:0] tdqs_n;

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

    reg dm_drive_en = 1'b0;
    reg dm_drive = 1'b1;
    reg dq_drive_en = 1'b0;
    reg [7:0] dq_drive = 8'hff;
    reg dqs_drive_en = 1'b0;
    reg dqs_drive = 1'b0;

    reg lane_start = 1'b0;
    reg lane_write = 1'b0;
    reg [63:0] lane_wr_data = WRITE_PATTERN;
    reg [7:0] lane_wr_mask = 8'd0;
    reg lane_phy_wr_ready = 1'b0;
    reg lane_phy_rd_valid = 1'b0;
    reg [7:0] lane_phy_rd_data = 8'd0;
    wire lane_ready;
    wire lane_busy;
    wire lane_done;
    wire lane_phy_wr_valid;
    wire [7:0] lane_phy_wr_data;
    wire lane_phy_wr_mask;
    wire lane_phy_wr_last;
    wire lane_phy_rd_ready;
    wire lane_rd_valid;
    wire [63:0] lane_rd_data;

    reg write_prefetch_done = 1'b0;
    reg read_lane_done = 1'b0;
    reg [7:0] write_burst [0:7];
    reg [7:0] write_masks;
    reg write_seen = 1'b0;
    reg capture_active = 1'b0;
    reg read_seen = 1'b0;
    integer read_count = 0;
    reg [63:0] read_pattern = 64'd0;

    assign dm_tdqs[0] = dm_drive_en ? dm_drive : 1'bz;
    assign dq = dq_drive_en ? dq_drive : 8'hzz;
    assign dqs[0] = dqs_drive_en ? dqs_drive : 1'bz;
    assign dqs_n[0] = dqs_drive_en ? ~dqs_drive : 1'bz;

    pullup p_dm[0:0]  (dm_tdqs);
    pullup p_dq[7:0]  (dq);
    pullup p_dqs[0:0] (dqs);
    pulldown p_dqsn[0:0] (dqs_n);

    always #(TCK_PS / 2) ck <= ~ck;

    ddr3_init_seq #(
        .RESET_LOW_CYCLES(16),
        .RESET_CKE_CYCLES(20)
    ) u_init (
        .i_clk(ck),
        .i_rst(rst),
        .i_start(start),
        .o_busy(),
        .o_done(init_done),
        .o_state(init_state),
        .o_reset_n(init_reset_n),
        .o_cke(init_cke),
        .o_odt(init_odt),
        .o_cmd_valid(init_cmd_valid),
        .o_cs_n(init_cs_n),
        .o_ras_n(init_ras_n),
        .o_cas_n(init_cas_n),
        .o_we_n(init_we_n),
        .o_ba(init_ba),
        .o_addr(init_addr)
    );

    ddr3_single_write_read_seq u_run (
        .i_clk(ck),
        .i_rst(rst),
        .i_start(init_done),
        .o_busy(),
        .o_done(run_done),
        .o_state(run_state),
        .o_cmd_valid(run_cmd_valid),
        .o_cs_n(run_cs_n),
        .o_ras_n(run_ras_n),
        .o_cas_n(run_cas_n),
        .o_we_n(run_we_n),
        .o_ba(run_ba),
        .o_addr(run_addr)
    );

    ddr3_byte_lane u_lane (
        .i_clk(ck),
        .i_rst(rst),
        .i_start(lane_start),
        .o_ready(lane_ready),
        .i_write(lane_write),
        .i_wr_data(lane_wr_data),
        .i_wr_mask(lane_wr_mask),
        .o_busy(lane_busy),
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

    always @(posedge ck) begin
        if ({model_cs_n, model_ras_n, model_cas_n, model_we_n} == `DDR3_CMD_WR && !write_seen) begin
            write_seen <= 1'b1;
            fork
                drive_write_burst();
            join_none
        end

        if ({model_cs_n, model_ras_n, model_cas_n, model_we_n} == `DDR3_CMD_RD) begin
            capture_active <= 1'b1;
            read_seen <= 1'b1;
            read_count <= 0;
            read_pattern <= 64'd0;
            fork
                capture_read_burst();
            join_none
        end
    end

    task automatic drive_write_burst;
        integer i;
        begin
            if (!write_prefetch_done) begin
                $display("[micron-single-write-read] byte-lane write payload was not ready");
                $fatal(1);
            end

            repeat (`DDR3_800_CWL_CYCLES) @(posedge ck);

            dq_drive = write_burst[0];
            dq_drive_en = 1'b1;
            dm_drive = write_masks[0];
            dm_drive_en = 1'b1;
            dqs_drive = 1'b0;
            dqs_drive_en = 1'b1;

            #(TCK_PS / 4);
            for (i = 0; i < 8; i = i + 1) begin
                dqs_drive = ~dqs_drive;
                #200;
                if (i < 7) begin
                    dq_drive = write_burst[i + 1];
                    dm_drive = write_masks[i + 1];
                end
                #(TCK_PS / 2 - 200);
            end

            #(TCK_PS / 2);
            dqs_drive = 1'b0;
            #(TCK_PS / 2);
            dqs_drive_en = 1'b0;
            dq_drive_en = 1'b0;
            dm_drive_en = 1'b0;
            dq_drive = 8'hff;
            dm_drive = 1'b1;
        end
    endtask

    task automatic capture_read_burst;
        integer i;
        begin
            repeat (`DDR3_800_CL_CYCLES - 1) @(posedge ck);
            @(negedge ck);
            #(TCK_PS / 2 + 10);

            for (i = 0; i < 8; i = i + 1) begin
                read_pattern[i * 8 +: 8] = dq;
                read_count = i + 1;
                if (i < 7) begin
                    #(TCK_PS / 2);
                end
            end

            capture_active = 1'b0;
            feed_lane_read_burst(read_pattern);
        end
    endtask

    task automatic prefetch_lane_write_burst;
        integer i;
        begin
            wait (!rst);
            wait (lane_ready);
            @(negedge ck);
            lane_write = 1'b1;
            lane_wr_data = WRITE_PATTERN;
            lane_wr_mask = 8'd0;
            lane_start = 1'b1;
            @(negedge ck);
            lane_start = 1'b0;

            i = 0;
            while (i < 8) begin
                @(negedge ck);
                lane_phy_wr_ready = 1'b1;
                if (lane_phy_wr_valid) begin
                    write_burst[i] = lane_phy_wr_data;
                    write_masks[i] = lane_phy_wr_mask;
                    if (lane_phy_wr_last !== (i == 7)) begin
                        $display("[micron-single-write-read] byte-lane write last mismatch beat=%0d last=%0b",
                                 i, lane_phy_wr_last);
                        $fatal(1);
                    end
                    i = i + 1;
                end
            end

            @(negedge ck);
            lane_phy_wr_ready = 1'b0;
            wait (lane_done);
            write_prefetch_done = 1'b1;
        end
    endtask

    task automatic feed_lane_read_burst;
        input [63:0] data;
        integer i;
        begin
            wait (lane_ready);
            @(negedge ck);
            lane_write = 1'b0;
            lane_start = 1'b1;
            @(negedge ck);
            lane_start = 1'b0;

            for (i = 0; i < 8; i = i + 1) begin
                @(negedge ck);
                if (!lane_phy_rd_ready) begin
                    $display("[micron-single-write-read] byte-lane read side not ready at beat=%0d",
                             i);
                    $fatal(1);
                end
                lane_phy_rd_data = pattern_from_line(data, i);
                lane_phy_rd_valid = 1'b1;
            end

            @(negedge ck);
            lane_phy_rd_valid = 1'b0;
            lane_phy_rd_data = 8'd0;
            wait (lane_rd_valid);
            if (lane_rd_data !== data) begin
                $display("[micron-single-write-read] byte-lane read mismatch: expected=%h got=%h",
                         data, lane_rd_data);
                $fatal(1);
            end
            read_lane_done = 1'b1;
        end
    endtask

    function [7:0] pattern_from_line;
        input [63:0] data;
        input integer index;
        begin
            pattern_from_line = data[index * 8 +: 8];
        end
    endfunction

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
        fork
            prefetch_lane_write_burst();
        join_none

        wait (run_done);
        repeat (`DDR3_800_TRFC_CYCLES) @(posedge ck);

        if (!write_seen) begin
            $display("[micron-single-write-read] WRITE command was not observed");
            $fatal(1);
        end
        if (!read_seen || read_count != 8) begin
            $display("[micron-single-write-read] incomplete read capture: seen=%0b count=%0d data=%h",
                     read_seen, read_count, read_pattern);
            $fatal(1);
        end
        if (!read_lane_done) begin
            $display("[micron-single-write-read] byte-lane read path did not complete");
            $fatal(1);
        end
        if (read_pattern !== WRITE_PATTERN) begin
            $display("[micron-single-write-read] data mismatch: expected=%h got=%h",
                     WRITE_PATTERN, read_pattern);
            $fatal(1);
        end
        if (lane_rd_data !== WRITE_PATTERN) begin
            $display("[micron-single-write-read] byte-lane loopback mismatch: expected=%h got=%h",
                     WRITE_PATTERN, lane_rd_data);
            $fatal(1);
        end

        $display("[micron-single-write-read] init state=%0d runtime state=%0d pattern=%h byte_lane=%h",
                 init_state, run_state, read_pattern, lane_rd_data);
        $finish;
    end

    initial begin
        repeat (10000) @(posedge ck);
        $display("[micron-single-write-read] timeout: init=%0d run=%0d run_done=%0b write=%0b read=%0b count=%0d data=%h cmd=%b ba=%0d addr=%h",
                 init_state, run_state, run_done, write_seen, read_seen, read_count, read_pattern,
                 {model_cs_n, model_ras_n, model_cas_n, model_we_n}, model_ba, model_addr);
        $fatal(1);
    end
endmodule

`default_nettype wire

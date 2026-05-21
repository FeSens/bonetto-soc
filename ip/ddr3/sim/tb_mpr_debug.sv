`default_nettype none
`timescale 1ps/1ps

module tb_mpr_debug;
    localparam integer CHANNELS = 2;
    localparam integer ADDR_BITS = 15;
    localparam integer BANK_BITS = 3;

    reg clk = 1'b0;
    reg rst = 1'b1;
    always #10000 clk = !clk;

    reg [31:0] cmd_word = 32'd0;
    reg cmd_valid = 1'b0;
    reg [CHANNELS-1:0] ctrl_cmd_active = 2'b00;

    wire [CHANNELS-1:0] cmd_valid_o;
    wire [CHANNELS-1:0] cs_n;
    wire [CHANNELS-1:0] ras_n;
    wire [CHANNELS-1:0] cas_n;
    wire [CHANNELS-1:0] we_n;
    wire [CHANNELS*BANK_BITS-1:0] ba;
    wire [CHANNELS*ADDR_BITS-1:0] addr;
    wire capture_arm_pulse;
    wire [4:0] capture_arm_lane;
    wire capture_pulse;
    wire [4:0] capture_lane;
    wire busy;
    wire error;
    wire [CHANNELS-1:0] mpr_enabled;
    wire [3:0] state;
    wire [4:0] selected_lane;
    wire [7:0] capture_delay;
    wire capture_swap_edges;
    wire [7:0] cmd_count;
    wire [7:0] read_count;
    wire [7:0] capture_count;
    wire [12:0] read_addr;

    ddr3_mpr_debug #(
        .CHANNELS(CHANNELS),
        .ADDR_BITS(ADDR_BITS),
        .BANK_BITS(BANK_BITS),
        .PHY_LANES_PER_CHANNEL(9),
        .MRS_WAIT_CYCLES(2),
        .QUIET_SETTLE_CYCLES(4),
        .CAPTURE_DELAY_CYCLES(3)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_cmd_word(cmd_word),
        .i_cmd_valid(cmd_valid),
        .i_init_done(1'b1),
        .i_ctrl_cmd_active(ctrl_cmd_active),
        .o_cmd_valid(cmd_valid_o),
        .o_cs_n(cs_n),
        .o_ras_n(ras_n),
        .o_cas_n(cas_n),
        .o_we_n(we_n),
        .o_ba(ba),
        .o_addr(addr),
        .o_capture_arm_pulse(capture_arm_pulse),
        .o_capture_arm_lane(capture_arm_lane),
        .o_capture_pulse(capture_pulse),
        .o_capture_lane(capture_lane),
        .o_busy(busy),
        .o_error(error),
        .o_mpr_enabled(mpr_enabled),
        .o_state(state),
        .o_selected_lane(selected_lane),
        .o_capture_delay(capture_delay),
        .o_capture_swap_edges(capture_swap_edges),
        .o_cmd_count(cmd_count),
        .o_read_count(read_count),
        .o_capture_count(capture_count),
        .o_read_addr(read_addr)
    );

    task send_cmd;
        input [7:0] code;
        input [23:0] payload;
        begin
            @(negedge clk);
            cmd_word = {code, payload};
            cmd_valid = 1'b1;
            @(negedge clk);
            cmd_valid = 1'b0;
            cmd_word = 32'd0;
        end
    endtask

    task wait_arm_one_cycle;
        input [4:0] exp_lane;
        integer timeout;
        begin
            timeout = 0;
            while (!capture_arm_pulse && timeout < 40) begin
                timeout = timeout + 1;
                @(posedge clk);
                #1;
            end
            if (timeout >= 40) begin
                $display("[mpr-debug] missing arm pulse before read");
                $fatal(1);
            end
            if (!capture_arm_pulse || capture_arm_lane !== exp_lane) begin
                $display("[mpr-debug] missing arm pulse lane=%0d exp=%0d pulse=%0d",
                         capture_arm_lane, exp_lane, capture_arm_pulse);
                $fatal(1);
            end
            @(posedge clk);
            #1;
            if (capture_arm_pulse) begin
                $display("[mpr-debug] arm pulse was not one cycle");
                $fatal(1);
            end
        end
    endtask

    task wait_idle;
        integer timeout;
        begin
            timeout = 0;
            while (busy && timeout < 80) begin
                timeout = timeout + 1;
                @(posedge clk);
            end
            if (timeout >= 80) begin
                $display("[mpr-debug] timeout state=%0d", state);
                $fatal(1);
            end
        end
    endtask

    task expect_no_arm_now;
        begin
            if (capture_arm_pulse) begin
                $display("[mpr-debug] unexpected early arm pulse lane=%0d",
                         capture_arm_lane);
                $fatal(1);
            end
        end
    endtask

    task wait_cmd;
        input exp_channel;
        input [3:0] exp_cmd;
        input [BANK_BITS-1:0] exp_ba;
        input [ADDR_BITS-1:0] exp_addr;
        integer timeout;
        reg [3:0] got_cmd;
        begin
            timeout = 0;
            while (!cmd_valid_o[exp_channel] && timeout < 40) begin
                timeout = timeout + 1;
                @(posedge clk);
                #1;
            end
            if (timeout >= 40) begin
                $display("[mpr-debug] missing command channel=%0d", exp_channel);
                $fatal(1);
            end
            got_cmd = {
                cs_n[exp_channel],
                ras_n[exp_channel],
                cas_n[exp_channel],
                we_n[exp_channel]
            };
            if (got_cmd !== exp_cmd ||
                ba[exp_channel*BANK_BITS +: BANK_BITS] !== exp_ba ||
                addr[exp_channel*ADDR_BITS +: ADDR_BITS] !== exp_addr) begin
                $display("[mpr-debug] command mismatch got cmd=%b ba=%0d addr=%04x",
                         got_cmd,
                         ba[exp_channel*BANK_BITS +: BANK_BITS],
                         addr[exp_channel*ADDR_BITS +: ADDR_BITS]);
                $fatal(1);
            end
        end
    endtask

    initial begin
        repeat (5) @(posedge clk);
        rst = 1'b0;

        send_cmd(8'hEE, 24'h01_0203); // channel 1, delay 2, local lane 3
        if (selected_lane !== 5'd12 || capture_delay !== 8'd2 ||
            capture_swap_edges) begin
            $display("[mpr-debug] select mismatch lane=%0d delay=%0d swap=%0d",
                     selected_lane, capture_delay, capture_swap_edges);
            $fatal(1);
        end

        send_cmd(8'hEE, 24'h02_0102); // ch0, swap edges, delay 1, lane 2
        if (selected_lane !== 5'd2 || capture_delay !== 8'd1 ||
            !capture_swap_edges) begin
            $display("[mpr-debug] ch0 select mismatch lane=%0d delay=%0d swap=%0d",
                     selected_lane, capture_delay, capture_swap_edges);
            $fatal(1);
        end

        ctrl_cmd_active = 2'b01;
        send_cmd(8'hEB, 24'h00_0000);
        repeat (3) @(posedge clk);
        if (cmd_valid_o[0]) begin
            $display("[mpr-debug] ch0 command issued before quiet window");
            $fatal(1);
        end
        ctrl_cmd_active = 2'b00;
        wait_cmd(1'b0, 4'b0000, 3'd3, 15'h0004);
        wait_idle();
        if (mpr_enabled !== 2'b01) begin
            $display("[mpr-debug] ch0 enable mismatch mpr_enabled=%b",
                     mpr_enabled);
            $fatal(1);
        end

        send_cmd(8'hED, 24'h00_0010);
        expect_no_arm_now();
        wait_arm_one_cycle(5'd2);
        wait_cmd(1'b0, 4'b0101, 3'd0, 15'h1010);
        wait_idle();
        if (capture_count !== 8'd1 || capture_lane !== 5'd2 ||
            read_count !== 8'd1 || read_addr !== 13'h1010) begin
            $display("[mpr-debug] ch0 capture mismatch count=%0d lane=%0d reads=%0d addr=%04x",
                     capture_count, capture_lane, read_count, read_addr);
            $fatal(1);
        end

        send_cmd(8'hEC, 24'h00_0000);
        wait_cmd(1'b0, 4'b0000, 3'd3, 15'h0000);
        wait_idle();
        if (error || mpr_enabled !== 2'b00 || cmd_count !== 8'd3) begin
            $display("[mpr-debug] ch0 final mismatch error=%0d enabled=%b cmds=%0d",
                     error, mpr_enabled, cmd_count);
            $fatal(1);
        end

        send_cmd(8'hEE, 24'h03_0203); // ch1, swap edges, delay 2, lane 3
        if (selected_lane !== 5'd12 || capture_delay !== 8'd2 ||
            !capture_swap_edges) begin
            $display("[mpr-debug] ch1 select mismatch lane=%0d delay=%0d swap=%0d",
                     selected_lane, capture_delay, capture_swap_edges);
            $fatal(1);
        end

        ctrl_cmd_active = 2'b10;
        send_cmd(8'hEB, 24'h01_0000);
        repeat (3) @(posedge clk);
        if (cmd_valid_o[1]) begin
            $display("[mpr-debug] command issued before quiet window");
            $fatal(1);
        end
        repeat (3) @(posedge clk);
        if (cmd_valid_o[1]) begin
            $display("[mpr-debug] command issued while channel remained busy");
            $fatal(1);
        end
        ctrl_cmd_active = 2'b00;
        wait_cmd(1'b1, 4'b0000, 3'd3, 15'h0004);
        wait_idle();
        if (mpr_enabled !== 2'b10) begin
            $display("[mpr-debug] enable mismatch mpr_enabled=%b", mpr_enabled);
            $fatal(1);
        end

        send_cmd(8'hED, 24'h01_0018);
        expect_no_arm_now();
        wait_arm_one_cycle(5'd12);
        wait_cmd(1'b1, 4'b0101, 3'd0, 15'h1018);
        wait_idle();
        if (capture_count !== 8'd2 || capture_lane !== 5'd12 ||
            read_count !== 8'd2 || read_addr !== 13'h1018) begin
            $display("[mpr-debug] capture mismatch count=%0d lane=%0d reads=%0d addr=%04x",
                     capture_count, capture_lane, read_count, read_addr);
            $fatal(1);
        end

        send_cmd(8'hEC, 24'h01_0000);
        wait_cmd(1'b1, 4'b0000, 3'd3, 15'h0000);
        wait_idle();
        if (error || mpr_enabled !== 2'b00 || cmd_count !== 8'd6) begin
            $display("[mpr-debug] final mismatch error=%0d enabled=%b cmds=%0d",
                     error, mpr_enabled, cmd_count);
            $fatal(1);
        end

        $display("[mpr-debug] host MPR sequencer passed");
        $finish;
    end

    initial begin
        repeat (300) @(posedge clk);
        $display("[mpr-debug] timeout");
        $fatal(1);
    end
endmodule

`default_nettype wire

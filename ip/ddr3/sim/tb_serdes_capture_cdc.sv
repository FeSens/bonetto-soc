`default_nettype none
`timescale 1ps/1ps

module tb_serdes_capture_cdc;
    localparam integer PHY_LANES = 18;
    localparam integer TAP_W = 5;

    reg phy_clk = 1'b0;
    reg ctrl_clk = 1'b0;
    reg phy_rst = 1'b1;
    reg ctrl_rst = 1'b1;

    always #3500 phy_clk = !phy_clk;
    always #10000 ctrl_clk = !ctrl_clk;

    reg [PHY_LANES-1:0] capture_lane = {PHY_LANES{1'b0}};
    reg [PHY_LANES*TAP_W-1:0] tap_bus = {(PHY_LANES*TAP_W){1'b0}};
    reg [PHY_LANES*64-1:0] dq_bus = {(PHY_LANES*64){1'b0}};
    reg [PHY_LANES*8-1:0] dqs_bus = {(PHY_LANES*8){1'b0}};

    wire valid;
    wire [4:0] lane;
    wire [TAP_W-1:0] tap;
    wire [63:0] dq_bits;
    wire [7:0] dqs_bits;
    wire [7:0] count;

    ddr3_serdes_capture_cdc #(
        .PHY_LANES(PHY_LANES),
        .TAP_W(TAP_W)
    ) dut (
        .i_phy_clk(phy_clk),
        .i_phy_rst(phy_rst),
        .i_ctrl_clk(ctrl_clk),
        .i_ctrl_rst(ctrl_rst),
        .i_phy_capture_lane(capture_lane),
        .i_phy_tap(tap_bus),
        .i_phy_dq_bits(dq_bus),
        .i_phy_dqs_bits(dqs_bus),
        .o_ctrl_valid(valid),
        .o_ctrl_lane(lane),
        .o_ctrl_tap(tap),
        .o_ctrl_dq_bits(dq_bits),
        .o_ctrl_dqs_bits(dqs_bits),
        .o_ctrl_count(count)
    );

    task issue_capture;
        input [4:0] req_lane;
        input [TAP_W-1:0] req_tap;
        input [63:0] req_dq;
        input [7:0] req_dqs;
        begin
            @(negedge phy_clk);
            tap_bus[req_lane*TAP_W +: TAP_W] = req_tap;
            dq_bus[req_lane*64 +: 64] = req_dq;
            dqs_bus[req_lane*8 +: 8] = req_dqs;
            capture_lane = ({PHY_LANES{1'b0}} | (18'd1 << req_lane));
            @(negedge phy_clk);
            capture_lane = {PHY_LANES{1'b0}};
        end
    endtask

    task wait_capture;
        input [7:0] exp_count;
        input [4:0] exp_lane;
        input [TAP_W-1:0] exp_tap;
        input [63:0] exp_dq;
        input [7:0] exp_dqs;
        integer timeout;
        begin
            timeout = 0;
            while ((count != exp_count) && timeout < 80) begin
                timeout = timeout + 1;
                @(posedge ctrl_clk);
                #1;
            end
            if (timeout >= 80) begin
                $display("[serdes-capture-cdc] missing capture count=%0d",
                         exp_count);
                $fatal(1);
            end
            if (!valid || lane !== exp_lane || tap !== exp_tap ||
                dq_bits !== exp_dq || dqs_bits !== exp_dqs) begin
                $display("[serdes-capture-cdc] mismatch valid=%0d lane=%0d tap=%0d dq=%016x dqs=%02x",
                         valid, lane, tap, dq_bits, dqs_bits);
                $fatal(1);
            end
        end
    endtask

    initial begin
        repeat (5) @(posedge ctrl_clk);
        phy_rst = 1'b0;
        ctrl_rst = 1'b0;

        fork
            issue_capture(5'd4, 5'd9, 64'h0123_4567_89ab_cdef, 8'ha5);
            wait_capture(8'd1, 5'd4, 5'd9,
                         64'h0123_4567_89ab_cdef, 8'ha5);
        join

        fork
            issue_capture(5'd12, 5'd21, 64'hfedc_ba98_7654_3210, 8'h3c);
            wait_capture(8'd2, 5'd12, 5'd21,
                         64'hfedc_ba98_7654_3210, 8'h3c);
        join

        $display("[serdes-capture-cdc] dual-clock raw SERDES capture CDC passed");
        $finish;
    end

    initial begin
        repeat (400) @(posedge ctrl_clk);
        $display("[serdes-capture-cdc] timeout");
        $fatal(1);
    end
endmodule

`default_nettype wire

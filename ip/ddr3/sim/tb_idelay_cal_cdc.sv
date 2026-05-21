`default_nettype none
`timescale 1ps/1ps

module tb_idelay_cal_cdc;
    localparam integer PHY_LANES = 18;
    localparam integer PHY_BYTE_LANES = 9;
    localparam integer TAP_W = 5;

    reg ctrl_clk = 1'b0;
    reg phy_clk = 1'b0;
    reg ctrl_rst = 1'b1;
    reg phy_rst = 1'b1;

    always #10000 ctrl_clk = !ctrl_clk;
    always #3500 phy_clk = !phy_clk;

    reg [PHY_LANES-1:0] ctrl_load_lane = {PHY_LANES{1'b0}};
    reg [TAP_W-1:0] ctrl_tap = {TAP_W{1'b0}};
    reg ctrl_channel = 1'b0;

    wire [PHY_LANES-1:0] phy_load;
    wire [PHY_LANES*TAP_W-1:0] phy_tap;
    wire [4:0] req_lane;
    wire [TAP_W-1:0] req_tap;
    wire req_channel;
    wire [7:0] req_count;
    wire [4:0] seen_lane;
    wire [TAP_W-1:0] seen_tap;
    wire [7:0] seen_count;
    wire pending;

    ddr3_idelay_cal_cdc #(
        .PHY_LANES(PHY_LANES),
        .PHY_BYTE_LANES(PHY_BYTE_LANES),
        .TAP_W(TAP_W)
    ) dut (
        .i_ctrl_clk(ctrl_clk),
        .i_ctrl_rst(ctrl_rst),
        .i_phy_clk(phy_clk),
        .i_phy_rst(phy_rst),
        .i_ctrl_load_lane(ctrl_load_lane),
        .i_ctrl_tap(ctrl_tap),
        .i_ctrl_channel(ctrl_channel),
        .o_phy_load(phy_load),
        .o_phy_tap(phy_tap),
        .o_ctrl_req_lane(req_lane),
        .o_ctrl_req_tap(req_tap),
        .o_ctrl_req_channel(req_channel),
        .o_ctrl_req_count(req_count),
        .o_ctrl_seen_lane(seen_lane),
        .o_ctrl_seen_tap(seen_tap),
        .o_ctrl_seen_count(seen_count),
        .o_ctrl_pending(pending)
    );

    task issue_request;
        input [4:0] lane;
        input [TAP_W-1:0] tap;
        input channel;
        begin
            @(negedge ctrl_clk);
            ctrl_load_lane = ({PHY_LANES{1'b0}} | (18'd1 << lane));
            ctrl_tap = tap;
            ctrl_channel = channel;
            @(negedge ctrl_clk);
            ctrl_load_lane = {PHY_LANES{1'b0}};
            ctrl_tap = {TAP_W{1'b0}};
            ctrl_channel = 1'b0;
        end
    endtask

    task expect_load;
        input [4:0] lane;
        input [TAP_W-1:0] tap;
        reg [PHY_LANES-1:0] expected;
        integer timeout;
        begin
            expected = ({PHY_LANES{1'b0}} | (18'd1 << lane));
            timeout = 0;
            while (phy_load !== expected && timeout < 200) begin
                timeout = timeout + 1;
                @(posedge phy_clk);
                #1;
            end
            if (timeout >= 200) begin
                $display("[idelay-cal-cdc] missing load lane=%0d tap=%0d",
                         lane, tap);
                $fatal(1);
            end
            if (phy_tap[lane*TAP_W +: TAP_W] !== tap) begin
                $display("[idelay-cal-cdc] tap mismatch lane=%0d expected=%0d got=%0d",
                         lane, tap, phy_tap[lane*TAP_W +: TAP_W]);
                $fatal(1);
            end
            @(posedge phy_clk);
            #1;
            if (phy_load !== {PHY_LANES{1'b0}}) begin
                $display("[idelay-cal-cdc] load pulse wider than one phy clock");
                $fatal(1);
            end
        end
    endtask

    task wait_seen;
        input [7:0] count;
        input [4:0] lane;
        input [TAP_W-1:0] tap;
        integer timeout;
        begin
            timeout = 0;
            while ((seen_count != count || pending) && timeout < 80) begin
                timeout = timeout + 1;
                @(posedge ctrl_clk);
                #1;
            end
            if (timeout >= 80) begin
                $display("[idelay-cal-cdc] missing seen count=%0d", count);
                $fatal(1);
            end
            if (seen_lane !== lane || seen_tap !== tap) begin
                $display("[idelay-cal-cdc] seen mismatch lane=%0d/%0d tap=%0d/%0d",
                         seen_lane, lane, seen_tap, tap);
                $fatal(1);
            end
        end
    endtask

    initial begin
        repeat (5) @(posedge ctrl_clk);
        ctrl_rst = 1'b0;
        phy_rst = 1'b0;
        repeat (3) @(posedge ctrl_clk);

        fork
            begin
                issue_request(5'd2, 5'd17, 1'b0);
                wait_seen(8'd1, 5'd2, 5'd17);
            end
            expect_load(5'd2, 5'd17);
        join
        if (req_lane !== 5'd2 || req_tap !== 5'd17 ||
            req_channel !== 1'b0 || req_count !== 8'd1) begin
            $display("[idelay-cal-cdc] direct CH0 request status mismatch");
            $fatal(1);
        end

        fork
            begin
                issue_request(5'd10, 5'd5, 1'b0);
                wait_seen(8'd2, 5'd10, 5'd5);
            end
            expect_load(5'd10, 5'd5);
        join
        if (req_lane !== 5'd10 || req_tap !== 5'd5 ||
            req_channel !== 1'b0 || req_count !== 8'd2) begin
            $display("[idelay-cal-cdc] direct physical CH1 request status mismatch");
            $fatal(1);
        end

        fork
            begin
                issue_request(5'd3, 5'd21, 1'b1);
                wait_seen(8'd3, 5'd12, 5'd21);
            end
            expect_load(5'd12, 5'd21);
        join
        if (req_lane !== 5'd12 || req_tap !== 5'd21 ||
            req_channel !== 1'b1 || req_count !== 8'd3) begin
            $display("[idelay-cal-cdc] legacy channel-mapped request status mismatch");
            $fatal(1);
        end

        repeat (10) @(posedge ctrl_clk);
        if (pending) begin
            $display("[idelay-cal-cdc] pending stuck after all requests");
            $fatal(1);
        end

        $display("[idelay-cal-cdc] dual-clock IDELAY calibration CDC passed");
        $finish;
    end

    initial begin
        repeat (400) @(posedge ctrl_clk);
        $display("[idelay-cal-cdc] timeout");
        $fatal(1);
    end
endmodule

`default_nettype wire

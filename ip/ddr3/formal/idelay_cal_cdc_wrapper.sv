// Formal protocol harness for the IDELAY calibration command bridge.
//
// This ties both clocks to one formal clock. The implementation still uses
// toggle synchronizers in hardware; this proof focuses on lane mapping, tap
// integrity, one-cycle load pulses, and request/seen accounting.

`default_nettype none

module ddr3_idelay_cal_cdc_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer PHY_LANES = 18;
    localparam integer PHY_BYTE_LANES = 9;
    localparam integer TAP_W = 5;

    reg [6:0] f_cycle = 7'd0;
    reg       f_saw_lane2 = 1'b0;
    reg       f_saw_lane10 = 1'b0;
    reg       f_saw_lane12 = 1'b0;
    reg       f_past_valid = 1'b0;

    wire [PHY_LANES-1:0] ctrl_load_lane =
        (f_cycle == 7'd2)  ? (18'd1 << 2) :
        (f_cycle == 7'd18) ? (18'd1 << 10) :
        (f_cycle == 7'd34) ? (18'd1 << 3) : 18'd0;
    wire [TAP_W-1:0] ctrl_tap =
        (f_cycle == 7'd2)  ? 5'd17 :
        (f_cycle == 7'd18) ? 5'd5 :
        (f_cycle == 7'd34) ? 5'd21 : 5'd0;
    wire ctrl_channel = (f_cycle == 7'd34);

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
        .i_ctrl_clk(clk),
        .i_ctrl_rst(rst),
        .i_phy_clk(clk),
        .i_phy_rst(rst),
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

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_cycle <= 7'd0;
            f_saw_lane2 <= 1'b0;
            f_saw_lane10 <= 1'b0;
            f_saw_lane12 <= 1'b0;
        end else begin
            if (f_cycle != 7'd127)
                f_cycle <= f_cycle + 7'd1;

            assert((phy_load & (phy_load - 18'd1)) == 18'd0);
            assert((phy_load & ~(18'd1 << 2) &
                    ~(18'd1 << 10) & ~(18'd1 << 12)) == 18'd0);

            if (phy_load[2]) begin
                assert(phy_load == (18'd1 << 2));
                assert(phy_tap[2*TAP_W +: TAP_W] == 5'd17);
                f_saw_lane2 <= 1'b1;
            end

            if (phy_load[10]) begin
                assert(phy_load == (18'd1 << 10));
                assert(phy_tap[10*TAP_W +: TAP_W] == 5'd5);
                f_saw_lane10 <= 1'b1;
            end

            if (phy_load[12]) begin
                assert(phy_load == (18'd1 << 12));
                assert(phy_tap[12*TAP_W +: TAP_W] == 5'd21);
                f_saw_lane12 <= 1'b1;
            end

            if (f_cycle == 7'd2) begin
                assert(req_count == 8'd0);
                assert(seen_count == 8'd0);
            end

            if (f_cycle == 7'd4) begin
                assert(req_count == 8'd1);
                assert(req_lane == 5'd2);
                assert(req_tap == 5'd17);
                assert(!req_channel);
                assert(pending);
            end

            if (f_cycle == 7'd20) begin
                assert(req_count == 8'd2);
                assert(req_lane == 5'd10);
                assert(req_tap == 5'd5);
                assert(!req_channel);
            end

            if (f_cycle == 7'd36) begin
                assert(req_count == 8'd3);
                assert(req_lane == 5'd12);
                assert(req_tap == 5'd21);
                assert(req_channel);
            end

            if (f_cycle == 7'd56) begin
                assert(f_saw_lane2);
                assert(f_saw_lane10);
                assert(f_saw_lane12);
                assert(seen_count == 8'd3);
                assert(seen_lane == 5'd12);
                assert(seen_tap == 5'd21);
                assert(!pending);
            end

            cover(f_saw_lane2 && f_saw_lane10 && f_saw_lane12 &&
                  seen_count == 8'd3 && !pending);
        end
    end
`endif
endmodule

`default_nettype wire

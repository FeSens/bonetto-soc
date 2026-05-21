// Formal harness for the raw SERDES capture snapshot bridge.
//
// Both clocks are tied to one formal clock. The implementation still uses a
// toggle plus stable snapshot CDC in hardware; this proof focuses on lane
// selection, payload integrity, and capture accounting.

`default_nettype none

module ddr3_serdes_capture_cdc_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer PHY_LANES = 18;
    localparam integer TAP_W = 5;

    reg [6:0] f_cycle = 7'd0;
    reg f_past_valid = 1'b0;

    wire [PHY_LANES-1:0] capture_lane =
        (f_cycle == 7'd2)  ? (18'd1 << 4) :
        (f_cycle == 7'd18) ? (18'd1 << 12) : 18'd0;

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
        .i_phy_clk(clk),
        .i_phy_rst(rst),
        .i_ctrl_clk(clk),
        .i_ctrl_rst(rst),
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

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        tap_bus[4*TAP_W +: TAP_W] <= 5'd9;
        dq_bus[4*64 +: 64] <= 64'h0123_4567_89ab_cdef;
        dqs_bus[4*8 +: 8] <= 8'ha5;

        tap_bus[12*TAP_W +: TAP_W] <= 5'd21;
        dq_bus[12*64 +: 64] <= 64'hfedc_ba98_7654_3210;
        dqs_bus[12*8 +: 8] <= 8'h3c;

        if (rst) begin
            f_cycle <= 7'd0;
        end else begin
            if (f_cycle != 7'd127)
                f_cycle <= f_cycle + 7'd1;

            assert(count <= 8'd2);
            if (count != 8'd0)
                assert(valid);

            if (f_cycle == 7'd8) begin
                assert(valid);
                assert(count == 8'd1);
                assert(lane == 5'd4);
                assert(tap == 5'd9);
                assert(dq_bits == 64'h0123_4567_89ab_cdef);
                assert(dqs_bits == 8'ha5);
            end

            if (f_cycle == 7'd24) begin
                assert(valid);
                assert(count == 8'd2);
                assert(lane == 5'd12);
                assert(tap == 5'd21);
                assert(dq_bits == 64'hfedc_ba98_7654_3210);
                assert(dqs_bits == 8'h3c);
            end

            cover(valid && count == 8'd2 && lane == 5'd12);
        end
    end
`endif
endmodule

`default_nettype wire

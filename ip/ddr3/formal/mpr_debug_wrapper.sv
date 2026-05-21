// Formal harness for the host-driven MPR debug command sequencer.

`default_nettype none

module ddr3_mpr_debug_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 2;
    localparam integer ADDR_BITS = 15;
    localparam integer BANK_BITS = 3;

    reg [6:0] f_cycle = 7'd0;
    reg f_past_valid = 1'b0;

    reg [31:0] cmd_word = 32'd0;
    reg cmd_valid = 1'b0;

    wire [CHANNELS-1:0] cmd_valid_o;
    wire [CHANNELS-1:0] cs_n;
    wire [CHANNELS-1:0] ras_n;
    wire [CHANNELS-1:0] cas_n;
    wire [CHANNELS-1:0] we_n;
    wire [CHANNELS*BANK_BITS-1:0] ba;
    wire [CHANNELS*ADDR_BITS-1:0] addr;
    wire capture_pulse;
    wire [4:0] capture_lane;
    wire busy;
    wire error;
    wire [CHANNELS-1:0] mpr_enabled;
    wire [3:0] state;
    wire [4:0] selected_lane;
    wire [7:0] capture_delay;
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
        .QUIET_SETTLE_CYCLES(2),
        .CAPTURE_DELAY_CYCLES(3)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_cmd_word(cmd_word),
        .i_cmd_valid(cmd_valid),
        .i_init_done(1'b1),
        .i_ctrl_cmd_active({CHANNELS{1'b0}}),
        .o_cmd_valid(cmd_valid_o),
        .o_cs_n(cs_n),
        .o_ras_n(ras_n),
        .o_cas_n(cas_n),
        .o_we_n(we_n),
        .o_ba(ba),
        .o_addr(addr),
        .o_capture_pulse(capture_pulse),
        .o_capture_lane(capture_lane),
        .o_busy(busy),
        .o_error(error),
        .o_mpr_enabled(mpr_enabled),
        .o_state(state),
        .o_selected_lane(selected_lane),
        .o_capture_delay(capture_delay),
        .o_cmd_count(cmd_count),
        .o_read_count(read_count),
        .o_capture_count(capture_count),
        .o_read_addr(read_addr)
    );

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        if (f_past_valid)
            assume(!rst);

        cmd_valid <= 1'b0;
        cmd_word <= 32'd0;

        if (rst) begin
            f_cycle <= 7'd0;
        end else begin
            if (f_cycle != 7'd127)
                f_cycle <= f_cycle + 7'd1;

            case (f_cycle)
                7'd2: begin
                    cmd_valid <= 1'b1;
                    cmd_word <= 32'hEE_01_0203; // ch1, delay 2, lane 3
                end
                7'd6: begin
                    cmd_valid <= 1'b1;
                    cmd_word <= 32'hEB_01_0000; // MPR enable ch1
                end
                7'd16: begin
                    cmd_valid <= 1'b1;
                    cmd_word <= 32'hED_01_0018; // READ ch1, addr 0x1018
                end
                7'd28: begin
                    cmd_valid <= 1'b1;
                    cmd_word <= 32'hEC_01_0000; // MPR disable ch1
                end
                default: begin
                end
            endcase

            assert(!error);
            if (cmd_valid_o[1]) begin
                assert(!cs_n[1]);
                if (!ras_n[1] && !cas_n[1] && !we_n[1]) begin
                    assert(ba[1*BANK_BITS +: BANK_BITS] == 3'd3);
                    assert(addr[1*ADDR_BITS +: ADDR_BITS] == 15'h0004 ||
                           addr[1*ADDR_BITS +: ADDR_BITS] == 15'h0000);
                end
                if (ras_n[1] && !cas_n[1] && we_n[1]) begin
                    assert(ba[1*BANK_BITS +: BANK_BITS] == 3'd0);
                    assert(addr[1*ADDR_BITS +: ADDR_BITS] == 15'h1018);
                end
            end

            if (capture_pulse) begin
                assert(capture_lane == 5'd12);
                assert(capture_count == 8'd0);
                assert(selected_lane == 5'd12);
                assert(read_addr == 13'h1018);
            end

            cover(capture_pulse && capture_lane == 5'd12);
            cover(cmd_count == 8'd3 && read_count == 8'd1 &&
                  capture_count == 8'd1 && mpr_enabled == 2'b00);
        end
    end
`endif
endmodule

`default_nettype wire

// bringup_status_led — encodes DDR3 bringup state into the 3 user LEDs
// so silicon health can be read from across the room without JTAG.
//
// LED pin map (from constraints/ypcb-00338.xdc):
//   o_led[0] = P30 (red)
//   o_led[1] = M30 (green)
//   o_led[2] = N30 (yellow)
//
// Priority-encoded state display (highest priority first):
//   POR active       : all off
//   !mmcm_locked     : red fast blink                  ("clocks not up")
//   init_error       : red solid + yellow fast blink   ("init FSM trapped")
//   cal_error        : yellow solid + green fast blink ("cal FSM trapped")
//   !init_done       : yellow slow blink               ("init in progress")
//   !cal_done        : yellow solid + green slow blink ("cal in progress")
//   mtest_any_err    : red/yellow alternate            ("memtest mismatch")
//   target=BRAM(0)   : green slow blink                ("BRAM pass running")
//   target=DDR3(1)   : green solid + yellow heartbeat  ("DDR3 pass running")
//
// Runs on clk_50 so the LEDs work even before MMCM locks. All inputs
// other than i_por_active are expected to already be CDC-synchronised
// into the clk_50 domain by the caller (top.v already does this for
// the status-mux readback).

`default_nettype none

module bringup_status_led (
    input  wire        i_clk_50,
    input  wire        i_por_active,
    input  wire        i_mmcm_locked,
    input  wire        i_init_done,
    input  wire        i_init_error,
    input  wire        i_cal_done,
    input  wire        i_cal_error,
    input  wire        i_mtest_any_err,
    input  wire        i_mtest_target,
    output reg  [2:0]  o_led
);
    reg [27:0] tick = 28'd0;
    always @(posedge i_clk_50) tick <= tick + 1'b1;

    wire slow_blink = tick[25];
    wire fast_blink = tick[22];
    wire heartbeat  = (tick[25:23] == 3'b000);

    wire red, green, yellow;
    reg r_red, r_green, r_yellow;

    always @(*) begin
        r_red    = 1'b0;
        r_green  = 1'b0;
        r_yellow = 1'b0;
        if (i_por_active) begin
            // All off.
        end else if (!i_mmcm_locked) begin
            r_red    = fast_blink;
        end else if (i_init_error) begin
            r_red    = 1'b1;
            r_yellow = fast_blink;
        end else if (i_cal_error) begin
            r_yellow = 1'b1;
            r_green  = fast_blink;
        end else if (!i_init_done) begin
            r_yellow = slow_blink;
        end else if (!i_cal_done) begin
            r_yellow = 1'b1;
            r_green  = slow_blink;
        end else if (i_mtest_any_err) begin
            r_red    = slow_blink;
            r_yellow = ~slow_blink;
        end else if (!i_mtest_target) begin
            r_green  = slow_blink;
        end else begin
            r_green  = 1'b1;
            r_yellow = heartbeat;
        end
    end

    assign red    = r_red;
    assign green  = r_green;
    assign yellow = r_yellow;

    always @(*) o_led = {yellow, green, red};

endmodule

`default_nettype wire

// ddr3_cal_seq — DDR3 calibration sequencer.
//
// Orchestrates the post-init calibration flow:
//
//   init_done -> [pulse wlvl_start -> wait wlvl_done | wlvl_error]
//             -> [pulse rdlvl_start -> wait rdlvl_done | rdlvl_error]
//             -> assert cal_done
//
// Any error along the way latches o_cal_error with a 2-bit reason
// code so the host (via JTAG-UART status reg) can distinguish wlvl
// vs rdlvl failures.
//
// SKIP_WLVL: when 1, the wlvl phase is bypassed entirely (used on boards
// where DQS pins lack ODELAYE2 — e.g., YPCB-00338's HR-bank pinout —
// so write-leveling per JEDEC cannot sweep DQS output delay). Cal_seq
// goes directly from init_done to rdlvl. The DQS-CK fixed 90° from the
// MMCM still gives correct WRITE timing — only the cal sweep is skipped.
//
// SKIP_RDLVL: same idea for read-leveling. Default 0 (cal still runs
// rdlvl). Set both to 1 to bypass calibration entirely.

`default_nettype none

module ddr3_cal_seq #(
    parameter integer SKIP_WLVL  = 0,    // boards with HR-bank DQS pins (e.g. YPCB-00338) override to 1
    parameter integer SKIP_RDLVL = 0
) (
    input  wire        i_clk,
    input  wire        i_rst,

    input  wire        i_init_done,

    output reg         o_wlvl_start,
    input  wire        i_wlvl_done,
    input  wire        i_wlvl_error,

    output reg         o_rdlvl_start,
    input  wire        i_rdlvl_done,
    input  wire        i_rdlvl_error,

    output reg         o_cal_done,
    output reg         o_cal_error,
    output reg  [1:0]  o_cal_error_code,
    output reg  [3:0]  o_state
);
    localparam [3:0]
        S_IDLE        = 4'd0,
        S_WAIT_INIT   = 4'd1,
        S_PULSE_WLVL  = 4'd2,
        S_WAIT_WLVL   = 4'd3,
        S_PULSE_RDLVL = 4'd4,
        S_WAIT_RDLVL  = 4'd5,
        S_DONE        = 4'd6,
        S_ERROR       = 4'd7;

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_state          <= S_IDLE;
            o_wlvl_start     <= 1'b0;
            o_rdlvl_start    <= 1'b0;
            o_cal_done       <= 1'b0;
            o_cal_error      <= 1'b0;
            o_cal_error_code <= 2'b00;
        end else begin
            o_wlvl_start  <= 1'b0;
            o_rdlvl_start <= 1'b0;

            case (o_state)
                S_IDLE: begin
                    o_state <= S_WAIT_INIT;
                end

                S_WAIT_INIT: begin
                    if (i_init_done) begin
                        if (SKIP_WLVL)
                            o_state <= (SKIP_RDLVL) ? S_DONE : S_PULSE_RDLVL;
                        else
                            o_state <= S_PULSE_WLVL;
                    end
                end

                S_PULSE_WLVL: begin
                    o_wlvl_start <= 1'b1;
                    o_state      <= S_WAIT_WLVL;
                end

                S_WAIT_WLVL: begin
                    if (i_wlvl_error) begin
                        o_cal_error      <= 1'b1;
                        o_cal_error_code <= 2'b01;
                        o_state          <= S_ERROR;
                    end else if (i_wlvl_done) begin
                        o_state <= (SKIP_RDLVL) ? S_DONE : S_PULSE_RDLVL;
                    end
                end

                S_PULSE_RDLVL: begin
                    o_rdlvl_start <= 1'b1;
                    o_state       <= S_WAIT_RDLVL;
                end

                S_WAIT_RDLVL: begin
                    if (i_rdlvl_error) begin
                        o_cal_error      <= 1'b1;
                        o_cal_error_code <= 2'b10;
                        o_state          <= S_ERROR;
                    end else if (i_rdlvl_done) begin
                        o_cal_done <= 1'b1;
                        o_state    <= S_DONE;
                    end
                end

                S_DONE: begin
                    o_cal_done <= 1'b1;
                end

                S_ERROR: ;

                default: o_state <= S_IDLE;
            endcase
        end
    end
endmodule

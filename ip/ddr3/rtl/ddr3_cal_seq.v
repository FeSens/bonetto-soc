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

`include "ddr3_params.vh"

module ddr3_cal_seq #(
    parameter integer SKIP_WLVL  = 0,    // boards with HR-bank DQS pins (e.g. YPCB-00338) override to 1
    parameter integer SKIP_RDLVL = 0,
    parameter integer ROW_BITS   = `DDR3_ROW_BITS,
    parameter integer BANK_BITS  = `DDR3_BANK_BITS
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

    // iter-8: MRS-rewrite handshake to ddr3_ctrl. cal_seq pulses
    // o_mrs_req with target MR ba/addr, then waits for i_mrs_busy=0.
    // Bank 3 + value 0x0004 toggles MR3[2]=1 (MPR enable); bank 3 +
    // value 0x0000 restores normal mode.
    output reg                       o_mrs_req,
    output reg  [BANK_BITS-1:0]      o_mrs_ba,
    output reg  [ROW_BITS-1:0]       o_mrs_addr,
    input  wire                      i_mrs_busy,

    output reg         o_cal_done,
    output reg         o_cal_error,
    output reg  [1:0]  o_cal_error_code,
    output reg  [3:0]  o_state
);
    localparam [3:0]
        S_IDLE         = 4'd0,
        S_WAIT_INIT    = 4'd1,
        S_PULSE_WLVL   = 4'd2,
        S_WAIT_WLVL    = 4'd3,
        S_MR3_EN_PULSE = 4'd8,
        S_MR3_EN_WAIT  = 4'd9,
        S_PULSE_RDLVL  = 4'd4,
        S_WAIT_RDLVL   = 4'd5,
        S_MR3_DIS_PULSE= 4'd10,
        S_MR3_DIS_WAIT = 4'd11,
        S_DONE         = 4'd6,
        S_ERROR        = 4'd7;

    localparam [BANK_BITS-1:0] MR3_BA = 3'd3;
    localparam [ROW_BITS-1:0]  MR3_VAL_NORMAL = {ROW_BITS{1'b0}};
    // MR3[2] = 1 enables MPR mode; MR3[1:0]=00 selects the predefined pattern.
    localparam [ROW_BITS-1:0]  MR3_VAL_MPR_EN = {{(ROW_BITS-3){1'b0}}, 3'b100};

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_state          <= S_IDLE;
            o_wlvl_start     <= 1'b0;
            o_rdlvl_start    <= 1'b0;
            o_mrs_req        <= 1'b0;
            o_mrs_ba         <= {BANK_BITS{1'b0}};
            o_mrs_addr       <= {ROW_BITS{1'b0}};
            o_cal_done       <= 1'b0;
            o_cal_error      <= 1'b0;
            o_cal_error_code <= 2'b00;
        end else begin
            o_wlvl_start  <= 1'b0;
            o_rdlvl_start <= 1'b0;
            o_mrs_req     <= 1'b0;

            case (o_state)
                S_IDLE: begin
                    o_state <= S_WAIT_INIT;
                end

                S_WAIT_INIT: begin
                    if (i_init_done) begin
                        if (SKIP_WLVL)
                            o_state <= (SKIP_RDLVL) ? S_DONE : S_MR3_EN_PULSE;
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
                        o_state <= (SKIP_RDLVL) ? S_DONE : S_MR3_EN_PULSE;
                    end
                end

                // ---- MR3-rewrite path before rdlvl ----
                S_MR3_EN_PULSE: begin
                    o_mrs_req  <= 1'b1;
                    o_mrs_ba   <= MR3_BA;
                    o_mrs_addr <= MR3_VAL_MPR_EN;
                    o_state    <= S_MR3_EN_WAIT;
                end

                S_MR3_EN_WAIT: begin
                    // After mrs_busy clears the chip is in MPR mode and the
                    // tMOD wait has been honoured by the runtime FSM.
                    if (!i_mrs_busy && !o_mrs_req)
                        o_state <= S_PULSE_RDLVL;
                end

                S_PULSE_RDLVL: begin
                    o_rdlvl_start <= 1'b1;
                    o_state       <= S_WAIT_RDLVL;
                end

                S_WAIT_RDLVL: begin
                    if (i_rdlvl_error) begin
                        o_cal_error      <= 1'b1;
                        o_cal_error_code <= 2'b10;
                        // Leave the chip in MPR mode would be very bad; we
                        // still attempt the MR3-disable rewrite even on
                        // error so subsequent normal reads aren't poisoned.
                        o_state          <= S_MR3_DIS_PULSE;
                    end else if (i_rdlvl_done) begin
                        o_state <= S_MR3_DIS_PULSE;
                    end
                end

                // ---- MR3-rewrite path after rdlvl (always re-runs, even on err) ----
                S_MR3_DIS_PULSE: begin
                    o_mrs_req  <= 1'b1;
                    o_mrs_ba   <= MR3_BA;
                    o_mrs_addr <= MR3_VAL_NORMAL;
                    o_state    <= S_MR3_DIS_WAIT;
                end

                S_MR3_DIS_WAIT: begin
                    if (!i_mrs_busy && !o_mrs_req) begin
                        if (o_cal_error) begin
                            o_state <= S_ERROR;
                        end else begin
                            o_cal_done <= 1'b1;
                            o_state    <= S_DONE;
                        end
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

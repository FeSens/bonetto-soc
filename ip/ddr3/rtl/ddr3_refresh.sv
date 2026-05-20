// Periodic DDR3 refresh requester.
//
// This block owns tREFI accounting only. It asks the scheduler for a refresh
// before the JEDEC deadline, then waits for the scheduler's REF acknowledge.
// Bank closing, command arbitration, and tRFC remain scheduler responsibilities.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_refresh #(
    parameter integer COUNTER_BITS = 16,
    parameter integer T_REFI       = `DDR3_800_TREFI_CYCLES,
    parameter integer T_MARGIN     = `DDR3_800_REFRESH_MARGIN_CYCLES
) (
    input wire                       i_clk,
    input wire                       i_rst,
    input wire                       i_enable,
    input wire                       i_refresh_ack,

    output reg                       o_refresh_req,
    output reg                       o_refresh_late,
    output wire                      o_refresh_window,
    output wire [COUNTER_BITS-1:0]   o_cycles_to_deadline,
    output reg [15:0]                o_refresh_count
);
    reg [COUNTER_BITS-1:0] cycles_to_deadline;

    assign o_cycles_to_deadline = cycles_to_deadline;
    assign o_refresh_window = i_enable && (cycles_to_deadline <= margin_level());

    function [COUNTER_BITS-1:0] load_count;
        input integer cycles;
        begin
            load_count = (cycles <= 1) ? {COUNTER_BITS{1'b0}} :
                         cycles[COUNTER_BITS-1:0] - {{(COUNTER_BITS-1){1'b0}}, 1'b1};
        end
    endfunction

    function [COUNTER_BITS-1:0] margin_level;
        begin
            margin_level = T_MARGIN[COUNTER_BITS-1:0];
        end
    endfunction

    function enters_refresh_window;
        input [COUNTER_BITS-1:0] value;
        begin
            enters_refresh_window = (value <= margin_level()) ||
                                    ((value != {COUNTER_BITS{1'b0}}) &&
                                     ((value - {{(COUNTER_BITS-1){1'b0}}, 1'b1}) <= margin_level()));
        end
    endfunction

    always @(posedge i_clk) begin
        if (i_rst) begin
            cycles_to_deadline <= load_count(T_REFI);
            o_refresh_req <= 1'b0;
            o_refresh_late <= 1'b0;
            o_refresh_count <= 16'd0;
        end else if (!i_enable) begin
            cycles_to_deadline <= load_count(T_REFI);
            o_refresh_req <= 1'b0;
            o_refresh_late <= 1'b0;
        end else if (i_refresh_ack) begin
            cycles_to_deadline <= load_count(T_REFI);
            o_refresh_req <= 1'b0;
            o_refresh_late <= 1'b0;
            o_refresh_count <= o_refresh_count + 16'd1;
        end else begin
            if (cycles_to_deadline != {COUNTER_BITS{1'b0}})
                cycles_to_deadline <= cycles_to_deadline - {{(COUNTER_BITS-1){1'b0}}, 1'b1};
            else
                o_refresh_late <= 1'b1;

            if (enters_refresh_window(cycles_to_deadline))
                o_refresh_req <= 1'b1;
        end
    end
endmodule

`default_nettype wire

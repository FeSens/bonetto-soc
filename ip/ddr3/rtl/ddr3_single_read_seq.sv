// Minimal single-bank command sequencer.
//
// This is the second clean-sheet RTL slice: after initialization has completed,
// issue one conservative ACT/READ/PRE/REF sequence. It has no data capture and
// no Wishbone frontend; its purpose is to prove the runtime command path and
// the command timing monitor before we build a real scheduler.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_single_read_seq #(
    parameter integer ADDR_BITS = `DDR3_ADDR_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer T_RCD = `DDR3_800_TRCD_CYCLES,
    parameter integer T_RTP = `DDR3_800_TRTP_CYCLES,
    parameter integer T_RP  = `DDR3_800_TRP_CYCLES,
    parameter integer T_RFC = `DDR3_800_TRFC_CYCLES,
    parameter [BANK_BITS-1:0] BANK = {BANK_BITS{1'b0}},
    parameter [ADDR_BITS-1:0] ROW  = 15'h0123,
    parameter [ADDR_BITS-1:0] COL  = 15'h0000
) (
    input wire                 i_clk,
    input wire                 i_rst,
    input wire                 i_start,

    output reg                 o_busy,
    output reg                 o_done,
    output reg [3:0]           o_state,

    output reg                 o_cmd_valid,
    output reg                 o_cs_n,
    output reg                 o_ras_n,
    output reg                 o_cas_n,
    output reg                 o_we_n,
    output reg [BANK_BITS-1:0] o_ba,
    output reg [ADDR_BITS-1:0] o_addr
);
    localparam [3:0]
        ST_IDLE     = 4'd0,
        ST_ACT      = 4'd1,
        ST_WAIT_RCD = 4'd2,
        ST_READ     = 4'd3,
        ST_WAIT_RTP = 4'd4,
        ST_PRE      = 4'd5,
        ST_WAIT_RP  = 4'd6,
        ST_REF      = 4'd7,
        ST_WAIT_RFC = 4'd8,
        ST_DONE     = 4'd9;

    reg [15:0] wait_left;

    function [15:0] load_wait;
        input integer cycles;
        begin
            load_wait = (cycles <= 1) ? 16'd0 : cycles[15:0] - 16'd1;
        end
    endfunction

    function [15:0] dec_wait;
        input [15:0] value;
        begin
            dec_wait = (value == 16'd0) ? 16'd0 : value - 16'd1;
        end
    endfunction

    task set_cmd;
        input [3:0] command;
        input [BANK_BITS-1:0] bank;
        input [ADDR_BITS-1:0] addr;
        begin
            o_cmd_valid <= 1'b1;
            o_cs_n      <= command[3];
            o_ras_n     <= command[2];
            o_cas_n     <= command[1];
            o_we_n      <= command[0];
            o_ba        <= bank;
            o_addr      <= addr;
        end
    endtask

    always @(posedge i_clk) begin
        if (i_rst) begin
            o_busy    <= 1'b0;
            o_done    <= 1'b0;
            o_state   <= ST_IDLE;
            wait_left <= 16'd0;
            set_cmd(`DDR3_CMD_NOP, {BANK_BITS{1'b0}}, {ADDR_BITS{1'b0}});
        end else begin
            set_cmd(`DDR3_CMD_NOP, {BANK_BITS{1'b0}}, {ADDR_BITS{1'b0}});

            case (o_state)
                ST_IDLE: begin
                    o_busy <= 1'b0;
                    o_done <= 1'b0;
                    if (i_start) begin
                        o_busy  <= 1'b1;
                        o_state <= ST_ACT;
                    end
                end

                ST_ACT: begin
                    set_cmd(`DDR3_CMD_ACT, BANK, ROW);
                    o_state   <= ST_WAIT_RCD;
                    wait_left <= load_wait(T_RCD);
                end

                ST_WAIT_RCD: begin
                    if (wait_left == 16'd0)
                        o_state <= ST_READ;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_READ: begin
                    set_cmd(`DDR3_CMD_RD, BANK, COL);
                    o_state   <= ST_WAIT_RTP;
                    wait_left <= load_wait(T_RTP);
                end

                ST_WAIT_RTP: begin
                    if (wait_left == 16'd0)
                        o_state <= ST_PRE;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_PRE: begin
                    set_cmd(`DDR3_CMD_PRE, BANK, {ADDR_BITS{1'b0}});
                    o_state   <= ST_WAIT_RP;
                    wait_left <= load_wait(T_RP);
                end

                ST_WAIT_RP: begin
                    if (wait_left == 16'd0)
                        o_state <= ST_REF;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_REF: begin
                    set_cmd(`DDR3_CMD_REF, {BANK_BITS{1'b0}}, {ADDR_BITS{1'b0}});
                    o_state   <= ST_WAIT_RFC;
                    wait_left <= load_wait(T_RFC);
                end

                ST_WAIT_RFC: begin
                    if (wait_left == 16'd0)
                        o_state <= ST_DONE;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_DONE: begin
                    o_busy <= 1'b0;
                    o_done <= 1'b1;
                end

                default: begin
                    o_state <= ST_IDLE;
                end
            endcase
        end
    end
endmodule

`default_nettype wire

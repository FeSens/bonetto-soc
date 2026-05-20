// DDR3 reset and initialization sequencer.
//
// This first RTL slice owns only JEDEC reset/MRS/ZQ/REF bring-up. It emits one
// registered command per CK-domain cycle and intentionally does not include any
// bank scheduling, DQ/DQS PHY work, or Wishbone-facing behavior.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_init_seq #(
    parameter integer ADDR_BITS = `DDR3_ADDR_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer RESET_LOW_CYCLES = `DDR3_800_RESET_LOW_CYCLES,
    parameter integer RESET_CKE_CYCLES = `DDR3_800_RESET_CKE_CYCLES,
    parameter integer TXPR_CYCLES      = `DDR3_800_TXPR_CYCLES,
    parameter integer TMRD_CYCLES      = `DDR3_800_TMRD_CYCLES,
    parameter integer TMOD_CYCLES      = `DDR3_800_TMOD_CYCLES,
    parameter integer TZQINIT_CYCLES   = `DDR3_800_TZQINIT_CYCLES,
    parameter integer TRFC_CYCLES      = `DDR3_800_TRFC_CYCLES,
    parameter integer TDLLK_CYCLES     = `DDR3_800_TDLLK_CYCLES,
    parameter [ADDR_BITS-1:0] MR0 = `DDR3_MR0_DDR800,
    parameter [ADDR_BITS-1:0] MR1 = `DDR3_MR1_DDR800,
    parameter [ADDR_BITS-1:0] MR2 = `DDR3_MR2_DDR800,
    parameter [ADDR_BITS-1:0] MR3 = `DDR3_MR3_DDR800
) (
    input wire                  i_clk,
    input wire                  i_rst,
    input wire                  i_start,

    output reg                  o_busy,
    output reg                  o_done,
    output reg [4:0]            o_state,

    output reg                  o_reset_n,
    output reg                  o_cke,
    output reg                  o_odt,
    output reg                  o_cmd_valid,
    output reg                  o_cs_n,
    output reg                  o_ras_n,
    output reg                  o_cas_n,
    output reg                  o_we_n,
    output reg [BANK_BITS-1:0]  o_ba,
    output reg [ADDR_BITS-1:0]  o_addr
);
    localparam [4:0]
        ST_IDLE      = 5'd0,
        ST_RESET_LOW = 5'd1,
        ST_RESET_CKE = 5'd2,
        ST_TXPR      = 5'd3,
        ST_MR2       = 5'd4,
        ST_WAIT_MR2  = 5'd5,
        ST_MR3       = 5'd6,
        ST_WAIT_MR3  = 5'd7,
        ST_MR1       = 5'd8,
        ST_WAIT_MR1  = 5'd9,
        ST_MR0       = 5'd10,
        ST_WAIT_MR0  = 5'd11,
        ST_ZQCL      = 5'd12,
        ST_WAIT_ZQ   = 5'd13,
        ST_REF       = 5'd14,
        ST_WAIT_RFC  = 5'd15,
        ST_WAIT_DLLK = 5'd16,
        ST_DONE      = 5'd17;

    reg [31:0] wait_left;

    function [31:0] load_wait;
        input integer cycles;
        begin
            load_wait = (cycles <= 1) ? 32'd0 : cycles[31:0] - 32'd1;
        end
    endfunction

    function [31:0] dec_wait;
        input [31:0] value;
        begin
            dec_wait = (value == 32'd0) ? 32'd0 : value - 32'd1;
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
            o_busy      <= 1'b0;
            o_done      <= 1'b0;
            o_state     <= ST_IDLE;
            wait_left   <= 32'd0;
            o_reset_n   <= 1'b0;
            o_cke       <= 1'b0;
            o_odt       <= 1'b0;
            set_cmd(`DDR3_CMD_DES, {BANK_BITS{1'b0}}, {ADDR_BITS{1'b0}});
        end else begin
            o_odt <= 1'b0;

            if (!o_cke)
                set_cmd(`DDR3_CMD_DES, {BANK_BITS{1'b0}}, {ADDR_BITS{1'b0}});
            else
                set_cmd(`DDR3_CMD_NOP, {BANK_BITS{1'b0}}, {ADDR_BITS{1'b0}});

            case (o_state)
                ST_IDLE: begin
                    o_busy    <= 1'b0;
                    o_done    <= 1'b0;
                    o_reset_n <= 1'b0;
                    o_cke     <= 1'b0;
                    if (i_start) begin
                        o_busy    <= 1'b1;
                        o_state   <= ST_RESET_LOW;
                        wait_left <= load_wait(RESET_LOW_CYCLES);
                    end
                end

                ST_RESET_LOW: begin
                    o_busy    <= 1'b1;
                    o_done    <= 1'b0;
                    o_reset_n <= 1'b0;
                    o_cke     <= 1'b0;
                    if (wait_left == 32'd0) begin
                        o_reset_n <= 1'b1;
                        o_state   <= ST_RESET_CKE;
                        wait_left <= load_wait(RESET_CKE_CYCLES);
                    end else begin
                        wait_left <= dec_wait(wait_left);
                    end
                end

                ST_RESET_CKE: begin
                    o_reset_n <= 1'b1;
                    o_cke     <= 1'b0;
                    if (wait_left == 32'd0) begin
                        o_cke     <= 1'b1;
                        o_state   <= ST_TXPR;
                        wait_left <= load_wait(TXPR_CYCLES);
                    end else begin
                        wait_left <= dec_wait(wait_left);
                    end
                end

                ST_TXPR: begin
                    o_reset_n <= 1'b1;
                    o_cke     <= 1'b1;
                    if (wait_left == 32'd0)
                        o_state <= ST_MR2;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_MR2: begin
                    set_cmd(`DDR3_CMD_MRS, {{(BANK_BITS-2){1'b0}}, 2'd2}, MR2);
                    o_state   <= ST_WAIT_MR2;
                    wait_left <= load_wait(TMRD_CYCLES);
                end

                ST_WAIT_MR2: begin
                    if (wait_left == 32'd0)
                        o_state <= ST_MR3;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_MR3: begin
                    set_cmd(`DDR3_CMD_MRS, {{(BANK_BITS-2){1'b0}}, 2'd3}, MR3);
                    o_state   <= ST_WAIT_MR3;
                    wait_left <= load_wait(TMRD_CYCLES);
                end

                ST_WAIT_MR3: begin
                    if (wait_left == 32'd0)
                        o_state <= ST_MR1;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_MR1: begin
                    set_cmd(`DDR3_CMD_MRS, {{(BANK_BITS-1){1'b0}}, 1'd1}, MR1);
                    o_state   <= ST_WAIT_MR1;
                    wait_left <= load_wait(TMRD_CYCLES);
                end

                ST_WAIT_MR1: begin
                    if (wait_left == 32'd0)
                        o_state <= ST_MR0;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_MR0: begin
                    set_cmd(`DDR3_CMD_MRS, {BANK_BITS{1'b0}}, MR0);
                    o_state   <= ST_WAIT_MR0;
                    wait_left <= load_wait(TMOD_CYCLES);
                end

                ST_WAIT_MR0: begin
                    if (wait_left == 32'd0)
                        o_state <= ST_ZQCL;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_ZQCL: begin
                    set_cmd(`DDR3_CMD_ZQ, {BANK_BITS{1'b0}}, {{(ADDR_BITS-11){1'b0}}, 1'b1, 10'd0});
                    o_state   <= ST_WAIT_ZQ;
                    wait_left <= load_wait(TZQINIT_CYCLES);
                end

                ST_WAIT_ZQ: begin
                    if (wait_left == 32'd0)
                        o_state <= ST_REF;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_REF: begin
                    set_cmd(`DDR3_CMD_REF, {BANK_BITS{1'b0}}, {ADDR_BITS{1'b0}});
                    o_state   <= ST_WAIT_RFC;
                    wait_left <= load_wait(TRFC_CYCLES);
                end

                ST_WAIT_RFC: begin
                    if (wait_left == 32'd0) begin
                        o_state <= ST_WAIT_DLLK;
                        wait_left <= load_wait(TDLLK_CYCLES);
                    end else begin
                        wait_left <= dec_wait(wait_left);
                    end
                end

                ST_WAIT_DLLK: begin
                    if (wait_left == 32'd0)
                        o_state <= ST_DONE;
                    else
                        wait_left <= dec_wait(wait_left);
                end

                ST_DONE: begin
                    o_busy    <= 1'b0;
                    o_done    <= 1'b1;
                    o_reset_n <= 1'b1;
                    o_cke     <= 1'b1;
                end

                default: begin
                    o_state <= ST_IDLE;
                end
            endcase
        end
    end
endmodule

`default_nettype wire

// DDR3 command timing monitor.
//
// This is verification infrastructure, not the controller. Instantiate it next
// to any future controller command bus and it will assert the basic JEDEC
// command-ordering and timing contracts we want to preserve from day one.

`default_nettype none

module ddr3_cmd_timing_monitor #(
    parameter integer BANK_BITS = 3,
    parameter integer ROW_BITS  = 15,
    parameter integer T_RCD     = 3,
    parameter integer T_RP      = 3,
    parameter integer T_RAS     = 5,
    parameter integer T_RC      = 8,
    parameter integer T_RRD     = 3,
    parameter integer T_FAW     = 8,
    parameter integer T_CCD     = 4,
    parameter integer T_WTR     = 4,
    parameter integer T_RTP     = 4,
    parameter integer T_WR      = 4,
    parameter integer T_RFC     = 4,
    parameter integer T_ZQ      = 4,
    parameter integer T_REFI    = 64,
    parameter integer CHECK_REFRESH_DEADLINE = 0
) (
    input wire                 i_clk,
    input wire                 i_rst,
    input wire                 i_cmd_valid,
    input wire                 i_cs_n,
    input wire                 i_ras_n,
    input wire                 i_cas_n,
    input wire                 i_we_n,
    input wire [BANK_BITS-1:0] i_bank,
    input wire [ROW_BITS-1:0]  i_addr
);
    localparam integer BANKS = 1 << BANK_BITS;

    wire selected = i_cmd_valid && !i_cs_n;
    wire cmd_mrs  = selected && !i_ras_n && !i_cas_n && !i_we_n;
    wire cmd_ref  = selected && !i_ras_n && !i_cas_n &&  i_we_n;
    wire cmd_pre  = selected && !i_ras_n &&  i_cas_n && !i_we_n;
    wire cmd_act  = selected && !i_ras_n &&  i_cas_n &&  i_we_n;
    wire cmd_wr   = selected &&  i_ras_n && !i_cas_n && !i_we_n;
    wire cmd_rd   = selected &&  i_ras_n && !i_cas_n &&  i_we_n;
    wire cmd_zq   = selected &&  i_ras_n &&  i_cas_n && !i_we_n;
    wire cmd_nop  = !selected || (i_ras_n && i_cas_n && i_we_n);
    wire pre_all  = cmd_pre && i_addr[10];

    reg [BANKS-1:0] bank_open;
    reg [ROW_BITS-1:0] open_row [0:BANKS-1];

    reg [7:0] t_rcd_wait [0:BANKS-1];
    reg [7:0] t_rp_wait  [0:BANKS-1];
    reg [7:0] t_ras_wait [0:BANKS-1];
    reg [7:0] t_rc_wait  [0:BANKS-1];
    reg [7:0] t_wr_wait  [0:BANKS-1];
    reg [7:0] t_rtp_wait [0:BANKS-1];

    reg [7:0] t_rrd_wait;
    reg [7:0] t_ccd_wait;
    reg [7:0] t_wtr_wait;
    reg [7:0] t_rfc_wait;
    reg [7:0] t_zq_wait;
    reg [7:0] ref_deadline;

    reg [T_FAW-1:0] act_window;

    integer k;

    function [7:0] load_wait;
        input integer cycles;
        begin
            load_wait = (cycles <= 1) ? 8'd0 : cycles[7:0] - 8'd1;
        end
    endfunction

    function [7:0] dec_wait;
        input [7:0] value;
        begin
            dec_wait = (value == 8'd0) ? 8'd0 : value - 8'd1;
        end
    endfunction

    function [7:0] count_activates;
        input [T_FAW-1:0] window;
        integer i;
        begin
            count_activates = 8'd0;
            for (i = 0; i < T_FAW; i = i + 1)
                count_activates = count_activates + {7'd0, window[i]};
        end
    endfunction

    always @(posedge i_clk) begin
        if (i_rst) begin
            bank_open   <= {BANKS{1'b0}};
            t_rrd_wait  <= 8'd0;
            t_ccd_wait  <= 8'd0;
            t_wtr_wait  <= 8'd0;
            t_rfc_wait  <= 8'd0;
            t_zq_wait   <= 8'd0;
            ref_deadline <= T_REFI[7:0];
            act_window  <= {T_FAW{1'b0}};
            for (k = 0; k < BANKS; k = k + 1) begin
                open_row[k]   <= {ROW_BITS{1'b0}};
                t_rcd_wait[k] <= 8'd0;
                t_rp_wait[k]  <= 8'd0;
                t_ras_wait[k] <= 8'd0;
                t_rc_wait[k]  <= 8'd0;
                t_wr_wait[k]  <= 8'd0;
                t_rtp_wait[k] <= 8'd0;
            end
        end else begin
`ifdef FORMAL
            if (selected && !cmd_nop) begin
                assert(t_rfc_wait == 8'd0);
                assert(t_zq_wait == 8'd0);
            end

            if (cmd_act) begin
                assert(!bank_open[i_bank]);
                assert(t_rp_wait[i_bank] == 8'd0);
                assert(t_rc_wait[i_bank] == 8'd0);
                assert(t_rrd_wait == 8'd0);
                assert(count_activates(act_window) < 8'd4);
            end

            if (cmd_rd || cmd_wr) begin
                assert(bank_open[i_bank]);
                assert(open_row[i_bank] == i_addr);
                assert(t_rcd_wait[i_bank] == 8'd0);
                assert(t_ccd_wait == 8'd0);
            end

            if (cmd_rd)
                assert(t_wtr_wait == 8'd0);

            if (cmd_pre && !pre_all) begin
                assert(bank_open[i_bank]);
                assert(t_ras_wait[i_bank] == 8'd0);
                assert(t_wr_wait[i_bank] == 8'd0);
                assert(t_rtp_wait[i_bank] == 8'd0);
            end

            if (pre_all) begin
                for (k = 0; k < BANKS; k = k + 1) begin
                    assert(t_ras_wait[k] == 8'd0);
                    assert(t_wr_wait[k] == 8'd0);
                    assert(t_rtp_wait[k] == 8'd0);
                end
            end

            if (cmd_ref) begin
                assert(bank_open == {BANKS{1'b0}});
            end

            if (CHECK_REFRESH_DEADLINE)
                assert(ref_deadline != 8'd0 || cmd_ref);
`endif

            for (k = 0; k < BANKS; k = k + 1) begin
                t_rcd_wait[k] <= dec_wait(t_rcd_wait[k]);
                t_rp_wait[k]  <= dec_wait(t_rp_wait[k]);
                t_ras_wait[k] <= dec_wait(t_ras_wait[k]);
                t_rc_wait[k]  <= dec_wait(t_rc_wait[k]);
                t_wr_wait[k]  <= dec_wait(t_wr_wait[k]);
                t_rtp_wait[k] <= dec_wait(t_rtp_wait[k]);
            end

            t_rrd_wait <= dec_wait(t_rrd_wait);
            t_ccd_wait <= dec_wait(t_ccd_wait);
            t_wtr_wait <= dec_wait(t_wtr_wait);
            t_rfc_wait <= dec_wait(t_rfc_wait);
            t_zq_wait  <= dec_wait(t_zq_wait);
            act_window <= {act_window[T_FAW-2:0], cmd_act};

            if (CHECK_REFRESH_DEADLINE && ref_deadline != 8'd0)
                ref_deadline <= ref_deadline - 8'd1;

            if (cmd_act) begin
                bank_open[i_bank]   <= 1'b1;
                open_row[i_bank]    <= i_addr;
                t_rcd_wait[i_bank]  <= load_wait(T_RCD);
                t_ras_wait[i_bank]  <= load_wait(T_RAS);
                t_rc_wait[i_bank]   <= load_wait(T_RC);
                t_rrd_wait          <= load_wait(T_RRD);
            end

            if (cmd_rd) begin
                t_ccd_wait          <= load_wait(T_CCD);
                t_rtp_wait[i_bank]  <= load_wait(T_RTP);
            end

            if (cmd_wr) begin
                t_ccd_wait          <= load_wait(T_CCD);
                t_wtr_wait          <= load_wait(T_WTR);
                t_wr_wait[i_bank]   <= load_wait(T_WR);
            end

            if (cmd_pre && !pre_all) begin
                bank_open[i_bank]  <= 1'b0;
                t_rp_wait[i_bank] <= load_wait(T_RP);
            end

            if (pre_all) begin
                bank_open <= {BANKS{1'b0}};
                for (k = 0; k < BANKS; k = k + 1)
                    t_rp_wait[k] <= load_wait(T_RP);
            end

            if (cmd_ref) begin
                t_rfc_wait   <= load_wait(T_RFC);
                ref_deadline <= T_REFI[7:0];
            end

            if (cmd_zq)
                t_zq_wait <= load_wait(T_ZQ);

            if (cmd_mrs)
                t_zq_wait <= load_wait(2);
        end
    end
endmodule

`default_nettype wire

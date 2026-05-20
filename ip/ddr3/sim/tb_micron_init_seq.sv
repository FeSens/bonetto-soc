`default_nettype none
`timescale 1ps/1ps
`include "ddr3_params.vh"

module tb_micron_init_seq;
    localparam integer TCK_PS = `DDR3_800_TCK_PS;

    reg ck = 1'b0;
    wire ck_n = ~ck;
    reg rst = 1'b1;
    reg start = 1'b1;

    wire busy;
    wire done;
    wire [4:0] state;
    wire reset_n;
    wire cke;
    wire odt;
    wire cmd_valid;
    wire cs_n;
    wire ras_n;
    wire cas_n;
    wire we_n;
    wire [2:0] ba;
    wire [14:0] addr;
    wire [0:0] dm_tdqs;
    wire [7:0] dq;
    wire [0:0] dqs;
    wire [0:0] dqs_n;
    wire [0:0] tdqs_n;

    reg seed_inputs = 1'b1;
    reg model_reset_n = 1'b1;
    reg model_cke = 1'b1;
    reg model_odt = 1'b0;
    reg model_cs_n = 1'b0;
    reg model_ras_n = 1'b1;
    reg model_cas_n = 1'b1;
    reg model_we_n = 1'b1;
    reg [2:0] model_ba = 3'h7;
    reg [14:0] model_addr = 15'h7fff;

    pullup p_dm[0:0]  (dm_tdqs);
    pullup p_dq[7:0]  (dq);
    pullup p_dqs[0:0] (dqs);
    pulldown p_dqsn[0:0] (dqs_n);

    always #(TCK_PS / 2) ck <= ~ck;

    ddr3_init_seq #(
        .RESET_LOW_CYCLES(16),
        .RESET_CKE_CYCLES(20)
    ) u_init (
        .i_clk(ck),
        .i_rst(rst),
        .i_start(start),
        .o_busy(busy),
        .o_done(done),
        .o_state(state),
        .o_reset_n(reset_n),
        .o_cke(cke),
        .o_odt(odt),
        .o_cmd_valid(cmd_valid),
        .o_cs_n(cs_n),
        .o_ras_n(ras_n),
        .o_cas_n(cas_n),
        .o_we_n(we_n),
        .o_ba(ba),
        .o_addr(addr)
    );

    ddr3 #(
        .SIMUL_500US(0),
        .SIMUL_200US(0)
    ) u_model (
        .rst_n(model_reset_n),
        .ck(ck),
        .ck_n(ck_n),
        .cke(model_cke),
        .cs_n(model_cs_n),
        .ras_n(model_ras_n),
        .cas_n(model_cas_n),
        .we_n(model_we_n),
        .dm_tdqs(dm_tdqs),
        .ba(model_ba),
        .addr(model_addr),
        .dq(dq),
        .dqs(dqs),
        .dqs_n(dqs_n),
        .tdqs_n(tdqs_n),
        .odt(model_odt)
    );

    always @(negedge ck) begin
        if (!seed_inputs) begin
            model_reset_n <= reset_n;
            model_cke     <= cke;
            model_odt     <= odt;
            model_cs_n    <= cs_n;
            model_ras_n   <= ras_n;
            model_cas_n   <= cas_n;
            model_we_n    <= we_n;
            model_ba      <= ba;
            model_addr    <= addr;
        end
    end

    initial begin
        #1;
        model_reset_n = 1'b0;
        model_cke = 1'b0;
        model_cs_n = 1'b1;
        model_ba = 3'd0;
        model_addr = 15'd0;
        seed_inputs = 1'b0;
        repeat (4) @(posedge ck);
        rst = 1'b0;

        wait (done);
        repeat (`DDR3_800_TRFC_CYCLES) @(posedge ck);
        $display("[micron-init-rtl] DDR3 init sequencer reached done at state %0d", state);
        $finish;
    end

    initial begin
        repeat (5000) @(posedge ck);
        $display("[micron-init-rtl] timeout: state=%0d busy=%0b done=%0b reset_n=%0b cke=%0b cmd=%b ba=%0d addr=%h",
                 state, busy, done, reset_n, cke, {cs_n, ras_n, cas_n, we_n}, ba, addr);
        $fatal(1);
    end
endmodule

`default_nettype wire

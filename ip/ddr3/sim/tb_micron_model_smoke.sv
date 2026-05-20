// Micron DDR3 model smoke bench.
//
// This does not validate a controller. It makes the vendored Micron BFM part
// of the live simulation gate so future controller benches can fail for real
// protocol issues instead of bit-rotting at compile time.

`default_nettype none
`timescale 1ps / 1ps

module tb_micron_model_smoke;
    reg rst_n = 1'b0;
    reg ck    = 1'b0;
    wire ck_n = ~ck;

    reg cke   = 1'b0;
    reg cs_n  = 1'b1;
    reg ras_n = 1'b1;
    reg cas_n = 1'b1;
    reg we_n  = 1'b1;
    reg odt   = 1'b0;
    reg [2:0]  ba   = 3'd0;
    reg [14:0] addr = 15'd0;

    wire [0:0] dm_tdqs;
    wire [7:0] dq;
    wire [0:0] dqs;
    wire [0:0] dqs_n;
    wire [0:0] tdqs_n;

    pullup p_dm[0:0]  (dm_tdqs);
    pullup p_dq[7:0]  (dq);
    pullup p_dqs[0:0] (dqs);
    pulldown p_dqsn[0:0] (dqs_n);

    // DDR3-800 clock: 400 MHz CK, tCK = 2500 ps.
    always #1250 ck = ~ck;

    initial begin
        #20000;
        $display("[micron-smoke] Micron DDR3 x8 2Gb model elaborated and clocked");
        $finish;
    end

    ddr3 u_micron (
        .rst_n   (rst_n),
        .ck      (ck),
        .ck_n    (ck_n),
        .cke     (cke),
        .cs_n    (cs_n),
        .ras_n   (ras_n),
        .cas_n   (cas_n),
        .we_n    (we_n),
        .dm_tdqs (dm_tdqs),
        .ba      (ba),
        .addr    (addr),
        .dq      (dq),
        .dqs     (dqs),
        .dqs_n   (dqs_n),
        .tdqs_n  (tdqs_n),
        .odt     (odt)
    );
endmodule

`default_nettype wire

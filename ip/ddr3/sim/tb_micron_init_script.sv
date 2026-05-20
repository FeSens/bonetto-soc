`default_nettype none
`timescale 1ps/1ps

module tb_micron_init_script;
    localparam integer TCK_PS = 2500; // DDR3-800: 400 MHz CK, 800 MT/s data.

    localparam [3:0] CMD_DES = 4'b1111;
    localparam [3:0] CMD_NOP = 4'b0111;
    localparam [3:0] CMD_MRS = 4'b0000;
    localparam [3:0] CMD_REF = 4'b0001;
    localparam [3:0] CMD_ZQ  = 4'b0110;

    reg ck = 1'b0;
    wire ck_n = ~ck;
    reg rst_n = 1'b0;
    reg cke = 1'b0;
    reg cs_n = 1'b1;
    reg ras_n = 1'b1;
    reg cas_n = 1'b1;
    reg we_n = 1'b1;
    reg [14:0] addr = 15'd0;
    reg [2:0] ba = 3'd0;
    wire [0:0] dm_tdqs;
    wire [7:0] dq;
    wire [0:0] dqs;
    wire [0:0] dqs_n;
    wire [0:0] tdqs_n;
    reg odt = 1'b0;

    pullup p_dm[0:0]  (dm_tdqs);
    pullup p_dq[7:0]  (dq);
    pullup p_dqs[0:0] (dqs);
    pulldown p_dqsn[0:0] (dqs_n);

    always #(TCK_PS / 2) ck <= ~ck;

    ddr3 u_model (
        .rst_n(rst_n),
        .ck(ck),
        .ck_n(ck_n),
        .cke(cke),
        .cs_n(cs_n),
        .ras_n(ras_n),
        .cas_n(cas_n),
        .we_n(we_n),
        .dm_tdqs(dm_tdqs),
        .ba(ba),
        .addr(addr),
        .dq(dq),
        .dqs(dqs),
        .dqs_n(dqs_n),
        .tdqs_n(tdqs_n),
        .odt(odt)
    );

    task automatic drive_cmd(input [3:0] cmd, input [2:0] bank, input [14:0] a);
        begin
            @(negedge ck);
            {cs_n, ras_n, cas_n, we_n} = cmd;
            ba = bank;
            addr = a;
            @(negedge ck);
            {cs_n, ras_n, cas_n, we_n} = CMD_NOP;
            ba = 3'd0;
            addr = 15'd0;
        end
    endtask

    task automatic wait_cycles(input integer cycles);
        integer i;
        begin
            for (i = 0; i < cycles; i = i + 1)
                @(posedge ck);
        end
    endtask

    initial begin
        // Toggle pins once while reset is asserted so the Micron model's
        // delayed internal input copies do not start as X for zero commands.
        cke = 1'b1;
        {cs_n, ras_n, cas_n, we_n} = CMD_NOP;
        ba = 3'h7;
        addr = 15'h7fff;
        #1;
        cke = 1'b0;
        {cs_n, ras_n, cas_n, we_n} = CMD_DES;
        ba = 3'd0;
        addr = 15'd0;

        // JEDEC power-up: reset low, then CKE low after reset release.
        #(201_000_000);
        rst_n = 1'b1;
        #(500_000_000);
        @(negedge ck);
        {cs_n, ras_n, cas_n, we_n} = CMD_DES;
        wait_cycles(4);
        @(negedge ck);
        cke = 1'b1;
        wait_cycles(80); // tXPR margin at DDR3-800.

        // MR2: CWL=5, RTT_WR disabled.
        drive_cmd(CMD_MRS, 3'd2, 15'h0000);
        wait_cycles(8);

        // MR3: MPR disabled.
        drive_cmd(CMD_MRS, 3'd3, 15'h0000);
        wait_cycles(8);

        // MR1: DLL enabled, output enabled, no write leveling.
        drive_cmd(CMD_MRS, 3'd1, 15'h0000);
        wait_cycles(8);

        // MR0: BL8, sequential, CL=6, WR=6, DLL reset, DLL-on power down.
        drive_cmd(CMD_MRS, 3'd0, 15'h1520);
        wait_cycles(16); // tMOD margin before the first non-MRS command.

        // ZQCL command, then wait longer than 512 clocks.
        drive_cmd(CMD_ZQ, 3'd0, 15'h0400);
        wait_cycles(640);

        drive_cmd(CMD_REF, 3'd0, 15'h0000);
        wait_cycles(80);

        $display("[micron-init] DDR3-800 reset/MRS/ZQ/REF script completed");
        $finish;
    end
endmodule

`default_nettype wire

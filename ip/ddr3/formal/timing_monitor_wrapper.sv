// Self-check harness for ddr3_cmd_timing_monitor.
//
// This drives one legal DDR3 command trace through the monitor. It is not a
// controller proof; it keeps the verification primitive live so future
// controller RTL can be wired into a proven set of assertions.

`default_nettype none

module ddr3_timing_monitor_wrapper (
    input wire clk,
    input wire rst
);
    reg [7:0] step = 8'd0;

    reg        cmd_valid;
    reg        cs_n;
    reg        ras_n;
    reg        cas_n;
    reg        we_n;
    reg [2:0]  bank;
    reg [14:0] addr;

    localparam [3:0] CMD_MRS = 4'b0000;
    localparam [3:0] CMD_REF = 4'b0001;
    localparam [3:0] CMD_PRE = 4'b0010;
    localparam [3:0] CMD_ACT = 4'b0011;
    localparam [3:0] CMD_WR  = 4'b0100;
    localparam [3:0] CMD_RD  = 4'b0101;
    localparam [3:0] CMD_ZQ  = 4'b0110;
    localparam [3:0] CMD_NOP = 4'b0111;

    task set_cmd;
        input [3:0] command;
        input [2:0] command_bank;
        input [14:0] command_addr;
        begin
            cmd_valid = 1'b1;
            cs_n      = command[3];
            ras_n     = command[2];
            cas_n     = command[1];
            we_n      = command[0];
            bank      = command_bank;
            addr      = command_addr;
        end
    endtask

    always @(*) begin
        set_cmd(CMD_NOP, 3'd0, 15'd0);
        case (step)
            8'd2:  set_cmd(CMD_ACT, 3'd0, 15'h0123);
            8'd5:  set_cmd(CMD_RD,  3'd0, 15'h0000);
            8'd9:  set_cmd(CMD_PRE, 3'd0, 15'h0000);
            8'd12: set_cmd(CMD_REF, 3'd0, 15'h0000);
            8'd17: set_cmd(CMD_ACT, 3'd1, 15'h0456);
            8'd20: set_cmd(CMD_WR,  3'd1, 15'h0008);
            8'd24: set_cmd(CMD_PRE, 3'd1, 15'h0000);
            8'd28: set_cmd(CMD_ZQ,  3'd0, 15'h0400);
            default: begin end
        endcase
    end

    always @(posedge clk) begin
        if (rst)
            step <= 8'd0;
        else if (step != 8'hff)
            step <= step + 8'd1;
    end

    ddr3_cmd_timing_monitor #(
        .BANK_BITS(3),
        .ROW_BITS (15),
        .T_RCD    (3),
        .T_RP     (3),
        .T_RAS    (5),
        .T_RC     (8),
        .T_RRD    (3),
        .T_FAW    (8),
        .T_CCD    (4),
        .T_WTR    (4),
        .T_RTP    (4),
        .T_WR     (4),
        .T_RFC    (4),
        .T_ZQ     (4),
        .T_REFI   (64),
        .CHECK_REFRESH_DEADLINE(0)
    ) monitor (
        .i_clk       (clk),
        .i_rst       (rst),
        .i_cmd_valid (cmd_valid),
        .i_cs_n      (cs_n),
        .i_ras_n     (ras_n),
        .i_cas_n     (cas_n),
        .i_we_n      (we_n),
        .i_bank      (bank),
        .i_addr      (addr)
    );

`ifdef FORMAL
    initial assume(rst);

    always @(posedge clk) begin
        if (!rst) begin
            cover(step == 8'd12);
            cover(step == 8'd20);
            cover(step == 8'd28);
        end
    end
`endif
endmodule

`default_nettype wire

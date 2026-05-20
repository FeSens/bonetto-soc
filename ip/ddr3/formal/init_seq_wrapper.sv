// Formal harness for the DDR3 init sequencer.
//
// This proves the first controller-owned RTL slice emits the expected
// reset/MRS/ZQ/REF order and keeps minimum compressed waits between commands.

`default_nettype none
`include "ddr3_params.vh"

module ddr3_init_seq_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer RESET_LOW_CYCLES = 3;
    localparam integer RESET_CKE_CYCLES = 3;
    localparam integer TXPR_CYCLES      = 3;
    localparam integer TMRD_CYCLES      = 2;
    localparam integer TMOD_CYCLES      = 3;
    localparam integer TZQINIT_CYCLES   = 4;
    localparam integer TRFC_CYCLES      = 3;

    wire       busy;
    wire       done;
    wire [4:0] state;
    wire       reset_n;
    wire       cke;
    wire       odt;
    wire       cmd_valid;
    wire       cs_n;
    wire       ras_n;
    wire       cas_n;
    wire       we_n;
    wire [2:0] ba;
    wire [14:0] addr;

    ddr3_init_seq #(
        .RESET_LOW_CYCLES(RESET_LOW_CYCLES),
        .RESET_CKE_CYCLES(RESET_CKE_CYCLES),
        .TXPR_CYCLES(TXPR_CYCLES),
        .TMRD_CYCLES(TMRD_CYCLES),
        .TMOD_CYCLES(TMOD_CYCLES),
        .TZQINIT_CYCLES(TZQINIT_CYCLES),
        .TRFC_CYCLES(TRFC_CYCLES)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_start(1'b1),
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

`ifdef FORMAL
    wire selected = cmd_valid && !cs_n;
    wire [3:0] cmd = {cs_n, ras_n, cas_n, we_n};
    wire issue = selected && (cmd != `DDR3_CMD_NOP);

    reg f_past_valid = 1'b0;
    reg [7:0] command_index = 8'd0;
    reg [7:0] cycle_count = 8'd0;
    reg [7:0] last_issue_cycle = 8'd0;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;
        cycle_count <= cycle_count + 8'd1;

        if (f_past_valid)
            assume(!rst);

        assert(!odt);
        if (!reset_n || !cke)
            assert(!selected);
        if (cke)
            assert(reset_n);

        if (done) begin
            assert(!busy);
            assert(reset_n);
            assert(cke);
            assert(command_index == 8'd6);
        end

        if (rst) begin
            command_index <= 8'd0;
            last_issue_cycle <= 8'd0;
        end else if (issue) begin
            case (command_index)
                8'd0: begin
                    assert(cmd == `DDR3_CMD_MRS);
                    assert(ba == 3'd2);
                    assert(addr == `DDR3_MR2_DDR800);
                end
                8'd1: begin
                    assert(cmd == `DDR3_CMD_MRS);
                    assert(ba == 3'd3);
                    assert(addr == `DDR3_MR3_DDR800);
                    assert(cycle_count - last_issue_cycle >= TMRD_CYCLES[7:0]);
                end
                8'd2: begin
                    assert(cmd == `DDR3_CMD_MRS);
                    assert(ba == 3'd1);
                    assert(addr == `DDR3_MR1_DDR800);
                    assert(cycle_count - last_issue_cycle >= TMRD_CYCLES[7:0]);
                end
                8'd3: begin
                    assert(cmd == `DDR3_CMD_MRS);
                    assert(ba == 3'd0);
                    assert(addr == `DDR3_MR0_DDR800);
                    assert(cycle_count - last_issue_cycle >= TMRD_CYCLES[7:0]);
                end
                8'd4: begin
                    assert(cmd == `DDR3_CMD_ZQ);
                    assert(addr[10]);
                    assert(cycle_count - last_issue_cycle >= TMOD_CYCLES[7:0]);
                end
                8'd5: begin
                    assert(cmd == `DDR3_CMD_REF);
                    assert(cycle_count - last_issue_cycle >= TZQINIT_CYCLES[7:0]);
                end
                default: assert(1'b0);
            endcase

            command_index <= command_index + 8'd1;
            last_issue_cycle <= cycle_count;
        end

        cover(done);
        cover(command_index == 8'd6);
    end
`endif
endmodule

`default_nettype wire

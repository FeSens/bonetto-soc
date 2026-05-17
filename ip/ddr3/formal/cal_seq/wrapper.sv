// Formal harness for ddr3_cal_seq — write/read-leveling sequencer.
//
// Safety properties:
//   P1: cal_done is sticky once asserted (no spontaneous deassertion).
//   P2: cal_error is sticky once asserted (no spontaneous deassertion).
//   P3: cal_done and cal_error are mutually exclusive.
//   P4: o_wlvl_start is a one-cycle pulse (never two cycles in a row).
//   P5: o_rdlvl_start is a one-cycle pulse.
//   P6: cal_error_code value 2'b11 never appears (only {00, 01, 10}).
//   P7: cal_error_code is stable once it has become nonzero.
//   P8: cal_done implies cal_error_code == 0.
//   P9: o_mrs_req is a one-cycle pulse (matches wlvl/rdlvl_start pulse pattern).
//
// Cover properties (to demonstrate the FSM CAN reach each terminal):
//   C1: reach cal_done (full happy path through MR3 enable + rdlvl + MR3 disable).
//   C2: reach cal_error with code=01 (wlvl error).
//   C3: reach cal_error with code=10 (rdlvl error).
//   C4: reach o_mrs_req=1 at least once (exercises the MR3-rewrite path).

`default_nettype none

module cal_seq_wrapper (
    input wire clk,
    input wire rst
);
    (* anyseq *) wire init_done;
    (* anyseq *) wire wlvl_done, wlvl_error;
    (* anyseq *) wire rdlvl_done, rdlvl_error;
    (* anyseq *) wire mrs_busy;

    wire        wlvl_start, rdlvl_start;
    wire        mrs_req;
    wire [2:0]  mrs_ba;
    wire [14:0] mrs_addr;
    wire        cal_done, cal_error;
    wire [1:0]  cal_error_code;
    wire [3:0]  state;

    ddr3_cal_seq #(
        .SKIP_WLVL  (0),     // formal still proves the full wlvl-then-rdlvl flow
        .SKIP_RDLVL (0)
    ) dut (
        .i_clk            (clk),
        .i_rst            (rst),
        .i_init_done      (init_done),
        .o_wlvl_start     (wlvl_start),
        .i_wlvl_done      (wlvl_done),
        .i_wlvl_error     (wlvl_error),
        .o_rdlvl_start    (rdlvl_start),
        .i_rdlvl_done     (rdlvl_done),
        .i_rdlvl_error    (rdlvl_error),
        .o_mrs_req        (mrs_req),
        .o_mrs_ba         (mrs_ba),
        .o_mrs_addr       (mrs_addr),
        .i_mrs_busy       (mrs_busy),
        .o_cal_done       (cal_done),
        .o_cal_error      (cal_error),
        .o_cal_error_code (cal_error_code),
        .o_state          (state)
    );

`ifdef FORMAL
    initial assume(rst);

    // Track prior-cycle values for stickiness checks.
    reg cal_done_q     = 1'b0;
    reg cal_error_q    = 1'b0;
    reg wlvl_start_q   = 1'b0;
    reg rdlvl_start_q  = 1'b0;
    reg mrs_req_q      = 1'b0;
    reg [1:0] cal_error_code_q = 2'b00;
    always @(posedge clk) begin
        if (rst) begin
            cal_done_q       <= 1'b0;
            cal_error_q      <= 1'b0;
            wlvl_start_q     <= 1'b0;
            rdlvl_start_q    <= 1'b0;
            mrs_req_q        <= 1'b0;
            cal_error_code_q <= 2'b00;
        end else begin
            cal_done_q       <= cal_done;
            cal_error_q      <= cal_error;
            wlvl_start_q     <= wlvl_start;
            rdlvl_start_q    <= rdlvl_start;
            mrs_req_q        <= mrs_req;
            cal_error_code_q <= cal_error_code;
        end
    end

    // -------- P1: cal_done sticky --------
    always @(posedge clk) begin
        if (!rst && cal_done_q)
            assert(cal_done);
    end

    // -------- P2: cal_error sticky --------
    always @(posedge clk) begin
        if (!rst && cal_error_q)
            assert(cal_error);
    end

    // -------- P3: cal_done and cal_error mutually exclusive --------
    always @(posedge clk) begin
        if (!rst)
            assert(!(cal_done && cal_error));
    end

    // -------- P4: wlvl_start is a 1-cycle pulse --------
    always @(posedge clk) begin
        if (!rst && wlvl_start_q)
            assert(!wlvl_start);
    end

    // -------- P5: rdlvl_start is a 1-cycle pulse --------
    always @(posedge clk) begin
        if (!rst && rdlvl_start_q)
            assert(!rdlvl_start);
    end

    // -------- P6: cal_error_code never takes value 2'b11 --------
    always @(posedge clk) begin
        if (!rst)
            assert(cal_error_code != 2'b11);
    end

    // -------- P7: cal_error_code stable once nonzero --------
    always @(posedge clk) begin
        if (!rst && cal_error_code_q != 2'b00)
            assert(cal_error_code == cal_error_code_q);
    end

    // -------- P8: cal_done implies cal_error_code == 0 --------
    always @(posedge clk) begin
        if (!rst && cal_done)
            assert(cal_error_code == 2'b00);
    end

    // -------- P9: o_mrs_req is a 1-cycle pulse --------
    always @(posedge clk) begin
        if (!rst && mrs_req_q)
            assert(!mrs_req);
    end

    // -------- Cover properties --------
    always @(posedge clk) begin
        if (!rst) begin
            cover(cal_done);
            cover(cal_error && cal_error_code == 2'b01);
            cover(cal_error && cal_error_code == 2'b10);
            cover(mrs_req);
        end
    end
`endif
endmodule

// memtest_lite — Wishbone B4 pipelined master.
//
// Iter-4 (cal-gated DDR3 + BRAM sanity):
//   * Pre-cal_done: hits BRAM (adr[14]=0). 16K-word sweep, validates the
//     WB master + decoder + memory protocol works.
//   * Post-cal_done: hits DDR3 (adr[14]=1). Same 16K-word sweep on a
//     fresh address window in DDR3. memtest tracks BRAM and DDR3 pass
//     counters independently so the host can see "BRAM works" before
//     "DDR3 works".
//
// LED encoding:
//   led[0] = last_ok         most-recent read matched
//   led[1] = heartbeat       toggles ~0.3 s; FSM is alive
//   led[2] = sticky_error    set on first DDR3 mismatch
//
// Status outputs (consumed by board-top status mux):
//   o_pass_ctr             — total successful BRAM+DDR3 read/compare
//   o_ddr3_pass_ctr        — DDR3-only pass counter
//   o_err_ctr              — total mismatches
//   o_first_err_addr       — first mismatched addr (full 32 bits with target bit)
//   o_first_err_expected   — first mismatch expected pattern
//   o_first_err_got        — first mismatch actual pattern
//   o_any_err              — sticky error
//   o_target               — current target: 0=BRAM, 1=DDR3

`default_nettype none

module memtest_lite #(
    parameter integer WB_ADDR_W = 15      // top.v's wb_decode2 SEL_BIT = 14
) (
    input  wire        i_clk,
    input  wire        i_rst,
    input  wire        i_cal_done,        // synchronised from DDR3 cal_seq

    // Wishbone master
    output reg         o_wb_cyc,
    output reg         o_wb_stb,
    output reg         o_wb_we,
    output reg  [WB_ADDR_W-1:0] o_wb_adr,
    output reg  [31:0] o_wb_dat,
    output wire [3:0]  o_wb_sel,
    input  wire        i_wb_stall,
    input  wire        i_wb_ack,
    input  wire [31:0] i_wb_dat,
    input  wire        i_wb_err,

    output wire [2:0]  o_led,

    // Status outputs
    output wire [31:0] o_pass_ctr,
    output wire [31:0] o_ddr3_pass_ctr,
    output wire [31:0] o_err_ctr,
    output wire [31:0] o_first_err_addr,
    output wire [31:0] o_first_err_expected,
    output wire [31:0] o_first_err_got,
    output wire        o_any_err,
    output wire        o_target
);
    assign o_wb_sel = 4'b1111;

    localparam [1:0]
        S_WRITE     = 2'd0,
        S_WAIT_WACK = 2'd1,
        S_READ      = 2'd2,
        S_WAIT_RACK = 2'd3;

    reg [1:0]  state              = S_WRITE;
    reg [13:0] addr               = 14'd0;
    reg [31:0] pattern            = 32'd0;
    reg        any_err            = 1'b0;
    reg        last_ok            = 1'b0;
    reg [31:0] pass_ctr           = 32'd0;
    reg [31:0] ddr3_pass_ctr      = 32'd0;
    reg [31:0] err_ctr            = 32'd0;
    reg [31:0] first_err_addr     = 32'd0;
    reg [31:0] first_err_expected = 32'd0;
    reg [31:0] first_err_got      = 32'd0;
    reg [23:0] heartbeat          = 24'd0;
    reg        target             = 1'b0;  // 0=BRAM, 1=DDR3
    reg        bram_validated     = 1'b0;  // set once a full BRAM sweep passes

    always @(posedge i_clk) heartbeat <= heartbeat + 1'b1;

    // Pattern: 0xA + 12-bit addr-hi + 14-bit addr + 2'b00 → 32 bits
    wire [31:0] pattern_for_addr = {4'hA, addr, addr};

    wire [WB_ADDR_W-1:0] tgt_addr = {target, addr};

    // Promotion to DDR3 target: once BRAM validated AND cal_done.
    // The first time we wrap addr through 0x3FFF in BRAM successfully,
    // we mark bram_validated. On the next wrap we promote target to DDR3
    // if cal_done is high.
    wire promote_to_ddr3 = bram_validated && i_cal_done && (target == 1'b0);

    always @(posedge i_clk) begin
        if (i_rst) begin
            state              <= S_WRITE;
            addr               <= 14'd0;
            any_err            <= 1'b0;
            last_ok            <= 1'b0;
            pass_ctr           <= 32'd0;
            ddr3_pass_ctr      <= 32'd0;
            err_ctr            <= 32'd0;
            first_err_addr     <= 32'd0;
            first_err_expected <= 32'd0;
            first_err_got      <= 32'd0;
            target             <= 1'b0;
            bram_validated     <= 1'b0;
            o_wb_cyc           <= 1'b0;
            o_wb_stb           <= 1'b0;
            o_wb_we            <= 1'b0;
        end else begin
            case (state)
                S_WRITE: begin
                    pattern  <= pattern_for_addr;
                    o_wb_cyc <= 1'b1;
                    o_wb_stb <= 1'b1;
                    o_wb_we  <= 1'b1;
                    o_wb_adr <= tgt_addr;
                    o_wb_dat <= pattern_for_addr;
                    state    <= S_WAIT_WACK;
                end
                S_WAIT_WACK: begin
                    if (i_wb_ack) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
                        state    <= S_READ;
                    end
                end
                S_READ: begin
                    o_wb_cyc <= 1'b1;
                    o_wb_stb <= 1'b1;
                    o_wb_we  <= 1'b0;
                    o_wb_adr <= tgt_addr;
                    state    <= S_WAIT_RACK;
                end
                S_WAIT_RACK: begin
                    if (i_wb_ack) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
                        last_ok  <= (i_wb_dat == pattern);
                        if (i_wb_dat != pattern) begin
                            err_ctr <= err_ctr + 1'b1;
                            if (!any_err) begin
                                first_err_addr     <= {17'b0, target, addr};
                                first_err_expected <= pattern;
                                first_err_got      <= i_wb_dat;
                            end
                            any_err <= 1'b1;
                        end
                        pass_ctr <= pass_ctr + 1'b1;
                        if (target) ddr3_pass_ctr <= ddr3_pass_ctr + 1'b1;

                        // Wrap addr and possibly promote to DDR3.
                        if (addr == 14'h3FFF) begin
                            addr <= 14'd0;
                            if (target == 1'b0) bram_validated <= 1'b1;
                            if (promote_to_ddr3) target <= 1'b1;
                        end else begin
                            addr <= addr + 1'b1;
                        end
                        state <= S_WRITE;
                    end
                end
                default: state <= S_WRITE;
            endcase
        end
    end

    /* verilator lint_off UNUSED */
    wire _unused = &{1'b0, i_wb_stall, i_wb_err, 1'b0};
    /* verilator lint_on UNUSED */

    assign o_led = {any_err, heartbeat[23], last_ok};

    assign o_pass_ctr           = pass_ctr;
    assign o_ddr3_pass_ctr      = ddr3_pass_ctr;
    assign o_err_ctr            = err_ctr;
    assign o_first_err_addr     = first_err_addr;
    assign o_first_err_expected = first_err_expected;
    assign o_first_err_got      = first_err_got;
    assign o_any_err            = any_err;
    assign o_target             = target;
endmodule

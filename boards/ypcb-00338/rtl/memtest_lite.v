// memtest_lite — Wishbone B4 pipelined master with multi-pattern coverage.
//
// Iter-5 (cal-gated + pattern sweep):
//   * Pre-cal_done: hits BRAM (adr[14]=0). 16K-word sweep validates the
//     WB master + decoder + memory protocol.
//   * Post-cal_done: hits DDR3 (adr[14]=1). Same 16K-word sweep on a
//     fresh address window in DDR3.
//   * Each "pass" cycles through 4 patterns: address-as-data, walking-1,
//     0xAA repeating, and 0x55 repeating. Catches stuck-at, swapped-bit,
//     and DQ-rotation faults that a single-pattern test misses.
//
// LED encoding:
//   led[0] = last_ok         most-recent read matched
//   led[1] = heartbeat       toggles ~0.3 s; FSM is alive
//   led[2] = sticky_error    set on first DDR3 mismatch (any pattern)

`default_nettype none

module memtest_lite #(
    parameter integer WB_ADDR_W = 15      // top.v's wb_decode2 SEL_BIT = 14
) (
    input  wire        i_clk,
    input  wire        i_rst,
    input  wire        i_cal_done,
    input  wire        i_pause,           // iter-7: held high → FSM stalls at next IDLE


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

    output wire [31:0] o_pass_ctr,
    output wire [31:0] o_ddr3_pass_ctr,
    output wire [31:0] o_err_ctr,
    output wire [31:0] o_first_err_addr,
    output wire [31:0] o_first_err_expected,
    output wire [31:0] o_first_err_got,
    output wire        o_any_err,
    output wire        o_target,
    output wire [1:0]  o_pattern_idx
);
    assign o_wb_sel = 4'b1111;

    localparam [2:0]
        S_WRITE     = 3'd0,
        S_WAIT_WACK = 3'd1,
        S_READ      = 3'd2,
        S_WAIT_RACK = 3'd3,
        S_CHECK     = 3'd4;

    reg [2:0]  state              = S_WRITE;
    reg [13:0] addr               = 14'd0;
    reg [1:0]  pattern_idx        = 2'd0;     // 0=addr-data, 1=walking1, 2=0xAA, 3=0x55
    reg [4:0]  walk_bit           = 5'd0;
    reg [31:0] pattern            = 32'd0;
    reg        any_err            = 1'b0;
    reg        last_ok            = 1'b0;
    reg [31:0] pass_ctr           = 32'd0;
    reg [31:0] ddr3_pass_ctr      = 32'd0;
    reg [31:0] err_ctr            = 32'd0;
    reg [31:0] first_err_addr     = 32'd0;
    reg [31:0] first_err_expected = 32'd0;
    reg [31:0] first_err_got      = 32'd0;
    reg [31:0] read_dat_q         = 32'd0;
    reg [23:0] heartbeat          = 24'd0;
    reg        target             = 1'b0;
    reg        bram_validated     = 1'b0;

    // Power-up values for the WB output regs. FPGA flops respect these
    // via the bitstream so power-up matches sim/formal: cyc/stb/we=0.
    initial begin
        o_wb_cyc = 1'b0;
        o_wb_stb = 1'b0;
        o_wb_we  = 1'b0;
        o_wb_adr = {WB_ADDR_W{1'b0}};
        o_wb_dat = 32'd0;
    end

    always @(posedge i_clk) heartbeat <= heartbeat + 1'b1;

    // Pattern generator — picks one of 4 patterns per pattern_idx.
    reg [31:0] pattern_for_addr;
    always @(*) begin
        case (pattern_idx)
            2'd0: pattern_for_addr = {4'hA, addr, addr};        // address-as-data
            2'd1: pattern_for_addr = (32'd1 << walk_bit);        // walking-1
            2'd2: pattern_for_addr = 32'hAAAAAAAA;               // 0xAA stripes
            2'd3: pattern_for_addr = 32'h55555555;               // 0x55 stripes
        endcase
    end

    wire [WB_ADDR_W-1:0] tgt_addr = {target, addr};

    wire promote_to_ddr3 = bram_validated && i_cal_done && (target == 1'b0);

    always @(posedge i_clk) begin
        if (i_rst) begin
            state              <= S_WRITE;
            addr               <= 14'd0;
            pattern_idx        <= 2'd0;
            walk_bit           <= 5'd0;
            any_err            <= 1'b0;
            last_ok            <= 1'b0;
            pass_ctr           <= 32'd0;
            ddr3_pass_ctr      <= 32'd0;
            err_ctr            <= 32'd0;
            first_err_addr     <= 32'd0;
            first_err_expected <= 32'd0;
            first_err_got      <= 32'd0;
            read_dat_q         <= 32'd0;
            target             <= 1'b0;
            bram_validated     <= 1'b0;
            o_wb_cyc           <= 1'b0;
            o_wb_stb           <= 1'b0;
            o_wb_we            <= 1'b0;
        end else begin
            case (state)
                S_WRITE: begin
                    if (i_pause) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
                    end else begin
                        pattern  <= pattern_for_addr;
                        o_wb_cyc <= 1'b1;
                        o_wb_stb <= 1'b1;
                        o_wb_we  <= 1'b1;
                        o_wb_adr <= tgt_addr;
                        o_wb_dat <= pattern_for_addr;
                        state    <= S_WAIT_WACK;
                    end
                end
                S_WAIT_WACK: begin
                    // WB B4 pipelined: drop stb as soon as the slave has
                    // accepted (i.e., !stall on the previous cycle). This
                    // prevents fwb_master from counting multiple
                    // outstanding requests for the single transaction.
                    if (!i_wb_stall) o_wb_stb <= 1'b0;
                    // On err, abort: drop cyc/stb and return to S_WRITE.
                    if (i_wb_err) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
                        state    <= S_WRITE;
                    end else if (i_wb_ack) begin
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
                    if (!i_wb_stall) o_wb_stb <= 1'b0;
                    if (i_wb_err) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
                        state    <= S_WRITE;
                    end else if (i_wb_ack) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
                        read_dat_q <= i_wb_dat;
                        state    <= S_CHECK;
                    end
                end
                S_CHECK: begin
                    last_ok <= (read_dat_q == pattern);
                    if (read_dat_q != pattern) begin
                        err_ctr <= err_ctr + 1'b1;
                        if (!any_err) begin
                            first_err_addr     <= {15'b0, pattern_idx, target, addr};
                            first_err_expected <= pattern;
                            first_err_got      <= read_dat_q;
                        end
                        any_err <= 1'b1;
                    end
                    pass_ctr <= pass_ctr + 1'b1;
                    if (target) ddr3_pass_ctr <= ddr3_pass_ctr + 1'b1;

                    if (addr == 14'h3FFF) begin
                        addr <= 14'd0;
                        if (target == 1'b0) bram_validated <= 1'b1;
                        if (promote_to_ddr3) target <= 1'b1;
                        // Cycle pattern index every BRAM wrap.
                        pattern_idx <= pattern_idx + 1'b1;
                        // Walking-1 bit advances every full sweep of pattern 1.
                        if (pattern_idx == 2'd1)
                            walk_bit <= (walk_bit == 5'd31) ? 5'd0 : walk_bit + 1'b1;
                    end else begin
                        addr <= addr + 1'b1;
                    end
                    state <= S_WRITE;
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
    assign o_pattern_idx        = pattern_idx;
endmodule

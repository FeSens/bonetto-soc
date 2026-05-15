// memtest_lite — minimal Wishbone B4 pipelined master driving wb_memory
// through a write / read-back / compare loop. Iter-1 SoC integration test.
//
// LED encoding:
//   led[0] = last_ok          — most recent read matched the expected pattern
//   led[1] = heartbeat        — toggles every ~0.3 s; "the FSM is running"
//   led[2] = sticky_error     — set on first mismatch ever; stays set
//
// On healthy hardware: led[0] solid on, led[1] blinking, led[2] off.

`default_nettype none

module memtest_lite (
    input  wire        i_clk,
    input  wire        i_rst,
    output reg         o_wb_cyc,
    output reg         o_wb_stb,
    output reg         o_wb_we,
    output reg  [13:0] o_wb_adr,
    output reg  [31:0] o_wb_dat,
    output wire [3:0]  o_wb_sel,
    input  wire        i_wb_stall,
    input  wire        i_wb_ack,
    input  wire [31:0] i_wb_dat,
    input  wire        i_wb_err,
    output wire [2:0]  o_led
);
    assign o_wb_sel = 4'b1111;

    localparam [1:0]
        S_WRITE     = 2'd0,
        S_WAIT_WACK = 2'd1,
        S_READ      = 2'd2,
        S_WAIT_RACK = 2'd3;

    reg [1:0]  state     = S_WRITE;
    reg [13:0] addr      = 14'd0;
    reg [31:0] pattern   = 32'd0;
    reg        any_err   = 1'b0;
    reg        last_ok   = 1'b0;
    reg [23:0] heartbeat = 24'd0;

    always @(posedge i_clk) heartbeat <= heartbeat + 1'b1;

    // Pattern: every word has a recognisable value derived from its address.
    // Using {addr,addr,4'hA} keeps it dependent on every address bit while
    // remaining easy to eyeball if we ever read it back over JTAG-UART.
    wire [31:0] pattern_for_addr = {4'hA, addr, addr};

    always @(posedge i_clk) begin
        if (i_rst) begin
            state    <= S_WRITE;
            addr     <= 14'd0;
            any_err  <= 1'b0;
            last_ok  <= 1'b0;
            o_wb_cyc <= 1'b0;
            o_wb_stb <= 1'b0;
            o_wb_we  <= 1'b0;
        end else begin
            case (state)
                S_WRITE: begin
                    pattern  <= pattern_for_addr;
                    o_wb_cyc <= 1'b1;
                    o_wb_stb <= 1'b1;
                    o_wb_we  <= 1'b1;
                    o_wb_adr <= addr;
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
                    o_wb_adr <= addr;
                    state    <= S_WAIT_RACK;
                end
                S_WAIT_RACK: begin
                    if (i_wb_ack) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
                        last_ok  <= (i_wb_dat == pattern);
                        if (i_wb_dat != pattern) any_err <= 1'b1;
                        addr     <= addr + 1'b1;
                        state    <= S_WRITE;
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
endmodule

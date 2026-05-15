// memtest_lite — Wishbone B4 pipelined master.
//
// Iter-2.5: drives two slaves through a wb_decode2:
//   adr[14]=0 → wb_memory (BRAM): write/read/compare loop
//   adr[14]=1 → jtag_uart      : after every 1024 successful test cycles,
//                                publish the pass counter so the host
//                                reads it via XVC + USER1.
//
// LED encoding unchanged from iter-1:
//   led[0] = last_ok         most-recent read matched
//   led[1] = heartbeat       toggles every ~0.3 s; FSM is alive
//   led[2] = sticky_error    set on first mismatch, stays set
//
// On healthy hardware: led[0] solid, led[1] blinking, led[2] off,
// AND jtag_uart's fpga_to_host = pass counter incrementing over JTAG.

`default_nettype none

module memtest_lite (
    input  wire        i_clk,
    input  wire        i_rst,
    // Wishbone master (single port — wb_decode2 routes to BRAM/UART)
    output reg         o_wb_cyc,
    output reg         o_wb_stb,
    output reg         o_wb_we,
    output reg  [14:0] o_wb_adr,        // 15-bit address: bit 14 = decoder SEL
    output reg  [31:0] o_wb_dat,
    output wire [3:0]  o_wb_sel,
    input  wire        i_wb_stall,
    input  wire        i_wb_ack,
    input  wire [31:0] i_wb_dat,
    input  wire        i_wb_err,
    // Status LEDs
    output wire [2:0]  o_led
);
    assign o_wb_sel = 4'b1111;

    // Address layout for the decoder: SEL_BIT = 14
    localparam UART_TX_OFFSET = 15'h4000;  // bit 14 set → jtag_uart base

    localparam [2:0]
        S_WRITE      = 3'd0,
        S_WAIT_WACK  = 3'd1,
        S_READ       = 3'd2,
        S_WAIT_RACK  = 3'd3,
        S_REPORT     = 3'd4,
        S_WAIT_REPACK = 3'd5;

    reg [2:0]  state     = S_WRITE;
    reg [13:0] addr      = 14'd0;
    reg [31:0] pattern   = 32'd0;
    reg        any_err   = 1'b0;
    reg        last_ok   = 1'b0;
    reg [31:0] pass_ctr  = 32'd0;
    reg [23:0] heartbeat = 24'd0;

    always @(posedge i_clk) heartbeat <= heartbeat + 1'b1;

    wire [31:0] pattern_for_addr = {4'hA, addr, addr};

    always @(posedge i_clk) begin
        if (i_rst) begin
            state    <= S_WRITE;
            addr     <= 14'd0;
            any_err  <= 1'b0;
            last_ok  <= 1'b0;
            pass_ctr <= 32'd0;
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
                    o_wb_adr <= {1'b0, addr};               // bit 14 = 0 → BRAM
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
                    o_wb_adr <= {1'b0, addr};
                    state    <= S_WAIT_RACK;
                end
                S_WAIT_RACK: begin
                    if (i_wb_ack) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
                        last_ok  <= (i_wb_dat == pattern);
                        if (i_wb_dat != pattern) any_err <= 1'b1;
                        pass_ctr <= pass_ctr + 1'b1;
                        addr     <= addr + 1'b1;
                        // Every 1024 test cycles, push pass_ctr to jtag_uart
                        // so the host can read it via XVC + USER1.
                        if (addr[9:0] == 10'h3FF) state <= S_REPORT;
                        else                      state <= S_WRITE;
                    end
                end
                S_REPORT: begin
                    o_wb_cyc <= 1'b1;
                    o_wb_stb <= 1'b1;
                    o_wb_we  <= 1'b1;
                    o_wb_adr <= UART_TX_OFFSET;             // bit 14 = 1 → jtag_uart
                    o_wb_dat <= pass_ctr;
                    state    <= S_WAIT_REPACK;
                end
                S_WAIT_REPACK: begin
                    if (i_wb_ack) begin
                        o_wb_cyc <= 1'b0;
                        o_wb_stb <= 1'b0;
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

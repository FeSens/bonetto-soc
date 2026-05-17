// jtag_wb_master — Host-driven Wishbone master via jtag_uart command words.
//
// iter-7: while memtest_lite drives the WB bus autonomously, this module
// lets the host drive arbitrary WB transactions over JTAG. The host writes
// command codes embedded in the upper byte of jtag_uart's o_host_to_fpga
// word; this module decodes them into stored addr/data and triggers WB
// master cycles.
//
// Command codes (i_cmd_word[31:24]) — gated by i_cmd_valid pulse:
//   0x00     reserved for status-mux select (handled by top.v, no-op here)
//   0xE0     SET_ADDR    - addr[14:0] <= i_cmd_word[14:0]
//   0xE2     SET_DATA_LO - data[15:0] <= i_cmd_word[15:0]
//   0xE3     SET_DATA_HI - data[31:16] <= i_cmd_word[15:0]
//   0xE4     GO_WRITE    - issue WB write of stored data to stored addr
//   0xE5     GO_READ     - issue WB read of stored addr; latch result in rd_data
//   0xE6     HALT_OTHERS - assert o_halt_others (top.v pauses memtest_lite)
//   0xE7     RESUME      - clear o_halt_others
//
// Status outputs (consumed by top.v status mux at reg indices 0x10-0x15):
//   o_busy        1 while a WB transaction is in flight
//   o_last_ack    sticky: last completed transaction got an ack
//   o_last_err    sticky: last transaction asserted err
//   o_addr        currently stored WB addr
//   o_data        currently stored write data
//   o_rd_data     last read data

`default_nettype none

module jtag_wb_master #(
    parameter integer WB_ADDR_W = 15,
    parameter integer WB_DATA_W = 32
) (
    input  wire                     i_clk,
    input  wire                     i_rst,

    // Host command input (clk-aligned pulses + bus, already CDC'd in parent).
    input  wire [31:0]              i_cmd_word,
    input  wire                     i_cmd_valid,

    // Wishbone B4 pipelined master to the bus mux.
    output reg                      o_wb_cyc,
    output reg                      o_wb_stb,
    output reg                      o_wb_we,
    output reg  [WB_ADDR_W-1:0]     o_wb_adr,
    output reg  [WB_DATA_W-1:0]     o_wb_dat,
    output wire [WB_DATA_W/8-1:0]   o_wb_sel,
    input  wire                     i_wb_stall,
    input  wire                     i_wb_ack,
    input  wire [WB_DATA_W-1:0]     i_wb_dat,
    input  wire                     i_wb_err,

    // Status visible through top.v status mux.
    output reg                      o_busy,
    output reg                      o_last_ack,
    output reg                      o_last_err,
    output reg  [WB_ADDR_W-1:0]     o_addr,
    output reg  [WB_DATA_W-1:0]     o_data,
    output reg  [WB_DATA_W-1:0]     o_rd_data,
    output reg                      o_halt_others
);
    assign o_wb_sel = {(WB_DATA_W/8){1'b1}};

    localparam [1:0]
        S_IDLE    = 2'd0,
        S_WB_STB  = 2'd1,
        S_WB_WAIT = 2'd2;

    reg [1:0] state;

    wire [7:0] cmd = i_cmd_word[31:24];
    wire       cmd_set_addr = i_cmd_valid && (cmd == 8'hE0);
    wire       cmd_set_dlo  = i_cmd_valid && (cmd == 8'hE2);
    wire       cmd_set_dhi  = i_cmd_valid && (cmd == 8'hE3);
    wire       cmd_go_wr    = i_cmd_valid && (cmd == 8'hE4);
    wire       cmd_go_rd    = i_cmd_valid && (cmd == 8'hE5);
    wire       cmd_halt     = i_cmd_valid && (cmd == 8'hE6);
    wire       cmd_resume   = i_cmd_valid && (cmd == 8'hE7);

    always @(posedge i_clk) begin
        if (i_rst) begin
            state         <= S_IDLE;
            o_wb_cyc      <= 1'b0;
            o_wb_stb      <= 1'b0;
            o_wb_we       <= 1'b0;
            o_wb_adr      <= {WB_ADDR_W{1'b0}};
            o_wb_dat      <= {WB_DATA_W{1'b0}};
            o_busy        <= 1'b0;
            o_last_ack    <= 1'b0;
            o_last_err    <= 1'b0;
            o_addr        <= {WB_ADDR_W{1'b0}};
            o_data        <= {WB_DATA_W{1'b0}};
            o_rd_data     <= {WB_DATA_W{1'b0}};
            o_halt_others <= 1'b0;
        end else begin
            // Idle-time scratch updates from host commands.
            if (state == S_IDLE) begin
                if (cmd_set_addr) o_addr        <= i_cmd_word[WB_ADDR_W-1:0];
                if (cmd_set_dlo)  o_data[15:0]  <= i_cmd_word[15:0];
                if (cmd_set_dhi)  o_data[31:16] <= i_cmd_word[15:0];
                if (cmd_halt)     o_halt_others <= 1'b1;
                if (cmd_resume)   o_halt_others <= 1'b0;
            end

            case (state)
                S_IDLE: begin
                    o_wb_cyc <= 1'b0;
                    o_wb_stb <= 1'b0;
                    o_busy   <= 1'b0;
                    if (cmd_go_wr || cmd_go_rd) begin
                        o_wb_cyc   <= 1'b1;
                        o_wb_stb   <= 1'b1;
                        o_wb_we    <= cmd_go_wr;
                        o_wb_adr   <= o_addr;
                        o_wb_dat   <= o_data;
                        o_busy     <= 1'b1;
                        o_last_ack <= 1'b0;
                        o_last_err <= 1'b0;
                        state      <= S_WB_STB;
                    end
                end

                S_WB_STB: begin
                    // Hold stb until slave deasserts stall, then drop stb.
                    if (!i_wb_stall) begin
                        o_wb_stb <= 1'b0;
                        state    <= S_WB_WAIT;
                    end
                    // Ack can race the stb-drop on single-cycle slaves.
                    if (i_wb_ack) begin
                        o_wb_cyc   <= 1'b0;
                        o_wb_stb   <= 1'b0;
                        o_last_ack <= 1'b1;
                        o_last_err <= i_wb_err;
                        if (!o_wb_we) o_rd_data <= i_wb_dat;
                        o_busy     <= 1'b0;
                        state      <= S_IDLE;
                    end
                end

                S_WB_WAIT: begin
                    if (i_wb_ack) begin
                        o_wb_cyc   <= 1'b0;
                        o_last_ack <= 1'b1;
                        o_last_err <= i_wb_err;
                        if (!o_wb_we) o_rd_data <= i_wb_dat;
                        o_busy     <= 1'b0;
                        state      <= S_IDLE;
                    end
                end

                default: state <= S_IDLE;
            endcase
        end
    end

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, i_cmd_word[23:WB_ADDR_W], 1'b0};
    /* verilator lint_on UNUSED */
endmodule

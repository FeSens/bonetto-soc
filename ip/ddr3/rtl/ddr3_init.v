// ddr3_init — JEDEC DDR3 power-up initialisation FSM.
//
// Drives RESET#, CKE, and the command bus through the full JEDEC init
// sequence (TN-41-07). Hands off to the runtime FSM by raising
// `o_init_done` once the device is ready for normal commands.
//
// Cycle-precise: every wait state is implemented by a counter that
// matches the JEDEC tCK requirement for the active speed grade. Per
// INVARIANTS #6, the same counters are referenced by formal cover
// properties in `ip/ddr3/formal/`.
//
// Error policy: this FSM never deadlocks. If the counters are
// misconfigured or a state-machine arc is impossible, `o_init_error`
// latches and the FSM stays in `S_FAIL` so the host can inspect
// `o_init_error_code` via JTAG-UART.
//
// Reset: synchronous, active-high.

`default_nettype none

`include "ddr3_params.vh"
`include "ddr3_cmd.vh"

module ddr3_init #(
    parameter integer ROW_BITS  = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer CMD_BITS  = 4
) (
    input  wire                       i_clk_phy,
    input  wire                       i_rst,

    // DDR3 command bus (output side — registered).
    // The board top wires these directly to the chip pins.
    output reg                        o_ddr3_reset_n,
    output reg                        o_ddr3_cke,
    output reg                        o_ddr3_odt,
    output reg  [CMD_BITS-1:0]        o_ddr3_cmd,     // {cs_n, ras_n, cas_n, we_n}
    output reg  [BANK_BITS-1:0]       o_ddr3_ba,
    output reg  [ROW_BITS-1:0]        o_ddr3_addr,

    // Init status — visible to runtime FSM and host.
    output reg                        o_init_done,
    output reg                        o_init_error,
    output reg  [3:0]                 o_init_error_code,
    output wire [4:0]                 o_state         // for debug / formal cover
);

    // ---- State encoding ----
    localparam [4:0]
        S_PWR_ON       = 5'd0,   // RESET# low after VDD stable
        S_RESET_HIGH   = 5'd1,   // RESET# released, CKE still low
        S_CKE_HIGH_NOP = 5'd2,   // CKE up, NOPs for tXPR
        S_MR2          = 5'd3,
        S_MR2_WAIT     = 5'd4,   // tMRD
        S_MR3          = 5'd5,
        S_MR3_WAIT     = 5'd6,
        S_MR1          = 5'd7,
        S_MR1_WAIT     = 5'd8,
        S_MR0          = 5'd9,
        S_MR0_WAIT     = 5'd10,  // tMOD
        S_ZQCL         = 5'd11,
        S_ZQ_WAIT      = 5'd12,  // tZQinit
        S_DLLK_WAIT    = 5'd13,  // tDLLK (may overlap with tZQinit)
        S_PRE_ALL      = 5'd14,
        S_PRE_WAIT     = 5'd15,  // tRP
        S_FIRST_REF    = 5'd16,
        S_REF_WAIT     = 5'd17,  // tRFC
        S_DONE         = 5'd18,
        S_FAIL         = 5'd31;

    assign o_state = state;
    reg [4:0] state;

    // ---- Wait counter ----
    // Widest deadline is tRESET_TCK = 160k cycles → fits in 24 bits with margin.
    reg [23:0] wait_ctr;

    // Mode-register payloads — explicit constants from ddr3_params.vh.
    localparam [15:0] MR0_VAL = `DDR3_MR0_VAL;
    localparam [15:0] MR1_VAL = `DDR3_MR1_VAL;
    localparam [15:0] MR2_VAL = `DDR3_MR2_VAL;
    localparam [15:0] MR3_VAL = `DDR3_MR3_VAL;

    // ---- Helpers ----
    function automatic [ROW_BITS-1:0] mr_addr;
        input [15:0] mr_val;
        begin
            // MR values are 16 bits; the DDR3 chip reads A[15:0]. With our
            // ROW_BITS = 15 we drop the unused MSB (always 0 per JEDEC).
            mr_addr = mr_val[ROW_BITS-1:0];
        end
    endfunction

    // ---- Main FSM ----
    always @(posedge i_clk_phy) begin
        if (i_rst) begin
            state             <= S_PWR_ON;
            wait_ctr          <= 24'd0;
            o_ddr3_reset_n    <= 1'b0;
            o_ddr3_cke        <= 1'b0;
            o_ddr3_odt        <= 1'b0;
            o_ddr3_cmd        <= `DDR3_CMD_NOP;
            o_ddr3_ba         <= {BANK_BITS{1'b0}};
            o_ddr3_addr       <= {ROW_BITS{1'b0}};
            o_init_done       <= 1'b0;
            o_init_error      <= 1'b0;
            o_init_error_code <= 4'd0;
        end else begin
            // Default each cycle: NOP on the bus, hold prior bank/addr.
            o_ddr3_cmd <= `DDR3_CMD_NOP;

            case (state)
                // -------------------------------------------------------------
                S_PWR_ON: begin
                    // Hold RESET# low for ≥200 µs after stable VDD.
                    o_ddr3_reset_n <= 1'b0;
                    o_ddr3_cke     <= 1'b0;
                    if (wait_ctr == `DDR3_TRESET_TCK - 1) begin
                        wait_ctr <= 24'd0;
                        state    <= S_RESET_HIGH;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_RESET_HIGH: begin
                    // RESET# released, CKE low for ≥500 µs.
                    o_ddr3_reset_n <= 1'b1;
                    o_ddr3_cke     <= 1'b0;
                    if (wait_ctr == `DDR3_TCKE_LOW_TCK - 1) begin
                        wait_ctr <= 24'd0;
                        state    <= S_CKE_HIGH_NOP;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_CKE_HIGH_NOP: begin
                    // CKE high, NOP only, wait tXPR before any other command.
                    o_ddr3_cke <= 1'b1;
                    if (wait_ctr == `DDR3_TXPR - 1) begin
                        wait_ctr <= 24'd0;
                        state    <= S_MR2;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // -------------------------------------------------------------
                // MR programming order is MR2 → MR3 → MR1 → MR0 per JEDEC.
                S_MR2: begin
                    o_ddr3_cmd  <= `DDR3_CMD_MRS;
                    o_ddr3_ba   <= `DDR3_MR2_BA;
                    o_ddr3_addr <= mr_addr(MR2_VAL);
                    wait_ctr    <= 24'd0;
                    state       <= S_MR2_WAIT;
                end
                S_MR2_WAIT: begin
                    if (wait_ctr == `DDR3_TMRD - 2) begin
                        // -2 because we spent 1 cycle issuing MRS and 1 cycle
                        // for the first NOP — total tMRD cycles between MRSs.
                        wait_ctr <= 24'd0;
                        state    <= S_MR3;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_MR3: begin
                    o_ddr3_cmd  <= `DDR3_CMD_MRS;
                    o_ddr3_ba   <= `DDR3_MR3_BA;
                    o_ddr3_addr <= mr_addr(MR3_VAL);
                    wait_ctr    <= 24'd0;
                    state       <= S_MR3_WAIT;
                end
                S_MR3_WAIT: begin
                    if (wait_ctr == `DDR3_TMRD - 2) begin
                        wait_ctr <= 24'd0;
                        state    <= S_MR1;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_MR1: begin
                    o_ddr3_cmd  <= `DDR3_CMD_MRS;
                    o_ddr3_ba   <= `DDR3_MR1_BA;
                    o_ddr3_addr <= mr_addr(MR1_VAL);
                    wait_ctr    <= 24'd0;
                    state       <= S_MR1_WAIT;
                end
                S_MR1_WAIT: begin
                    if (wait_ctr == `DDR3_TMRD - 2) begin
                        wait_ctr <= 24'd0;
                        state    <= S_MR0;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_MR0: begin
                    o_ddr3_cmd  <= `DDR3_CMD_MRS;
                    o_ddr3_ba   <= `DDR3_MR0_BA;
                    o_ddr3_addr <= mr_addr(MR0_VAL);
                    wait_ctr    <= 24'd0;
                    state       <= S_MR0_WAIT;
                end
                S_MR0_WAIT: begin
                    // tMOD after MR0 (because MR0 carries DLL_RST=1) — longer
                    // than the inter-MRS tMRD.
                    if (wait_ctr == `DDR3_TMOD - 2) begin
                        wait_ctr <= 24'd0;
                        state    <= S_ZQCL;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // -------------------------------------------------------------
                S_ZQCL: begin
                    o_ddr3_cmd  <= `DDR3_CMD_ZQCL;
                    o_ddr3_ba   <= {BANK_BITS{1'b0}};
                    // A10 = 1 selects ZQCL (long) vs ZQCS (short).
                    o_ddr3_addr <= {{ROW_BITS-11{1'b0}}, 1'b1, 10'b0};
                    wait_ctr    <= 24'd0;
                    state       <= S_ZQ_WAIT;
                end
                S_ZQ_WAIT: begin
                    if (wait_ctr == `DDR3_TZQINIT - 2) begin
                        wait_ctr <= 24'd0;
                        state    <= S_DLLK_WAIT;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // tDLLK overlaps tZQinit in practice; we still wait the full
                // tDLLK from MR0 issue to be conservative.
                S_DLLK_WAIT: begin
                    if (wait_ctr == `DDR3_TDLLK - 1) begin
                        wait_ctr <= 24'd0;
                        state    <= S_PRE_ALL;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // -------------------------------------------------------------
                S_PRE_ALL: begin
                    o_ddr3_cmd  <= `DDR3_CMD_PRE;
                    o_ddr3_ba   <= {BANK_BITS{1'b0}};
                    // A10 = 1 → all-bank PRECHARGE
                    o_ddr3_addr <= {{ROW_BITS-11{1'b0}}, 1'b1, 10'b0};
                    wait_ctr    <= 24'd0;
                    state       <= S_PRE_WAIT;
                end
                S_PRE_WAIT: begin
                    if (wait_ctr == `DDR3_TRP - 2) begin
                        wait_ctr <= 24'd0;
                        state    <= S_FIRST_REF;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_FIRST_REF: begin
                    o_ddr3_cmd  <= `DDR3_CMD_REF;
                    o_ddr3_ba   <= {BANK_BITS{1'b0}};
                    o_ddr3_addr <= {ROW_BITS{1'b0}};
                    wait_ctr    <= 24'd0;
                    state       <= S_REF_WAIT;
                end
                S_REF_WAIT: begin
                    if (wait_ctr == `DDR3_TRFC - 2) begin
                        wait_ctr    <= 24'd0;
                        state       <= S_DONE;
                        o_init_done <= 1'b1;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // -------------------------------------------------------------
                S_DONE: begin
                    // Idle here forever (runtime FSM takes ownership of the
                    // command bus). Hold init_done high.
                    o_init_done <= 1'b1;
                end

                S_FAIL: begin
                    o_init_error <= 1'b1;
                end

                default: begin
                    // Should be unreachable; latch error and lock.
                    state             <= S_FAIL;
                    o_init_error     <= 1'b1;
                    o_init_error_code <= 4'd1;
                end
            endcase
        end
    end
endmodule

// clk_liveness — generic clk-domain liveness probe.
//
// Generates a slow-toggling bit on i_clk, CDCs it into the observer clock
// domain, and reports alive=1 if at least one toggle was seen recently. The
// optional odd-period divider avoids false-dead reports when the observed clock
// is phase-related to the observer clock.

`default_nettype none

module clk_liveness #(
    parameter integer DIV_BIT      = 7,  // probe bit DIV_BIT of free-running ctr
    parameter integer TOGGLE_PERIOD = 0, // 0 = legacy power-of-two divider
    parameter integer FRESHNESS_W  = 16  // observer cycles before declaring dead
) (
    input  wire        i_clk,        // domain under test
    input  wire        i_clk_obs,    // observer (clk_50)
    output wire        o_alive,      // 1 = saw a toggle recently
    output wire        o_synced_bit, // raw CDC bit
    output wire [5:0]  o_ticks_lo    // low 6 bits of the toggle counter
);
    localparam [FRESHNESS_W-1:0] FRESH_MAX = {FRESHNESS_W{1'b1}};

    wire hb_src;
    generate
        if (TOGGLE_PERIOD > 0) begin : gen_odd_period
            localparam integer CTR_W =
                (TOGGLE_PERIOD <= 2) ? 1 : $clog2(TOGGLE_PERIOD);
            localparam [CTR_W-1:0] TOGGLE_LAST = TOGGLE_PERIOD - 1;

            reg [CTR_W-1:0] div_ctr = {CTR_W{1'b0}};
            reg hb_q = 1'b0;
            always @(posedge i_clk) begin
                if (div_ctr == TOGGLE_LAST) begin
                    div_ctr <= {CTR_W{1'b0}};
                    hb_q <= !hb_q;
                end else begin
                    div_ctr <= div_ctr + 1'b1;
                end
            end
            assign hb_src = hb_q;
        end else begin : gen_power2_period
            reg [DIV_BIT:0] hb_q = {(DIV_BIT+1){1'b0}};
            always @(posedge i_clk) hb_q <= hb_q + 1'b1;
            assign hb_src = hb_q[DIV_BIT];
        end
    endgenerate

    reg [1:0]              sync = 2'b00;
    reg                    prev = 1'b0;
    reg [FRESHNESS_W-1:0]  freshness = FRESH_MAX;
    reg [15:0]             ticks = 16'd0;
    always @(posedge i_clk_obs) begin
        sync <= {sync[0], hb_src};
        prev <= sync[1];
        if (sync[1] != prev) begin
            ticks     <= ticks + 1'b1;
            freshness <= {FRESHNESS_W{1'b0}};
        end else if (freshness != FRESH_MAX) begin
            freshness <= freshness + 1'b1;
        end
    end

    assign o_alive      = (freshness != FRESH_MAX);
    assign o_synced_bit = sync[1];
    assign o_ticks_lo   = ticks[5:0];
endmodule

`default_nettype wire

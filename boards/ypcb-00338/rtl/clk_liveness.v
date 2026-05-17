// clk_liveness — generic clk-domain liveness probe.
//
// Generates a slow-toggling bit on i_clk, CDCs it into the observer
// clk_50 domain, and reports alive=1 if at least one toggle was seen
// in the last ~1.3 ms. Used by top.v to detect the prjxray-db kintex7
// segbit gap symptom (MMCM locks but a specific CLKOUT routing is
// silently dropped).

`default_nettype none

module clk_liveness #(
    parameter integer DIV_BIT = 7  // probe bit DIV_BIT of a free-running ctr
) (
    input  wire        i_clk,        // domain under test
    input  wire        i_clk_obs,    // observer (clk_50)
    output wire        o_alive,      // 1 = saw a toggle recently
    output wire        o_synced_bit, // raw CDC bit
    output wire [5:0]  o_ticks_lo    // low 6 bits of the toggle counter
);
    reg [DIV_BIT:0] hb_q = {(DIV_BIT+1){1'b0}};
    always @(posedge i_clk) hb_q <= hb_q + 1'b1;

    reg [1:0]  sync = 2'b00;
    reg        prev = 1'b0;
    reg [15:0] freshness = 16'hFFFF;
    reg [15:0] ticks = 16'd0;
    always @(posedge i_clk_obs) begin
        sync <= {sync[0], hb_q[DIV_BIT]};
        prev <= sync[1];
        if (sync[1] != prev) begin
            ticks     <= ticks + 1'b1;
            freshness <= 16'd0;
        end else if (freshness != 16'hFFFF) begin
            freshness <= freshness + 1'b1;
        end
    end

    assign o_alive      = (freshness != 16'hFFFF);
    assign o_synced_bit = sync[1];
    assign o_ticks_lo   = ticks[5:0];
endmodule

`default_nettype wire

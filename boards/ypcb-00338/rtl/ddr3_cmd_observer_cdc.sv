// Low-rate observer for the DDR3 command stream after it reaches the
// board-facing command clock domain.
//
// This is a debug/status block, not part of the DDR3 protocol datapath.  It
// lets the JTAG status mux answer a specific bring-up question: did MRS/RD
// commands actually cross into the clk_dq pin domain with the expected command,
// bank, and address fields?

`default_nettype none

`include "ddr3_params.vh"

module ddr3_cmd_observer_cdc #(
    parameter integer CHANNELS = 2,
    parameter integer ADDR_BITS = `DDR3_ADDR_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer COUNT_W = 8
) (
    input  wire                         i_clk_dq,
    input  wire                         i_rst_dq,
    input  wire [CHANNELS-1:0]          i_reset_n,
    input  wire [CHANNELS-1:0]          i_cke,
    input  wire [CHANNELS-1:0]          i_odt,
    input  wire [CHANNELS-1:0]          i_cmd_valid,
    input  wire [CHANNELS-1:0]          i_cs_n,
    input  wire [CHANNELS-1:0]          i_ras_n,
    input  wire [CHANNELS-1:0]          i_cas_n,
    input  wire [CHANNELS-1:0]          i_we_n,
    input  wire [CHANNELS*BANK_BITS-1:0] i_ba,
    input  wire [CHANNELS*ADDR_BITS-1:0] i_addr,

    input  wire                         i_clk_ctrl,
    input  wire                         i_rst_ctrl,
    output reg  [CHANNELS-1:0]          o_reset_n,
    output reg  [CHANNELS-1:0]          o_cke,
    output reg  [CHANNELS-1:0]          o_odt,
    output reg  [CHANNELS*4-1:0]        o_last_cmd,
    output reg  [CHANNELS*BANK_BITS-1:0] o_last_ba,
    output reg  [CHANNELS*ADDR_BITS-1:0] o_last_addr,
    output reg  [CHANNELS*BANK_BITS-1:0] o_last_mrs_ba,
    output reg  [CHANNELS*ADDR_BITS-1:0] o_last_mrs_addr,
    output reg  [CHANNELS*BANK_BITS-1:0] o_last_rd_ba,
    output reg  [CHANNELS*ADDR_BITS-1:0] o_last_rd_addr,
    output reg  [CHANNELS*COUNT_W-1:0]  o_cmd_count,
    output reg  [CHANNELS*COUNT_W-1:0]  o_mrs_count,
    output reg  [CHANNELS*COUNT_W-1:0]  o_rd_count
);
    reg [CHANNELS-1:0] reset_n_dq = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] cke_dq = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] odt_dq = {CHANNELS{1'b0}};
    reg [CHANNELS*4-1:0] last_cmd_dq = {CHANNELS{`DDR3_CMD_DES}};
    reg [CHANNELS*BANK_BITS-1:0] last_ba_dq =
        {(CHANNELS*BANK_BITS){1'b0}};
    reg [CHANNELS*ADDR_BITS-1:0] last_addr_dq =
        {(CHANNELS*ADDR_BITS){1'b0}};
    reg [CHANNELS*BANK_BITS-1:0] last_mrs_ba_dq =
        {(CHANNELS*BANK_BITS){1'b0}};
    reg [CHANNELS*ADDR_BITS-1:0] last_mrs_addr_dq =
        {(CHANNELS*ADDR_BITS){1'b0}};
    reg [CHANNELS*BANK_BITS-1:0] last_rd_ba_dq =
        {(CHANNELS*BANK_BITS){1'b0}};
    reg [CHANNELS*ADDR_BITS-1:0] last_rd_addr_dq =
        {(CHANNELS*ADDR_BITS){1'b0}};
    reg [CHANNELS*COUNT_W-1:0] cmd_count_dq =
        {(CHANNELS*COUNT_W){1'b0}};
    reg [CHANNELS*COUNT_W-1:0] mrs_count_dq =
        {(CHANNELS*COUNT_W){1'b0}};
    reg [CHANNELS*COUNT_W-1:0] rd_count_dq =
        {(CHANNELS*COUNT_W){1'b0}};

    integer dq_ch;
    reg [3:0] cmd_code;
    always @(posedge i_clk_dq) begin
        if (i_rst_dq) begin
            reset_n_dq <= {CHANNELS{1'b0}};
            cke_dq <= {CHANNELS{1'b0}};
            odt_dq <= {CHANNELS{1'b0}};
            last_cmd_dq <= {CHANNELS{`DDR3_CMD_DES}};
            last_ba_dq <= {(CHANNELS*BANK_BITS){1'b0}};
            last_addr_dq <= {(CHANNELS*ADDR_BITS){1'b0}};
            last_mrs_ba_dq <= {(CHANNELS*BANK_BITS){1'b0}};
            last_mrs_addr_dq <= {(CHANNELS*ADDR_BITS){1'b0}};
            last_rd_ba_dq <= {(CHANNELS*BANK_BITS){1'b0}};
            last_rd_addr_dq <= {(CHANNELS*ADDR_BITS){1'b0}};
            cmd_count_dq <= {(CHANNELS*COUNT_W){1'b0}};
            mrs_count_dq <= {(CHANNELS*COUNT_W){1'b0}};
            rd_count_dq <= {(CHANNELS*COUNT_W){1'b0}};
        end else begin
            reset_n_dq <= i_reset_n;
            cke_dq <= i_cke;
            odt_dq <= i_odt;

            for (dq_ch = 0; dq_ch < CHANNELS; dq_ch = dq_ch + 1) begin
                if (i_cmd_valid[dq_ch]) begin
                    cmd_code = {
                        i_cs_n[dq_ch],
                        i_ras_n[dq_ch],
                        i_cas_n[dq_ch],
                        i_we_n[dq_ch]
                    };
                    last_cmd_dq[dq_ch*4 +: 4] <= cmd_code;
                    last_ba_dq[dq_ch*BANK_BITS +: BANK_BITS] <=
                        i_ba[dq_ch*BANK_BITS +: BANK_BITS];
                    last_addr_dq[dq_ch*ADDR_BITS +: ADDR_BITS] <=
                        i_addr[dq_ch*ADDR_BITS +: ADDR_BITS];
                    cmd_count_dq[dq_ch*COUNT_W +: COUNT_W] <=
                        cmd_count_dq[dq_ch*COUNT_W +: COUNT_W] + 1'b1;
                    if (cmd_code == `DDR3_CMD_MRS) begin
                        last_mrs_ba_dq[dq_ch*BANK_BITS +: BANK_BITS] <=
                            i_ba[dq_ch*BANK_BITS +: BANK_BITS];
                        last_mrs_addr_dq[dq_ch*ADDR_BITS +: ADDR_BITS] <=
                            i_addr[dq_ch*ADDR_BITS +: ADDR_BITS];
                        mrs_count_dq[dq_ch*COUNT_W +: COUNT_W] <=
                            mrs_count_dq[dq_ch*COUNT_W +: COUNT_W] + 1'b1;
                    end
                    if (cmd_code == `DDR3_CMD_RD) begin
                        last_rd_ba_dq[dq_ch*BANK_BITS +: BANK_BITS] <=
                            i_ba[dq_ch*BANK_BITS +: BANK_BITS];
                        last_rd_addr_dq[dq_ch*ADDR_BITS +: ADDR_BITS] <=
                            i_addr[dq_ch*ADDR_BITS +: ADDR_BITS];
                        rd_count_dq[dq_ch*COUNT_W +: COUNT_W] <=
                            rd_count_dq[dq_ch*COUNT_W +: COUNT_W] + 1'b1;
                    end
                end
            end
        end
    end

    (* ASYNC_REG = "TRUE" *) reg [CHANNELS-1:0] reset_n_ctrl_0 =
        {CHANNELS{1'b0}};
    (* ASYNC_REG = "TRUE" *) reg [CHANNELS-1:0] reset_n_ctrl_1 =
        {CHANNELS{1'b0}};
    (* ASYNC_REG = "TRUE" *) reg [CHANNELS-1:0] cke_ctrl_0 =
        {CHANNELS{1'b0}};
    (* ASYNC_REG = "TRUE" *) reg [CHANNELS-1:0] cke_ctrl_1 =
        {CHANNELS{1'b0}};
    (* ASYNC_REG = "TRUE" *) reg [CHANNELS-1:0] odt_ctrl_0 =
        {CHANNELS{1'b0}};
    (* ASYNC_REG = "TRUE" *) reg [CHANNELS-1:0] odt_ctrl_1 =
        {CHANNELS{1'b0}};

    always @(posedge i_clk_ctrl) begin
        if (i_rst_ctrl) begin
            reset_n_ctrl_0 <= {CHANNELS{1'b0}};
            reset_n_ctrl_1 <= {CHANNELS{1'b0}};
            cke_ctrl_0 <= {CHANNELS{1'b0}};
            cke_ctrl_1 <= {CHANNELS{1'b0}};
            odt_ctrl_0 <= {CHANNELS{1'b0}};
            odt_ctrl_1 <= {CHANNELS{1'b0}};
            o_reset_n <= {CHANNELS{1'b0}};
            o_cke <= {CHANNELS{1'b0}};
            o_odt <= {CHANNELS{1'b0}};
            o_last_cmd <= {CHANNELS{`DDR3_CMD_DES}};
            o_last_ba <= {(CHANNELS*BANK_BITS){1'b0}};
            o_last_addr <= {(CHANNELS*ADDR_BITS){1'b0}};
            o_last_mrs_ba <= {(CHANNELS*BANK_BITS){1'b0}};
            o_last_mrs_addr <= {(CHANNELS*ADDR_BITS){1'b0}};
            o_last_rd_ba <= {(CHANNELS*BANK_BITS){1'b0}};
            o_last_rd_addr <= {(CHANNELS*ADDR_BITS){1'b0}};
            o_cmd_count <= {(CHANNELS*COUNT_W){1'b0}};
            o_mrs_count <= {(CHANNELS*COUNT_W){1'b0}};
            o_rd_count <= {(CHANNELS*COUNT_W){1'b0}};
        end else begin
            reset_n_ctrl_0 <= reset_n_dq;
            reset_n_ctrl_1 <= reset_n_ctrl_0;
            cke_ctrl_0 <= cke_dq;
            cke_ctrl_1 <= cke_ctrl_0;
            odt_ctrl_0 <= odt_dq;
            odt_ctrl_1 <= odt_ctrl_0;
            o_reset_n <= reset_n_ctrl_1;
            o_cke <= cke_ctrl_1;
            o_odt <= odt_ctrl_1;

            // The command payloads and counters are sampled for low-rate JTAG
            // diagnostics after the command stream has gone idle.  The source
            // values are held until the next DQ-domain command event.
            o_last_cmd <= last_cmd_dq;
            o_last_ba <= last_ba_dq;
            o_last_addr <= last_addr_dq;
            o_last_mrs_ba <= last_mrs_ba_dq;
            o_last_mrs_addr <= last_mrs_addr_dq;
            o_last_rd_ba <= last_rd_ba_dq;
            o_last_rd_addr <= last_rd_addr_dq;
            o_cmd_count <= cmd_count_dq;
            o_mrs_count <= mrs_count_dq;
            o_rd_count <= rd_count_dq;
        end
    end
endmodule

`default_nettype wire

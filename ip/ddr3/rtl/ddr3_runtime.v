// ddr3_runtime — DDR3 runtime read/write FSM (post-init).
//
// Current runtime: ACT -> RD/WR -> PRE per transaction (no row caching),
// single-bank-at-a-time, hard-coded burst length 8. Refresh scheduler
// interleaved.
//
// Iter-3 refinements (TODO, marked in code):
//   * Per-bank state tracking with row caching (avoid ACT/PRE on the
//     same row twice).
//   * Command queue with bank-interleaved arbitration.
//   * Wide WB burst buffering to use every word in each BL8 transaction.
//   * Auto-precharge variant (A10=1 on RD/WR) to skip the explicit PRE.
//
// State machine (single-bank simple variant):
//
//   IDLE ──[wb_stb, !pending_ref]──▶ ACT
//   ACT  ─────[1 cycle]────────────▶ WAIT_RCD
//   WAIT_RCD ──[tRCD elapsed]──────▶ CMD (RD or WR)
//   CMD ─────[1 cycle]─────────────▶ WAIT_CL  (read) or WAIT_CWL (write)
//   WAIT_CL ─[tCL elapsed]─────────▶ DATA_RD (CL cycles → first beat)
//   WAIT_CWL──[tCWL elapsed]──────▶ DATA_WR
//   DATA_RD ─[8 beats]─────────────▶ PRE
//   DATA_WR ─[8 beats]─────────────▶ PRE
//   PRE  ─[tRP elapsed]────────────▶ IDLE
//
// Refresh:
//   While IDLE, if (cycles_since_ref > tREFI), insert PRE_ALL → tRP →
//   REF → tRFC → IDLE before accepting new WB requests.

`default_nettype none

`include "ddr3_params.vh"
`include "ddr3_cmd.vh"

module ddr3_runtime #(
    parameter integer WB_DATA_W = 32,
    parameter integer WB_ADDR_W = 28,
    parameter integer ROW_BITS  = `DDR3_ROW_BITS,
    parameter integer BANK_BITS = `DDR3_BANK_BITS,
    parameter integer COL_BITS  = `DDR3_COL_BITS,
    parameter integer DQ_BITS   = 8,
    parameter integer NUM_BYTE_LANES = 9,
    parameter integer SERDES_RATIO   = 4,
    parameter integer WB_BURST_WORD_BITS = 0
) (
    input  wire                       i_clk_phy,
    input  wire                       i_rst,
    input  wire                       i_init_done,

    // -------- Wishbone B4 pipelined slave (from ddr3_ctrl front-end) --------
    input  wire                       i_wb_cyc,
    input  wire                       i_wb_stb,
    input  wire                       i_wb_we,
    input  wire [WB_ADDR_W-1:0]       i_wb_adr,
    input  wire [WB_DATA_W-1:0]       i_wb_dat,
    input  wire [WB_DATA_W/8-1:0]     i_wb_sel,
    output wire                       o_wb_stall,
    output reg                        o_wb_ack,
    output reg  [WB_DATA_W-1:0]       o_wb_dat,
    output wire                       o_wb_err,

    // -------- DDR3 command outputs (when active) --------
    output reg                        o_cmd_valid,    // 1 = drive cmd this cycle
    output reg  [3:0]                 o_cmd,          // {cs_n, ras_n, cas_n, we_n}
    output reg  [BANK_BITS-1:0]       o_cmd_ba,
    output reg  [ROW_BITS-1:0]        o_cmd_addr,
    output wire                       o_cmd_odt,

    // -------- DDR3 PHY data side --------
    input  wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] i_rd_data,
    input  wire                       i_rd_valid,
    output wire [NUM_BYTE_LANES*DQ_BITS*SERDES_RATIO-1:0] o_wr_data,
    output reg                        o_wr_valid,
    output wire                       o_rd_capture,

    // -------- MPR-read request port (iter-3c, for read-leveling) --------
    // When `i_mpr_req` pulses, the FSM emits an RD command with
    // address bits driven from `i_mpr_addr` (A[12]=1, A[2:0]=000 for
    // MPR location 0). No ACT precedes, no PRE follows — MPR data is
    // internal to the DDR3 chip, not in a row. The chip must already
    // be in MR3[2]=1 mode (programmed via the init FSM's MR3-rewrite
    // pass after standard init completes).
    input  wire                       i_mpr_req,
    input  wire [12:0]                i_mpr_addr,
    output wire                       o_mpr_busy,

    // -------- MRS-rewrite request port (iter-8, for cal_seq) --------
    // Lets cal_seq toggle MR1[7] (wlvl enable) or MR3[2] (MPR enable)
    // mid-calibration. The runtime FSM emits a single MRS command with
    // the supplied bank/addr and then waits tMOD before resuming WB
    // traffic. Priority: refresh > MRS > MPR > WB.
    input  wire                       i_mrs_req,
    input  wire [BANK_BITS-1:0]       i_mrs_ba,
    input  wire [ROW_BITS-1:0]        i_mrs_addr,
    output wire                       o_mrs_busy
);
    localparam integer WB_BYTES = WB_DATA_W / 8;
    localparam integer PHY_DATA_W = NUM_BYTE_LANES * DQ_BITS * SERDES_RATIO;
    localparam integer BURST_ADDR_W = BANK_BITS + ROW_BITS + (COL_BITS - 3);
    localparam integer WB_BURST_LOCAL_W = BURST_ADDR_W + WB_BURST_WORD_BITS;
    localparam integer WB_BURST_WORD_W = (WB_BURST_WORD_BITS > 0) ? WB_BURST_WORD_BITS : 1;
    localparam integer USE_BURST_WORD_OFFSET = (WB_BURST_WORD_BITS > 0);
    localparam integer USE_FAST_BURST_WORD =
        (WB_BURST_WORD_BITS == 4) && (NUM_BYTE_LANES == 8) &&
        (SERDES_RATIO == 8) && (WB_DATA_W == 32) && (DQ_BITS == 8);

    // ---- WB address split ----
    // Default validated CH0 mode consumes one WB word per BL8 command:
    //   adr = { bank, row, col[COL_BITS-1:3] }
    //
    // Full-width ports can set WB_BURST_WORD_BITS to strip low word-offset
    // bits before the DRAM address split. For a 64-bit channel exposed through
    // a 32-bit WB port, one BL8 burst holds 16 WB words, so the channel-local
    // address is {bank,row,col[COL_BITS-1:3],word_offset[3:0]}.
    // The data path still needs a real BL8 burst buffer/RMW before enabling
    // that mode in hardware.
    wire [BURST_ADDR_W-1:0] wb_burst_adr;
    wire [WB_BURST_WORD_W-1:0] wb_burst_word_offset;
    wire [WB_BURST_LOCAL_W-1:0] wb_burst_local_adr;
    generate
        if (WB_ADDR_W >= WB_BURST_LOCAL_W) begin : g_wb_addr_truncate
            assign wb_burst_local_adr = i_wb_adr[WB_BURST_LOCAL_W-1:0];
        end else begin : g_wb_addr_pad
            assign wb_burst_local_adr = {{(WB_BURST_LOCAL_W-WB_ADDR_W){1'b0}}, i_wb_adr};
        end

        if (WB_BURST_WORD_BITS > 0) begin : g_wb_burst_word_offset
            assign wb_burst_adr = wb_burst_local_adr[WB_BURST_WORD_BITS +: BURST_ADDR_W];
            assign wb_burst_word_offset = wb_burst_local_adr[WB_BURST_WORD_BITS-1:0];
        end else begin : g_wb_burst_word_none
            assign wb_burst_adr = wb_burst_local_adr[BURST_ADDR_W-1:0];
            assign wb_burst_word_offset = 1'b0;
        end
    endgenerate

    wire [BANK_BITS-1:0]        wb_bank = wb_burst_adr[BANK_BITS + ROW_BITS + (COL_BITS-3) - 1 -: BANK_BITS];
    wire [ROW_BITS-1:0]         wb_row  = wb_burst_adr[ROW_BITS + (COL_BITS-3) - 1            -: ROW_BITS];
    wire [COL_BITS-1:0]         wb_col  = { wb_burst_adr[(COL_BITS-3)-1:0], 3'b000 };

    localparam integer CK_PER_SYS = `DDR3_CK_PER_SYS;
    function integer tck_to_sys;
        input integer tck_cycles;
        begin
            tck_to_sys = (tck_cycles + CK_PER_SYS - 1) / CK_PER_SYS;
            if (tck_to_sys < 1) tck_to_sys = 1;
        end
    endfunction
    function integer wait_limit;
        input integer sys_cycles;
        begin
            wait_limit = (sys_cycles > 1) ? (sys_cycles - 2) : 0;
        end
    endfunction

    localparam integer CL_SYS  = tck_to_sys(`DDR3_CL);
    localparam integer CWL_SYS = tck_to_sys(`DDR3_CWL);
    localparam integer BURST_SYS_CYCLES = tck_to_sys(`DDR3_BL / 2);
    localparam integer CWL_START_WAIT = (CWL_SYS > 2) ? (CWL_SYS - 3) : 0;
    localparam integer READ_CAPTURE_SYS_CYCLES = BURST_SYS_CYCLES + 6;
    localparam integer READ_SETTLE_SYS_CYCLES = 4;
    localparam integer TREFI_SYS = tck_to_sys(`DDR3_TREFI);
    localparam integer TRCD_WAIT = wait_limit(tck_to_sys(`DDR3_TRCD));
    localparam integer TRP_WAIT  = wait_limit(tck_to_sys(`DDR3_TRP));
    localparam integer TRFC_WAIT = wait_limit(tck_to_sys(`DDR3_TRFC));
    localparam integer TCCD_WAIT = wait_limit(tck_to_sys(`DDR3_TCCD));
    localparam integer TMOD_WAIT = wait_limit(tck_to_sys(`DDR3_TMOD));
    localparam integer TWR_SYS   = tck_to_sys(`DDR3_TWR);

    // ---- Refresh scheduler ----
    // ref_pending is SET by the scheduler when tREFI elapses and
    // CLEARED by the main FSM when REF completes. Both updates live in
    // the same always block to avoid multiple-driver issues.
    reg [15:0] ref_ctr;
    reg        ref_pending;
    reg        ref_clear;                  // pulses from FSM at end of REF
    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            ref_ctr     <= 16'd0;
            ref_pending <= 1'b0;
        end else begin
            if (ref_ctr == TREFI_SYS - 1) begin
                ref_ctr     <= 16'd0;
                ref_pending <= 1'b1;
            end else begin
                ref_ctr <= ref_ctr + 1'b1;
            end
            if (ref_clear) ref_pending <= 1'b0;
        end
    end

    // ---- Runtime FSM ----
    localparam [4:0]
        S_IDLE      = 5'd0,
        S_ACT       = 5'd1,
        S_WAIT_RCD  = 5'd2,
        S_RD        = 5'd3,
        S_WR        = 5'd4,
        S_WAIT_CL   = 5'd5,
        S_WAIT_CWL  = 5'd6,
        S_DATA_RD   = 5'd7,
        S_DATA_WR   = 5'd8,
        S_PRE       = 5'd9,
        S_WAIT_RP   = 5'd10,
        S_REF_PRE   = 5'd11,
        S_REF_WAIT_RP = 5'd12,
        S_REF       = 5'd13,
        S_REF_WAIT  = 5'd14,
        S_MPR_RD    = 5'd15,
        S_MPR_WAIT  = 5'd16,
        S_MRS       = 5'd17,
        S_MRS_WAIT  = 5'd18,
        S_WR_RECOV  = 5'd19;

    // ---- MPR-request latch (single-shot; cleared on completion) ----
    reg        mpr_pending;
    reg [12:0] mpr_addr_q;
    reg        mpr_clear;     // pulses from FSM when MPR-RD command emitted

    reg [4:0]  state;

    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            mpr_pending <= 1'b0;
            mpr_addr_q  <= 13'd0;
        end else begin
            if (i_mpr_req) begin
                mpr_pending <= 1'b1;
                mpr_addr_q  <= i_mpr_addr;
            end
            if (mpr_clear) mpr_pending <= 1'b0;
        end
    end

    assign o_mpr_busy = mpr_pending || (state == S_MPR_RD) || (state == S_MPR_WAIT);

    // ---- MRS-rewrite latch (single-shot; cleared when FSM emits MRS) ----
    reg                       mrs_pending;
    reg [BANK_BITS-1:0]       mrs_ba_q;
    reg [ROW_BITS-1:0]        mrs_addr_q;
    reg                       mrs_clear;
    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            mrs_pending <= 1'b0;
            mrs_ba_q    <= {BANK_BITS{1'b0}};
            mrs_addr_q  <= {ROW_BITS{1'b0}};
        end else begin
            if (i_mrs_req) begin
                mrs_pending <= 1'b1;
                mrs_ba_q    <= i_mrs_ba;
                mrs_addr_q  <= i_mrs_addr;
            end
            if (mrs_clear) mrs_pending <= 1'b0;
        end
    end

    assign o_mrs_busy = mrs_pending || (state == S_MRS) || (state == S_MRS_WAIT);
    reg [7:0]  beat_ctr;                   // BL8 beat counter (0..7)
    reg [7:0]  wait_ctr;                   // generic wait counter
    reg [BANK_BITS-1:0]  saved_bank;
    reg [ROW_BITS-1:0]   saved_row;
    reg [COL_BITS-1:0]   saved_col;
    reg                  saved_we;
    reg [WB_DATA_W-1:0]  saved_wdat;
    reg [WB_BYTES-1:0]   saved_sel;
    reg [WB_BURST_WORD_W-1:0] saved_burst_word_offset;
    reg [15:0]           saved_burst_word_onehot;
    reg [PHY_DATA_W-1:0] rmw_wr_data;

    // Accept WB only in IDLE with no pending refresh.
    wire wb_accept_ok = i_init_done && (state == S_IDLE) && !ref_pending;
    assign o_wb_stall = ~wb_accept_ok;
    assign o_wb_err   = 1'b0;
    assign o_rd_capture = (state == S_DATA_RD) && (beat_ctr < READ_CAPTURE_SYS_CYCLES);
    assign o_cmd_odt = (state == S_WR) || (state == S_WAIT_CWL) ||
                       (state == S_DATA_WR) || (state == S_WR_RECOV);

    function [WB_DATA_W-1:0] burst_get_word;
        input [PHY_DATA_W-1:0] burst_data;
        input [WB_BURST_WORD_W-1:0] word_offset;
        integer byte_idx;
        integer bit_idx;
        integer burst_byte;
        integer lane_idx;
        integer sample_idx;
        begin
            burst_get_word = {WB_DATA_W{1'b0}};
            for (byte_idx = 0; byte_idx < WB_BYTES; byte_idx = byte_idx + 1) begin
                burst_byte = (word_offset * WB_BYTES) + byte_idx;
                lane_idx   = burst_byte % NUM_BYTE_LANES;
                sample_idx = burst_byte / NUM_BYTE_LANES;
                for (bit_idx = 0; bit_idx < 8; bit_idx = bit_idx + 1) begin
                    if (sample_idx < SERDES_RATIO) begin
                        burst_get_word[byte_idx*8 + bit_idx] =
                            burst_data[lane_idx*DQ_BITS*SERDES_RATIO +
                                       bit_idx*SERDES_RATIO +
                                       sample_idx];
                    end
                end
            end
        end
    endfunction

    function [PHY_DATA_W-1:0] burst_put_word;
        input [PHY_DATA_W-1:0] burst_data;
        input [WB_BURST_WORD_W-1:0] word_offset;
        input [WB_DATA_W-1:0] word_data;
        input [WB_BYTES-1:0] word_sel;
        integer byte_idx;
        integer bit_idx;
        integer burst_byte;
        integer lane_idx;
        integer sample_idx;
        begin
            burst_put_word = burst_data;
            for (byte_idx = 0; byte_idx < WB_BYTES; byte_idx = byte_idx + 1) begin
                if (word_sel[byte_idx]) begin
                    burst_byte = (word_offset * WB_BYTES) + byte_idx;
                    lane_idx   = burst_byte % NUM_BYTE_LANES;
                    sample_idx = burst_byte / NUM_BYTE_LANES;
                    for (bit_idx = 0; bit_idx < 8; bit_idx = bit_idx + 1) begin
                        if (sample_idx < SERDES_RATIO) begin
                            burst_put_word[lane_idx*DQ_BITS*SERDES_RATIO +
                                           bit_idx*SERDES_RATIO +
                                           sample_idx] =
                                word_data[byte_idx*8 + bit_idx];
                        end
                    end
                end
            end
        end
    endfunction

    function [15:0] burst_word_onehot;
        input [WB_BURST_WORD_W-1:0] word_offset;
        integer idx;
        begin
            burst_word_onehot = 16'd0;
            for (idx = 0; idx < 16; idx = idx + 1) begin
                if (word_offset == idx[WB_BURST_WORD_W-1:0])
                    burst_word_onehot[idx] = 1'b1;
            end
        end
    endfunction

    wire [WB_DATA_W-1:0] phy_rd_word;
    wire [PHY_DATA_W-1:0] rmw_wr_data_next;

    generate
        if (USE_FAST_BURST_WORD) begin : g_fast_burst_word
            genvar fb, fbit, fw, fl, fs;

            // For an 8-lane x8 BL8 burst exposed as 32-bit WB words:
            //   word_offset[0] selects lane group 0..3 vs 4..7,
            //   word_offset[3:1] selects the BL8 sample.
            // A registered one-hot avoids fanning four offset bits into every
            // byte-lane mux in both duplicated full-channel controllers.
            for (fb = 0; fb < WB_BYTES; fb = fb + 1) begin : g_fast_rd_byte
                for (fbit = 0; fbit < 8; fbit = fbit + 1) begin : g_fast_rd_bit
                    wire [15:0] rd_sel_bits;
                    for (fw = 0; fw < 16; fw = fw + 1) begin : g_fast_rd_word
                        localparam integer RD_LANE = ((fw % 2) * 4) + fb;
                        localparam integer RD_SAMPLE = fw / 2;
                        localparam integer RD_BIT =
                            RD_LANE*DQ_BITS*SERDES_RATIO +
                            fbit*SERDES_RATIO + RD_SAMPLE;
                        assign rd_sel_bits[fw] =
                            saved_burst_word_onehot[fw] & i_rd_data[RD_BIT];
                    end
                    assign phy_rd_word[fb*8 + fbit] = |rd_sel_bits;
                end
            end

            for (fl = 0; fl < NUM_BYTE_LANES; fl = fl + 1) begin : g_fast_wr_lane
                for (fbit = 0; fbit < DQ_BITS; fbit = fbit + 1) begin : g_fast_wr_bit
                    for (fs = 0; fs < SERDES_RATIO; fs = fs + 1) begin : g_fast_wr_sample
                        localparam integer WORD_INDEX = (fs * 2) + (fl / 4);
                        localparam integer BYTE_INDEX = fl % 4;
                        localparam integer WR_BIT =
                            fl*DQ_BITS*SERDES_RATIO +
                            fbit*SERDES_RATIO + fs;
                        wire replace_bit =
                            saved_burst_word_onehot[WORD_INDEX] &
                            saved_sel[BYTE_INDEX];
                        assign rmw_wr_data_next[WR_BIT] = replace_bit ?
                            saved_wdat[BYTE_INDEX*8 + fbit] :
                            (i_rd_valid ? i_rd_data[WR_BIT] : 1'b0);
                    end
                end
            end
        end else begin : g_generic_burst_word
            assign phy_rd_word =
                USE_BURST_WORD_OFFSET ? burst_get_word(i_rd_data, saved_burst_word_offset) :
                                        burst_get_word(i_rd_data, {WB_BURST_WORD_W{1'b0}});
            assign rmw_wr_data_next = burst_put_word(
                i_rd_valid ? i_rd_data : {PHY_DATA_W{1'b0}},
                saved_burst_word_offset,
                saved_wdat,
                saved_sel
            );
        end
    endgenerate

    wire [PHY_DATA_W-1:0] legacy_wr_data;

    genvar gl, gb, gs;
    generate
        for (gl = 0; gl < NUM_BYTE_LANES; gl = gl + 1) begin : g_lane_pack
            wire [7:0] lane_byte = (gl < WB_BYTES) ? saved_wdat[gl*8 +: 8] : 8'h00;
            for (gb = 0; gb < DQ_BITS; gb = gb + 1) begin : g_bit_pack
                for (gs = 0; gs < SERDES_RATIO; gs = gs + 1) begin : g_ser_pack
                    assign legacy_wr_data[gl*DQ_BITS*SERDES_RATIO + gb*SERDES_RATIO + gs]
                        = lane_byte[gb];
                end
            end
        end
    endgenerate
    assign o_wr_data = USE_BURST_WORD_OFFSET ? rmw_wr_data : legacy_wr_data;

    // Default mode acks each WB write/read after one BL8 command. Offset mode
    // first reads the whole BL8 payload for writes, merges the selected WB
    // bytes into the requested word offset, then writes the full burst back.
    always @(posedge i_clk_phy) begin
        if (i_rst || !i_init_done) begin
            state       <= S_IDLE;
            o_cmd_valid <= 1'b0;
            o_cmd       <= `DDR3_CMD_NOP;
            o_cmd_ba    <= {BANK_BITS{1'b0}};
            o_cmd_addr  <= {ROW_BITS{1'b0}};
            o_wb_ack    <= 1'b0;
            o_wb_dat    <= {WB_DATA_W{1'b0}};
            o_wr_valid  <= 1'b0;
            beat_ctr    <= 8'd0;
            wait_ctr    <= 8'd0;
            saved_burst_word_offset <= {WB_BURST_WORD_W{1'b0}};
            saved_burst_word_onehot <= 16'd1;
            saved_sel   <= {WB_BYTES{1'b0}};
            rmw_wr_data <= {PHY_DATA_W{1'b0}};
            ref_clear   <= 1'b0;
            mpr_clear   <= 1'b0;
            mrs_clear   <= 1'b0;
        end else begin
            o_cmd_valid <= 1'b0;
            o_cmd       <= `DDR3_CMD_NOP;
            o_wb_ack    <= 1'b0;
            o_wr_valid  <= 1'b0;
            ref_clear   <= 1'b0;
            mpr_clear   <= 1'b0;
            mrs_clear   <= 1'b0;

            case (state)
                S_IDLE: begin
                    if (ref_pending) begin
                        // Refresh has higher priority than new WB / MPR / MRS requests.
                        state    <= S_REF_PRE;
                    end else if (mrs_pending) begin
                        // MRS-rewrite (cal driving MR1[7] or MR3[2]) — before MPR
                        // so cal_seq can enable MPR mode before issuing MPR reads.
                        state    <= S_MRS;
                    end else if (mpr_pending) begin
                        state    <= S_MPR_RD;
                    end else if (i_wb_cyc && i_wb_stb && !o_wb_stall) begin
                        saved_bank <= wb_bank;
                        saved_row  <= wb_row;
                        saved_col  <= wb_col;
                        saved_we   <= i_wb_we;
                        saved_wdat <= i_wb_dat;
                        saved_sel  <= i_wb_sel;
                        saved_burst_word_offset <= wb_burst_word_offset;
                        saved_burst_word_onehot <= burst_word_onehot(wb_burst_word_offset);
                        state      <= S_ACT;
                    end
                end

                S_ACT: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_ACT;
                    o_cmd_ba    <= saved_bank;
                    o_cmd_addr  <= saved_row;
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_RCD;
                end

                S_WAIT_RCD: begin
                    if (wait_ctr == TRCD_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= (saved_we && !USE_BURST_WORD_OFFSET) ? S_WR : S_RD;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_RD: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_READ;
                    o_cmd_ba    <= saved_bank;
                    o_cmd_addr  <= { {(ROW_BITS-COL_BITS-1){1'b0}}, 1'b0 /* A10=0 no AP */, saved_col };
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_CL;
                end

                S_WAIT_CL: begin
                    if (wait_ctr == CL_SYS - 2) begin
                        wait_ctr <= 8'd0;
                        beat_ctr <= 8'd0;
                        state    <= S_DATA_RD;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_DATA_RD: begin
                    if (beat_ctr == READ_CAPTURE_SYS_CYCLES + READ_SETTLE_SYS_CYCLES - 1) begin
                        beat_ctr <= 8'd0;
                        if (saved_we && USE_BURST_WORD_OFFSET) begin
                            rmw_wr_data <= rmw_wr_data_next;
                            wait_ctr <= 8'd0;
                            state    <= S_WR;
                        end else begin
                            o_wb_dat <= i_rd_valid ? phy_rd_word : 32'hBAD0_BAD0;
                            o_wb_ack <= 1'b1;
                            state    <= S_PRE;
                        end
                    end else begin
                        beat_ctr <= beat_ctr + 1'b1;
                    end
                end

                S_WR: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_WRITE;
                    o_cmd_ba    <= saved_bank;
                    o_cmd_addr  <= { {(ROW_BITS-COL_BITS-1){1'b0}}, 1'b0, saved_col };
                    o_wr_valid  <= 1'b1;
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_CWL;
                end

                S_WAIT_CWL: begin
                    if (wait_ctr == CWL_START_WAIT) begin
                        wait_ctr <= 8'd0;
                        beat_ctr <= 8'd0;
                        state    <= S_DATA_WR;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_DATA_WR: begin
                    if (beat_ctr == BURST_SYS_CYCLES - 1) begin
                        o_wb_ack <= 1'b1;
                        beat_ctr <= 8'd0;
                        wait_ctr <= 8'd0;
                        state    <= S_WR_RECOV;
                    end else begin
                        beat_ctr <= beat_ctr + 1'b1;
                    end
                end

                S_WR_RECOV: begin
                    if (wait_ctr == TWR_SYS - 1) begin
                        wait_ctr <= 8'd0;
                        state    <= S_PRE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_PRE: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_PRE;
                    o_cmd_ba    <= saved_bank;
                    o_cmd_addr  <= {{(ROW_BITS-11){1'b0}}, 1'b0 /* A10=0 single bank */, 10'b0};
                    wait_ctr    <= 8'd0;
                    state       <= S_WAIT_RP;
                end

                S_WAIT_RP: begin
                    if (wait_ctr == TRP_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= S_IDLE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // ---- Refresh path ----
                S_REF_PRE: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_PRE;
                    o_cmd_ba    <= {BANK_BITS{1'b0}};
                    // A10 = 1 → all-bank precharge
                    o_cmd_addr  <= { {(ROW_BITS-11){1'b0}}, 1'b1, 10'b0 };
                    wait_ctr    <= 8'd0;
                    state       <= S_REF_WAIT_RP;
                end

                S_REF_WAIT_RP: begin
                    if (wait_ctr == TRP_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= S_REF;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                S_REF: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_REF;
                    o_cmd_ba    <= {BANK_BITS{1'b0}};
                    o_cmd_addr  <= {ROW_BITS{1'b0}};
                    wait_ctr    <= 8'd0;
                    state       <= S_REF_WAIT;
                end

                S_REF_WAIT: begin
                    if (wait_ctr == TRFC_WAIT) begin
                        wait_ctr  <= 8'd0;
                        ref_clear <= 1'b1;          // pulse to refresh scheduler
                        state     <= S_IDLE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // ---- MPR-read path (used by read-leveling) ----
                // No ACT, no PRE — MPR data is internal to the chip.
                // After RD with A[12]=1, wait CL cycles for data to
                // start appearing on DQ; rdlvl drives its own data
                // capture via the PHY's o_rd_valid pulse.
                S_MPR_RD: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_READ;
                    o_cmd_ba    <= {BANK_BITS{1'b0}};
                    // ROW_BITS-wide address; low 13 bits come from rdlvl,
                    // upper bits zero.
                    o_cmd_addr  <= { {(ROW_BITS-13){1'b0}}, mpr_addr_q };
                    mpr_clear   <= 1'b1;        // ack the request
                    wait_ctr    <= 8'd0;
                    state       <= S_MPR_WAIT;
                end

                S_MPR_WAIT: begin
                    // tCCD = 4 tCK minimum between back-to-back reads
                    // (BL8 occupies 4 tCK on the bus). After tCCD the
                    // next RD command can issue; rdlvl gates that by
                    // its own SETTLE_CYCLES + READ_LATENCY logic.
                    if (wait_ctr == TCCD_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= S_IDLE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                // ---- MRS-rewrite path (used by cal_seq) ----
                S_MRS: begin
                    o_cmd_valid <= 1'b1;
                    o_cmd       <= `DDR3_CMD_MRS;
                    o_cmd_ba    <= mrs_ba_q;
                    o_cmd_addr  <= mrs_addr_q;
                    mrs_clear   <= 1'b1;
                    wait_ctr    <= 8'd0;
                    state       <= S_MRS_WAIT;
                end

                S_MRS_WAIT: begin
                    // tMOD before any non-MRS command may issue.
                    if (wait_ctr == TMOD_WAIT) begin
                        wait_ctr <= 8'd0;
                        state    <= S_IDLE;
                    end else begin
                        wait_ctr <= wait_ctr + 1'b1;
                    end
                end

                default: state <= S_IDLE;
            endcase
        end
    end

    /* verilator lint_off UNUSED */
    wire _u = &{1'b0, ref_pending, saved_burst_word_offset,
                saved_burst_word_onehot, 1'b0};
    /* verilator lint_on UNUSED */
endmodule

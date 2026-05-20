// Formal harness for the DDR3 line-to-x8-burst adapter.

`default_nettype none

module ddr3_line_to_bursts_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer LANE_DATA_W = 64;
    localparam integer LANE_MASK_W = 8;

    (* anyseq *) wire [CHANNELS-1:0]               wr_line_valid;
    (* anyseq *) wire [(CHANNELS*LINE_DATA_W)-1:0] wr_line_data;
    (* anyseq *) wire [(CHANNELS*LINE_BYTES)-1:0]  wr_line_mask;
    (* anyseq *) wire [CHANNELS-1:0]               rd_line_ready;
    (* anyseq *) wire [PHY_LANES-1:0]              lane_wr_ready;
    (* anyseq *) wire [PHY_LANES-1:0]              lane_rd_valid;
    (* anyseq *) wire [(PHY_LANES*LANE_DATA_W)-1:0] lane_rd_data;

    wire [CHANNELS-1:0]                wr_line_ready;
    wire [CHANNELS-1:0]                rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0]  rd_line_data;
    wire [CHANNELS-1:0]                rd_line_err;
    wire [PHY_LANES-1:0]               lane_wr_valid;
    wire [(PHY_LANES*LANE_DATA_W)-1:0] lane_wr_data;
    wire [(PHY_LANES*LANE_MASK_W)-1:0] lane_wr_mask;
    wire [PHY_LANES-1:0]               lane_rd_ready;

    ddr3_line_to_bursts #(
        .CHANNELS(CHANNELS),
        .LANES(LANES)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_wr_line_valid(wr_line_valid),
        .o_wr_line_ready(wr_line_ready),
        .i_wr_line_data(wr_line_data),
        .i_wr_line_mask(wr_line_mask),
        .i_rd_line_ready(rd_line_ready),
        .o_rd_line_valid(rd_line_valid),
        .o_rd_line_data(rd_line_data),
        .o_rd_line_err(rd_line_err),
        .o_lane_wr_valid(lane_wr_valid),
        .i_lane_wr_ready(lane_wr_ready),
        .o_lane_wr_data(lane_wr_data),
        .o_lane_wr_mask(lane_wr_mask),
        .o_lane_rd_ready(lane_rd_ready),
        .i_lane_rd_valid(lane_rd_valid),
        .i_lane_rd_data(lane_rd_data)
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;
    reg [CHANNELS-1:0] f_wr_active = {CHANNELS{1'b0}};
    reg [PHY_LANES-1:0] f_wr_pending = {PHY_LANES{1'b0}};
    reg [(CHANNELS*LINE_DATA_W)-1:0] f_wr_line_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};
    reg [(CHANNELS*LINE_BYTES)-1:0] f_wr_line_mask =
        {(CHANNELS*LINE_BYTES){1'b1}};

    reg [CHANNELS-1:0] f_rd_done = {CHANNELS{1'b0}};
    reg [PHY_LANES-1:0] f_rd_seen = {PHY_LANES{1'b0}};
    reg [(CHANNELS*LINE_DATA_W)-1:0] f_rd_line_data =
        {(CHANNELS*LINE_DATA_W){1'b0}};

    reg [CHANNELS-1:0] f_wr_complete;
    reg [CHANNELS-1:0] f_rd_complete;

    integer ch_i;
    integer lane_i;
    integer phy_i;
    integer comb_ch_i;
    integer comb_lane_i;
    integer comb_phy_i;

    initial assume(rst);

    always @(*) begin
        f_wr_complete = {CHANNELS{1'b1}};
        f_rd_complete = {CHANNELS{1'b1}};

        for (comb_ch_i = 0; comb_ch_i < CHANNELS;
             comb_ch_i = comb_ch_i + 1) begin
            for (comb_lane_i = 0; comb_lane_i < LANES;
                 comb_lane_i = comb_lane_i + 1) begin
                comb_phy_i = (comb_ch_i * LANES) + comb_lane_i;
                if (f_wr_pending[comb_phy_i])
                    f_wr_complete[comb_ch_i] = 1'b0;
                if (!f_rd_seen[comb_phy_i])
                    f_rd_complete[comb_ch_i] = 1'b0;
            end
        end
    end

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_wr_active <= {CHANNELS{1'b0}};
            f_wr_pending <= {PHY_LANES{1'b0}};
            f_wr_line_data <= {(CHANNELS*LINE_DATA_W){1'b0}};
            f_wr_line_mask <= {(CHANNELS*LINE_BYTES){1'b1}};
            f_rd_done <= {CHANNELS{1'b0}};
            f_rd_seen <= {PHY_LANES{1'b0}};
            f_rd_line_data <= {(CHANNELS*LINE_DATA_W){1'b0}};
        end else begin
            assert(rd_line_err == {CHANNELS{1'b0}});

            for (ch_i = 0; ch_i < CHANNELS; ch_i = ch_i + 1) begin
                assert(wr_line_ready[ch_i] == !f_wr_active[ch_i]);

                if (wr_line_valid[ch_i] && !wr_line_ready[ch_i]) begin
                    assume(wr_line_data[ch_i*LINE_DATA_W +: LINE_DATA_W] ==
                           $past(wr_line_data[ch_i*LINE_DATA_W +: LINE_DATA_W]));
                    assume(wr_line_mask[ch_i*LINE_BYTES +: LINE_BYTES] ==
                           $past(wr_line_mask[ch_i*LINE_BYTES +: LINE_BYTES]));
                end

                if (wr_line_valid[ch_i] && wr_line_ready[ch_i]) begin
                    f_wr_active[ch_i] <= 1'b1;
                    f_wr_line_data[ch_i*LINE_DATA_W +: LINE_DATA_W] <=
                        wr_line_data[ch_i*LINE_DATA_W +: LINE_DATA_W];
                    f_wr_line_mask[ch_i*LINE_BYTES +: LINE_BYTES] <=
                        wr_line_mask[ch_i*LINE_BYTES +: LINE_BYTES];
                    for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1)
                        f_wr_pending[(ch_i*LANES) + lane_i] <= 1'b1;
                end else if (f_wr_active[ch_i] && f_wr_complete[ch_i]) begin
                    f_wr_active[ch_i] <= 1'b0;
                end

                if (!rd_line_ready[ch_i]) begin
                    f_rd_done[ch_i] <= 1'b0;
                    for (lane_i = 0; lane_i < LANES; lane_i = lane_i + 1)
                        f_rd_seen[(ch_i*LANES) + lane_i] <= 1'b0;
                end else if (f_rd_complete[ch_i]) begin
                    f_rd_done[ch_i] <= 1'b1;
                end

                if (rd_line_valid[ch_i]) begin
                    assert(rd_line_ready[ch_i]);
                    assert(f_rd_done[ch_i] || f_rd_complete[ch_i]);
                    assert(rd_line_data[ch_i*LINE_DATA_W +: LINE_DATA_W] ==
                           f_rd_line_data[ch_i*LINE_DATA_W +: LINE_DATA_W]);
                end
            end

            for (phy_i = 0; phy_i < PHY_LANES; phy_i = phy_i + 1) begin
                ch_i = phy_i / LANES;
                lane_i = phy_i % LANES;

                assert(lane_rd_ready[phy_i] ==
                       (rd_line_ready[ch_i] && !f_rd_done[ch_i] &&
                        !f_rd_seen[phy_i]));

                if (lane_wr_valid[phy_i]) begin
                    assert(f_wr_active[ch_i]);
                    assert(f_wr_pending[phy_i]);
                    assert(lane_wr_data[phy_i*LANE_DATA_W +: LANE_DATA_W] ==
                           f_wr_line_data[(ch_i*LINE_DATA_W) +
                                          (lane_i*LANE_DATA_W) +: LANE_DATA_W]);
                    assert(lane_wr_mask[phy_i*LANE_MASK_W +: LANE_MASK_W] ==
                           f_wr_line_mask[(ch_i*LINE_BYTES) +
                                          (lane_i*LANE_MASK_W) +: LANE_MASK_W]);
                end

                if (f_past_valid && $past(lane_wr_valid[phy_i]) &&
                    !$past(lane_wr_ready[phy_i])) begin
                    assert(lane_wr_valid[phy_i]);
                    assert(lane_wr_data[phy_i*LANE_DATA_W +: LANE_DATA_W] ==
                           $past(lane_wr_data[phy_i*LANE_DATA_W +: LANE_DATA_W]));
                    assert(lane_wr_mask[phy_i*LANE_MASK_W +: LANE_MASK_W] ==
                           $past(lane_wr_mask[phy_i*LANE_MASK_W +: LANE_MASK_W]));
                end

                if (lane_wr_valid[phy_i] && lane_wr_ready[phy_i])
                    f_wr_pending[phy_i] <= 1'b0;

                if (lane_rd_ready[phy_i] && lane_rd_valid[phy_i]) begin
                    assert(!f_rd_seen[phy_i]);
                    assert(!f_rd_done[ch_i]);
                    f_rd_seen[phy_i] <= 1'b1;
                    f_rd_line_data[(ch_i*LINE_DATA_W) +
                                   (lane_i*LANE_DATA_W) +: LANE_DATA_W] <=
                        lane_rd_data[phy_i*LANE_DATA_W +: LANE_DATA_W];
                end
            end

            cover(wr_line_valid[0] && wr_line_ready[0]);
            cover(f_wr_active[0] && f_wr_complete[0]);
            cover(rd_line_valid[0]);
            cover(rd_line_valid[0] && rd_line_valid[1]);
        end
    end
`endif
endmodule

`default_nettype wire

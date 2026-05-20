// Formal harness for the x64-data to x72-physical line adapter.

`default_nettype none

module ddr3_x8_to_x9_line_adapter_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer CHANNELS = 2;
    localparam integer DATA_LANES = 8;
    localparam integer PHY_LANES = 9;
    localparam integer DATA_LINE_BYTES = DATA_LANES * 8;
    localparam integer DATA_LINE_DATA_W = DATA_LINE_BYTES * 8;
    localparam integer PHY_LINE_BYTES = PHY_LANES * 8;
    localparam integer PHY_LINE_DATA_W = PHY_LINE_BYTES * 8;

    (* anyseq *) wire [CHANNELS-1:0] ctrl_wr_valid;
    (* anyseq *) wire [CHANNELS-1:0] phy_wr_ready;
    (* anyseq *) wire [CHANNELS-1:0] phy_wr_loaded;
    (* anyseq *) wire [(CHANNELS*DATA_LINE_DATA_W)-1:0] ctrl_wr_data;
    (* anyseq *) wire [(CHANNELS*DATA_LINE_BYTES)-1:0] ctrl_wr_mask;
    (* anyseq *) wire [CHANNELS-1:0] ctrl_rd_ready;
    (* anyseq *) wire [CHANNELS-1:0] phy_rd_valid;
    (* anyseq *) wire [(CHANNELS*PHY_LINE_DATA_W)-1:0] phy_rd_data;
    (* anyseq *) wire [CHANNELS-1:0] phy_rd_err;

    wire [CHANNELS-1:0] ctrl_wr_ready;
    wire [CHANNELS-1:0] ctrl_wr_loaded;
    wire [CHANNELS-1:0] ctrl_rd_valid;
    wire [(CHANNELS*DATA_LINE_DATA_W)-1:0] ctrl_rd_data;
    wire [CHANNELS-1:0] ctrl_rd_err;
    wire [CHANNELS-1:0] phy_wr_valid;
    wire [(CHANNELS*PHY_LINE_DATA_W)-1:0] phy_wr_data;
    wire [(CHANNELS*PHY_LINE_BYTES)-1:0] phy_wr_mask;
    wire [CHANNELS-1:0] phy_rd_ready;

    ddr3_x8_to_x9_line_adapter #(
        .CHANNELS(CHANNELS)
    ) dut (
        .i_ctrl_wr_line_valid(ctrl_wr_valid),
        .o_ctrl_wr_line_ready(ctrl_wr_ready),
        .o_ctrl_wr_line_loaded(ctrl_wr_loaded),
        .i_ctrl_wr_line_data(ctrl_wr_data),
        .i_ctrl_wr_line_mask(ctrl_wr_mask),
        .i_ctrl_rd_line_ready(ctrl_rd_ready),
        .o_ctrl_rd_line_valid(ctrl_rd_valid),
        .o_ctrl_rd_line_data(ctrl_rd_data),
        .o_ctrl_rd_line_err(ctrl_rd_err),
        .o_phy_wr_line_valid(phy_wr_valid),
        .i_phy_wr_line_ready(phy_wr_ready),
        .i_phy_wr_line_loaded(phy_wr_loaded),
        .o_phy_wr_line_data(phy_wr_data),
        .o_phy_wr_line_mask(phy_wr_mask),
        .o_phy_rd_line_ready(phy_rd_ready),
        .i_phy_rd_line_valid(phy_rd_valid),
        .i_phy_rd_line_data(phy_rd_data),
        .i_phy_rd_line_err(phy_rd_err)
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;
    integer ch_i;
    integer lane_i;

    initial assume(rst);

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        assert(phy_wr_valid == ctrl_wr_valid);
        assert(ctrl_wr_ready == phy_wr_ready);
        assert(ctrl_wr_loaded == phy_wr_loaded);
        assert(phy_rd_ready == ctrl_rd_ready);
        assert(ctrl_rd_valid == phy_rd_valid);
        assert(ctrl_rd_err == phy_rd_err);

        for (ch_i = 0; ch_i < CHANNELS; ch_i = ch_i + 1) begin
            for (lane_i = 0; lane_i < DATA_LANES; lane_i = lane_i + 1) begin
                assert(phy_wr_data[
                    ch_i*PHY_LINE_DATA_W + lane_i*64 +: 64] ==
                    ctrl_wr_data[
                        ch_i*DATA_LINE_DATA_W + lane_i*64 +: 64]);
                assert(phy_wr_mask[
                    ch_i*PHY_LINE_BYTES + lane_i*8 +: 8] ==
                    ctrl_wr_mask[
                        ch_i*DATA_LINE_BYTES + lane_i*8 +: 8]);
                assert(ctrl_rd_data[
                    ch_i*DATA_LINE_DATA_W + lane_i*64 +: 64] ==
                    phy_rd_data[
                        ch_i*PHY_LINE_DATA_W + lane_i*64 +: 64]);
            end

            assert(phy_wr_data[
                ch_i*PHY_LINE_DATA_W + DATA_LANES*64 +: 64] == 64'h0);
            assert(phy_wr_mask[
                ch_i*PHY_LINE_BYTES + DATA_LANES*8 +: 8] == 8'h00);
        end

        cover(phy_wr_valid[0] && ctrl_wr_ready[0]);
        cover(phy_rd_valid[1] && ctrl_rd_ready[1]);
    end
`endif
endmodule

`default_nettype wire

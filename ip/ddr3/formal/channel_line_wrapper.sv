// Formal harness for the full-channel DDR3 BL8 packetizer.

`default_nettype none

module ddr3_channel_line_wrapper (
    input wire clk,
    input wire rst
);
    localparam integer LANES = 8;
    localparam integer LINE_DATA_W = LANES * 64;
    localparam integer LINE_MASK_W = LANES * 8;

    (* anyseq *) wire                       start;
    (* anyseq *) wire                       write;
    (* anyseq *) wire [LINE_DATA_W-1:0]     wr_data;
    (* anyseq *) wire [LINE_MASK_W-1:0]     wr_mask;
    (* anyseq *) wire [LANES-1:0]           phy_wr_ready;
    (* anyseq *) wire [LANES-1:0]           phy_rd_valid;
    (* anyseq *) wire [(LANES*8)-1:0]       phy_rd_data;

    wire                      ready;
    wire                      busy;
    wire                      done;
    wire                      rd_valid;
    wire [LINE_DATA_W-1:0]    rd_data;
    wire [LANES-1:0]          phy_wr_valid;
    wire [(LANES*8)-1:0]      phy_wr_data;
    wire [LANES-1:0]          phy_wr_mask;
    wire [LANES-1:0]          phy_wr_last;
    wire [LANES-1:0]          phy_rd_ready;

    ddr3_channel_line #(
        .LANES(LANES)
    ) dut (
        .i_clk(clk),
        .i_rst(rst),
        .i_start(start),
        .o_ready(ready),
        .i_write(write),
        .i_wr_data(wr_data),
        .i_wr_mask(wr_mask),
        .o_busy(busy),
        .o_done(done),
        .o_rd_valid(rd_valid),
        .o_rd_data(rd_data),
        .o_phy_wr_valid(phy_wr_valid),
        .i_phy_wr_ready(phy_wr_ready),
        .o_phy_wr_data(phy_wr_data),
        .o_phy_wr_mask(phy_wr_mask),
        .o_phy_wr_last(phy_wr_last),
        .o_phy_rd_ready(phy_rd_ready),
        .i_phy_rd_valid(phy_rd_valid),
        .i_phy_rd_data(phy_rd_data)
    );

`ifdef FORMAL
    reg f_past_valid = 1'b0;
    reg f_active = 1'b0;
    reg f_write = 1'b0;
    reg [LINE_DATA_W-1:0] f_wr_data = {LINE_DATA_W{1'b0}};
    reg [LINE_MASK_W-1:0] f_wr_mask = {LINE_MASK_W{1'b0}};
    reg [LINE_DATA_W-1:0] f_rd_data = {LINE_DATA_W{1'b0}};
    reg [LANES-1:0] f_done_mask = {LANES{1'b0}};
    reg [LANES-1:0] f_rd_done_mask = {LANES{1'b0}};
    reg [(LANES*3)-1:0] f_wr_index = {(LANES*3){1'b0}};
    reg [(LANES*3)-1:0] f_rd_index = {(LANES*3){1'b0}};

    reg [LINE_DATA_W-1:0] f_rd_data_next;
    reg [LANES-1:0] f_done_mask_next;
    reg [LANES-1:0] f_rd_done_mask_next;
    integer i;

    initial assume(rst);

    function [2:0] lane_wr_index;
        input integer lane;
        begin
            lane_wr_index = f_wr_index[(lane * 3) +: 3];
        end
    endfunction

    function [2:0] lane_rd_index;
        input integer lane;
        begin
            lane_rd_index = f_rd_index[(lane * 3) +: 3];
        end
    endfunction

    always @(*) begin
        f_rd_data_next = f_rd_data;
        f_done_mask_next = f_done_mask;
        f_rd_done_mask_next = f_rd_done_mask;

        for (i = 0; i < LANES; i = i + 1) begin
            if (phy_wr_valid[i] && phy_wr_ready[i])
                f_done_mask_next[i] = (lane_wr_index(i) == 3'd7);

            if (phy_rd_valid[i] && phy_rd_ready[i]) begin
                f_rd_data_next[(i * 64) + (lane_rd_index(i) * 8) +: 8] =
                    phy_rd_data[(i * 8) +: 8];
                f_done_mask_next[i] = (lane_rd_index(i) == 3'd7);
                f_rd_done_mask_next[i] = (lane_rd_index(i) == 3'd7);
            end
        end
    end

    always @(posedge clk) begin
        f_past_valid <= 1'b1;

        if (f_past_valid)
            assume(!rst);

        if (rst) begin
            f_active <= 1'b0;
            f_write <= 1'b0;
            f_wr_data <= {LINE_DATA_W{1'b0}};
            f_wr_mask <= {LINE_MASK_W{1'b0}};
            f_rd_data <= {LINE_DATA_W{1'b0}};
            f_done_mask <= {LANES{1'b0}};
            f_rd_done_mask <= {LANES{1'b0}};
            f_wr_index <= {(LANES*3){1'b0}};
            f_rd_index <= {(LANES*3){1'b0}};
        end else begin
            if (start)
                assume(ready);
            assume(!(start && f_active));

            for (i = 0; i < LANES; i = i + 1) begin
                if (phy_rd_valid[i])
                    assume(phy_rd_ready[i]);
            end

            if (f_active && f_write)
                assume(phy_wr_ready == {LANES{1'b1}});
            if (f_active && !f_write)
                assume(phy_rd_valid == phy_rd_ready);

            assert(!rd_valid || done);
            assert(!(phy_wr_valid != {LANES{1'b0}} && phy_rd_ready != {LANES{1'b0}}));

            if (start && ready) begin
                f_active <= 1'b1;
                f_write <= write;
                f_wr_data <= wr_data;
                f_wr_mask <= wr_mask;
                f_rd_data <= {LINE_DATA_W{1'b0}};
                f_done_mask <= {LANES{1'b0}};
                f_rd_done_mask <= {LANES{1'b0}};
                f_wr_index <= {(LANES*3){1'b0}};
                f_rd_index <= {(LANES*3){1'b0}};
            end else if (f_active) begin
                f_rd_data <= f_rd_data_next;
                f_done_mask <= f_done_mask_next;
                f_rd_done_mask <= f_rd_done_mask_next;

                for (i = 0; i < LANES; i = i + 1) begin
                    if (phy_wr_valid[i] && phy_wr_ready[i]) begin
                        if (lane_wr_index(i) == 3'd7)
                            f_wr_index[(i * 3) +: 3] <= 3'd0;
                        else
                            f_wr_index[(i * 3) +: 3] <= lane_wr_index(i) + 3'd1;
                    end

                    if (phy_rd_valid[i] && phy_rd_ready[i]) begin
                        if (lane_rd_index(i) == 3'd7)
                            f_rd_index[(i * 3) +: 3] <= 3'd0;
                        else
                            f_rd_index[(i * 3) +: 3] <= lane_rd_index(i) + 3'd1;
                    end
                end

                if (&f_done_mask_next)
                    f_active <= 1'b0;
            end

            for (i = 0; i < LANES; i = i + 1) begin
                if (phy_wr_valid[i]) begin
                    assert(f_active);
                    assert(f_write);
                    assert(phy_wr_data[(i * 8) +: 8] ==
                           f_wr_data[(i * 64) + (lane_wr_index(i) * 8) +: 8]);
                    assert(phy_wr_mask[i] ==
                           f_wr_mask[(i * 8) + lane_wr_index(i)]);
                    assert(phy_wr_last[i] == (lane_wr_index(i) == 3'd7));
                end

                if (phy_rd_ready[i]) begin
                    assert(f_active);
                    assert(!f_write);
                end
            end

            if (done) begin
                assert(f_active);
                assert(&f_done_mask_next);
            end

            if (rd_valid) begin
                assert(!f_write);
                assert(&f_rd_done_mask_next);
                assert(rd_data == f_rd_data_next);
            end

            cover(done && f_write);
            cover(rd_valid && !f_write);
        end
    end
`endif
endmodule

`default_nettype wire

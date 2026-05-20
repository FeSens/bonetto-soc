`default_nettype none
`timescale 1ns/1ps

module tb_x8_to_x9_line_adapter;
    localparam integer CHANNELS = 2;
    localparam integer DATA_LANES = 8;
    localparam integer PHY_LANES = 9;
    localparam integer DATA_LINE_BYTES = DATA_LANES * 8;
    localparam integer DATA_LINE_DATA_W = DATA_LINE_BYTES * 8;
    localparam integer PHY_LINE_BYTES = PHY_LANES * 8;
    localparam integer PHY_LINE_DATA_W = PHY_LINE_BYTES * 8;

    reg [CHANNELS-1:0] ctrl_wr_valid = 2'b00;
    reg [CHANNELS-1:0] phy_wr_ready = 2'b00;
    reg [CHANNELS-1:0] phy_wr_loaded = 2'b00;
    reg [(CHANNELS*DATA_LINE_DATA_W)-1:0] ctrl_wr_data =
        {(CHANNELS*DATA_LINE_DATA_W){1'b0}};
    reg [(CHANNELS*DATA_LINE_BYTES)-1:0] ctrl_wr_mask =
        {(CHANNELS*DATA_LINE_BYTES){1'b1}};
    reg [CHANNELS-1:0] ctrl_rd_ready = 2'b00;
    reg [CHANNELS-1:0] phy_rd_valid = 2'b00;
    reg [(CHANNELS*PHY_LINE_DATA_W)-1:0] phy_rd_data =
        {(CHANNELS*PHY_LINE_DATA_W){1'b0}};
    reg [CHANNELS-1:0] phy_rd_err = 2'b00;

    wire [CHANNELS-1:0] ctrl_wr_ready;
    wire [CHANNELS-1:0] ctrl_wr_loaded;
    wire [CHANNELS-1:0] ctrl_rd_valid;
    wire [(CHANNELS*DATA_LINE_DATA_W)-1:0] ctrl_rd_data;
    wire [CHANNELS-1:0] ctrl_rd_err;
    wire [CHANNELS-1:0] phy_wr_valid;
    wire [(CHANNELS*PHY_LINE_DATA_W)-1:0] phy_wr_data;
    wire [(CHANNELS*PHY_LINE_BYTES)-1:0] phy_wr_mask;
    wire [CHANNELS-1:0] phy_rd_ready;

    integer ch;
    integer lane;

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

    initial begin
        ctrl_wr_valid = 2'b10;
        phy_wr_ready = 2'b01;
        phy_wr_loaded = 2'b11;
        ctrl_rd_ready = 2'b11;
        phy_rd_valid = 2'b01;
        phy_rd_err = 2'b10;

        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin
            for (lane = 0; lane < DATA_LANES; lane = lane + 1) begin
                ctrl_wr_data[ch*DATA_LINE_DATA_W + lane*64 +: 64] =
                    64'h1000_0000_0000_0000 + ch*64'h100 + lane;
                ctrl_wr_mask[ch*DATA_LINE_BYTES + lane*8 +: 8] =
                    8'h80 + lane;
            end

            for (lane = 0; lane < PHY_LANES; lane = lane + 1)
                phy_rd_data[ch*PHY_LINE_DATA_W + lane*64 +: 64] =
                    64'hA000_0000_0000_0000 + ch*64'h100 + lane;
        end

        #1;
        if (phy_wr_valid !== ctrl_wr_valid ||
            ctrl_wr_ready !== phy_wr_ready ||
            ctrl_wr_loaded !== phy_wr_loaded ||
            phy_rd_ready !== ctrl_rd_ready ||
            ctrl_rd_valid !== phy_rd_valid ||
            ctrl_rd_err !== phy_rd_err) begin
            $display("[x8-to-x9] handshake passthrough mismatch");
            $fatal(1);
        end

        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin
            for (lane = 0; lane < DATA_LANES; lane = lane + 1) begin
                if (phy_wr_data[ch*PHY_LINE_DATA_W + lane*64 +: 64] !==
                    ctrl_wr_data[ch*DATA_LINE_DATA_W + lane*64 +: 64]) begin
                    $display("[x8-to-x9] write data mismatch ch=%0d lane=%0d",
                             ch, lane);
                    $fatal(1);
                end
                if (phy_wr_mask[ch*PHY_LINE_BYTES + lane*8 +: 8] !==
                    ctrl_wr_mask[ch*DATA_LINE_BYTES + lane*8 +: 8]) begin
                    $display("[x8-to-x9] write mask mismatch ch=%0d lane=%0d",
                             ch, lane);
                    $fatal(1);
                end
                if (ctrl_rd_data[ch*DATA_LINE_DATA_W + lane*64 +: 64] !==
                    phy_rd_data[ch*PHY_LINE_DATA_W + lane*64 +: 64]) begin
                    $display("[x8-to-x9] read data mismatch ch=%0d lane=%0d",
                             ch, lane);
                    $fatal(1);
                end
            end

            if (phy_wr_data[ch*PHY_LINE_DATA_W + DATA_LANES*64 +: 64] !==
                64'h0) begin
                $display("[x8-to-x9] spare lane write data mismatch ch=%0d",
                         ch);
                $fatal(1);
            end
            if (phy_wr_mask[ch*PHY_LINE_BYTES + DATA_LANES*8 +: 8] !==
                8'h00) begin
                $display("[x8-to-x9] spare lane mask mismatch ch=%0d", ch);
                $fatal(1);
            end
        end

        $display("[x8-to-x9] explicit spare-lane adapter passed");
        $finish;
    end
endmodule

`default_nettype wire

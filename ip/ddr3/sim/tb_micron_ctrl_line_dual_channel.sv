`default_nettype none
`timescale 1ps/1ps

`include "ddr3_params.vh"

module tb_micron_ctrl_line_dual_channel;
    localparam integer CHANNELS = 2;
    localparam integer LANES = 8;
    localparam integer WB_DATA_W = 32;
    localparam integer GLOBAL_WORD_ADDR_W = 30;
    localparam integer ADDR_BITS = `DDR3_ADDR_BITS;
    localparam integer BANK_BITS = `DDR3_BANK_BITS;
    localparam integer LINE_BYTES = LANES * 8;
    localparam integer LINE_DATA_W = LINE_BYTES * 8;
    localparam integer PHY_LANES = CHANNELS * LANES;
    localparam integer TCK_PS = `DDR3_800_TCK_PS;

    localparam [GLOBAL_WORD_ADDR_W-1:0] CH0_ADDR = 30'h0000_002d;
    localparam [GLOBAL_WORD_ADDR_W-1:0] CH1_ADDR = {1'b1, 29'h0000_003e};
    localparam [WB_DATA_W-1:0] CH0_DATA = 32'h0bad_cafe;
    localparam [WB_DATA_W-1:0] CH1_DATA = 32'h1357_9bdf;

    reg ck = 1'b0;
    wire ck_n = ~ck;
    reg rst = 1'b1;
    reg init_start = 1'b1;
    reg seed_inputs = 1'b1;

    reg                         wb_cyc = 1'b0;
    reg                         wb_stb = 1'b0;
    reg                         wb_we = 1'b0;
    reg [GLOBAL_WORD_ADDR_W-1:0] wb_adr = {GLOBAL_WORD_ADDR_W{1'b0}};
    reg [WB_DATA_W-1:0]         wb_dat_w = {WB_DATA_W{1'b0}};
    reg [(WB_DATA_W/8)-1:0]     wb_sel = {(WB_DATA_W/8){1'b0}};
    wire                        wb_stall;
    wire                        wb_ack;
    wire                        wb_err;
    wire [WB_DATA_W-1:0]        wb_dat_r;

    wire [CHANNELS-1:0]         init_done;
    wire [CHANNELS-1:0]         ddr_reset_n;
    wire [CHANNELS-1:0]         ddr_cke;
    wire [CHANNELS-1:0]         ddr_odt;
    wire [CHANNELS-1:0]         ddr_cmd_valid;
    wire [CHANNELS-1:0]         ddr_cs_n;
    wire [CHANNELS-1:0]         ddr_ras_n;
    wire [CHANNELS-1:0]         ddr_cas_n;
    wire [CHANNELS-1:0]         ddr_we_n;
    wire [(CHANNELS*BANK_BITS)-1:0] ddr_ba;
    wire [(CHANNELS*ADDR_BITS)-1:0] ddr_addr;

    wire [CHANNELS-1:0]         phy_wr_line_valid;
    wire [CHANNELS-1:0]         phy_wr_line_ready;
    wire [(CHANNELS*LINE_DATA_W)-1:0] phy_wr_line_data;
    wire [(CHANNELS*LINE_BYTES)-1:0]  phy_wr_line_mask;
    wire [CHANNELS-1:0]         phy_rd_line_ready;
    wire [CHANNELS-1:0]         phy_rd_line_valid;
    wire [(CHANNELS*LINE_DATA_W)-1:0] phy_rd_line_data;
    wire [CHANNELS-1:0]         phy_rd_line_err;

    wire [PHY_LANES-1:0]        phy_wr_valid;
    wire [PHY_LANES-1:0]        phy_wr_ready;
    wire [(PHY_LANES*8)-1:0]    phy_wr_data;
    wire [PHY_LANES-1:0]        phy_wr_mask;
    wire [PHY_LANES-1:0]        phy_wr_last;
    wire [PHY_LANES-1:0]        phy_rd_ready;
    wire [PHY_LANES-1:0]        phy_rd_valid;
    wire [(PHY_LANES*8)-1:0]    phy_rd_data;

    reg [CHANNELS-1:0] model_reset_n = {CHANNELS{1'b1}};
    reg [CHANNELS-1:0] model_cke = {CHANNELS{1'b1}};
    reg [CHANNELS-1:0] model_odt = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] model_cs_n = {CHANNELS{1'b0}};
    reg [CHANNELS-1:0] model_ras_n = {CHANNELS{1'b1}};
    reg [CHANNELS-1:0] model_cas_n = {CHANNELS{1'b1}};
    reg [CHANNELS-1:0] model_we_n = {CHANNELS{1'b1}};
    reg [(CHANNELS*BANK_BITS)-1:0] model_ba = {CHANNELS{3'h7}};
    reg [(CHANNELS*ADDR_BITS)-1:0] model_addr = {CHANNELS{15'h7fff}};

    integer ch_i;

    always #(TCK_PS / 2) ck <= ~ck;

    ddr3_ctrl_line #(
        .INIT_RESET_LOW_CYCLES(16),
        .INIT_RESET_CKE_CYCLES(20)
    ) dut (
        .i_clk(ck),
        .i_rst(rst),
        .i_init_start(init_start),
        .i_wb_cyc(wb_cyc),
        .i_wb_stb(wb_stb),
        .i_wb_we(wb_we),
        .i_wb_dat(wb_dat_w),
        .i_wb_sel(wb_sel),
        .i_wb_adr(wb_adr),
        .o_wb_stall(wb_stall),
        .o_wb_ack(wb_ack),
        .o_wb_err(wb_err),
        .o_wb_dat(wb_dat_r),
        .o_init_done(init_done),
        .o_init_busy(),
        .o_init_state(),
        .o_init_all_done(),
        .o_sched_req_pending(),
        .o_refresh_req(),
        .o_refresh_ack(),
        .o_refresh_busy(),
        .o_refresh_late(),
        .o_refresh_count(),
        .o_bank_busy(),
        .o_bank_open(),
        .o_ddr_reset_n(ddr_reset_n),
        .o_ddr_cke(ddr_cke),
        .o_ddr_odt(ddr_odt),
        .o_ddr_cmd_valid(ddr_cmd_valid),
        .o_ddr_cs_n(ddr_cs_n),
        .o_ddr_ras_n(ddr_ras_n),
        .o_ddr_cas_n(ddr_cas_n),
        .o_ddr_we_n(ddr_we_n),
        .o_ddr_ba(ddr_ba),
        .o_ddr_addr(ddr_addr),
        .o_phy_wr_line_valid(phy_wr_line_valid),
        .i_phy_wr_line_ready(phy_wr_line_ready),
        .o_phy_wr_line_data(phy_wr_line_data),
        .o_phy_wr_line_mask(phy_wr_line_mask),
        .o_phy_rd_line_ready(phy_rd_line_ready),
        .i_phy_rd_line_valid(phy_rd_line_valid),
        .i_phy_rd_line_data(phy_rd_line_data),
        .i_phy_rd_line_err(phy_rd_line_err)
    );

    ddr3_line_phy_bridge #(
        .CHANNELS(CHANNELS),
        .LANES(LANES)
    ) u_line_bridge (
        .i_clk(ck),
        .i_rst(rst),
        .i_wr_line_valid(phy_wr_line_valid),
        .o_wr_line_ready(phy_wr_line_ready),
        .i_wr_line_data(phy_wr_line_data),
        .i_wr_line_mask(phy_wr_line_mask),
        .i_rd_line_ready(phy_rd_line_ready),
        .o_rd_line_valid(phy_rd_line_valid),
        .o_rd_line_data(phy_rd_line_data),
        .o_rd_line_err(phy_rd_line_err),
        .o_lane_wr_valid(phy_wr_valid),
        .i_lane_wr_ready(phy_wr_ready),
        .o_lane_wr_data(phy_wr_data),
        .o_lane_wr_mask(phy_wr_mask),
        .o_lane_wr_last(phy_wr_last),
        .o_lane_rd_ready(phy_rd_ready),
        .i_lane_rd_valid(phy_rd_valid),
        .i_lane_rd_data(phy_rd_data)
    );

    always @(negedge ck) begin
        if (!seed_inputs) begin
            for (ch_i = 0; ch_i < CHANNELS; ch_i = ch_i + 1) begin
                model_reset_n[ch_i] <= ddr_reset_n[ch_i];
                model_cke[ch_i]     <= ddr_cke[ch_i];
                model_odt[ch_i]     <= ddr_odt[ch_i];
                model_cs_n[ch_i]    <= ddr_cmd_valid[ch_i] ? ddr_cs_n[ch_i] : 1'b1;
                model_ras_n[ch_i]   <= ddr_ras_n[ch_i];
                model_cas_n[ch_i]   <= ddr_cas_n[ch_i];
                model_we_n[ch_i]    <= ddr_we_n[ch_i];
                model_ba[ch_i*BANK_BITS +: BANK_BITS] <=
                    ddr_ba[ch_i*BANK_BITS +: BANK_BITS];
                model_addr[ch_i*ADDR_BITS +: ADDR_BITS] <=
                    ddr_addr[ch_i*ADDR_BITS +: ADDR_BITS];
            end
        end
    end

    genvar ch;
    genvar lane;
    generate
        for (ch = 0; ch < CHANNELS; ch = ch + 1) begin : gen_channel
            wire model_cmd_valid_agent = !model_cs_n[ch] &&
                ({model_cs_n[ch], model_ras_n[ch], model_cas_n[ch],
                  model_we_n[ch]} != `DDR3_CMD_NOP);

            for (lane = 0; lane < LANES; lane = lane + 1) begin : gen_lane
                localparam integer PHY_INDEX = (ch * LANES) + lane;

                wire [7:0] dq;
                wire [0:0] dqs;
                wire [0:0] dqs_n;
                wire [0:0] dm_tdqs;
                wire [0:0] tdqs_n;

                pullup p_dm[0:0]  (dm_tdqs);
                pullup p_dq[7:0]  (dq);
                pullup p_dqs[0:0] (dqs);
                pulldown p_dqsn[0:0] (dqs_n);

                ddr3_x8_phy_agent #(
                    .TCK_PS(TCK_PS),
                    .CL_CYCLES(`DDR3_800_CL_CYCLES),
                    .CWL_CYCLES(`DDR3_800_CWL_CYCLES)
                ) u_agent (
                    .i_clk(ck),
                    .i_rst(rst),
                    .i_cmd_valid(model_cmd_valid_agent),
                    .i_cmd({model_cs_n[ch], model_ras_n[ch],
                            model_cas_n[ch], model_we_n[ch]}),
                    .i_phy_wr_valid(phy_wr_valid[PHY_INDEX]),
                    .o_phy_wr_ready(phy_wr_ready[PHY_INDEX]),
                    .i_phy_wr_data(phy_wr_data[PHY_INDEX*8 +: 8]),
                    .i_phy_wr_mask(phy_wr_mask[PHY_INDEX]),
                    .i_phy_wr_last(phy_wr_last[PHY_INDEX]),
                    .i_phy_rd_ready(phy_rd_ready[PHY_INDEX]),
                    .o_phy_rd_valid(phy_rd_valid[PHY_INDEX]),
                    .o_phy_rd_data(phy_rd_data[PHY_INDEX*8 +: 8]),
                    .io_dq(dq),
                    .io_dqs(dqs[0]),
                    .io_dqs_n(dqs_n[0]),
                    .io_dm_tdqs(dm_tdqs[0])
                );

                ddr3 #(
                    .SIMUL_500US(0),
                    .SIMUL_200US(0)
                ) u_model (
                    .rst_n(model_reset_n[ch]),
                    .ck(ck),
                    .ck_n(ck_n),
                    .cke(model_cke[ch]),
                    .cs_n(model_cs_n[ch]),
                    .ras_n(model_ras_n[ch]),
                    .cas_n(model_cas_n[ch]),
                    .we_n(model_we_n[ch]),
                    .dm_tdqs(dm_tdqs),
                    .ba(model_ba[ch*BANK_BITS +: BANK_BITS]),
                    .addr(model_addr[ch*ADDR_BITS +: ADDR_BITS]),
                    .dq(dq),
                    .dqs(dqs),
                    .dqs_n(dqs_n),
                    .tdqs_n(tdqs_n),
                    .odt(model_odt[ch])
                );
            end
        end
    endgenerate

    task start_wb;
        input write;
        input [GLOBAL_WORD_ADDR_W-1:0] addr;
        input [WB_DATA_W-1:0] data;
        input [(WB_DATA_W/8)-1:0] sel;
        begin
            @(negedge ck);
            wb_cyc = 1'b1;
            wb_stb = 1'b1;
            wb_we = write;
            wb_adr = addr;
            wb_dat_w = data;
            wb_sel = sel;
            while (wb_stall)
                @(negedge ck);
            @(negedge ck);
            wb_stb = 1'b0;
        end
    endtask

    task finish_wb;
        begin
            @(negedge ck);
            wb_cyc = 1'b0;
            wb_we = 1'b0;
            wb_adr = {GLOBAL_WORD_ADDR_W{1'b0}};
            wb_dat_w = {WB_DATA_W{1'b0}};
            wb_sel = {(WB_DATA_W/8){1'b0}};
        end
    endtask

    task wb_write_word;
        input integer channel;
        input [GLOBAL_WORD_ADDR_W-1:0] addr;
        input [WB_DATA_W-1:0] data;
        begin
            start_wb(1'b1, addr, data, 4'hf);
            wait (wb_ack);
            if (wb_err) begin
                $display("[micron-ctrl-line-dual] write ack error channel=%0d addr=%h",
                         channel, addr);
                $fatal(1);
            end
            finish_wb();
        end
    endtask

    task wb_read_word;
        input [GLOBAL_WORD_ADDR_W-1:0] addr;
        input [WB_DATA_W-1:0] expected;
        begin
            start_wb(1'b0, addr, {WB_DATA_W{1'b0}}, 4'hf);
            wait (wb_ack);
            if (wb_err || wb_dat_r !== expected) begin
                $display("[micron-ctrl-line-dual] read mismatch addr=%h expected=%h got=%h err=%0b",
                         addr, expected, wb_dat_r, wb_err);
                $fatal(1);
            end
            finish_wb();
        end
    endtask

    initial begin
        #1;
        model_reset_n = {CHANNELS{1'b0}};
        model_cke = {CHANNELS{1'b0}};
        model_cs_n = {CHANNELS{1'b1}};
        model_ba = {CHANNELS{3'd0}};
        model_addr = {CHANNELS{15'd0}};
        seed_inputs = 1'b0;

        repeat (4) @(posedge ck);
        rst = 1'b0;

        wait (init_done == {CHANNELS{1'b1}});
        repeat (4) @(posedge ck);

        wb_write_word(0, CH0_ADDR, CH0_DATA);
        wb_read_word(CH0_ADDR, CH0_DATA);

        wb_write_word(1, CH1_ADDR, CH1_DATA);
        wb_read_word(CH1_ADDR, CH1_DATA);

        $display("[micron-ctrl-line-dual] line-level dual-channel Micron loopback passed");
        $finish;
    end

    initial begin
        repeat (12000) @(posedge ck);
        $display("[micron-ctrl-line-dual] timeout init_done=%b ack=%0b stall=%0b wr_line=%b rd_ready=%b rd_valid=%b",
                 init_done, wb_ack, wb_stall, phy_wr_line_valid,
                 phy_rd_line_ready, phy_rd_line_valid);
        $fatal(1);
    end
endmodule

`default_nettype wire

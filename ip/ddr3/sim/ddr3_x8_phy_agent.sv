`default_nettype none
`timescale 1ps/1ps

`include "ddr3_params.vh"

module ddr3_x8_phy_agent #(
    parameter integer TCK_PS = `DDR3_800_TCK_PS,
    parameter integer CL_CYCLES = `DDR3_800_CL_CYCLES,
    parameter integer CWL_CYCLES = `DDR3_800_CWL_CYCLES
) (
    input wire        i_clk,
    input wire        i_rst,

    input wire        i_cmd_valid,
    input wire [3:0]  i_cmd,

    input wire        i_phy_wr_valid,
    output reg        o_phy_wr_ready,
    input wire [7:0]  i_phy_wr_data,
    input wire        i_phy_wr_mask,
    input wire        i_phy_wr_last,

    input wire        i_phy_rd_ready,
    output reg        o_phy_rd_valid,
    output reg [7:0]  o_phy_rd_data,

    inout wire [7:0]  io_dq,
    inout wire        io_dqs,
    inout wire        io_dqs_n,
    inout wire        io_dm_tdqs
);
    localparam integer DQS_EDGE_SETTLE_PS = 200;

    reg        dq_drive_en = 1'b0;
    reg [7:0]  dq_drive = 8'hff;
    reg        dqs_drive_en = 1'b0;
    reg        dqs_drive = 1'b0;
    reg        dm_drive_en = 1'b0;
    reg        dm_drive = 1'b1;

    reg [7:0] wr_data [0:7];
    reg       wr_mask [0:7];
    integer   wr_loaded = 0;

    assign io_dq      = dq_drive_en  ? dq_drive  : 8'hzz;
    assign io_dqs     = dqs_drive_en ? dqs_drive : 1'bz;
    assign io_dqs_n   = dqs_drive_en ? ~dqs_drive : 1'bz;
    assign io_dm_tdqs = dm_drive_en  ? dm_drive  : 1'bz;

    wire cmd_write = i_cmd_valid && (i_cmd == `DDR3_CMD_WR);
    wire cmd_read  = i_cmd_valid && (i_cmd == `DDR3_CMD_RD);

    integer k;
    initial begin
        o_phy_wr_ready = 1'b0;
        o_phy_rd_valid = 1'b0;
        o_phy_rd_data = 8'h00;
        for (k = 0; k < 8; k = k + 1) begin
            wr_data[k] = 8'h00;
            wr_mask[k] = 1'b1;
        end
    end

    always @(posedge i_clk) begin
        if (!i_rst && cmd_write) begin
            fork
                collect_write_beats();
                drive_write_burst();
            join_none
        end

        if (!i_rst && cmd_read) begin
            fork
                capture_read_burst();
            join_none
        end
    end

    task automatic collect_write_beats;
        integer i;
        begin
            wr_loaded = 0;
            o_phy_wr_ready = 1'b1;

            for (i = 0; i < 8; i = i + 1) begin
                while (!i_phy_wr_valid)
                    @(negedge i_clk);

                wr_data[i] = i_phy_wr_data;
                wr_mask[i] = i_phy_wr_mask;
                wr_loaded = i + 1;

                if (i_phy_wr_last !== (i == 7)) begin
                    $display("[x8-agent] write last mismatch beat=%0d last=%0b",
                             i, i_phy_wr_last);
                    $fatal(1);
                end

                @(posedge i_clk);
                @(negedge i_clk);
            end

            o_phy_wr_ready = 1'b0;
        end
    endtask

    task automatic drive_write_burst;
        integer i;
        begin
            repeat (CWL_CYCLES) @(posedge i_clk);

            wait (wr_loaded > 0);
            dq_drive = wr_data[0];
            dm_drive = wr_mask[0];
            dq_drive_en = 1'b1;
            dm_drive_en = 1'b1;
            dqs_drive = 1'b0;
            dqs_drive_en = 1'b1;

            #(TCK_PS / 4);
            for (i = 0; i < 8; i = i + 1) begin
                dqs_drive = ~dqs_drive;
                #DQS_EDGE_SETTLE_PS;

                if (i < 7) begin
                    wait (wr_loaded > i + 1);
                    dq_drive = wr_data[i + 1];
                    dm_drive = wr_mask[i + 1];
                end

                #(TCK_PS / 2 - DQS_EDGE_SETTLE_PS);
            end

            #(TCK_PS / 2);
            dqs_drive = 1'b0;
            #(TCK_PS / 2);
            dqs_drive_en = 1'b0;
            dq_drive_en = 1'b0;
            dm_drive_en = 1'b0;
            dq_drive = 8'hff;
            dm_drive = 1'b1;
        end
    endtask

    task automatic capture_read_burst;
        reg [7:0] rd_data [0:7];
        integer i;
        begin
            repeat (CL_CYCLES - 1) @(posedge i_clk);
            @(negedge i_clk);
            #(TCK_PS / 2 + 10);

            for (i = 0; i < 8; i = i + 1) begin
                rd_data[i] = io_dq;
                if (i < 7)
                    #(TCK_PS / 2);
            end

            for (i = 0; i < 8; i = i + 1) begin
                while (!i_phy_rd_ready)
                    @(negedge i_clk);

                o_phy_rd_data = rd_data[i];
                o_phy_rd_valid = 1'b1;
                @(posedge i_clk);
                @(negedge i_clk);
            end

            o_phy_rd_valid = 1'b0;
            o_phy_rd_data = 8'h00;
        end
    endtask
endmodule

`default_nettype wire

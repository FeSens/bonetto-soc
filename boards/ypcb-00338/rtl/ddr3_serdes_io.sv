// Xilinx 7-series DDR3 x8 SERDES pin shell.
//
// This is board-local primitive glue. It converts one 64-bit BL8 x8 lane in
// the CLKDIV domain into eight OSERDESE2-driven DQ pins plus one OSERDESE2
// DQS pin, and captures the same pins back through IDELAYE2 + ISERDESE2.
// Training, bitslip policy, DQS phase selection, and read leveling belong in
// the controller/PHY logic above this structural shell.

`default_nettype none

module ddr3_x8_serdes_io_7series #(
    parameter integer IDELAY_TAPS = 0,
    parameter integer ENABLE_TX = 1,
    parameter integer ENABLE_RX = 1,
    parameter integer USE_IDELAY = 1
) (
    input  wire        i_clk_serdes,
    input  wire        i_clk_div,
    input  wire        i_rst,
    input  wire [63:0] i_dq_bits,
    input  wire [7:0]  i_dqs_bits,
    input  wire [3:0]  i_dq_oe,
    input  wire [3:0]  i_dqs_oe,
    input  wire        i_bitslip,
    output wire [63:0] o_dq_bits,
    output wire [7:0]  o_dqs_bits,
    inout  wire [7:0]  io_dq,
    inout  wire        io_dqs_p,
    inout  wire        io_dqs_n
);
    wire clk_serdes_b = !i_clk_serdes;

    genvar dq_i;
    generate
        for (dq_i = 0; dq_i < 8; dq_i = dq_i + 1) begin : gen_dq
            wire dq_out;
            wire dq_tri;
            wire dq_in;
            wire dq_delayed;
            wire q1;
            wire q2;
            wire q3;
            wire q4;
            wire q5;
            wire q6;
            wire q7;
            wire q8;
            wire unused_ofb;
            wire unused_shiftout1;
            wire unused_shiftout2;
            wire unused_tbyteout;
            wire unused_tfb;
            wire [4:0] unused_tap_count;

            if (ENABLE_TX != 0) begin : gen_tx
                OSERDESE2 #(
                    .DATA_RATE_OQ("DDR"),
                    .DATA_RATE_TQ("BUF"),
                    .DATA_WIDTH(8),
                    .INIT_OQ(1'b0),
                    .SERDES_MODE("MASTER"),
                    .TRISTATE_WIDTH(1)
                ) u_dq_oserdes (
                    .OFB(unused_ofb),
                    .OQ(dq_out),
                    .SHIFTOUT1(unused_shiftout1),
                    .SHIFTOUT2(unused_shiftout2),
                    .TBYTEOUT(unused_tbyteout),
                    .TFB(unused_tfb),
                    .TQ(dq_tri),
                    .CLK(i_clk_serdes),
                    .CLKDIV(i_clk_div),
                    .D1(i_dq_bits[(0*8) + dq_i]),
                    .D2(i_dq_bits[(1*8) + dq_i]),
                    .D3(i_dq_bits[(2*8) + dq_i]),
                    .D4(i_dq_bits[(3*8) + dq_i]),
                    .D5(i_dq_bits[(4*8) + dq_i]),
                    .D6(i_dq_bits[(5*8) + dq_i]),
                    .D7(i_dq_bits[(6*8) + dq_i]),
                    .D8(i_dq_bits[(7*8) + dq_i]),
                    .OCE(1'b1),
                    .RST(i_rst),
                    .SHIFTIN1(1'b0),
                    .SHIFTIN2(1'b0),
                    .T1(!i_dq_oe[0]),
                    .T2(1'b0),
                    .T3(1'b0),
                    .T4(1'b0),
                    .TBYTEIN(1'b0),
                    .TCE(1'b1)
                );
            end else begin : gen_no_tx
                assign dq_out = 1'b0;
                assign dq_tri = 1'b1;
            end

            IOBUF #(
                .IBUF_LOW_PWR("FALSE"),
                .SLEW("FAST")
            ) u_dq_iobuf (
                .I(dq_out),
                .O(dq_in),
                .T(dq_tri),
                .IO(io_dq[dq_i])
            );

            if (ENABLE_RX != 0) begin : gen_rx
                if (USE_IDELAY != 0) begin : gen_dq_rx_idelay
                    (* IODELAY_GROUP = "DDR3_SERDES_PROBE" *)
                    IDELAYE2 #(
                        .DELAY_SRC("IDATAIN"),
                        .HIGH_PERFORMANCE_MODE("TRUE"),
                        .IDELAY_TYPE("FIXED"),
                        .IDELAY_VALUE(IDELAY_TAPS),
                        .REFCLK_FREQUENCY(200.0),
                        .SIGNAL_PATTERN("DATA")
                    ) u_dq_idelay (
                        .CNTVALUEOUT(unused_tap_count),
                        .DATAOUT(dq_delayed),
                        .C(i_clk_div),
                        .CE(1'b0),
                        .CINVCTRL(1'b0),
                        .CNTVALUEIN(5'd0),
                        .DATAIN(1'b0),
                        .IDATAIN(dq_in),
                        .INC(1'b0),
                        .LD(1'b0),
                        .LDPIPEEN(1'b0),
                        .REGRST(i_rst)
                    );

                    ISERDESE2 #(
                        .DATA_RATE("DDR"),
                        .DATA_WIDTH(8),
                        .INIT_Q1(1'b0),
                        .INIT_Q2(1'b0),
                        .INIT_Q3(1'b0),
                        .INIT_Q4(1'b0),
                        .INTERFACE_TYPE("NETWORKING"),
                        .IOBDELAY("IFD"),
                        .NUM_CE(1),
                        .OFB_USED("FALSE"),
                        .SRVAL_Q1(1'b0),
                        .SRVAL_Q2(1'b0),
                        .SRVAL_Q3(1'b0),
                        .SRVAL_Q4(1'b0),
                        .SERDES_MODE("MASTER")
                    ) u_dq_iserdes (
                        .O(),
                        .Q1(q1),
                        .Q2(q2),
                        .Q3(q3),
                        .Q4(q4),
                        .Q5(q5),
                        .Q6(q6),
                        .Q7(q7),
                        .Q8(q8),
                        .SHIFTOUT1(),
                        .SHIFTOUT2(),
                        .BITSLIP(i_bitslip),
                        .CE1(1'b1),
                        .CE2(1'b1),
                        .CLK(i_clk_serdes),
                        .CLKB(clk_serdes_b),
                        .CLKDIV(i_clk_div),
                        .CLKDIVP(),
                        .D(),
                        .DDLY(dq_delayed),
                        .DYNCLKDIVSEL(),
                        .DYNCLKSEL(),
                        .OCLK(),
                        .OCLKB(),
                        .OFB(),
                        .RST(i_rst),
                        .SHIFTIN1(),
                        .SHIFTIN2()
                    );
                end else begin : gen_dq_rx_direct
                    assign unused_tap_count = 5'd0;

                    ISERDESE2 #(
                        .DATA_RATE("DDR"),
                        .DATA_WIDTH(8),
                        .INIT_Q1(1'b0),
                        .INIT_Q2(1'b0),
                        .INIT_Q3(1'b0),
                        .INIT_Q4(1'b0),
                        .INTERFACE_TYPE("NETWORKING"),
                        .IOBDELAY("NONE"),
                        .NUM_CE(1),
                        .OFB_USED("FALSE"),
                        .SRVAL_Q1(1'b0),
                        .SRVAL_Q2(1'b0),
                        .SRVAL_Q3(1'b0),
                        .SRVAL_Q4(1'b0),
                        .SERDES_MODE("MASTER")
                    ) u_dq_iserdes (
                        .O(),
                        .Q1(q1),
                        .Q2(q2),
                        .Q3(q3),
                        .Q4(q4),
                        .Q5(q5),
                        .Q6(q6),
                        .Q7(q7),
                        .Q8(q8),
                        .SHIFTOUT1(),
                        .SHIFTOUT2(),
                        .BITSLIP(i_bitslip),
                        .CE1(1'b1),
                        .CE2(1'b1),
                        .CLK(i_clk_serdes),
                        .CLKB(clk_serdes_b),
                        .CLKDIV(i_clk_div),
                        .CLKDIVP(),
                        .D(dq_in),
                        .DDLY(),
                        .DYNCLKDIVSEL(),
                        .DYNCLKSEL(),
                        .OCLK(),
                        .OCLKB(),
                        .OFB(),
                        .RST(i_rst),
                        .SHIFTIN1(),
                        .SHIFTIN2()
                    );
                end

                assign o_dq_bits[(0*8) + dq_i] = q1;
                assign o_dq_bits[(1*8) + dq_i] = q2;
                assign o_dq_bits[(2*8) + dq_i] = q3;
                assign o_dq_bits[(3*8) + dq_i] = q4;
                assign o_dq_bits[(4*8) + dq_i] = q5;
                assign o_dq_bits[(5*8) + dq_i] = q6;
                assign o_dq_bits[(6*8) + dq_i] = q7;
                assign o_dq_bits[(7*8) + dq_i] = q8;
            end else begin : gen_no_rx
                assign o_dq_bits[(0*8) + dq_i] = 1'b0;
                assign o_dq_bits[(1*8) + dq_i] = 1'b0;
                assign o_dq_bits[(2*8) + dq_i] = 1'b0;
                assign o_dq_bits[(3*8) + dq_i] = 1'b0;
                assign o_dq_bits[(4*8) + dq_i] = 1'b0;
                assign o_dq_bits[(5*8) + dq_i] = 1'b0;
                assign o_dq_bits[(6*8) + dq_i] = 1'b0;
                assign o_dq_bits[(7*8) + dq_i] = 1'b0;
            end
        end
    endgenerate

    wire dqs_out;
    wire dqs_tri;
    wire dqs_in;
    wire dqs_delayed;
    wire dqs_q1;
    wire dqs_q2;
    wire dqs_q3;
    wire dqs_q4;
    wire dqs_q5;
    wire dqs_q6;
    wire dqs_q7;
    wire dqs_q8;
    wire dqs_unused_ofb;
    wire dqs_unused_shiftout1;
    wire dqs_unused_shiftout2;
    wire dqs_unused_tbyteout;
    wire dqs_unused_tfb;
    wire [4:0] dqs_unused_tap_count;

    generate
        if (ENABLE_TX != 0) begin : gen_dqs_tx
            OSERDESE2 #(
                .DATA_RATE_OQ("DDR"),
                .DATA_RATE_TQ("BUF"),
                .DATA_WIDTH(8),
                .INIT_OQ(1'b1),
                .SERDES_MODE("MASTER"),
                .TRISTATE_WIDTH(1)
            ) u_dqs_oserdes (
                .OFB(dqs_unused_ofb),
                .OQ(dqs_out),
                .SHIFTOUT1(dqs_unused_shiftout1),
                .SHIFTOUT2(dqs_unused_shiftout2),
                .TBYTEOUT(dqs_unused_tbyteout),
                .TFB(dqs_unused_tfb),
                .TQ(dqs_tri),
                .CLK(i_clk_serdes),
                .CLKDIV(i_clk_div),
                .D1(i_dqs_bits[0]),
                .D2(i_dqs_bits[1]),
                .D3(i_dqs_bits[2]),
                .D4(i_dqs_bits[3]),
                .D5(i_dqs_bits[4]),
                .D6(i_dqs_bits[5]),
                .D7(i_dqs_bits[6]),
                .D8(i_dqs_bits[7]),
                .OCE(1'b1),
                .RST(i_rst),
                .SHIFTIN1(1'b0),
                .SHIFTIN2(1'b0),
                .T1(!i_dqs_oe[0]),
                .T2(1'b0),
                .T3(1'b0),
                .T4(1'b0),
                .TBYTEIN(1'b0),
                .TCE(1'b1)
            );
        end else begin : gen_dqs_no_tx
            assign dqs_out = 1'b0;
            assign dqs_tri = 1'b1;
        end
    endgenerate

    IOBUFDS #(
        .DIFF_TERM("FALSE"),
        .DQS_BIAS("FALSE"),
        .IOSTANDARD("SSTL15")
    ) u_dqs_iobuf (
        .O(dqs_in),
        .IO(io_dqs_p),
        .IOB(io_dqs_n),
        .I(dqs_out),
        .T(dqs_tri)
    );

    generate
        if (ENABLE_RX != 0) begin : gen_dqs_rx
            if (USE_IDELAY != 0) begin : gen_dqs_rx_idelay
                (* IODELAY_GROUP = "DDR3_SERDES_PROBE" *)
                IDELAYE2 #(
                    .DELAY_SRC("IDATAIN"),
                    .HIGH_PERFORMANCE_MODE("TRUE"),
                    .IDELAY_TYPE("FIXED"),
                    .IDELAY_VALUE(IDELAY_TAPS),
                    .REFCLK_FREQUENCY(200.0),
                    .SIGNAL_PATTERN("CLOCK")
                ) u_dqs_idelay (
                    .CNTVALUEOUT(dqs_unused_tap_count),
                    .DATAOUT(dqs_delayed),
                    .C(i_clk_div),
                    .CE(1'b0),
                    .CINVCTRL(1'b0),
                    .CNTVALUEIN(5'd0),
                    .DATAIN(1'b0),
                    .IDATAIN(dqs_in),
                    .INC(1'b0),
                    .LD(1'b0),
                    .LDPIPEEN(1'b0),
                    .REGRST(i_rst)
                );

                ISERDESE2 #(
                    .DATA_RATE("DDR"),
                    .DATA_WIDTH(8),
                    .INIT_Q1(1'b0),
                    .INIT_Q2(1'b0),
                    .INIT_Q3(1'b0),
                    .INIT_Q4(1'b0),
                    .INTERFACE_TYPE("NETWORKING"),
                    .IOBDELAY("IFD"),
                    .NUM_CE(1),
                    .OFB_USED("FALSE"),
                    .SRVAL_Q1(1'b0),
                    .SRVAL_Q2(1'b0),
                    .SRVAL_Q3(1'b0),
                    .SRVAL_Q4(1'b0),
                    .SERDES_MODE("MASTER")
                ) u_dqs_iserdes (
                    .O(),
                    .Q1(dqs_q1),
                    .Q2(dqs_q2),
                    .Q3(dqs_q3),
                    .Q4(dqs_q4),
                    .Q5(dqs_q5),
                    .Q6(dqs_q6),
                    .Q7(dqs_q7),
                    .Q8(dqs_q8),
                    .SHIFTOUT1(),
                    .SHIFTOUT2(),
                    .BITSLIP(i_bitslip),
                    .CE1(1'b1),
                    .CE2(1'b1),
                    .CLK(i_clk_serdes),
                    .CLKB(clk_serdes_b),
                    .CLKDIV(i_clk_div),
                    .CLKDIVP(),
                    .D(),
                    .DDLY(dqs_delayed),
                    .DYNCLKDIVSEL(),
                    .DYNCLKSEL(),
                    .OCLK(),
                    .OCLKB(),
                    .OFB(),
                    .RST(i_rst),
                    .SHIFTIN1(),
                    .SHIFTIN2()
                );
            end else begin : gen_dqs_rx_direct
                assign dqs_unused_tap_count = 5'd0;

                ISERDESE2 #(
                    .DATA_RATE("DDR"),
                    .DATA_WIDTH(8),
                    .INIT_Q1(1'b0),
                    .INIT_Q2(1'b0),
                    .INIT_Q3(1'b0),
                    .INIT_Q4(1'b0),
                    .INTERFACE_TYPE("NETWORKING"),
                    .IOBDELAY("NONE"),
                    .NUM_CE(1),
                    .OFB_USED("FALSE"),
                    .SRVAL_Q1(1'b0),
                    .SRVAL_Q2(1'b0),
                    .SRVAL_Q3(1'b0),
                    .SRVAL_Q4(1'b0),
                    .SERDES_MODE("MASTER")
                ) u_dqs_iserdes (
                    .O(),
                    .Q1(dqs_q1),
                    .Q2(dqs_q2),
                    .Q3(dqs_q3),
                    .Q4(dqs_q4),
                    .Q5(dqs_q5),
                    .Q6(dqs_q6),
                    .Q7(dqs_q7),
                    .Q8(dqs_q8),
                    .SHIFTOUT1(),
                    .SHIFTOUT2(),
                    .BITSLIP(i_bitslip),
                    .CE1(1'b1),
                    .CE2(1'b1),
                    .CLK(i_clk_serdes),
                    .CLKB(clk_serdes_b),
                    .CLKDIV(i_clk_div),
                    .CLKDIVP(),
                    .D(dqs_in),
                    .DDLY(),
                    .DYNCLKDIVSEL(),
                    .DYNCLKSEL(),
                    .OCLK(),
                    .OCLKB(),
                    .OFB(),
                    .RST(i_rst),
                    .SHIFTIN1(),
                    .SHIFTIN2()
                );
            end

            assign o_dqs_bits = {
                dqs_q8, dqs_q7, dqs_q6, dqs_q5,
                dqs_q4, dqs_q3, dqs_q2, dqs_q1
            };
        end else begin : gen_dqs_no_rx
            assign o_dqs_bits = 8'd0;
        end
    endgenerate
endmodule

`default_nettype wire

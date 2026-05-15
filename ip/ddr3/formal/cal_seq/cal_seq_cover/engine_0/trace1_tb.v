`ifndef VERILATOR
module testbench;
  reg [4095:0] vcdfile;
  reg clock;
`else
module testbench(input clock, output reg genclock);
  initial genclock = 1;
`endif
  reg genclock = 1;
  reg [31:0] cycle = 0;
  wire [0:0] PI_clk = clock;
  reg [0:0] PI_rst;
  cal_seq_wrapper UUT (
    .clk(PI_clk),
    .rst(PI_rst)
  );
`ifndef VERILATOR
  initial begin
    if ($value$plusargs("vcd=%s", vcdfile)) begin
      $dumpfile(vcdfile);
      $dumpvars(0, testbench);
    end
    #5 clock = 0;
    while (genclock) begin
      #5 clock = 0;
      #5 clock = 1;
    end
  end
`endif
  initial begin
`ifndef VERILATOR
    #1;
`endif
    // UUT.$auto$async2sync.\cc:107:execute$221  = 1'b0;
    // UUT.$auto$async2sync.\cc:116:execute$225  = 1'b1;
    // UUT.$auto$async2sync.\cc:116:execute$231  = 1'b1;
    // UUT.$auto$async2sync.\cc:116:execute$237  = 1'b1;
    UUT.dut.o_cal_done = 1'b0;
    UUT.dut.o_cal_error = 1'b0;
    UUT.dut.o_cal_error_code = 2'b00;
    UUT.dut.o_rdlvl_start = 1'b0;
    UUT.dut.o_state = 4'b0000;
    UUT.dut.o_wlvl_start = 1'b0;

    // state 0
    PI_rst = 1'b1;
    UUT.init_done = 1'b0;
    UUT.rdlvl_done = 1'b0;
    UUT.rdlvl_error = 1'b0;
    UUT.wlvl_done = 1'b0;
    UUT.wlvl_error = 1'b0;
  end
  always @(posedge clock) begin
    // state 1
    if (cycle == 0) begin
      PI_rst <= 1'b0;
      UUT.init_done <= 1'b0;
      UUT.rdlvl_done <= 1'b0;
      UUT.rdlvl_error <= 1'b0;
      UUT.wlvl_done <= 1'b0;
      UUT.wlvl_error <= 1'b0;
    end

    // state 2
    if (cycle == 1) begin
      PI_rst <= 1'b0;
      UUT.init_done <= 1'b1;
      UUT.rdlvl_done <= 1'b0;
      UUT.rdlvl_error <= 1'b0;
      UUT.wlvl_done <= 1'b0;
      UUT.wlvl_error <= 1'b0;
    end

    // state 3
    if (cycle == 2) begin
      PI_rst <= 1'b0;
      UUT.init_done <= 1'b1;
      UUT.rdlvl_done <= 1'b0;
      UUT.rdlvl_error <= 1'b0;
      UUT.wlvl_done <= 1'b0;
      UUT.wlvl_error <= 1'b0;
    end

    // state 4
    if (cycle == 3) begin
      PI_rst <= 1'b0;
      UUT.init_done <= 1'b0;
      UUT.rdlvl_done <= 1'b1;
      UUT.rdlvl_error <= 1'b0;
      UUT.wlvl_done <= 1'b1;
      UUT.wlvl_error <= 1'b0;
    end

    // state 5
    if (cycle == 4) begin
      PI_rst <= 1'b0;
      UUT.init_done <= 1'b1;
      UUT.rdlvl_done <= 1'b1;
      UUT.rdlvl_error <= 1'b0;
      UUT.wlvl_done <= 1'b1;
      UUT.wlvl_error <= 1'b1;
    end

    // state 6
    if (cycle == 5) begin
      PI_rst <= 1'b0;
      UUT.init_done <= 1'b0;
      UUT.rdlvl_done <= 1'b0;
      UUT.rdlvl_error <= 1'b1;
      UUT.wlvl_done <= 1'b0;
      UUT.wlvl_error <= 1'b0;
    end

    // state 7
    if (cycle == 6) begin
      PI_rst <= 1'b0;
      UUT.init_done <= 1'b0;
      UUT.rdlvl_done <= 1'b0;
      UUT.rdlvl_error <= 1'b0;
      UUT.wlvl_done <= 1'b0;
      UUT.wlvl_error <= 1'b0;
    end

    // state 8
    if (cycle == 7) begin
      PI_rst <= 1'b0;
      UUT.init_done <= 1'b0;
      UUT.rdlvl_done <= 1'b0;
      UUT.rdlvl_error <= 1'b0;
      UUT.wlvl_done <= 1'b0;
      UUT.wlvl_error <= 1'b0;
    end

    genclock <= cycle < 8;
    cycle <= cycle + 1;
  end
endmodule

// ddr3_cmd.vh — DDR3 command encoding (CS_n / RAS_n / CAS_n / WE_n).
//
// One macro per command. All assume CKE = 1 (so commands are evaluated).
// CKE = 0 + NOP = power-down entry (handled separately).
//
// Format is { CS_n, RAS_n, CAS_n, WE_n } — 4 bits, active-low semantics.

`ifndef DDR3_CMD_VH
`define DDR3_CMD_VH

`define DDR3_CMD_NOP       4'b0_1_1_1   // do nothing
`define DDR3_CMD_DES       4'b1_x_x_x   // device deselect (CS_n high; rest don't care)
`define DDR3_CMD_ACT       4'b0_0_1_1   // activate row
`define DDR3_CMD_PRE       4'b0_0_1_0   // precharge (A10=0 single bank, A10=1 all)
`define DDR3_CMD_READ      4'b0_1_0_1   // read (with optional auto-precharge via A10)
`define DDR3_CMD_WRITE     4'b0_1_0_0   // write (with optional auto-precharge via A10)
`define DDR3_CMD_MRS       4'b0_0_0_0   // mode register set
`define DDR3_CMD_REF       4'b0_0_0_1   // refresh
`define DDR3_CMD_ZQCL      4'b0_1_1_0   // ZQ calibration long (A10=1) or short (A10=0)

`endif

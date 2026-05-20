// Shared DDR3 command and timing constants for the clean-sheet controller.
//
// Keep board/device timing here so controller RTL, formal wrappers, and
// simulation benches do not grow their own private JEDEC constants.

`ifndef BONETTO_DDR3_PARAMS_VH
`define BONETTO_DDR3_PARAMS_VH

`define DDR3_BANK_BITS 3
`define DDR3_ROW_BITS  15
`define DDR3_ADDR_BITS 15

// DDR3 command encoding as {cs_n, ras_n, cas_n, we_n}.
`define DDR3_CMD_MRS 4'b0000
`define DDR3_CMD_REF 4'b0001
`define DDR3_CMD_PRE 4'b0010
`define DDR3_CMD_ACT 4'b0011
`define DDR3_CMD_WR  4'b0100
`define DDR3_CMD_RD  4'b0101
`define DDR3_CMD_ZQ  4'b0110
`define DDR3_CMD_NOP 4'b0111
`define DDR3_CMD_DES 4'b1111

// Mode registers for the first DDR3-800 bring-up target.
// MR0: BL8, sequential, CL=6, WR=6, DLL reset, DLL-on power down.
// MR1: DLL enabled, RZQ/6 drive, RTT_NOM disabled, AL=0, Qoff disabled.
// MR2: CWL=5, PASR full array, ASR/SRT disabled, RTT_WR disabled.
// MR3: MPR disabled.
`define DDR3_MR0_DDR800 15'h1520
`define DDR3_MR1_DDR800 15'h0000
`define DDR3_MR2_DDR800 15'h0000
`define DDR3_MR3_DDR800 15'h0000

// DDR3-800 CK domain waits. One command cycle is one 400 MHz CK period.
`define DDR3_800_TCK_PS             2500
`define DDR3_800_RESET_LOW_CYCLES   80400   // >200 us
`define DDR3_800_RESET_CKE_CYCLES   200000  // 500 us
`define DDR3_800_TXPR_CYCLES        80      // >170 ns
`define DDR3_800_TMRD_CYCLES        8       // >=4 tCK
`define DDR3_800_TMOD_CYCLES        16      // >=max(12 tCK, 15 ns)
`define DDR3_800_TZQINIT_CYCLES     640     // >512 tCK
`define DDR3_800_TRFC_CYCLES        80      // >160 ns for 2Gb
`define DDR3_800_TDLLK_CYCLES       512     // DLL lock after MR0 DLL reset
`define DDR3_800_TRCD_CYCLES        8
`define DDR3_800_TRP_CYCLES         8
`define DDR3_800_TRAS_CYCLES        20
`define DDR3_800_TRC_CYCLES         28
`define DDR3_800_TRRD_CYCLES        8
`define DDR3_800_TFAW_CYCLES        20
`define DDR3_800_TCCD_CYCLES        4
`define DDR3_800_TWTR_CYCLES        8
`define DDR3_800_TWTR_CMD_CYCLES    13      // CWL + BL/2 + tWTR for WR->RD
`define DDR3_800_TRTP_CYCLES        8
`define DDR3_800_TWR_CYCLES         8
`define DDR3_800_CWL_CYCLES         5
`define DDR3_800_CL_CYCLES          6

`endif

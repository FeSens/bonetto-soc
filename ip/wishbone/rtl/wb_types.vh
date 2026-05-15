// wb_types.vh — Shared Wishbone B4 pipelined definitions for every IP in the SoC.
// Per INVARIANTS.md item #3, changing any of these is a contract-level change.

`ifndef WB_TYPES_VH
`define WB_TYPES_VH

// Default dimensions. IPs may override at parameter level but every external
// bus crossing in this SoC uses these values; see soc_params.vh.

`define WB_DEFAULT_DATA_W 32
`define WB_DEFAULT_ADDR_W 30   // word-addressed; byte addr = adr<<2
`define WB_DEFAULT_SEL_W  (`WB_DEFAULT_DATA_W / 8)

// Port-bundle macros to keep IP-instantiation noise down. AW = word-addr width.

`define WB_SLAVE_PORTS(AW, DW)                                          \
    input  wire                  i_wb_cyc,                              \
    input  wire                  i_wb_stb,                              \
    input  wire                  i_wb_we,                               \
    input  wire [(AW)-1:0]       i_wb_adr,                              \
    input  wire [(DW)-1:0]       i_wb_dat,                              \
    input  wire [(DW)/8-1:0]     i_wb_sel,                              \
    output wire                  o_wb_stall,                            \
    output wire                  o_wb_ack,                              \
    output wire [(DW)-1:0]       o_wb_dat,                              \
    output wire                  o_wb_err

`define WB_MASTER_PORTS(AW, DW)                                         \
    output wire                  o_wb_cyc,                              \
    output wire                  o_wb_stb,                              \
    output wire                  o_wb_we,                               \
    output wire [(AW)-1:0]       o_wb_adr,                              \
    output wire [(DW)-1:0]       o_wb_dat,                              \
    output wire [(DW)/8-1:0]     o_wb_sel,                              \
    input  wire                  i_wb_stall,                            \
    input  wire                  i_wb_ack,                              \
    input  wire [(DW)-1:0]       i_wb_dat,                              \
    input  wire                  i_wb_err

`endif

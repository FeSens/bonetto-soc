// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_ddr3_init_top__Syms.h"


VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____2(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____3(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____4(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____5(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____6(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____7(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____8(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____10(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____11(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____12(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____13(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____14(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____16(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____18(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____19(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_sub__TOP__0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_sub__TOP__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+568,0,"done_or_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tb_ddr3_init_top", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+568,0,"done_or_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+569,0,"clk_phy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+569,0,"clk_50",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+570,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+801,0,"ROW_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+802,0,"BANK_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+803,0,"DQ_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+804,0,"DM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+804,0,"DQS_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+805,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+399,0,"reset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"odt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+402,0,"cs_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"ras_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+404,0,"cas_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+405,0,"we_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+406,0,"ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+407,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BIT(tracep,c+408,0,"init_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+409,0,"init_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+410,0,"init_error_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+411,0,"init_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+412,0,"addr_padded",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+571,0,"ck_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+572,0,"dq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+573,0,"dqs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+574,0,"dqs_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+806,0,"dm_tdqs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+806,0,"tdqs_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+575,0,"prev_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+807,0,"WB_DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+808,0,"WB_ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+809,0,"DDR3_PART",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+813,0,"SPEED_GRADE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+801,0,"ROW_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+802,0,"BANK_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+814,0,"COL_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+803,0,"DQ_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+569,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+569,0,"i_clk_phy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+570,0,"i_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+815,0,"i_wb_cyc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+815,0,"i_wb_stb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+815,0,"i_wb_we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+816,0,"i_wb_adr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 27,0);
    VL_TRACE_DECL_BUS(tracep,c+817,0,"i_wb_dat",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+818,0,"i_wb_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+413,0,"o_wb_stall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+414,0,"o_wb_ack",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+415,0,"o_wb_dat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+815,0,"o_wb_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+399,0,"o_ddr3_reset_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"o_ddr3_cke",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"o_ddr3_odt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+402,0,"o_ddr3_cs_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"o_ddr3_ras_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+404,0,"o_ddr3_cas_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+405,0,"o_ddr3_we_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+406,0,"o_ddr3_ba",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+407,0,"o_ddr3_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BIT(tracep,c+408,0,"o_init_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+409,0,"o_init_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+410,0,"o_init_error_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+411,0,"o_init_state",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+416,0,"init_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+417,0,"init_ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+418,0,"init_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BIT(tracep,c+419,0,"init_reset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+420,0,"init_cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+421,0,"init_odt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+819,0,"rt_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+820,0,"rt_ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+821,0,"rt_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BIT(tracep,c+822,0,"rt_reset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+822,0,"rt_cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+815,0,"rt_odt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+422,0,"sel_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+399,0,"sel_reset_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"sel_cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"sel_odt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+406,0,"sel_ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+407,0,"sel_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BIT(tracep,c+823,0,"accept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_init", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+801,0,"ROW_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+802,0,"BANK_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+824,0,"CMD_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+569,0,"i_clk_phy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+570,0,"i_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+419,0,"o_ddr3_reset_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+420,0,"o_ddr3_cke",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+421,0,"o_ddr3_odt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+416,0,"o_ddr3_cmd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+417,0,"o_ddr3_ba",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+418,0,"o_ddr3_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BIT(tracep,c+408,0,"o_init_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+409,0,"o_init_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+410,0,"o_init_error_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+411,0,"o_state",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+825,0,"S_PWR_ON",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+826,0,"S_RESET_HIGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+827,0,"S_CKE_HIGH_NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+828,0,"S_MR2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+829,0,"S_MR2_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+830,0,"S_MR3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+831,0,"S_MR3_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+832,0,"S_MR1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+833,0,"S_MR1_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+834,0,"S_MR0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+835,0,"S_MR0_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+836,0,"S_ZQCL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+837,0,"S_ZQ_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+838,0,"S_DLLK_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+839,0,"S_PRE_ALL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+840,0,"S_PRE_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+841,0,"S_FIRST_REF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+842,0,"S_REF_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+843,0,"S_DONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+844,0,"S_FAIL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+411,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+423,0,"wait_ctr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 23,0);
    VL_TRACE_DECL_BUS(tracep,c+845,0,"MR0_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+846,0,"MR1_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+847,0,"MR2_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+848,0,"MR3_VAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_micron", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"check_strict_mrbits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"check_strict_timing",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"feature_pasr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+850,0,"feature_truebl4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+850,0,"feature_odt_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+851,0,"PERTCKAVG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+399,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+569,0,"ck",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+571,0,"ck_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"cke",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+402,0,"cs_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"ras_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+404,0,"cas_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+405,0,"we_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+852,0,"dm_tdqs",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+406,0,"ba",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+407,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BUS(tracep,c+572,0,"dq",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+573,0,"dqs",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+574,0,"dqs_n",-1, VerilatedTraceSigDirection::INOUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+852,0,"tdqs_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"odt",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_DOUBLE(tracep,c+262,0,"tck_avg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_QUAD(tracep,c+264,0,"tck_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+424,0,"tch_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+426,0,"tcl_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+266,0,"tch_avg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+268,0,"tcl_avg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_QUAD(tracep,c+270,0,"tm_ck_pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+272,0,"tm_ck_neg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+274,0,"tjit_per_rtime",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+276,0,"tjit_cc_time",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+277,0,"terr_nper_rtime",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+279,0,"tjit_ch_rtime",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+281,0,"duty_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+283,0,"out_delay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);

    Vtb_ddr3_init_top___024root__trace_init_dtype____0(vlSelf, tracep, "dqsck", 0, c+853, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+854,0,"dqsck_min",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+855,0,"dqsck_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+856,0,"dqsq_min",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+857,0,"dqsq_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+139,0,"seed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mode_reg", VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+370+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (7 - i), 14,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+284,0,"burst_order",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+285,0,"burst_length",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+286,0,"blotf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+287,0,"truebl4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+288,0,"cas_latency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+289,0,"dll_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+290,0,"dll_locked",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+291,0,"write_recovery",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+292,0,"low_power",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+293,0,"dll_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+294,0,"odt_rtt_nom",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+295,0,"odt_rtt_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+296,0,"odt_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+297,0,"dyn_odt_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+298,0,"al",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"additive_latency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+300,0,"write_levelization",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+858,0,"duty_cycle_corrector",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+301,0,"tdqs_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"out_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"pasr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+304,0,"cas_write_latency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"asr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"srt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+307,0,"mpr_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+308,0,"mpr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+859,0,"odts_readout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"read_latency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"write_latency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+860,0,"LOAD_MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+861,0,"REFRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+862,0,"PRECHARGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+863,0,"ACTIVATE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+864,0,"WRITE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+865,0,"READ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+866,0,"ZQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+867,0,"NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+868,0,"PWR_DOWN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+869,0,"SELF_REF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);

    Vtb_ddr3_init_top___024root__trace_init_dtype____2(vlSelf, tracep, "cmd_string", 0, c+140, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+378,0,"active_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+379,0,"auto_precharge_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+311,0,"write_precharge_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+312,0,"read_precharge_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);

    Vtb_ddr3_init_top___024root__trace_init_dtype____3(vlSelf, tracep, "active_row", 0, c+313, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BIT(tracep,c+321,0,"in_power_down",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+322,0,"in_self_refresh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+323,0,"init_mode_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+324,0,"init_dll_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+325,0,"init_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+326,0,"init_step",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+327,0,"zq_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+328,0,"er_trfc_max",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+329,0,"odt_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+428,0,"odt_state_dly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+330,0,"dyn_odt_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+429,0,"dyn_odt_state_dly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+430,0,"prev_odt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+870,0,"calibration_pattern",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+871,0,"temp_sensor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+331,0,"mr_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+332,0,"rd_bc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+872,0,"banki",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+333,0,"ref_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+334,0,"odt_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+576,0,"ck_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+431,0,"ck_txpr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+432,0,"ck_load_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+433,0,"ck_refresh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+380,0,"ck_precharge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"ck_activate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"ck_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"ck_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"ck_zqinit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+438,0,"ck_zqoper",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+439,0,"ck_zqcs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+440,0,"ck_power_down",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+441,0,"ck_slow_exit_pd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+442,0,"ck_self_refresh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+443,0,"ck_freq_change",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+444,0,"ck_odt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+445,0,"ck_odth8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+446,0,"ck_dll_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+447,0,"ck_cke_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);

    Vtb_ddr3_init_top___024root__trace_init_dtype____4(vlSelf, tracep, "ck_bank_write", 0, c+448, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____5(vlSelf, tracep, "ck_bank_read", 0, c+456, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____6(vlSelf, tracep, "ck_group_activate", 0, c+464, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____7(vlSelf, tracep, "ck_group_write", 0, c+466, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____8(vlSelf, tracep, "ck_group_read", 0, c+468, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_QUAD(tracep,c+470,0,"tm_txpr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+472,0,"tm_load_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+474,0,"tm_refresh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+381,0,"tm_precharge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+476,0,"tm_activate",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+478,0,"tm_write_end",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+480,0,"tm_power_down",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+482,0,"tm_slow_exit_pd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+484,0,"tm_self_refresh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+486,0,"tm_freq_change",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+488,0,"tm_cke_cmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+873,0,"tm_ttsinit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_PUSH_PREFIX(tracep, "tm_bank_precharge", VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+383+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (7 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);

    Vtb_ddr3_init_top___024root__trace_init_dtype____10(vlSelf, tracep, "tm_bank_activate", 0, c+490, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____11(vlSelf, tracep, "tm_bank_write_end", 0, c+506, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____12(vlSelf, tracep, "tm_bank_read_end", 0, c+522, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____13(vlSelf, tracep, "tm_group_activate", 0, c+538, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____14(vlSelf, tracep, "tm_group_write_end", 0, c+542, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_QUAD(tracep,c+335,0,"al_pipeline",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 56,0);
    VL_TRACE_DECL_QUAD(tracep,c+337,0,"wr_pipeline",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 56,0);
    VL_TRACE_DECL_QUAD(tracep,c+339,0,"rd_pipeline",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 56,0);
    VL_TRACE_DECL_QUAD(tracep,c+341,0,"odt_pipeline",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 56,0);
    VL_TRACE_DECL_QUAD(tracep,c+343,0,"dyn_odt_pipeline",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 56,0);
    VL_TRACE_DECL_BIT(tracep,c+345,0,"prev_cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+346,0,"cmd_tran_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+875,0,"cmd_tran_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_QUAD(tracep,c+347,0,"cmd_tran_pipeline",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+349,0,"memory_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+351,0,"bit_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+353,0,"burst_position",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+354,0,"burst_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+355,0,"dq_temp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_QUAD(tracep,c+558,0,"check_write_postamble",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+560,0,"check_write_preamble",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+577,0,"check_write_dqs_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+562,0,"check_write_dqs_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+579,0,"check_dm_tdipw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+564,0,"check_dq_tdipw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_QUAD(tracep,c+580,0,"tm_rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+582,0,"tm_cke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+584,0,"tm_odt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+356,0,"tm_tdqss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, 63,0);
    VL_TRACE_PUSH_PREFIX(tracep, "tm_dm", VerilatedTracePrefixType::ARRAY_UNPACKED, 31, 0);
    for (int i = 0; i < 32; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+586+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (31 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);

    Vtb_ddr3_init_top___024root__trace_init_dtype____16(vlSelf, tracep, "tm_dqs", 0, c+650, VerilatedTraceSigDirection::NONE);
    VL_TRACE_PUSH_PREFIX(tracep, "tm_cmd_addr", VerilatedTracePrefixType::ARRAY_UNPACKED, 23, 0);
    for (int i = 0; i < 24; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+714+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (23 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);

    Vtb_ddr3_init_top___024root__trace_init_dtype____18(vlSelf, tracep, "cmd_addr_string", 0, c+170, VerilatedTraceSigDirection::NONE);

    Vtb_ddr3_init_top___024root__trace_init_dtype____19(vlSelf, tracep, "dqs_string", 0, c+218, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+876,0,"RFF_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+877,0,"RFF_CHUNK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+222,0,"tmp_model_dir",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1024,1);
    VL_TRACE_PUSH_PREFIX(tracep, "memfd", VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+254+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, (7 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+762,0,"rst_n_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+763,0,"ck_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+764,0,"ck_n_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+765,0,"cke_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+766,0,"cs_n_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+767,0,"ras_n_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+768,0,"cas_n_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+769,0,"we_n_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+770,0,"dm_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+771,0,"ba_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+772,0,"addr_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 16,0);
    VL_TRACE_DECL_WIDE(tracep,c+550,0,"dq_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_QUAD(tracep,c+554,0,"dqs_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BIT(tracep,c+773,0,"odt_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+774,0,"dm_in_pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+775,0,"dm_in_neg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+776,0,"dq_in_pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_WIDE(tracep,c+780,0,"dq_in_neg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BIT(tracep,c+358,0,"dq_in_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+546,0,"dqs_in_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+359,0,"wdqs_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+360,0,"wdq_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+547,0,"b2b_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+361,0,"wr_burst_length",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+784,0,"prev_dqs_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BIT(tracep,c+786,0,"diff_ck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+556,0,"dqs_even",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+557,0,"dqs_odd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+787,0,"cmd_n_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+362,0,"dqs_out_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+548,0,"dqs_out_en_dly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+363,0,"dqs_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+549,0,"dqs_out_dly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+364,0,"dq_out_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+788,0,"dq_out_en_dly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+365,0,"dq_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+789,0,"dq_out_dly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+366,0,"rdqsen_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+367,0,"rdqs_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+368,0,"rdqen_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+369,0,"rdq_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"open_bank_file__Vstatic__fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+24,0,"open_bank_file__Vstatic__filename",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2048,1);
    VL_TRACE_DECL_BUS(tracep,c+88,0,"read_from_file__Vstatic__code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+89,0,"read_from_file__Vstatic__offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+90,0,"read_from_file__Vstatic__msg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1024,1);
    VL_TRACE_DECL_QUAD(tracep,c+122,0,"read_from_file__Vstatic__read_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 64,1);
    VL_TRACE_DECL_BUS(tracep,c+124,0,"write_to_file__Vstatic__code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+125,0,"write_to_file__Vstatic__offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"memory_write__Vstatic__addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 24,0);
    VL_TRACE_DECL_BUS(tracep,c+127,0,"memory_read__Vstatic__addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 24,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"erase_banks__Vstatic__ba",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"erase_banks__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 24,0);
    VL_TRACE_DECL_BUS(tracep,c+128,0,"erase_banks__Vstatic__bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+129,0,"reset_task__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+878,0,"SAME_BANK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+879,0,"DIFF_BANK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+880,0,"DIFF_GROUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+881,0,"SIMUL_500US",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+882,0,"SIMUL_200US",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"chk_err__Vstatic__err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+130,0,"cmd_task__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 8,0);
    VL_TRACE_DECL_BUS(tracep,c+131,0,"cmd_task__Vstatic__j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+132,0,"cmd_task__Vstatic__tfaw_cntr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 8,0);
    VL_TRACE_DECL_BUS(tracep,c+133,0,"cmd_task__Vstatic__col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"cmd_task__Vstatic__group",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+134,0,"data_task__Vstatic__bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+135,0,"data_task__Vstatic__row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BUS(tracep,c+136,0,"data_task__Vstatic__col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+137,0,"data_task__Vstatic__i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"data_task__Vstatic__j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+790,0,"dqs_even_receiver__Vstatic__bit_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_WIDE(tracep,c+794,0,"dqs_odd_receiver__Vstatic__bit_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+798,0,"dqs_pos_timing_check__Vstatic__j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+799,0,"dqs_neg_timing_check__Vstatic__j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+883,0,"TCK_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+884,0,"TJIT_PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+885,0,"TJIT_CC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+886,0,"TERR_2PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+887,0,"TERR_3PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+888,0,"TERR_4PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+889,0,"TERR_5PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+890,0,"TERR_6PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+891,0,"TERR_7PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+892,0,"TERR_8PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+893,0,"TERR_9PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+894,0,"TERR_10PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+895,0,"TERR_11PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+896,0,"TERR_12PER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+897,0,"TDS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+898,0,"TDH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+899,0,"TDQSQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+900,0,"TDQSS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+902,0,"TDSS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+902,0,"TDSH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+904,0,"TDQSCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+905,0,"TQSH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+905,0,"TQSL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+907,0,"TDIPW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+908,0,"TIPW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+909,0,"TIS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+910,0,"TIH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+911,0,"TRAS_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+912,0,"TRC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+913,0,"TRCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+913,0,"TRP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+914,0,"TXP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+915,0,"TCKE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+916,0,"TAON",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+917,0,"TWLS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+917,0,"TWLH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+918,0,"TWLO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+913,0,"TAA_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+913,0,"CL_TIME",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+904,0,"TDQSCK_DLLDIS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+914,0,"TRRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+919,0,"TFAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+920,0,"CL_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+921,0,"CL_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+850,0,"AL_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"AL_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+920,0,"WR_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+877,0,"WR_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"BL_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+924,0,"BL_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+920,0,"CWL_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+897,0,"CWL_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+925,0,"TCK_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+926,0,"TCH_AVG_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+926,0,"TCL_AVG_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+928,0,"TCH_AVG_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+928,0,"TCL_AVG_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+930,0,"TCH_ABS_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+930,0,"TCL_ABS_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+932,0,"TCKE_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+933,0,"TAA_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+934,0,"TQH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+936,0,"TRPRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+938,0,"TRPST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+940,0,"TDQSH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+940,0,"TDQSL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+936,0,"TWPRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_DOUBLE(tracep,c+938,0,"TWPST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"TZQCS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"TZQINIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+7,0,"TZQOPER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"TCCD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"TCCD_DG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+942,0,"TRAS_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+944,0,"TWR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"TMRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+944,0,"TMOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+945,0,"TMOD_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"TRRD_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+946,0,"TRRD_DG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"TRRD_DG_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+918,0,"TRTP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"TRTP_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+918,0,"TWTR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+947,0,"TWTR_DG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"TWTR_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"TWTR_DG_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+851,0,"TDLLK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+948,0,"TRFC_MIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+949,0,"TRFC_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+932,0,"TXP_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+950,0,"TXPDLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+897,0,"TXPDLL_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"TACTPDEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"TPRPDEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"TREFPDEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"TCPDED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+949,0,"TPD_MAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+951,0,"TXPR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+920,0,"TXPR_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+951,0,"TXS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+920,0,"TXS_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+851,0,"TXSDLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+909,0,"TISXR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+952,0,"TCKSRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+920,0,"TCKSRE_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+952,0,"TCKSRX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+920,0,"TCKSRX_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"TCKESR_TCK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+953,0,"TAOF",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+955,0,"TAONPD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+955,0,"TAOFPD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"ODTH4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+956,0,"ODTH8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_DOUBLE(tracep,c+953,0,"TADC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE);
    VL_TRACE_DECL_BUS(tracep,c+957,0,"TWLMRD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+958,0,"TWLDQSEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+959,0,"TWLOE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"DM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+960,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+960,0,"ROW_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+897,0,"COL_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+924,0,"DQ_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"DQS_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+932,0,"BA_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+897,0,"MEM_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+897,0,"AP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+945,0,"BC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+932,0,"BL_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"BO_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"CS_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"RANKS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+961,0,"RZQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+962,0,"PRE_DEF_PAT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"STOP_ON_ERROR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"DEBUG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+850,0,"BUS_DELAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+850,0,"RANDOM_OUT_DELAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+963,0,"RANDOM_SEED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"RDQSEN_PRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"RDQSEN_PST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"RDQS_PRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"RDQS_PST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+850,0,"RDQEN_PRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+850,0,"RDQEN_PST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"WDQS_PRE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"WDQS_PST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"min_cl__Vstatic__cwl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"min_cl__Vstatic__cl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "file_io_open", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+13,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 27,0);
    VL_TRACE_DECL_QUAD(tracep,c+14,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_WIDE(tracep,c+16,0,"char",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+20,0,"in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"fio_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+800,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "main", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+138,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reset", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    for (int i = 0; i < 1; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, (0 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____1(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____1(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____1\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____1(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____1(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____1\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (7 - i), 14,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____2(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____2(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____2\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____2(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____2(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____2\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 9, 0);
    for (int i = 0; i < 10; ++i) {
        VL_TRACE_DECL_WIDE_ARRAY(tracep,c+0+i*3,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (9 - i), 71,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____3(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____3(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____3\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____3(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____3(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____3\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (7 - i), 14,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____4(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____4(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____4\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____4(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____4(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____4\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, (7 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____5(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____5(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____5\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____5(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____5(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____5\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, (7 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____6(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____6(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____6\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____6(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____6(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____6\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 1, 0);
    for (int i = 0; i < 2; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, (1 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____7(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____7(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____7\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____7(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____7(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____7\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 1, 0);
    for (int i = 0; i < 2; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, (1 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____8(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____8(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____8\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____8(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____8(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____8\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 1, 0);
    for (int i = 0; i < 2; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, (1 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____9(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____9(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____9\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____9(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____9(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____9\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (7 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____10(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____10(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____10\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____10(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____10(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____10\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (7 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____11(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____11(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____11\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____11(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____11(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____11\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (7 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____12(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____12(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____12\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____12(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____12(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____12\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (7 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____13(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____13(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____13\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____13(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____13(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____13\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 1, 0);
    for (int i = 0; i < 2; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (1 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____14(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____14(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____14\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____14(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____14(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____14\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 1, 0);
    for (int i = 0; i < 2; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (1 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____15(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____15(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____15\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____15(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____15(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____15\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 31, 0);
    for (int i = 0; i < 32; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (31 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____16(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____16(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____16\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____16(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____16(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____16\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 31, 0);
    for (int i = 0; i < 32; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (31 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____17(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____17(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____17\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____17(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____17(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____17\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 23, 0);
    for (int i = 0; i < 24; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::TIME, (23 - i), 63,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____18(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____18(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____18\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____18(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____18(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____18\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 23, 0);
    for (int i = 0; i < 24; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (23 - i), 55,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____19(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____19(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____19\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____19(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____19(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____19\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 1, 0);
    for (int i = 0; i < 2; ++i) {
        VL_TRACE_DECL_QUAD_ARRAY(tracep,c+0+i*2,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (1 - i), 39,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____20(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype____20(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype____20\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____20(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_dtype_sub____20(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_dtype_sub____20\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 7, 0);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, (7 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_init_top(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_init_top\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_ddr3_init_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_ddr3_init_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_register(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_register\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_ddr3_init_top___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtb_ddr3_init_top___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtb_ddr3_init_top___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtb_ddr3_init_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_const_0_sub_0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_const_0\n"); );
    // Body
    Vtb_ddr3_init_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_ddr3_init_top___024root*>(voidSelf);
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_ddr3_init_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_const_dtype____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 1>& __VdtypeVar);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_const_0_sub_0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_const_0_sub_0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+801,(0x0000000fU),32);
    bufp->fullIData(oldp+802,(3U),32);
    bufp->fullIData(oldp+803,(8U),32);
    bufp->fullIData(oldp+804,(1U),32);
    bufp->fullIData(oldp+805,(0x00000010U),32);
    bufp->fullBit(oldp+806,(0U));
    bufp->fullIData(oldp+807,(0x00000020U),32);
    bufp->fullIData(oldp+808,(0x0000001cU),32);
    __Vtemp_1[0U] = 0x2d313235U;
    __Vtemp_1[1U] = 0x4d384441U;
    __Vtemp_1[2U] = 0x4b323536U;
    __Vtemp_1[3U] = 0x4d543431U;
    bufp->fullWData(oldp+809,(__Vtemp_1),128);
    bufp->fullIData(oldp+813,(0x00000640U),32);
    bufp->fullIData(oldp+814,(0x0000000aU),32);
    bufp->fullBit(oldp+815,(0U));
    bufp->fullIData(oldp+816,(0U),28);
    bufp->fullIData(oldp+817,(0U),32);
    bufp->fullCData(oldp+818,(0U),4);
    bufp->fullCData(oldp+819,(7U),4);
    bufp->fullCData(oldp+820,(0U),3);
    bufp->fullSData(oldp+821,(0U),15);
    bufp->fullBit(oldp+822,(1U));
    bufp->fullBit(oldp+823,(0U));
    bufp->fullIData(oldp+824,(4U),32);
    bufp->fullCData(oldp+825,(0U),5);
    bufp->fullCData(oldp+826,(1U),5);
    bufp->fullCData(oldp+827,(2U),5);
    bufp->fullCData(oldp+828,(3U),5);
    bufp->fullCData(oldp+829,(4U),5);
    bufp->fullCData(oldp+830,(5U),5);
    bufp->fullCData(oldp+831,(6U),5);
    bufp->fullCData(oldp+832,(7U),5);
    bufp->fullCData(oldp+833,(8U),5);
    bufp->fullCData(oldp+834,(9U),5);
    bufp->fullCData(oldp+835,(0x0aU),5);
    bufp->fullCData(oldp+836,(0x0bU),5);
    bufp->fullCData(oldp+837,(0x0cU),5);
    bufp->fullCData(oldp+838,(0x0dU),5);
    bufp->fullCData(oldp+839,(0x0eU),5);
    bufp->fullCData(oldp+840,(0x0fU),5);
    bufp->fullCData(oldp+841,(0x10U),5);
    bufp->fullCData(oldp+842,(0x11U),5);
    bufp->fullCData(oldp+843,(0x12U),5);
    bufp->fullCData(oldp+844,(0x1fU),5);
    bufp->fullSData(oldp+845,(0x0d70U),16);
    bufp->fullSData(oldp+846,(0x0102U),16);
    bufp->fullSData(oldp+847,(0x0018U),16);
    bufp->fullSData(oldp+848,(0U),16);
    bufp->fullIData(oldp+849,(1U),32);
    bufp->fullIData(oldp+850,(0U),32);
    bufp->fullIData(oldp+851,(0x00000200U),32);
    bufp->fullBit(oldp+852,(0U));
    Vtb_ddr3_init_top___024root__trace_const_dtype____0(vlSelf, bufp, 853, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqsck);
    bufp->fullIData(oldp+854,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqsck_min),32);
    bufp->fullIData(oldp+855,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqsck_max),32);
    bufp->fullIData(oldp+856,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqsq_min),32);
    bufp->fullIData(oldp+857,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqsq_max),32);
    bufp->fullBit(oldp+858,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__duty_cycle_corrector));
    bufp->fullBit(oldp+859,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odts_readout));
    bufp->fullCData(oldp+860,(0U),4);
    bufp->fullCData(oldp+861,(1U),4);
    bufp->fullCData(oldp+862,(2U),4);
    bufp->fullCData(oldp+863,(3U),4);
    bufp->fullCData(oldp+864,(4U),4);
    bufp->fullCData(oldp+865,(5U),4);
    bufp->fullCData(oldp+866,(6U),4);
    bufp->fullCData(oldp+867,(7U),4);
    bufp->fullCData(oldp+868,(8U),4);
    bufp->fullCData(oldp+869,(9U),4);
    bufp->fullCData(oldp+870,(0xaaU),8);
    bufp->fullCData(oldp+871,(1U),8);
    bufp->fullIData(oldp+872,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__banki),32);
    bufp->fullQData(oldp+873,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ttsinit),64);
    bufp->fullCData(oldp+875,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_tran_i),6);
    bufp->fullIData(oldp+876,(0x00000040U),32);
    bufp->fullIData(oldp+877,(0x00000010U),32);
    bufp->fullCData(oldp+878,(0U),2);
    bufp->fullCData(oldp+879,(1U),2);
    bufp->fullCData(oldp+880,(2U),2);
    bufp->fullIData(oldp+881,(0x000001f4U),32);
    bufp->fullIData(oldp+882,(0x000000c8U),32);
    bufp->fullIData(oldp+883,(0x000004e2U),32);
    bufp->fullIData(oldp+884,(0x00000046U),32);
    bufp->fullIData(oldp+885,(0x0000008cU),32);
    bufp->fullIData(oldp+886,(0x00000067U),32);
    bufp->fullIData(oldp+887,(0x0000007aU),32);
    bufp->fullIData(oldp+888,(0x00000088U),32);
    bufp->fullIData(oldp+889,(0x00000093U),32);
    bufp->fullIData(oldp+890,(0x0000009bU),32);
    bufp->fullIData(oldp+891,(0x000000a3U),32);
    bufp->fullIData(oldp+892,(0x000000a9U),32);
    bufp->fullIData(oldp+893,(0x000000afU),32);
    bufp->fullIData(oldp+894,(0x000000b4U),32);
    bufp->fullIData(oldp+895,(0x000000b8U),32);
    bufp->fullIData(oldp+896,(0x000000bcU),32);
    bufp->fullIData(oldp+897,(0x0000000aU),32);
    bufp->fullIData(oldp+898,(0x0000002dU),32);
    bufp->fullIData(oldp+899,(0x00000064U),32);
    bufp->fullDouble(oldp+900,(2.70000000000000018e-01));
    bufp->fullDouble(oldp+902,(1.79999999999999993e-01));
    bufp->fullIData(oldp+904,(0x000000e1U),32);
    bufp->fullDouble(oldp+905,(4.00000000000000022e-01));
    bufp->fullIData(oldp+907,(0x00000168U),32);
    bufp->fullIData(oldp+908,(0x00000230U),32);
    bufp->fullIData(oldp+909,(0x000000aaU),32);
    bufp->fullIData(oldp+910,(0x00000078U),32);
    bufp->fullIData(oldp+911,(0x000088b8U),32);
    bufp->fullIData(oldp+912,(0x0000be6eU),32);
    bufp->fullIData(oldp+913,(0x000035b6U),32);
    bufp->fullIData(oldp+914,(0x00001770U),32);
    bufp->fullIData(oldp+915,(0x00001388U),32);
    bufp->fullIData(oldp+916,(0x000000faU),32);
    bufp->fullIData(oldp+917,(0x000000a5U),32);
    bufp->fullIData(oldp+918,(0x00001d4cU),32);
    bufp->fullIData(oldp+919,(0x00007530U),32);
    bufp->fullIData(oldp+920,(5U),32);
    bufp->fullIData(oldp+921,(0x0000000eU),32);
    bufp->fullIData(oldp+922,(2U),32);
    bufp->fullIData(oldp+923,(4U),32);
    bufp->fullIData(oldp+924,(8U),32);
    bufp->fullIData(oldp+925,(0x00000ce4U),32);
    bufp->fullDouble(oldp+926,(4.69999999999999973e-01));
    bufp->fullDouble(oldp+928,(5.30000000000000027e-01));
    bufp->fullDouble(oldp+930,(4.29999999999999993e-01));
    bufp->fullIData(oldp+932,(3U),32);
    bufp->fullIData(oldp+933,(0x00004e20U),32);
    bufp->fullDouble(oldp+934,(3.80000000000000004e-01));
    bufp->fullDouble(oldp+936,(9.00000000000000022e-01));
    bufp->fullDouble(oldp+938,(2.99999999999999989e-01));
    bufp->fullDouble(oldp+940,(4.50000000000000011e-01));
    bufp->fullDouble(oldp+942,(6.00000000000000000e+10));
    bufp->fullIData(oldp+944,(0x00003a98U),32);
    bufp->fullIData(oldp+945,(0x0000000cU),32);
    bufp->fullIData(oldp+946,(0x00000bb8U),32);
    bufp->fullIData(oldp+947,(0x00000ea6U),32);
    bufp->fullIData(oldp+948,(0x00027100U),32);
    bufp->fullIData(oldp+949,(0x042f2ac0U),32);
    bufp->fullIData(oldp+950,(0x00005dc0U),32);
    bufp->fullIData(oldp+951,(0x00029810U),32);
    bufp->fullIData(oldp+952,(0x00002710U),32);
    bufp->fullDouble(oldp+953,(6.99999999999999956e-01));
    bufp->fullIData(oldp+955,(0x00002134U),32);
    bufp->fullIData(oldp+956,(6U),32);
    bufp->fullIData(oldp+957,(0x00000028U),32);
    bufp->fullIData(oldp+958,(0x00000019U),32);
    bufp->fullIData(oldp+959,(0x000007d0U),32);
    bufp->fullIData(oldp+960,(0x0000000fU),32);
    bufp->fullIData(oldp+961,(0x000000f0U),32);
    bufp->fullCData(oldp+962,(0xaaU),8);
    bufp->fullIData(oldp+963,(0x00007ca9U),32);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_const_dtype____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 1>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_const_dtype____0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),32);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_0_sub_0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_0\n"); );
    // Body
    Vtb_ddr3_init_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_ddr3_init_top___024root*>(voidSelf);
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_ddr3_init_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<3>/*71:0*/, 10>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____1(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*55:0*/, 24>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____2(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*39:0*/, 2>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____3(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*14:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____4(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____5(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____6(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____7(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____8(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____9(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____10(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____11(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____12(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 2>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____13(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 2>& __VdtypeVar);
VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____14(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 32>& __VdtypeVar);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_0_sub_0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_0_sub_0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__ba),3);
    bufp->fullIData(oldp+1,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__i),25);
    bufp->fullBit(oldp+2,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__chk_err__Vstatic__err));
    bufp->fullBit(oldp+3,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__group));
    bufp->fullIData(oldp+4,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__j),32);
    bufp->fullIData(oldp+5,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQCS),32);
    bufp->fullIData(oldp+6,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQINIT),32);
    bufp->fullIData(oldp+7,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQOPER),32);
    bufp->fullCData(oldp+8,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__min_cl__Vstatic__cwl),4);
    bufp->fullCData(oldp+9,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__min_cl__Vstatic__cl),4);
    bufp->fullCData(oldp+10,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__bank),3);
    bufp->fullSData(oldp+11,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__row),15);
    bufp->fullSData(oldp+12,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__col),10);
    bufp->fullIData(oldp+13,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__addr),28);
    bufp->fullQData(oldp+14,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__data),64);
    bufp->fullWData(oldp+16,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__char),128);
    bufp->fullIData(oldp+20,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__in),32);
    bufp->fullIData(oldp+21,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__fio_status),32);
    bufp->fullIData(oldp+22,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__reset__DOT__i),32);
    bufp->fullIData(oldp+23,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd),32);
    bufp->fullWData(oldp+24,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename),2048);
    bufp->fullIData(oldp+88,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__code),32);
    bufp->fullIData(oldp+89,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__offset),32);
    bufp->fullWData(oldp+90,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__msg),1024);
    bufp->fullQData(oldp+122,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__read_value),64);
    bufp->fullIData(oldp+124,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_to_file__Vstatic__code),32);
    bufp->fullIData(oldp+125,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_to_file__Vstatic__offset),32);
    bufp->fullIData(oldp+126,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memory_write__Vstatic__addr),25);
    bufp->fullIData(oldp+127,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memory_read__Vstatic__addr),25);
    bufp->fullIData(oldp+128,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__bank),32);
    bufp->fullIData(oldp+129,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__reset_task__Vstatic__i),32);
    bufp->fullSData(oldp+130,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__i),9);
    bufp->fullIData(oldp+131,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__j),32);
    bufp->fullSData(oldp+132,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__tfaw_cntr),9);
    bufp->fullSData(oldp+133,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__col),10);
    bufp->fullCData(oldp+134,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__bank),3);
    bufp->fullSData(oldp+135,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__row),15);
    bufp->fullSData(oldp+136,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__col),10);
    bufp->fullIData(oldp+137,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__i),32);
    bufp->fullIData(oldp+138,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__main__DOT__i),32);
    bufp->fullIData(oldp+139,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__seed),32);
    Vtb_ddr3_init_top___024root__trace_full_dtype____0(vlSelf, bufp, 140, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string);
    Vtb_ddr3_init_top___024root__trace_full_dtype____1(vlSelf, bufp, 170, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string);
    Vtb_ddr3_init_top___024root__trace_full_dtype____2(vlSelf, bufp, 218, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string);
    bufp->fullWData(oldp+222,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir),1024);
    bufp->fullIData(oldp+254,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[7]),32);
    bufp->fullIData(oldp+255,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[6]),32);
    bufp->fullIData(oldp+256,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[5]),32);
    bufp->fullIData(oldp+257,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[4]),32);
    bufp->fullIData(oldp+258,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[3]),32);
    bufp->fullIData(oldp+259,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[2]),32);
    bufp->fullIData(oldp+260,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[1]),32);
    bufp->fullIData(oldp+261,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[0]),32);
    bufp->fullDouble(oldp+262,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg));
    bufp->fullQData(oldp+264,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_i),64);
    bufp->fullDouble(oldp+266,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tch_avg));
    bufp->fullDouble(oldp+268,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tcl_avg));
    bufp->fullQData(oldp+270,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos),64);
    bufp->fullQData(oldp+272,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg),64);
    bufp->fullDouble(oldp+274,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tjit_per_rtime));
    bufp->fullIData(oldp+276,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tjit_cc_time),32);
    bufp->fullDouble(oldp+277,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__terr_nper_rtime));
    bufp->fullDouble(oldp+279,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tjit_ch_rtime));
    bufp->fullDouble(oldp+281,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__duty_cycle));
    bufp->fullIData(oldp+283,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_delay),32);
    bufp->fullBit(oldp+284,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__burst_order));
    bufp->fullCData(oldp+285,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__burst_length),4);
    bufp->fullBit(oldp+286,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__blotf));
    bufp->fullBit(oldp+287,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__truebl4));
    bufp->fullIData(oldp+288,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_latency),32);
    bufp->fullBit(oldp+289,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_reset));
    bufp->fullBit(oldp+290,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked));
    bufp->fullIData(oldp+291,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_recovery),32);
    bufp->fullBit(oldp+292,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__low_power));
    bufp->fullBit(oldp+293,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_en));
    bufp->fullCData(oldp+294,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_rtt_nom),3);
    bufp->fullCData(oldp+295,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_rtt_wr),2);
    bufp->fullBit(oldp+296,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_en));
    bufp->fullBit(oldp+297,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_en));
    bufp->fullCData(oldp+298,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__al),2);
    bufp->fullIData(oldp+299,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__additive_latency),32);
    bufp->fullBit(oldp+300,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization));
    bufp->fullBit(oldp+301,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tdqs_en));
    bufp->fullBit(oldp+302,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_en));
    bufp->fullCData(oldp+303,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__pasr),3);
    bufp->fullIData(oldp+304,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_write_latency),32);
    bufp->fullBit(oldp+305,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__asr));
    bufp->fullBit(oldp+306,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__srt));
    bufp->fullCData(oldp+307,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mpr_select),2);
    bufp->fullBit(oldp+308,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mpr_en));
    bufp->fullIData(oldp+309,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_latency),32);
    bufp->fullIData(oldp+310,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_latency),32);
    bufp->fullCData(oldp+311,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_precharge_bank),8);
    bufp->fullCData(oldp+312,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_precharge_bank),8);
    Vtb_ddr3_init_top___024root__trace_full_dtype____3(vlSelf, bufp, 313, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__active_row);
    bufp->fullBit(oldp+321,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__in_power_down));
    bufp->fullBit(oldp+322,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__in_self_refresh));
    bufp->fullCData(oldp+323,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__init_mode_reg),4);
    bufp->fullBit(oldp+324,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__init_dll_reset));
    bufp->fullBit(oldp+325,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__init_done));
    bufp->fullIData(oldp+326,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__init_step),32);
    bufp->fullBit(oldp+327,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__zq_set));
    bufp->fullBit(oldp+328,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__er_trfc_max));
    bufp->fullBit(oldp+329,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_state));
    bufp->fullBit(oldp+330,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state));
    bufp->fullCData(oldp+331,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mr_chk),2);
    bufp->fullBit(oldp+332,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rd_bc));
    bufp->fullIData(oldp+333,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ref_cntr),32);
    bufp->fullIData(oldp+334,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_cntr),32);
    bufp->fullQData(oldp+335,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__al_pipeline),57);
    bufp->fullQData(oldp+337,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_pipeline),57);
    bufp->fullQData(oldp+339,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rd_pipeline),57);
    bufp->fullQData(oldp+341,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_pipeline),57);
    bufp->fullQData(oldp+343,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_pipeline),57);
    bufp->fullBit(oldp+345,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_cke));
    bufp->fullCData(oldp+346,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_tran_index),6);
    bufp->fullQData(oldp+347,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_tran_pipeline),64);
    bufp->fullQData(oldp+349,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memory_data),64);
    bufp->fullQData(oldp+351,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__bit_mask),64);
    bufp->fullCData(oldp+353,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__burst_position),3);
    bufp->fullCData(oldp+354,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__burst_cntr),4);
    bufp->fullCData(oldp+355,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_temp),8);
    bufp->fullQData(oldp+356,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_tdqss),64);
    bufp->fullBit(oldp+358,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_valid));
    bufp->fullIData(oldp+359,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_cntr),32);
    bufp->fullIData(oldp+360,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdq_cntr),32);
    bufp->fullCData(oldp+361,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length),4);
    bufp->fullBit(oldp+362,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en));
    bufp->fullBit(oldp+363,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out));
    bufp->fullBit(oldp+364,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en));
    bufp->fullCData(oldp+365,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out),8);
    bufp->fullIData(oldp+366,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rdqsen_cntr),32);
    bufp->fullIData(oldp+367,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rdqs_cntr),32);
    bufp->fullIData(oldp+368,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rdqen_cntr),32);
    bufp->fullIData(oldp+369,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rdq_cntr),32);
    bufp->fullSData(oldp+370,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[7]),15);
    bufp->fullSData(oldp+371,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[6]),15);
    bufp->fullSData(oldp+372,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[5]),15);
    bufp->fullSData(oldp+373,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[4]),15);
    bufp->fullSData(oldp+374,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[3]),15);
    bufp->fullSData(oldp+375,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[2]),15);
    bufp->fullSData(oldp+376,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[1]),15);
    bufp->fullSData(oldp+377,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[0]),15);
    bufp->fullCData(oldp+378,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__active_bank),8);
    bufp->fullCData(oldp+379,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank),8);
    bufp->fullIData(oldp+380,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge),32);
    bufp->fullQData(oldp+381,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge),64);
    bufp->fullQData(oldp+383,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[7]),64);
    bufp->fullQData(oldp+385,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[6]),64);
    bufp->fullQData(oldp+387,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[5]),64);
    bufp->fullQData(oldp+389,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[4]),64);
    bufp->fullQData(oldp+391,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[3]),64);
    bufp->fullQData(oldp+393,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[2]),64);
    bufp->fullQData(oldp+395,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[1]),64);
    bufp->fullQData(oldp+397,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[0]),64);
    bufp->fullBit(oldp+399,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done) 
                             | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n))));
    bufp->fullBit(oldp+400,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done) 
                             | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cke))));
    bufp->fullBit(oldp+401,(((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done)) 
                             & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_odt))));
    bufp->fullBit(oldp+402,((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                   >> 3U))));
    bufp->fullBit(oldp+403,((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                   >> 2U))));
    bufp->fullBit(oldp+404,((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                   >> 1U))));
    bufp->fullBit(oldp+405,((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd))));
    bufp->fullCData(oldp+406,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_ba) 
                               & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done))))))),3);
    bufp->fullSData(oldp+407,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_addr) 
                               & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done))))))),15);
    bufp->fullBit(oldp+408,(vlSelfRef.tb_ddr3_init_top__DOT__init_done));
    bufp->fullBit(oldp+409,(vlSelfRef.tb_ddr3_init_top__DOT__init_error));
    bufp->fullCData(oldp+410,(vlSelfRef.tb_ddr3_init_top__DOT__init_error_code),4);
    bufp->fullCData(oldp+411,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state),5);
    bufp->fullSData(oldp+412,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_addr) 
                               & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done))))))),16);
    bufp->fullBit(oldp+413,((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done)))));
    bufp->fullBit(oldp+414,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack));
    bufp->fullIData(oldp+415,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_dat),32);
    bufp->fullCData(oldp+416,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd),4);
    bufp->fullCData(oldp+417,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_ba),3);
    bufp->fullSData(oldp+418,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_addr),15);
    bufp->fullBit(oldp+419,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n));
    bufp->fullBit(oldp+420,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cke));
    bufp->fullBit(oldp+421,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_odt));
    bufp->fullCData(oldp+422,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd),4);
    bufp->fullIData(oldp+423,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr),24);
    bufp->fullQData(oldp+424,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tch_i),64);
    bufp->fullQData(oldp+426,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i),64);
    bufp->fullBit(oldp+428,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly));
    bufp->fullBit(oldp+429,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly));
    bufp->fullBit(oldp+430,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt));
    bufp->fullIData(oldp+431,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr),32);
    bufp->fullIData(oldp+432,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode),32);
    bufp->fullIData(oldp+433,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh),32);
    bufp->fullIData(oldp+434,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate),32);
    bufp->fullIData(oldp+435,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_write),32);
    bufp->fullIData(oldp+436,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_read),32);
    bufp->fullIData(oldp+437,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit),32);
    bufp->fullIData(oldp+438,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper),32);
    bufp->fullIData(oldp+439,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs),32);
    bufp->fullIData(oldp+440,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down),32);
    bufp->fullIData(oldp+441,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd),32);
    bufp->fullIData(oldp+442,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh),32);
    bufp->fullIData(oldp+443,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change),32);
    bufp->fullIData(oldp+444,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt),32);
    bufp->fullIData(oldp+445,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8),32);
    bufp->fullIData(oldp+446,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset),32);
    bufp->fullIData(oldp+447,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd),32);
    Vtb_ddr3_init_top___024root__trace_full_dtype____4(vlSelf, bufp, 448, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write);
    Vtb_ddr3_init_top___024root__trace_full_dtype____5(vlSelf, bufp, 456, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read);
    Vtb_ddr3_init_top___024root__trace_full_dtype____6(vlSelf, bufp, 464, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate);
    Vtb_ddr3_init_top___024root__trace_full_dtype____7(vlSelf, bufp, 466, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write);
    Vtb_ddr3_init_top___024root__trace_full_dtype____8(vlSelf, bufp, 468, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read);
    bufp->fullQData(oldp+470,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr),64);
    bufp->fullQData(oldp+472,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode),64);
    bufp->fullQData(oldp+474,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh),64);
    bufp->fullQData(oldp+476,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate),64);
    bufp->fullQData(oldp+478,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end),64);
    bufp->fullQData(oldp+480,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down),64);
    bufp->fullQData(oldp+482,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd),64);
    bufp->fullQData(oldp+484,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh),64);
    bufp->fullQData(oldp+486,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change),64);
    bufp->fullQData(oldp+488,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd),64);
    Vtb_ddr3_init_top___024root__trace_full_dtype____9(vlSelf, bufp, 490, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate);
    Vtb_ddr3_init_top___024root__trace_full_dtype____10(vlSelf, bufp, 506, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end);
    Vtb_ddr3_init_top___024root__trace_full_dtype____11(vlSelf, bufp, 522, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end);
    Vtb_ddr3_init_top___024root__trace_full_dtype____12(vlSelf, bufp, 538, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate);
    Vtb_ddr3_init_top___024root__trace_full_dtype____13(vlSelf, bufp, 542, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end);
    bufp->fullBit(oldp+546,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid));
    bufp->fullBit(oldp+547,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write));
    bufp->fullBit(oldp+548,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly));
    bufp->fullBit(oldp+549,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly));
    bufp->fullWData(oldp+550,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in),128);
    bufp->fullQData(oldp+554,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in),64);
    bufp->fullIData(oldp+556,((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in)),32);
    bufp->fullIData(oldp+557,((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                       >> 0x00000020U))),32);
    bufp->fullQData(oldp+558,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble),64);
    bufp->fullQData(oldp+560,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble),64);
    bufp->fullQData(oldp+562,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low),64);
    bufp->fullWData(oldp+564,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw),128);
    bufp->fullBit(oldp+568,(vlSelfRef.done_or_err));
    bufp->fullBit(oldp+569,(vlSelfRef.tb_ddr3_init_top__DOT__clk_phy));
    bufp->fullBit(oldp+570,(vlSelfRef.tb_ddr3_init_top__DOT__rst));
    bufp->fullBit(oldp+571,((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__clk_phy)))));
    bufp->fullCData(oldp+572,((0x000000ffU & ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en)) 
                                              | ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly) 
                                                 & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en))))),8);
    bufp->fullBit(oldp+573,((1U & ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en)) 
                                   | ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly) 
                                      & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en))))));
    bufp->fullBit(oldp+574,(((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly)) 
                             & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en))));
    bufp->fullCData(oldp+575,(vlSelfRef.tb_ddr3_init_top__DOT__prev_state),5);
    bufp->fullIData(oldp+576,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr),32);
    bufp->fullQData(oldp+577,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high),64);
    bufp->fullIData(oldp+579,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw),32);
    bufp->fullQData(oldp+580,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_rst_n),64);
    bufp->fullQData(oldp+582,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke),64);
    bufp->fullQData(oldp+584,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_odt),64);
    bufp->fullQData(oldp+586,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[31]),64);
    bufp->fullQData(oldp+588,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[30]),64);
    bufp->fullQData(oldp+590,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[29]),64);
    bufp->fullQData(oldp+592,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[28]),64);
    bufp->fullQData(oldp+594,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[27]),64);
    bufp->fullQData(oldp+596,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[26]),64);
    bufp->fullQData(oldp+598,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[25]),64);
    bufp->fullQData(oldp+600,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[24]),64);
    bufp->fullQData(oldp+602,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[23]),64);
    bufp->fullQData(oldp+604,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[22]),64);
    bufp->fullQData(oldp+606,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[21]),64);
    bufp->fullQData(oldp+608,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[20]),64);
    bufp->fullQData(oldp+610,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[19]),64);
    bufp->fullQData(oldp+612,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[18]),64);
    bufp->fullQData(oldp+614,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[17]),64);
    bufp->fullQData(oldp+616,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[16]),64);
    bufp->fullQData(oldp+618,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[15]),64);
    bufp->fullQData(oldp+620,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[14]),64);
    bufp->fullQData(oldp+622,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[13]),64);
    bufp->fullQData(oldp+624,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[12]),64);
    bufp->fullQData(oldp+626,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[11]),64);
    bufp->fullQData(oldp+628,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[10]),64);
    bufp->fullQData(oldp+630,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[9]),64);
    bufp->fullQData(oldp+632,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[8]),64);
    bufp->fullQData(oldp+634,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[7]),64);
    bufp->fullQData(oldp+636,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[6]),64);
    bufp->fullQData(oldp+638,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[5]),64);
    bufp->fullQData(oldp+640,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[4]),64);
    bufp->fullQData(oldp+642,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[3]),64);
    bufp->fullQData(oldp+644,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[2]),64);
    bufp->fullQData(oldp+646,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[1]),64);
    bufp->fullQData(oldp+648,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[0]),64);
    Vtb_ddr3_init_top___024root__trace_full_dtype____14(vlSelf, bufp, 650, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs);
    bufp->fullQData(oldp+714,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[23]),64);
    bufp->fullQData(oldp+716,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[22]),64);
    bufp->fullQData(oldp+718,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[21]),64);
    bufp->fullQData(oldp+720,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[20]),64);
    bufp->fullQData(oldp+722,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[19]),64);
    bufp->fullQData(oldp+724,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[18]),64);
    bufp->fullQData(oldp+726,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[17]),64);
    bufp->fullQData(oldp+728,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[16]),64);
    bufp->fullQData(oldp+730,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[15]),64);
    bufp->fullQData(oldp+732,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[14]),64);
    bufp->fullQData(oldp+734,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[13]),64);
    bufp->fullQData(oldp+736,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[12]),64);
    bufp->fullQData(oldp+738,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[11]),64);
    bufp->fullQData(oldp+740,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[10]),64);
    bufp->fullQData(oldp+742,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[9]),64);
    bufp->fullQData(oldp+744,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[8]),64);
    bufp->fullQData(oldp+746,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[7]),64);
    bufp->fullQData(oldp+748,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[6]),64);
    bufp->fullQData(oldp+750,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[5]),64);
    bufp->fullQData(oldp+752,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[4]),64);
    bufp->fullQData(oldp+754,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[3]),64);
    bufp->fullQData(oldp+756,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[2]),64);
    bufp->fullQData(oldp+758,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[1]),64);
    bufp->fullQData(oldp+760,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[0]),64);
    bufp->fullBit(oldp+762,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in));
    bufp->fullBit(oldp+763,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_in));
    bufp->fullBit(oldp+764,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in));
    bufp->fullBit(oldp+765,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cke_in));
    bufp->fullBit(oldp+766,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in));
    bufp->fullBit(oldp+767,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in));
    bufp->fullBit(oldp+768,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in));
    bufp->fullBit(oldp+769,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in));
    bufp->fullIData(oldp+770,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in),32);
    bufp->fullCData(oldp+771,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ba_in),3);
    bufp->fullIData(oldp+772,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in),17);
    bufp->fullBit(oldp+773,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_in));
    bufp->fullIData(oldp+774,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in_pos),32);
    bufp->fullIData(oldp+775,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in_neg),32);
    bufp->fullWData(oldp+776,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_pos),128);
    bufp->fullWData(oldp+780,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_neg),128);
    bufp->fullQData(oldp+784,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in),64);
    bufp->fullBit(oldp+786,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
    bufp->fullCData(oldp+787,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_n_in),4);
    bufp->fullCData(oldp+788,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly),8);
    bufp->fullCData(oldp+789,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly),8);
    bufp->fullWData(oldp+790,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_even_receiver__Vstatic__bit_mask),128);
    bufp->fullWData(oldp+794,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_odd_receiver__Vstatic__bit_mask),128);
    bufp->fullCData(oldp+798,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j),5);
    bufp->fullCData(oldp+799,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j),5);
    bufp->fullIData(oldp+800,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__i),32);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<3>/*71:0*/, 10>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullWData(oldp+0,(__VdtypeVar[9]),72);
    bufp->fullWData(oldp+3,(__VdtypeVar[8]),72);
    bufp->fullWData(oldp+6,(__VdtypeVar[7]),72);
    bufp->fullWData(oldp+9,(__VdtypeVar[6]),72);
    bufp->fullWData(oldp+12,(__VdtypeVar[5]),72);
    bufp->fullWData(oldp+15,(__VdtypeVar[4]),72);
    bufp->fullWData(oldp+18,(__VdtypeVar[3]),72);
    bufp->fullWData(oldp+21,(__VdtypeVar[2]),72);
    bufp->fullWData(oldp+24,(__VdtypeVar[1]),72);
    bufp->fullWData(oldp+27,(__VdtypeVar[0]),72);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____1(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*55:0*/, 24>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____1\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullQData(oldp+0,(__VdtypeVar[23]),56);
    bufp->fullQData(oldp+2,(__VdtypeVar[22]),56);
    bufp->fullQData(oldp+4,(__VdtypeVar[21]),56);
    bufp->fullQData(oldp+6,(__VdtypeVar[20]),56);
    bufp->fullQData(oldp+8,(__VdtypeVar[19]),56);
    bufp->fullQData(oldp+10,(__VdtypeVar[18]),56);
    bufp->fullQData(oldp+12,(__VdtypeVar[17]),56);
    bufp->fullQData(oldp+14,(__VdtypeVar[16]),56);
    bufp->fullQData(oldp+16,(__VdtypeVar[15]),56);
    bufp->fullQData(oldp+18,(__VdtypeVar[14]),56);
    bufp->fullQData(oldp+20,(__VdtypeVar[13]),56);
    bufp->fullQData(oldp+22,(__VdtypeVar[12]),56);
    bufp->fullQData(oldp+24,(__VdtypeVar[11]),56);
    bufp->fullQData(oldp+26,(__VdtypeVar[10]),56);
    bufp->fullQData(oldp+28,(__VdtypeVar[9]),56);
    bufp->fullQData(oldp+30,(__VdtypeVar[8]),56);
    bufp->fullQData(oldp+32,(__VdtypeVar[7]),56);
    bufp->fullQData(oldp+34,(__VdtypeVar[6]),56);
    bufp->fullQData(oldp+36,(__VdtypeVar[5]),56);
    bufp->fullQData(oldp+38,(__VdtypeVar[4]),56);
    bufp->fullQData(oldp+40,(__VdtypeVar[3]),56);
    bufp->fullQData(oldp+42,(__VdtypeVar[2]),56);
    bufp->fullQData(oldp+44,(__VdtypeVar[1]),56);
    bufp->fullQData(oldp+46,(__VdtypeVar[0]),56);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____2(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*39:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____2\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullQData(oldp+0,(__VdtypeVar[1]),40);
    bufp->fullQData(oldp+2,(__VdtypeVar[0]),40);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____3(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*14:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____3\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullSData(oldp+0,(__VdtypeVar[7]),15);
    bufp->fullSData(oldp+1,(__VdtypeVar[6]),15);
    bufp->fullSData(oldp+2,(__VdtypeVar[5]),15);
    bufp->fullSData(oldp+3,(__VdtypeVar[4]),15);
    bufp->fullSData(oldp+4,(__VdtypeVar[3]),15);
    bufp->fullSData(oldp+5,(__VdtypeVar[2]),15);
    bufp->fullSData(oldp+6,(__VdtypeVar[1]),15);
    bufp->fullSData(oldp+7,(__VdtypeVar[0]),15);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____4(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____4\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[0]),32);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____5(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____5\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[0]),32);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____6(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____6\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[0]),32);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____7(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____7\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[0]),32);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____8(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____8\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[0]),32);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____9(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____9\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullQData(oldp+0,(__VdtypeVar[7]),64);
    bufp->fullQData(oldp+2,(__VdtypeVar[6]),64);
    bufp->fullQData(oldp+4,(__VdtypeVar[5]),64);
    bufp->fullQData(oldp+6,(__VdtypeVar[4]),64);
    bufp->fullQData(oldp+8,(__VdtypeVar[3]),64);
    bufp->fullQData(oldp+10,(__VdtypeVar[2]),64);
    bufp->fullQData(oldp+12,(__VdtypeVar[1]),64);
    bufp->fullQData(oldp+14,(__VdtypeVar[0]),64);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____10(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____10\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullQData(oldp+0,(__VdtypeVar[7]),64);
    bufp->fullQData(oldp+2,(__VdtypeVar[6]),64);
    bufp->fullQData(oldp+4,(__VdtypeVar[5]),64);
    bufp->fullQData(oldp+6,(__VdtypeVar[4]),64);
    bufp->fullQData(oldp+8,(__VdtypeVar[3]),64);
    bufp->fullQData(oldp+10,(__VdtypeVar[2]),64);
    bufp->fullQData(oldp+12,(__VdtypeVar[1]),64);
    bufp->fullQData(oldp+14,(__VdtypeVar[0]),64);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____11(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____11\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullQData(oldp+0,(__VdtypeVar[7]),64);
    bufp->fullQData(oldp+2,(__VdtypeVar[6]),64);
    bufp->fullQData(oldp+4,(__VdtypeVar[5]),64);
    bufp->fullQData(oldp+6,(__VdtypeVar[4]),64);
    bufp->fullQData(oldp+8,(__VdtypeVar[3]),64);
    bufp->fullQData(oldp+10,(__VdtypeVar[2]),64);
    bufp->fullQData(oldp+12,(__VdtypeVar[1]),64);
    bufp->fullQData(oldp+14,(__VdtypeVar[0]),64);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____12(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____12\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullQData(oldp+0,(__VdtypeVar[1]),64);
    bufp->fullQData(oldp+2,(__VdtypeVar[0]),64);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____13(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____13\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullQData(oldp+0,(__VdtypeVar[1]),64);
    bufp->fullQData(oldp+2,(__VdtypeVar[0]),64);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root__trace_full_dtype____14(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_full_dtype____14\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullQData(oldp+0,(__VdtypeVar[31]),64);
    bufp->fullQData(oldp+2,(__VdtypeVar[30]),64);
    bufp->fullQData(oldp+4,(__VdtypeVar[29]),64);
    bufp->fullQData(oldp+6,(__VdtypeVar[28]),64);
    bufp->fullQData(oldp+8,(__VdtypeVar[27]),64);
    bufp->fullQData(oldp+10,(__VdtypeVar[26]),64);
    bufp->fullQData(oldp+12,(__VdtypeVar[25]),64);
    bufp->fullQData(oldp+14,(__VdtypeVar[24]),64);
    bufp->fullQData(oldp+16,(__VdtypeVar[23]),64);
    bufp->fullQData(oldp+18,(__VdtypeVar[22]),64);
    bufp->fullQData(oldp+20,(__VdtypeVar[21]),64);
    bufp->fullQData(oldp+22,(__VdtypeVar[20]),64);
    bufp->fullQData(oldp+24,(__VdtypeVar[19]),64);
    bufp->fullQData(oldp+26,(__VdtypeVar[18]),64);
    bufp->fullQData(oldp+28,(__VdtypeVar[17]),64);
    bufp->fullQData(oldp+30,(__VdtypeVar[16]),64);
    bufp->fullQData(oldp+32,(__VdtypeVar[15]),64);
    bufp->fullQData(oldp+34,(__VdtypeVar[14]),64);
    bufp->fullQData(oldp+36,(__VdtypeVar[13]),64);
    bufp->fullQData(oldp+38,(__VdtypeVar[12]),64);
    bufp->fullQData(oldp+40,(__VdtypeVar[11]),64);
    bufp->fullQData(oldp+42,(__VdtypeVar[10]),64);
    bufp->fullQData(oldp+44,(__VdtypeVar[9]),64);
    bufp->fullQData(oldp+46,(__VdtypeVar[8]),64);
    bufp->fullQData(oldp+48,(__VdtypeVar[7]),64);
    bufp->fullQData(oldp+50,(__VdtypeVar[6]),64);
    bufp->fullQData(oldp+52,(__VdtypeVar[5]),64);
    bufp->fullQData(oldp+54,(__VdtypeVar[4]),64);
    bufp->fullQData(oldp+56,(__VdtypeVar[3]),64);
    bufp->fullQData(oldp+58,(__VdtypeVar[2]),64);
    bufp->fullQData(oldp+60,(__VdtypeVar[1]),64);
    bufp->fullQData(oldp+62,(__VdtypeVar[0]),64);
}

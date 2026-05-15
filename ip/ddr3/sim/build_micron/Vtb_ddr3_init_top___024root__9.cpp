// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ddr3_init_top.h for the primary calling header

#include "Vtb_ddr3_init_top__pch.h"

void Vtb_ddr3_init_top___024root___nba_comb__TOP__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_comb__TOP__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_en) 
           & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly));
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs 
        = (1U & ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en)) 
                 | ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly) 
                    & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en))));
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n 
        = ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly)) 
           & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en));
}

void Vtb_ddr3_init_top___024root___nba_comb__TOP__1(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_comb__TOP__1\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_n_in 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in)
            ? 7U : (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in) 
                     << 2U) | (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in) 
                                << 1U) | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in))));
}

void Vtb_ddr3_init_top___024root___nba_comb__TOP__2(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_comb__TOP__2\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly) 
           & (- (IData)((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_en))));
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq 
        = (0x000000ffU & ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en)) 
                          | ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly) 
                             & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en))));
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__0(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__1(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__2(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__3(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__4(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__5(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__6(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__7(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__8(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__9(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__10(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__11(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__12(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__13(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__14(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__15(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__16(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__17(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__18(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__19(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__20(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__21(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___nba_sequent__TOP__22(Vtb_ddr3_init_top___024root* vlSelf);

void Vtb_ddr3_init_top___024root___eval_nba(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_nba\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((0x1800000000000000ULL & vlSelfRef.__VnbaTriggered[5U])) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x3000000000000000ULL & vlSelfRef.__VnbaTriggered[5U])) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x5000000000000000ULL & vlSelfRef.__VnbaTriggered[5U])) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__5(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (8ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__6(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x0000000000000010ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__7(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x0000000000000020ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__8(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x0000000000000040ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__9(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x0000000000000180ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__10(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x0000000000000200ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x9000000000000000ULL & vlSelfRef.__VnbaTriggered[5U])) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__12(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (1ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__13(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (2ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__14(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (4ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__15(vlSelf);
    }
    if ((((0x17ffffffffffffffULL & vlSelfRef.__VnbaTriggered[5U]) 
          | (0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered[6U])) 
         | (0xf800000000000000ULL & vlSelfRef.__VnbaTriggered[4U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__16(vlSelf);
    }
    if ((((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
          | (0x00000ffffffffc00ULL & vlSelfRef.__VnbaTriggered[6U])) 
         | (0x07fffffff8000000ULL & vlSelfRef.__VnbaTriggered[4U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__17(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
    if ((((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
          | (0x00000ffffffff000ULL & vlSelfRef.__VnbaTriggered[6U])) 
         | (0x07fffffff8000000ULL & vlSelfRef.__VnbaTriggered[4U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__18(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x00000ffffffffc00ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__19(vlSelf);
    }
    if ((((((0x00000fffffffffffULL & vlSelfRef.__VnbaTriggered[7U]) 
            | (0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U])) 
           | (0xf800000000000000ULL & vlSelfRef.__VnbaTriggered[1U])) 
          | (0xfffff00000000000ULL & vlSelfRef.__VnbaTriggered[6U])) 
         | (0x0000000007ffffffULL & vlSelfRef.__VnbaTriggered[2U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__20(vlSelf);
    }
    if ((((0x00000fffffffffffULL & vlSelfRef.__VnbaTriggered[7U]) 
          | (0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U])) 
         | (0xfffff00000000000ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__21(vlSelf);
    }
    if (((((((0x00000fffffffffffULL & vlSelfRef.__VnbaTriggered[7U]) 
             | vlSelfRef.__VnbaTriggered[3U]) | (0x17ffffffffffffffULL 
                                                 & vlSelfRef.__VnbaTriggered[5U])) 
           | (0xfffff00000000000ULL & vlSelfRef.__VnbaTriggered[6U])) 
          | (0xfffffffff8000000ULL & vlSelfRef.__VnbaTriggered[2U])) 
         | (0xf800000007ffffffULL & vlSelfRef.__VnbaTriggered[4U]))) {
        Vtb_ddr3_init_top___024root___nba_sequent__TOP__22(vlSelf);
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x0000000000000c00ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_comb__TOP__0(vlSelf);
    }
    if (((0x9000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (7ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_comb__TOP__1(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VnbaTriggered[5U]) 
         | (0x00000ffffffffc00ULL & vlSelfRef.__VnbaTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___nba_comb__TOP__2(vlSelf);
    }
}

void Vtb_ddr3_init_top___024root___timing_ready(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___timing_ready\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x0000100000000000ULL & vlSelfRef.__VactTriggered[7U])) {
        vlSelfRef.__VtrigSched_h7abd7d05__0.ready("@(posedge tb_ddr3_init_top.init_done)");
    }
    if ((0x0000200000000000ULL & vlSelfRef.__VactTriggered[7U])) {
        vlSelfRef.__VtrigSched_h849b2911__0.ready("@(posedge tb_ddr3_init_top.init_error)");
    }
    if ((0x0800000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        vlSelfRef.__VtrigSched_h42cb58c7__0.ready("@( tb_ddr3_init_top.u_dut.o_ddr3_reset_n)");
    }
    if ((0x2000000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        vlSelfRef.__VtrigSched_h431685b1__0.ready("@( tb_ddr3_init_top.clk_phy)");
    }
    if ((0x4000000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        vlSelfRef.__VtrigSched_h19711794__0.ready("@( tb_ddr3_init_top.u_dut.o_ddr3_cke)");
    }
    if ((0x8000000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        vlSelfRef.__VtrigSched_hc7c70aae__0.ready("@( tb_ddr3_init_top.u_dut.sel_cmd[3])");
    }
    if ((1ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_hc7c709f3__0.ready("@( tb_ddr3_init_top.u_dut.sel_cmd[2])");
    }
    if ((2ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_hc7c70837__0.ready("@( tb_ddr3_init_top.u_dut.sel_cmd[1])");
    }
    if ((4ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_hc7c70b72__0.ready("@( tb_ddr3_init_top.u_dut.sel_cmd[0])");
    }
    if ((8ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_he5edbdd7__0.ready("@( 1'h0)");
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_he1a85685__0.ready("@( tb_ddr3_init_top.u_dut.o_ddr3_ba)");
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_haf83f068__0.ready("@( tb_ddr3_init_top.u_dut.o_ddr3_addr)");
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h42287e6e__0.ready("@( tb_ddr3_init_top.u_micron.dq)");
    }
    if ((0x0000000000000180ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h0c92d3e1__0.ready("@( tb_ddr3_init_top.u_micron.dqs or  tb_ddr3_init_top.u_micron.dqs_n)");
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h1cb92c28__0.ready("@( tb_ddr3_init_top.u_dut.o_ddr3_odt)");
    }
    if ((0x0000000000000c00ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_hd46fc85a__0.ready("@(edge tb_ddr3_init_top.u_micron.diff_ck or negedge tb_ddr3_init_top.u_micron.rst_n_in)");
    }
    if ((0x0000080000000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3299__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[0])");
    }
    if ((0x0000000008000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca34da__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[1])");
    }
    if ((0x0000000800000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca2c06__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[2])");
    }
    if ((0x0000000000080000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca325c__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[3])");
    }
    if ((0x0000008000000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca2d98__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[4])");
    }
    if ((0x0000000000800000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca342b__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[5])");
    }
    if ((0x0000000080000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3705__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[6])");
    }
    if ((0x0000000000008000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3159__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[7])");
    }
    if ((0x0000020000000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca349b__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[8])");
    }
    if ((0x0000000002000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca36c8__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[9])");
    }
    if ((0x0000000200000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3e44__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[10])");
    }
    if ((0x0000000000020000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3476__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[11])");
    }
    if ((0x0000002000000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca37c2__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[12])");
    }
    if ((0x0000000000200000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3201__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[13])");
    }
    if ((0x0000000020000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca590b__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[14])");
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3b4b__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[15])");
    }
    if ((0x0000040000000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca66b5__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[16])");
    }
    if ((0x0000000004000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca58e6__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[17])");
    }
    if ((0x0000000400000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca301a__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[18])");
    }
    if ((0x0000000000040000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca6678__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[19])");
    }
    if ((0x0000004000000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca319c__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[20])");
    }
    if ((0x0000000000400000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca37df__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[21])");
    }
    if ((0x0000000040000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3b31__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[22])");
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca355d__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[23])");
    }
    if ((0x0000010000000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca38b7__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[24])");
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3af4__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[25])");
    }
    if ((0x0000000100000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3238__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[26])");
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3872__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[27])");
    }
    if ((0x0000001000000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca3ba6__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[28])");
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca59f5__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[29])");
    }
    if ((0x0000000010000000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca5d37__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[30])");
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VactTriggered[6U])) {
        vlSelfRef.__VtrigSched_h5cca65ff__0.ready("@(posedge tb_ddr3_init_top.u_micron.dqs_in[31])");
    }
}

void Vtb_ddr3_init_top___024root___timing_resume(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___timing_resume\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h7abd7d05__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.init_done)");
    vlSelfRef.__VtrigSched_h849b2911__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.init_error)");
    vlSelfRef.__VtrigSched_h42cb58c7__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.o_ddr3_reset_n)");
    vlSelfRef.__VtrigSched_h431685b1__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.clk_phy)");
    vlSelfRef.__VtrigSched_h19711794__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.o_ddr3_cke)");
    vlSelfRef.__VtrigSched_hc7c70aae__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.sel_cmd[3])");
    vlSelfRef.__VtrigSched_hc7c709f3__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.sel_cmd[2])");
    vlSelfRef.__VtrigSched_hc7c70837__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.sel_cmd[1])");
    vlSelfRef.__VtrigSched_hc7c70b72__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.sel_cmd[0])");
    vlSelfRef.__VtrigSched_he5edbdd7__0.moveToResumeQueue(
                                                          "@( 1'h0)");
    vlSelfRef.__VtrigSched_he1a85685__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.o_ddr3_ba)");
    vlSelfRef.__VtrigSched_haf83f068__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.o_ddr3_addr)");
    vlSelfRef.__VtrigSched_h42287e6e__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_micron.dq)");
    vlSelfRef.__VtrigSched_h0c92d3e1__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_micron.dqs or  tb_ddr3_init_top.u_micron.dqs_n)");
    vlSelfRef.__VtrigSched_h1cb92c28__0.moveToResumeQueue(
                                                          "@( tb_ddr3_init_top.u_dut.o_ddr3_odt)");
    vlSelfRef.__VtrigSched_hd46fc85a__0.moveToResumeQueue(
                                                          "@(edge tb_ddr3_init_top.u_micron.diff_ck or negedge tb_ddr3_init_top.u_micron.rst_n_in)");
    vlSelfRef.__VtrigSched_h5cca3299__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[0])");
    vlSelfRef.__VtrigSched_h5cca34da__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[1])");
    vlSelfRef.__VtrigSched_h5cca2c06__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[2])");
    vlSelfRef.__VtrigSched_h5cca325c__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[3])");
    vlSelfRef.__VtrigSched_h5cca2d98__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[4])");
    vlSelfRef.__VtrigSched_h5cca342b__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[5])");
    vlSelfRef.__VtrigSched_h5cca3705__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[6])");
    vlSelfRef.__VtrigSched_h5cca3159__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[7])");
    vlSelfRef.__VtrigSched_h5cca349b__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[8])");
    vlSelfRef.__VtrigSched_h5cca36c8__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[9])");
    vlSelfRef.__VtrigSched_h5cca3e44__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[10])");
    vlSelfRef.__VtrigSched_h5cca3476__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[11])");
    vlSelfRef.__VtrigSched_h5cca37c2__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[12])");
    vlSelfRef.__VtrigSched_h5cca3201__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[13])");
    vlSelfRef.__VtrigSched_h5cca590b__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[14])");
    vlSelfRef.__VtrigSched_h5cca3b4b__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[15])");
    vlSelfRef.__VtrigSched_h5cca66b5__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[16])");
    vlSelfRef.__VtrigSched_h5cca58e6__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[17])");
    vlSelfRef.__VtrigSched_h5cca301a__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[18])");
    vlSelfRef.__VtrigSched_h5cca6678__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[19])");
    vlSelfRef.__VtrigSched_h5cca319c__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[20])");
    vlSelfRef.__VtrigSched_h5cca37df__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[21])");
    vlSelfRef.__VtrigSched_h5cca3b31__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[22])");
    vlSelfRef.__VtrigSched_h5cca355d__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[23])");
    vlSelfRef.__VtrigSched_h5cca38b7__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[24])");
    vlSelfRef.__VtrigSched_h5cca3af4__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[25])");
    vlSelfRef.__VtrigSched_h5cca3238__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[26])");
    vlSelfRef.__VtrigSched_h5cca3872__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[27])");
    vlSelfRef.__VtrigSched_h5cca3ba6__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[28])");
    vlSelfRef.__VtrigSched_h5cca59f5__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[29])");
    vlSelfRef.__VtrigSched_h5cca5d37__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[30])");
    vlSelfRef.__VtrigSched_h5cca65ff__0.moveToResumeQueue(
                                                          "@(posedge tb_ddr3_init_top.u_micron.dqs_in[31])");
    vlSelfRef.__VtrigSched_h7abd7d05__0.resume("@(posedge tb_ddr3_init_top.init_done)");
    vlSelfRef.__VtrigSched_h849b2911__0.resume("@(posedge tb_ddr3_init_top.init_error)");
    vlSelfRef.__VtrigSched_h42cb58c7__0.resume("@( tb_ddr3_init_top.u_dut.o_ddr3_reset_n)");
    vlSelfRef.__VtrigSched_h431685b1__0.resume("@( tb_ddr3_init_top.clk_phy)");
    vlSelfRef.__VtrigSched_h19711794__0.resume("@( tb_ddr3_init_top.u_dut.o_ddr3_cke)");
    vlSelfRef.__VtrigSched_hc7c70aae__0.resume("@( tb_ddr3_init_top.u_dut.sel_cmd[3])");
    vlSelfRef.__VtrigSched_hc7c709f3__0.resume("@( tb_ddr3_init_top.u_dut.sel_cmd[2])");
    vlSelfRef.__VtrigSched_hc7c70837__0.resume("@( tb_ddr3_init_top.u_dut.sel_cmd[1])");
    vlSelfRef.__VtrigSched_hc7c70b72__0.resume("@( tb_ddr3_init_top.u_dut.sel_cmd[0])");
    vlSelfRef.__VtrigSched_he5edbdd7__0.resume("@( 1'h0)");
    vlSelfRef.__VtrigSched_he1a85685__0.resume("@( tb_ddr3_init_top.u_dut.o_ddr3_ba)");
    vlSelfRef.__VtrigSched_haf83f068__0.resume("@( tb_ddr3_init_top.u_dut.o_ddr3_addr)");
    vlSelfRef.__VtrigSched_h42287e6e__0.resume("@( tb_ddr3_init_top.u_micron.dq)");
    vlSelfRef.__VtrigSched_h0c92d3e1__0.resume("@( tb_ddr3_init_top.u_micron.dqs or  tb_ddr3_init_top.u_micron.dqs_n)");
    vlSelfRef.__VtrigSched_h1cb92c28__0.resume("@( tb_ddr3_init_top.u_dut.o_ddr3_odt)");
    vlSelfRef.__VtrigSched_hd46fc85a__0.resume("@(edge tb_ddr3_init_top.u_micron.diff_ck or negedge tb_ddr3_init_top.u_micron.rst_n_in)");
    vlSelfRef.__VtrigSched_h5cca3299__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[0])");
    vlSelfRef.__VtrigSched_h5cca34da__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[1])");
    vlSelfRef.__VtrigSched_h5cca2c06__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[2])");
    vlSelfRef.__VtrigSched_h5cca325c__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[3])");
    vlSelfRef.__VtrigSched_h5cca2d98__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[4])");
    vlSelfRef.__VtrigSched_h5cca342b__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[5])");
    vlSelfRef.__VtrigSched_h5cca3705__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[6])");
    vlSelfRef.__VtrigSched_h5cca3159__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[7])");
    vlSelfRef.__VtrigSched_h5cca349b__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[8])");
    vlSelfRef.__VtrigSched_h5cca36c8__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[9])");
    vlSelfRef.__VtrigSched_h5cca3e44__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[10])");
    vlSelfRef.__VtrigSched_h5cca3476__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[11])");
    vlSelfRef.__VtrigSched_h5cca37c2__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[12])");
    vlSelfRef.__VtrigSched_h5cca3201__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[13])");
    vlSelfRef.__VtrigSched_h5cca590b__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[14])");
    vlSelfRef.__VtrigSched_h5cca3b4b__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[15])");
    vlSelfRef.__VtrigSched_h5cca66b5__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[16])");
    vlSelfRef.__VtrigSched_h5cca58e6__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[17])");
    vlSelfRef.__VtrigSched_h5cca301a__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[18])");
    vlSelfRef.__VtrigSched_h5cca6678__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[19])");
    vlSelfRef.__VtrigSched_h5cca319c__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[20])");
    vlSelfRef.__VtrigSched_h5cca37df__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[21])");
    vlSelfRef.__VtrigSched_h5cca3b31__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[22])");
    vlSelfRef.__VtrigSched_h5cca355d__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[23])");
    vlSelfRef.__VtrigSched_h5cca38b7__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[24])");
    vlSelfRef.__VtrigSched_h5cca3af4__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[25])");
    vlSelfRef.__VtrigSched_h5cca3238__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[26])");
    vlSelfRef.__VtrigSched_h5cca3872__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[27])");
    vlSelfRef.__VtrigSched_h5cca3ba6__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[28])");
    vlSelfRef.__VtrigSched_h5cca59f5__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[29])");
    vlSelfRef.__VtrigSched_h5cca5d37__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[30])");
    vlSelfRef.__VtrigSched_h5cca65ff__0.resume("@(posedge tb_ddr3_init_top.u_micron.dqs_in[31])");
    if ((0x1000000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_ddr3_init_top___024root___trigger_orInto__act_vec_ext(VlUnpacked<QData/*63:0*/, 9> &out, const VlUnpacked<QData/*63:0*/, 8> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___trigger_orInto__act_vec_ext\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((7U >= n));
}

void Vtb_ddr3_init_top___024root___trigger_orInto__act_ext_vec(VlUnpacked<QData/*63:0*/, 8> &out, const VlUnpacked<QData/*63:0*/, 9> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___trigger_orInto__act_ext_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((7U >= n));
}

void Vtb_ddr3_init_top___024root___eval_triggers_vec__act(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___eval_triggers_ext__act(Vtb_ddr3_init_top___024root* vlSelf, const VlUnpacked<QData/*63:0*/, 8> &latched);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ddr3_init_top___024root___dump_triggers__act_ext(const VlUnpacked<QData/*63:0*/, 9> &ext, const std::string &tag);
#endif  // VL_DEBUG
bool Vtb_ddr3_init_top___024root___trigger_anySet__act_ext(const VlUnpacked<QData/*63:0*/, 9> &in);
void Vtb_ddr3_init_top___024root___eval_act(Vtb_ddr3_init_top___024root* vlSelf);

bool Vtb_ddr3_init_top___024root___eval_phase__act(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_phase__act\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_ddr3_init_top___024root___eval_triggers_vec__act(vlSelf);
    Vtb_ddr3_init_top___024root___timing_ready(vlSelf);
    Vtb_ddr3_init_top___024root___trigger_orInto__act_vec_ext(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
    Vtb_ddr3_init_top___024root___eval_triggers_ext__act(vlSelf, vlSelfRef.__VnbaTriggered);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_ddr3_init_top___024root___dump_triggers__act_ext(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_ddr3_init_top___024root___trigger_orInto__act_ext_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_ddr3_init_top___024root___trigger_anySet__act_ext(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_ddr3_init_top___024root___timing_resume(vlSelf);
        Vtb_ddr3_init_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_ddr3_init_top___024root___trigger_anySet__act_ext(const VlUnpacked<QData/*63:0*/, 9> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___trigger_anySet__act_ext\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((9U > n));
    return (0U);
}

bool Vtb_ddr3_init_top___024root___eval_phase__inact(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_phase__inact\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        vlSelfRef.__VdlySched.resumeZeroDelay();
    }
    return (__VinactExecute);
}

void Vtb_ddr3_init_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 8> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((8U > n));
}

bool Vtb_ddr3_init_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 8> &in);

bool Vtb_ddr3_init_top___024root___eval_phase__nba(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_phase__nba\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_ddr3_init_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_ddr3_init_top___024root___eval_nba(vlSelf);
        Vtb_ddr3_init_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ddr3_init_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 8> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtb_ddr3_init_top___024root___eval(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_ddr3_init_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("ip/ddr3/sim/tb_ddr3_init_top.sv", 19, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("ip/ddr3/sim/tb_ddr3_init_top.sv", 19, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_ddr3_init_top___024root___dump_triggers__act_ext(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("ip/ddr3/sim/tb_ddr3_init_top.sv", 19, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_ddr3_init_top___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_ddr3_init_top___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_ddr3_init_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h7abd7d05__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h7abd7d05__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = 0ULL;
    __VTmp[7U] = ((QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done) 
                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__init_done__0))) 
                                   << 0x0000000cU))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__init_done__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__init_done;
    if ((0x0000000000001000ULL & __VTmp[7U])) {
        vlSelfRef.__VtrigSched_h7abd7d05__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[7U] = (vlSelfRef.__VactTriggeredAcc[7U] 
                                        | __VTmp[7U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h849b2911__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h849b2911__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = 0ULL;
    __VTmp[7U] = ((QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_error) 
                                    & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__init_error__0))) 
                                   << 0x0000000dU))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__init_error__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__init_error;
    if ((0x0000000000002000ULL & __VTmp[7U])) {
        vlSelfRef.__VtrigSched_h849b2911__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[7U] = (vlSelfRef.__VactTriggeredAcc[7U] 
                                        | __VTmp[7U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h42cb58c7__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h42cb58c7__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = ((QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n) 
                                    != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n__0)) 
                                   << 0x0000001bU))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n;
    if ((0x0000000008000000ULL & __VTmp[5U])) {
        vlSelfRef.__VtrigSched_h42cb58c7__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[5U] = (vlSelfRef.__VactTriggeredAcc[5U] 
                                        | __VTmp[5U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h431685b1__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h431685b1__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = ((QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__clk_phy) 
                                    != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__clk_phy__0)) 
                                   << 0x0000001dU))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__clk_phy__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__clk_phy;
    if ((0x0000000020000000ULL & __VTmp[5U])) {
        vlSelfRef.__VtrigSched_h431685b1__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h431685b1__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[5U] = (vlSelfRef.__VactTriggeredAcc[5U] 
                                        | __VTmp[5U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h19711794__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h19711794__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = ((QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke) 
                                    != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke__0)) 
                                   << 0x0000001eU))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke;
    if ((0x0000000040000000ULL & __VTmp[5U])) {
        vlSelfRef.__VtrigSched_h19711794__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[5U] = (vlSelfRef.__VactTriggeredAcc[5U] 
                                        | __VTmp[5U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_hc7c70aae__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_hc7c70aae__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = ((QData)((IData)((((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                           >> 3U)) 
                                    != (IData)(vlSelfRef.__Vtrigprevexpr_h60001e29__0)) 
                                   << 0x0000001fU))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h60001e29__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                               >> 3U));
    if ((0xffffffff80000000ULL & __VTmp[5U])) {
        vlSelfRef.__VtrigSched_hc7c70aae__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[5U] = (vlSelfRef.__VactTriggeredAcc[5U] 
                                        | __VTmp[5U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_hc7c709f3__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_hc7c709f3__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)(((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                         >> 2U)) != (IData)(vlSelfRef.__Vtrigprevexpr_h6000216a__0))));
    vlSelfRef.__Vtrigprevexpr_h6000216a__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                               >> 2U));
    if ((1ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_hc7c709f3__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_hc7c70837__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_hc7c70837__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                          >> 1U)) != (IData)(vlSelfRef.__Vtrigprevexpr_h60001fa6__0)) 
                                  << 1U)));
    vlSelfRef.__Vtrigprevexpr_h60001fa6__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                               >> 1U));
    if ((2ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_hc7c70837__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_hc7c70b72__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_hc7c70b72__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd)) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr_h60001ee5__0)) 
                                  << 2U)));
    vlSelfRef.__Vtrigprevexpr_h60001ee5__0 = (1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd));
    if ((4ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_hc7c70b72__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_he5edbdd7__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_he5edbdd7__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)(((IData)(vlSelfRef.__Vtrigprevexpr_h81d9cd46__0) 
                                  << 3U)));
    vlSelfRef.__Vtrigprevexpr_h81d9cd46__0 = 0U;
    if ((8ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_he5edbdd7__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_he1a85685__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_he1a85685__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba__0)) 
                                  << 4U)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba;
    if ((0x0000000000000010ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_he1a85685__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_haf83f068__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_haf83f068__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr__0)) 
                                  << 5U)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr;
    if ((0x0000000000000020ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_haf83f068__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h42287e6e__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h42287e6e__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dq__0)) 
                                  << 6U)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dq__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq;
    if ((0x0000000000000040ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h42287e6e__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h0c92d3e1__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h0c92d3e1__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)(((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n) 
                                    != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n__0)) 
                                   << 8U) | (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs) 
                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dqs__0)) 
                                             << 7U))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dqs__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n;
    if ((0x0000000000000080ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h0c92d3e1__0.ready(__VeventDescription);
    }
    if ((0x0000000000000100ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h0c92d3e1__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h1cb92c28__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h1cb92c28__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt) 
                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt__0)) 
                                  << 9U)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt;
    if ((0x0000000000000200ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h1cb92c28__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_hd46fc85a__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_hd46fc85a__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)(((((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__0)) 
                                   << 0x0000000bU) 
                                  | (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck) 
                                      ^ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck__0)) 
                                     << 0x0000000aU))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in;
    if ((0x0000000000000400ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_hd46fc85a__0.ready(__VeventDescription);
    }
    if ((0x0000000000000800ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_hd46fc85a__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3299__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3299__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((0x00000800U & (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in) 
                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd45ae__0))) 
                                                  << 0x0000000bU)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd45ae__0 = (1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in));
    if ((0x0000000000000800ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3299__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca34da__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca34da__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x08000000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 1U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd43eb__0))) 
                                                 << 0x0000001bU))));
    vlSelfRef.__Vtrigprevexpr_h08fd43eb__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 1U)));
    if ((0x0000000008000000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca34da__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca2c06__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca2c06__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((8U & (((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                   >> 2U)) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd3aff__0))) 
                                         << 3U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd3aff__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 2U)));
    if ((8ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca2c06__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca325c__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca325c__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00080000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 3U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd456d__0))) 
                                                 << 0x00000013U))));
    vlSelfRef.__Vtrigprevexpr_h08fd456d__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 3U)));
    if ((0x0000000000080000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca325c__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca2d98__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca2d98__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((0x00000080U & (((IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 4U)) 
                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd3c91__0))) 
                                                  << 7U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd3c91__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 4U)));
    if ((0x0000000000000080ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca2d98__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca342b__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca342b__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00800000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 5U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd46c0__0))) 
                                                 << 0x00000017U))));
    vlSelfRef.__Vtrigprevexpr_h08fd46c0__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 5U)));
    if ((0x0000000000800000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca342b__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3705__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3705__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                            >> 6U)) 
                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4202__0))) 
                                  << 0x0000001fU)));
    vlSelfRef.__Vtrigprevexpr_h08fd4202__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 6U)));
    if ((0xffffffff80000000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3705__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3159__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3159__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00008000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 7U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd486e__0))) 
                                                 << 0x0000000fU))));
    vlSelfRef.__Vtrigprevexpr_h08fd486e__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 7U)));
    if ((0x0000000000008000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3159__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca349b__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca349b__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((0x00000200U & (((IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 8U)) 
                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd43b0__0))) 
                                                  << 9U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd43b0__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 8U)));
    if ((0x0000000000000200ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca349b__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca36c8__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca36c8__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x02000000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 9U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd41c1__0))) 
                                                 << 0x00000019U))));
    vlSelfRef.__Vtrigprevexpr_h08fd41c1__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 9U)));
    if ((0x0000000002000000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca36c8__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3e44__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3e44__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((2U & (((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                   >> 0x0aU)) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4935__0))) 
                                         << 1U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd4935__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0aU)));
    if ((2ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3e44__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3476__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3476__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00020000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x0bU)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd436f__0))) 
                                                 << 0x00000011U))));
    vlSelfRef.__Vtrigprevexpr_h08fd436f__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0bU)));
    if ((0x0000000000020000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3476__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca37c2__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca37c2__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((0x00000020U & (((IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0cU)) 
                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd42b3__0))) 
                                                  << 5U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd42b3__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0cU)));
    if ((0x0000000000000020ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca37c2__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3201__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3201__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00200000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x0dU)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd44f6__0))) 
                                                 << 0x00000015U))));
    vlSelfRef.__Vtrigprevexpr_h08fd44f6__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0dU)));
    if ((0x0000000000200000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3201__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca590b__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca590b__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x20000000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x0eU)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd7020__0))) 
                                                 << 0x0000001dU))));
    vlSelfRef.__Vtrigprevexpr_h08fd7020__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0eU)));
    if ((0x0000000020000000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca590b__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3b4b__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3b4b__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00002000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x0fU)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4e60__0))) 
                                                 << 0x0000000dU))));
    vlSelfRef.__Vtrigprevexpr_h08fd4e60__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0fU)));
    if ((0x0000000000002000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3b4b__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca66b5__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca66b5__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((0x00000400U & (((IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x10U)) 
                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd71b2__0))) 
                                                  << 0x0000000aU)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd71b2__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x10U)));
    if ((0x0000000000000400ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca66b5__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca58e6__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca58e6__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x04000000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x11U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd6fdf__0))) 
                                                 << 0x0000001aU))));
    vlSelfRef.__Vtrigprevexpr_h08fd6fdf__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x11U)));
    if ((0x0000000004000000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca58e6__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca301a__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca301a__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((4U & (((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                   >> 0x12U)) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd472b__0))) 
                                         << 2U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd472b__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x12U)));
    if ((4ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca301a__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca6678__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca6678__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00040000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x13U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd7171__0))) 
                                                 << 0x00000012U))));
    vlSelfRef.__Vtrigprevexpr_h08fd7171__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x13U)));
    if ((0x0000000000040000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca6678__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca319c__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca319c__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((0x00000040U & (((IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x14U)) 
                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd48ad__0))) 
                                                  << 6U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd48ad__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x14U)));
    if ((0x0000000000000040ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca319c__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca37df__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca37df__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00400000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x15U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd42ec__0))) 
                                                 << 0x00000016U))));
    vlSelfRef.__Vtrigprevexpr_h08fd42ec__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x15U)));
    if ((0x0000000000400000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca37df__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3b31__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3b31__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x40000000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x16U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4e26__0))) 
                                                 << 0x0000001eU))));
    vlSelfRef.__Vtrigprevexpr_h08fd4e26__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x16U)));
    if ((0x0000000040000000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3b31__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca355d__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca355d__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00004000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x17U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd445a__0))) 
                                                 << 0x0000000eU))));
    vlSelfRef.__Vtrigprevexpr_h08fd445a__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x17U)));
    if ((0x0000000000004000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca355d__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca38b7__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca38b7__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((0x00000100U & (((IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x18U)) 
                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4fa4__0))) 
                                                  << 8U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd4fa4__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x18U)));
    if ((0x0000000000000100ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca38b7__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3af4__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3af4__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x01000000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x19U)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4de5__0))) 
                                                 << 0x00000018U))));
    vlSelfRef.__Vtrigprevexpr_h08fd4de5__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x19U)));
    if ((0x0000000001000000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3af4__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3238__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3238__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                  >> 0x1aU)) 
                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4531__0)))))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd4531__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1aU)));
    if ((1ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3238__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3872__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3872__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00010000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x1bU)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4f63__0))) 
                                                 << 0x00000010U))));
    vlSelfRef.__Vtrigprevexpr_h08fd4f63__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1bU)));
    if ((0x0000000000010000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3872__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3ba6__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3ba6__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = ((QData)((IData)((0x00000010U & (((IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1cU)) 
                                                   & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd4e9f__0))) 
                                                  << 4U)))) 
                  << 0x00000020U);
    vlSelfRef.__Vtrigprevexpr_h08fd4e9f__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1cU)));
    if ((0x0000000000000010ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca3ba6__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca59f5__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca59f5__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00100000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x1dU)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd70f2__0))) 
                                                 << 0x00000014U))));
    vlSelfRef.__Vtrigprevexpr_h08fd70f2__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1dU)));
    if ((0x0000000000100000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca59f5__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca5d37__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca5d37__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x10000000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x1eU)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd6c24__0))) 
                                                 << 0x0000001cU))));
    vlSelfRef.__Vtrigprevexpr_h08fd6c24__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1eU)));
    if ((0x0000000010000000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca5d37__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca65ff__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca65ff__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 8> __VTmp;
    // Body
    __VTmp[0U] = 0ULL;
    __VTmp[1U] = 0ULL;
    __VTmp[2U] = 0ULL;
    __VTmp[3U] = 0ULL;
    __VTmp[4U] = 0ULL;
    __VTmp[5U] = 0ULL;
    __VTmp[6U] = (QData)((IData)((0x00001000U & (((IData)(
                                                          (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                           >> 0x1fU)) 
                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr_h08fd710c__0))) 
                                                 << 0x0000000cU))));
    vlSelfRef.__Vtrigprevexpr_h08fd710c__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1fU)));
    if ((0x0000000000001000ULL & __VTmp[6U])) {
        vlSelfRef.__VtrigSched_h5cca65ff__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[6U] = (vlSelfRef.__VactTriggeredAcc[6U] 
                                        | __VTmp[6U]);
}

#ifdef VL_DEBUG
void Vtb_ddr3_init_top___024root___eval_debug_assertions(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_debug_assertions\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG

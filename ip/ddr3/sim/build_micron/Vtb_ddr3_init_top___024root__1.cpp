// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ddr3_init_top.h for the primary calling header

#include "Vtb_ddr3_init_top__pch.h"

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_26__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_26__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(VL_RTOIROUND_Q_D(
                                                          (6.99999999999999956e-01 
                                                           * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2354);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly__v0 
        = vlSelfRef.__Vintraval_hf79e2544__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_25__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_25__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x00000000000000faULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2335);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v1 
        = vlSelfRef.__Vintraval_h7656007d__1;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v1 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_24__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_24__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000002134ULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2317);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v0 
        = vlSelfRef.__Vintraval_h7656007d__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_23__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_23__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay((QData)((IData)(
                                                         VL_RTOI_I_D(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg))), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         1354);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg__v0 
        = vlSelfRef.__Vintraval_h25fa3a89__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_22__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_22__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(((0x0000000000001d4cULL 
                                           + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end
                                           [(7U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__main__DOT__i)]) 
                                          - (QData)(VL_TIME_UNITED_Q(1))), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2131);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v0 
        = vlSelfRef.__Vintraval_he1624136__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_21__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_21__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*63:0*/ __VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge__v0;
    __VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge__v0;
    __VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge__v0 = 0;
    // Body
    co_await vlSelfRef.__VdlySched.delay(((0x0000000000001d4cULL 
                                           + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end
                                           [(7U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__main__DOT__i)]) 
                                          - (QData)(VL_TIME_UNITED_Q(1))), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2130);
    __VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge__v0 
        = vlSelfRef.__Vintraval_h2994922b__0;
    __VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge__v0 
        = vlSelfRef.__Vintraidx_he99cb274__0;
    vlSelfRef.__VdlyCommitQueuetb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge.enqueue(__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge__v0, (IData)(__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge__v0));
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_20__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_20__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(((0x0000000000001d4cULL 
                                           + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end
                                           [(7U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__main__DOT__i)]) 
                                          - (QData)(VL_TIME_UNITED_Q(1))), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2129);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0 
        = vlSelfRef.__Vintraval_h10ee5d2c__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0 
        = vlSelfRef.__Vintralsb_h3f6a9d9d__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_19__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_19__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(((0x0000000000001d4cULL 
                                           + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end
                                           [(7U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__main__DOT__i)]) 
                                          - (QData)(VL_TIME_UNITED_Q(1))), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2128);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0 
        = vlSelfRef.__Vintraval_h93ac25d1__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0 
        = vlSelfRef.__Vintralsb_hf60466b3__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_18__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_18__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay((QData)((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_delay)), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         1985);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v0 
        = vlSelfRef.__Vintraval_h50e69344__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_17__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_17__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay((QData)((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_delay)), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         1984);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v0 
        = vlSelfRef.__Vintraval_h4514651e__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_16__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_16__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay((QData)((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_delay)), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         1982);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly__v0 
        = vlSelfRef.__Vintraval_h03aab35a__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly__v0 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_15__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__19__0____Vfork_15__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay((QData)((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_delay)), 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         1981);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly__v0 
        = vlSelfRef.__Vintraval_hfce06310__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly__v0 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3299__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_27__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_28__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_29__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_30__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3299__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[0])");
        co_await vlSelfRef.__VtrigSched_h5cca3299__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[0])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2790);
        if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i = 0U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h898ccd2b__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U));
                vlSelfRef.__Vintraval_h4e52a0da__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_27__0(vlSelf);
                vlSelfRef.__Vintralsb_hb62a94af__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U));
                vlSelfRef.__Vintraval_h2939e239__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_28__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_hd29f0a2e__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h57d375eb__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_29__0(vlSelf);
                    vlSelfRef.__Vintralsb_hd3dd5b39__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h7797d73a__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_30__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[0U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v128 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v128 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v129 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v129 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v130 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v130 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v131 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v131 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v132 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v132 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v133 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v133 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v134 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v134 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v135 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v135 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v32 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v32 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v2 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v2 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v2 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v2 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v2 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v2 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v0 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v0 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v0 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v0 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v0 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v0 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v0 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v0 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__274__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v0 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_30__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_30__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v2 
        = vlSelfRef.__Vintraval_h7797d73a__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v2 
        = vlSelfRef.__Vintralsb_hd3dd5b39__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v2 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_29__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_29__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v2 
        = vlSelfRef.__Vintraval_h57d375eb__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v2 
        = vlSelfRef.__Vintralsb_hd29f0a2e__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v2 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_28__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_28__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v1 
        = vlSelfRef.__Vintraval_h2939e239__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v1 
        = vlSelfRef.__Vintralsb_hb62a94af__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v1 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_27__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__20____Vfork_27__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v1 
        = vlSelfRef.__Vintraval_h4e52a0da__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v1 
        = vlSelfRef.__Vintralsb_h898ccd2b__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v1 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca34da__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_31__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_32__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_33__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_34__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca34da__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[1])");
        co_await vlSelfRef.__VtrigSched_h5cca34da__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[1])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2791);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 1U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i = 1U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_hfa74061c__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U));
                vlSelfRef.__Vintraval_h19dc5c35__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_31__0(vlSelf);
                vlSelfRef.__Vintralsb_h443ffb80__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U));
                vlSelfRef.__Vintraval_h96249967__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_32__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h183f335f__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hde4dba67__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_33__0(vlSelf);
                    vlSelfRef.__Vintralsb_h1afc9cf0__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_ha9cb318d__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_34__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[1U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v136 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v136 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v137 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v137 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v138 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v138 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v139 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v139 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v140 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v140 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v141 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v141 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v142 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v142 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v143 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v143 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v33 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v33 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v3 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v3 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v3 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v3 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v3 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v3 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v1 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v1 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v1 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v1 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v1 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v1 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v1 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v1 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__275__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v1 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_34__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_34__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v4 
        = vlSelfRef.__Vintraval_ha9cb318d__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v4 
        = vlSelfRef.__Vintralsb_h1afc9cf0__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v4 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_33__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_33__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v4 
        = vlSelfRef.__Vintraval_hde4dba67__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v4 
        = vlSelfRef.__Vintralsb_h183f335f__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v4 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_32__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_32__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v3 
        = vlSelfRef.__Vintraval_h96249967__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v3 
        = vlSelfRef.__Vintralsb_h443ffb80__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v3 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_31__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__21____Vfork_31__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v3 
        = vlSelfRef.__Vintraval_h19dc5c35__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v3 
        = vlSelfRef.__Vintralsb_hfa74061c__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v3 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca2c06__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_35__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_36__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_37__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_38__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca2c06__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[2])");
        co_await vlSelfRef.__VtrigSched_h5cca2c06__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[2])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2792);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 2U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i = 2U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_hec1db5f3__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U));
                vlSelfRef.__Vintraval_h36107c4f__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_35__0(vlSelf);
                vlSelfRef.__Vintralsb_h5257a277__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U));
                vlSelfRef.__Vintraval_h58209db4__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_36__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_ha012d2d8__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h457f0462__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_37__0(vlSelf);
                    vlSelfRef.__Vintralsb_h9e697c27__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_he8bff7d6__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_38__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[2U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v144 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v144 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v145 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v145 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v146 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v146 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v147 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v147 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v148 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v148 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v149 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v149 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v150 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v150 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v151 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v151 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v34 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v34 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v4 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v4 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v4 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v4 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v4 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v4 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v2 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v2 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v2 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v2 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v2 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v2 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v2 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v2 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__276__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v2 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_38__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_38__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v6 
        = vlSelfRef.__Vintraval_he8bff7d6__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v6 
        = vlSelfRef.__Vintralsb_h9e697c27__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v6 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_37__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_37__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v6 
        = vlSelfRef.__Vintraval_h457f0462__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v6 
        = vlSelfRef.__Vintralsb_ha012d2d8__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v6 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_36__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_36__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v5 
        = vlSelfRef.__Vintraval_h58209db4__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v5 
        = vlSelfRef.__Vintralsb_h5257a277__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v5 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_35__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__22____Vfork_35__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v5 
        = vlSelfRef.__Vintraval_h36107c4f__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v5 
        = vlSelfRef.__Vintralsb_hec1db5f3__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v5 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca325c__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_39__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_40__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_41__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_42__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca325c__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[3])");
        co_await vlSelfRef.__VtrigSched_h5cca325c__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[3])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2793);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 3U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i = 3U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_hfd59d945__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U));
                vlSelfRef.__Vintraval_h385045b5__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_39__0(vlSelf);
                vlSelfRef.__Vintralsb_h41b545e5__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U));
                vlSelfRef.__Vintraval_h0b8880bb__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_40__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h5473a5fd__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h6923fe30__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_41__0(vlSelf);
                    vlSelfRef.__Vintralsb_h52491e4a__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_heb7808f1__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_42__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[3U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v152 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v152 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v153 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v153 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v154 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v154 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v155 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v155 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v156 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v156 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v157 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v157 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v158 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v158 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v159 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v159 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v35 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v35 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v5 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v5 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v5 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v5 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v5 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v5 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v3 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v3 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v3 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v3 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v3 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v3 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v3 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v3 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__277__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v3 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_42__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_42__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v8 
        = vlSelfRef.__Vintraval_heb7808f1__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v8 
        = vlSelfRef.__Vintralsb_h52491e4a__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v8 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_41__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_41__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v8 
        = vlSelfRef.__Vintraval_h6923fe30__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v8 
        = vlSelfRef.__Vintralsb_h5473a5fd__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v8 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_40__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_40__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v7 
        = vlSelfRef.__Vintraval_h0b8880bb__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v7 
        = vlSelfRef.__Vintralsb_h41b545e5__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v7 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_39__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__23____Vfork_39__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v7 
        = vlSelfRef.__Vintraval_h385045b5__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v7 
        = vlSelfRef.__Vintralsb_hfd59d945__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v7 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca2d98__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_43__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_44__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_45__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_46__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca2d98__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[4])");
        co_await vlSelfRef.__VtrigSched_h5cca2d98__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[4])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2794);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 4U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i = 4U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h37f0ec55__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U));
                vlSelfRef.__Vintraval_ha0a017f6__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_43__0(vlSelf);
                vlSelfRef.__Vintralsb_h07bc1e95__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U));
                vlSelfRef.__Vintraval_h20a2a0cb__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_44__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h3a232341__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hd30f8fdf__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_45__0(vlSelf);
                    vlSelfRef.__Vintralsb_h38a0c37e__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h9d3c0bc6__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_46__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[4U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v160 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v160 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v161 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v161 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v162 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v162 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v163 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v163 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v164 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v164 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v165 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v165 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v166 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v166 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v167 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v167 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v36 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v36 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v6 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v6 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v6 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v6 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v6 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v6 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v4 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v4 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v4 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v4 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v4 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v4 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v4 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v4 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__278__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v4 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_46__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_46__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v10 
        = vlSelfRef.__Vintraval_h9d3c0bc6__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v10 
        = vlSelfRef.__Vintralsb_h38a0c37e__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v10 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_45__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_45__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v10 
        = vlSelfRef.__Vintraval_hd30f8fdf__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v10 
        = vlSelfRef.__Vintralsb_h3a232341__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v10 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_44__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_44__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v9 
        = vlSelfRef.__Vintraval_h20a2a0cb__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v9 
        = vlSelfRef.__Vintralsb_h07bc1e95__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v9 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_43__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__24____Vfork_43__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v9 
        = vlSelfRef.__Vintraval_ha0a017f6__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v9 
        = vlSelfRef.__Vintralsb_h37f0ec55__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v9 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca342b__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_47__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_48__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_49__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_50__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca342b__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[5])");
        co_await vlSelfRef.__VtrigSched_h5cca342b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[5])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2795);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 5U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i = 5U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h6971b953__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U));
                vlSelfRef.__Vintraval_h204b06a4__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_47__0(vlSelf);
                vlSelfRef.__Vintralsb_hd53ba997__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U));
                vlSelfRef.__Vintraval_h45d6394f__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_48__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_hb3758930__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h6970a987__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_49__0(vlSelf);
                    vlSelfRef.__Vintralsb_hb34f45bf__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hd8e756b2__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_50__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[5U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v168 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v168 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v169 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v169 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v170 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v170 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v171 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v171 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v172 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v172 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v173 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v173 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v174 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v174 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v175 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v175 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v37 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v37 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v7 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v7 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v7 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v7 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v7 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v7 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v5 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v5 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v5 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v5 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v5 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v5 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v5 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v5 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__279__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v5 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_50__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_50__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v12 
        = vlSelfRef.__Vintraval_hd8e756b2__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v12 
        = vlSelfRef.__Vintralsb_hb34f45bf__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v12 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_49__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_49__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v12 
        = vlSelfRef.__Vintraval_h6970a987__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v12 
        = vlSelfRef.__Vintralsb_hb3758930__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v12 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_48__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_48__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v11 
        = vlSelfRef.__Vintraval_h45d6394f__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v11 
        = vlSelfRef.__Vintralsb_hd53ba997__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v11 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_47__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__25____Vfork_47__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v11 
        = vlSelfRef.__Vintraval_h204b06a4__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v11 
        = vlSelfRef.__Vintralsb_h6971b953__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v11 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3705__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_51__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_52__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_53__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_54__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3705__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[6])");
        co_await vlSelfRef.__VtrigSched_h5cca3705__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[6])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2796);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 6U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i = 6U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_hd38ff959__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U));
                vlSelfRef.__Vintraval_h64b07d2b__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_51__0(vlSelf);
                vlSelfRef.__Vintralsb_h6bdf67b9__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U));
                vlSelfRef.__Vintraval_haf1e0fe0__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_52__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h51cb3fb0__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h02c6b868__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_53__0(vlSelf);
                    vlSelfRef.__Vintralsb_h5162293f__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h91a8c848__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_54__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[6U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v176 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v176 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v177 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v177 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v178 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v178 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v179 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v179 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v180 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v180 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v181 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v181 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v182 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v182 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v183 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v183 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v38 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v38 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v8 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v8 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v8 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v8 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v8 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v8 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v6 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v6 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v6 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v6 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v6 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v6 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v6 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v6 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__280__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v6 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_54__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_54__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v14 
        = vlSelfRef.__Vintraval_h91a8c848__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v14 
        = vlSelfRef.__Vintralsb_h5162293f__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v14 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_53__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_53__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v14 
        = vlSelfRef.__Vintraval_h02c6b868__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v14 
        = vlSelfRef.__Vintralsb_h51cb3fb0__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v14 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_52__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_52__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v13 
        = vlSelfRef.__Vintraval_haf1e0fe0__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v13 
        = vlSelfRef.__Vintralsb_h6bdf67b9__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v13 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_51__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__26____Vfork_51__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v13 
        = vlSelfRef.__Vintraval_h64b07d2b__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v13 
        = vlSelfRef.__Vintralsb_hd38ff959__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v13 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3159__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_55__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_56__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_57__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_58__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3159__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[7])");
        co_await vlSelfRef.__VtrigSched_h5cca3159__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[7])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2797);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 7U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i = 7U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h663050b1__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U));
                vlSelfRef.__Vintraval_hbdf9bcba__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_55__0(vlSelf);
                vlSelfRef.__Vintralsb_hd9fbb031__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U));
                vlSelfRef.__Vintraval_h071a5b72__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_56__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h07be1aba__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hf0631220__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_57__0(vlSelf);
                    vlSelfRef.__Vintralsb_h0795b415__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hc4b9aee3__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_58__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[7U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v184 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v184 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v185 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v185 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v186 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v186 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v187 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v187 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v188 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v188 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v189 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v189 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v190 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v190 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v191 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v191 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v39 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v39 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v9 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v9 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v9 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v9 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v9 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v9 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v7 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v7 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v7 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v7 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v7 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v7 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v7 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v7 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__281__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v7 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_58__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_58__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v16 
        = vlSelfRef.__Vintraval_hc4b9aee3__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v16 
        = vlSelfRef.__Vintralsb_h0795b415__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v16 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_57__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_57__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v16 
        = vlSelfRef.__Vintraval_hf0631220__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v16 
        = vlSelfRef.__Vintralsb_h07be1aba__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v16 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_56__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_56__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v15 
        = vlSelfRef.__Vintraval_h071a5b72__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v15 
        = vlSelfRef.__Vintralsb_hd9fbb031__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v15 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_55__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__27____Vfork_55__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v15 
        = vlSelfRef.__Vintraval_hbdf9bcba__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v15 
        = vlSelfRef.__Vintralsb_h663050b1__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v15 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca349b__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_59__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_60__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_61__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_62__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca349b__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[8])");
        co_await vlSelfRef.__VtrigSched_h5cca349b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[8])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2798);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 8U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i = 8U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h1f1a487b__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U));
                vlSelfRef.__Vintraval_h769a5563__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_59__0(vlSelf);
                vlSelfRef.__Vintralsb_h1f59b51f__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U));
                vlSelfRef.__Vintraval_h055b0f8b__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_60__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h81c210fa__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h5e5e87cc__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_61__0(vlSelf);
                    vlSelfRef.__Vintralsb_h8199bf55__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hea9316a6__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_62__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[8U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v192 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v192 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v193 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v193 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v194 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v194 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v195 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v195 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v196 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v196 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v197 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v197 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v198 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v198 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v199 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v199 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v40 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v40 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v10 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v10 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v10 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v10 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v10 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v10 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v8 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v8 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v8 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v8 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v8 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v8 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v8 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v8 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__282__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v8 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_62__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_62__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v18 
        = vlSelfRef.__Vintraval_hea9316a6__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v18 
        = vlSelfRef.__Vintralsb_h8199bf55__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v18 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_61__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_61__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v18 
        = vlSelfRef.__Vintraval_h5e5e87cc__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v18 
        = vlSelfRef.__Vintralsb_h81c210fa__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v18 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_60__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_60__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v17 
        = vlSelfRef.__Vintraval_h055b0f8b__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v17 
        = vlSelfRef.__Vintralsb_h1f59b51f__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v17 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_59__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__28____Vfork_59__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v17 
        = vlSelfRef.__Vintraval_h769a5563__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v17 
        = vlSelfRef.__Vintralsb_h1f1a487b__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v17 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca36c8__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_63__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_64__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_65__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_66__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca36c8__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[9])");
        co_await vlSelfRef.__VtrigSched_h5cca36c8__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[9])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2799);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 9U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i = 9U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h3f43dce8__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U));
                vlSelfRef.__Vintraval_h0f2340d7__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_63__0(vlSelf);
                vlSelfRef.__Vintralsb_h0133673c__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U));
                vlSelfRef.__Vintraval_h3e4025b3__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_64__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_hd8949e1a__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h4b791da2__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_65__0(vlSelf);
                    vlSelfRef.__Vintralsb_hd9e82fb5__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h93713b10__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_66__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[9U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v200 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v200 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v201 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v201 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v202 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v202 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v203 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v203 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v204 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v204 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v205 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v205 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v206 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v206 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v207 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v207 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v41 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v41 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v11 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v11 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v11 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v11 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v11 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v11 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v9 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v9 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v9 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v9 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v9 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v9 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v9 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v9 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__283__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v9 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_66__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_66__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v20 
        = vlSelfRef.__Vintraval_h93713b10__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v20 
        = vlSelfRef.__Vintralsb_hd9e82fb5__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v20 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_65__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_65__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v20 
        = vlSelfRef.__Vintraval_h4b791da2__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v20 
        = vlSelfRef.__Vintralsb_hd8949e1a__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v20 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_64__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_64__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v19 
        = vlSelfRef.__Vintraval_h3e4025b3__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v19 
        = vlSelfRef.__Vintralsb_h0133673c__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v19 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_63__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__29____Vfork_63__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v19 
        = vlSelfRef.__Vintraval_h0f2340d7__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v19 
        = vlSelfRef.__Vintralsb_h3f43dce8__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v19 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3e44__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_67__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_68__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_69__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_70__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3e44__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[10])");
        co_await vlSelfRef.__VtrigSched_h5cca3e44__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[10])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2800);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x0aU)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i = 0x0aU;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h2bd60927__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U));
                vlSelfRef.__Vintraval_h6dcba91d__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_67__0(vlSelf);
                vlSelfRef.__Vintralsb_h1425f87b__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U));
                vlSelfRef.__Vintraval_hc7ed9d99__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_68__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h7ba5e197__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hcd0fa031__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_69__0(vlSelf);
                    vlSelfRef.__Vintralsb_h7aff6ee8__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h93be7041__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_70__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[10U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v208 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v208 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v209 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v209 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v210 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v210 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v211 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v211 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v212 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v212 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v213 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v213 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v214 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v214 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v215 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v215 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v42 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v42 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v12 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v12 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v12 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v12 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v12 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v12 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v10 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v10 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v10 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v10 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v10 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v10 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v10 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v10 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__284__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v10 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_70__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_70__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v22 
        = vlSelfRef.__Vintraval_h93be7041__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v22 
        = vlSelfRef.__Vintralsb_h7aff6ee8__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v22 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_69__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_69__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v22 
        = vlSelfRef.__Vintraval_hcd0fa031__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v22 
        = vlSelfRef.__Vintralsb_h7ba5e197__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v22 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_68__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_68__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v21 
        = vlSelfRef.__Vintraval_hc7ed9d99__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v21 
        = vlSelfRef.__Vintralsb_h1425f87b__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v21 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_67__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__30____Vfork_67__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v21 
        = vlSelfRef.__Vintraval_h6dcba91d__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v21 
        = vlSelfRef.__Vintralsb_h2bd60927__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v21 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3476__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_71__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_72__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_73__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_74__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3476__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[11])");
        co_await vlSelfRef.__VtrigSched_h5cca3476__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[11])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2801);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x0bU)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i = 0x0bU;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_hdf382097__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U));
                vlSelfRef.__Vintraval_h22311016__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_71__0(vlSelf);
                vlSelfRef.__Vintralsb_h6113fccb__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U));
                vlSelfRef.__Vintraval_hc22c2dd4__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_72__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_hb8a1ec13__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hf079c7cb__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_73__0(vlSelf);
                    vlSelfRef.__Vintralsb_hb9fa8064__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hc355eba7__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_74__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[11U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v216 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v216 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v217 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v217 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v218 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v218 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v219 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v219 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v220 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v220 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v221 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v221 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v222 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v222 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v223 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v223 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v43 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v43 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v13 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v13 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v13 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v13 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v13 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v13 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v11 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v11 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v11 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v11 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v11 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v11 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v11 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v11 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__285__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v11 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_74__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_74__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v24 
        = vlSelfRef.__Vintraval_hc355eba7__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v24 
        = vlSelfRef.__Vintralsb_hb9fa8064__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v24 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_73__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_73__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v24 
        = vlSelfRef.__Vintraval_hf079c7cb__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v24 
        = vlSelfRef.__Vintralsb_hb8a1ec13__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v24 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_72__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_72__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v23 
        = vlSelfRef.__Vintraval_hc22c2dd4__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v23 
        = vlSelfRef.__Vintralsb_h6113fccb__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v23 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_71__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__31____Vfork_71__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v23 
        = vlSelfRef.__Vintraval_h22311016__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v23 
        = vlSelfRef.__Vintralsb_hdf382097__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v23 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca37c2__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_75__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_76__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_77__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_78__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca37c2__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[12])");
        co_await vlSelfRef.__VtrigSched_h5cca37c2__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[12])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2802);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x0cU)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i = 0x0cU;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h49554d97__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U));
                vlSelfRef.__Vintraval_h374a500c__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_75__0(vlSelf);
                vlSelfRef.__Vintralsb_hf5a113cb__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U));
                vlSelfRef.__Vintraval_hd6b59ad0__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_76__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_hd2080853__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h20655c10__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_77__0(vlSelf);
                    vlSelfRef.__Vintralsb_hd08bbea4__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h83095b0b__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_78__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[12U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v224 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v224 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v225 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v225 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v226 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v226 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v227 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v227 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v228 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v228 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v229 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v229 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v230 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v230 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v231 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v231 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v44 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v44 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v14 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v14 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v14 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v14 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v14 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v14 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v12 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v12 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v12 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v12 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v12 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v12 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v12 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v12 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__286__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v12 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_78__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_78__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v26 
        = vlSelfRef.__Vintraval_h83095b0b__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v26 
        = vlSelfRef.__Vintralsb_hd08bbea4__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v26 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_77__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_77__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v26 
        = vlSelfRef.__Vintraval_h20655c10__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v26 
        = vlSelfRef.__Vintralsb_hd2080853__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v26 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_76__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_76__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v25 
        = vlSelfRef.__Vintraval_hd6b59ad0__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v25 
        = vlSelfRef.__Vintralsb_hf5a113cb__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v25 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_75__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__32____Vfork_75__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v25 
        = vlSelfRef.__Vintraval_h374a500c__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v25 
        = vlSelfRef.__Vintralsb_h49554d97__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v25 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3201__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_79__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_80__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_81__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_82__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3201__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[13])");
        co_await vlSelfRef.__VtrigSched_h5cca3201__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[13])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2803);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x0dU)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i = 0x0dU;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h3dc5ecf9__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U));
                vlSelfRef.__Vintraval_h452fe6e4__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_79__0(vlSelf);
                vlSelfRef.__Vintralsb_h01b13799__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U));
                vlSelfRef.__Vintraval_h337af308__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_80__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_hf63a56e8__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h6950b66f__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_81__0(vlSelf);
                    vlSelfRef.__Vintralsb_hf911f177__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hbd129dd7__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_82__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[13U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v232 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v232 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v233 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v233 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v234 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v234 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v235 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v235 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v236 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v236 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v237 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v237 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v238 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v238 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v239 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v239 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v45 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v45 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v15 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v15 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v15 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v15 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v15 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v15 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v13 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v13 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v13 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v13 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v13 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v13 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v13 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v13 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__287__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v13 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_82__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_82__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v28 
        = vlSelfRef.__Vintraval_hbd129dd7__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v28 
        = vlSelfRef.__Vintralsb_hf911f177__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v28 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_81__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_81__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v28 
        = vlSelfRef.__Vintraval_h6950b66f__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v28 
        = vlSelfRef.__Vintralsb_hf63a56e8__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v28 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_80__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_80__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v27 
        = vlSelfRef.__Vintraval_h337af308__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v27 
        = vlSelfRef.__Vintralsb_h01b13799__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v27 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_79__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__33____Vfork_79__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v27 
        = vlSelfRef.__Vintraval_h452fe6e4__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v27 
        = vlSelfRef.__Vintralsb_h3dc5ecf9__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v27 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca590b__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_83__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_84__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_85__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_86__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca590b__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[14])");
        co_await vlSelfRef.__VtrigSched_h5cca590b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[14])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2804);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x0eU)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i = 0x0eU;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_hd18b80a6__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U));
                vlSelfRef.__Vintraval_hbb0342e1__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_83__0(vlSelf);
                vlSelfRef.__Vintralsb_h6e2b6006__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U));
                vlSelfRef.__Vintraval_h878d5ab1__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_84__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_hdd4c6a38__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h4fcaf6a2__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_85__0(vlSelf);
                    vlSelfRef.__Vintralsb_hdde6fb47__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hda664231__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_86__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[14U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v240 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v240 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v241 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v241 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v242 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v242 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v243 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v243 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v244 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v244 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v245 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v245 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v246 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v246 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v247 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v247 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v46 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v46 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v16 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v16 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v16 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v16 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v16 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v16 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v14 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v14 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v14 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v14 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v14 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v14 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v14 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v14 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__288__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v14 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_86__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_86__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v30 
        = vlSelfRef.__Vintraval_hda664231__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v30 
        = vlSelfRef.__Vintralsb_hdde6fb47__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v30 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_85__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_85__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v30 
        = vlSelfRef.__Vintraval_h4fcaf6a2__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v30 
        = vlSelfRef.__Vintralsb_hdd4c6a38__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v30 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_84__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_84__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v29 
        = vlSelfRef.__Vintraval_h878d5ab1__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v29 
        = vlSelfRef.__Vintralsb_h6e2b6006__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v29 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_83__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__34____Vfork_83__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v29 
        = vlSelfRef.__Vintraval_hbb0342e1__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v29 
        = vlSelfRef.__Vintralsb_hd18b80a6__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v29 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3b4b__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_87__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_88__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_89__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_90__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca3b4b__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[15])");
        co_await vlSelfRef.__VtrigSched_h5cca3b4b__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[15])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2805);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x0fU)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i = 0x0fU;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h871b98f5__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U));
                vlSelfRef.__Vintraval_hbbf08367__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_87__0(vlSelf);
                vlSelfRef.__Vintralsb_hb7598b75__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U));
                vlSelfRef.__Vintraval_h66e87d51__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_88__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h2d5dda89__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hbbc4eef8__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_89__0(vlSelf);
                    vlSelfRef.__Vintralsb_h2db76de6__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h0480713d__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_90__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[15U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v248 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v248 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v249 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v249 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v250 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v250 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v251 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v251 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v252 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v252 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v253 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v253 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v254 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v254 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v255 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v255 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v47 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v47 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v17 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v17 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v17 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v17 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v17 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v17 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v15 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v15 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v15 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v15 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v15 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v15 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v15 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v15 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__289__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v15 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_90__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_90__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v32 
        = vlSelfRef.__Vintraval_h0480713d__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v32 
        = vlSelfRef.__Vintralsb_h2db76de6__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v32 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_89__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_89__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v32 
        = vlSelfRef.__Vintraval_hbbc4eef8__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v32 
        = vlSelfRef.__Vintralsb_h2d5dda89__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v32 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_88__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_88__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v31 
        = vlSelfRef.__Vintraval_h66e87d51__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v31 
        = vlSelfRef.__Vintralsb_hb7598b75__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v31 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_87__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__35____Vfork_87__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v31 
        = vlSelfRef.__Vintraval_hbbf08367__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v31 
        = vlSelfRef.__Vintralsb_h871b98f5__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v31 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca66b5__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_91__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_92__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_93__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_94__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca66b5__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[16])");
        co_await vlSelfRef.__VtrigSched_h5cca66b5__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[16])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2806);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x10U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i = 0x10U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_hbeec5d98__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U));
                vlSelfRef.__Vintraval_h193eaa19__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_91__0(vlSelf);
                vlSelfRef.__Vintralsb_h7f87e3cc__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U));
                vlSelfRef.__Vintraval_h1757169e__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_92__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h0064ab16__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hfc5746c8__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_93__0(vlSelf);
                    vlSelfRef.__Vintralsb_h02b86561__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h74aed05d__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_94__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[16U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v256 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v256 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v257 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v257 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v258 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v258 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v259 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v259 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v260 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v260 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v261 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v261 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v262 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v262 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v263 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v263 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v48 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v48 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v18 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v18 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v18 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v18 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v18 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v18 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v16 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v16 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v16 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v16 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v16 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v16 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v16 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v16 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__290__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v16 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_94__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_94__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v34 
        = vlSelfRef.__Vintraval_h74aed05d__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v34 
        = vlSelfRef.__Vintralsb_h02b86561__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v34 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_93__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_93__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v34 
        = vlSelfRef.__Vintraval_hfc5746c8__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v34 
        = vlSelfRef.__Vintralsb_h0064ab16__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v34 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_92__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_92__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v33 
        = vlSelfRef.__Vintraval_h1757169e__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v33 
        = vlSelfRef.__Vintralsb_h7f87e3cc__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v33 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_91__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__36____Vfork_91__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v33 
        = vlSelfRef.__Vintraval_h193eaa19__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v33 
        = vlSelfRef.__Vintralsb_hbeec5d98__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v33 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca58e6__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_95__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_96__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_97__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_98__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca58e6__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[17])");
        co_await vlSelfRef.__VtrigSched_h5cca58e6__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[17])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2807);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x11U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i = 0x11U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_hbab09f5e__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U));
                vlSelfRef.__Vintraval_h02aa34fa__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_95__0(vlSelf);
                vlSelfRef.__Vintralsb_h7c7e79be__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U));
                vlSelfRef.__Vintraval_h3cc722d4__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_96__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h3b2a0eba__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h0e930142__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_97__0(vlSelf);
                    vlSelfRef.__Vintralsb_h3bc1d815__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_ha4747d00__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_98__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[17U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v264 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v264 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v265 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v265 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v266 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v266 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v267 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v267 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v268 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v268 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v269 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v269 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v270 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v270 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v271 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v271 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v49 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v49 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v19 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v19 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v19 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v19 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v19 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v19 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v17 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v17 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v17 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v17 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v17 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v17 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v17 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v17 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__291__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v17 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_98__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_98__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v36 
        = vlSelfRef.__Vintraval_ha4747d00__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v36 
        = vlSelfRef.__Vintralsb_h3bc1d815__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v36 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_97__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_97__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v36 
        = vlSelfRef.__Vintraval_h0e930142__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v36 
        = vlSelfRef.__Vintralsb_h3b2a0eba__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v36 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_96__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_96__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v35 
        = vlSelfRef.__Vintraval_h3cc722d4__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v35 
        = vlSelfRef.__Vintralsb_h7c7e79be__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v35 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_95__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__37____Vfork_95__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v35 
        = vlSelfRef.__Vintraval_h02aa34fa__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v35 
        = vlSelfRef.__Vintralsb_hbab09f5e__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v35 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca301a__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_99__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_100__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_101__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_102__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca301a__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[18])");
        co_await vlSelfRef.__VtrigSched_h5cca301a__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[18])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2808);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x12U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i = 0x12U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h85982476__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U));
                vlSelfRef.__Vintraval_h181c6548__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_99__0(vlSelf);
                vlSelfRef.__Vintralsb_hb9f408f6__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U));
                vlSelfRef.__Vintraval_haa3f9c24__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_100__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h515eb22c__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h882fc7a8__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_101__0(vlSelf);
                    vlSelfRef.__Vintralsb_h51b6333b__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h0b35f5cc__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_102__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[18U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v272 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v272 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v273 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v273 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v274 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v274 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v275 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v275 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v276 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v276 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v277 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v277 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v278 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v278 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v279 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v279 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v50 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v50 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v20 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v20 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v20 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v20 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v20 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v20 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v18 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v18 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v18 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v18 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v18 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v18 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v18 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v18 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__292__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v18 = 1U;
        }
    }
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_102__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_102__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2743);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v38 
        = vlSelfRef.__Vintraval_h0b35f5cc__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v38 
        = vlSelfRef.__Vintralsb_h51b6333b__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v38 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_101__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_101__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x000000000000251cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2742);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v38 
        = vlSelfRef.__Vintraval_h882fc7a8__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v38 
        = vlSelfRef.__Vintralsb_h515eb22c__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v38 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_100__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_100__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2734);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v37 
        = vlSelfRef.__Vintraval_haa3f9c24__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v37 
        = vlSelfRef.__Vintralsb_hb9f408f6__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v37 = 1U;
    co_return;
}

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_99__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__38____Vfork_99__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x0000000000001d4cULL, 
                                         nullptr, "ip/ddr3/sim/vendor/ddr3.v", 
                                         2733);
    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v37 
        = vlSelfRef.__Vintraval_h181c6548__0;
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v37 
        = vlSelfRef.__Vintralsb_h85982476__0;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v37 = 1U;
    co_return;
}

void Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca6678__0(Vtb_ddr3_init_top___024root* vlSelf, const char* __VeventDescription);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39____Vfork_103__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39____Vfork_104__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39____Vfork_105__0(Vtb_ddr3_init_top___024root* vlSelf);
VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39____Vfork_106__0(Vtb_ddr3_init_top___024root* vlSelf);

VlCoroutine Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i = 0;
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        Vtb_ddr3_init_top___024root____VbeforeTrig_h5cca6678__0(vlSelf, 
                                                                "@(posedge tb_ddr3_init_top.u_micron.dqs_in[19])");
        co_await vlSelfRef.__VtrigSched_h5cca6678__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ddr3_init_top.u_micron.dqs_in[19])", 
                                                             "ip/ddr3/sim/vendor/ddr3.v", 
                                                             2809);
        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                           >> 0x13U)))) {
            __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i = 0x13U;
            if (VL_UNLIKELY((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization))) {
                if (VL_UNLIKELY((VL_GTS_III(32, 0x00000028U, 
                                            (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tWLMRD violation on DQS bit %d positive edge.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i));
                }
                if (VL_UNLIKELY((((0x00000000000000a5ULL 
                                   > ((QData)(VL_TIME_UNITED_Q(1)) 
                                      - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos)) 
                                  | (0x00000000000000a5ULL 
                                     > ((QData)(VL_TIME_UNITED_Q(1)) 
                                        - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg)))))) {
                    VL_WRITEF_NX("%m: at time %t WARNING: tWLS violation on DQS bit %d positive edge.  Indeterminate CK capture is possible.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i));
                }
                VL_WRITEF_NX("%m: at time %t Write Leveling @ DQS ck = %b\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',1,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
                vlSelfRef.__Vintralsb_h0409f9db__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U));
                vlSelfRef.__Vintraval_h5386a100__0 = 1U;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39____Vfork_103__0(vlSelf);
                vlSelfRef.__Vintralsb_h3aa9ee3f__0 
                    = (7U & VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U));
                vlSelfRef.__Vintraval_h52454d0c__0 
                    = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
                Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39____Vfork_104__0(vlSelf);
                vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                while ((8U > (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j))) {
                    vlSelfRef.__Vintralsb_h911d40a2__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_h8c1e4aa9__0 = 1U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39____Vfork_105__0(vlSelf);
                    vlSelfRef.__Vintralsb_h91700f1d__0 
                        = (7U & (VL_SHIFTL_III(3,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U) 
                                 + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                    vlSelfRef.__Vintraval_hff67720e__0 = 0U;
                    Vtb_ddr3_init_top___024root___eval_initial__TOP__Vtiming__39____Vfork_106__0(vlSelf);
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j)));
                }
            }
            if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
                 & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[19U] 
                     < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                    | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
                if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                               >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i))) 
                                      ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i)))))))) {
                    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                        if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (9.00000000000000022e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i)));
                            }
                        } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                                  >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i))))) {
                            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i]) 
                                              < (QData)((IData)(
                                                                VL_RTOI_I_D(
                                                                            (2.99999999999999989e-01 
                                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                                VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                             , '#',64,VL_TIME_UNITED_Q(1)
                                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                             [(1U & 
                                               ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i) 
                                                >> 5U))]
                                             , '#',32,
                                             (0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i)));
                            }
                        } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                                  - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                                  [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i]) 
                                                 < (QData)((IData)(
                                                                   VL_RTOI_I_D(
                                                                               (4.50000000000000011e-01 
                                                                                * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i)));
                        }
                    }
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                         [(0x0000001fU 
                                           & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                                [(0x0000001fU 
                                                  & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 0U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x78U 
                                               & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U)
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x78U 
                                                     & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v280 
                            = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v280 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(1U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(1U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(1U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 2U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v281 
                            = (0x0000007fU & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v281 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 3U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(2U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(2U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(2U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 4U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v282 
                            = (0x0000007fU & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v282 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 5U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(3U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(3U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(3U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 6U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v283 
                            = (0x0000007fU & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v283 = 1U;
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 7U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(4U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(4U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(4U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v284 
                            = (0x0000007fU & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v284 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(5U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(5U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(5U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v285 
                            = (0x0000007fU & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v285 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(6U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(6U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(6U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v286 
                            = (0x0000007fU & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v286 = 1U;
                        if (VL_UNLIKELY(((0x000000000000000aULL 
                                          > ((QData)(VL_TIME_UNITED_Q(1)) 
                                             - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                             [(0x0000007fU 
                                               & ((IData)(7U) 
                                                  + 
                                                  (0x78U 
                                                   & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',32,((IData)(7U) 
                                                   + 
                                                   VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))
                                         , '#',64,(
                                                   (0x000000000000000aULL 
                                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                    [
                                                    (0x0000007fU 
                                                     & ((IData)(7U) 
                                                        + 
                                                        (0x78U 
                                                         & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))))]) 
                                                   - (QData)(VL_TIME_UNITED_Q(1))));
                        }
                        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v287 
                            = (0x0000007fU & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i), 3U))));
                        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v287 = 1U;
                    }
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146 
                        = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                             [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i] 
                             < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                            & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                            ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i])
                            : 1U);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v51 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v51 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v21 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v21 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v21 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v21 = 1U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v21 
                        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i;
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v21 = 1U;
                    vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v19 
                        = VL_TIME_UNITED_Q(1);
                    vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v19 
                        = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v19 = 1U;
                } else {
                    VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                 [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i) 
                                         >> 5U))], '#',32,
                                 (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i)));
                }
            }
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v19 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v19 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v19 = 1U;
            vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i] 
                = VL_TIME_UNITED_Q(1);
            vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v19 
                = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                 >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i))));
            vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v19 
                = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__293__i;
            vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v19 = 1U;
        }
    }
    co_return;
}

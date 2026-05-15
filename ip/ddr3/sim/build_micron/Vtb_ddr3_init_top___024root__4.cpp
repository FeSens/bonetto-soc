// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ddr3_init_top.h for the primary calling header

#include "Vtb_ddr3_init_top__pch.h"

void Vtb_ddr3_init_top___024root___act_sequent__TOP__180(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__180\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i = 0x57U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v87 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v87 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__233__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__181(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__181\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i = 0x58U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v88 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v88 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__234__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__182(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__182\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i = 0x59U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v89 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v89 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__235__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__183(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__183\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i = 0x5aU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v90 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v90 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__236__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__184(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__184\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i = 0x5bU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v91 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v91 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__237__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__185(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__185\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i = 0x5cU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v92 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v92 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__238__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__186(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__186\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i = 0x5dU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v93 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v93 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__239__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__187(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__187\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i = 0x5eU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v94 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v94 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__240__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__188(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__188\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i = 0x5fU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v95 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v95 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__241__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__189(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__189\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i = 0x60U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v96 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v96 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__242__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__190(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__190\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i = 0x61U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v97 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v97 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__243__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__191(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__191\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i = 0x62U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v98 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v98 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__244__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__192(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__192\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i = 0x63U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v99 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v99 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__245__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__193(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__193\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i = 0x64U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v100 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v100 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__246__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__194(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__194\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i = 0x65U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v101 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v101 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__247__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__195(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__195\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i = 0x66U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v102 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v102 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__248__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__196(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__196\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i = 0x67U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v103 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v103 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__249__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__197(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__197\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i = 0x68U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v104 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v104 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__250__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__198(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__198\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i = 0x69U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v105 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v105 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__251__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__199(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__199\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i = 0x6aU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v106 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v106 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__252__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__200(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__200\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i = 0x6bU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v107 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v107 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__253__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__201(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__201\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i = 0x6cU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v108 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v108 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__254__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__202(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__202\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i = 0x6dU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v109 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v109 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__255__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__203(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__203\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i = 0x6eU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v110 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v110 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__256__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__204(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__204\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i = 0x6fU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v111 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v111 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__257__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__205(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__205\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i = 0x70U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v112 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v112 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__258__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__206(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__206\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i = 0x71U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v113 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v113 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__259__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__207(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__207\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i = 0x72U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v114 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v114 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__260__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__208(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__208\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i = 0x73U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v115 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v115 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__261__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__209(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__209\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i = 0x74U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v116 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v116 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__262__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__210(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__210\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i = 0x75U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v117 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v117 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__263__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__211(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__211\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i = 0x76U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v118 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v118 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__264__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__212(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__212\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i = 0x77U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v119 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v119 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__265__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__213(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__213\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i = 0x78U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v120 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v120 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__266__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__214(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__214\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i = 0x79U;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v121 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v121 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__267__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__215(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__215\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i = 0x7aU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v122 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v122 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__268__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__216(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__216\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i = 0x7bU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v123 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v123 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__269__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__217(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__217\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i = 0x7cU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v124 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v124 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__270__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__218(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__218\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i = 0x7dU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v125 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v125 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__271__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__219(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__219\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i = 0x7eU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v126 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v126 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__272__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__220(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__220\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i = 0;
    // Body
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i = 0x7fU;
    if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) {
        if (VL_UNLIKELY(((0x000000000000002dULL > ((QData)(VL_TIME_UNITED_Q(1)) 
                                                   - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                                   [
                                                   (0x0000001fU 
                                                    & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i) 
                                                       >> 3U))]))))) {
            VL_WRITEF_NX("%m: at time %t ERROR:   tDH violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                         , '#',64,VL_TIME_UNITED_Q(1)
                         , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i)
                         , '#',64,((0x000000000000002dULL 
                                    + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs
                                    [(0x0000001fU & 
                                      ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i) 
                                       >> 3U))]) - (QData)(VL_TIME_UNITED_Q(1))));
        }
        if ((1U & (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw
                   [((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i) 
                     >> 5U)] >> (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i))))) {
            if (VL_UNLIKELY(((0x0000000000000168ULL 
                              > ((QData)(VL_TIME_UNITED_Q(1)) 
                                 - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i]))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDIPW violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dq_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',7,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i)
                             , '#',64,((0x0000000000000168ULL 
                                        + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                        [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i]) 
                                       - (QData)(VL_TIME_UNITED_Q(1))));
            }
        }
    }
    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v127 
        = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i;
    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v127 = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dq_timing_check__273__i] 
        = VL_TIME_UNITED_Q(1);
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__221(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__221\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x20U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i = 0x20U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[32U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v384 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v384 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v385 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v385 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v386 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v386 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v387 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v387 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v388 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v388 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v389 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v389 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v390 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v390 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v391 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v391 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v64 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v64 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v34 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v34 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v34 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v34 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v34 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v34 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v32 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v32 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v32 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v32 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v32 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v32 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v32 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v32 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__306__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v32 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__222(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__222\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x21U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i = 0x21U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[33U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v392 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v392 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v393 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v393 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v394 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v394 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v395 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v395 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v396 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v396 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v397 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v397 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v398 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v398 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v399 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v399 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v65 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v65 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v35 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v35 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v35 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v35 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v35 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v35 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v33 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v33 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v33 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v33 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v33 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v33 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v33 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v33 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__307__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v33 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__223(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__223\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x22U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i = 0x22U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[34U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v400 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v400 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v401 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v401 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v402 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v402 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v403 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v403 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v404 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v404 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v405 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v405 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v406 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v406 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v407 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v407 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v66 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v66 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v36 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v36 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v36 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v36 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v36 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v36 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v34 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v34 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v34 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v34 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v34 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v34 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v34 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v34 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__308__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v34 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__224(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__224\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x23U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i = 0x23U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[35U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v408 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v408 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v409 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v409 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v410 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v410 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v411 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v411 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v412 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v412 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v413 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v413 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v414 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v414 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v415 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v415 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v67 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v67 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v37 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v37 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v37 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v37 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v37 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v37 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v35 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v35 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v35 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v35 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v35 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v35 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v35 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v35 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__309__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v35 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__225(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__225\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x24U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i = 0x24U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[36U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v416 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v416 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v417 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v417 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v418 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v418 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v419 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v419 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v420 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v420 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v421 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v421 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v422 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v422 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v423 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v423 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v68 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v68 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v38 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v38 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v38 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v38 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v38 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v38 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v36 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v36 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v36 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v36 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v36 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v36 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v36 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v36 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__310__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v36 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__226(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__226\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x25U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i = 0x25U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[37U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v424 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v424 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v425 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v425 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v426 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v426 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v427 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v427 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v428 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v428 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v429 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v429 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v430 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v430 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v431 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v431 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v69 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v69 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v39 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v39 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v39 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v39 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v39 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v39 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v37 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v37 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v37 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v37 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v37 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v37 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v37 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v37 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__311__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v37 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__227(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__227\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x26U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i = 0x26U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[38U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v432 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v432 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v433 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v433 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v434 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v434 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v435 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v435 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v436 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v436 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v437 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v437 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v438 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v438 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v439 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v439 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v70 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v70 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v40 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v40 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v40 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v40 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v40 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v40 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v38 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v38 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v38 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v38 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v38 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v38 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v38 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v38 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__312__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v38 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__228(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__228\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x27U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i = 0x27U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[39U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v440 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v440 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v441 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v441 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v442 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v442 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v443 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v443 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v444 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v444 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v445 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v445 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v446 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v446 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v447 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v447 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v71 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v71 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v41 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v41 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v41 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v41 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v41 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v41 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v39 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v39 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v39 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v39 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v39 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v39 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v39 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v39 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__313__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v39 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__229(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__229\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x28U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i = 0x28U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[40U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v448 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v448 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v449 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v449 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v450 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v450 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v451 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v451 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v452 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v452 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v453 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v453 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v454 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v454 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v455 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v455 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v72 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v72 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v42 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v42 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v42 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v42 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v42 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v42 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v40 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v40 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v40 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v40 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v40 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v40 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v40 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v40 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__314__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v40 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__230(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__230\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x29U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i = 0x29U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[41U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v456 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v456 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v457 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v457 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v458 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v458 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v459 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v459 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v460 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v460 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v461 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v461 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v462 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v462 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v463 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v463 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v73 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v73 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v43 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v43 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v43 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v43 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v43 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v43 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v41 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v41 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v41 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v41 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v41 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v41 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v41 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v41 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__315__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v41 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__231(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__231\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x2aU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i = 0x2aU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[42U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v464 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v464 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v465 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v465 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v466 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v466 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v467 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v467 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v468 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v468 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v469 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v469 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v470 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v470 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v471 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v471 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v74 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v74 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v44 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v44 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v44 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v44 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v44 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v44 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v42 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v42 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v42 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v42 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v42 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v42 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v42 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v42 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__316__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v42 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__232(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__232\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x2bU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i = 0x2bU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[43U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v472 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v472 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v473 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v473 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v474 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v474 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v475 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v475 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v476 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v476 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v477 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v477 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v478 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v478 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v479 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v479 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v75 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v75 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v45 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v45 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v45 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v45 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v45 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v45 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v43 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v43 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v43 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v43 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v43 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v43 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v43 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v43 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__317__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v43 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__233(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__233\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x2cU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i = 0x2cU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[44U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v480 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v480 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v481 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v481 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v482 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v482 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v483 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v483 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v484 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v484 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v485 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v485 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v486 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v486 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v487 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v487 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v76 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v76 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v46 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v46 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v46 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v46 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v46 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v46 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v44 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v44 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v44 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v44 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v44 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v44 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v44 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v44 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__318__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v44 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__234(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__234\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x2dU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i = 0x2dU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[45U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v488 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v488 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v489 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v489 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v490 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v490 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v491 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v491 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v492 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v492 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v493 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v493 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v494 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v494 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v495 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v495 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v77 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v77 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v47 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v47 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v47 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v47 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v47 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v47 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v45 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v45 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v45 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v45 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v45 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v45 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v45 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v45 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__319__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v45 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__235(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__235\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x2eU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i = 0x2eU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[46U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v496 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v496 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v497 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v497 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v498 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v498 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v499 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v499 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v500 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v500 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v501 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v501 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v502 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v502 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v503 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v503 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v78 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v78 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v48 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v48 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v48 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v48 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v48 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v48 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v46 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v46 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v46 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v46 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v46 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v46 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v46 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v46 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__320__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v46 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__236(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__236\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x2fU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i = 0x2fU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[47U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v504 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v504 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v505 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v505 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v506 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v506 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v507 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v507 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v508 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v508 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v509 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v509 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v510 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v510 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v511 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v511 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v79 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v79 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v49 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v49 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v49 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v49 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v49 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v49 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v47 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v47 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v47 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v47 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v47 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v47 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v47 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v47 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__321__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v47 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__237(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__237\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x30U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i = 0x30U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[48U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v512 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v512 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v513 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v513 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v514 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v514 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v515 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v515 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v516 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v516 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v517 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v517 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v518 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v518 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v519 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v519 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v80 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v80 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v50 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v50 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v50 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v50 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v50 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v50 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v48 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v48 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v48 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v48 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v48 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v48 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v48 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v48 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__322__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v48 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__238(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__238\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x31U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i = 0x31U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[49U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v520 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v520 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v521 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v521 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v522 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v522 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v523 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v523 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v524 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v524 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v525 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v525 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v526 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v526 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v527 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v527 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v81 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v81 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v51 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v51 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v51 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v51 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v51 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v51 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v49 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v49 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v49 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v49 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v49 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v49 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v49 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v49 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__323__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v49 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__239(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__239\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x32U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i = 0x32U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[50U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v528 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v528 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v529 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v529 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v530 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v530 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v531 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v531 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v532 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v532 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v533 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v533 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v534 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v534 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v535 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v535 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v82 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v82 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v52 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v52 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v52 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v52 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v52 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v52 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v50 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v50 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v50 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v50 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v50 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v50 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v50 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v50 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__324__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v50 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__240(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__240\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x33U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i = 0x33U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[51U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v536 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v536 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v537 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v537 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v538 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v538 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v539 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v539 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v540 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v540 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v541 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v541 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v542 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v542 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v543 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v543 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v83 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v83 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v53 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v53 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v53 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v53 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v53 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v53 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v51 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v51 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v51 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v51 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v51 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v51 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v51 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v51 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__325__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v51 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__241(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__241\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x34U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i = 0x34U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[52U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v544 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v544 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v545 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v545 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v546 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v546 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v547 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v547 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v548 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v548 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v549 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v549 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v550 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v550 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v551 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v551 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v84 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v84 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v54 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v54 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v54 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v54 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v54 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v54 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v52 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v52 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v52 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v52 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v52 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v52 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v52 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v52 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__326__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v52 = 1U;
    }
}

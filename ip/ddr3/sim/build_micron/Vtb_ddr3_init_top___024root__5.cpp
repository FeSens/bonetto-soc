// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ddr3_init_top.h for the primary calling header

#include "Vtb_ddr3_init_top__pch.h"

void Vtb_ddr3_init_top___024root___act_sequent__TOP__242(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__242\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x35U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i = 0x35U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[53U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v552 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v552 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v553 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v553 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v554 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v554 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v555 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v555 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v556 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v556 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v557 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v557 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v558 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v558 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v559 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v559 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v85 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v85 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v55 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v55 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v55 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v55 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v55 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v55 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v53 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v53 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v53 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v53 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v53 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v53 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v53 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v53 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__327__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v53 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__243(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__243\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x36U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i = 0x36U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[54U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v560 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v560 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v561 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v561 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v562 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v562 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v563 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v563 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v564 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v564 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v565 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v565 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v566 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v566 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v567 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v567 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v86 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v86 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v56 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v56 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v56 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v56 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v56 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v56 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v54 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v54 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v54 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v54 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v54 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v54 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v54 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v54 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__328__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v54 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__244(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__244\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x37U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i = 0x37U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[55U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v568 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v568 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v569 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v569 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v570 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v570 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v571 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v571 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v572 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v572 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v573 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v573 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v574 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v574 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v575 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v575 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v87 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v87 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v57 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v57 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v57 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v57 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v57 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v57 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v55 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v55 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v55 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v55 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v55 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v55 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v55 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v55 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__329__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v55 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__245(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__245\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x38U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i = 0x38U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[56U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v576 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v576 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v577 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v577 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v578 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v578 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v579 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v579 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v580 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v580 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v581 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v581 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v582 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v582 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v583 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v583 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v88 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v88 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v58 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v58 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v58 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v58 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v58 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v58 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v56 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v56 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v56 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v56 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v56 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v56 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v56 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v56 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__330__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v56 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__246(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__246\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x39U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i = 0x39U;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[57U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v584 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v584 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v585 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v585 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v586 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v586 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v587 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v587 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v588 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v588 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v589 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v589 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v590 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v590 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v591 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v591 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v89 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v89 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v59 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v59 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v59 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v59 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v59 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v59 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v57 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v57 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v57 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v57 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v57 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v57 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v57 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v57 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__331__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v57 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__247(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__247\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x3aU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i = 0x3aU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[58U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v592 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v592 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v593 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v593 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v594 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v594 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v595 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v595 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v596 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v596 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v597 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v597 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v598 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v598 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v599 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v599 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v90 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v90 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v60 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v60 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v60 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v60 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v60 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v60 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v58 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v58 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v58 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v58 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v58 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v58 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v58 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v58 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__332__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v58 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__248(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__248\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x3bU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i = 0x3bU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[59U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v600 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v600 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v601 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v601 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v602 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v602 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v603 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v603 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v604 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v604 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v605 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v605 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v606 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v606 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v607 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v607 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v91 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v91 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v61 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v61 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v61 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v61 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v61 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v61 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v59 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v59 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v59 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v59 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v59 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v59 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v59 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v59 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__333__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v59 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__249(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__249\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x3cU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i = 0x3cU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[60U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v608 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v608 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v609 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v609 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v610 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v610 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v611 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v611 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v612 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v612 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v613 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v613 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v614 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v614 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v615 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v615 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v92 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v92 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v62 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v62 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v62 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v62 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v62 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v62 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v60 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v60 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v60 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v60 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v60 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v60 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v60 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v60 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__334__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v60 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__250(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__250\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x3dU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i = 0x3dU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[61U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v616 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v616 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v617 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v617 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v618 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v618 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v619 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v619 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v620 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v620 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v621 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v621 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v622 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v622 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v623 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v623 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v93 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v93 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v63 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v63 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v63 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v63 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v63 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v63 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v61 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v61 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v61 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v61 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v61 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v61 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v61 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v61 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__335__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v61 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__251(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__251\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x3eU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i = 0x3eU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[62U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v624 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v624 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v625 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v625 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v626 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v626 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v627 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v627 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v628 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v628 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v629 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v629 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v630 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v630 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v631 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v631 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v94 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v94 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v64 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v64 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v64 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v64 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v64 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v64 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v62 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v62 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v62 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v62 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v62 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v62 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v62 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v62 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__336__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v62 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__252(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__252\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x3fU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i = 0x3fU;
        if (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
             & ((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[63U] 
                 < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
                                       >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (9.00000000000000022e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPRE violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i)));
                        }
                    } else if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
                                              >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i))))) {
                        if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                           - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i]) 
                                          < (QData)((IData)(
                                                            VL_RTOI_I_D(
                                                                        (2.99999999999999989e-01 
                                                                         * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                            VL_WRITEF_NX("%m: at time %t ERROR: tWPST violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                         , '#',64,VL_TIME_UNITED_Q(1)
                                         , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                         [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i) 
                                                 >> 5U))]
                                         , '#',32,(0x0000001fU 
                                                   & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i)));
                        }
                    } else if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                              - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg
                                              [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i]) 
                                             < (QData)((IData)(
                                                               VL_RTOI_I_D(
                                                                           (4.50000000000000011e-01 
                                                                            * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSL violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v632 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v632 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v633 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v633 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v634 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v634 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v635 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v635 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v636 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v636 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v637 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v637 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v638 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v638 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v639 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v639 = 1U;
                }
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190 
                    = (((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                         [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i] 
                         < VL_SHIFTR_III(32,32,32, (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length), 1U)) 
                        & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write)))
                        ? ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i])
                        : 1U);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v95 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v95 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v65 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v65 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v65 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v65 = 1U;
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v65 
                    = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i;
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v65 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v63 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v63 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v63 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_pos_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i)));
            }
        }
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v63 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v63 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v63 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v63 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v63 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__337__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v63 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__253(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__253\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x20U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i = 0x20U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[32U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x20U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v896 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v896 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v897 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v897 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v898 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v898 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v899 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v899 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v900 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v900 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v901 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v901 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v902 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v902 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v903 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v903 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v128 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v128 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v96 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v96 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v96 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v34 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v34 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v96 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v96 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__370__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v96 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__254(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__254\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x21U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i = 0x21U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[33U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x21U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v904 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v904 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v905 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v905 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v906 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v906 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v907 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v907 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v908 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v908 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v909 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v909 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v910 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v910 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v911 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v911 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v129 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v129 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v97 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v97 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v97 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v35 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v35 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v97 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v97 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__371__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v97 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__255(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__255\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x22U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i = 0x22U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[34U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x22U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v912 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v912 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v913 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v913 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v914 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v914 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v915 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v915 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v916 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v916 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v917 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v917 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v918 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v918 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v919 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v919 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v130 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v130 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v98 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v98 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v98 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v36 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v36 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v98 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v98 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__372__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v98 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__256(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__256\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x23U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i = 0x23U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[35U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x23U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v920 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v920 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v921 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v921 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v922 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v922 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v923 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v923 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v924 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v924 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v925 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v925 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v926 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v926 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v927 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v927 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v131 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v131 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v99 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v99 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v99 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v37 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v37 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v99 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v99 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__373__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v99 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__257(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__257\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x24U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i = 0x24U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[36U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x24U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v928 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v928 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v929 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v929 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v930 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v930 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v931 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v931 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v932 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v932 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v933 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v933 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v934 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v934 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v935 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v935 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v132 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v132 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v100 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v100 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v100 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v38 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v38 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v100 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v100 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__374__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v100 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__258(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__258\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x25U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i = 0x25U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[37U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x25U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v936 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v936 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v937 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v937 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v938 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v938 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v939 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v939 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v940 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v940 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v941 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v941 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v942 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v942 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v943 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v943 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v133 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v133 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v101 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v101 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v101 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v39 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v39 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v101 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v101 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__375__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v101 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__259(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__259\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x26U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i = 0x26U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[38U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x26U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v944 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v944 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v945 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v945 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v946 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v946 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v947 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v947 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v948 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v948 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v949 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v949 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v950 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v950 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v951 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v951 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v134 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v134 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v102 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v102 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v102 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v40 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v40 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v102 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v102 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__376__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v102 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__260(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__260\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x27U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i = 0x27U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[39U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x27U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v952 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v952 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v953 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v953 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v954 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v954 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v955 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v955 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v956 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v956 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v957 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v957 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v958 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v958 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v959 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v959 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v135 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v135 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v103 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v103 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v103 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v41 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v41 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v103 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v103 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__377__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v103 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__261(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__261\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x28U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i = 0x28U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[40U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x28U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v960 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v960 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v961 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v961 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v962 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v962 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v963 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v963 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v964 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v964 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v965 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v965 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v966 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v966 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v967 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v967 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v136 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v136 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v104 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v104 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v104 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v42 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v42 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v104 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v104 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__378__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v104 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__262(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__262\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x29U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i = 0x29U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[41U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x29U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v968 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v968 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v969 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v969 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v970 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v970 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v971 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v971 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v972 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v972 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v973 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v973 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v974 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v974 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v975 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v975 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v137 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v137 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v105 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v105 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v105 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v43 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v43 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v105 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v105 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__379__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v105 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__263(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__263\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x2aU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i = 0x2aU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[42U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x2aU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v976 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v976 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v977 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v977 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v978 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v978 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v979 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v979 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v980 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v980 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v981 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v981 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v982 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v982 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v983 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v983 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v138 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v138 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v106 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v106 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v106 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v44 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v44 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v106 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v106 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__380__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v106 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__264(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__264\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x2bU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i = 0x2bU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[43U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x2bU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v984 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v984 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v985 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v985 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v986 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v986 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v987 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v987 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v988 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v988 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v989 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v989 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v990 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v990 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v991 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v991 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v139 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v139 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v107 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v107 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v107 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v45 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v45 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v107 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v107 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__381__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v107 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__265(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__265\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x2cU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i = 0x2cU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[44U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x2cU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v992 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v992 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v993 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v993 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v994 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v994 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v995 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v995 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v996 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v996 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v997 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v997 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v998 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v998 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v999 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v999 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v140 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v140 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v108 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v108 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v108 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v46 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v46 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v108 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v108 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__382__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v108 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__266(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__266\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x2dU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i = 0x2dU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[45U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x2dU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1000 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1000 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1001 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1001 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1002 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1002 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1003 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1003 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1004 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1004 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1005 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1005 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1006 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1006 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1007 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1007 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v141 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v141 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v109 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v109 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v109 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v47 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v47 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v109 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v109 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__383__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v109 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__267(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__267\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x2eU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i = 0x2eU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[46U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x2eU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1008 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1008 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1009 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1009 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1010 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1010 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1011 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1011 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1012 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1012 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1013 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1013 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1014 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1014 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1015 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1015 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v142 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v142 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v110 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v110 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v110 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v48 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v48 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v110 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v110 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__384__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v110 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__268(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__268\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x2fU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i = 0x2fU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[47U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x2fU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1016 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1016 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1017 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1017 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1018 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1018 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1019 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1019 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1020 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1020 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1021 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1021 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1022 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1022 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1023 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1023 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v143 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v143 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v111 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v111 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v111 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v49 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v49 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v111 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v111 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__385__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v111 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__269(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__269\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x30U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i = 0x30U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[48U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x30U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i)));
                    }
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (1.79999999999999993e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1024 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1024 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1025 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1025 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1026 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1026 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1027 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1027 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1028 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1028 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1029 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1029 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1030 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1030 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1031 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1031 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v144 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v144 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v112 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v112 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v112 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v50 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v50 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v112 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v112 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__386__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v112 = 1U;
    }
}

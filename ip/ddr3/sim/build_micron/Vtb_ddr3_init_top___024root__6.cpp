// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ddr3_init_top.h for the primary calling header

#include "Vtb_ddr3_init_top__pch.h"

void Vtb_ddr3_init_top___024root___act_sequent__TOP__270(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__270\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x31U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i = 0x31U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[49U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x31U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1032 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1032 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1033 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1033 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1034 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1034 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1035 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1035 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1036 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1036 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1037 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1037 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1038 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1038 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1039 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1039 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v145 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v145 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v113 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v113 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v113 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v51 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v51 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v113 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v113 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__387__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v113 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__271(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__271\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x32U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i = 0x32U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[50U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x32U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1040 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1040 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1041 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1041 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1042 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1042 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1043 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1043 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1044 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1044 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1045 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1045 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1046 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1046 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1047 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1047 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v146 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v146 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v114 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v114 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v114 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v52 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v52 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v114 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v114 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__388__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v114 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__272(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__272\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x33U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i = 0x33U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[51U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x33U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1048 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1048 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1049 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1049 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1050 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1050 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1051 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1051 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1052 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1052 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1053 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1053 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1054 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1054 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1055 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1055 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v147 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v147 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v115 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v115 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v115 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v53 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v53 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v115 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v115 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__389__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v115 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__273(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__273\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x34U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i = 0x34U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[52U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x34U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1056 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1056 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1057 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1057 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1058 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1058 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1059 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1059 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1060 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1060 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1061 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1061 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1062 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1062 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1063 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1063 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v148 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v148 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v116 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v116 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v116 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v54 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v54 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v116 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v116 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__390__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v116 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__274(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__274\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x35U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i = 0x35U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[53U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x35U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1064 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1064 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1065 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1065 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1066 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1066 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1067 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1067 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1068 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1068 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1069 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1069 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1070 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1070 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1071 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1071 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v149 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v149 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v117 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v117 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v117 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v55 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v55 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v117 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v117 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__391__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v117 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__275(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__275\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x36U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i = 0x36U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[54U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x36U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1072 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1072 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1073 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1073 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1074 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1074 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1075 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1075 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1076 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1076 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1077 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1077 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1078 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1078 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1079 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1079 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v150 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v150 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v118 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v118 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v118 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v56 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v56 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v118 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v118 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__392__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v118 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__276(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__276\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x37U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i = 0x37U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[55U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x37U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1080 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1080 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1081 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1081 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1082 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1082 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1083 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1083 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1084 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1084 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1085 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1085 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1086 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1086 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1087 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1087 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v151 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v151 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v119 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v119 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v119 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v57 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v57 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v119 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v119 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__393__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v119 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__277(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__277\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x38U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i = 0x38U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[56U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x38U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1088 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1088 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1089 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1089 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1090 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1090 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1091 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1091 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1092 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1092 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1093 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1093 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1094 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1094 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1095 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1095 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v152 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v152 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v120 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v120 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v120 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v58 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v58 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v120 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v120 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__394__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v120 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__278(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__278\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x39U)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i = 0x39U;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[57U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x39U)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1096 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1096 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1097 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1097 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1098 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1098 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1099 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1099 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1100 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1100 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1101 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1101 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1102 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1102 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1103 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1103 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v153 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v153 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v121 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v121 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v121 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v59 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v59 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v121 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v121 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__395__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v121 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__279(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__279\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x3aU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i = 0x3aU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[58U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x3aU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1104 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1104 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1105 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1105 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1106 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1106 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1107 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1107 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1108 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1108 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1109 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1109 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1110 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1110 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1111 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1111 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v154 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v154 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v122 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v122 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v122 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v60 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v60 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v122 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v122 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__396__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v122 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__280(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__280\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x3bU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i = 0x3bU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[59U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x3bU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1112 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1112 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1113 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1113 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1114 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1114 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1115 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1115 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1116 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1116 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1117 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1117 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1118 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1118 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1119 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1119 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v155 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v155 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v123 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v123 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v123 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v61 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v61 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v123 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v123 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__397__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v123 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__281(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__281\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x3cU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i = 0x3cU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[60U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x3cU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1120 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1120 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1121 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1121 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1122 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1122 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1123 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1123 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1124 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1124 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1125 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1125 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1126 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1126 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1127 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1127 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v156 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v156 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v124 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v124 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v124 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v62 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v62 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v124 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v124 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__398__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v124 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__282(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__282\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x3dU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i = 0x3dU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[61U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x3dU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1128 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1128 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1129 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1129 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1130 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1130 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1131 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1131 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1132 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1132 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1133 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1133 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1134 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1134 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1135 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1135 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v157 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v157 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v125 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v125 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v125 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v63 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v63 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v125 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v125 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__399__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v125 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__283(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__283\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x3eU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i = 0x3eU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[62U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x3eU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1136 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1136 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1137 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1137 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1138 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1138 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1139 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1139 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1140 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1140 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1141 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1141 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1142 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1142 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1143 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1143 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v158 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v158 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v126 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v126 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v126 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v64 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v64 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v126 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v126 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__400__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v126 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__284(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__284\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i = 0;
    // Body
    if ((1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                       >> 0x3fU)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i = 0x3fU;
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[63U])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> 0x3fU)))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1144 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1144 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1145 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1145 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1146 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1146 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1147 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1147 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1148 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1148 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1149 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1149 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1150 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1150 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1151 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1151 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v159 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v159 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v127 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v127 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v127 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v65 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v65 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v127 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v127 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__401__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v127 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__285(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__285\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i = 0;
    // Body
    if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in)))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i = 0U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v640 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v640 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v641 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v641 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v642 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v642 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v643 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v643 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v644 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v644 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v645 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v645 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v646 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v646 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v647 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v647 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v96 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v96 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v64 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v64 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v64 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v2 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v2 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v64 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v64 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__338__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v64 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__286(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__286\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 1U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i = 1U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v648 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v648 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v649 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v649 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v650 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v650 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v651 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v651 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v652 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v652 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v653 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v653 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v654 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v654 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v655 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v655 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v97 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v97 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v65 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v65 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v65 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v3 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v3 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v65 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v65 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__339__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v65 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__287(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__287\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 2U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i = 2U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v656 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v656 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v657 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v657 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v658 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v658 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v659 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v659 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v660 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v660 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v661 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v661 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v662 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v662 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v663 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v663 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v98 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v98 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v66 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v66 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v66 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v4 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v4 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v66 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v66 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__340__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v66 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__288(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__288\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 3U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i = 3U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v664 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v664 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v665 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v665 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v666 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v666 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v667 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v667 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v668 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v668 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v669 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v669 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v670 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v670 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v671 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v671 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v99 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v99 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v67 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v67 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v67 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v5 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v5 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v67 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v67 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__341__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v67 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__289(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__289\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 4U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i = 4U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v672 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v672 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v673 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v673 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v674 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v674 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v675 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v675 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v676 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v676 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v677 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v677 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v678 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v678 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v679 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v679 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v100 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v100 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v68 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v68 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v68 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v6 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v6 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v68 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v68 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__342__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v68 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__290(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__290\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 5U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i = 5U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v680 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v680 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v681 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v681 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v682 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v682 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v683 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v683 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v684 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v684 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v685 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v685 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v686 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v686 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v687 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v687 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v101 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v101 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v69 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v69 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v69 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v7 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v7 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v69 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v69 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__343__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v69 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__291(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__291\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 6U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i = 6U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v688 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v688 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v689 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v689 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v690 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v690 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v691 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v691 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v692 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v692 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v693 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v693 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v694 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v694 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v695 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v695 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v102 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v102 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v70 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v70 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v70 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v8 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v8 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v70 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v70 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__344__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v70 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__292(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__292\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 7U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i = 7U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v696 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v696 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v697 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v697 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v698 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v698 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v699 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v699 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v700 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v700 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v701 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v701 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v702 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v702 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v703 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v703 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v103 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v103 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v71 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v71 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v71 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v9 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v9 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v71 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v71 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__345__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v71 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__293(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__293\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 8U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i = 8U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v704 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v704 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v705 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v705 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v706 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v706 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v707 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v707 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v708 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v708 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v709 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v709 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v710 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v710 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v711 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v711 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v104 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v104 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v72 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v72 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v72 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v10 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v10 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v72 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v72 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__346__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v72 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__294(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__294\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 9U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i = 9U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v712 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v712 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v713 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v713 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v714 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v714 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v715 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v715 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v716 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v716 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v717 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v717 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v718 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v718 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v719 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v719 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v105 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v105 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v73 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v73 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v73 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v11 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v11 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v73 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v73 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__347__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v73 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__295(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__295\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x0aU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i = 0x0aU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v720 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v720 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v721 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v721 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v722 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v722 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v723 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v723 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v724 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v724 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v725 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v725 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v726 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v726 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v727 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v727 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v106 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v106 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v74 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v74 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v74 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v12 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v12 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v74 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v74 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__348__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v74 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__296(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__296\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x0bU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i = 0x0bU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v728 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v728 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v729 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v729 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v730 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v730 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v731 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v731 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v732 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v732 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v733 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v733 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v734 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v734 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v735 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v735 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v107 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v107 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v75 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v75 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v75 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v13 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v13 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v75 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v75 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__349__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v75 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__297(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__297\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x0cU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i = 0x0cU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v736 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v736 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v737 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v737 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v738 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v738 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v739 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v739 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v740 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v740 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v741 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v741 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v742 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v742 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v743 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v743 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v108 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v108 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v76 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v76 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v76 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v14 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v14 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v76 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v76 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__350__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v76 = 1U;
    }
}

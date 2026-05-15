// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ddr3_init_top.h for the primary calling header

#include "Vtb_ddr3_init_top__pch.h"

void Vtb_ddr3_init_top___024root___act_sequent__TOP__298(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__298\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x0dU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i = 0x0dU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v744 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v744 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v745 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v745 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v746 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v746 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v747 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v747 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v748 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v748 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v749 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v749 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v750 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v750 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v751 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v751 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v109 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v109 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v77 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v77 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v77 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v15 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v15 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v77 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v77 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__351__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v77 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__299(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__299\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x0eU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i = 0x0eU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v752 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v752 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v753 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v753 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v754 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v754 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v755 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v755 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v756 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v756 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v757 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v757 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v758 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v758 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v759 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v759 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v110 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v110 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v78 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v78 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v78 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v16 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v16 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v78 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v78 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__352__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v78 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__300(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__300\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x0fU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i = 0x0fU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v760 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v760 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v761 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v761 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v762 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v762 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v763 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v763 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v764 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v764 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v765 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v765 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v766 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v766 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v767 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v767 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v111 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v111 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v79 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v79 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v79 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v17 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v17 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v79 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v79 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__353__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v79 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__301(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__301\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x10U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i = 0x10U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v768 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v768 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v769 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v769 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v770 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v770 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v771 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v771 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v772 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v772 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v773 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v773 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v774 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v774 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v775 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v775 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v112 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v112 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v80 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v80 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v80 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v18 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v18 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v80 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v80 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__354__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v80 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__302(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__302\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x11U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i = 0x11U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v776 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v776 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v777 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v777 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v778 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v778 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v779 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v779 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v780 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v780 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v781 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v781 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v782 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v782 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v783 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v783 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v113 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v113 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v81 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v81 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v81 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v19 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v19 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v81 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v81 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__355__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v81 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__303(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__303\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x12U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i = 0x12U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v784 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v784 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v785 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v785 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v786 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v786 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v787 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v787 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v788 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v788 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v789 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v789 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v790 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v790 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v791 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v791 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v114 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v114 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v82 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v82 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v82 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v20 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v20 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v82 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v82 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__356__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v82 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__304(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__304\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x13U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i = 0x13U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v792 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v792 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v793 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v793 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v794 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v794 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v795 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v795 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v796 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v796 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v797 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v797 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v798 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v798 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v799 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v799 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v115 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v115 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v83 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v83 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v83 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v21 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v21 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v83 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v83 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__357__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v83 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__305(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__305\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x14U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i = 0x14U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v800 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v800 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v801 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v801 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v802 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v802 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v803 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v803 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v804 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v804 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v805 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v805 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v806 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v806 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v807 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v807 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v116 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v116 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v84 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v84 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v84 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v22 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v22 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v84 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v84 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__358__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v84 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__306(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__306\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x15U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i = 0x15U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v808 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v808 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v809 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v809 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v810 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v810 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v811 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v811 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v812 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v812 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v813 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v813 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v814 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v814 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v815 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v815 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v117 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v117 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v85 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v85 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v85 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v23 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v23 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v85 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v85 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__359__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v85 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__307(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__307\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x16U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i = 0x16U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v816 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v816 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v817 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v817 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v818 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v818 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v819 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v819 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v820 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v820 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v821 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v821 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v822 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v822 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v823 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v823 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v118 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v118 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v86 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v86 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v86 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v24 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v24 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v86 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v86 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__360__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v86 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__308(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__308\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x17U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i = 0x17U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v824 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v824 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v825 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v825 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v826 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v826 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v827 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v827 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v828 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v828 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v829 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v829 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v830 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v830 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v831 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v831 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v119 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v119 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v87 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v87 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v87 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v25 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v25 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v87 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v87 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__361__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v87 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__309(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__309\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x18U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i = 0x18U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v832 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v832 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v833 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v833 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v834 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v834 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v835 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v835 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v836 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v836 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v837 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v837 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v838 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v838 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v839 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v839 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v120 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v120 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v88 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v88 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v88 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v26 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v26 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v88 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v88 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__362__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v88 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__310(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__310\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x19U))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i = 0x19U;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v840 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v840 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v841 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v841 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v842 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v842 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v843 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v843 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v844 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v844 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v845 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v845 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v846 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v846 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v847 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v847 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v121 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v121 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v89 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v89 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v89 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v27 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v27 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v89 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v89 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__363__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v89 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__311(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__311\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x1aU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i = 0x1aU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v848 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v848 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v849 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v849 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v850 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v850 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v851 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v851 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v852 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v852 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v853 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v853 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v854 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v854 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v855 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v855 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v122 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v122 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v90 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v90 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v90 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v28 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v28 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v90 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v90 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__364__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v90 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__312(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__312\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x1bU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i = 0x1bU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v856 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v856 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v857 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v857 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v858 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v858 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v859 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v859 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v860 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v860 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v861 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v861 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v862 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v862 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v863 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v863 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v123 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v123 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v91 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v91 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v91 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v29 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v29 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v91 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v91 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__365__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v91 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__313(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__313\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x1cU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i = 0x1cU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v864 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v864 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v865 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v865 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v866 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v866 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v867 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v867 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v868 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v868 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v869 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v869 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v870 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v870 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v871 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v871 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v124 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v124 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v92 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v92 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v92 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v30 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v30 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v92 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v92 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__366__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v92 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__314(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__314\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x1dU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i = 0x1dU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v872 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v872 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v873 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v873 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v874 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v874 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v875 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v875 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v876 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v876 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v877 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v877 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v878 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v878 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v879 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v879 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v125 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v125 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v93 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v93 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v93 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v31 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v31 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v93 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v93 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__367__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v93 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__315(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__315\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x1eU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i = 0x1eU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v880 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v880 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v881 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v881 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v882 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v882 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v883 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v883 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v884 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v884 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v885 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v885 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v886 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v886 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v887 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v887 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v126 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v126 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v94 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v94 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v94 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v32 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v32 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v94 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v94 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__368__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v94 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__316(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__316\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i;
    __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i = 0;
    // Body
    if ((1U & (~ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                          >> 0x1fU))))) {
        __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i = 0x1fU;
        if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization) {
            if (VL_UNLIKELY((VL_GTS_III(32, 0x00000019U, 
                                        (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tWLDQSEN violation on DQS bit %d.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i));
            }
            if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                               - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                               [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i]) 
                              < (QData)((IData)(VL_RTOI_I_D(
                                                            (4.50000000000000011e-01 
                                                             * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on DQS bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i)
                             , 'D',((VL_ITOR_D_Q(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                                 [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i]) 
                                     + (4.50000000000000011e-01 
                                        * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)) 
                                    - VL_ITOR_D_Q(64, VL_TIME_UNITED_Q(1))));
            }
        }
        if ((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid) 
              & VL_LTS_III(32, 0U, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr
                           [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i])) 
             & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
                        >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i))))) {
            if (VL_LIKELY(((1U & ((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                           >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i))) 
                                  ^ (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in 
                                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i)))))))) {
                if (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked) {
                    if (VL_UNLIKELY(((((QData)(VL_TIME_UNITED_Q(1)) 
                                       - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos
                                       [__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i]) 
                                      < (QData)((IData)(
                                                        VL_RTOI_I_D(
                                                                    (4.50000000000000011e-01 
                                                                     * vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg)))))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDQSH violation on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i)));
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
                                     [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i) 
                                             >> 5U))]
                                     , '#',32,(0x0000001fU 
                                               & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i)));
                    }
                }
                if (VL_UNLIKELY(((0x000000000000000aULL 
                                  > ((QData)(VL_TIME_UNITED_Q(1)) 
                                     - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                     [(0x0000001fU 
                                       & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i))]))))) {
                    VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DM bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                 , '#',64,VL_TIME_UNITED_Q(1)
                                 , '#',6,(IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i)
                                 , '#',64,((0x000000000000000aULL 
                                            + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm
                                            [(0x0000001fU 
                                              & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i))]) 
                                           - (QData)(VL_TIME_UNITED_Q(1))));
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en)))) {
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x78U & 
                                           VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U)
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x78U 
                                                  & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = 8U;
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v888 
                        = (0x78U & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v888 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(1U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(1U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v889 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v889 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(2U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(2U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(2U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v890 
                        = (0x0000007fU & ((IData)(2U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v890 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(3U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(3U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(3U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v891 
                        = (0x0000007fU & ((IData)(3U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v891 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(4U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(4U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(4U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v892 
                        = (0x0000007fU & ((IData)(4U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v892 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(5U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(5U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(5U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v893 
                        = (0x0000007fU & ((IData)(5U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v893 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(6U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(6U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(6U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v894 
                        = (0x0000007fU & ((IData)(6U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v894 = 1U;
                    if (VL_UNLIKELY(((0x000000000000000aULL 
                                      > ((QData)(VL_TIME_UNITED_Q(1)) 
                                         - vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                         [(0x0000007fU 
                                           & ((IData)(7U) 
                                              + (0x78U 
                                                 & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]))))) {
                        VL_WRITEF_NX("%m: at time %t ERROR: tDS violation on DQ bit %d by %t\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                                     , '#',64,VL_TIME_UNITED_Q(1)
                                     , '#',32,((IData)(7U) 
                                               + VL_SHIFTL_III(32,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))
                                     , '#',64,((0x000000000000000aULL 
                                                + vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq
                                                [(0x0000007fU 
                                                  & ((IData)(7U) 
                                                     + 
                                                     (0x78U 
                                                      & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))))]) 
                                               - (QData)(VL_TIME_UNITED_Q(1))));
                    }
                    vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v895 
                        = (0x0000007fU & ((IData)(7U) 
                                          + (0x78U 
                                             & VL_SHIFTL_III(7,32,32, (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i), 3U))));
                    vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v895 = 1U;
                }
                vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v127 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v127 = 1U;
                vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v95 
                    = VL_TIME_UNITED_Q(1);
                vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v95 
                    = (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i));
                vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v95 = 1U;
            } else {
                VL_WRITEF_NX("%m: at time %t ERROR: Invalid latching edge on %s bit %d\n",5, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.dqs_neg_timing_check", 'T',-12
                             , '#',64,VL_TIME_UNITED_Q(1)
                             , '#',40,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string
                             [(1U & ((IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i) 
                                     >> 5U))], '#',32,
                             (0x0000001fU & (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i)));
            }
        }
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v33 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v33 = 1U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i] 
            = VL_TIME_UNITED_Q(1);
        vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v95 
            = (1U & (IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                             >> (IData)(__Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i))));
        vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v95 
            = __Vtask_tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__369__i;
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v95 = 1U;
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__317(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__317\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state) 
                      != (IData)(vlSelfRef.tb_ddr3_init_top__DOT__prev_state))))) {
        VL_WRITEF_NX("[tb] t=%0t  state=%0d\n",3, 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',5,(IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state));
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__prev_state 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state;
    }
    if (vlSelfRef.tb_ddr3_init_top__DOT__rst) {
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_odt = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_dat = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cke = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 7U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_done = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error_code = 0U;
    } else {
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack = 0U;
        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 7U;
        if ((0x00000010U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
            if ((8U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                if ((4U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                    if ((2U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                        if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error = 1U;
                        } else {
                            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x1fU;
                            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error = 1U;
                            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error_code = 1U;
                        }
                    } else {
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x1fU;
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error = 1U;
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error_code = 1U;
                    }
                } else {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x1fU;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error = 1U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error_code = 1U;
                }
            } else if ((4U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x1fU;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error = 1U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error_code = 1U;
            } else if ((2U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x1fU;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error = 1U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error_code = 1U;
                } else {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_done = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                if ((0x0000007eU == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x12U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_done = 1U;
                } else {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                        = (0x00ffffffU & ((IData)(1U) 
                                          + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
                }
            } else {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 1U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x11U;
            }
        } else if ((8U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
            if ((4U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                        if ((9U == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x10U;
                        } else {
                            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                                = (0x00ffffffU & ((IData)(1U) 
                                                  + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
                        }
                    } else {
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 2U;
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 0U;
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0x0400U;
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x0fU;
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                    if ((0x000001ffU == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x0eU;
                    } else {
                        vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                            = (0x00ffffffU & ((IData)(1U) 
                                              + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
                    }
                } else if ((0x000001feU == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x0dU;
                } else {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                        = (0x00ffffffU & ((IData)(1U) 
                                          + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
                }
            } else if ((2U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 6U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0x0400U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x0cU;
                } else if ((0x0000000aU == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x0bU;
                } else {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                        = (0x00ffffffU & ((IData)(1U) 
                                          + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
                }
            } else if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0x0d70U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0x0aU;
            } else if ((2U == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 9U;
            } else {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                    = (0x00ffffffU & ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
            }
        } else if ((4U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 1U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0x0102U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 8U;
                } else if ((2U == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 7U;
                } else {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                        = (0x00ffffffU & ((IData)(1U) 
                                          + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
                }
            } else if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 3U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 6U;
            } else if ((2U == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 5U;
            } else {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                    = (0x00ffffffU & ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
            }
        } else if ((2U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 2U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0x0018U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 4U;
            } else {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cke = 1U;
                if ((0x0000007fU == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 3U;
                } else {
                    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                        = (0x00ffffffU & ((IData)(1U) 
                                          + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state))) {
            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n = 1U;
            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cke = 0U;
            if ((0x00061a7fU == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 2U;
            } else {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                    = (0x00ffffffU & ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
            }
        } else {
            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n = 0U;
            vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cke = 0U;
            if ((0x000270ffU == vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr)) {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0U;
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 1U;
            } else {
                vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
                    = (0x00ffffffU & ((IData)(1U) + vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr));
            }
        }
    }
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__318(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__318\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_in;
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__319(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___act_sequent__TOP__319\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck 
        = (1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in)));
}

void Vtb_ddr3_init_top___024root___act_sequent__TOP__0(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__1(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_comb__TOP__0(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__2(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__3(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__4(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__5(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__6(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__7(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__8(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__9(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__10(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__11(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__12(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__13(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__14(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__15(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__16(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__17(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__18(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__19(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__20(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__21(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__22(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__23(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__24(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__25(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__26(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__27(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__28(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__29(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__30(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__31(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__32(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__33(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__34(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__35(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__36(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__37(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__38(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__39(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__40(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__41(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__42(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__43(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__44(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__45(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__46(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__47(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__48(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__49(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__50(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__51(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__52(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__53(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__54(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__55(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__56(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__57(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__58(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__59(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__60(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__61(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__62(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__63(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__64(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__65(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__66(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__67(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__68(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__69(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__70(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__71(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__72(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__73(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__74(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__75(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__76(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__77(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__78(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__79(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__80(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__81(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__82(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__83(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__84(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__85(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__86(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__87(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__88(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__89(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__90(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__91(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__92(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__93(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__94(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__95(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__96(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__97(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__98(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__99(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__100(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__101(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__102(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__103(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__104(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__105(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__106(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__107(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__108(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__109(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__110(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__111(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__112(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__113(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__114(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__115(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__116(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__117(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__118(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__119(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__120(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__121(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__122(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__123(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__124(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__125(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__126(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__127(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__128(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__129(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__130(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__131(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__132(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__133(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__134(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__135(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__136(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__137(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__138(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__139(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__140(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__141(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__142(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__143(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__144(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__145(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__146(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__147(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__148(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__149(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__150(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__151(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__152(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__153(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__154(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__155(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__156(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__157(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__158(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__159(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__160(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__161(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__162(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__163(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__164(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__165(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__166(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__167(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__168(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__169(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__170(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__171(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__172(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__173(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__174(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__175(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__176(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__177(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__178(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__179(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__180(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__181(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__182(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__183(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__184(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__185(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__186(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__187(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__188(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__189(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__190(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__191(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__192(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__193(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__194(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__195(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__196(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__197(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__198(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__199(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__200(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__201(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__202(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__203(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__204(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__205(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__206(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__207(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__208(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__209(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__210(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__211(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__212(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__213(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__214(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__215(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__216(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__217(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__218(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__219(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__220(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__221(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__222(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__223(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__224(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__225(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__226(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__227(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__228(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__229(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__230(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__231(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__232(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__233(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__234(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__235(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__236(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__237(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__238(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__239(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__240(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__241(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__242(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__243(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__244(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__245(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__246(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__247(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__248(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__249(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__250(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__251(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__252(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__253(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__254(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__255(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__256(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__257(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__258(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__259(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__260(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__261(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__262(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__263(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__264(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__265(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__266(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__267(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__268(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__269(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__270(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__271(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__272(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__273(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__274(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__275(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__276(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__277(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__278(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__279(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__280(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__281(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__282(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__283(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__284(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__285(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__286(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__287(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__288(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__289(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__290(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__291(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__292(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__293(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__294(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__295(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__296(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___act_sequent__TOP__297(Vtb_ddr3_init_top___024root* vlSelf);

void Vtb_ddr3_init_top___024root___eval_act(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_act\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[8U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__1(vlSelf);
    }
    if (((0x1000000000000000ULL & vlSelfRef.__VactTriggered[5U]) 
         | (0x0000000000000c00ULL & vlSelfRef.__VactTriggered[6U]))) {
        Vtb_ddr3_init_top___024root___act_comb__TOP__0(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VactTriggered[8U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0x0000000200000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((0x0000000400000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__4(vlSelf);
    }
    if ((0x0000000800000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__5(vlSelf);
    }
    if ((0x0000001000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__6(vlSelf);
    }
    if ((0x0000002000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__7(vlSelf);
    }
    if ((0x0000004000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__8(vlSelf);
    }
    if ((0x0000008000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__9(vlSelf);
    }
    if ((0x0000010000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__10(vlSelf);
    }
    if ((0x0000020000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__11(vlSelf);
    }
    if ((0x0000040000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__12(vlSelf);
    }
    if ((0x0000080000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__13(vlSelf);
    }
    if ((0x0000100000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__14(vlSelf);
    }
    if ((0x0000200000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__15(vlSelf);
    }
    if ((0x0000400000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__16(vlSelf);
    }
    if ((0x0000800000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__17(vlSelf);
    }
    if ((0x0001000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__18(vlSelf);
    }
    if ((0x0002000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__19(vlSelf);
    }
    if ((0x0004000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__20(vlSelf);
    }
    if ((0x0008000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__21(vlSelf);
    }
    if ((0x0010000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__22(vlSelf);
    }
    if ((0x0020000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__23(vlSelf);
    }
    if ((0x0040000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__24(vlSelf);
    }
    if ((0x0080000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__25(vlSelf);
    }
    if ((0x0100000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__26(vlSelf);
    }
    if ((0x0200000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__27(vlSelf);
    }
    if ((0x0400000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__28(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__29(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__30(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__31(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__32(vlSelf);
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__33(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__34(vlSelf);
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__35(vlSelf);
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__36(vlSelf);
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__37(vlSelf);
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__38(vlSelf);
    }
    if ((0x0000000000000800ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__39(vlSelf);
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__40(vlSelf);
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__41(vlSelf);
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__42(vlSelf);
    }
    if ((0x0000000000008000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__43(vlSelf);
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__44(vlSelf);
    }
    if ((0x0000000000020000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__45(vlSelf);
    }
    if ((0x0000000000040000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__46(vlSelf);
    }
    if ((0x0000000000080000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__47(vlSelf);
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__48(vlSelf);
    }
    if ((0x0000000000200000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__49(vlSelf);
    }
    if ((0x0000000000400000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__50(vlSelf);
    }
    if ((0x0000000000800000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__51(vlSelf);
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__52(vlSelf);
    }
    if ((0x0000000002000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__53(vlSelf);
    }
    if ((0x0000000004000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__54(vlSelf);
    }
    if ((0x0000000008000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__55(vlSelf);
    }
    if ((0x0000000010000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__56(vlSelf);
    }
    if ((0x0000000020000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__57(vlSelf);
    }
    if ((0x0000000040000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__58(vlSelf);
    }
    if ((0x0000000080000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__59(vlSelf);
    }
    if ((0x0000000100000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__60(vlSelf);
    }
    if ((0x0800000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__61(vlSelf);
    }
    if ((0x1000000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__62(vlSelf);
    }
    if ((0x2000000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__63(vlSelf);
    }
    if ((0x4000000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__64(vlSelf);
    }
    if ((0x8000000000000000ULL & vlSelfRef.__VactTriggered[1U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__65(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__66(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__67(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__68(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__69(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__70(vlSelf);
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__71(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__72(vlSelf);
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__73(vlSelf);
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__74(vlSelf);
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__75(vlSelf);
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__76(vlSelf);
    }
    if ((0x0000000000000800ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__77(vlSelf);
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__78(vlSelf);
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__79(vlSelf);
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__80(vlSelf);
    }
    if ((0x0000000000008000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__81(vlSelf);
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__82(vlSelf);
    }
    if ((0x0000000000020000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__83(vlSelf);
    }
    if ((0x0000000000040000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__84(vlSelf);
    }
    if ((0x0000000000080000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__85(vlSelf);
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__86(vlSelf);
    }
    if ((0x0000000000200000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__87(vlSelf);
    }
    if ((0x0000000000400000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__88(vlSelf);
    }
    if ((0x0000000000800000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__89(vlSelf);
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__90(vlSelf);
    }
    if ((0x0000000002000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__91(vlSelf);
    }
    if ((0x0000000004000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__92(vlSelf);
    }
    if ((0x0000000008000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__93(vlSelf);
    }
    if ((0x0000000010000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__94(vlSelf);
    }
    if ((0x0000000020000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__95(vlSelf);
    }
    if ((0x0000000040000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__96(vlSelf);
    }
    if ((0x0000000080000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__97(vlSelf);
    }
    if ((0x0000000100000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__98(vlSelf);
    }
    if ((0x0000000200000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__99(vlSelf);
    }
    if ((0x0000000400000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__100(vlSelf);
    }
    if ((0x0000000800000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__101(vlSelf);
    }
    if ((0x0000001000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__102(vlSelf);
    }
    if ((0x0000002000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__103(vlSelf);
    }
    if ((0x0000004000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__104(vlSelf);
    }
    if ((0x0000008000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__105(vlSelf);
    }
    if ((0x0000010000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__106(vlSelf);
    }
    if ((0x0000020000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__107(vlSelf);
    }
    if ((0x0000040000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__108(vlSelf);
    }
    if ((0x0000080000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__109(vlSelf);
    }
    if ((0x0000100000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__110(vlSelf);
    }
    if ((0x0000200000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__111(vlSelf);
    }
    if ((0x0000400000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__112(vlSelf);
    }
    if ((0x0000800000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__113(vlSelf);
    }
    if ((0x0001000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__114(vlSelf);
    }
    if ((0x0002000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__115(vlSelf);
    }
    if ((0x0004000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__116(vlSelf);
    }
    if ((0x0008000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__117(vlSelf);
    }
    if ((0x0010000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__118(vlSelf);
    }
    if ((0x0020000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__119(vlSelf);
    }
    if ((0x0040000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__120(vlSelf);
    }
    if ((0x0080000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__121(vlSelf);
    }
    if ((0x0100000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__122(vlSelf);
    }
    if ((0x0200000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__123(vlSelf);
    }
    if ((0x0400000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__124(vlSelf);
    }
    if ((0x0800000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__125(vlSelf);
    }
    if ((0x1000000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__126(vlSelf);
    }
    if ((0x2000000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__127(vlSelf);
    }
    if ((0x4000000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__128(vlSelf);
    }
    if ((0x8000000000000000ULL & vlSelfRef.__VactTriggered[2U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__129(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__130(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__131(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__132(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__133(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__134(vlSelf);
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__135(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__136(vlSelf);
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__137(vlSelf);
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__138(vlSelf);
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__139(vlSelf);
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__140(vlSelf);
    }
    if ((0x0000000000000800ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__141(vlSelf);
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__142(vlSelf);
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__143(vlSelf);
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__144(vlSelf);
    }
    if ((0x0000000000008000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__145(vlSelf);
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__146(vlSelf);
    }
    if ((0x0000000000020000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__147(vlSelf);
    }
    if ((0x0000000000040000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__148(vlSelf);
    }
    if ((0x0000000000080000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__149(vlSelf);
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__150(vlSelf);
    }
    if ((0x0000000000200000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__151(vlSelf);
    }
    if ((0x0000000000400000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__152(vlSelf);
    }
    if ((0x0000000000800000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__153(vlSelf);
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__154(vlSelf);
    }
    if ((0x0000000002000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__155(vlSelf);
    }
    if ((0x0000000004000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__156(vlSelf);
    }
    if ((0x0000000008000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__157(vlSelf);
    }
    if ((0x0000000010000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__158(vlSelf);
    }
    if ((0x0000000020000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__159(vlSelf);
    }
    if ((0x0000000040000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__160(vlSelf);
    }
    if ((0x0000000080000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__161(vlSelf);
    }
    if ((0x0000000100000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__162(vlSelf);
    }
    if ((0x0000000200000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__163(vlSelf);
    }
    if ((0x0000000400000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__164(vlSelf);
    }
    if ((0x0000000800000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__165(vlSelf);
    }
    if ((0x0000001000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__166(vlSelf);
    }
    if ((0x0000002000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__167(vlSelf);
    }
    if ((0x0000004000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__168(vlSelf);
    }
    if ((0x0000008000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__169(vlSelf);
    }
    if ((0x0000010000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__170(vlSelf);
    }
    if ((0x0000020000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__171(vlSelf);
    }
    if ((0x0000040000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__172(vlSelf);
    }
    if ((0x0000080000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__173(vlSelf);
    }
    if ((0x0000100000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__174(vlSelf);
    }
    if ((0x0000200000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__175(vlSelf);
    }
    if ((0x0000400000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__176(vlSelf);
    }
    if ((0x0000800000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__177(vlSelf);
    }
    if ((0x0001000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__178(vlSelf);
    }
    if ((0x0002000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__179(vlSelf);
    }
    if ((0x0004000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__180(vlSelf);
    }
    if ((0x0008000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__181(vlSelf);
    }
    if ((0x0010000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__182(vlSelf);
    }
    if ((0x0020000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__183(vlSelf);
    }
    if ((0x0040000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__184(vlSelf);
    }
    if ((0x0080000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__185(vlSelf);
    }
    if ((0x0100000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__186(vlSelf);
    }
    if ((0x0200000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__187(vlSelf);
    }
    if ((0x0400000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__188(vlSelf);
    }
    if ((0x0800000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__189(vlSelf);
    }
    if ((0x1000000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__190(vlSelf);
    }
    if ((0x2000000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__191(vlSelf);
    }
    if ((0x4000000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__192(vlSelf);
    }
    if ((0x8000000000000000ULL & vlSelfRef.__VactTriggered[3U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__193(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__194(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__195(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__196(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__197(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__198(vlSelf);
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__199(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__200(vlSelf);
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__201(vlSelf);
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__202(vlSelf);
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__203(vlSelf);
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__204(vlSelf);
    }
    if ((0x0000000000000800ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__205(vlSelf);
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__206(vlSelf);
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__207(vlSelf);
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__208(vlSelf);
    }
    if ((0x0000000000008000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__209(vlSelf);
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__210(vlSelf);
    }
    if ((0x0000000000020000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__211(vlSelf);
    }
    if ((0x0000000000040000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__212(vlSelf);
    }
    if ((0x0000000000080000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__213(vlSelf);
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__214(vlSelf);
    }
    if ((0x0000000000200000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__215(vlSelf);
    }
    if ((0x0000000000400000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__216(vlSelf);
    }
    if ((0x0000000000800000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__217(vlSelf);
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__218(vlSelf);
    }
    if ((0x0000000002000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__219(vlSelf);
    }
    if ((0x0000000004000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__220(vlSelf);
    }
    if ((0x0000000008000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__221(vlSelf);
    }
    if ((0x0000000010000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__222(vlSelf);
    }
    if ((0x0000000020000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__223(vlSelf);
    }
    if ((0x0000000040000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__224(vlSelf);
    }
    if ((0x0000000080000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__225(vlSelf);
    }
    if ((0x0000000100000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__226(vlSelf);
    }
    if ((0x0000000200000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__227(vlSelf);
    }
    if ((0x0000000400000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__228(vlSelf);
    }
    if ((0x0000000800000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__229(vlSelf);
    }
    if ((0x0000001000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__230(vlSelf);
    }
    if ((0x0000002000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__231(vlSelf);
    }
    if ((0x0000004000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__232(vlSelf);
    }
    if ((0x0000008000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__233(vlSelf);
    }
    if ((0x0000010000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__234(vlSelf);
    }
    if ((0x0000020000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__235(vlSelf);
    }
    if ((0x0000040000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__236(vlSelf);
    }
    if ((0x0000080000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__237(vlSelf);
    }
    if ((0x0000100000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__238(vlSelf);
    }
    if ((0x0000200000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__239(vlSelf);
    }
    if ((0x0000400000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__240(vlSelf);
    }
    if ((0x0000800000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__241(vlSelf);
    }
    if ((0x0001000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__242(vlSelf);
    }
    if ((0x0002000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__243(vlSelf);
    }
    if ((0x0004000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__244(vlSelf);
    }
    if ((0x0008000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__245(vlSelf);
    }
    if ((0x0010000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__246(vlSelf);
    }
    if ((0x0020000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__247(vlSelf);
    }
    if ((0x0040000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__248(vlSelf);
    }
    if ((0x0080000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__249(vlSelf);
    }
    if ((0x0100000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__250(vlSelf);
    }
    if ((0x0200000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__251(vlSelf);
    }
    if ((0x0400000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__252(vlSelf);
    }
    if ((0x0000000008000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__253(vlSelf);
    }
    if ((0x0000000010000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__254(vlSelf);
    }
    if ((0x0000000020000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__255(vlSelf);
    }
    if ((0x0000000040000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__256(vlSelf);
    }
    if ((0x0000000080000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__257(vlSelf);
    }
    if ((0x0000000100000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__258(vlSelf);
    }
    if ((0x0000000200000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__259(vlSelf);
    }
    if ((0x0000000400000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__260(vlSelf);
    }
    if ((0x0000000800000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__261(vlSelf);
    }
    if ((0x0000001000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__262(vlSelf);
    }
    if ((0x0000002000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__263(vlSelf);
    }
    if ((0x0000004000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__264(vlSelf);
    }
    if ((0x0000008000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__265(vlSelf);
    }
    if ((0x0000010000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__266(vlSelf);
    }
    if ((0x0000020000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__267(vlSelf);
    }
    if ((0x0000040000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__268(vlSelf);
    }
    if ((0x0000080000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__269(vlSelf);
    }
    if ((0x0000100000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__270(vlSelf);
    }
    if ((0x0000200000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__271(vlSelf);
    }
    if ((0x0000400000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__272(vlSelf);
    }
    if ((0x0000800000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__273(vlSelf);
    }
    if ((0x0001000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__274(vlSelf);
    }
    if ((0x0002000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__275(vlSelf);
    }
    if ((0x0004000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__276(vlSelf);
    }
    if ((0x0008000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__277(vlSelf);
    }
    if ((0x0010000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__278(vlSelf);
    }
    if ((0x0020000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__279(vlSelf);
    }
    if ((0x0040000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__280(vlSelf);
    }
    if ((0x0080000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__281(vlSelf);
    }
    if ((0x0100000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__282(vlSelf);
    }
    if ((0x0200000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__283(vlSelf);
    }
    if ((0x0400000000000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__284(vlSelf);
    }
    if ((0x0800000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__285(vlSelf);
    }
    if ((0x1000000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__286(vlSelf);
    }
    if ((0x2000000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__287(vlSelf);
    }
    if ((0x4000000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__288(vlSelf);
    }
    if ((0x8000000000000000ULL & vlSelfRef.__VactTriggered[4U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__289(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__290(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__291(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__292(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__293(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__294(vlSelf);
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__295(vlSelf);
    }
    if ((0x0000000000000040ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__296(vlSelf);
    }
    if ((0x0000000000000080ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__297(vlSelf);
    }
    if ((0x0000000000000100ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__298(vlSelf);
    }
    if ((0x0000000000000200ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__299(vlSelf);
    }
    if ((0x0000000000000400ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__300(vlSelf);
    }
    if ((0x0000000000000800ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__301(vlSelf);
    }
    if ((0x0000000000001000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__302(vlSelf);
    }
    if ((0x0000000000002000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__303(vlSelf);
    }
    if ((0x0000000000004000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__304(vlSelf);
    }
    if ((0x0000000000008000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__305(vlSelf);
    }
    if ((0x0000000000010000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__306(vlSelf);
    }
    if ((0x0000000000020000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__307(vlSelf);
    }
    if ((0x0000000000040000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__308(vlSelf);
    }
    if ((0x0000000000080000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__309(vlSelf);
    }
    if ((0x0000000000100000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__310(vlSelf);
    }
    if ((0x0000000000200000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__311(vlSelf);
    }
    if ((0x0000000000400000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__312(vlSelf);
    }
    if ((0x0000000000800000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__313(vlSelf);
    }
    if ((0x0000000001000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__314(vlSelf);
    }
    if ((0x0000000002000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__315(vlSelf);
    }
    if ((0x0000000004000000ULL & vlSelfRef.__VactTriggered[5U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__316(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__317(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__318(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_ddr3_init_top___024root___act_sequent__TOP__319(vlSelf);
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ddr3_init_top__DOT__prev_state = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__prev_state;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr;
    vlSelfRef.tb_ddr3_init_top__DOT__init_error_code 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error_code;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_dat 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_dat;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cke 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cke;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_ba 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_addr 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr;
    vlSelfRef.tb_ddr3_init_top__DOT__init_error = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_error;
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_odt 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_odt;
    vlSelfRef.tb_ddr3_init_top__DOT__init_done = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__init_done;
    vlSelfRef.done_or_err = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done) 
                             | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_error));
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done) 
           | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n));
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done) 
           | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cke));
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt 
        = ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done)) 
           & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_odt));
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_ba) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done))))));
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_addr) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done))))));
    vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done)
            ? 7U : (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd));
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__1(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__1\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck 
        = vlSelfRef.__Vdly__tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__2(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__2\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlyCommitQueuetb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge.commit(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge);
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[0U] 
            = ((0x7effU & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[0U]) 
               | ((SData)((IData)(vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg__v0)) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_write__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_write__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_write 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_write__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_read__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_read__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_read 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_read__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tch_i__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tch_i__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tch_i 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tch_i__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__active_bank 
            = (((~ ((IData)(1U) << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0))) 
                & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__active_bank)) 
               | (0x00ffU & ((IData)(vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0) 
                             << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0))));
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank 
            = (((~ ((IData)(1U) << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0))) 
                & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank)) 
               | (0x00ffU & ((IData)(vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0) 
                             << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0))));
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate__v0] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate__v0] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate__v0] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write__v0] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write__v0] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read__v0] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read__v0] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end__v0] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write = 1U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v1;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v1;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v1;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v1;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[0U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[1U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v1;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[2U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v3) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v3 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[3U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v4) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v4 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[4U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v4;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v5) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v5 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[5U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v5;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v6) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v6 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[6U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v6;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v7) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v7 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[7U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v7;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[0U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[0U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v1;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[1U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v3) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v3 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[1U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v4) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v4 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[0U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v4;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v5) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v5 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[0U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v5;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v6) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v6 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[1U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v6;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v7) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v7 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[1U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v7;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v1;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v2;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v3) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v3 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v3;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v4) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v4 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v4;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v5) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v5 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v5;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v6) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v6 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v6;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v7) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v7 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v7;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__3(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__3\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__4(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__4\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_in__v0;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__5(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__5\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cke_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cke_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cke_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__cke_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__6(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__6\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dm_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dm_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dm_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__7(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__7\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ba_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ba_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ba_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ba_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__8(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__8\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__addr_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__addr_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__addr_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__9(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__9\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_in__v0[0U];
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_in__v0[1U];
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_in__v0[2U];
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_in__v0[3U];
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__10(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__10\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__11(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__11\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__odt_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__12(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__12\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__13(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__13\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__14(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__14\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__15(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__15\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in__v0;
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__16(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__16\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high = 0x0000000100000001ULL;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v2))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v3) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v3 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v3))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v4) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v4 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v4))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v5) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v5 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v5))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v6) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v6 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v6))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v7) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v7 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v7))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v8) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v8 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v8))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v9) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v9 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v9))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v10) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v10 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v10))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v11) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v11 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v11))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v12) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v12 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v12))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v13) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v13 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v13))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v14) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v14 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v14))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v15) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v15 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v15))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v16) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v16 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v16))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v17) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v17 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v17))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v18) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v18 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v18))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v19) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v19 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v19))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v20) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v20 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v20))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v21) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v21 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v21))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v22) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v22 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v22))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v23) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v23 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v23))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v24) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v24 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v24))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v25) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v25 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v25))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v26) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v26 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v26))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v27) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v27 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v27))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v28) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v28 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v28))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v29) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v29 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v29))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v30) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v30 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v30))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v31) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v31 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v31))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v32) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v32 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v32))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v33) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v33 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v33))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v34) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v34 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v34))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v35) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v35 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v35))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v36) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v36 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v36))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v37) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v37 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v37))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v38) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v38 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v38))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v39) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v39 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v39))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v40) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v40 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v40))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v41) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v41 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v41))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v42) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v42 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v42))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v43) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v43 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v43))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v44) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v44 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v44))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v45) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v45 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v45))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v46) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v46 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v46))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v47) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v47 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v47))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v48) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v48 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v48))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v49) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v49 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v49))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v50) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v50 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v50))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v51) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v51 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v51))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v52) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v52 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v52))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v53) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v53 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v53))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v54) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v54 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v54))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v55) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v55 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v55))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v56) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v56 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v56))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v57) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v57 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v57))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v58) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v58 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v58))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v59) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v59 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v59))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v60) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v60 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v60))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v61) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v61 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v61))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v62) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v62 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v62))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v63) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v63 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v63))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v64) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v64 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v64))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v65) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v65 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v65))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high);
    }
}

void Vtb_ddr3_init_top___024root___nba_sequent__TOP__17(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___nba_sequent__TOP__17\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble = 0x0000000100000001ULL;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v2))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v3) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v3 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v3))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v4) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v4 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v4))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v5) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v5 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v5))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v6) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v6 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v6))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v7) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v7 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v7))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v8) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v8 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v8))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v9) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v9 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v9))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v10) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v10 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v10))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v11) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v11 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v11))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v12) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v12 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v12))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v13) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v13 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v13))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v14) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v14 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v14))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v15) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v15 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v15))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v16) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v16 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v16))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v17) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v17 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v17))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v18) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v18 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v18))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v19) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v19 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v19))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v20) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v20 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v20))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v21) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v21 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v21))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v22) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v22 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v22))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v23) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v23 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v23))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v24) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v24 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v24))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v25) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v25 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v25))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v26) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v26 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v26))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v27) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v27 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v27))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v28) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v28 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v28))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v29) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v29 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v29))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v30) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v30 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v30))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v31) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v31 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v31))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v32) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v32 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v32))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v33) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v33 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v33))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v34) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v34 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v34))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v35) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v35 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v35))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v36) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v36 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v36))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v37) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v37 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v37))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v38) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v38 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v38))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v39) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v39 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v39))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v40) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v40 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v40))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v41) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v41 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v41))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v42) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v42 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v42))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v43) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v43 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v43))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v44) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v44 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v44))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v45) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v45 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v45))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v46) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v46 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v46))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v47) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v47 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v47))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v48) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v48 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v48))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v49) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v49 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v49))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v50) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v50 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v50))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v51) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v51 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v51))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v52) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v52 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v52))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v53) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v53 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v53))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v54) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v54 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v54))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v55) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v55 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v55))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v56) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v56 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v56))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v57) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v57 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v57))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v58) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v58 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v58))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v59) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v59 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v59))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v60) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v60 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v60))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v61) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v61 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v61))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v62) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v62 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v62))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v63) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v63 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v63))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v64) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v64 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v64))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v65) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v65 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v65))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble = 0x0000000100000001ULL;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v2))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v3) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v3 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v3))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v4) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v4 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v4))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v5) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v5 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v5))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v6) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v6 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v6))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v7) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v7 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v7))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v8) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v8 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v8))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v9) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v9 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v9))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v10) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v10 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v10))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v11) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v11 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v11))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v12) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v12 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v12))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v13) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v13 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v13))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v14) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v14 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v14))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v15) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v15 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v15))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v16) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v16 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v16))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v17) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v17 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v17))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v18) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v18 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v18))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v19) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v19 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v19))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v20) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v20 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v20))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v21) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v21 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v21))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v22) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v22 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v22))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v23) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v23 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v23))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v24) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v24 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v24))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v25) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v25 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v25))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v26) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v26 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v26))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v27) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v27 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v27))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v28) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v28 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v28))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v29) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v29 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v29))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v30) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v30 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v30))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v31) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v31 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v31))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v32) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v32 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v32))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v33) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v33 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v33))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v34) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v34 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v34))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v35) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v35 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v35))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v36) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v36 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v36))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v37) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v37 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v37))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v38) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v38 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v38))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v39) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v39 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v39))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v40) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v40 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v40))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v41) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v41 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v41))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v42) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v42 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v42))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v43) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v43 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v43))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v44) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v44 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v44))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v45) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v45 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v45))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v46) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v46 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v46))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v47) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v47 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v47))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v48) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v48 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v48))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v49) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v49 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v49))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v50) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v50 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v50))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v51) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v51 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v51))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v52) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v52 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v52))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v53) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v53 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v53))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v54) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v54 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v54))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v55) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v55 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v55))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v56) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v56 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v56))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v57) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v57 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v57))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v58) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v58 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v58))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v59) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v59 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v59))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v60) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v60 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v60))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v61) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v61 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v61))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v62) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v62 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v62))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v63) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v63 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v63))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v64) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v64 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v64))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v65) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v65 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v65))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low = 0x0000000100000001ULL;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v2))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v3) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v3 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v3))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v4) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v4 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v4))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v5) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v5 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v5))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v6) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v6 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v6))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v7) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v7 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v7))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v8) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v8 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v8))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v9) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v9 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v9))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v10) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v10 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v10))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v11) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v11 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v11))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v12) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v12 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v12))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v13) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v13 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v13))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v14) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v14 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v14))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v15) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v15 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v15))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v16) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v16 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v16))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v17) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v17 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v17))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v18) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v18 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v18))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v19) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v19 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v19))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v20) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v20 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v20))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v21) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v21 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v21))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v22) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v22 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v22))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v23) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v23 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v23))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v24) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v24 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v24))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v25) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v25 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v25))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v26) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v26 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v26))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v27) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v27 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v27))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v28) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v28 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v28))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v29) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v29 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v29))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v30) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v30 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v30))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v31) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v31 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v31))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v32) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v32 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v32))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v33) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v33 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v33))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v34) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v34 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v34))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v35) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v35 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v35))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v36) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v36 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v36))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v37) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v37 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v37))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v38) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v38 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v38))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v39) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v39 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v39))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v40) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v40 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v40))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v41) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v41 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v41))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v42) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v42 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v42))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v43) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v43 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v43))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v44) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v44 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v44))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v45) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v45 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v45))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v46) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v46 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v46))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v47) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v47 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v47))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v48) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v48 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v48))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v49) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v49 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v49))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v50) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v50 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v50))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v51) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v51 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v51))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v52) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v52 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v52))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v53) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v53 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v53))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v54) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v54 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v54))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v55) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v55 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v55))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v56) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v56 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v56))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v57) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v57 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v57))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v58) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v58 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v58))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v59) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v59 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v59))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v60) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v60 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v60))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v61) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v61 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v61))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v62) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v62 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v62))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v63) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v63 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v63))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v64) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v64 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v64))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v65) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v65 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low 
            = ((~ (1ULL << (IData)(vlSelfRef.__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v65))) 
               & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low);
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v0) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v0 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v1) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v1 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v2) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v2 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v3) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v3 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[3U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v4) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v4 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[4U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v5) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v5 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[5U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v6) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v6 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[6U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v7) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v7 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[7U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v8) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v8 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[8U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v9) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v9 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[9U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v10) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v10 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[10U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v11) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v11 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[11U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v12) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v12 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[12U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v13) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v13 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[13U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v14) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v14 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[14U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v15) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v15 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[15U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v16) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v16 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[16U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v17) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v17 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[17U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v18) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v18 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[18U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v19) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v19 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[19U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v20) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v20 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[20U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v21) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v21 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[21U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v22) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v22 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[22U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v23) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v23 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[23U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v24) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v24 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[24U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v25) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v25 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[25U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v26) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v26 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[26U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v27) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v27 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[27U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v28) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v28 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[28U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v29) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v29 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[29U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v30) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v30 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[30U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v31) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v31 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[31U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v32) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v32 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[32U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v33) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v33 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[33U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v34) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v34 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[34U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v35) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v35 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[35U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v36) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v36 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[36U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v37) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v37 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[37U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v38) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v38 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[38U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v39) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v39 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[39U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v40) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v40 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[40U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v41) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v41 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[41U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v42) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v42 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[42U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v43) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v43 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[43U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v44) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v44 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[44U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v45) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v45 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[45U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v46) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v46 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[46U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v47) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v47 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[47U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v48) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v48 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[48U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v49) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v49 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[49U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v50) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v50 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[50U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v51) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v51 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[51U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v52) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v52 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[52U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v53) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v53 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[53U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v54) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v54 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[54U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v55) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v55 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[55U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v56) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v56 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[56U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v57) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v57 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[57U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v58) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v58 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[58U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v59) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v59 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[59U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v60) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v60 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[60U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v61) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v61 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[61U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v62) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v62 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[62U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v63) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v63 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v64) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v64 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v65) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v65 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v66) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v66 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[3U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v67) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v67 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[4U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v68) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v68 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[5U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v69) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v69 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[6U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v70) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v70 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[7U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v71) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v71 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[8U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v72) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v72 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[9U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v73) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v73 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[10U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v74) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v74 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[11U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v75) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v75 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[12U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v76) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v76 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[13U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v77) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v77 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[14U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v78) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v78 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[15U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v79) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v79 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[16U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v80) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v80 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[17U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v81) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v81 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[18U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v82) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v82 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[19U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v83) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v83 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[20U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v84) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v84 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[21U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v85) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v85 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[22U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v86) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v86 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[23U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v87) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v87 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[24U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v88) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v88 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[25U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v89) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v89 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[26U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v90) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v90 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[27U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v91) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v91 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[28U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v92) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v92 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[29U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v93) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v93 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[30U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v94) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v94 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[31U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v95) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v95 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[32U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v96) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v96 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[33U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v97) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v97 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[34U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v98) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v98 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[35U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v99) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v99 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[36U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v100) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v100 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[37U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v101) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v101 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[38U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v102) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v102 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[39U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v103) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v103 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[40U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v104) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v104 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[41U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v105) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v105 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[42U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v106) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v106 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[43U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v107) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v107 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[44U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v108) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v108 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[45U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v109) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v109 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[46U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v110) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v110 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[47U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v111) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v111 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[48U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v112) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v112 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[49U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v113) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v113 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[50U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v114) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v114 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[51U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v115) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v115 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[52U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v116) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v116 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[53U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v117) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v117 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[54U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v118) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v118 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[55U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v119) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v119 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[56U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v120) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v120 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[57U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v121) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v121 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[58U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v122) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v122 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[59U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v123) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v123 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[60U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v124) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v124 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[61U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v125) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v125 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[62U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v126) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v126 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[63U] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v147) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v147 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v147] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v147;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v148) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v148 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v148] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v148;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v149) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v149 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v149] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v149;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v150) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v150 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v150] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v150;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v151) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v151 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v151] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v151;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v152) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v152 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v152] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v152;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v153) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v153 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v153] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v153;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v154) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v154 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v154] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v154;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v155) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v155 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v155] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v155;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v156) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v156 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v156] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v156;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v157) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v157 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v157] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v157;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v158) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v158 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v158] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v158;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189;
    }
    if (vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190) {
        vlSelfRef.__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190 = 0U;
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[vlSelfRef.__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190] 
            = vlSelfRef.__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190;
    }
}

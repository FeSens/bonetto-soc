// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ddr3_init_top.h for the primary calling header

#include "Vtb_ddr3_init_top__pch.h"

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___eval_static__TOP(Vtb_ddr3_init_top___024root* vlSelf);
void Vtb_ddr3_init_top___024root___timing_ready(Vtb_ddr3_init_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___eval_static(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_static\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ddr3_init_top___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__VactTriggered[1U] = (0x0000000200000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000000400000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000000800000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000001000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000002000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000004000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000008000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000010000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000020000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000040000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000080000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000100000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000200000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000400000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0000800000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0001000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0002000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0004000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0008000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0010000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0020000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0040000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0080000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0100000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0200000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0400000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x0800000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x1000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x2000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x4000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[1U] = (0x8000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[1U]);
    vlSelfRef.__VactTriggered[2U] = (1ULL | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (2ULL | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (4ULL | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (8ULL | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000000010ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000000020ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000000040ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000000080ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000000100ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000000200ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000000400ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000000800ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000001000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000002000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000004000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000008000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000010000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000020000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000040000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000080000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000100000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000200000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000400000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000000800000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000001000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000002000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000004000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000008000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000010000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000020000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000040000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000080000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000100000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000200000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000400000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000000800000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000001000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000002000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000004000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000008000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000010000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000020000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000040000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000080000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000100000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000200000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000400000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0000800000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0001000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0002000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0004000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0008000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0010000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0020000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0040000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0080000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0100000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0200000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0400000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x0800000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x1000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x2000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x4000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[2U] = (0x8000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[2U]);
    vlSelfRef.__VactTriggered[3U] = (1ULL | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (2ULL | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (4ULL | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (8ULL | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000000010ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000000020ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000000040ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000000080ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000000100ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000000200ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000000400ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000000800ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000001000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000002000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000004000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000008000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000010000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000020000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000040000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000080000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000100000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000200000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000400000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000000800000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000001000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000002000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000004000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000008000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000010000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000020000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000040000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000080000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000100000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000200000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000400000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000000800000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000001000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000002000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000004000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000008000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000010000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000020000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000040000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000080000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000100000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000200000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000400000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0000800000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0001000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0002000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0004000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0008000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0010000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0020000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0040000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0080000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0100000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0200000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0400000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x0800000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x1000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x2000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x4000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[3U] = (0x8000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[3U]);
    vlSelfRef.__VactTriggered[4U] = (1ULL | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (2ULL | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (4ULL | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (8ULL | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000000010ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000000020ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000000040ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000000080ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000000100ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000000200ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000000400ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000000800ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000001000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000002000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000004000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000008000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000010000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000020000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000040000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000080000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000100000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000200000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000400000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000000800000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000001000000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000002000000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[4U] = (0x0000000004000000ULL 
                                     | vlSelfRef.__VactTriggered[4U]);
    vlSelfRef.__VactTriggered[5U] = (0x0800000000000000ULL 
                                     | vlSelfRef.__VactTriggered[5U]);
    vlSelfRef.__VactTriggered[5U] = (0x2000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[5U]);
    vlSelfRef.__VactTriggered[5U] = (0x4000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[5U]);
    vlSelfRef.__VactTriggered[5U] = (0x8000000000000000ULL 
                                     | vlSelfRef.__VactTriggered[5U]);
    vlSelfRef.__VactTriggered[6U] = (1ULL | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (2ULL | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (4ULL | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (8ULL | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (0x0000000000000010ULL 
                                     | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (0x0000000000000020ULL 
                                     | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (0x0000000000000040ULL 
                                     | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (0x0000000000000080ULL 
                                     | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (0x0000000000000100ULL 
                                     | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__VactTriggered[6U] = (0x0000000000000200ULL 
                                     | vlSelfRef.__VactTriggered[6U]);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__clk_phy__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__ck_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_in;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in;
    vlSelfRef.__Vtrigprevexpr_h08656a01__0 = (1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in));
    vlSelfRef.__Vtrigprevexpr_h08656b42__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 1U)));
    vlSelfRef.__Vtrigprevexpr_h086571b6__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 2U)));
    vlSelfRef.__Vtrigprevexpr_h086570f5__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 3U)));
    vlSelfRef.__Vtrigprevexpr_h08657134__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 4U)));
    vlSelfRef.__Vtrigprevexpr_h08656a73__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 5U)));
    vlSelfRef.__Vtrigprevexpr_h086570a9__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 6U)));
    vlSelfRef.__Vtrigprevexpr_h08656fea__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 7U)));
    vlSelfRef.__Vtrigprevexpr_h08657037__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 8U)));
    vlSelfRef.__Vtrigprevexpr_h08657178__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 9U)));
    vlSelfRef.__Vtrigprevexpr_h086576e0__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000000aU)));
    vlSelfRef.__Vtrigprevexpr_h0865779f__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000000bU)));
    vlSelfRef.__Vtrigprevexpr_h08656872__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000000cU)));
    vlSelfRef.__Vtrigprevexpr_h08656731__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000000dU)));
    vlSelfRef.__Vtrigprevexpr_h086575db__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000000eU)));
    vlSelfRef.__Vtrigprevexpr_h0865769c__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000000fU)));
    vlSelfRef.__Vtrigprevexpr_h086571c9__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000020U)));
    vlSelfRef.__Vtrigprevexpr_h0865720a__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000021U)));
    vlSelfRef.__Vtrigprevexpr_h0865794e__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000022U)));
    vlSelfRef.__Vtrigprevexpr_h0865798d__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000023U)));
    vlSelfRef.__Vtrigprevexpr_h086578cc__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000024U)));
    vlSelfRef.__Vtrigprevexpr_h0865790b__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000025U)));
    vlSelfRef.__Vtrigprevexpr_h086578a1__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000026U)));
    vlSelfRef.__Vtrigprevexpr_h086577e2__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000027U)));
    vlSelfRef.__Vtrigprevexpr_h086577cf__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000028U)));
    vlSelfRef.__Vtrigprevexpr_h08657810__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x00000029U)));
    vlSelfRef.__Vtrigprevexpr_h0864ff88__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000002aU)));
    vlSelfRef.__Vtrigprevexpr_h0864fec7__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000002bU)));
    vlSelfRef.__Vtrigprevexpr_h08656efa__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000002cU)));
    vlSelfRef.__Vtrigprevexpr_h08657039__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000002dU)));
    vlSelfRef.__Vtrigprevexpr_h0864fe83__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000002eU)));
    vlSelfRef.__Vtrigprevexpr_h0864fdc4__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0000002fU)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__cke_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cke_in;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__odt_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_in;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in;
    vlSelfRef.__Vtrigprevexpr_h1bed9077__0 = (1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ba_in));
    vlSelfRef.__Vtrigprevexpr_h1bed8a19__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ba_in) 
                                               >> 1U));
    vlSelfRef.__Vtrigprevexpr_h1bed8ade__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ba_in) 
                                               >> 2U));
    vlSelfRef.__Vtrigprevexpr_hb7b42cfa__0 = (1U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in);
    vlSelfRef.__Vtrigprevexpr_hb7b42e3e__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 1U));
    vlSelfRef.__Vtrigprevexpr_hb7b4279a__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 2U));
    vlSelfRef.__Vtrigprevexpr_hb7b426dd__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 3U));
    vlSelfRef.__Vtrigprevexpr_hb7b42e11__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 4U));
    vlSelfRef.__Vtrigprevexpr_hb7b4275f__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 5U));
    vlSelfRef.__Vtrigprevexpr_hb7b42c79__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 6U));
    vlSelfRef.__Vtrigprevexpr_hb7b42bc6__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 7U));
    vlSelfRef.__Vtrigprevexpr_hb7b42b24__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 8U));
    vlSelfRef.__Vtrigprevexpr_hb7b42c3c__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 9U));
    vlSelfRef.__Vtrigprevexpr_hb7b42d80__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 0x0aU));
    vlSelfRef.__Vtrigprevexpr_hb7b42cbf__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 0x0bU));
    vlSelfRef.__Vtrigprevexpr_hb7b42bfb__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 0x0cU));
    vlSelfRef.__Vtrigprevexpr_hb7b42d3d__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 0x0dU));
    vlSelfRef.__Vtrigprevexpr_hb7b434cf__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 0x0eU));
    vlSelfRef.__Vtrigprevexpr_hb7b43210__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 0x0fU));
    vlSelfRef.__Vtrigprevexpr_hb7b4314e__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in 
                                               >> 0x10U));
    vlSelfRef.__Vtrigprevexpr_h7eb5ad84__0 = (1U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in);
    vlSelfRef.__Vtrigprevexpr_h7eb5b0c8__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 1U));
    vlSelfRef.__Vtrigprevexpr_h7eb64224__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 2U));
    vlSelfRef.__Vtrigprevexpr_h7eb64367__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 3U));
    vlSelfRef.__Vtrigprevexpr_h7eb5aa8b__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 4U));
    vlSelfRef.__Vtrigprevexpr_h7eb641e1__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 5U));
    vlSelfRef.__Vtrigprevexpr_h7eb5ab03__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 6U));
    vlSelfRef.__Vtrigprevexpr_h7eb5ac40__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 7U));
    vlSelfRef.__Vtrigprevexpr_h7eb645d6__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 8U));
    vlSelfRef.__Vtrigprevexpr_h7eb5aabe__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 9U));
    vlSelfRef.__Vtrigprevexpr_h7eb5ac02__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x0aU));
    vlSelfRef.__Vtrigprevexpr_h7eb5ad41__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x0bU));
    vlSelfRef.__Vtrigprevexpr_h7eb5ac7d__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x0cU));
    vlSelfRef.__Vtrigprevexpr_h7eb5abc7__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x0dU));
    vlSelfRef.__Vtrigprevexpr_h7eb5b551__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x0eU));
    vlSelfRef.__Vtrigprevexpr_h7eb5ae92__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x0fU));
    vlSelfRef.__Vtrigprevexpr_h7eb5afd8__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x10U));
    vlSelfRef.__Vtrigprevexpr_h7eb5b514__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x11U));
    vlSelfRef.__Vtrigprevexpr_h7eb64658__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x12U));
    vlSelfRef.__Vtrigprevexpr_h7eb6475b__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x13U));
    vlSelfRef.__Vtrigprevexpr_h7eb5b4d7__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x14U));
    vlSelfRef.__Vtrigprevexpr_h7eb64615__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x15U));
    vlSelfRef.__Vtrigprevexpr_h7eb5af4f__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x16U));
    vlSelfRef.__Vtrigprevexpr_h7eb5b08c__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x17U));
    vlSelfRef.__Vtrigprevexpr_h7eb5a9ca__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x18U));
    vlSelfRef.__Vtrigprevexpr_h7eb5af0a__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x19U));
    vlSelfRef.__Vtrigprevexpr_h7eb5b056__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x1aU));
    vlSelfRef.__Vtrigprevexpr_h7eb5b195__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x1bU));
    vlSelfRef.__Vtrigprevexpr_h7eb5aec9__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x1cU));
    vlSelfRef.__Vtrigprevexpr_h7eb5afdb__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x1dU));
    vlSelfRef.__Vtrigprevexpr_h7eb5991d__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                               >> 0x1eU));
    vlSelfRef.__Vtrigprevexpr_h7eb5925e__0 = (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in 
                                              >> 0x1fU);
    vlSelfRef.__Vtrigprevexpr_h424933b1__0 = (1U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U]);
    vlSelfRef.__Vtrigprevexpr_h42493360__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 1U));
    vlSelfRef.__Vtrigprevexpr_h4249331f__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 2U));
    vlSelfRef.__Vtrigprevexpr_h42491ce7__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 3U));
    vlSelfRef.__Vtrigprevexpr_h42491ca8__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 4U));
    vlSelfRef.__Vtrigprevexpr_h42492859__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 5U));
    vlSelfRef.__Vtrigprevexpr_h42491c36__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 6U));
    vlSelfRef.__Vtrigprevexpr_h42491df8__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 7U));
    vlSelfRef.__Vtrigprevexpr_h424921b7__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 8U));
    vlSelfRef.__Vtrigprevexpr_h4249216a__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 9U));
    vlSelfRef.__Vtrigprevexpr_h42492129__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000000aU));
    vlSelfRef.__Vtrigprevexpr_h424932dd__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000000bU));
    vlSelfRef.__Vtrigprevexpr_h4249329e__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000000cU));
    vlSelfRef.__Vtrigprevexpr_h42491e5b__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000000dU));
    vlSelfRef.__Vtrigprevexpr_h42493208__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000000eU));
    vlSelfRef.__Vtrigprevexpr_h424953c6__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000000fU));
    vlSelfRef.__Vtrigprevexpr_h42495785__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000010U));
    vlSelfRef.__Vtrigprevexpr_h42495744__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000011U));
    vlSelfRef.__Vtrigprevexpr_h42495703__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000012U));
    vlSelfRef.__Vtrigprevexpr_h424920f3__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000013U));
    vlSelfRef.__Vtrigprevexpr_h424920b4__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000014U));
    vlSelfRef.__Vtrigprevexpr_h42491c75__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000015U));
    vlSelfRef.__Vtrigprevexpr_h42492002__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000016U));
    vlSelfRef.__Vtrigprevexpr_h4249322c__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000017U));
    vlSelfRef.__Vtrigprevexpr_h424931eb__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000018U));
    vlSelfRef.__Vtrigprevexpr_h424935ae__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x00000019U));
    vlSelfRef.__Vtrigprevexpr_h4249356d__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000001aU));
    vlSelfRef.__Vtrigprevexpr_h424956b9__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000001bU));
    vlSelfRef.__Vtrigprevexpr_h4249567a__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000001cU));
    vlSelfRef.__Vtrigprevexpr_h42493247__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000001dU));
    vlSelfRef.__Vtrigprevexpr_h42495614__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                               >> 0x0000001eU));
    vlSelfRef.__Vtrigprevexpr_h424957ca__0 = (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[0U] 
                                              >> 0x0000001fU);
    vlSelfRef.__Vtrigprevexpr_h42494b89__0 = (1U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U]);
    vlSelfRef.__Vtrigprevexpr_h42494b58__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 1U));
    vlSelfRef.__Vtrigprevexpr_h42494b17__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 2U));
    vlSelfRef.__Vtrigprevexpr_h4249352f__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 3U));
    vlSelfRef.__Vtrigprevexpr_h424934f0__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 4U));
    vlSelfRef.__Vtrigprevexpr_h42492041__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 5U));
    vlSelfRef.__Vtrigprevexpr_h424953fe__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 6U));
    vlSelfRef.__Vtrigprevexpr_h424955c0__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 7U));
    vlSelfRef.__Vtrigprevexpr_h4249597f__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 8U));
    vlSelfRef.__Vtrigprevexpr_h42495952__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 9U));
    vlSelfRef.__Vtrigprevexpr_h42495911__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000000aU));
    vlSelfRef.__Vtrigprevexpr_h42494ad5__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000000bU));
    vlSelfRef.__Vtrigprevexpr_h42494a96__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000000cU));
    vlSelfRef.__Vtrigprevexpr_h42495653__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000000dU));
    vlSelfRef.__Vtrigprevexpr_h42488a80__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000000eU));
    vlSelfRef.__Vtrigprevexpr_h42488dbe__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000000fU));
    vlSelfRef.__Vtrigprevexpr_h424890fd__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000010U));
    vlSelfRef.__Vtrigprevexpr_h42488e3c__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000011U));
    vlSelfRef.__Vtrigprevexpr_h4248917b__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000012U));
    vlSelfRef.__Vtrigprevexpr_h424958bb__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000013U));
    vlSelfRef.__Vtrigprevexpr_h4249587c__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000014U));
    vlSelfRef.__Vtrigprevexpr_h4249543d__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000015U));
    vlSelfRef.__Vtrigprevexpr_h42488c8a__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000016U));
    vlSelfRef.__Vtrigprevexpr_h424897d4__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000017U));
    vlSelfRef.__Vtrigprevexpr_h42488b13__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000018U));
    vlSelfRef.__Vtrigprevexpr_h42489856__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x00000019U));
    vlSelfRef.__Vtrigprevexpr_h42488b95__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000001aU));
    vlSelfRef.__Vtrigprevexpr_h42488ad1__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000001bU));
    vlSelfRef.__Vtrigprevexpr_h42488e12__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000001cU));
    vlSelfRef.__Vtrigprevexpr_h42488b3f__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000001dU));
    vlSelfRef.__Vtrigprevexpr_h42488eec__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                               >> 0x0000001eU));
    vlSelfRef.__Vtrigprevexpr_h424961c2__0 = (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[1U] 
                                              >> 0x0000001fU);
    vlSelfRef.__Vtrigprevexpr_h42496501__0 = (1U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U]);
    vlSelfRef.__Vtrigprevexpr_h424962b0__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 1U));
    vlSelfRef.__Vtrigprevexpr_h424961ef__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 2U));
    vlSelfRef.__Vtrigprevexpr_h42488cd7__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 3U));
    vlSelfRef.__Vtrigprevexpr_h42489818__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 4U));
    vlSelfRef.__Vtrigprevexpr_h42488d49__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 5U));
    vlSelfRef.__Vtrigprevexpr_h42489086__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 6U));
    vlSelfRef.__Vtrigprevexpr_h42488bc8__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 7U));
    vlSelfRef.__Vtrigprevexpr_h42488f07__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 8U));
    vlSelfRef.__Vtrigprevexpr_h42488c3a__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 9U));
    vlSelfRef.__Vtrigprevexpr_h42488f79__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000000aU));
    vlSelfRef.__Vtrigprevexpr_h42488f2d__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000000bU));
    vlSelfRef.__Vtrigprevexpr_h4249626e__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000000cU));
    vlSelfRef.__Vtrigprevexpr_h42488fab__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000000dU));
    vlSelfRef.__Vtrigprevexpr_h424962b8__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000000eU));
    vlSelfRef.__Vtrigprevexpr_h424945f6__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000000fU));
    vlSelfRef.__Vtrigprevexpr_h42494935__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000010U));
    vlSelfRef.__Vtrigprevexpr_h42494674__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000011U));
    vlSelfRef.__Vtrigprevexpr_h424949b3__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000012U));
    vlSelfRef.__Vtrigprevexpr_h424890c3__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000013U));
    vlSelfRef.__Vtrigprevexpr_h42488c04__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000014U));
    vlSelfRef.__Vtrigprevexpr_h42489145__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000015U));
    vlSelfRef.__Vtrigprevexpr_h424964b2__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000016U));
    vlSelfRef.__Vtrigprevexpr_h42488fdc__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000017U));
    vlSelfRef.__Vtrigprevexpr_h4249631b__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000018U));
    vlSelfRef.__Vtrigprevexpr_h4248905e__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x00000019U));
    vlSelfRef.__Vtrigprevexpr_h4249639d__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000001aU));
    vlSelfRef.__Vtrigprevexpr_h424962e9__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000001bU));
    vlSelfRef.__Vtrigprevexpr_h4249462a__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000001cU));
    vlSelfRef.__Vtrigprevexpr_h42496377__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000001dU));
    vlSelfRef.__Vtrigprevexpr_h424946a4__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                               >> 0x0000001eU));
    vlSelfRef.__Vtrigprevexpr_h424939da__0 = (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[2U] 
                                              >> 0x0000001fU);
    vlSelfRef.__Vtrigprevexpr_h42493d19__0 = (1U & vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U]);
    vlSelfRef.__Vtrigprevexpr_h42493a68__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 1U));
    vlSelfRef.__Vtrigprevexpr_h42493da7__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 2U));
    vlSelfRef.__Vtrigprevexpr_h424964df__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 3U));
    vlSelfRef.__Vtrigprevexpr_h42489020__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 4U));
    vlSelfRef.__Vtrigprevexpr_h42496571__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 5U));
    vlSelfRef.__Vtrigprevexpr_h4249488e__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 6U));
    vlSelfRef.__Vtrigprevexpr_h424943d0__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 7U));
    vlSelfRef.__Vtrigprevexpr_h4249470f__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 8U));
    vlSelfRef.__Vtrigprevexpr_h42494462__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 9U));
    vlSelfRef.__Vtrigprevexpr_h424947a1__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000000aU));
    vlSelfRef.__Vtrigprevexpr_h424946e5__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000000bU));
    vlSelfRef.__Vtrigprevexpr_h42493a26__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000000cU));
    vlSelfRef.__Vtrigprevexpr_h42494763__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000000dU));
    vlSelfRef.__Vtrigprevexpr_h42493b30__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000000eU));
    vlSelfRef.__Vtrigprevexpr_h42493dee__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000000fU));
    vlSelfRef.__Vtrigprevexpr_h424941ad__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000010U));
    vlSelfRef.__Vtrigprevexpr_h42493e6c__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000011U));
    vlSelfRef.__Vtrigprevexpr_h42493e2b__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000012U));
    vlSelfRef.__Vtrigprevexpr_h424948cb__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000013U));
    vlSelfRef.__Vtrigprevexpr_h4249440c__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000014U));
    vlSelfRef.__Vtrigprevexpr_h4249494d__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000015U));
    vlSelfRef.__Vtrigprevexpr_h42493cba__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000016U));
    vlSelfRef.__Vtrigprevexpr_h42493b84__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000017U));
    vlSelfRef.__Vtrigprevexpr_h42493b43__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000018U));
    vlSelfRef.__Vtrigprevexpr_h42494806__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x00000019U));
    vlSelfRef.__Vtrigprevexpr_h424947c5__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000001aU));
    vlSelfRef.__Vtrigprevexpr_h42493a81__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000001bU));
    vlSelfRef.__Vtrigprevexpr_h42493e42__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000001cU));
    vlSelfRef.__Vtrigprevexpr_h42493b6f__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000001dU));
    vlSelfRef.__Vtrigprevexpr_h42493ebc__0 = (1U & 
                                              (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                               >> 0x0000001eU));
    vlSelfRef.__Vtrigprevexpr_h42495592__0 = (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in[3U] 
                                              >> 0x0000001fU);
    vlSelfRef.__Vtrigprevexpr_h08fd6da6__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x20U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6be3__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x21U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4327__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x22U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6d65__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x23U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4499__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x24U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4ee8__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x25U)));
    vlSelfRef.__Vtrigprevexpr_h08fd69ca__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x26U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6f16__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x27U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6b58__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x28U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6a89__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x29U)));
    vlSelfRef.__Vtrigprevexpr_h08fd70cd__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x2aU)));
    vlSelfRef.__Vtrigprevexpr_h08fd6a17__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x2bU)));
    vlSelfRef.__Vtrigprevexpr_h08fd6a4b__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x2cU)));
    vlSelfRef.__Vtrigprevexpr_h08fd6d8e__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x2dU)));
    vlSelfRef.__Vtrigprevexpr_h08fd7978__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x2eU)));
    vlSelfRef.__Vtrigprevexpr_h08fd6d38__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x2fU)));
    vlSelfRef.__Vtrigprevexpr_h08fd78ea__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x30U)));
    vlSelfRef.__Vtrigprevexpr_h08fd78b7__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x31U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6ed3__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x32U)));
    vlSelfRef.__Vtrigprevexpr_h08fd7829__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x33U)));
    vlSelfRef.__Vtrigprevexpr_h08fd7055__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x34U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6b94__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x35U)));
    vlSelfRef.__Vtrigprevexpr_h08fd776e__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x36U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6b02__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x37U)));
    vlSelfRef.__Vtrigprevexpr_h08fd76ec__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x38U)));
    vlSelfRef.__Vtrigprevexpr_h08fd76ad__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x39U)));
    vlSelfRef.__Vtrigprevexpr_h08fd7669__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x3aU)));
    vlSelfRef.__Vtrigprevexpr_h08fd762b__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x3bU)));
    vlSelfRef.__Vtrigprevexpr_h08fd75f7__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x3cU)));
    vlSelfRef.__Vtrigprevexpr_h08fd79aa__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x3dU)));
    vlSelfRef.__Vtrigprevexpr_h08fd753c__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x3eU)));
    vlSelfRef.__Vtrigprevexpr_h08fd7904__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x3fU)));
    vlSelfRef.__Vtrigprevexpr_h08fd45ae__0 = (1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in));
    vlSelfRef.__Vtrigprevexpr_h08fd43eb__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 1U)));
    vlSelfRef.__Vtrigprevexpr_h08fd3aff__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 2U)));
    vlSelfRef.__Vtrigprevexpr_h08fd456d__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 3U)));
    vlSelfRef.__Vtrigprevexpr_h08fd3c91__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 4U)));
    vlSelfRef.__Vtrigprevexpr_h08fd46c0__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 5U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4202__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 6U)));
    vlSelfRef.__Vtrigprevexpr_h08fd486e__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 7U)));
    vlSelfRef.__Vtrigprevexpr_h08fd43b0__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 8U)));
    vlSelfRef.__Vtrigprevexpr_h08fd41c1__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 9U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4935__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0aU)));
    vlSelfRef.__Vtrigprevexpr_h08fd436f__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0bU)));
    vlSelfRef.__Vtrigprevexpr_h08fd42b3__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0cU)));
    vlSelfRef.__Vtrigprevexpr_h08fd44f6__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0dU)));
    vlSelfRef.__Vtrigprevexpr_h08fd7020__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0eU)));
    vlSelfRef.__Vtrigprevexpr_h08fd4e60__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x0fU)));
    vlSelfRef.__Vtrigprevexpr_h08fd71b2__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x10U)));
    vlSelfRef.__Vtrigprevexpr_h08fd6fdf__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x11U)));
    vlSelfRef.__Vtrigprevexpr_h08fd472b__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x12U)));
    vlSelfRef.__Vtrigprevexpr_h08fd7171__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x13U)));
    vlSelfRef.__Vtrigprevexpr_h08fd48ad__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x14U)));
    vlSelfRef.__Vtrigprevexpr_h08fd42ec__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x15U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4e26__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x16U)));
    vlSelfRef.__Vtrigprevexpr_h08fd445a__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x17U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4fa4__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x18U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4de5__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x19U)));
    vlSelfRef.__Vtrigprevexpr_h08fd4531__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1aU)));
    vlSelfRef.__Vtrigprevexpr_h08fd4f63__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1bU)));
    vlSelfRef.__Vtrigprevexpr_h08fd4e9f__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1cU)));
    vlSelfRef.__Vtrigprevexpr_h08fd70f2__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1dU)));
    vlSelfRef.__Vtrigprevexpr_h08fd6c24__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1eU)));
    vlSelfRef.__Vtrigprevexpr_h08fd710c__0 = (1U & (IData)(
                                                           (vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                                            >> 0x1fU)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke;
    vlSelfRef.__Vtrigprevexpr_h60001e29__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                               >> 3U));
    vlSelfRef.__Vtrigprevexpr_h6000216a__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                               >> 2U));
    vlSelfRef.__Vtrigprevexpr_h60001fa6__0 = (1U & 
                                              ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                               >> 1U));
    vlSelfRef.__Vtrigprevexpr_h60001ee5__0 = (1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd));
    vlSelfRef.__Vtrigprevexpr_h81d9cd46__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dq__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dqs__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__init_done__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__init_done;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__init_error__0 
        = vlSelfRef.tb_ddr3_init_top__DOT__init_error;
    Vtb_ddr3_init_top___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((7U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___eval_static__TOP(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_static__TOP\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ddr3_init_top__DOT__clk_phy = 0U;
    vlSelfRef.tb_ddr3_init_top__DOT__rst = 1U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQCS = 0x00000040U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQINIT = 0x00000200U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQOPER = 0x00000100U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__min_cl__Vstatic__cwl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 326811307985478391ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__min_cl__Vstatic__cl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14630384661639976704ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__bank = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2966176962064528362ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__row = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 10170838761602259831ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__col = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 14789417925663953901ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__addr = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 7123185040016071731ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 78304668507452060ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__char, __VscopeHash, 13925412496568606927ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4034884230233323702ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__fio_status = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18405688539774496352ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15033378200036306728ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 827303933179042686ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename, __VscopeHash, 3209748962774836174ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10503892597155996482ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__offset = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7161092971043315615ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__msg, __VscopeHash, 9758701667254312275ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__read_value = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2673848825217412311ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__write_to_file__Vstatic__code = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13163893724855390733ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__write_to_file__Vstatic__offset = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8027221616639935148ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__memory_write__Vstatic__addr = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 5901775209224696469ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__memory_read__Vstatic__addr = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6361949687359093406ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__ba = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9269778467800738197ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__i = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4483981667596652123ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__bank = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9054906333911821919ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__reset_task__Vstatic__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14630569433033391987ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__chk_err__Vstatic__err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15149968957306510720ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__i = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9918085763449668932ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6943114166787084910ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__tfaw_cntr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15962159139426218488ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__col = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9202643723231291552ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__group = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1625988416223539683ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__bank = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3438237065374841103ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__row = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 13484236234723679181ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__col = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 11265789963154862175ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1143772768893242801ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8792595959744402282ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__reset__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18429537990271924801ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__main__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11054770800777924490ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_even_receiver__Vstatic__bit_mask, __VscopeHash, 14838700353497043392ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_odd_receiver__Vstatic__bit_mask, __VscopeHash, 3065045018498562249ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17384011011178350913ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17783586108083660620ull);
}

extern const VlWide<32>/*1023:0*/ Vtb_ddr3_init_top__ConstPool__CONST_hc7cf22ae_0;

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___eval_initial__TOP(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_initial__TOP\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_ddr3_init_top__DOT__u_micron__DOT____VlemExpr_3;
    // Body
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[0U][0U] = 0x4d6f6465U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[0U][1U] = 0x6f616420U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[0U][2U] = 0x0000004cU;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[1U][0U] = 0x73682020U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[1U][1U] = 0x65667265U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[1U][2U] = 0x00000052U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[2U][0U] = 0x61726765U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[2U][1U] = 0x72656368U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[2U][2U] = 0x00000050U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[3U][0U] = 0x61746520U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[3U][1U] = 0x63746976U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[3U][2U] = 0x00000041U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[4U][0U] = 0x20202020U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[4U][1U] = 0x72697465U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[4U][2U] = 0x00000057U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[5U][0U] = 0x20202020U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[5U][1U] = 0x65616420U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[5U][2U] = 0x00000052U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[6U][0U] = 0x20202020U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[6U][1U] = 0x51202020U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[6U][2U] = 0x0000005aU;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[7U][0U] = 0x20202020U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[7U][1U] = 0x6f204f70U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[7U][2U] = 0x0000004eU;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[8U][0U] = 0x6f776e20U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[8U][1U] = 0x77722044U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[8U][2U] = 0x00000050U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[9U][0U] = 0x52656620U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[9U][1U] = 0x656c6620U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[9U][2U] = 0x00000053U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[0U] = 0x0043535f4e202020ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[1U] = 0x005241535f4e2020ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[2U] = 0x004341535f4e2020ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[3U] = 0x0057455f4e202020ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[4U] = 0x0042412030202020ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[5U] = 0x0042412031202020ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[6U] = 0x0042412032202020ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[7U] = 0x0041444452202030ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[8U] = 0x0041444452202031ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[9U] = 0x0041444452202032ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[10U] = 0x0041444452202033ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[11U] = 0x0041444452202034ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[12U] = 0x0041444452202035ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[13U] = 0x0041444452202036ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[14U] = 0x0041444452202037ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[15U] = 0x0041444452202038ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[16U] = 0x0041444452202039ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[17U] = 0x0041444452203130ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[18U] = 0x0041444452203131ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[19U] = 0x0041444452203132ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[20U] = 0x0041444452203133ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[21U] = 0x0041444452203134ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[22U] = 0x0041444452203135ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[23U] = 0x0041444452203136ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string[0U] = 0x0000004451532020ULL;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string[1U] = 0x0000004451535f4eULL;
    tb_ddr3_init_top__DOT__u_micron__DOT____VlemExpr_3 
        = VL_VALUEPLUSARGS_INW(1024, "model_data+%s"s, 
                               vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir);
    if (VL_UNLIKELY(((! tb_ddr3_init_top__DOT__u_micron__DOT____VlemExpr_3)))) {
        VL_ASSIGN_W(1024, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir, Vtb_ddr3_init_top__ConstPool__CONST_hc7cf22ae_0);
        VL_WRITEF_NX("%m: at time %t WARNING: no +model_data option specified, using /tmp.\n",3, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.file_io_open", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1));
    }
    VL_SFORMAT_NX(2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename
                  ,"%0s/%m.0",2, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file"
                  , '#',1024,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir.data());
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename)
                      , "wb+"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd)))) {
        VL_WRITEF_NX("%m: at time %0t ERROR: failed to open %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        VL_FINISH_MT("ip/ddr3/sim/vendor/ddr3.v", 629, "");
    } else {
        VL_WRITEF_NX("%m: at time %0t INFO: opening %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd;
    }
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[0U] 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file;
    VL_SFORMAT_NX(2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename
                  ,"%0s/%m.1",2, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file"
                  , '#',1024,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir.data());
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename)
                      , "wb+"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd)))) {
        VL_WRITEF_NX("%m: at time %0t ERROR: failed to open %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        VL_FINISH_MT("ip/ddr3/sim/vendor/ddr3.v", 629, "");
    } else {
        VL_WRITEF_NX("%m: at time %0t INFO: opening %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd;
    }
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[1U] 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file;
    VL_SFORMAT_NX(2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename
                  ,"%0s/%m.2",2, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file"
                  , '#',1024,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir.data());
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename)
                      , "wb+"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd)))) {
        VL_WRITEF_NX("%m: at time %0t ERROR: failed to open %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        VL_FINISH_MT("ip/ddr3/sim/vendor/ddr3.v", 629, "");
    } else {
        VL_WRITEF_NX("%m: at time %0t INFO: opening %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd;
    }
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[2U] 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file;
    VL_SFORMAT_NX(2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename
                  ,"%0s/%m.3",2, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file"
                  , '#',1024,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir.data());
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename)
                      , "wb+"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd)))) {
        VL_WRITEF_NX("%m: at time %0t ERROR: failed to open %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        VL_FINISH_MT("ip/ddr3/sim/vendor/ddr3.v", 629, "");
    } else {
        VL_WRITEF_NX("%m: at time %0t INFO: opening %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd;
    }
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[3U] 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file;
    VL_SFORMAT_NX(2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename
                  ,"%0s/%m.4",2, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file"
                  , '#',1024,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir.data());
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename)
                      , "wb+"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd)))) {
        VL_WRITEF_NX("%m: at time %0t ERROR: failed to open %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        VL_FINISH_MT("ip/ddr3/sim/vendor/ddr3.v", 629, "");
    } else {
        VL_WRITEF_NX("%m: at time %0t INFO: opening %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd;
    }
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[4U] 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file;
    VL_SFORMAT_NX(2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename
                  ,"%0s/%m.5",2, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file"
                  , '#',1024,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir.data());
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename)
                      , "wb+"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd)))) {
        VL_WRITEF_NX("%m: at time %0t ERROR: failed to open %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        VL_FINISH_MT("ip/ddr3/sim/vendor/ddr3.v", 629, "");
    } else {
        VL_WRITEF_NX("%m: at time %0t INFO: opening %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd;
    }
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[5U] 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file;
    VL_SFORMAT_NX(2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename
                  ,"%0s/%m.6",2, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file"
                  , '#',1024,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir.data());
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename)
                      , "wb+"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd)))) {
        VL_WRITEF_NX("%m: at time %0t ERROR: failed to open %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        VL_FINISH_MT("ip/ddr3/sim/vendor/ddr3.v", 629, "");
    } else {
        VL_WRITEF_NX("%m: at time %0t INFO: opening %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd;
    }
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[6U] 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file;
    VL_SFORMAT_NX(2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename
                  ,"%0s/%m.7",2, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file"
                  , '#',1024,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir.data());
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(64, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename)
                      , "wb+"s);
    ;
    if (VL_UNLIKELY(((0U == vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd)))) {
        VL_WRITEF_NX("%m: at time %0t ERROR: failed to open %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        VL_FINISH_MT("ip/ddr3/sim/vendor/ddr3.v", 629, "");
    } else {
        VL_WRITEF_NX("%m: at time %0t INFO: opening %0s.\n",4, 'M',vlSymsp->name(),"tb_ddr3_init_top.u_micron.open_bank_file", 'T',-12
                     , '#',64,VL_TIME_UNITED_Q(1), '#',2048,vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename.data());
        vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file 
            = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd;
    }
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[7U] 
        = vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT____VlemCall_4__open_bank_file;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__i = 8U;
    VL_TIMEFORMAT_IINI(true, 0xfffffff4U, true, 1U, true, " ps"s, true, 1U, vlSymsp->_vm_contextp__);
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__seed = 0x00007ca9U;
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr = 0U;
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___eval_final(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_final\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ddr3_init_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_ddr3_init_top___024root___eval_phase__stl(Vtb_ddr3_init_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___eval_settle(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_settle\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_ddr3_init_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("ip/ddr3/sim/tb_ddr3_init_top.sv", 19, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_ddr3_init_top___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___eval_triggers_vec__stl(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_triggers_vec__stl\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_ddr3_init_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ddr3_init_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_ddr3_init_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_ddr3_init_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___stl_sequent__TOP__0(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___stl_sequent__TOP__0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_n_in 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in)
            ? 7U : (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in) 
                     << 2U) | (((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in) 
                                << 1U) | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in))));
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly) 
           & (- (IData)((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_en))));
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en 
        = ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_en) 
           & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly));
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq 
        = (0x000000ffU & ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en)) 
                          | ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly) 
                             & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en))));
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs 
        = (1U & ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en)) 
                 | ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly) 
                    & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en))));
    vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n 
        = ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly)) 
           & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en));
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root____Vm_traceActivitySetAll(Vtb_ddr3_init_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___eval_stl(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_stl\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_ddr3_init_top___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_ddr3_init_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_ddr3_init_top___024root___eval_phase__stl(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___eval_phase__stl\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_ddr3_init_top___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_ddr3_init_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_ddr3_init_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_ddr3_init_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_ddr3_init_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 8> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ddr3_init_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 8> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_ddr3_init_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_ddr3_init_top.clk_phy)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tb_ddr3_init_top.u_micron.ck_in)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge tb_ddr3_init_top.u_micron.ck_n_in)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: @(posedge tb_ddr3_init_top.u_micron.rst_n_in)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 65 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[0])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 66 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[1])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 67 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[2])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 68 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[3])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 69 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[4])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 70 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[5])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 71 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[6])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 72 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[7])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 73 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[8])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 74 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[9])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 75 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[10])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 76 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[11])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 77 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[12])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 78 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[13])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 79 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[14])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 80 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[15])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 81 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[32])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 82 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[33])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 83 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[34])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 84 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[35])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 85 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[36])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 86 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[37])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 87 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[38])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 88 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[39])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 89 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[40])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 90 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[41])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 91 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[42])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 92 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[43])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 93 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[44])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 94 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[45])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 95 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[46])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 96 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[47])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 97 is active: @( tb_ddr3_init_top.u_micron.cke_in)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 98 is active: @( tb_ddr3_init_top.u_micron.odt_in)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 99 is active: @( tb_ddr3_init_top.u_micron.cs_n_in)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 100 is active: @( tb_ddr3_init_top.u_micron.ras_n_in)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 101 is active: @( tb_ddr3_init_top.u_micron.cas_n_in)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 102 is active: @( tb_ddr3_init_top.u_micron.we_n_in)\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 103 is active: @( tb_ddr3_init_top.u_micron.ba_in[0])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 104 is active: @( tb_ddr3_init_top.u_micron.ba_in[1])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 105 is active: @( tb_ddr3_init_top.u_micron.ba_in[2])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 106 is active: @( tb_ddr3_init_top.u_micron.addr_in[0])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 107 is active: @( tb_ddr3_init_top.u_micron.addr_in[1])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 108 is active: @( tb_ddr3_init_top.u_micron.addr_in[2])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 109 is active: @( tb_ddr3_init_top.u_micron.addr_in[3])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000002eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 110 is active: @( tb_ddr3_init_top.u_micron.addr_in[4])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000002fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 111 is active: @( tb_ddr3_init_top.u_micron.addr_in[5])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000030U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 112 is active: @( tb_ddr3_init_top.u_micron.addr_in[6])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000031U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 113 is active: @( tb_ddr3_init_top.u_micron.addr_in[7])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000032U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 114 is active: @( tb_ddr3_init_top.u_micron.addr_in[8])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000033U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 115 is active: @( tb_ddr3_init_top.u_micron.addr_in[9])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000034U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 116 is active: @( tb_ddr3_init_top.u_micron.addr_in[10])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000035U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 117 is active: @( tb_ddr3_init_top.u_micron.addr_in[11])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000036U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 118 is active: @( tb_ddr3_init_top.u_micron.addr_in[12])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000037U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 119 is active: @( tb_ddr3_init_top.u_micron.addr_in[13])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000038U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 120 is active: @( tb_ddr3_init_top.u_micron.addr_in[14])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x00000039U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 121 is active: @( tb_ddr3_init_top.u_micron.addr_in[15])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000003aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 122 is active: @( tb_ddr3_init_top.u_micron.addr_in[16])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000003bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 123 is active: @( tb_ddr3_init_top.u_micron.dm_in[0])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000003cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 124 is active: @( tb_ddr3_init_top.u_micron.dm_in[1])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000003dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 125 is active: @( tb_ddr3_init_top.u_micron.dm_in[2])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000003eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 126 is active: @( tb_ddr3_init_top.u_micron.dm_in[3])\n");
    }
    if ((1U & (IData)((triggers[1U] >> 0x0000003fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 127 is active: @( tb_ddr3_init_top.u_micron.dm_in[4])\n");
    }
    if ((1U & (IData)(triggers[2U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 128 is active: @( tb_ddr3_init_top.u_micron.dm_in[5])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 129 is active: @( tb_ddr3_init_top.u_micron.dm_in[6])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 130 is active: @( tb_ddr3_init_top.u_micron.dm_in[7])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 131 is active: @( tb_ddr3_init_top.u_micron.dm_in[8])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 132 is active: @( tb_ddr3_init_top.u_micron.dm_in[9])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 133 is active: @( tb_ddr3_init_top.u_micron.dm_in[10])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 134 is active: @( tb_ddr3_init_top.u_micron.dm_in[11])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 135 is active: @( tb_ddr3_init_top.u_micron.dm_in[12])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 136 is active: @( tb_ddr3_init_top.u_micron.dm_in[13])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 137 is active: @( tb_ddr3_init_top.u_micron.dm_in[14])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 138 is active: @( tb_ddr3_init_top.u_micron.dm_in[15])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 139 is active: @( tb_ddr3_init_top.u_micron.dm_in[16])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 140 is active: @( tb_ddr3_init_top.u_micron.dm_in[17])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 141 is active: @( tb_ddr3_init_top.u_micron.dm_in[18])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 142 is active: @( tb_ddr3_init_top.u_micron.dm_in[19])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 143 is active: @( tb_ddr3_init_top.u_micron.dm_in[20])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 144 is active: @( tb_ddr3_init_top.u_micron.dm_in[21])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 145 is active: @( tb_ddr3_init_top.u_micron.dm_in[22])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 146 is active: @( tb_ddr3_init_top.u_micron.dm_in[23])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 147 is active: @( tb_ddr3_init_top.u_micron.dm_in[24])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 148 is active: @( tb_ddr3_init_top.u_micron.dm_in[25])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 149 is active: @( tb_ddr3_init_top.u_micron.dm_in[26])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 150 is active: @( tb_ddr3_init_top.u_micron.dm_in[27])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 151 is active: @( tb_ddr3_init_top.u_micron.dm_in[28])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 152 is active: @( tb_ddr3_init_top.u_micron.dm_in[29])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 153 is active: @( tb_ddr3_init_top.u_micron.dm_in[30])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 154 is active: @( tb_ddr3_init_top.u_micron.dm_in[31])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 155 is active: @( tb_ddr3_init_top.u_micron.dq_in[0])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 156 is active: @( tb_ddr3_init_top.u_micron.dq_in[1])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 157 is active: @( tb_ddr3_init_top.u_micron.dq_in[2])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 158 is active: @( tb_ddr3_init_top.u_micron.dq_in[3])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 159 is active: @( tb_ddr3_init_top.u_micron.dq_in[4])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 160 is active: @( tb_ddr3_init_top.u_micron.dq_in[5])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 161 is active: @( tb_ddr3_init_top.u_micron.dq_in[6])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 162 is active: @( tb_ddr3_init_top.u_micron.dq_in[7])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 163 is active: @( tb_ddr3_init_top.u_micron.dq_in[8])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 164 is active: @( tb_ddr3_init_top.u_micron.dq_in[9])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 165 is active: @( tb_ddr3_init_top.u_micron.dq_in[10])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 166 is active: @( tb_ddr3_init_top.u_micron.dq_in[11])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 167 is active: @( tb_ddr3_init_top.u_micron.dq_in[12])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 168 is active: @( tb_ddr3_init_top.u_micron.dq_in[13])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 169 is active: @( tb_ddr3_init_top.u_micron.dq_in[14])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 170 is active: @( tb_ddr3_init_top.u_micron.dq_in[15])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 171 is active: @( tb_ddr3_init_top.u_micron.dq_in[16])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 172 is active: @( tb_ddr3_init_top.u_micron.dq_in[17])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 173 is active: @( tb_ddr3_init_top.u_micron.dq_in[18])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000002eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 174 is active: @( tb_ddr3_init_top.u_micron.dq_in[19])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000002fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 175 is active: @( tb_ddr3_init_top.u_micron.dq_in[20])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000030U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 176 is active: @( tb_ddr3_init_top.u_micron.dq_in[21])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000031U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 177 is active: @( tb_ddr3_init_top.u_micron.dq_in[22])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000032U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 178 is active: @( tb_ddr3_init_top.u_micron.dq_in[23])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000033U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 179 is active: @( tb_ddr3_init_top.u_micron.dq_in[24])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000034U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 180 is active: @( tb_ddr3_init_top.u_micron.dq_in[25])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000035U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 181 is active: @( tb_ddr3_init_top.u_micron.dq_in[26])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000036U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 182 is active: @( tb_ddr3_init_top.u_micron.dq_in[27])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000037U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 183 is active: @( tb_ddr3_init_top.u_micron.dq_in[28])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000038U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 184 is active: @( tb_ddr3_init_top.u_micron.dq_in[29])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x00000039U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 185 is active: @( tb_ddr3_init_top.u_micron.dq_in[30])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000003aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 186 is active: @( tb_ddr3_init_top.u_micron.dq_in[31])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000003bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 187 is active: @( tb_ddr3_init_top.u_micron.dq_in[32])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000003cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 188 is active: @( tb_ddr3_init_top.u_micron.dq_in[33])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000003dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 189 is active: @( tb_ddr3_init_top.u_micron.dq_in[34])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000003eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 190 is active: @( tb_ddr3_init_top.u_micron.dq_in[35])\n");
    }
    if ((1U & (IData)((triggers[2U] >> 0x0000003fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 191 is active: @( tb_ddr3_init_top.u_micron.dq_in[36])\n");
    }
    if ((1U & (IData)(triggers[3U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 192 is active: @( tb_ddr3_init_top.u_micron.dq_in[37])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 193 is active: @( tb_ddr3_init_top.u_micron.dq_in[38])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 194 is active: @( tb_ddr3_init_top.u_micron.dq_in[39])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 195 is active: @( tb_ddr3_init_top.u_micron.dq_in[40])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 196 is active: @( tb_ddr3_init_top.u_micron.dq_in[41])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 197 is active: @( tb_ddr3_init_top.u_micron.dq_in[42])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 198 is active: @( tb_ddr3_init_top.u_micron.dq_in[43])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 199 is active: @( tb_ddr3_init_top.u_micron.dq_in[44])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 200 is active: @( tb_ddr3_init_top.u_micron.dq_in[45])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 201 is active: @( tb_ddr3_init_top.u_micron.dq_in[46])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 202 is active: @( tb_ddr3_init_top.u_micron.dq_in[47])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 203 is active: @( tb_ddr3_init_top.u_micron.dq_in[48])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 204 is active: @( tb_ddr3_init_top.u_micron.dq_in[49])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 205 is active: @( tb_ddr3_init_top.u_micron.dq_in[50])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 206 is active: @( tb_ddr3_init_top.u_micron.dq_in[51])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 207 is active: @( tb_ddr3_init_top.u_micron.dq_in[52])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 208 is active: @( tb_ddr3_init_top.u_micron.dq_in[53])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 209 is active: @( tb_ddr3_init_top.u_micron.dq_in[54])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 210 is active: @( tb_ddr3_init_top.u_micron.dq_in[55])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 211 is active: @( tb_ddr3_init_top.u_micron.dq_in[56])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 212 is active: @( tb_ddr3_init_top.u_micron.dq_in[57])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 213 is active: @( tb_ddr3_init_top.u_micron.dq_in[58])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 214 is active: @( tb_ddr3_init_top.u_micron.dq_in[59])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 215 is active: @( tb_ddr3_init_top.u_micron.dq_in[60])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 216 is active: @( tb_ddr3_init_top.u_micron.dq_in[61])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 217 is active: @( tb_ddr3_init_top.u_micron.dq_in[62])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 218 is active: @( tb_ddr3_init_top.u_micron.dq_in[63])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 219 is active: @( tb_ddr3_init_top.u_micron.dq_in[64])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 220 is active: @( tb_ddr3_init_top.u_micron.dq_in[65])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 221 is active: @( tb_ddr3_init_top.u_micron.dq_in[66])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 222 is active: @( tb_ddr3_init_top.u_micron.dq_in[67])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 223 is active: @( tb_ddr3_init_top.u_micron.dq_in[68])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 224 is active: @( tb_ddr3_init_top.u_micron.dq_in[69])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 225 is active: @( tb_ddr3_init_top.u_micron.dq_in[70])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 226 is active: @( tb_ddr3_init_top.u_micron.dq_in[71])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 227 is active: @( tb_ddr3_init_top.u_micron.dq_in[72])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 228 is active: @( tb_ddr3_init_top.u_micron.dq_in[73])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 229 is active: @( tb_ddr3_init_top.u_micron.dq_in[74])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 230 is active: @( tb_ddr3_init_top.u_micron.dq_in[75])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 231 is active: @( tb_ddr3_init_top.u_micron.dq_in[76])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 232 is active: @( tb_ddr3_init_top.u_micron.dq_in[77])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 233 is active: @( tb_ddr3_init_top.u_micron.dq_in[78])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 234 is active: @( tb_ddr3_init_top.u_micron.dq_in[79])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 235 is active: @( tb_ddr3_init_top.u_micron.dq_in[80])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 236 is active: @( tb_ddr3_init_top.u_micron.dq_in[81])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 237 is active: @( tb_ddr3_init_top.u_micron.dq_in[82])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000002eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 238 is active: @( tb_ddr3_init_top.u_micron.dq_in[83])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000002fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 239 is active: @( tb_ddr3_init_top.u_micron.dq_in[84])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000030U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 240 is active: @( tb_ddr3_init_top.u_micron.dq_in[85])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000031U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 241 is active: @( tb_ddr3_init_top.u_micron.dq_in[86])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000032U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 242 is active: @( tb_ddr3_init_top.u_micron.dq_in[87])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000033U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 243 is active: @( tb_ddr3_init_top.u_micron.dq_in[88])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000034U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 244 is active: @( tb_ddr3_init_top.u_micron.dq_in[89])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000035U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 245 is active: @( tb_ddr3_init_top.u_micron.dq_in[90])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000036U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 246 is active: @( tb_ddr3_init_top.u_micron.dq_in[91])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000037U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 247 is active: @( tb_ddr3_init_top.u_micron.dq_in[92])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000038U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 248 is active: @( tb_ddr3_init_top.u_micron.dq_in[93])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x00000039U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 249 is active: @( tb_ddr3_init_top.u_micron.dq_in[94])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000003aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 250 is active: @( tb_ddr3_init_top.u_micron.dq_in[95])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000003bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 251 is active: @( tb_ddr3_init_top.u_micron.dq_in[96])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000003cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 252 is active: @( tb_ddr3_init_top.u_micron.dq_in[97])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000003dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 253 is active: @( tb_ddr3_init_top.u_micron.dq_in[98])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000003eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 254 is active: @( tb_ddr3_init_top.u_micron.dq_in[99])\n");
    }
    if ((1U & (IData)((triggers[3U] >> 0x0000003fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 255 is active: @( tb_ddr3_init_top.u_micron.dq_in[100])\n");
    }
    if ((1U & (IData)(triggers[4U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 256 is active: @( tb_ddr3_init_top.u_micron.dq_in[101])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 257 is active: @( tb_ddr3_init_top.u_micron.dq_in[102])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 258 is active: @( tb_ddr3_init_top.u_micron.dq_in[103])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 259 is active: @( tb_ddr3_init_top.u_micron.dq_in[104])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 260 is active: @( tb_ddr3_init_top.u_micron.dq_in[105])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 261 is active: @( tb_ddr3_init_top.u_micron.dq_in[106])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 262 is active: @( tb_ddr3_init_top.u_micron.dq_in[107])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 263 is active: @( tb_ddr3_init_top.u_micron.dq_in[108])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 264 is active: @( tb_ddr3_init_top.u_micron.dq_in[109])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 265 is active: @( tb_ddr3_init_top.u_micron.dq_in[110])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 266 is active: @( tb_ddr3_init_top.u_micron.dq_in[111])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 267 is active: @( tb_ddr3_init_top.u_micron.dq_in[112])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 268 is active: @( tb_ddr3_init_top.u_micron.dq_in[113])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 269 is active: @( tb_ddr3_init_top.u_micron.dq_in[114])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 270 is active: @( tb_ddr3_init_top.u_micron.dq_in[115])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 271 is active: @( tb_ddr3_init_top.u_micron.dq_in[116])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 272 is active: @( tb_ddr3_init_top.u_micron.dq_in[117])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 273 is active: @( tb_ddr3_init_top.u_micron.dq_in[118])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 274 is active: @( tb_ddr3_init_top.u_micron.dq_in[119])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 275 is active: @( tb_ddr3_init_top.u_micron.dq_in[120])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 276 is active: @( tb_ddr3_init_top.u_micron.dq_in[121])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 277 is active: @( tb_ddr3_init_top.u_micron.dq_in[122])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 278 is active: @( tb_ddr3_init_top.u_micron.dq_in[123])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 279 is active: @( tb_ddr3_init_top.u_micron.dq_in[124])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 280 is active: @( tb_ddr3_init_top.u_micron.dq_in[125])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 281 is active: @( tb_ddr3_init_top.u_micron.dq_in[126])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 282 is active: @( tb_ddr3_init_top.u_micron.dq_in[127])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 283 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[32])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 284 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[33])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 285 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[34])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 286 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[35])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 287 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[36])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 288 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[37])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 289 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[38])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 290 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[39])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 291 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[40])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 292 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[41])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 293 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[42])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 294 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[43])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 295 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[44])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 296 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[45])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 297 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[46])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 298 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[47])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 299 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[48])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 300 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[49])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 301 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[50])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000002eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 302 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[51])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000002fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 303 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[52])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000030U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 304 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[53])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000031U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 305 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[54])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000032U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 306 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[55])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000033U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 307 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[56])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000034U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 308 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[57])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000035U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 309 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[58])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000036U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 310 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[59])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000037U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 311 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[60])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000038U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 312 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[61])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x00000039U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 313 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[62])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000003aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 314 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[63])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000003bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 315 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[0])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000003cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 316 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[1])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000003dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 317 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[2])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000003eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 318 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[3])\n");
    }
    if ((1U & (IData)((triggers[4U] >> 0x0000003fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 319 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[4])\n");
    }
    if ((1U & (IData)(triggers[5U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 320 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[5])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 321 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[6])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 322 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[7])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 323 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[8])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 324 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[9])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 325 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[10])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 326 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[11])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 327 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[12])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 328 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[13])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 329 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[14])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 330 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[15])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 331 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[16])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 332 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[17])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 333 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[18])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 334 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[19])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 335 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[20])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 336 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[21])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 337 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[22])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 338 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[23])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 339 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[24])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 340 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[25])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 341 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[26])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 342 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[27])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 343 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[28])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 344 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[29])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 345 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[30])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 346 is active: @(negedge tb_ddr3_init_top.u_micron.dqs_in[31])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 347 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[32])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 348 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[33])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 349 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[34])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 350 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[35])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 351 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[36])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 352 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[37])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 353 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[38])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 354 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[39])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 355 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[40])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 356 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[41])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 357 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[42])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 358 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[43])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 359 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[44])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 360 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[45])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 361 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[46])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 362 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[47])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 363 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[48])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 364 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[49])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 365 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[50])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000002eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 366 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[51])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000002fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 367 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[52])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000030U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 368 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[53])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000031U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 369 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[54])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000032U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 370 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[55])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000033U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 371 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[56])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000034U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 372 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[57])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000035U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 373 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[58])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000036U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 374 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[59])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000037U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 375 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[60])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000038U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 376 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[61])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x00000039U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 377 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[62])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000003aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 378 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[63])\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000003bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 379 is active: @( tb_ddr3_init_top.u_dut.o_ddr3_reset_n)\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000003cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 380 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000003dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 381 is active: @( tb_ddr3_init_top.clk_phy)\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000003eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 382 is active: @( tb_ddr3_init_top.u_dut.o_ddr3_cke)\n");
    }
    if ((1U & (IData)((triggers[5U] >> 0x0000003fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 383 is active: @( tb_ddr3_init_top.u_dut.sel_cmd[3])\n");
    }
    if ((1U & (IData)(triggers[6U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 384 is active: @( tb_ddr3_init_top.u_dut.sel_cmd[2])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 385 is active: @( tb_ddr3_init_top.u_dut.sel_cmd[1])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 386 is active: @( tb_ddr3_init_top.u_dut.sel_cmd[0])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 387 is active: @( 1'h0)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 388 is active: @( tb_ddr3_init_top.u_dut.o_ddr3_ba)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 389 is active: @( tb_ddr3_init_top.u_dut.o_ddr3_addr)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 390 is active: @( tb_ddr3_init_top.u_micron.dq)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 391 is active: @( tb_ddr3_init_top.u_micron.dqs)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 392 is active: @( tb_ddr3_init_top.u_micron.dqs_n)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 393 is active: @( tb_ddr3_init_top.u_dut.o_ddr3_odt)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 394 is active: @(edge tb_ddr3_init_top.u_micron.diff_ck)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 395 is active: @(negedge tb_ddr3_init_top.u_micron.rst_n_in)\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 396 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[31])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 397 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[15])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 398 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[23])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 399 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[7])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 400 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[27])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 401 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[11])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 402 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[19])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 403 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[3])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 404 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[29])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 405 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[13])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 406 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[21])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 407 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[5])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 408 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[25])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 409 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[9])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 410 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[17])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 411 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[1])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 412 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[30])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 413 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[14])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 414 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[22])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 415 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[6])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 416 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[26])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 417 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[10])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 418 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[18])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 419 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[2])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 420 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[28])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 421 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[12])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 422 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[20])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 423 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[4])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 424 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[24])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 425 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[8])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 426 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[16])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 427 is active: @(posedge tb_ddr3_init_top.u_micron.dqs_in[0])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 428 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[63])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 429 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[31])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000002eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 430 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[47])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000002fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 431 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[15])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000030U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 432 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[55])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000031U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 433 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[23])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000032U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 434 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[39])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000033U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 435 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[7])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000034U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 436 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[59])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000035U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 437 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[27])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000036U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 438 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[43])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000037U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 439 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[11])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000038U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 440 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[51])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x00000039U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 441 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[19])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000003aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 442 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[35])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000003bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 443 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[3])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000003cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 444 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[61])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000003dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 445 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[29])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000003eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 446 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[45])\n");
    }
    if ((1U & (IData)((triggers[6U] >> 0x0000003fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 447 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[13])\n");
    }
    if ((1U & (IData)(triggers[7U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 448 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[53])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 449 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[21])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 450 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[37])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 451 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[5])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 452 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[57])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 453 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[25])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 454 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[41])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 455 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[9])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 456 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[49])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 457 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[17])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000000aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 458 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[33])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000000bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 459 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[1])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000000cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 460 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[62])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000000dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 461 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[30])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000000eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 462 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[46])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000000fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 463 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[14])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000010U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 464 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[54])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000011U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 465 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[22])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000012U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 466 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[38])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000013U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 467 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[6])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000014U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 468 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[58])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000015U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 469 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[26])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000016U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 470 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[42])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000017U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 471 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[10])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000018U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 472 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[50])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000019U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 473 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[18])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000001aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 474 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[34])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000001bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 475 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[2])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000001cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 476 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[60])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000001dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 477 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[28])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000001eU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 478 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[44])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000001fU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 479 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[12])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000020U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 480 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[52])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000021U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 481 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[20])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000022U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 482 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[36])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000023U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 483 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[4])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000024U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 484 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[56])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000025U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 485 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[24])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000026U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 486 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[40])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000027U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 487 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[8])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000028U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 488 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[48])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x00000029U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 489 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[16])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000002aU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 490 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[32])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000002bU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 491 is active: @(edge tb_ddr3_init_top.u_micron.dqs_in[0])\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000002cU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 492 is active: @(posedge tb_ddr3_init_top.init_done)\n");
    }
    if ((1U & (IData)((triggers[7U] >> 0x0000002dU)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 493 is active: @(posedge tb_ddr3_init_top.init_error)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ddr3_init_top___024root___dump_triggers__act_ext(const VlUnpacked<QData/*63:0*/, 9> &ext, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___dump_triggers__act_ext\n"); );
    // Locals
    VlUnpacked<QData/*63:0*/, 8> vec;
    IData/*31:0*/ i;
    VlUnpacked<QData/*63:0*/, 8> pre;
    IData/*31:0*/ j;
    // Body
    i = 0U;
    do {
        vec[i] = ext[i];
        i = ((IData)(1U) + i);
    } while ((8U > i));
    Vtb_ddr3_init_top___024root___dump_triggers__act(vec, tag);
    j = 0U;
    do {
        pre[j] = ext[j];
        j = ((IData)(1U) + j);
    } while ((1U > j));
    do {
        pre[j] = 0ULL;
        j = ((IData)(1U) + j);
    } while ((8U > j));
    Vtb_ddr3_init_top___024root___dump_triggers__act(pre, 
                                                     VL_CONCATN_NNN(tag, " pre"s));
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_ddr3_init_top___024root____Vm_traceActivitySetAll(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root____Vm_traceActivitySetAll\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
    vlSelfRef.__Vm_traceActivity[9U] = 1U;
}

VL_ATTR_COLD void Vtb_ddr3_init_top___024root___ctor_var_reset(Vtb_ddr3_init_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root___ctor_var_reset\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->done_or_err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8251369408906850860ull);
    vlSelf->tb_ddr3_init_top__DOT__init_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12170722439216330016ull);
    vlSelf->tb_ddr3_init_top__DOT__init_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2540417884331775654ull);
    vlSelf->tb_ddr3_init_top__DOT__init_error_code = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10890743074694133235ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14173993818388562772ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_dat = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8331661466558482200ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14116880660253146872ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6422138976011845159ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5822583198539114013ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5780050457733605561ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 3364648425210570244ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18306592920266912275ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 122823332605837178ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 4859879197171850176ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5591103128983472096ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__init_cke = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5504785904180570262ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__init_odt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9233989498075362719ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16288578219621524643ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13495938786152951913ull);
    vlSelf->tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10598352486608428799ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT____Vlvbound_h1d3af5e8__0 = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT____Vlvbound_h330793c0__0 = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT____Vlvbound_hd2d7c233__0 = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT____Vlvbound_hf9e23c94__0 = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT____Vlvbound_h8ee4f377__0 = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT____Vlvbound_h22c6ecaf__0 = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT____Vlvbound_h58280f13__0 = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT____Vlvbound_hde98c8fb__0 = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4739675095385704775ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10049064991976998411ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15018589870016664816ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg = 0;
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tck_sample[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4107550260916095970ull);
    }
    for (int __Vi0 = 0; __Vi0 < 513; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tch_sample[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14548894171119353854ull);
    }
    for (int __Vi0 = 0; __Vi0 < 513; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tcl_sample[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5760579178821481841ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tck_i = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2578898255922112478ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tch_i = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13086476990903812888ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7092833703462326316ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tch_avg = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tcl_avg = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4715140377394715428ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7668283110975095576ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tjit_per_rtime = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tjit_cc_time = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15004105348390815625ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__terr_nper_rtime = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tjit_ch_rtime = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__duty_cycle = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__out_delay = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15554320345161037081ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqsck[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17928087330212297479ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqsck_min = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2425828674480165478ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqsck_max = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3080369037429094902ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqsq_min = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8748978420332984328ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqsq_max = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3572779722670265205ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__seed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15858811558225923507ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[__Vi0] = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 6795161160398121763ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__burst_order = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3505031993681216309ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__burst_length = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5390697490621391978ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__blotf = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16470402052106056097ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__truebl4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7298586436337280518ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cas_latency = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 450411365348772423ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dll_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15425170396425743953ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9082240025091549150ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__write_recovery = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4667919412710803280ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__low_power = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13157271337483065404ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dll_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3976609057612429441ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odt_rtt_nom = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1462433887180624758ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odt_rtt_wr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13114646941912943078ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odt_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8464209601576670262ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1857324902523438335ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__al = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13384629608330234855ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__additive_latency = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1387722265296615560ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12467387920895632824ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__duty_cycle_corrector = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2497028365806105686ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tdqs_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6312505709111220196ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__out_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16366561307254144369ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__pasr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12799092543992670958ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cas_write_latency = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5389955599633616232ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__asr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 700398003136761296ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__srt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6081982917264624472ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__mpr_select = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5942997830055518833ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__mpr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 277402672521042743ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odts_readout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5923619456493919102ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__read_latency = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16415558519875585962ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__write_latency = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11819276328596696118ull);
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(72, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string[__Vi0], __VscopeHash, 12321982108695482725ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__active_bank = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12219568257162490173ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17251323215294342364ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__write_precharge_bank = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16644695021143286094ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__read_precharge_bank = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7201312322129639752ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__active_row[__Vi0] = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 9649675993722974697ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__in_power_down = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16993366407543266775ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__in_self_refresh = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6552664640404882843ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__init_mode_reg = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18141064800275445235ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__init_dll_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4188186063147894104ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__init_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2615680765471383528ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__init_step = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4376638474690686660ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__zq_set = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2714264371907464732ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__er_trfc_max = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17483533739084363746ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odt_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5308645063699074187ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14619773104392218202ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 554430654505306449ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13404964797690339445ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1308298741484886384ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__mr_chk = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5034693645154464852ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__rd_bc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1098569448331060509ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__banki = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4467148976707526187ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ref_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11842475687878433161ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odt_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4927010529606032925ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8606078505515578088ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6827569143669699697ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3836158168576164668ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13417210369160498762ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10314233460363629086ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15218338173444637314ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_write = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6983905908802366402ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_read = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11782783933240501510ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5250886318334586383ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2415714417238019206ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2593289754984105382ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2315365721088095351ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14783149716784238143ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6357082007956674525ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13100482098733053722ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 918602096555296405ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4759942286554510651ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1924567856933735604ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3525202818456194737ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9857851553496113771ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5759773265764618055ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7893942017074669470ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2466874091531821777ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18158369441048722013ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5141188657566158868ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15715273426283883621ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9429548762492224614ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4400852974873906865ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10246783687066321213ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3667844850559604021ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13844032847012476738ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9442436320864998563ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6728940424289857580ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3621303438265528843ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11581464735885493414ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_ttsinit = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 942079399418099560ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8841475014821298869ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 697577597680095153ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16679927958121520824ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11391977926706447769ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16303211688738071397ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3178501013235731246ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__al_pipeline = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 16916013301014094559ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__wr_pipeline = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 589667586748896943ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__rd_pipeline = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 3781939499613552066ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odt_pipeline = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 2134429813596857706ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_pipeline = VL_SCOPED_RAND_RESET_Q(57, __VscopeHash, 2919008897172750506ull);
    for (int __Vi0 = 0; __Vi0 < 57; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__bl_pipeline[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9477509940377639669ull);
    }
    for (int __Vi0 = 0; __Vi0 < 57; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ba_pipeline[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4382533104497223513ull);
    }
    for (int __Vi0 = 0; __Vi0 < 57; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__row_pipeline[__Vi0] = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 6737285073539838200ull);
    }
    for (int __Vi0 = 0; __Vi0 < 57; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__col_pipeline[__Vi0] = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 9035725845572892293ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__prev_cke = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 98137563291098229ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_tran_index = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 12258180721392778676ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_tran_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11236355212151370703ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_tran_pipeline = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14650487289164829660ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__memory_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8965474043334475380ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__bit_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5231859543831273728ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__burst_position = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 433970343131142958ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__burst_cntr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7356927756594237443ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_temp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16556092522121288981ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2097026021748439682ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14552083040979413974ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 883032448094221599ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11340290741913751717ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16106727408635547393ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw, __VscopeHash, 17200690473269287619ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_rst_n = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15667419690437246316ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8123803537944970146ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_odt = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6050521063432282507ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_tdqss = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11952723088874165248ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5276807791429164268ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1350202245948919767ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_pos[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8754049227522277293ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4705899815066847623ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs_neg[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14114782765883069821ull);
    }
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_dq[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3656718035236189455ull);
    }
    for (int __Vi0 = 0; __Vi0 < 24; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4071727643073486383ull);
    }
    for (int __Vi0 = 0; __Vi0 < 24; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string[__Vi0] = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 7763471773228595638ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string[__Vi0] = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 10717201648592701711ull);
    }
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir, __VscopeHash, 14550117727457518208ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__memfd[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15777150784259207947ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16285211085301046032ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17904302860231799467ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9748403772640004509ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cke_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2573123677427801618ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2622276819677994992ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18191414859134684717ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7190009105468092840ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17139233621016770794ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dm_in = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5964979022370560722ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__ba_in = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3333477196380471196ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__addr_in = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9446348715176310975ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_in, __VscopeHash, 17864393631635445654ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8945445681253732258ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__odt_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17698671864346578304ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dm_in_pos = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1599876737180278136ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dm_in_neg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4543179763034375004ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_pos, __VscopeHash, 10726133726819683955ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_neg, __VscopeHash, 14122872943599029557ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15092854793823362154ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10757593921516849246ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10100228282361518632ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__wdq_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15505026567246102695ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6919234987183954293ull);
    }
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17403137147544534988ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15387440788708508200ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1962393846020827965ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13880160664464092527ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__cmd_n_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2478263179385221511ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8699181281707244559ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18075035947688344637ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5565059013640909848ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4162917610767889127ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 624405270947861448ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10443322981197901631ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4833500109662506061ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4573067075443307633ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__rdqsen_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9038609728415107213ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__rdqs_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5884023957038689620ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__rdqen_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5833179380748362171ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__rdq_cntr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10388734910735689585ull);
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en = 0;
    vlSelf->tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en = 0;
    vlSelf->__Vintraval_h8111a003__0 = 0;
    vlSelf->__Vintraval_h35bc09b0__0 = 0;
    vlSelf->__Vintraval_h03304c89__0 = 0;
    vlSelf->__Vintraval_hbf1c7320__0 = 0;
    vlSelf->__Vintraval_h297516e9__0 = 0;
    vlSelf->__Vintraval_hcb9b84fb__0 = 0;
    vlSelf->__Vintraval_h07b4ee8a__0 = 0;
    vlSelf->__Vintraval_h3e7155a0__0 = 0;
    vlSelf->__Vintraval_hafe4f182__0 = 0;
    vlSelf->__Vintraval_he92dda99__0 = 0;
    vlSelf->__Vintraval_h7e0143a8__0 = 0;
    VL_ZERO_RESET_W(128, vlSelf->__Vintraval_hc888c3fb__0);
    vlSelf->__Vintraval_h4e039bb0__0 = 0;
    vlSelf->__Vintraval_h0cfea8d0__0 = 0;
    vlSelf->__Vintraval_hfce06310__0 = 0;
    vlSelf->__Vintraval_h03aab35a__0 = 0;
    vlSelf->__Vintraval_h4514651e__0 = 0;
    vlSelf->__Vintraval_h50e69344__0 = 0;
    vlSelf->__Vintralsb_hf60466b3__0 = 0;
    vlSelf->__Vintraval_h93ac25d1__0 = 0;
    vlSelf->__Vintralsb_h3f6a9d9d__0 = 0;
    vlSelf->__Vintraval_h10ee5d2c__0 = 0;
    vlSelf->__Vintraidx_he99cb274__0 = 0;
    vlSelf->__Vintraval_h2994922b__0 = 0;
    vlSelf->__Vintraval_he1624136__0 = 0;
    vlSelf->__Vintraval_h25fa3a89__0 = 0;
    vlSelf->__Vintraval_h7656007d__0 = 0;
    vlSelf->__Vintraval_h7656007d__1 = 0;
    vlSelf->__Vintraval_hf79e2544__0 = 0;
    vlSelf->__Vintralsb_h898ccd2b__0 = 0;
    vlSelf->__Vintraval_h4e52a0da__0 = 0;
    vlSelf->__Vintralsb_hb62a94af__0 = 0;
    vlSelf->__Vintraval_h2939e239__0 = 0;
    vlSelf->__Vintralsb_hd29f0a2e__0 = 0;
    vlSelf->__Vintraval_h57d375eb__0 = 0;
    vlSelf->__Vintralsb_hd3dd5b39__0 = 0;
    vlSelf->__Vintraval_h7797d73a__0 = 0;
    vlSelf->__Vintralsb_hfa74061c__0 = 0;
    vlSelf->__Vintraval_h19dc5c35__0 = 0;
    vlSelf->__Vintralsb_h443ffb80__0 = 0;
    vlSelf->__Vintraval_h96249967__0 = 0;
    vlSelf->__Vintralsb_h183f335f__0 = 0;
    vlSelf->__Vintraval_hde4dba67__0 = 0;
    vlSelf->__Vintralsb_h1afc9cf0__0 = 0;
    vlSelf->__Vintraval_ha9cb318d__0 = 0;
    vlSelf->__Vintralsb_hec1db5f3__0 = 0;
    vlSelf->__Vintraval_h36107c4f__0 = 0;
    vlSelf->__Vintralsb_h5257a277__0 = 0;
    vlSelf->__Vintraval_h58209db4__0 = 0;
    vlSelf->__Vintralsb_ha012d2d8__0 = 0;
    vlSelf->__Vintraval_h457f0462__0 = 0;
    vlSelf->__Vintralsb_h9e697c27__0 = 0;
    vlSelf->__Vintraval_he8bff7d6__0 = 0;
    vlSelf->__Vintralsb_hfd59d945__0 = 0;
    vlSelf->__Vintraval_h385045b5__0 = 0;
    vlSelf->__Vintralsb_h41b545e5__0 = 0;
    vlSelf->__Vintraval_h0b8880bb__0 = 0;
    vlSelf->__Vintralsb_h5473a5fd__0 = 0;
    vlSelf->__Vintraval_h6923fe30__0 = 0;
    vlSelf->__Vintralsb_h52491e4a__0 = 0;
    vlSelf->__Vintraval_heb7808f1__0 = 0;
    vlSelf->__Vintralsb_h37f0ec55__0 = 0;
    vlSelf->__Vintraval_ha0a017f6__0 = 0;
    vlSelf->__Vintralsb_h07bc1e95__0 = 0;
    vlSelf->__Vintraval_h20a2a0cb__0 = 0;
    vlSelf->__Vintralsb_h3a232341__0 = 0;
    vlSelf->__Vintraval_hd30f8fdf__0 = 0;
    vlSelf->__Vintralsb_h38a0c37e__0 = 0;
    vlSelf->__Vintraval_h9d3c0bc6__0 = 0;
    vlSelf->__Vintralsb_h6971b953__0 = 0;
    vlSelf->__Vintraval_h204b06a4__0 = 0;
    vlSelf->__Vintralsb_hd53ba997__0 = 0;
    vlSelf->__Vintraval_h45d6394f__0 = 0;
    vlSelf->__Vintralsb_hb3758930__0 = 0;
    vlSelf->__Vintraval_h6970a987__0 = 0;
    vlSelf->__Vintralsb_hb34f45bf__0 = 0;
    vlSelf->__Vintraval_hd8e756b2__0 = 0;
    vlSelf->__Vintralsb_hd38ff959__0 = 0;
    vlSelf->__Vintraval_h64b07d2b__0 = 0;
    vlSelf->__Vintralsb_h6bdf67b9__0 = 0;
    vlSelf->__Vintraval_haf1e0fe0__0 = 0;
    vlSelf->__Vintralsb_h51cb3fb0__0 = 0;
    vlSelf->__Vintraval_h02c6b868__0 = 0;
    vlSelf->__Vintralsb_h5162293f__0 = 0;
    vlSelf->__Vintraval_h91a8c848__0 = 0;
    vlSelf->__Vintralsb_h663050b1__0 = 0;
    vlSelf->__Vintraval_hbdf9bcba__0 = 0;
    vlSelf->__Vintralsb_hd9fbb031__0 = 0;
    vlSelf->__Vintraval_h071a5b72__0 = 0;
    vlSelf->__Vintralsb_h07be1aba__0 = 0;
    vlSelf->__Vintraval_hf0631220__0 = 0;
    vlSelf->__Vintralsb_h0795b415__0 = 0;
    vlSelf->__Vintraval_hc4b9aee3__0 = 0;
    vlSelf->__Vintralsb_h1f1a487b__0 = 0;
    vlSelf->__Vintraval_h769a5563__0 = 0;
    vlSelf->__Vintralsb_h1f59b51f__0 = 0;
    vlSelf->__Vintraval_h055b0f8b__0 = 0;
    vlSelf->__Vintralsb_h81c210fa__0 = 0;
    vlSelf->__Vintraval_h5e5e87cc__0 = 0;
    vlSelf->__Vintralsb_h8199bf55__0 = 0;
    vlSelf->__Vintraval_hea9316a6__0 = 0;
    vlSelf->__Vintralsb_h3f43dce8__0 = 0;
    vlSelf->__Vintraval_h0f2340d7__0 = 0;
    vlSelf->__Vintralsb_h0133673c__0 = 0;
    vlSelf->__Vintraval_h3e4025b3__0 = 0;
    vlSelf->__Vintralsb_hd8949e1a__0 = 0;
    vlSelf->__Vintraval_h4b791da2__0 = 0;
    vlSelf->__Vintralsb_hd9e82fb5__0 = 0;
    vlSelf->__Vintraval_h93713b10__0 = 0;
    vlSelf->__Vintralsb_h2bd60927__0 = 0;
    vlSelf->__Vintraval_h6dcba91d__0 = 0;
    vlSelf->__Vintralsb_h1425f87b__0 = 0;
    vlSelf->__Vintraval_hc7ed9d99__0 = 0;
    vlSelf->__Vintralsb_h7ba5e197__0 = 0;
    vlSelf->__Vintraval_hcd0fa031__0 = 0;
    vlSelf->__Vintralsb_h7aff6ee8__0 = 0;
    vlSelf->__Vintraval_h93be7041__0 = 0;
    vlSelf->__Vintralsb_hdf382097__0 = 0;
    vlSelf->__Vintraval_h22311016__0 = 0;
    vlSelf->__Vintralsb_h6113fccb__0 = 0;
    vlSelf->__Vintraval_hc22c2dd4__0 = 0;
    vlSelf->__Vintralsb_hb8a1ec13__0 = 0;
    vlSelf->__Vintraval_hf079c7cb__0 = 0;
    vlSelf->__Vintralsb_hb9fa8064__0 = 0;
    vlSelf->__Vintraval_hc355eba7__0 = 0;
    vlSelf->__Vintralsb_h49554d97__0 = 0;
    vlSelf->__Vintraval_h374a500c__0 = 0;
    vlSelf->__Vintralsb_hf5a113cb__0 = 0;
    vlSelf->__Vintraval_hd6b59ad0__0 = 0;
    vlSelf->__Vintralsb_hd2080853__0 = 0;
    vlSelf->__Vintraval_h20655c10__0 = 0;
    vlSelf->__Vintralsb_hd08bbea4__0 = 0;
    vlSelf->__Vintraval_h83095b0b__0 = 0;
    vlSelf->__Vintralsb_h3dc5ecf9__0 = 0;
    vlSelf->__Vintraval_h452fe6e4__0 = 0;
    vlSelf->__Vintralsb_h01b13799__0 = 0;
    vlSelf->__Vintraval_h337af308__0 = 0;
    vlSelf->__Vintralsb_hf63a56e8__0 = 0;
    vlSelf->__Vintraval_h6950b66f__0 = 0;
    vlSelf->__Vintralsb_hf911f177__0 = 0;
    vlSelf->__Vintraval_hbd129dd7__0 = 0;
    vlSelf->__Vintralsb_hd18b80a6__0 = 0;
    vlSelf->__Vintraval_hbb0342e1__0 = 0;
    vlSelf->__Vintralsb_h6e2b6006__0 = 0;
    vlSelf->__Vintraval_h878d5ab1__0 = 0;
    vlSelf->__Vintralsb_hdd4c6a38__0 = 0;
    vlSelf->__Vintraval_h4fcaf6a2__0 = 0;
    vlSelf->__Vintralsb_hdde6fb47__0 = 0;
    vlSelf->__Vintraval_hda664231__0 = 0;
    vlSelf->__Vintralsb_h871b98f5__0 = 0;
    vlSelf->__Vintraval_hbbf08367__0 = 0;
    vlSelf->__Vintralsb_hb7598b75__0 = 0;
    vlSelf->__Vintraval_h66e87d51__0 = 0;
    vlSelf->__Vintralsb_h2d5dda89__0 = 0;
    vlSelf->__Vintraval_hbbc4eef8__0 = 0;
    vlSelf->__Vintralsb_h2db76de6__0 = 0;
    vlSelf->__Vintraval_h0480713d__0 = 0;
    vlSelf->__Vintralsb_hbeec5d98__0 = 0;
    vlSelf->__Vintraval_h193eaa19__0 = 0;
    vlSelf->__Vintralsb_h7f87e3cc__0 = 0;
    vlSelf->__Vintraval_h1757169e__0 = 0;
    vlSelf->__Vintralsb_h0064ab16__0 = 0;
    vlSelf->__Vintraval_hfc5746c8__0 = 0;
    vlSelf->__Vintralsb_h02b86561__0 = 0;
    vlSelf->__Vintraval_h74aed05d__0 = 0;
    vlSelf->__Vintralsb_hbab09f5e__0 = 0;
    vlSelf->__Vintraval_h02aa34fa__0 = 0;
    vlSelf->__Vintralsb_h7c7e79be__0 = 0;
    vlSelf->__Vintraval_h3cc722d4__0 = 0;
    vlSelf->__Vintralsb_h3b2a0eba__0 = 0;
    vlSelf->__Vintraval_h0e930142__0 = 0;
    vlSelf->__Vintralsb_h3bc1d815__0 = 0;
    vlSelf->__Vintraval_ha4747d00__0 = 0;
    vlSelf->__Vintralsb_h85982476__0 = 0;
    vlSelf->__Vintraval_h181c6548__0 = 0;
    vlSelf->__Vintralsb_hb9f408f6__0 = 0;
    vlSelf->__Vintraval_haa3f9c24__0 = 0;
    vlSelf->__Vintralsb_h515eb22c__0 = 0;
    vlSelf->__Vintraval_h882fc7a8__0 = 0;
    vlSelf->__Vintralsb_h51b6333b__0 = 0;
    vlSelf->__Vintraval_h0b35f5cc__0 = 0;
    vlSelf->__Vintralsb_h0409f9db__0 = 0;
    vlSelf->__Vintraval_h5386a100__0 = 0;
    vlSelf->__Vintralsb_h3aa9ee3f__0 = 0;
    vlSelf->__Vintraval_h52454d0c__0 = 0;
    vlSelf->__Vintralsb_h911d40a2__0 = 0;
    vlSelf->__Vintraval_h8c1e4aa9__0 = 0;
    vlSelf->__Vintralsb_h91700f1d__0 = 0;
    vlSelf->__Vintraval_hff67720e__0 = 0;
    vlSelf->__Vintralsb_h18cafec3__0 = 0;
    vlSelf->__Vintraval_he9bc7815__0 = 0;
    vlSelf->__Vintralsb_h2722dd67__0 = 0;
    vlSelf->__Vintraval_hc6312479__0 = 0;
    vlSelf->__Vintralsb_h39fd98b4__0 = 0;
    vlSelf->__Vintraval_h2d90cbe1__0 = 0;
    vlSelf->__Vintralsb_h38d736c3__0 = 0;
    vlSelf->__Vintraval_h94c68543__0 = 0;
    vlSelf->__Vintralsb_h13ceac2a__0 = 0;
    vlSelf->__Vintraval_hc3da75d4__0 = 0;
    vlSelf->__Vintralsb_h2b6e75aa__0 = 0;
    vlSelf->__Vintraval_h805cc775__0 = 0;
    vlSelf->__Vintralsb_h73cca329__0 = 0;
    vlSelf->__Vintraval_h101cc0a5__0 = 0;
    vlSelf->__Vintralsb_h73602a46__0 = 0;
    vlSelf->__Vintraval_h88e7de81__0 = 0;
    vlSelf->__Vintralsb_h4c98aa9b__0 = 0;
    vlSelf->__Vintraval_h2df1b79b__0 = 0;
    vlSelf->__Vintralsb_hf2f45dff__0 = 0;
    vlSelf->__Vintraval_h11f6ea36__0 = 0;
    vlSelf->__Vintralsb_h47fd33d2__0 = 0;
    vlSelf->__Vintraval_h4f7d3f78__0 = 0;
    vlSelf->__Vintralsb_h46d6b30d__0 = 0;
    vlSelf->__Vintraval_h353c7182__0 = 0;
    vlSelf->__Vintralsb_hd5421c26__0 = 0;
    vlSelf->__Vintraval_hb38c122a__0 = 0;
    vlSelf->__Vintralsb_h6b322586__0 = 0;
    vlSelf->__Vintraval_h134b9f35__0 = 0;
    vlSelf->__Vintralsb_h0c7c3798__0 = 0;
    vlSelf->__Vintraval_h52694d95__0 = 0;
    vlSelf->__Vintralsb_h0a4f90e7__0 = 0;
    vlSelf->__Vintraval_hd7c7003f__0 = 0;
    vlSelf->__Vintralsb_h1f19a9ae__0 = 0;
    vlSelf->__Vintraval_he6fcdcbe__0 = 0;
    vlSelf->__Vintralsb_h1f739b2e__0 = 0;
    vlSelf->__Vintraval_h845623c0__0 = 0;
    vlSelf->__Vintralsb_h7adac6ce__0 = 0;
    vlSelf->__Vintraval_h0fa7c6c4__0 = 0;
    vlSelf->__Vintralsb_h7c318019__0 = 0;
    vlSelf->__Vintraval_h32469f38__0 = 0;
    vlSelf->__Vintralsb_h95836f61__0 = 0;
    vlSelf->__Vintraval_h7d54a835__0 = 0;
    vlSelf->__Vintralsb_ha96ec9c1__0 = 0;
    vlSelf->__Vintraval_hb4d2c81f__0 = 0;
    vlSelf->__Vintralsb_hbf10667e__0 = 0;
    vlSelf->__Vintraval_h6492024d__0 = 0;
    vlSelf->__Vintralsb_hbf73d9c9__0 = 0;
    vlSelf->__Vintraval_h4ac4b6b8__0 = 0;
    vlSelf->__Vintralsb_he236b3bc__0 = 0;
    vlSelf->__Vintraval_h280572d5__0 = 0;
    vlSelf->__Vintralsb_h5e008c60__0 = 0;
    vlSelf->__Vintraval_h3d4c9108__0 = 0;
    vlSelf->__Vintralsb_h76573bd7__0 = 0;
    vlSelf->__Vintraval_h3acf6d62__0 = 0;
    vlSelf->__Vintralsb_h78a8eb28__0 = 0;
    vlSelf->__Vintraval_h08bfa0e6__0 = 0;
    vlSelf->__Vintralsb_h2a2bef98__0 = 0;
    vlSelf->__Vintraval_hd18559df__0 = 0;
    vlSelf->__Vintralsb_h15cb49cc__0 = 0;
    vlSelf->__Vintraval_h009f954c__0 = 0;
    vlSelf->__Vintralsb_h73af7c96__0 = 0;
    vlSelf->__Vintraval_h999fc1ab__0 = 0;
    vlSelf->__Vintralsb_h739553e1__0 = 0;
    vlSelf->__Vintraval_haffe0990__0 = 0;
    vlSelf->__Vintralsb_h3226cd1d__0 = 0;
    vlSelf->__Vintraval_h9682e4be__0 = 0;
    vlSelf->__Vintralsb_h0c90947d__0 = 0;
    vlSelf->__Vintraval_he418a6f3__0 = 0;
    vlSelf->__Vintralsb_ha2153bf7__0 = 0;
    vlSelf->__Vintraval_h050cb7ce__0 = 0;
    vlSelf->__Vintralsb_ha072eb08__0 = 0;
    vlSelf->__Vintraval_h23e0aa04__0 = 0;
    vlSelf->__Vintralsb_h92b8be3e__0 = 0;
    vlSelf->__Vintraval_h932ab1ed__0 = 0;
    vlSelf->__Vintralsb_ha4941cde__0 = 0;
    vlSelf->__Vintraval_h9d6256b3__0 = 0;
    vlSelf->__Vintralsb_h7a9ea702__0 = 0;
    vlSelf->__Vintraval_h22503c73__0 = 0;
    vlSelf->__Vintralsb_h7bf6213d__0 = 0;
    vlSelf->__Vintraval_hfe87c3b8__0 = 0;
    vlSelf->__Vintralsb_hdfb7b2a7__0 = 0;
    vlSelf->__Vintraval_h452595be__0 = 0;
    vlSelf->__Vintralsb_h5f9595fb__0 = 0;
    vlSelf->__Vintraval_h6f304140__0 = 0;
    vlSelf->__Vintralsb_h99302c77__0 = 0;
    vlSelf->__Vintraval_h9c85fb1b__0 = 0;
    vlSelf->__Vintralsb_h9a13e488__0 = 0;
    vlSelf->__Vintraval_h22121fd6__0 = 0;
    vlSelf->__Vintralsb_hc737357e__0 = 0;
    vlSelf->__Vintraval_h40529125__0 = 0;
    vlSelf->__Vintralsb_h78ff0c1e__0 = 0;
    vlSelf->__Vintraval_h065dd8af__0 = 0;
    vlSelf->__Vintralsb_hf8b0ab92__0 = 0;
    vlSelf->__Vintraval_h5c4a18f2__0 = 0;
    vlSelf->__Vintralsb_hf69464cd__0 = 0;
    vlSelf->__Vintraval_ha8b12c7d__0 = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_dat = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cke = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_ba = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_addr = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__init_done = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__init_error = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__init_error_code = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_dut__DOT__init_odt = 0;
    vlSelf->__Vdly__tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__cke_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cke_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dm_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dm_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ba_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ba_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__addr_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__addr_in__v0 = 0;
    VL_ZERO_RESET_W(128, vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_in__v0);
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__odt_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__active_bank__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_write__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_write__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_read__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_read__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tch_i__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tch_i__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v66 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v67 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v68 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v69 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v70 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v71 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v72 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v73 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v74 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v75 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v76 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v77 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v78 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v79 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v80 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v81 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v82 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v83 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v84 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v85 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v86 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v87 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v88 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v89 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v90 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v91 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v92 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v93 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v94 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v95 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v96 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v97 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v98 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v99 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v100 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v101 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v102 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v103 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v104 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v105 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v106 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v107 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v108 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v109 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v110 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v111 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v112 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v113 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v114 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v115 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v116 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v117 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v118 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v119 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v120 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v121 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v122 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v123 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v124 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v125 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v126 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v0 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v1 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v2 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v3 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v4 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v5 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v6 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v7 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v8 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v9 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v10 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v11 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v12 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v13 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v14 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v15 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v16 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v17 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v18 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v19 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v20 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v21 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v22 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v23 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v24 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v25 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v26 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v27 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v28 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v29 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v30 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v31 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v0 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v2 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v3 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v4 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v5 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v6 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v7 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v8 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v9 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v10 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v11 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v12 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v13 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v14 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v15 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v16 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v17 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v18 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v19 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v20 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v21 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v22 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v23 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v24 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v25 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v26 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v27 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v28 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v29 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v30 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v31 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v33 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v35 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v37 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v39 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v41 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v43 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v45 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v47 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v49 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v51 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v53 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v55 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v57 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v59 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v61 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v63 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v65 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v66 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v66 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v67 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v67 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v68 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v68 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v69 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v69 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v70 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v70 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v71 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v71 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v72 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v72 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v73 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v73 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v74 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v74 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v75 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v75 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v76 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v76 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v77 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v77 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v78 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v78 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v79 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v79 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v80 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v80 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v81 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v81 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v82 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v82 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v83 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v83 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v84 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v84 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v85 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v85 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v86 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v86 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v87 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v87 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v88 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v88 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v89 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v89 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v90 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v90 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v91 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v91 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v92 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v92 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v93 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v93 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v94 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v94 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v95 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v95 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v96 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v96 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v97 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v97 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v98 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v98 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v99 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v99 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v100 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v100 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v101 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v101 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v102 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v102 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v103 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v103 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v104 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v104 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v105 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v105 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v106 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v106 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v107 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v107 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v108 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v108 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v109 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v109 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v110 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v110 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v111 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v111 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v112 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v112 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v113 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v113 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v114 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v114 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v115 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v115 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v116 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v116 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v117 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v117 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v118 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v118 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v119 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v119 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v120 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v120 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v121 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v121 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v122 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v122 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v123 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v123 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v124 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v124 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v125 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v125 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v126 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v126 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v127 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v127 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v1 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v1 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v2 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v2 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v2 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v128 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v128 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v129 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v129 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v130 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v130 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v131 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v131 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v132 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v132 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v133 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v133 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v134 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v134 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v135 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v135 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v127 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v2 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v2 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v0 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v0 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v0 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v0 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v3 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v3 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v4 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v4 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v4 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v136 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v136 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v137 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v137 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v138 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v138 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v139 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v139 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v140 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v140 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v141 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v141 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v142 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v142 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v143 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v143 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v128 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v33 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v3 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v3 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v1 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v1 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v1 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v1 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v1 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v5 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v5 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v6 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v6 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v6 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v144 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v144 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v145 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v145 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v146 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v146 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v147 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v147 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v148 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v148 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v149 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v149 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v150 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v150 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v151 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v151 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v129 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v4 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v4 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v2 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v2 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v2 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v7 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v7 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v8 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v8 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v8 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v8 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v152 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v152 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v153 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v153 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v154 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v154 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v155 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v155 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v156 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v156 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v157 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v157 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v158 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v158 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v159 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v159 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v130 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v35 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v5 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v5 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v3 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v3 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v3 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v9 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v9 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v9 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v9 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v10 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v10 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v10 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v10 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v160 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v160 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v161 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v161 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v162 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v162 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v163 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v163 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v164 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v164 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v165 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v165 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v166 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v166 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v167 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v167 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v131 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v6 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v6 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v4 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v4 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v4 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v11 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v11 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v11 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v11 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v12 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v12 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v12 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v12 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v168 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v168 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v169 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v169 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v170 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v170 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v171 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v171 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v172 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v172 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v173 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v173 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v174 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v174 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v175 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v175 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v132 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v37 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v7 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v7 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v5 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v5 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v5 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v13 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v13 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v13 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v13 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v14 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v14 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v14 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v14 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v176 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v176 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v177 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v177 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v178 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v178 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v179 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v179 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v180 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v180 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v181 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v181 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v182 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v182 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v183 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v183 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v133 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v8 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v8 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v8 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v6 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v6 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v6 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v15 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v15 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v15 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v15 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v16 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v16 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v16 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v16 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v184 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v184 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v185 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v185 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v186 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v186 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v187 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v187 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v188 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v188 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v189 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v189 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v190 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v190 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v191 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v191 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v134 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v39 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v9 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v9 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v9 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v7 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v7 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v7 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v17 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v17 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v17 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v17 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v18 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v18 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v18 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v18 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v192 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v192 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v193 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v193 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v194 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v194 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v195 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v195 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v196 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v196 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v197 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v197 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v198 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v198 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v199 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v199 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v135 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v10 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v10 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v10 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v8 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v8 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v8 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v8 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v8 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v8 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v19 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v19 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v19 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v19 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v20 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v20 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v20 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v20 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v200 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v200 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v201 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v201 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v202 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v202 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v203 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v203 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v204 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v204 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v205 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v205 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v206 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v206 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v207 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v207 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v136 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v41 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v11 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v11 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v11 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v9 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v9 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v9 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v9 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v9 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v9 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v21 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v21 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v21 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v21 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v22 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v22 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v22 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v22 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v208 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v208 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v209 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v209 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v210 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v210 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v211 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v211 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v212 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v212 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v213 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v213 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v214 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v214 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v215 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v215 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v137 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v12 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v12 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v12 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v10 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v10 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v10 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v10 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v10 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v10 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v23 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v23 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v23 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v23 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v24 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v24 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v24 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v24 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v216 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v216 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v217 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v217 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v218 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v218 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v219 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v219 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v220 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v220 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v221 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v221 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v222 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v222 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v223 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v223 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v138 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v43 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v13 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v13 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v13 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v11 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v11 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v11 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v11 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v11 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v11 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v25 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v25 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v25 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v25 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v26 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v26 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v26 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v26 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v224 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v224 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v225 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v225 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v226 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v226 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v227 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v227 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v228 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v228 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v229 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v229 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v230 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v230 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v231 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v231 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v139 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v14 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v14 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v14 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v12 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v12 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v12 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v12 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v12 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v12 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v27 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v27 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v27 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v27 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v28 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v28 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v28 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v28 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v232 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v232 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v233 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v233 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v234 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v234 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v235 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v235 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v236 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v236 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v237 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v237 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v238 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v238 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v239 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v239 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v140 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v45 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v15 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v15 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v15 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v13 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v13 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v13 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v13 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v13 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v13 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v29 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v29 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v29 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v29 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v30 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v30 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v30 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v30 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v240 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v240 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v241 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v241 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v242 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v242 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v243 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v243 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v244 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v244 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v245 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v245 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v246 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v246 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v247 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v247 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v141 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v16 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v16 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v16 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v14 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v14 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v14 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v14 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v14 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v14 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v31 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v31 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v31 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v31 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v32 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v248 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v248 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v249 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v249 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v250 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v250 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v251 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v251 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v252 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v252 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v253 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v253 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v254 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v254 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v255 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v255 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v142 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v47 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v17 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v17 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v17 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v15 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v15 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v15 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v15 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v15 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v15 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v33 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v33 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v33 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v33 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v34 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v256 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v256 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v257 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v257 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v258 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v258 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v259 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v259 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v260 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v260 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v261 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v261 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v262 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v262 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v263 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v263 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v143 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v18 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v18 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v18 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v16 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v16 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v16 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v16 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v16 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v16 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v35 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v35 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v35 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v35 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v36 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v264 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v264 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v265 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v265 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v266 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v266 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v267 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v267 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v268 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v268 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v269 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v269 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v270 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v270 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v271 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v271 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v144 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v49 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v19 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v19 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v19 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v17 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v17 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v17 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v17 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v17 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v17 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v37 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v37 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v37 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v37 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v38 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v272 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v272 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v273 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v273 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v274 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v274 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v275 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v275 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v276 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v276 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v277 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v277 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v278 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v278 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v279 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v279 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v145 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v20 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v20 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v20 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v18 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v18 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v18 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v18 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v18 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v18 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v39 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v39 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v39 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v39 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v40 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v280 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v280 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v281 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v281 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v282 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v282 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v283 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v283 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v284 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v284 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v285 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v285 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v286 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v286 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v287 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v287 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v146 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v51 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v21 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v21 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v21 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v19 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v19 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v19 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v19 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v19 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v19 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v41 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v41 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v41 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v41 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v42 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v288 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v288 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v289 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v289 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v290 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v290 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v291 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v291 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v292 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v292 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v293 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v293 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v294 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v294 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v295 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v295 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v147 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v147 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v147 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v22 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v22 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v22 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v20 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v20 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v20 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v20 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v20 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v20 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v43 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v43 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v43 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v43 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v44 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v296 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v296 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v297 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v297 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v298 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v298 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v299 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v299 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v300 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v300 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v301 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v301 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v302 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v302 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v303 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v303 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v148 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v148 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v148 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v53 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v23 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v23 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v23 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v21 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v21 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v21 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v21 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v21 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v21 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v45 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v45 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v45 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v45 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v46 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v304 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v304 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v305 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v305 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v306 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v306 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v307 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v307 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v308 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v308 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v309 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v309 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v310 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v310 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v311 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v311 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v149 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v149 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v149 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v24 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v24 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v24 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v22 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v22 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v22 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v22 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v22 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v22 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v47 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v47 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v47 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v47 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v48 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v312 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v312 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v313 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v313 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v314 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v314 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v315 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v315 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v316 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v316 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v317 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v317 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v318 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v318 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v319 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v319 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v150 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v150 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v150 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v55 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v25 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v25 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v25 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v23 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v23 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v23 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v23 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v23 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v23 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v49 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v49 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v49 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v49 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v50 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v320 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v320 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v321 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v321 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v322 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v322 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v323 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v323 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v324 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v324 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v325 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v325 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v326 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v326 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v327 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v327 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v151 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v151 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v151 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v26 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v26 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v26 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v24 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v24 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v24 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v24 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v24 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v24 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v51 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v51 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v51 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v51 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v52 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v328 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v328 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v329 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v329 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v330 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v330 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v331 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v331 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v332 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v332 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v333 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v333 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v334 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v334 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v335 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v335 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v152 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v152 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v152 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v57 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v27 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v27 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v27 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v25 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v25 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v25 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v25 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v25 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v25 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v53 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v53 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v53 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v53 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v54 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v336 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v336 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v337 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v337 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v338 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v338 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v339 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v339 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v340 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v340 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v341 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v341 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v342 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v342 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v343 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v343 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v153 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v153 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v153 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v28 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v28 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v28 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v26 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v26 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v26 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v26 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v26 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v26 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v55 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v55 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v55 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v55 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v56 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v344 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v344 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v345 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v345 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v346 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v346 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v347 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v347 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v348 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v348 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v349 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v349 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v350 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v350 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v351 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v351 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v154 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v154 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v154 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v59 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v29 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v29 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v29 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v27 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v27 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v27 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v27 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v27 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v27 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v57 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v57 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v57 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v57 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v58 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v352 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v352 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v353 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v353 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v354 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v354 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v355 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v355 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v356 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v356 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v357 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v357 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v358 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v358 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v359 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v359 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v155 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v155 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v155 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v30 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v30 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v30 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v28 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v28 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v28 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v28 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v28 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v28 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v59 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v59 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v59 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v59 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v60 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v360 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v360 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v361 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v361 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v362 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v362 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v363 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v363 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v364 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v364 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v365 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v365 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v366 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v366 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v367 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v367 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v156 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v156 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v156 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v61 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v31 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v31 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v31 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v29 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v29 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v29 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v29 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v29 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v29 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v61 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v61 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v61 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v61 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v62 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v368 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v368 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v369 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v369 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v370 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v370 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v371 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v371 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v372 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v372 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v373 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v373 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v374 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v374 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v375 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v375 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v157 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v157 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v157 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v32 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v30 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v30 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v30 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v30 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v30 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v30 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v63 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v63 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v63 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v63 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly__v64 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v376 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v376 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v377 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v377 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v378 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v378 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v379 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v379 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v380 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v380 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v381 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v381 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v382 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v382 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v383 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v383 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v158 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v158 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v158 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v63 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v33 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v33 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v33 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v31 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v31 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v31 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v31 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v31 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v31 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v384 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v384 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v385 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v385 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v386 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v386 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v387 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v387 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v388 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v388 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v389 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v389 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v390 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v390 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v391 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v391 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v159 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v34 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v32 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v32 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v32 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v32 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v32 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v392 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v392 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v393 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v393 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v394 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v394 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v395 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v395 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v396 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v396 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v397 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v397 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v398 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v398 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v399 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v399 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v160 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v65 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v35 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v35 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v35 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v33 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v33 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v33 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v33 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v33 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v33 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v400 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v400 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v401 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v401 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v402 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v402 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v403 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v403 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v404 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v404 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v405 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v405 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v406 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v406 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v407 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v407 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v161 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v66 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v66 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v36 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v34 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v34 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v34 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v34 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v34 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v408 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v408 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v409 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v409 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v410 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v410 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v411 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v411 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v412 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v412 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v413 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v413 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v414 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v414 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v415 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v415 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v162 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v67 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v67 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v37 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v37 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v37 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v35 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v35 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v35 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v35 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v35 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v35 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v416 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v416 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v417 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v417 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v418 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v418 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v419 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v419 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v420 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v420 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v421 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v421 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v422 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v422 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v423 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v423 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v163 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v68 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v68 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v38 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v36 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v36 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v36 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v36 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v36 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v424 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v424 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v425 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v425 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v426 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v426 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v427 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v427 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v428 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v428 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v429 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v429 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v430 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v430 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v431 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v431 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v164 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v69 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v69 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v39 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v39 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v39 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v37 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v37 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v37 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v37 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v37 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v37 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v432 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v432 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v433 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v433 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v434 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v434 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v435 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v435 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v436 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v436 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v437 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v437 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v438 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v438 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v439 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v439 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v165 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v70 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v70 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v40 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v38 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v38 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v38 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v38 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v38 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v440 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v440 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v441 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v441 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v442 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v442 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v443 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v443 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v444 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v444 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v445 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v445 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v446 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v446 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v447 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v447 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v166 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v71 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v71 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v41 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v41 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v41 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v39 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v39 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v39 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v39 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v39 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v39 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v448 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v448 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v449 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v449 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v450 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v450 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v451 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v451 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v452 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v452 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v453 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v453 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v454 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v454 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v455 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v455 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v167 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v72 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v72 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v42 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v40 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v40 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v40 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v40 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v40 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v456 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v456 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v457 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v457 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v458 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v458 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v459 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v459 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v460 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v460 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v461 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v461 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v462 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v462 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v463 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v463 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v168 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v73 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v73 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v43 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v43 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v43 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v41 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v41 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v41 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v41 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v41 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v41 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v464 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v464 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v465 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v465 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v466 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v466 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v467 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v467 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v468 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v468 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v469 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v469 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v470 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v470 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v471 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v471 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v169 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v74 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v74 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v44 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v42 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v42 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v42 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v42 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v42 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v472 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v472 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v473 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v473 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v474 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v474 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v475 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v475 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v476 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v476 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v477 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v477 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v478 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v478 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v479 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v479 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v170 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v75 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v75 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v45 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v45 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v45 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v43 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v43 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v43 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v43 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v43 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v43 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v480 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v480 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v481 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v481 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v482 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v482 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v483 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v483 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v484 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v484 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v485 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v485 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v486 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v486 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v487 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v487 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v171 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v76 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v76 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v46 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v44 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v44 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v44 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v44 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v44 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v488 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v488 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v489 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v489 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v490 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v490 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v491 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v491 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v492 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v492 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v493 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v493 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v494 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v494 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v495 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v495 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v172 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v77 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v77 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v47 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v47 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v47 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v45 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v45 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v45 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v45 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v45 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v45 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v496 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v496 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v497 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v497 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v498 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v498 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v499 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v499 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v500 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v500 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v501 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v501 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v502 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v502 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v503 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v503 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v173 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v78 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v78 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v48 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v46 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v46 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v46 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v46 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v46 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v504 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v504 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v505 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v505 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v506 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v506 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v507 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v507 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v508 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v508 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v509 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v509 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v510 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v510 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v511 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v511 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v174 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v79 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v79 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v49 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v49 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v49 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v47 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v47 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v47 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v47 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v47 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v47 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v512 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v512 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v513 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v513 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v514 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v514 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v515 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v515 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v516 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v516 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v517 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v517 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v518 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v518 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v519 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v519 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v175 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v80 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v80 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v50 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v48 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v48 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v48 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v48 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v48 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v520 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v520 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v521 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v521 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v522 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v522 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v523 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v523 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v524 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v524 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v525 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v525 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v526 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v526 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v527 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v527 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v176 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v81 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v81 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v51 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v51 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v51 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v49 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v49 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v49 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v49 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v49 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v49 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v528 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v528 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v529 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v529 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v530 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v530 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v531 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v531 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v532 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v532 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v533 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v533 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v534 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v534 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v535 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v535 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v177 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v82 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v82 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v52 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v50 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v50 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v50 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v50 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v50 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v536 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v536 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v537 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v537 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v538 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v538 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v539 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v539 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v540 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v540 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v541 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v541 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v542 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v542 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v543 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v543 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v178 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v83 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v83 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v53 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v53 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v53 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v51 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v51 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v51 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v51 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v51 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v51 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v544 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v544 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v545 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v545 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v546 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v546 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v547 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v547 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v548 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v548 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v549 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v549 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v550 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v550 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v551 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v551 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v179 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v84 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v84 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v54 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v52 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v52 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v52 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v52 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v52 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v552 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v552 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v553 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v553 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v554 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v554 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v555 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v555 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v556 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v556 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v557 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v557 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v558 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v558 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v559 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v559 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v180 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v85 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v85 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v55 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v55 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v55 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v53 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v53 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v53 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v53 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v53 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v53 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v560 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v560 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v561 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v561 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v562 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v562 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v563 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v563 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v564 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v564 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v565 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v565 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v566 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v566 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v567 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v567 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v181 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v86 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v86 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v56 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v54 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v54 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v54 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v54 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v54 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v568 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v568 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v569 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v569 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v570 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v570 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v571 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v571 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v572 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v572 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v573 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v573 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v574 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v574 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v575 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v575 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v182 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v87 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v87 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v57 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v57 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v57 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v55 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v55 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v55 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v55 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v55 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v55 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v576 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v576 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v577 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v577 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v578 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v578 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v579 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v579 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v580 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v580 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v581 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v581 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v582 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v582 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v583 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v583 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v183 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v88 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v88 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v58 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v56 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v56 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v56 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v56 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v56 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v584 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v584 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v585 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v585 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v586 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v586 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v587 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v587 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v588 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v588 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v589 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v589 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v590 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v590 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v591 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v591 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v184 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v89 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v89 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v59 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v59 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v59 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v57 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v57 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v57 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v57 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v57 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v57 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v592 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v592 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v593 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v593 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v594 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v594 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v595 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v595 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v596 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v596 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v597 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v597 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v598 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v598 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v599 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v599 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v185 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v90 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v90 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v60 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v58 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v58 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v58 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v58 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v58 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v600 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v600 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v601 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v601 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v602 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v602 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v603 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v603 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v604 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v604 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v605 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v605 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v606 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v606 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v607 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v607 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v186 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v91 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v91 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v61 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v61 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v61 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v59 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v59 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v59 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v59 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v59 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v59 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v608 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v608 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v609 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v609 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v610 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v610 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v611 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v611 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v612 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v612 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v613 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v613 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v614 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v614 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v615 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v615 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v187 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v92 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v92 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v62 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v60 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v60 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v60 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v60 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v60 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v616 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v616 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v617 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v617 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v618 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v618 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v619 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v619 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v620 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v620 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v621 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v621 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v622 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v622 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v623 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v623 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v188 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v93 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v93 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v63 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v63 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v63 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v61 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v61 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v61 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v61 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v61 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v61 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v624 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v624 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v625 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v625 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v626 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v626 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v627 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v627 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v628 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v628 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v629 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v629 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v630 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v630 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v631 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v631 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v189 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v94 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v94 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v64 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v62 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v62 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v62 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v62 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v62 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v632 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v632 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v633 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v633 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v634 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v634 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v635 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v635 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v636 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v636 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v637 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v637 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v638 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v638 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v639 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v639 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_pos_cntr__v190 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v95 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v95 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble__v65 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble__v65 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low__v65 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v63 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v63 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v63 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqss_pos__v63 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v63 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v63 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v640 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v640 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v641 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v641 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v642 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v642 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v643 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v643 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v644 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v644 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v645 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v645 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v646 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v646 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v647 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v647 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v96 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v96 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v64 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v2 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v2 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v64 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v648 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v648 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v649 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v649 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v650 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v650 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v651 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v651 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v652 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v652 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v653 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v653 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v654 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v654 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v655 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v655 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v97 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v97 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v65 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v65 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v3 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v3 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v65 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v65 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v656 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v656 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v657 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v657 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v658 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v658 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v659 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v659 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v660 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v660 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v661 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v661 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v662 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v662 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v663 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v663 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v98 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v98 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v66 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v66 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v66 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v4 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v4 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v66 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v66 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v66 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v664 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v664 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v665 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v665 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v666 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v666 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v667 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v667 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v668 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v668 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v669 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v669 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v670 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v670 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v671 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v671 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v99 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v99 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v67 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v67 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v67 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v5 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v5 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v67 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v67 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v67 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v672 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v672 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v673 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v673 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v674 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v674 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v675 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v675 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v676 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v676 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v677 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v677 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v678 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v678 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v679 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v679 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v100 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v100 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v68 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v68 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v68 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v6 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v6 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v68 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v68 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v68 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v680 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v680 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v681 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v681 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v682 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v682 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v683 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v683 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v684 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v684 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v685 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v685 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v686 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v686 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v687 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v687 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v101 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v101 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v69 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v69 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v69 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v7 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v7 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v69 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v69 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v69 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v688 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v688 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v689 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v689 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v690 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v690 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v691 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v691 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v692 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v692 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v693 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v693 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v694 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v694 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v695 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v695 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v102 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v102 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v70 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v70 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v70 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v8 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v8 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v70 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v70 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v70 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v696 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v696 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v697 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v697 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v698 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v698 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v699 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v699 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v700 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v700 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v701 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v701 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v702 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v702 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v703 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v703 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v103 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v103 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v71 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v71 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v71 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v9 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v9 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v71 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v71 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v71 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v704 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v704 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v705 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v705 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v706 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v706 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v707 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v707 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v708 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v708 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v709 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v709 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v710 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v710 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v711 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v711 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v104 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v104 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v72 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v72 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v72 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v10 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v10 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v72 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v72 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v72 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v712 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v712 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v713 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v713 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v714 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v714 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v715 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v715 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v716 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v716 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v717 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v717 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v718 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v718 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v719 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v719 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v105 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v105 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v73 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v73 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v73 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v11 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v11 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v73 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v73 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v73 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v720 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v720 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v721 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v721 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v722 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v722 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v723 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v723 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v724 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v724 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v725 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v725 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v726 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v726 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v727 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v727 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v106 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v106 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v74 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v74 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v74 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v12 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v12 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v74 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v74 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v74 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v728 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v728 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v729 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v729 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v730 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v730 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v731 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v731 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v732 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v732 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v733 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v733 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v734 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v734 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v735 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v735 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v107 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v107 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v75 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v75 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v75 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v13 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v13 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v75 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v75 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v75 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v736 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v736 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v737 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v737 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v738 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v738 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v739 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v739 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v740 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v740 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v741 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v741 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v742 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v742 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v743 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v743 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v108 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v108 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v76 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v76 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v76 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v14 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v14 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v76 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v76 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v76 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v744 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v744 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v745 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v745 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v746 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v746 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v747 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v747 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v748 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v748 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v749 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v749 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v750 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v750 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v751 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v751 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v109 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v109 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v77 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v77 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v77 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v15 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v15 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v77 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v77 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v77 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v752 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v752 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v753 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v753 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v754 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v754 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v755 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v755 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v756 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v756 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v757 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v757 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v758 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v758 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v759 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v759 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v110 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v110 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v78 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v78 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v78 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v16 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v16 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v78 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v78 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v78 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v760 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v760 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v761 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v761 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v762 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v762 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v763 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v763 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v764 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v764 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v765 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v765 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v766 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v766 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v767 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v767 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v111 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v111 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v79 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v79 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v79 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v17 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v17 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v79 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v79 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v79 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v768 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v768 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v769 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v769 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v770 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v770 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v771 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v771 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v772 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v772 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v773 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v773 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v774 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v774 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v775 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v775 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v112 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v112 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v80 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v80 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v80 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v18 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v18 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v80 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v80 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v80 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v776 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v776 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v777 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v777 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v778 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v778 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v779 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v779 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v780 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v780 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v781 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v781 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v782 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v782 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v783 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v783 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v113 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v113 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v81 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v81 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v81 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v19 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v19 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v81 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v81 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v81 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v784 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v784 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v785 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v785 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v786 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v786 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v787 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v787 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v788 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v788 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v789 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v789 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v790 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v790 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v791 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v791 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v114 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v114 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v82 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v82 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v82 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v20 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v20 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v82 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v82 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v82 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v792 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v792 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v793 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v793 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v794 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v794 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v795 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v795 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v796 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v796 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v797 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v797 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v798 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v798 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v799 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v799 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v115 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v115 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v83 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v83 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v83 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v21 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v21 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v83 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v83 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v83 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v800 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v800 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v801 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v801 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v802 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v802 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v803 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v803 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v804 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v804 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v805 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v805 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v806 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v806 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v807 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v807 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v116 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v116 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v84 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v84 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v84 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v22 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v22 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v84 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v84 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v84 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v808 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v808 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v809 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v809 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v810 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v810 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v811 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v811 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v812 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v812 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v813 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v813 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v814 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v814 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v815 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v815 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v117 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v117 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v85 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v85 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v85 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v23 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v23 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v85 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v85 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v85 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v816 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v816 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v817 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v817 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v818 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v818 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v819 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v819 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v820 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v820 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v821 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v821 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v822 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v822 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v823 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v823 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v118 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v118 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v86 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v86 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v86 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v24 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v24 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v86 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v86 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v86 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v824 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v824 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v825 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v825 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v826 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v826 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v827 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v827 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v828 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v828 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v829 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v829 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v830 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v830 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v831 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v831 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v119 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v119 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v87 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v87 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v87 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v25 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v25 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v87 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v87 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v87 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v832 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v832 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v833 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v833 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v834 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v834 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v835 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v835 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v836 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v836 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v837 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v837 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v838 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v838 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v839 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v839 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v120 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v120 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v88 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v88 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v88 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v26 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v26 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v88 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v88 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v88 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v840 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v840 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v841 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v841 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v842 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v842 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v843 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v843 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v844 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v844 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v845 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v845 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v846 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v846 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v847 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v847 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v121 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v121 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v89 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v89 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v89 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v27 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v27 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v89 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v89 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v89 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v848 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v848 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v849 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v849 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v850 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v850 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v851 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v851 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v852 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v852 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v853 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v853 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v854 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v854 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v855 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v855 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v122 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v122 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v90 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v90 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v90 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v28 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v28 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v90 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v90 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v90 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v856 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v856 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v857 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v857 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v858 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v858 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v859 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v859 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v860 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v860 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v861 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v861 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v862 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v862 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v863 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v863 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v123 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v123 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v91 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v91 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v91 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v29 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v29 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v91 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v91 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v91 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v864 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v864 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v865 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v865 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v866 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v866 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v867 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v867 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v868 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v868 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v869 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v869 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v870 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v870 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v871 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v871 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v124 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v124 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v92 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v92 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v92 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v30 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v30 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v92 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v92 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v92 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v872 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v872 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v873 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v873 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v874 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v874 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v875 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v875 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v876 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v876 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v877 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v877 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v878 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v878 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v879 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v879 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v125 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v125 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v93 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v93 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v93 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v31 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v31 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v93 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v93 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v93 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v880 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v880 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v881 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v881 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v882 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v882 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v883 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v883 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v884 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v884 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v885 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v885 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v886 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v886 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v887 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v887 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v126 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v126 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v94 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v94 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v94 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v32 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v32 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v94 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v94 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v94 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v888 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v888 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v889 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v889 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v890 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v890 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v891 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v891 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v892 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v892 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v893 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v893 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v894 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v894 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v895 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v895 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v127 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v127 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v95 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v95 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v95 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v33 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v33 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v95 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v95 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v95 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v896 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v896 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v897 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v897 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v898 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v898 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v899 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v899 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v900 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v900 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v901 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v901 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v902 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v902 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v903 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v903 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v128 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v128 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v96 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v96 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v96 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v34 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v34 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v96 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v96 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v96 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v904 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v904 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v905 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v905 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v906 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v906 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v907 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v907 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v908 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v908 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v909 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v909 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v910 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v910 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v911 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v911 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v129 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v129 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v97 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v97 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v97 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v35 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v35 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v97 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v97 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v97 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v912 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v912 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v913 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v913 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v914 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v914 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v915 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v915 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v916 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v916 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v917 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v917 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v918 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v918 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v919 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v919 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v130 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v130 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v98 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v98 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v98 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v36 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v36 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v98 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v98 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v98 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v920 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v920 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v921 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v921 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v922 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v922 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v923 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v923 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v924 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v924 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v925 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v925 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v926 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v926 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v927 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v927 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v131 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v131 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v99 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v99 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v99 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v37 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v37 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v99 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v99 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v99 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v928 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v928 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v929 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v929 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v930 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v930 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v931 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v931 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v932 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v932 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v933 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v933 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v934 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v934 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v935 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v935 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v132 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v132 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v100 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v100 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v100 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v38 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v38 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v100 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v100 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v100 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v936 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v936 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v937 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v937 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v938 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v938 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v939 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v939 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v940 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v940 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v941 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v941 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v942 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v942 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v943 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v943 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v133 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v133 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v101 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v101 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v101 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v39 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v39 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v101 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v101 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v101 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v944 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v944 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v945 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v945 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v946 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v946 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v947 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v947 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v948 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v948 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v949 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v949 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v950 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v950 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v951 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v951 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v134 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v134 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v102 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v102 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v102 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v40 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v40 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v102 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v102 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v102 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v952 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v952 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v953 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v953 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v954 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v954 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v955 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v955 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v956 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v956 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v957 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v957 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v958 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v958 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v959 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v959 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v135 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v135 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v103 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v103 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v103 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v41 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v41 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v103 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v103 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v103 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v960 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v960 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v961 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v961 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v962 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v962 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v963 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v963 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v964 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v964 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v965 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v965 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v966 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v966 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v967 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v967 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v136 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v136 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v104 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v104 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v104 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v42 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v42 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v104 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v104 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v104 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v968 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v968 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v969 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v969 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v970 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v970 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v971 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v971 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v972 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v972 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v973 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v973 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v974 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v974 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v975 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v975 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v137 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v137 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v105 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v105 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v105 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v43 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v43 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v105 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v105 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v105 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v976 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v976 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v977 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v977 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v978 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v978 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v979 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v979 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v980 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v980 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v981 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v981 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v982 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v982 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v983 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v983 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v138 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v138 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v106 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v106 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v106 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v44 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v44 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v106 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v106 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v106 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v984 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v984 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v985 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v985 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v986 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v986 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v987 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v987 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v988 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v988 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v989 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v989 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v990 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v990 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v991 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v991 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v139 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v139 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v107 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v107 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v107 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v45 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v45 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v107 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v107 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v107 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v992 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v992 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v993 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v993 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v994 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v994 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v995 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v995 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v996 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v996 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v997 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v997 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v998 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v998 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v999 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v999 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v140 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v140 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v108 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v108 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v108 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v46 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v46 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v108 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v108 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v108 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1000 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1000 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1001 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1001 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1002 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1002 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1003 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1003 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1004 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1004 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1005 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1005 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1006 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1006 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1007 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1007 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v141 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v141 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v109 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v109 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v109 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v47 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v47 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v109 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v109 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v109 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1008 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1008 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1009 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1009 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1010 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1010 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1011 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1011 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1012 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1012 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1013 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1013 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1014 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1014 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1015 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1015 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v142 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v142 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v110 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v110 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v110 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v48 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v48 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v110 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v110 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v110 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1016 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1016 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1017 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1017 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1018 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1018 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1019 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1019 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1020 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1020 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1021 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1021 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1022 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1022 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1023 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1023 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v143 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v143 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v111 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v111 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v111 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v49 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v49 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v111 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v111 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v111 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1024 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1024 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1025 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1025 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1026 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1026 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1027 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1027 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1028 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1028 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1029 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1029 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1030 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1030 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1031 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1031 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v144 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v144 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v112 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v112 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v112 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v50 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v50 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v112 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v112 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v112 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1032 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1032 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1033 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1033 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1034 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1034 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1035 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1035 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1036 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1036 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1037 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1037 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1038 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1038 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1039 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1039 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v145 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v145 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v113 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v113 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v113 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v51 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v51 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v113 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v113 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v113 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1040 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1040 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1041 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1041 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1042 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1042 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1043 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1043 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1044 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1044 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1045 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1045 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1046 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1046 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1047 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1047 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v146 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v146 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v114 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v114 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v114 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v52 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v52 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v114 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v114 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v114 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1048 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1048 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1049 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1049 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1050 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1050 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1051 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1051 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1052 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1052 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1053 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1053 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1054 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1054 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1055 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1055 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v147 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v147 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v115 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v115 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v115 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v53 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v53 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v115 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v115 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v115 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1056 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1056 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1057 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1057 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1058 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1058 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1059 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1059 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1060 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1060 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1061 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1061 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1062 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1062 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1063 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1063 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v148 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v148 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v116 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v116 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v116 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v54 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v54 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v116 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v116 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v116 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1064 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1064 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1065 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1065 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1066 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1066 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1067 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1067 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1068 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1068 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1069 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1069 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1070 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1070 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1071 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1071 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v149 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v149 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v117 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v117 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v117 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v55 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v55 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v117 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v117 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v117 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1072 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1072 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1073 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1073 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1074 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1074 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1075 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1075 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1076 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1076 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1077 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1077 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1078 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1078 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1079 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1079 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v150 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v150 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v118 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v118 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v118 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v56 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v56 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v118 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v118 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v118 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1080 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1080 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1081 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1081 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1082 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1082 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1083 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1083 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1084 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1084 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1085 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1085 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1086 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1086 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1087 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1087 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v151 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v151 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v119 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v119 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v119 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v57 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v57 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v119 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v119 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v119 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1088 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1088 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1089 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1089 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1090 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1090 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1091 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1091 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1092 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1092 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1093 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1093 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1094 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1094 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1095 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1095 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v152 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v152 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v120 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v120 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v120 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v58 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v58 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v120 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v120 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v120 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1096 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1096 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1097 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1097 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1098 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1098 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1099 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1099 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1100 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1100 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1101 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1101 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1102 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1102 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1103 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1103 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v153 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v153 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v121 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v121 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v121 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v59 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v59 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v121 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v121 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v121 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1104 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1104 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1105 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1105 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1106 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1106 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1107 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1107 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1108 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1108 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1109 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1109 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1110 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1110 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1111 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1111 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v154 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v154 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v122 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v122 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v122 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v60 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v60 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v122 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v122 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v122 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1112 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1112 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1113 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1113 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1114 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1114 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1115 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1115 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1116 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1116 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1117 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1117 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1118 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1118 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1119 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1119 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v155 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v155 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v123 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v123 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v123 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v61 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v61 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v123 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v123 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v123 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1120 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1120 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1121 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1121 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1122 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1122 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1123 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1123 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1124 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1124 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1125 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1125 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1126 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1126 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1127 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1127 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v156 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v156 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v124 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v124 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v124 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v62 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v62 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v124 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v124 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v124 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1128 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1128 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1129 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1129 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1130 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1130 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1131 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1131 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1132 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1132 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1133 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1133 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1134 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1134 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1135 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1135 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v157 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v157 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v125 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v125 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v125 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v63 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v63 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v125 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v125 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v125 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1136 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1136 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1137 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1137 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1138 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1138 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1139 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1139 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1140 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1140 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1141 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1141 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1142 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1142 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1143 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1143 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v158 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v158 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v126 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v126 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v126 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v64 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v64 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v126 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v126 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v126 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1144 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1144 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1145 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1145 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1146 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1146 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1147 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1147 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1148 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1148 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1149 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1149 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1150 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1150 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1151 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw__v1151 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v159 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw__v159 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v127 = 0;
    vlSelf->__VdlyDim0__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v127 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs__v127 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v65 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high__v65 = 0;
    vlSelf->__VdlyVal__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v127 = 0;
    vlSelf->__VdlyLsb__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v127 = 0;
    vlSelf->__VdlySet__tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in__v127 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__clk_phy__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__ck_in__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in__0 = 0;
    vlSelf->__Vtrigprevexpr_h08656a01__0 = 0;
    vlSelf->__Vtrigprevexpr_h08656b42__0 = 0;
    vlSelf->__Vtrigprevexpr_h086571b6__0 = 0;
    vlSelf->__Vtrigprevexpr_h086570f5__0 = 0;
    vlSelf->__Vtrigprevexpr_h08657134__0 = 0;
    vlSelf->__Vtrigprevexpr_h08656a73__0 = 0;
    vlSelf->__Vtrigprevexpr_h086570a9__0 = 0;
    vlSelf->__Vtrigprevexpr_h08656fea__0 = 0;
    vlSelf->__Vtrigprevexpr_h08657037__0 = 0;
    vlSelf->__Vtrigprevexpr_h08657178__0 = 0;
    vlSelf->__Vtrigprevexpr_h086576e0__0 = 0;
    vlSelf->__Vtrigprevexpr_h0865779f__0 = 0;
    vlSelf->__Vtrigprevexpr_h08656872__0 = 0;
    vlSelf->__Vtrigprevexpr_h08656731__0 = 0;
    vlSelf->__Vtrigprevexpr_h086575db__0 = 0;
    vlSelf->__Vtrigprevexpr_h0865769c__0 = 0;
    vlSelf->__Vtrigprevexpr_h086571c9__0 = 0;
    vlSelf->__Vtrigprevexpr_h0865720a__0 = 0;
    vlSelf->__Vtrigprevexpr_h0865794e__0 = 0;
    vlSelf->__Vtrigprevexpr_h0865798d__0 = 0;
    vlSelf->__Vtrigprevexpr_h086578cc__0 = 0;
    vlSelf->__Vtrigprevexpr_h0865790b__0 = 0;
    vlSelf->__Vtrigprevexpr_h086578a1__0 = 0;
    vlSelf->__Vtrigprevexpr_h086577e2__0 = 0;
    vlSelf->__Vtrigprevexpr_h086577cf__0 = 0;
    vlSelf->__Vtrigprevexpr_h08657810__0 = 0;
    vlSelf->__Vtrigprevexpr_h0864ff88__0 = 0;
    vlSelf->__Vtrigprevexpr_h0864fec7__0 = 0;
    vlSelf->__Vtrigprevexpr_h08656efa__0 = 0;
    vlSelf->__Vtrigprevexpr_h08657039__0 = 0;
    vlSelf->__Vtrigprevexpr_h0864fe83__0 = 0;
    vlSelf->__Vtrigprevexpr_h0864fdc4__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__cke_in__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__odt_in__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in__0 = 0;
    vlSelf->__Vtrigprevexpr_h1bed9077__0 = 0;
    vlSelf->__Vtrigprevexpr_h1bed8a19__0 = 0;
    vlSelf->__Vtrigprevexpr_h1bed8ade__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42cfa__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42e3e__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b4279a__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b426dd__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42e11__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b4275f__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42c79__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42bc6__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42b24__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42c3c__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42d80__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42cbf__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42bfb__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b42d3d__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b434cf__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b43210__0 = 0;
    vlSelf->__Vtrigprevexpr_hb7b4314e__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5ad84__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5b0c8__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb64224__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb64367__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5aa8b__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb641e1__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5ab03__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5ac40__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb645d6__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5aabe__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5ac02__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5ad41__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5ac7d__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5abc7__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5b551__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5ae92__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5afd8__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5b514__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb64658__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb6475b__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5b4d7__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb64615__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5af4f__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5b08c__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5a9ca__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5af0a__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5b056__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5b195__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5aec9__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5afdb__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5991d__0 = 0;
    vlSelf->__Vtrigprevexpr_h7eb5925e__0 = 0;
    vlSelf->__Vtrigprevexpr_h424933b1__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493360__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249331f__0 = 0;
    vlSelf->__Vtrigprevexpr_h42491ce7__0 = 0;
    vlSelf->__Vtrigprevexpr_h42491ca8__0 = 0;
    vlSelf->__Vtrigprevexpr_h42492859__0 = 0;
    vlSelf->__Vtrigprevexpr_h42491c36__0 = 0;
    vlSelf->__Vtrigprevexpr_h42491df8__0 = 0;
    vlSelf->__Vtrigprevexpr_h424921b7__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249216a__0 = 0;
    vlSelf->__Vtrigprevexpr_h42492129__0 = 0;
    vlSelf->__Vtrigprevexpr_h424932dd__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249329e__0 = 0;
    vlSelf->__Vtrigprevexpr_h42491e5b__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493208__0 = 0;
    vlSelf->__Vtrigprevexpr_h424953c6__0 = 0;
    vlSelf->__Vtrigprevexpr_h42495785__0 = 0;
    vlSelf->__Vtrigprevexpr_h42495744__0 = 0;
    vlSelf->__Vtrigprevexpr_h42495703__0 = 0;
    vlSelf->__Vtrigprevexpr_h424920f3__0 = 0;
    vlSelf->__Vtrigprevexpr_h424920b4__0 = 0;
    vlSelf->__Vtrigprevexpr_h42491c75__0 = 0;
    vlSelf->__Vtrigprevexpr_h42492002__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249322c__0 = 0;
    vlSelf->__Vtrigprevexpr_h424931eb__0 = 0;
    vlSelf->__Vtrigprevexpr_h424935ae__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249356d__0 = 0;
    vlSelf->__Vtrigprevexpr_h424956b9__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249567a__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493247__0 = 0;
    vlSelf->__Vtrigprevexpr_h42495614__0 = 0;
    vlSelf->__Vtrigprevexpr_h424957ca__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494b89__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494b58__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494b17__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249352f__0 = 0;
    vlSelf->__Vtrigprevexpr_h424934f0__0 = 0;
    vlSelf->__Vtrigprevexpr_h42492041__0 = 0;
    vlSelf->__Vtrigprevexpr_h424953fe__0 = 0;
    vlSelf->__Vtrigprevexpr_h424955c0__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249597f__0 = 0;
    vlSelf->__Vtrigprevexpr_h42495952__0 = 0;
    vlSelf->__Vtrigprevexpr_h42495911__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494ad5__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494a96__0 = 0;
    vlSelf->__Vtrigprevexpr_h42495653__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488a80__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488dbe__0 = 0;
    vlSelf->__Vtrigprevexpr_h424890fd__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488e3c__0 = 0;
    vlSelf->__Vtrigprevexpr_h4248917b__0 = 0;
    vlSelf->__Vtrigprevexpr_h424958bb__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249587c__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249543d__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488c8a__0 = 0;
    vlSelf->__Vtrigprevexpr_h424897d4__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488b13__0 = 0;
    vlSelf->__Vtrigprevexpr_h42489856__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488b95__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488ad1__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488e12__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488b3f__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488eec__0 = 0;
    vlSelf->__Vtrigprevexpr_h424961c2__0 = 0;
    vlSelf->__Vtrigprevexpr_h42496501__0 = 0;
    vlSelf->__Vtrigprevexpr_h424962b0__0 = 0;
    vlSelf->__Vtrigprevexpr_h424961ef__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488cd7__0 = 0;
    vlSelf->__Vtrigprevexpr_h42489818__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488d49__0 = 0;
    vlSelf->__Vtrigprevexpr_h42489086__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488bc8__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488f07__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488c3a__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488f79__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488f2d__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249626e__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488fab__0 = 0;
    vlSelf->__Vtrigprevexpr_h424962b8__0 = 0;
    vlSelf->__Vtrigprevexpr_h424945f6__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494935__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494674__0 = 0;
    vlSelf->__Vtrigprevexpr_h424949b3__0 = 0;
    vlSelf->__Vtrigprevexpr_h424890c3__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488c04__0 = 0;
    vlSelf->__Vtrigprevexpr_h42489145__0 = 0;
    vlSelf->__Vtrigprevexpr_h424964b2__0 = 0;
    vlSelf->__Vtrigprevexpr_h42488fdc__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249631b__0 = 0;
    vlSelf->__Vtrigprevexpr_h4248905e__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249639d__0 = 0;
    vlSelf->__Vtrigprevexpr_h424962e9__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249462a__0 = 0;
    vlSelf->__Vtrigprevexpr_h42496377__0 = 0;
    vlSelf->__Vtrigprevexpr_h424946a4__0 = 0;
    vlSelf->__Vtrigprevexpr_h424939da__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493d19__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493a68__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493da7__0 = 0;
    vlSelf->__Vtrigprevexpr_h424964df__0 = 0;
    vlSelf->__Vtrigprevexpr_h42489020__0 = 0;
    vlSelf->__Vtrigprevexpr_h42496571__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249488e__0 = 0;
    vlSelf->__Vtrigprevexpr_h424943d0__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249470f__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494462__0 = 0;
    vlSelf->__Vtrigprevexpr_h424947a1__0 = 0;
    vlSelf->__Vtrigprevexpr_h424946e5__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493a26__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494763__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493b30__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493dee__0 = 0;
    vlSelf->__Vtrigprevexpr_h424941ad__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493e6c__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493e2b__0 = 0;
    vlSelf->__Vtrigprevexpr_h424948cb__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249440c__0 = 0;
    vlSelf->__Vtrigprevexpr_h4249494d__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493cba__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493b84__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493b43__0 = 0;
    vlSelf->__Vtrigprevexpr_h42494806__0 = 0;
    vlSelf->__Vtrigprevexpr_h424947c5__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493a81__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493e42__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493b6f__0 = 0;
    vlSelf->__Vtrigprevexpr_h42493ebc__0 = 0;
    vlSelf->__Vtrigprevexpr_h42495592__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6da6__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6be3__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4327__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6d65__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4499__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4ee8__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd69ca__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6f16__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6b58__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6a89__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd70cd__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6a17__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6a4b__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6d8e__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd7978__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6d38__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd78ea__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd78b7__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6ed3__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd7829__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd7055__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6b94__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd776e__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6b02__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd76ec__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd76ad__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd7669__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd762b__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd75f7__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd79aa__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd753c__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd7904__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd45ae__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd43eb__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd3aff__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd456d__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd3c91__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd46c0__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4202__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd486e__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd43b0__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd41c1__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4935__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd436f__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd42b3__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd44f6__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd7020__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4e60__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd71b2__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6fdf__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd472b__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd7171__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd48ad__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd42ec__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4e26__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd445a__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4fa4__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4de5__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4531__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4f63__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd4e9f__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd70f2__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd6c24__0 = 0;
    vlSelf->__Vtrigprevexpr_h08fd710c__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_reset_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_cke__0 = 0;
    vlSelf->__Vtrigprevexpr_h60001e29__0 = 0;
    vlSelf->__Vtrigprevexpr_h6000216a__0 = 0;
    vlSelf->__Vtrigprevexpr_h60001fa6__0 = 0;
    vlSelf->__Vtrigprevexpr_h60001ee5__0 = 0;
    vlSelf->__Vtrigprevexpr_h81d9cd46__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_ba__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_addr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dq__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dqs__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__dqs_n__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_dut__DOT__o_ddr3_odt__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__init_done__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ddr3_init_top__DOT__init_error__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

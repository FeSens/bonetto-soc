// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_ddr3_init_top__Syms.h"


void Vtb_ddr3_init_top___024root__trace_chg_0_sub_0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_ddr3_init_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_0\n"); );
    // Body
    Vtb_ddr3_init_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_ddr3_init_top___024root*>(voidSelf);
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_ddr3_init_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<3>/*71:0*/, 10>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____1(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*55:0*/, 24>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____2(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*39:0*/, 2>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____3(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*14:0*/, 8>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____4(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____5(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____6(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____7(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____8(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____9(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____10(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____11(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____12(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 2>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____13(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 2>& __VdtypeVar);
void Vtb_ddr3_init_top___024root__trace_chg_dtype____14(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 32>& __VdtypeVar);

void Vtb_ddr3_init_top___024root__trace_chg_0_sub_0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_0_sub_0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__ba),3);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__i),25);
        bufp->chgBit(oldp+2,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__chk_err__Vstatic__err));
        bufp->chgBit(oldp+3,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__group));
        bufp->chgIData(oldp+4,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__j),32);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQCS),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQINIT),32);
        bufp->chgIData(oldp+7,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__TZQOPER),32);
        bufp->chgCData(oldp+8,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__min_cl__Vstatic__cwl),4);
        bufp->chgCData(oldp+9,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__min_cl__Vstatic__cl),4);
        bufp->chgCData(oldp+10,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__bank),3);
        bufp->chgSData(oldp+11,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__row),15);
        bufp->chgSData(oldp+12,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__col),10);
        bufp->chgIData(oldp+13,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__addr),28);
        bufp->chgQData(oldp+14,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__data),64);
        bufp->chgWData(oldp+16,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__char),128);
        bufp->chgIData(oldp+20,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__in),32);
        bufp->chgIData(oldp+21,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__fio_status),32);
        bufp->chgIData(oldp+22,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__reset__DOT__i),32);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgIData(oldp+23,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__fd),32);
        bufp->chgWData(oldp+24,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__open_bank_file__Vstatic__filename),2048);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgIData(oldp+88,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__code),32);
        bufp->chgIData(oldp+89,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__offset),32);
        bufp->chgWData(oldp+90,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__msg),1024);
        bufp->chgQData(oldp+122,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_from_file__Vstatic__read_value),64);
        bufp->chgIData(oldp+124,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_to_file__Vstatic__code),32);
        bufp->chgIData(oldp+125,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_to_file__Vstatic__offset),32);
        bufp->chgIData(oldp+126,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memory_write__Vstatic__addr),25);
        bufp->chgIData(oldp+127,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memory_read__Vstatic__addr),25);
        bufp->chgIData(oldp+128,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__erase_banks__Vstatic__bank),32);
        bufp->chgIData(oldp+129,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__reset_task__Vstatic__i),32);
        bufp->chgSData(oldp+130,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__i),9);
        bufp->chgIData(oldp+131,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__j),32);
        bufp->chgSData(oldp+132,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__tfaw_cntr),9);
        bufp->chgSData(oldp+133,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_task__Vstatic__col),10);
        bufp->chgCData(oldp+134,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__bank),3);
        bufp->chgSData(oldp+135,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__row),15);
        bufp->chgSData(oldp+136,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__col),10);
        bufp->chgIData(oldp+137,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__data_task__Vstatic__i),32);
        bufp->chgIData(oldp+138,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__main__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+139,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__seed),32);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____0(vlSelf, bufp, 140, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_string);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____1(vlSelf, bufp, 170, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_addr_string);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____2(vlSelf, bufp, 218, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_string);
        bufp->chgWData(oldp+222,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tmp_model_dir),1024);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgIData(oldp+254,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[7]),32);
        bufp->chgIData(oldp+255,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[6]),32);
        bufp->chgIData(oldp+256,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[5]),32);
        bufp->chgIData(oldp+257,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[4]),32);
        bufp->chgIData(oldp+258,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[3]),32);
        bufp->chgIData(oldp+259,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[2]),32);
        bufp->chgIData(oldp+260,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[1]),32);
        bufp->chgIData(oldp+261,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memfd[0]),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgDouble(oldp+262,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_avg));
        bufp->chgQData(oldp+264,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tck_i),64);
        bufp->chgDouble(oldp+266,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tch_avg));
        bufp->chgDouble(oldp+268,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tcl_avg));
        bufp->chgQData(oldp+270,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_pos),64);
        bufp->chgQData(oldp+272,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_ck_neg),64);
        bufp->chgDouble(oldp+274,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tjit_per_rtime));
        bufp->chgIData(oldp+276,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tjit_cc_time),32);
        bufp->chgDouble(oldp+277,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__terr_nper_rtime));
        bufp->chgDouble(oldp+279,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tjit_ch_rtime));
        bufp->chgDouble(oldp+281,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__duty_cycle));
        bufp->chgIData(oldp+283,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_delay),32);
        bufp->chgBit(oldp+284,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__burst_order));
        bufp->chgCData(oldp+285,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__burst_length),4);
        bufp->chgBit(oldp+286,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__blotf));
        bufp->chgBit(oldp+287,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__truebl4));
        bufp->chgIData(oldp+288,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_latency),32);
        bufp->chgBit(oldp+289,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_reset));
        bufp->chgBit(oldp+290,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_locked));
        bufp->chgIData(oldp+291,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_recovery),32);
        bufp->chgBit(oldp+292,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__low_power));
        bufp->chgBit(oldp+293,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dll_en));
        bufp->chgCData(oldp+294,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_rtt_nom),3);
        bufp->chgCData(oldp+295,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_rtt_wr),2);
        bufp->chgBit(oldp+296,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_en));
        bufp->chgBit(oldp+297,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_en));
        bufp->chgCData(oldp+298,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__al),2);
        bufp->chgIData(oldp+299,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__additive_latency),32);
        bufp->chgBit(oldp+300,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_levelization));
        bufp->chgBit(oldp+301,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tdqs_en));
        bufp->chgBit(oldp+302,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__out_en));
        bufp->chgCData(oldp+303,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__pasr),3);
        bufp->chgIData(oldp+304,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_write_latency),32);
        bufp->chgBit(oldp+305,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__asr));
        bufp->chgBit(oldp+306,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__srt));
        bufp->chgCData(oldp+307,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mpr_select),2);
        bufp->chgBit(oldp+308,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mpr_en));
        bufp->chgIData(oldp+309,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_latency),32);
        bufp->chgIData(oldp+310,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_latency),32);
        bufp->chgCData(oldp+311,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__write_precharge_bank),8);
        bufp->chgCData(oldp+312,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__read_precharge_bank),8);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____3(vlSelf, bufp, 313, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__active_row);
        bufp->chgBit(oldp+321,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__in_power_down));
        bufp->chgBit(oldp+322,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__in_self_refresh));
        bufp->chgCData(oldp+323,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__init_mode_reg),4);
        bufp->chgBit(oldp+324,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__init_dll_reset));
        bufp->chgBit(oldp+325,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__init_done));
        bufp->chgIData(oldp+326,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__init_step),32);
        bufp->chgBit(oldp+327,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__zq_set));
        bufp->chgBit(oldp+328,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__er_trfc_max));
        bufp->chgBit(oldp+329,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_state));
        bufp->chgBit(oldp+330,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state));
        bufp->chgCData(oldp+331,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mr_chk),2);
        bufp->chgBit(oldp+332,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rd_bc));
        bufp->chgIData(oldp+333,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ref_cntr),32);
        bufp->chgIData(oldp+334,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_cntr),32);
        bufp->chgQData(oldp+335,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__al_pipeline),57);
        bufp->chgQData(oldp+337,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_pipeline),57);
        bufp->chgQData(oldp+339,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rd_pipeline),57);
        bufp->chgQData(oldp+341,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_pipeline),57);
        bufp->chgQData(oldp+343,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_pipeline),57);
        bufp->chgBit(oldp+345,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_cke));
        bufp->chgCData(oldp+346,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_tran_index),6);
        bufp->chgQData(oldp+347,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_tran_pipeline),64);
        bufp->chgQData(oldp+349,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__memory_data),64);
        bufp->chgQData(oldp+351,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__bit_mask),64);
        bufp->chgCData(oldp+353,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__burst_position),3);
        bufp->chgCData(oldp+354,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__burst_cntr),4);
        bufp->chgCData(oldp+355,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_temp),8);
        bufp->chgQData(oldp+356,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_tdqss),64);
        bufp->chgBit(oldp+358,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_valid));
        bufp->chgIData(oldp+359,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdqs_cntr),32);
        bufp->chgIData(oldp+360,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wdq_cntr),32);
        bufp->chgCData(oldp+361,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__wr_burst_length),4);
        bufp->chgBit(oldp+362,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en));
        bufp->chgBit(oldp+363,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out));
        bufp->chgBit(oldp+364,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en));
        bufp->chgCData(oldp+365,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out),8);
        bufp->chgIData(oldp+366,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rdqsen_cntr),32);
        bufp->chgIData(oldp+367,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rdqs_cntr),32);
        bufp->chgIData(oldp+368,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rdqen_cntr),32);
        bufp->chgIData(oldp+369,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rdq_cntr),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity[5U])))) {
        bufp->chgSData(oldp+370,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[7]),15);
        bufp->chgSData(oldp+371,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[6]),15);
        bufp->chgSData(oldp+372,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[5]),15);
        bufp->chgSData(oldp+373,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[4]),15);
        bufp->chgSData(oldp+374,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[3]),15);
        bufp->chgSData(oldp+375,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[2]),15);
        bufp->chgSData(oldp+376,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[1]),15);
        bufp->chgSData(oldp+377,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__mode_reg[0]),15);
        bufp->chgCData(oldp+378,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__active_bank),8);
        bufp->chgCData(oldp+379,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__auto_precharge_bank),8);
        bufp->chgIData(oldp+380,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_precharge),32);
        bufp->chgQData(oldp+381,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_precharge),64);
        bufp->chgQData(oldp+383,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[7]),64);
        bufp->chgQData(oldp+385,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[6]),64);
        bufp->chgQData(oldp+387,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[5]),64);
        bufp->chgQData(oldp+389,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[4]),64);
        bufp->chgQData(oldp+391,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[3]),64);
        bufp->chgQData(oldp+393,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[2]),64);
        bufp->chgQData(oldp+395,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[1]),64);
        bufp->chgQData(oldp+397,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_precharge[0]),64);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgBit(oldp+399,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done) 
                                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n))));
        bufp->chgBit(oldp+400,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done) 
                                | (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cke))));
        bufp->chgBit(oldp+401,(((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done)) 
                                & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_odt))));
        bufp->chgBit(oldp+402,((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                      >> 3U))));
        bufp->chgBit(oldp+403,((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                      >> 2U))));
        bufp->chgBit(oldp+404,((1U & ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd) 
                                      >> 1U))));
        bufp->chgBit(oldp+405,((1U & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd))));
        bufp->chgCData(oldp+406,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_ba) 
                                  & (- (IData)((1U 
                                                & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done))))))),3);
        bufp->chgSData(oldp+407,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_addr) 
                                  & (- (IData)((1U 
                                                & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done))))))),15);
        bufp->chgBit(oldp+408,(vlSelfRef.tb_ddr3_init_top__DOT__init_done));
        bufp->chgBit(oldp+409,(vlSelfRef.tb_ddr3_init_top__DOT__init_error));
        bufp->chgCData(oldp+410,(vlSelfRef.tb_ddr3_init_top__DOT__init_error_code),4);
        bufp->chgCData(oldp+411,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__state),5);
        bufp->chgSData(oldp+412,(((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_addr) 
                                  & (- (IData)((1U 
                                                & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done))))))),16);
        bufp->chgBit(oldp+413,((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__init_done)))));
        bufp->chgBit(oldp+414,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_ack));
        bufp->chgIData(oldp+415,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__o_wb_dat),32);
        bufp->chgCData(oldp+416,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cmd),4);
        bufp->chgCData(oldp+417,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_ba),3);
        bufp->chgSData(oldp+418,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_addr),15);
        bufp->chgBit(oldp+419,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_reset_n));
        bufp->chgBit(oldp+420,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_cke));
        bufp->chgBit(oldp+421,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__init_odt));
        bufp->chgCData(oldp+422,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__sel_cmd),4);
        bufp->chgIData(oldp+423,(vlSelfRef.tb_ddr3_init_top__DOT__u_dut__DOT__u_init__DOT__wait_ctr),24);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgQData(oldp+424,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tch_i),64);
        bufp->chgQData(oldp+426,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tcl_i),64);
        bufp->chgBit(oldp+428,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_state_dly));
        bufp->chgBit(oldp+429,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dyn_odt_state_dly));
        bufp->chgBit(oldp+430,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_odt));
        bufp->chgIData(oldp+431,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_txpr),32);
        bufp->chgIData(oldp+432,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_load_mode),32);
        bufp->chgIData(oldp+433,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_refresh),32);
        bufp->chgIData(oldp+434,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_activate),32);
        bufp->chgIData(oldp+435,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_write),32);
        bufp->chgIData(oldp+436,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_read),32);
        bufp->chgIData(oldp+437,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqinit),32);
        bufp->chgIData(oldp+438,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqoper),32);
        bufp->chgIData(oldp+439,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_zqcs),32);
        bufp->chgIData(oldp+440,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_power_down),32);
        bufp->chgIData(oldp+441,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_slow_exit_pd),32);
        bufp->chgIData(oldp+442,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_self_refresh),32);
        bufp->chgIData(oldp+443,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_freq_change),32);
        bufp->chgIData(oldp+444,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_odt),32);
        bufp->chgIData(oldp+445,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_odth8),32);
        bufp->chgIData(oldp+446,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_dll_reset),32);
        bufp->chgIData(oldp+447,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cke_cmd),32);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____4(vlSelf, bufp, 448, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_write);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____5(vlSelf, bufp, 456, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_bank_read);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____6(vlSelf, bufp, 464, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_activate);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____7(vlSelf, bufp, 466, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_write);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____8(vlSelf, bufp, 468, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_group_read);
        bufp->chgQData(oldp+470,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_txpr),64);
        bufp->chgQData(oldp+472,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_load_mode),64);
        bufp->chgQData(oldp+474,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_refresh),64);
        bufp->chgQData(oldp+476,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_activate),64);
        bufp->chgQData(oldp+478,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_write_end),64);
        bufp->chgQData(oldp+480,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_power_down),64);
        bufp->chgQData(oldp+482,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_slow_exit_pd),64);
        bufp->chgQData(oldp+484,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_self_refresh),64);
        bufp->chgQData(oldp+486,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_freq_change),64);
        bufp->chgQData(oldp+488,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke_cmd),64);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____9(vlSelf, bufp, 490, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_activate);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____10(vlSelf, bufp, 506, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_write_end);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____11(vlSelf, bufp, 522, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_bank_read_end);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____12(vlSelf, bufp, 538, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_activate);
        Vtb_ddr3_init_top___024root__trace_chg_dtype____13(vlSelf, bufp, 542, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_group_write_end);
        bufp->chgBit(oldp+546,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in_valid));
        bufp->chgBit(oldp+547,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__b2b_write));
        bufp->chgBit(oldp+548,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_en_dly));
        bufp->chgBit(oldp+549,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgWData(oldp+550,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in),128);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgQData(oldp+554,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in),64);
        bufp->chgIData(oldp+556,((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in)),32);
        bufp->chgIData(oldp+557,((IData)((vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_in 
                                          >> 0x00000020U))),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgQData(oldp+558,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_postamble),64);
        bufp->chgQData(oldp+560,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_preamble),64);
        bufp->chgQData(oldp+562,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_low),64);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[9U]))) {
        bufp->chgWData(oldp+564,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dq_tdipw),128);
    }
    bufp->chgBit(oldp+568,(vlSelfRef.done_or_err));
    bufp->chgBit(oldp+569,(vlSelfRef.tb_ddr3_init_top__DOT__clk_phy));
    bufp->chgBit(oldp+570,(vlSelfRef.tb_ddr3_init_top__DOT__rst));
    bufp->chgBit(oldp+571,((1U & (~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__clk_phy)))));
    bufp->chgCData(oldp+572,((0x000000ffU & ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en)) 
                                             | ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly) 
                                                & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq__out__strong__en))))),8);
    bufp->chgBit(oldp+573,((1U & ((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en)) 
                                  | ((IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly) 
                                     & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en))))));
    bufp->chgBit(oldp+574,(((~ (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_out_dly)) 
                            & (IData)(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs__out__strong__en))));
    bufp->chgCData(oldp+575,(vlSelfRef.tb_ddr3_init_top__DOT__prev_state),5);
    bufp->chgIData(oldp+576,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_cntr),32);
    bufp->chgQData(oldp+577,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_write_dqs_high),64);
    bufp->chgIData(oldp+579,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__check_dm_tdipw),32);
    bufp->chgQData(oldp+580,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_rst_n),64);
    bufp->chgQData(oldp+582,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cke),64);
    bufp->chgQData(oldp+584,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_odt),64);
    bufp->chgQData(oldp+586,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[31]),64);
    bufp->chgQData(oldp+588,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[30]),64);
    bufp->chgQData(oldp+590,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[29]),64);
    bufp->chgQData(oldp+592,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[28]),64);
    bufp->chgQData(oldp+594,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[27]),64);
    bufp->chgQData(oldp+596,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[26]),64);
    bufp->chgQData(oldp+598,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[25]),64);
    bufp->chgQData(oldp+600,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[24]),64);
    bufp->chgQData(oldp+602,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[23]),64);
    bufp->chgQData(oldp+604,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[22]),64);
    bufp->chgQData(oldp+606,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[21]),64);
    bufp->chgQData(oldp+608,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[20]),64);
    bufp->chgQData(oldp+610,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[19]),64);
    bufp->chgQData(oldp+612,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[18]),64);
    bufp->chgQData(oldp+614,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[17]),64);
    bufp->chgQData(oldp+616,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[16]),64);
    bufp->chgQData(oldp+618,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[15]),64);
    bufp->chgQData(oldp+620,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[14]),64);
    bufp->chgQData(oldp+622,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[13]),64);
    bufp->chgQData(oldp+624,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[12]),64);
    bufp->chgQData(oldp+626,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[11]),64);
    bufp->chgQData(oldp+628,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[10]),64);
    bufp->chgQData(oldp+630,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[9]),64);
    bufp->chgQData(oldp+632,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[8]),64);
    bufp->chgQData(oldp+634,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[7]),64);
    bufp->chgQData(oldp+636,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[6]),64);
    bufp->chgQData(oldp+638,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[5]),64);
    bufp->chgQData(oldp+640,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[4]),64);
    bufp->chgQData(oldp+642,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[3]),64);
    bufp->chgQData(oldp+644,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[2]),64);
    bufp->chgQData(oldp+646,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[1]),64);
    bufp->chgQData(oldp+648,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dm[0]),64);
    Vtb_ddr3_init_top___024root__trace_chg_dtype____14(vlSelf, bufp, 650, vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_dqs);
    bufp->chgQData(oldp+714,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[23]),64);
    bufp->chgQData(oldp+716,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[22]),64);
    bufp->chgQData(oldp+718,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[21]),64);
    bufp->chgQData(oldp+720,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[20]),64);
    bufp->chgQData(oldp+722,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[19]),64);
    bufp->chgQData(oldp+724,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[18]),64);
    bufp->chgQData(oldp+726,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[17]),64);
    bufp->chgQData(oldp+728,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[16]),64);
    bufp->chgQData(oldp+730,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[15]),64);
    bufp->chgQData(oldp+732,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[14]),64);
    bufp->chgQData(oldp+734,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[13]),64);
    bufp->chgQData(oldp+736,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[12]),64);
    bufp->chgQData(oldp+738,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[11]),64);
    bufp->chgQData(oldp+740,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[10]),64);
    bufp->chgQData(oldp+742,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[9]),64);
    bufp->chgQData(oldp+744,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[8]),64);
    bufp->chgQData(oldp+746,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[7]),64);
    bufp->chgQData(oldp+748,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[6]),64);
    bufp->chgQData(oldp+750,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[5]),64);
    bufp->chgQData(oldp+752,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[4]),64);
    bufp->chgQData(oldp+754,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[3]),64);
    bufp->chgQData(oldp+756,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[2]),64);
    bufp->chgQData(oldp+758,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[1]),64);
    bufp->chgQData(oldp+760,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__tm_cmd_addr[0]),64);
    bufp->chgBit(oldp+762,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__rst_n_in));
    bufp->chgBit(oldp+763,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_in));
    bufp->chgBit(oldp+764,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ck_n_in));
    bufp->chgBit(oldp+765,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cke_in));
    bufp->chgBit(oldp+766,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cs_n_in));
    bufp->chgBit(oldp+767,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ras_n_in));
    bufp->chgBit(oldp+768,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cas_n_in));
    bufp->chgBit(oldp+769,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__we_n_in));
    bufp->chgIData(oldp+770,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in),32);
    bufp->chgCData(oldp+771,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__ba_in),3);
    bufp->chgIData(oldp+772,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__addr_in),17);
    bufp->chgBit(oldp+773,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__odt_in));
    bufp->chgIData(oldp+774,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in_pos),32);
    bufp->chgIData(oldp+775,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dm_in_neg),32);
    bufp->chgWData(oldp+776,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_pos),128);
    bufp->chgWData(oldp+780,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_in_neg),128);
    bufp->chgQData(oldp+784,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__prev_dqs_in),64);
    bufp->chgBit(oldp+786,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__diff_ck));
    bufp->chgCData(oldp+787,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__cmd_n_in),4);
    bufp->chgCData(oldp+788,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_en_dly),8);
    bufp->chgCData(oldp+789,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dq_out_dly),8);
    bufp->chgWData(oldp+790,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_even_receiver__Vstatic__bit_mask),128);
    bufp->chgWData(oldp+794,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_odd_receiver__Vstatic__bit_mask),128);
    bufp->chgCData(oldp+798,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_pos_timing_check__Vstatic__j),5);
    bufp->chgCData(oldp+799,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__dqs_neg_timing_check__Vstatic__j),5);
    bufp->chgIData(oldp+800,(vlSelfRef.tb_ddr3_init_top__DOT__u_micron__DOT__file_io_open__DOT__i),32);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____0(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<3>/*71:0*/, 10>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____0\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgWData(oldp+0,(__VdtypeVar[9]),72);
    bufp->chgWData(oldp+3,(__VdtypeVar[8]),72);
    bufp->chgWData(oldp+6,(__VdtypeVar[7]),72);
    bufp->chgWData(oldp+9,(__VdtypeVar[6]),72);
    bufp->chgWData(oldp+12,(__VdtypeVar[5]),72);
    bufp->chgWData(oldp+15,(__VdtypeVar[4]),72);
    bufp->chgWData(oldp+18,(__VdtypeVar[3]),72);
    bufp->chgWData(oldp+21,(__VdtypeVar[2]),72);
    bufp->chgWData(oldp+24,(__VdtypeVar[1]),72);
    bufp->chgWData(oldp+27,(__VdtypeVar[0]),72);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____1(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*55:0*/, 24>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____1\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgQData(oldp+0,(__VdtypeVar[23]),56);
    bufp->chgQData(oldp+2,(__VdtypeVar[22]),56);
    bufp->chgQData(oldp+4,(__VdtypeVar[21]),56);
    bufp->chgQData(oldp+6,(__VdtypeVar[20]),56);
    bufp->chgQData(oldp+8,(__VdtypeVar[19]),56);
    bufp->chgQData(oldp+10,(__VdtypeVar[18]),56);
    bufp->chgQData(oldp+12,(__VdtypeVar[17]),56);
    bufp->chgQData(oldp+14,(__VdtypeVar[16]),56);
    bufp->chgQData(oldp+16,(__VdtypeVar[15]),56);
    bufp->chgQData(oldp+18,(__VdtypeVar[14]),56);
    bufp->chgQData(oldp+20,(__VdtypeVar[13]),56);
    bufp->chgQData(oldp+22,(__VdtypeVar[12]),56);
    bufp->chgQData(oldp+24,(__VdtypeVar[11]),56);
    bufp->chgQData(oldp+26,(__VdtypeVar[10]),56);
    bufp->chgQData(oldp+28,(__VdtypeVar[9]),56);
    bufp->chgQData(oldp+30,(__VdtypeVar[8]),56);
    bufp->chgQData(oldp+32,(__VdtypeVar[7]),56);
    bufp->chgQData(oldp+34,(__VdtypeVar[6]),56);
    bufp->chgQData(oldp+36,(__VdtypeVar[5]),56);
    bufp->chgQData(oldp+38,(__VdtypeVar[4]),56);
    bufp->chgQData(oldp+40,(__VdtypeVar[3]),56);
    bufp->chgQData(oldp+42,(__VdtypeVar[2]),56);
    bufp->chgQData(oldp+44,(__VdtypeVar[1]),56);
    bufp->chgQData(oldp+46,(__VdtypeVar[0]),56);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____2(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*39:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____2\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgQData(oldp+0,(__VdtypeVar[1]),40);
    bufp->chgQData(oldp+2,(__VdtypeVar[0]),40);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____3(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*14:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____3\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgSData(oldp+0,(__VdtypeVar[7]),15);
    bufp->chgSData(oldp+1,(__VdtypeVar[6]),15);
    bufp->chgSData(oldp+2,(__VdtypeVar[5]),15);
    bufp->chgSData(oldp+3,(__VdtypeVar[4]),15);
    bufp->chgSData(oldp+4,(__VdtypeVar[3]),15);
    bufp->chgSData(oldp+5,(__VdtypeVar[2]),15);
    bufp->chgSData(oldp+6,(__VdtypeVar[1]),15);
    bufp->chgSData(oldp+7,(__VdtypeVar[0]),15);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____4(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____4\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[0]),32);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____5(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____5\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[0]),32);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____6(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____6\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[0]),32);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____7(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____7\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[0]),32);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____8(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____8\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[0]),32);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____9(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____9\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgQData(oldp+0,(__VdtypeVar[7]),64);
    bufp->chgQData(oldp+2,(__VdtypeVar[6]),64);
    bufp->chgQData(oldp+4,(__VdtypeVar[5]),64);
    bufp->chgQData(oldp+6,(__VdtypeVar[4]),64);
    bufp->chgQData(oldp+8,(__VdtypeVar[3]),64);
    bufp->chgQData(oldp+10,(__VdtypeVar[2]),64);
    bufp->chgQData(oldp+12,(__VdtypeVar[1]),64);
    bufp->chgQData(oldp+14,(__VdtypeVar[0]),64);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____10(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____10\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgQData(oldp+0,(__VdtypeVar[7]),64);
    bufp->chgQData(oldp+2,(__VdtypeVar[6]),64);
    bufp->chgQData(oldp+4,(__VdtypeVar[5]),64);
    bufp->chgQData(oldp+6,(__VdtypeVar[4]),64);
    bufp->chgQData(oldp+8,(__VdtypeVar[3]),64);
    bufp->chgQData(oldp+10,(__VdtypeVar[2]),64);
    bufp->chgQData(oldp+12,(__VdtypeVar[1]),64);
    bufp->chgQData(oldp+14,(__VdtypeVar[0]),64);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____11(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____11\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgQData(oldp+0,(__VdtypeVar[7]),64);
    bufp->chgQData(oldp+2,(__VdtypeVar[6]),64);
    bufp->chgQData(oldp+4,(__VdtypeVar[5]),64);
    bufp->chgQData(oldp+6,(__VdtypeVar[4]),64);
    bufp->chgQData(oldp+8,(__VdtypeVar[3]),64);
    bufp->chgQData(oldp+10,(__VdtypeVar[2]),64);
    bufp->chgQData(oldp+12,(__VdtypeVar[1]),64);
    bufp->chgQData(oldp+14,(__VdtypeVar[0]),64);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____12(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____12\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgQData(oldp+0,(__VdtypeVar[1]),64);
    bufp->chgQData(oldp+2,(__VdtypeVar[0]),64);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____13(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____13\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgQData(oldp+0,(__VdtypeVar[1]),64);
    bufp->chgQData(oldp+2,(__VdtypeVar[0]),64);
}

void Vtb_ddr3_init_top___024root__trace_chg_dtype____14(Vtb_ddr3_init_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<QData/*63:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_chg_dtype____14\n"); );
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgQData(oldp+0,(__VdtypeVar[31]),64);
    bufp->chgQData(oldp+2,(__VdtypeVar[30]),64);
    bufp->chgQData(oldp+4,(__VdtypeVar[29]),64);
    bufp->chgQData(oldp+6,(__VdtypeVar[28]),64);
    bufp->chgQData(oldp+8,(__VdtypeVar[27]),64);
    bufp->chgQData(oldp+10,(__VdtypeVar[26]),64);
    bufp->chgQData(oldp+12,(__VdtypeVar[25]),64);
    bufp->chgQData(oldp+14,(__VdtypeVar[24]),64);
    bufp->chgQData(oldp+16,(__VdtypeVar[23]),64);
    bufp->chgQData(oldp+18,(__VdtypeVar[22]),64);
    bufp->chgQData(oldp+20,(__VdtypeVar[21]),64);
    bufp->chgQData(oldp+22,(__VdtypeVar[20]),64);
    bufp->chgQData(oldp+24,(__VdtypeVar[19]),64);
    bufp->chgQData(oldp+26,(__VdtypeVar[18]),64);
    bufp->chgQData(oldp+28,(__VdtypeVar[17]),64);
    bufp->chgQData(oldp+30,(__VdtypeVar[16]),64);
    bufp->chgQData(oldp+32,(__VdtypeVar[15]),64);
    bufp->chgQData(oldp+34,(__VdtypeVar[14]),64);
    bufp->chgQData(oldp+36,(__VdtypeVar[13]),64);
    bufp->chgQData(oldp+38,(__VdtypeVar[12]),64);
    bufp->chgQData(oldp+40,(__VdtypeVar[11]),64);
    bufp->chgQData(oldp+42,(__VdtypeVar[10]),64);
    bufp->chgQData(oldp+44,(__VdtypeVar[9]),64);
    bufp->chgQData(oldp+46,(__VdtypeVar[8]),64);
    bufp->chgQData(oldp+48,(__VdtypeVar[7]),64);
    bufp->chgQData(oldp+50,(__VdtypeVar[6]),64);
    bufp->chgQData(oldp+52,(__VdtypeVar[5]),64);
    bufp->chgQData(oldp+54,(__VdtypeVar[4]),64);
    bufp->chgQData(oldp+56,(__VdtypeVar[3]),64);
    bufp->chgQData(oldp+58,(__VdtypeVar[2]),64);
    bufp->chgQData(oldp+60,(__VdtypeVar[1]),64);
    bufp->chgQData(oldp+62,(__VdtypeVar[0]),64);
}

void Vtb_ddr3_init_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ddr3_init_top___024root__trace_cleanup\n"); );
    // Body
    Vtb_ddr3_init_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_ddr3_init_top___024root*>(voidSelf);
    Vtb_ddr3_init_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
}

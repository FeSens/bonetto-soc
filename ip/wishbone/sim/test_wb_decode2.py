"""cocotb tests for wb_decode2 — confirms address-bit selection routes
WB transactions to the right slave and that acks flow back to the master."""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


async def reset(dut):
    dut.i_rst.value = 1
    dut.i_wb_cyc.value = 0
    dut.i_wb_stb.value = 0
    dut.i_wb_we.value  = 0
    dut.i_wb_adr.value = 0
    dut.i_wb_dat.value = 0
    dut.i_wb_sel.value = 0
    dut.i_s0_stall.value = 0
    dut.i_s0_ack.value   = 0
    dut.i_s0_dat.value   = 0
    dut.i_s0_err.value   = 0
    dut.i_s1_stall.value = 0
    dut.i_s1_ack.value   = 0
    dut.i_s1_dat.value   = 0
    dut.i_s1_err.value   = 0
    for _ in range(5):
        await RisingEdge(dut.i_clk)
    dut.i_rst.value = 0
    await RisingEdge(dut.i_clk)


@cocotb.test()
async def addr_bit_0_routes_to_slave0(dut):
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_we.value  = 1
    dut.i_wb_adr.value = 0x05         # SEL_BIT (param default 14) clear
    dut.i_wb_dat.value = 0xCAFEBABE
    dut.i_wb_sel.value = 0xF
    await RisingEdge(dut.i_clk)
    assert int(dut.o_s0_stb.value) == 1, "slave0 should see stb"
    assert int(dut.o_s1_stb.value) == 0, "slave1 should NOT see stb"
    assert int(dut.o_s0_we.value)  == 1
    assert int(dut.o_s0_dat.value) == 0xCAFEBABE


@cocotb.test()
async def addr_bit_1_routes_to_slave1(dut):
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_we.value  = 1
    dut.i_wb_adr.value = 0x4005        # SEL_BIT (default 14) set → slave1
    dut.i_wb_dat.value = 0xDEADBEEF
    dut.i_wb_sel.value = 0xF
    await RisingEdge(dut.i_clk)
    assert int(dut.o_s1_stb.value) == 1, "slave1 should see stb"
    assert int(dut.o_s0_stb.value) == 0, "slave0 should NOT see stb"
    assert int(dut.o_s1_we.value)  == 1
    assert int(dut.o_s1_dat.value) == 0xDEADBEEF


@cocotb.test()
async def slave0_ack_reaches_master(dut):
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_adr.value = 0x0007       # bit 14 clear → slave 0
    await RisingEdge(dut.i_clk)
    # Drop stb but keep cyc to wait for ack.
    dut.i_wb_stb.value = 0
    # Inject ack from slave0.
    dut.i_s0_ack.value = 1
    dut.i_s0_dat.value = 0x12345678
    await RisingEdge(dut.i_clk)
    assert int(dut.o_wb_ack.value) == 1, "master should see ack"
    assert int(dut.o_wb_dat.value) == 0x12345678


@cocotb.test()
async def slave1_ack_reaches_master(dut):
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_adr.value = 0x4007       # bit 14 set → slave 1
    await RisingEdge(dut.i_clk)
    dut.i_wb_stb.value = 0
    dut.i_s1_ack.value = 1
    dut.i_s1_dat.value = 0xABCDEF01
    await RisingEdge(dut.i_clk)
    assert int(dut.o_wb_ack.value) == 1
    assert int(dut.o_wb_dat.value) == 0xABCDEF01

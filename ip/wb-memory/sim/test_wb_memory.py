"""cocotb tests for wb_memory — BRAM-backed Wishbone slave."""

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
    for _ in range(5):
        await RisingEdge(dut.i_clk)
    dut.i_rst.value = 0
    await RisingEdge(dut.i_clk)


async def wb_write(dut, adr, dat):
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_we.value  = 1
    dut.i_wb_adr.value = adr
    dut.i_wb_dat.value = dat
    dut.i_wb_sel.value = 0xF
    await RisingEdge(dut.i_clk)
    dut.i_wb_stb.value = 0
    for _ in range(5):
        await RisingEdge(dut.i_clk)
        if int(dut.o_wb_ack.value):
            dut.i_wb_cyc.value = 0
            return
    raise AssertionError(f"WB write to 0x{adr:x} never acked")


async def wb_read(dut, adr):
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_we.value  = 0
    dut.i_wb_adr.value = adr
    dut.i_wb_sel.value = 0xF
    await RisingEdge(dut.i_clk)
    dut.i_wb_stb.value = 0
    for _ in range(5):
        await RisingEdge(dut.i_clk)
        if int(dut.o_wb_ack.value):
            rdat = int(dut.o_wb_dat.value)
            dut.i_wb_cyc.value = 0
            return rdat
    raise AssertionError(f"WB read from 0x{adr:x} never acked")


@cocotb.test()
async def write_read_single(dut):
    """Write a value, read it back from the same address."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    await wb_write(dut, 0x42, 0xDEADBEEF)
    val = await wb_read(dut, 0x42)
    assert val == 0xDEADBEEF, f"got 0x{val:08x}, want 0xdeadbeef"


@cocotb.test()
async def multiple_addresses_isolated(dut):
    """Writes to N different addresses come back independently."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    pat = {
        0x00: 0xCAFE0000,
        0x01: 0xCAFE0001,
        0x10: 0xCAFE0010,
        0x20: 0xCAFE0020,
        0x55: 0xCAFE0055,
        0xAA: 0xCAFE00AA,
        0xFF: 0xCAFE00FF,
    }
    for adr, dat in pat.items():
        await wb_write(dut, adr, dat)
    for adr, want in pat.items():
        got = await wb_read(dut, adr)
        assert got == want, f"adr=0x{adr:x}: got 0x{got:08x}, want 0x{want:08x}"


@cocotb.test()
async def stall_is_always_zero(dut):
    """wb_memory has BRAM-only depth-1 storage — `stall` is statically 0
    so a back-to-back stream of WB writes never stalls."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_we.value  = 1
    dut.i_wb_sel.value = 0xF
    for adr in range(8):
        dut.i_wb_adr.value = adr
        dut.i_wb_dat.value = 0x100 + adr
        await RisingEdge(dut.i_clk)
        assert int(dut.o_wb_stall.value) == 0, f"stall non-zero at adr={adr}"
    dut.i_wb_cyc.value = 0
    dut.i_wb_stb.value = 0

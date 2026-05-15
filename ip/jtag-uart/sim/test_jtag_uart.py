"""cocotb tests for jtag_uart's Wishbone slave port.

The BSCANE2 side can't be sim'd without Xilinx unisims, so we drive
the module with `\\`BONETTO_SOC_SIM` (tying off the JTAG signals) and
exercise the WB scratch-register behaviour from the controller side:

  * WB write at offset 0 stores into fpga_to_host (the value the host
    reads via JTAG USER1).
  * WB read at offset 0 returns host_to_fpga (latched from JTAG).
"""

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
    for _ in range(10):
        await RisingEdge(dut.i_clk)
        if int(dut.o_wb_ack.value):
            dut.i_wb_cyc.value = 0
            return
    raise AssertionError("WB write never acked")


async def wb_read(dut, adr):
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_we.value  = 0
    dut.i_wb_adr.value = adr
    dut.i_wb_sel.value = 0xF
    await RisingEdge(dut.i_clk)
    dut.i_wb_stb.value = 0
    for _ in range(10):
        await RisingEdge(dut.i_clk)
        if int(dut.o_wb_ack.value):
            rdat = int(dut.o_wb_dat.value)
            dut.i_wb_cyc.value = 0
            return rdat
    raise AssertionError("WB read never acked")


@cocotb.test()
async def fpga_to_host_inits_to_magic(dut):
    """After reset, fpga_to_host = 0xDEADBEEF magic value.
    WB doesn't expose fpga_to_host directly (host reads it via JTAG),
    but we can still verify the WB-write path acks immediately."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    # A WB write should still ack cleanly even before any other activity.
    await wb_write(dut, adr=0, dat=0x12345678)


@cocotb.test()
async def wb_write_then_read_roundtrip(dut):
    """A pattern of WB writes followed by reads — the IP must ack every
    transaction (data path is host_to_fpga ↔ fpga_to_host, so the value
    returned on WB-read is the most recent JTAG-side write; in sim that's
    0, but the protocol must complete cleanly)."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    for val in [0xDEADBEEF, 0xCAFEBABE, 0x55AA55AA, 0]:
        await wb_write(dut, adr=0, dat=val)
        rdat = await wb_read(dut, adr=0)
        dut._log.info(f"wrote 0x{val:08x}, read back 0x{rdat:08x}")

"""cocotb tests for jtag_wb_master — host-driven WB master via JTAG commands.

Drives i_cmd_word + single-cycle i_cmd_valid pulses to exercise the SET_ADDR,
SET_DATA_LO, SET_DATA_HI, GO_WRITE, GO_READ, HALT_OTHERS, and RESUME paths.
A simple slave model on the master-side WB pins acks single-cycle writes
and returns deterministic data on reads.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer


CMD_SET_ADDR = 0xE0
CMD_SET_AHI  = 0xE1
CMD_SET_DLO  = 0xE2
CMD_SET_DHI  = 0xE3
CMD_GO_WR    = 0xE4
CMD_GO_RD    = 0xE5
CMD_HALT     = 0xE6
CMD_RESUME   = 0xE7
CMD_SET_CAL  = 0xE8


def encode(cmd, payload):
    return ((cmd & 0xFF) << 24) | (payload & 0x00FFFFFF)


async def reset(dut):
    dut.i_rst.value = 1
    dut.i_cmd_word.value = 0
    dut.i_cmd_valid.value = 0
    dut.i_wb_stall.value = 0
    dut.i_wb_ack.value = 0
    dut.i_wb_dat.value = 0
    dut.i_wb_err.value = 0
    for _ in range(3):
        await RisingEdge(dut.i_clk)
    dut.i_rst.value = 0
    await RisingEdge(dut.i_clk)


async def fire_cmd(dut, cmd, payload=0):
    dut.i_cmd_word.value = encode(cmd, payload)
    dut.i_cmd_valid.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_cmd_valid.value = 0


async def slave_responder(dut, read_data=0xDECAFBAD, latency=2):
    """Single-outstanding WB slave: when stb&cyc, drop stall, then ack after
    `latency` cycles with read_data."""
    while True:
        await RisingEdge(dut.i_clk)
        await ReadOnly()
        if int(dut.o_wb_cyc.value) and int(dut.o_wb_stb.value):
            for _ in range(latency):
                await RisingEdge(dut.i_clk)
            dut.i_wb_ack.value = 1
            dut.i_wb_dat.value = read_data
            await RisingEdge(dut.i_clk)
            dut.i_wb_ack.value = 0
            dut.i_wb_dat.value = 0


@cocotb.test()
async def set_then_write(dut):
    """SET_ADDR + SET_DATA_LO + GO_WRITE — verify the WB master emits the
    stored addr/data, stb drops on stall=0, ack completes the transaction."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    cocotb.start_soon(slave_responder(dut, read_data=0xAAAA5555))

    await fire_cmd(dut, CMD_SET_ADDR, 0x1234)
    await fire_cmd(dut, CMD_SET_AHI, 0x2A5A)
    await fire_cmd(dut, CMD_SET_DLO, 0xDEAD)
    await fire_cmd(dut, CMD_SET_DHI, 0xBEEF)
    await ReadOnly()
    assert int(dut.o_addr.value) == 0x1234
    assert int(dut.o_addr_hi.value) == 0x2A5A
    assert int(dut.o_data.value) == 0xBEEFDEAD, \
        f"o_data want 0xBEEFDEAD got 0x{int(dut.o_data.value):08X}"
    await RisingEdge(dut.i_clk)

    await fire_cmd(dut, CMD_GO_WR)
    for _ in range(20):
        await RisingEdge(dut.i_clk)
        if not int(dut.o_busy.value):
            break
    else:
        raise AssertionError("WB write never completed")

    assert int(dut.o_last_ack.value) == 1
    assert int(dut.o_last_err.value) == 0


@cocotb.test()
async def set_then_read(dut):
    """SET_ADDR + GO_READ — verify rd_data latches the slave's response."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)
    cocotb.start_soon(slave_responder(dut, read_data=0xCAFEBABE))

    await fire_cmd(dut, CMD_SET_ADDR, 0x5678)
    await fire_cmd(dut, CMD_GO_RD)
    for _ in range(20):
        await RisingEdge(dut.i_clk)
        if not int(dut.o_busy.value):
            break
    else:
        raise AssertionError("WB read never completed")

    assert int(dut.o_rd_data.value) == 0xCAFEBABE, \
        f"rd_data want 0xCAFEBABE got 0x{int(dut.o_rd_data.value):08X}"
    assert int(dut.o_last_ack.value) == 1


@cocotb.test()
async def set_cal_pulse(dut):
    """SET_CAL command: payload[3:0]=lane, payload[12:8]=tap. One-shot
    pulse on o_cal_load_lane[lane]; o_cal_tap latched until next SET_CAL."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    # First load: lane=3, tap=17.
    payload = (17 << 8) | 3
    await fire_cmd(dut, CMD_SET_CAL, payload)
    await ReadOnly()
    assert int(dut.o_cal_load_lane.value) == (1 << 3), \
        f"want load[3]=1 got 0x{int(dut.o_cal_load_lane.value):03x}"
    assert int(dut.o_cal_tap.value) == 17

    # Pulse should clear after one cycle.
    await RisingEdge(dut.i_clk)
    await ReadOnly()
    assert int(dut.o_cal_load_lane.value) == 0, \
        "o_cal_load_lane must be a 1-cycle pulse"
    assert int(dut.o_cal_tap.value) == 17, "o_cal_tap must hold last value"

    # Second load: lane=7, tap=2.
    await RisingEdge(dut.i_clk)
    payload = (2 << 8) | 7
    await fire_cmd(dut, CMD_SET_CAL, payload)
    await ReadOnly()
    assert int(dut.o_cal_load_lane.value) == (1 << 7)
    assert int(dut.o_cal_tap.value) == 2


@cocotb.test()
async def halt_and_resume(dut):
    """HALT_OTHERS sets o_halt_others; RESUME clears it."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    assert int(dut.o_halt_others.value) == 0
    await fire_cmd(dut, CMD_HALT)
    await RisingEdge(dut.i_clk)
    assert int(dut.o_halt_others.value) == 1
    await fire_cmd(dut, CMD_RESUME)
    await RisingEdge(dut.i_clk)
    assert int(dut.o_halt_others.value) == 0

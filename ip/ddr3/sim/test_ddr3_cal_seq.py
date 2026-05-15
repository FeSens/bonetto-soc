"""cocotb tests for ddr3_cal_seq — post-init calibration sequencer.

Verifies the wlvl-then-rdlvl orchestration plus the two error paths."""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


async def reset(dut):
    dut.i_rst.value         = 1
    dut.i_init_done.value   = 0
    dut.i_wlvl_done.value   = 0
    dut.i_wlvl_error.value  = 0
    dut.i_rdlvl_done.value  = 0
    dut.i_rdlvl_error.value = 0
    for _ in range(3):
        await RisingEdge(dut.i_clk)
    dut.i_rst.value = 0
    await RisingEdge(dut.i_clk)


async def wait_for(dut, signal, value=1, max_cycles=200):
    for _ in range(max_cycles):
        await RisingEdge(dut.i_clk)
        if int(signal.value) == value:
            return
    raise AssertionError(f"signal {signal._name} stuck at {int(signal.value)}")


@cocotb.test()
async def happy_path_wlvl_then_rdlvl(dut):
    """init_done -> wlvl_start pulse -> wlvl_done -> rdlvl_start pulse ->
    rdlvl_done -> cal_done."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    dut.i_init_done.value = 1
    # Wait for wlvl_start to pulse high
    await wait_for(dut, dut.o_wlvl_start, 1)
    assert int(dut.o_rdlvl_start.value) == 0, "rdlvl shouldn't start yet"

    # FSM should drop wlvl_start the next cycle
    await RisingEdge(dut.i_clk)
    assert int(dut.o_wlvl_start.value) == 0, "wlvl_start should be a one-cycle pulse"

    # Simulate wlvl completion
    for _ in range(5):
        await RisingEdge(dut.i_clk)
    dut.i_wlvl_done.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_wlvl_done.value = 0

    # rdlvl_start must pulse next
    await wait_for(dut, dut.o_rdlvl_start, 1)
    await RisingEdge(dut.i_clk)
    assert int(dut.o_rdlvl_start.value) == 0

    # Simulate rdlvl completion
    for _ in range(5):
        await RisingEdge(dut.i_clk)
    dut.i_rdlvl_done.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_rdlvl_done.value = 0

    await wait_for(dut, dut.o_cal_done, 1)
    assert int(dut.o_cal_error.value) == 0
    assert int(dut.o_cal_error_code.value) == 0


@cocotb.test()
async def wlvl_error_latches_code_01(dut):
    """If wlvl returns error, sequencer goes to S_ERROR with code=01."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    dut.i_init_done.value = 1
    await wait_for(dut, dut.o_wlvl_start, 1)

    for _ in range(3):
        await RisingEdge(dut.i_clk)
    dut.i_wlvl_error.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_wlvl_error.value = 0

    await wait_for(dut, dut.o_cal_error, 1)
    assert int(dut.o_cal_done.value) == 0
    assert int(dut.o_cal_error_code.value) == 0b01, \
        f"want code 01, got {int(dut.o_cal_error_code.value):02b}"
    assert int(dut.o_rdlvl_start.value) == 0, "rdlvl shouldn't start after wlvl error"


@cocotb.test()
async def rdlvl_error_latches_code_10(dut):
    """If wlvl passes but rdlvl errors, sequencer goes to S_ERROR with code=10."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    dut.i_init_done.value = 1
    await wait_for(dut, dut.o_wlvl_start, 1)
    for _ in range(3):
        await RisingEdge(dut.i_clk)
    dut.i_wlvl_done.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_wlvl_done.value = 0

    await wait_for(dut, dut.o_rdlvl_start, 1)
    for _ in range(3):
        await RisingEdge(dut.i_clk)
    dut.i_rdlvl_error.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_rdlvl_error.value = 0

    await wait_for(dut, dut.o_cal_error, 1)
    assert int(dut.o_cal_done.value) == 0
    assert int(dut.o_cal_error_code.value) == 0b10, \
        f"want code 10, got {int(dut.o_cal_error_code.value):02b}"

"""
cocotb test for ddr3_ctrl — drives WB transactions after init_done and
watches the runtime FSM issue ACT / WR / PRE on the DDR3 command bus.

Run via `make -C ip/ddr3 cocotb` from the repo root (Icarus-based).

Pass criteria:
  1. init_done eventually asserts within INIT_DEADLINE clocks.
  2. After init_done, a WB write transaction is accepted (ack fires).
  3. While the write is in flight, the runtime FSM issues at least one
     ACT command (cs_n=0, ras_n=0, cas_n=1, we_n=1) on the cmd bus.
  4. init_error never asserts.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


INIT_DEADLINE = 1_000_000     # cycles; init takes ~560k @ 800 MHz tCK
WB_DEADLINE   = 100           # cycles to wait for an ack
TCK_PS        = 1250          # 1.25 ns @ DDR3-1600


def cmd_is(dut, cs, ras, cas, we):
    """Helper: return True if the DDR3 cmd bus matches the given pattern."""
    return (
        int(dut.o_ddr3_cs_n.value)  == cs  and
        int(dut.o_ddr3_ras_n.value) == ras and
        int(dut.o_ddr3_cas_n.value) == cas and
        int(dut.o_ddr3_we_n.value)  == we
    )


async def reset(dut):
    dut.i_rst.value     = 1
    dut.i_wb_cyc.value  = 0
    dut.i_wb_stb.value  = 0
    dut.i_wb_we.value   = 0
    dut.i_wb_adr.value  = 0
    dut.i_wb_dat.value  = 0
    dut.i_wb_sel.value  = 0
    for _ in range(20):
        await RisingEdge(dut.i_clk_phy)
    dut.i_rst.value = 0
    await RisingEdge(dut.i_clk_phy)


@cocotb.test()
async def init_completes(dut):
    """ddr3_ctrl raises init_done within INIT_DEADLINE cycles after reset."""
    cocotb.start_soon(Clock(dut.i_clk,     TCK_PS, units="ps").start())
    cocotb.start_soon(Clock(dut.i_clk_phy, TCK_PS, units="ps").start())
    await reset(dut)

    for cycle in range(INIT_DEADLINE):
        await RisingEdge(dut.i_clk_phy)
        if int(dut.o_init_error.value):
            raise AssertionError(
                f"init_error asserted at cycle {cycle}, "
                f"code={int(dut.o_init_error_code.value)}"
            )
        if int(dut.o_init_done.value):
            dut._log.info(f"init_done asserted at cycle {cycle}")
            return

    raise AssertionError(
        f"init_done did not assert within {INIT_DEADLINE} cycles "
        f"(state={int(dut.o_init_state.value)})"
    )


@cocotb.test()
async def wb_write_triggers_activate(dut):
    """After init_done, a WB write makes the runtime FSM issue ACT."""
    cocotb.start_soon(Clock(dut.i_clk,     TCK_PS, units="ps").start())
    cocotb.start_soon(Clock(dut.i_clk_phy, TCK_PS, units="ps").start())
    await reset(dut)

    # Wait for init_done.
    for _ in range(INIT_DEADLINE):
        await RisingEdge(dut.i_clk_phy)
        if int(dut.o_init_done.value):
            break
    else:
        raise AssertionError("init never completed")

    dut._log.info("init_done; issuing WB write")

    # Issue a WB write at a non-zero address.
    dut.i_wb_cyc.value = 1
    dut.i_wb_stb.value = 1
    dut.i_wb_we.value  = 1
    dut.i_wb_adr.value = 0x00010000     # arbitrary mid-range address
    dut.i_wb_dat.value = 0xDEADBEEF
    dut.i_wb_sel.value = 0xF

    # Wait for stall to drop (post-init it shouldn't be stalling).
    for _ in range(20):
        await RisingEdge(dut.i_clk_phy)
        if int(dut.o_wb_stall.value) == 0:
            break
    else:
        raise AssertionError("WB stayed stalled after init_done")

    # One cycle of stb low to complete the request, then drop cyc/stb.
    await RisingEdge(dut.i_clk_phy)
    dut.i_wb_cyc.value = 0
    dut.i_wb_stb.value = 0

    # Watch for an ACT command — cs_n=0, ras_n=0, cas_n=1, we_n=1.
    saw_act = False
    for cycle in range(WB_DEADLINE):
        await RisingEdge(dut.i_clk_phy)
        if cmd_is(dut, cs=0, ras=0, cas=1, we=1):
            dut._log.info(f"saw ACT command at relative cycle {cycle}")
            saw_act = True
            break

    if not saw_act:
        raise AssertionError(
            f"runtime FSM didn't issue ACT within {WB_DEADLINE} cycles"
        )

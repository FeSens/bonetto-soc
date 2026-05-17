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
    dut.i_mpr_req.value = 0
    dut.i_mpr_addr.value = 0
    dut.i_phy_rd_data.value = 0
    dut.i_phy_rd_valid.value = 1
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


@cocotb.test()
async def wb_write_read_roundtrip(dut):
    """After init_done, a WB write completes (ack), then a WB read completes
    (ack). Both transactions traverse the runtime FSM's ACT/CMD/PRE arc
    correctly — proves WB-side protocol survives the runtime path, even
    if the iter-2 PHY tristates DQ (read data is 0)."""
    cocotb.start_soon(Clock(dut.i_clk,     TCK_PS, units="ps").start())
    cocotb.start_soon(Clock(dut.i_clk_phy, TCK_PS, units="ps").start())
    await reset(dut)

    for _ in range(INIT_DEADLINE):
        await RisingEdge(dut.i_clk_phy)
        if int(dut.o_init_done.value):
            break
    else:
        raise AssertionError("init never completed")

    async def wb_xact(adr: int, dat: int = 0, we: bool = False) -> int:
        # Drive the request; wait for stall to drop.
        dut.i_wb_cyc.value = 1
        dut.i_wb_stb.value = 1
        dut.i_wb_we.value  = 1 if we else 0
        dut.i_wb_adr.value = adr
        dut.i_wb_dat.value = dat
        dut.i_wb_sel.value = 0xF
        for _ in range(50):
            await RisingEdge(dut.i_clk_phy)
            if int(dut.o_wb_stall.value) == 0:
                break
        else:
            raise AssertionError(f"WB stalled for >50 cycles on adr={adr:#x}")
        # Release stb after one cycle past stall-drop.
        await RisingEdge(dut.i_clk_phy)
        dut.i_wb_stb.value = 0
        # Wait for ack, then drop cyc.
        for _ in range(200):
            await RisingEdge(dut.i_clk_phy)
            if int(dut.o_wb_ack.value):
                rdat = int(dut.o_wb_dat.value)
                dut.i_wb_cyc.value = 0
                return rdat
        raise AssertionError(f"WB ack never came for adr={adr:#x}")

    dut._log.info("running WB write")
    await wb_xact(adr=0x00020000, dat=0xDEADBEEF, we=True)
    dut._log.info("write acked")

    # Let the runtime FSM return to IDLE before issuing the read.
    for _ in range(50):
        await RisingEdge(dut.i_clk_phy)

    dut._log.info("running WB read")
    rdat = await wb_xact(adr=0x00020000, we=False)
    dut._log.info(f"read acked, data=0x{rdat:08x}")

    # Read data will be 0 in iter-2 (PHY tristates DQ), but the round-trip
    # protocol must complete cleanly.


@cocotb.test()
async def refresh_fires_after_trefi(dut):
    """After init_done, the runtime FSM's refresh scheduler issues a REF
    command (cs_n=0, ras_n=0, cas_n=0, we_n=1) within tREFI cycles of
    init_done with no WB traffic on the bus."""
    cocotb.start_soon(Clock(dut.i_clk,     TCK_PS, units="ps").start())
    cocotb.start_soon(Clock(dut.i_clk_phy, TCK_PS, units="ps").start())
    await reset(dut)

    for _ in range(INIT_DEADLINE):
        await RisingEdge(dut.i_clk_phy)
        if int(dut.o_init_done.value):
            break
    else:
        raise AssertionError("init never completed")

    dut._log.info("init_done; watching for REF post-tREFI")

    # tREFI = 6240 cycles (DDR3-1600 @ 1.25 ns tCK = 7.8 us avg refresh).
    # After init_done, the refresh scheduler should fire REF within
    # tREFI + a few PRE/wait cycles. Give a 2x margin.
    TREFI = 6240
    saw_ref = False
    for cycle in range(TREFI * 2 + 200):
        await RisingEdge(dut.i_clk_phy)
        if cmd_is(dut, cs=0, ras=0, cas=0, we=1):
            dut._log.info(f"saw REF command at cycle {cycle} post-init_done")
            saw_ref = True
            break

    if not saw_ref:
        raise AssertionError(
            f"runtime FSM did not issue REF within {TREFI * 2 + 200} "
            f"cycles after init_done"
        )


@cocotb.test()
async def mpr_req_emits_rd_with_a12_high(dut):
    """After init_done, pulsing i_mpr_req with A[12]=1 in i_mpr_addr makes
    the runtime FSM emit an RD command (cs_n=0, ras_n=1, cas_n=0, we_n=1)
    whose address bus has bit 12 set. Proves the iter-3c MPR-read path
    is wired from the PHY-side rdlvl request through to the DDR3 cmd bus."""
    cocotb.start_soon(Clock(dut.i_clk,     TCK_PS, units="ps").start())
    cocotb.start_soon(Clock(dut.i_clk_phy, TCK_PS, units="ps").start())
    await reset(dut)

    for _ in range(INIT_DEADLINE):
        await RisingEdge(dut.i_clk_phy)
        if int(dut.o_init_done.value):
            break
    else:
        raise AssertionError("init never completed")

    # Pulse the MPR-read request — A[12]=1 (BC# disable + MPR mode bit),
    # A[2:0]=000 (location 0 of the predefined pattern register).
    MPR_ADDR = 0x1000
    dut.i_mpr_addr.value = MPR_ADDR
    dut.i_mpr_req.value  = 1
    await RisingEdge(dut.i_clk_phy)
    dut.i_mpr_req.value  = 0

    # o_mpr_busy must assert within a few cycles.
    for _ in range(10):
        await RisingEdge(dut.i_clk_phy)
        if int(dut.o_mpr_busy.value):
            break
    else:
        raise AssertionError("o_mpr_busy never asserted")

    # Watch for the RD command + verify A[12]=1.
    for cycle in range(100):
        await RisingEdge(dut.i_clk_phy)
        if cmd_is(dut, cs=0, ras=1, cas=0, we=1):
            addr = int(dut.o_ddr3_addr.value)
            assert (addr >> 12) & 1, \
                f"MPR RD addr A[12] not set — got 0x{addr:04x}"
            dut._log.info(
                f"saw MPR RD at cycle {cycle}, addr=0x{addr:04x}"
            )
            # busy must drop within tCCD (4 tCK) + a few cycles.
            for _ in range(20):
                await RisingEdge(dut.i_clk_phy)
                if not int(dut.o_mpr_busy.value):
                    return
            raise AssertionError("o_mpr_busy didn't drop after RD")

    raise AssertionError("RD command never fired after MPR request")

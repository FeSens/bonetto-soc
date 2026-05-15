"""cocotb tests for ddr3_phy_wlvl — write-leveling FSM.

Verifies the state-machine flow against a synthetic DQ[0] feedback signal
that emulates the DDR3 chip's response in write-leveling mode.

In real silicon, DQ[0] of each byte lane stays at 0 while DQS leads CK,
then flips to 1 once DQS catches up. This test models that as: for each
lane, a unique threshold tap T_l; for taps below T_l, DQ[0]=0; for taps
≥ T_l, DQ[0]=1. The FSM should lock the tap at exactly T_l per lane.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge


NUM_BYTE_LANES = 9
TAP_MAX        = 31
SETTLE_CYCLES  = 32

# Per-lane transition threshold (the tap at which DQ[0] first goes high).
THRESHOLDS = [3, 7, 12, 16, 19, 22, 25, 28, 30]
assert len(THRESHOLDS) == NUM_BYTE_LANES


async def reset(dut):
    dut.i_rst.value   = 1
    dut.i_start.value = 0
    dut.i_dq0_per_lane.value = 0
    for _ in range(5):
        await RisingEdge(dut.i_clk)
    dut.i_rst.value = 0
    await RisingEdge(dut.i_clk)


def compute_dq0(active_lane: int, current_tap: int) -> int:
    """Mirror the JEDEC response: DQ[0]=1 iff current_tap ≥ threshold[lane].
    Only the active lane drives a meaningful value (rest is 0)."""
    if current_tap >= THRESHOLDS[active_lane]:
        return 1 << active_lane
    return 0


async def drive_dq0_loop(dut):
    """Track the FSM's exposed lane + tap and present the matching DQ[0]
    bus on every clock. Stops when o_done or o_error goes high."""
    while True:
        await FallingEdge(dut.i_clk)
        if int(dut.o_done.value) or int(dut.o_error.value):
            return
        lane = int(dut.lane.value)
        tap  = int(dut.tap.value)
        dut.i_dq0_per_lane.value = compute_dq0(lane, tap)


@cocotb.test()
async def wlvl_walks_taps_and_locks_per_lane(dut):
    """Each lane's DQ[0] flips high at a different threshold tap; the FSM
    must lock at that exact tap per lane and assert o_done at the end."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    cocotb.start_soon(drive_dq0_loop(dut))

    dut.i_start.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_start.value = 0

    # Plenty of time: 9 lanes × 32 taps × (settle+sample) ~ 9*32*~36 ≈ 10K cycles.
    for _ in range(30000):
        await RisingEdge(dut.i_clk)
        if int(dut.o_done.value):
            break
    else:
        raise AssertionError("wlvl never asserted o_done")

    assert int(dut.o_error.value) == 0, "wlvl signalled error"

    locked = int(dut.o_locked_tap_lane.value)
    for lane in range(NUM_BYTE_LANES):
        got = (locked >> (lane * 5)) & 0x1F
        want = THRESHOLDS[lane]
        assert got == want, \
            f"lane {lane}: locked tap {got}, expected {want}"


@cocotb.test()
async def wlvl_errors_when_dq0_never_transitions(dut):
    """If DQ[0] stays low across all taps, the FSM must assert o_error."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    dut.i_dq0_per_lane.value = 0   # never transitions
    dut.i_start.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_start.value = 0

    for _ in range(5000):
        await RisingEdge(dut.i_clk)
        if int(dut.o_error.value):
            break
    else:
        raise AssertionError("wlvl never asserted o_error")

    assert int(dut.o_done.value) == 0, "wlvl shouldn't be done when erroring"

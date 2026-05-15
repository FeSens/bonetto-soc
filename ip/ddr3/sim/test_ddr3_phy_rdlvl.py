"""cocotb tests for ddr3_phy_rdlvl — MPR-based read-leveling FSM.

For each MPR read request, the test driver checks whether the FSM's
currently-being-trained lane is inside a synthetic per-lane pass window
of IDELAYE2 taps. If so, return EXPECTED_PATTERN on that lane slot; if
not, return an anti-pattern that won't match.

The FSM should converge on the geometric centre of the longest
contiguous pass run per lane.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


NUM_BYTE_LANES   = 9
DQ_BITS          = 8
RATIO            = 4
TAP_MAX          = 31
EXPECTED_PATTERN = 0xAAAAAAAA   # 8'hAA × 4 — per-lane 32-bit slot
LANE_WIDTH       = DQ_BITS * RATIO       # 32 bits per lane

# Per-lane (start_tap, end_tap_inclusive) pass windows. Centre target:
# start + (len-1) // 2  (Verilog FSM uses (start + len/2) — len/2 in
# integer arithmetic floors, matching Python `len // 2`).
PASS_WINDOWS = [
    ( 8, 20),
    ( 4, 12),
    (15, 25),
    ( 0,  6),
    (10, 14),
    (20, 31),
    ( 6, 18),
    (11, 22),
    (25, 30),
]
assert len(PASS_WINDOWS) == NUM_BYTE_LANES


def expected_centre(start: int, end_inclusive: int) -> int:
    """The FSM's centre = best_start + (best_len >> 1).
    best_len = end - start + 1.  Integer floor."""
    length = end_inclusive - start + 1
    return start + (length >> 1)


async def reset(dut):
    dut.i_rst.value             = 1
    dut.i_start.value           = 0
    dut.i_rd_data.value         = 0
    dut.i_rd_data_valid.value   = 0
    for _ in range(5):
        await RisingEdge(dut.i_clk)
    dut.i_rst.value = 0
    await RisingEdge(dut.i_clk)


def per_lane_pass(lane: int, tap: int) -> bool:
    s, e = PASS_WINDOWS[lane]
    return s <= tap <= e


async def mpr_responder(dut):
    """Watch for o_mpr_read_req pulses; respond with i_rd_data_valid
    plus a per-lane data payload matching the pass/fail policy.
    Stops on done/error."""
    while True:
        await RisingEdge(dut.i_clk)
        if int(dut.o_done.value) or int(dut.o_error.value):
            return

        if int(dut.o_mpr_read_req.value):
            # FSM issues mpr_read_req at S_ISSUE_READ; wait a few cycles
            # then drive valid + data. The exact latency only needs to
            # be less than READ_LATENCY (=32 cycles default).
            for _ in range(5):
                await RisingEdge(dut.i_clk)

            cur_lane = int(dut.lane.value)
            cur_tap  = int(dut.tap.value)

            payload = 0
            for lane in range(NUM_BYTE_LANES):
                if lane == cur_lane:
                    slot = EXPECTED_PATTERN if per_lane_pass(cur_lane, cur_tap) \
                                            else 0xDEADBEEF
                else:
                    slot = EXPECTED_PATTERN
                payload |= (slot & ((1 << LANE_WIDTH) - 1)) << (lane * LANE_WIDTH)

            dut.i_rd_data.value       = payload
            dut.i_rd_data_valid.value = 1
            await RisingEdge(dut.i_clk)
            dut.i_rd_data_valid.value = 0


@cocotb.test()
async def rdlvl_finds_centre_per_lane(dut):
    """For each lane, FSM picks the centre of the synthetic pass window."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    cocotb.start_soon(mpr_responder(dut))

    dut.i_start.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_start.value = 0

    # 9 lanes × 32 taps × ~50 cycles per tap ≈ 15K cycles. Be generous.
    for _ in range(80000):
        await RisingEdge(dut.i_clk)
        if int(dut.o_done.value):
            break
    else:
        raise AssertionError("rdlvl never asserted o_done")

    assert int(dut.o_error.value) == 0, "rdlvl signalled error"

    locked = int(dut.o_locked_tap_lane.value)
    for lane in range(NUM_BYTE_LANES):
        got = (locked >> (lane * 5)) & 0x1F
        s, e = PASS_WINDOWS[lane]
        want = expected_centre(s, e)
        assert got == want, \
            f"lane {lane} window {s}..{e}: locked tap {got}, expected centre {want}"


@cocotb.test()
async def rdlvl_errors_when_no_pass_window(dut):
    """If every MPR read returns the wrong pattern, the FSM should
    bail out with o_error since no contiguous pass run exists."""
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    await reset(dut)

    async def always_fail(dut):
        while True:
            await RisingEdge(dut.i_clk)
            if int(dut.o_done.value) or int(dut.o_error.value):
                return
            if int(dut.o_mpr_read_req.value):
                for _ in range(5):
                    await RisingEdge(dut.i_clk)
                dut.i_rd_data.value       = 0   # never matches 0xAA pattern
                dut.i_rd_data_valid.value = 1
                await RisingEdge(dut.i_clk)
                dut.i_rd_data_valid.value = 0

    cocotb.start_soon(always_fail(dut))

    dut.i_start.value = 1
    await RisingEdge(dut.i_clk)
    dut.i_start.value = 0

    for _ in range(20000):
        await RisingEdge(dut.i_clk)
        if int(dut.o_error.value):
            break
    else:
        raise AssertionError("rdlvl never errored despite no pass window")

    assert int(dut.o_done.value) == 0, "rdlvl reported done despite error"

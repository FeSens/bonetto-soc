"""cocotb test for bringup_status_led.

Validates the priority encoder + LED bit mapping ({yellow, green, red}
maps to o_led[2:0]). Uses small TICK_W + small bit positions via the
Makefile parameter overrides so blink-rate cycles fit in tens of ticks.

LED bit map (per constraints/ypcb-00338.xdc):
    o_led[0] = red
    o_led[1] = green
    o_led[2] = yellow
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


def red(led):    return (led >> 0) & 1
def green(led):  return (led >> 1) & 1
def yellow(led): return (led >> 2) & 1


async def reset_and_clock(dut):
    cocotb.start_soon(Clock(dut.i_clk_50, 20, units="ns").start())
    # Drive all inputs to "happy DDR3-running" then override per-test.
    dut.i_por_active.value    = 0
    dut.i_mmcm_locked.value   = 1
    dut.i_clk_sys_alive.value = 1
    dut.i_init_done.value     = 1
    dut.i_init_error.value    = 0
    dut.i_cal_done.value      = 1
    dut.i_cal_error.value     = 0
    dut.i_mtest_any_err.value = 0
    dut.i_mtest_target.value  = 1
    await RisingEdge(dut.i_clk_50)
    await RisingEdge(dut.i_clk_50)


async def observe_one_full_blink_cycle(dut, slow_bit):
    """Run for 2 * 2^(slow_bit+1) cycles so we sample both halves of slow_blink."""
    n = 2 << (slow_bit + 1)
    obs = []
    for _ in range(n):
        await RisingEdge(dut.i_clk_50)
        obs.append(int(dut.o_led.value))
    return obs


@cocotb.test()
async def por_all_off(dut):
    await reset_and_clock(dut)
    dut.i_por_active.value = 1
    await RisingEdge(dut.i_clk_50)
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    # POR active: all LEDs always off.
    for v in obs:
        assert v == 0, f"POR: led was {v:03b}, expected 000"


@cocotb.test()
async def mmcm_unlocked_red_only(dut):
    await reset_and_clock(dut)
    dut.i_mmcm_locked.value = 0
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    # red toggles, green + yellow always 0.
    saw_red_high = saw_red_low = False
    for v in obs:
        assert green(v) == 0, f"!mmcm_locked: green should be 0, led={v:03b}"
        assert yellow(v) == 0, f"!mmcm_locked: yellow should be 0, led={v:03b}"
        if red(v): saw_red_high = True
        else: saw_red_low = True
    assert saw_red_high and saw_red_low, "red should toggle"


@cocotb.test()
async def mmcm_locked_clksys_dead_red_green_alternate(dut):
    """iter-13 state: mmcm_locked=1 but clk_sys_alive=0."""
    await reset_and_clock(dut)
    dut.i_clk_sys_alive.value = 0
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    # red toggles, green is inverted-red, yellow always 0.
    for v in obs:
        assert yellow(v) == 0, f"!clk_sys: yellow should be 0, led={v:03b}"
        assert red(v) != green(v), \
            f"!clk_sys: red and green should be inverted, led={v:03b}"


@cocotb.test()
async def init_error_red_solid_yellow_blink(dut):
    await reset_and_clock(dut)
    dut.i_init_done.value  = 0
    dut.i_init_error.value = 1
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    saw_yel_high = saw_yel_low = False
    for v in obs:
        assert red(v) == 1, f"init_error: red should be solid, led={v:03b}"
        assert green(v) == 0
        if yellow(v): saw_yel_high = True
        else: saw_yel_low = True
    assert saw_yel_high and saw_yel_low, "yellow should toggle"


@cocotb.test()
async def cal_error_yellow_solid_green_blink(dut):
    await reset_and_clock(dut)
    dut.i_cal_done.value  = 0
    dut.i_cal_error.value = 1
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    saw_g_high = saw_g_low = False
    for v in obs:
        assert yellow(v) == 1, f"cal_error: yellow should be solid, led={v:03b}"
        assert red(v) == 0
        if green(v): saw_g_high = True
        else: saw_g_low = True
    assert saw_g_high and saw_g_low, "green should toggle"


@cocotb.test()
async def init_inprogress_yellow_only(dut):
    await reset_and_clock(dut)
    dut.i_init_done.value = 0
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    for v in obs:
        assert red(v) == 0
        assert green(v) == 0
    saw_y_high = saw_y_low = False
    for v in obs:
        if yellow(v): saw_y_high = True
        else: saw_y_low = True
    assert saw_y_high and saw_y_low, "yellow should toggle slow"


@cocotb.test()
async def cal_inprogress_yellow_solid_green_blink(dut):
    await reset_and_clock(dut)
    dut.i_cal_done.value = 0
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    saw_g_high = saw_g_low = False
    for v in obs:
        assert yellow(v) == 1, f"!cal_done: yellow should be solid, led={v:03b}"
        assert red(v) == 0
        if green(v): saw_g_high = True
        else: saw_g_low = True
    assert saw_g_high and saw_g_low


@cocotb.test()
async def memtest_bram_green_blink(dut):
    await reset_and_clock(dut)
    dut.i_mtest_target.value = 0  # BRAM phase
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    for v in obs:
        assert red(v) == 0
        assert yellow(v) == 0
    saw_g_high = saw_g_low = False
    for v in obs:
        if green(v): saw_g_high = True
        else: saw_g_low = True
    assert saw_g_high and saw_g_low


@cocotb.test()
async def memtest_ddr3_green_solid_yellow_heartbeat(dut):
    await reset_and_clock(dut)
    dut.i_mtest_target.value = 1  # DDR3 phase, all good
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    for v in obs:
        assert red(v) == 0, f"DDR3 happy: red should be 0, led={v:03b}"
        assert green(v) == 1, f"DDR3 happy: green should be solid, led={v:03b}"


@cocotb.test()
async def priority_init_error_beats_cal_error(dut):
    """If both init_error AND cal_error are set, init_error wins."""
    await reset_and_clock(dut)
    dut.i_init_done.value  = 0
    dut.i_init_error.value = 1
    dut.i_cal_error.value  = 1
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    # init_error pattern: red solid, yellow fast blink, green 0
    for v in obs:
        assert red(v) == 1
        assert green(v) == 0


@cocotb.test()
async def priority_mmcm_beats_everything(dut):
    await reset_and_clock(dut)
    dut.i_mmcm_locked.value = 0
    dut.i_init_done.value   = 0
    dut.i_init_error.value  = 1
    dut.i_cal_error.value   = 1
    dut.i_mtest_any_err.value = 1
    await RisingEdge(dut.i_clk_50)
    obs = await observe_one_full_blink_cycle(dut, slow_bit=4)
    # !mmcm_locked pattern: only red blinks.
    for v in obs:
        assert green(v) == 0
        assert yellow(v) == 0

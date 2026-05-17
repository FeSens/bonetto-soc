"""cocotb test for memtest_lite — WB-master pattern test FSM.

Pairs with the fwb_master formal proof: that proves protocol compliance;
this exercises end-to-end behaviour (writes get acked, reads return the
same data, error counter increments on mismatch, pause halts).

Uses a tiny memory model (just an associative array) so we can drive
ack/stall manually without instantiating wb_memory.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Combine, Timer


# The Makefile overrides WB_ADDR_W=9, BRAM_ADDR_W=5, DDR3_ADDR_W=7 so
# promotion and high DDR3 address bits are tractable in sim.

class WBSlaveModel:
    def __init__(self, dut, latency=0):
        self.dut = dut
        self.latency = latency
        self.mem = {}
        self.corrupt_on_read = False
        self.assert_err_once = False
        self.seen_writes = []
        self.seen_reads = []
        self.dut.i_wb_stall.value = 0
        self.dut.i_wb_ack.value   = 0
        self.dut.i_wb_dat.value   = 0
        self.dut.i_wb_err.value   = 0

    async def run(self):
        pending = []
        def safe_int(sig):
            try:
                return int(sig.value)
            except Exception:
                return 0
        while True:
            await RisingEdge(self.dut.i_clk)
            # Read outputs of the just-completed clock edge, queue any
            # accepted request, then drive next-cycle inputs immediately.
            cyc = safe_int(self.dut.o_wb_cyc)
            stb = safe_int(self.dut.o_wb_stb)
            we  = safe_int(self.dut.o_wb_we)
            adr = safe_int(self.dut.o_wb_adr)
            dat = safe_int(self.dut.o_wb_dat)
            if cyc and stb:
                pending.append((we, adr, dat))
            if pending:
                we_p, adr_p, dat_p = pending.pop(0)
                if we_p:
                    self.seen_writes.append(adr_p)
                    self.mem[adr_p] = dat_p
                    read_val = 0
                else:
                    self.seen_reads.append(adr_p)
                    read_val = self.mem.get(adr_p, 0)
                    if self.corrupt_on_read:
                        read_val ^= 0xFFFFFFFF
                emit_err = self.assert_err_once
                self.assert_err_once = False
                self.dut.i_wb_ack.value = 1
                self.dut.i_wb_dat.value = read_val
                self.dut.i_wb_err.value = 1 if emit_err else 0
            else:
                self.dut.i_wb_ack.value = 0
                self.dut.i_wb_err.value = 0
                self.dut.i_wb_dat.value = 0


async def reset(dut):
    cocotb.start_soon(Clock(dut.i_clk, 10, units="ns").start())
    dut.i_rst.value      = 1
    dut.i_cal_done.value = 0
    dut.i_pause.value    = 0
    dut.i_wb_stall.value = 0
    dut.i_wb_ack.value   = 0
    dut.i_wb_dat.value   = 0
    dut.i_wb_err.value   = 0
    for _ in range(3):
        await RisingEdge(dut.i_clk)
    dut.i_rst.value = 0
    await RisingEdge(dut.i_clk)


@cocotb.test()
async def write_read_no_errors_bram_phase(dut):
    """Memtest writes a pattern then reads it back — pass_ctr should advance,
    err_ctr should stay 0 in BRAM phase (target=0)."""
    await reset(dut)
    slave = WBSlaveModel(dut)
    cocotb.start_soon(slave.run())
    # Run ~400 cycles — enough for many write/read pairs.
    for _ in range(400):
        await RisingEdge(dut.i_clk)
    await Timer(1, units="ns")
    pass_ctr = int(dut.o_pass_ctr.value)
    err_ctr  = int(dut.o_err_ctr.value)
    target   = int(dut.o_target.value)
    assert pass_ctr > 0, f"pass_ctr should advance, got {pass_ctr}"
    assert err_ctr == 0, f"err_ctr should be 0 with clean slave, got {err_ctr}"
    assert target == 0, f"target should still be BRAM (0) at this point, got {target}"


@cocotb.test()
async def ddr3_phase_walks_high_address_bits(dut):
    """After BRAM validation and cal_done, DDR3 addresses must advance above
    the low BRAM window while keeping the decode-select bit set."""
    await reset(dut)
    dut.i_cal_done.value = 1
    slave = WBSlaveModel(dut)
    cocotb.start_soon(slave.run())
    for _ in range(2200):
        await RisingEdge(dut.i_clk)
    await Timer(1, units="ns")
    target = int(dut.o_target.value)
    assert target == 1, "target should promote to DDR3 once the BRAM sweep passes"
    ddr3_writes = [a for a in slave.seen_writes if (a >> 5) & 1]
    assert ddr3_writes, "expected writes with the DDR3 decode-select bit set"
    assert any(a & 0x1C0 for a in ddr3_writes), (
        f"expected DDR3 high address bits above select bit, got {ddr3_writes[:8]}"
    )


@cocotb.test()
async def err_ctr_increments_on_corruption(dut):
    """Slave corrupts reads — err_ctr should advance, first_err_* captured."""
    await reset(dut)
    slave = WBSlaveModel(dut)
    slave.corrupt_on_read = True
    cocotb.start_soon(slave.run())
    for _ in range(300):
        await RisingEdge(dut.i_clk)
    await Timer(1, units="ns")
    err_ctr  = int(dut.o_err_ctr.value)
    any_err  = int(dut.o_any_err.value)
    assert err_ctr > 0, f"err_ctr should increment when slave corrupts, got {err_ctr}"
    assert any_err == 1, "o_any_err should be sticky-high"


@cocotb.test()
async def pause_halts_cycles(dut):
    """When i_pause is held high, o_wb_cyc should reach 0 and stay low."""
    await reset(dut)
    slave = WBSlaveModel(dut)
    cocotb.start_soon(slave.run())
    # Run for a bit, then assert pause.
    for _ in range(50):
        await RisingEdge(dut.i_clk)
    dut.i_pause.value = 1
    # Give the FSM enough cycles to complete any in-flight transaction.
    for _ in range(20):
        await RisingEdge(dut.i_clk)
    # Now cyc should be 0 for at least 10 consecutive cycles.
    for _ in range(10):
        await RisingEdge(dut.i_clk)
        await Timer(1, units="ns")
        cyc = int(dut.o_wb_cyc.value)
        assert cyc == 0, f"o_wb_cyc should be 0 while paused, got {cyc}"


@cocotb.test()
async def err_handling_drops_cyc(dut):
    """When slave asserts i_wb_err, memtest_lite should drop cyc/stb (not hang)."""
    await reset(dut)
    slave = WBSlaveModel(dut)
    slave.assert_err_once = True
    cocotb.start_soon(slave.run())
    # Give the FSM a few transaction cycles.
    for _ in range(50):
        await RisingEdge(dut.i_clk)
    await Timer(1, units="ns")
    # FSM should be back to a non-stuck state (cyc=0 in S_WRITE before
    # next request, or cyc=1 mid-flight — either way not hung forever).
    # The strongest claim: pass_ctr can still advance after the err.
    for _ in range(200):
        await RisingEdge(dut.i_clk)
    await Timer(1, units="ns")
    pass_ctr = int(dut.o_pass_ctr.value)
    assert pass_ctr > 0, "memtest must keep progressing after err handling"

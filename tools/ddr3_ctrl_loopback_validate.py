#!/usr/bin/env python3
"""Validate the DDR3 controller-loopback image over XVC/USER1 JTAG.

This is an intermediate hardware gate. It proves the live JTAG/Wishbone path,
dual-channel clean DDR3 controller, scheduler, and BL8 line packetizer in FPGA
fabric. It does not validate external DDR3 DQ/DQS timing because the loopback
image keeps those pins high-Z.
"""

import argparse
import pathlib
import random
import sys
import time


sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

from jtag_uart_read import (  # noqa: E402
    JWB_CMD_RESUME,
    XVC,
    decode_status_flags,
    jwb_cmd,
    jwb_wb_read,
    jwb_wb_write,
    read_status_reg,
    select_user1,
    tap_reset_to_rti,
)


VERSION = 0xB07E0D81
DDR3_SELECT = 0x4000
DDR3_LOCAL_MASK = 0x3FFF
CH1_BIT = 1 << 29


def require(cond, msg):
    if not cond:
        raise RuntimeError(msg)


def mix32(x):
    x &= 0xFFFFFFFF
    x ^= x >> 16
    x = (x * 0x7FEB352D) & 0xFFFFFFFF
    x ^= x >> 15
    x = (x * 0x846CA68B) & 0xFFFFFFFF
    x ^= x >> 16
    return x & 0xFFFFFFFF


def ddr3_addr_parts(word_addr):
    return DDR3_SELECT | (word_addr & DDR3_LOCAL_MASK), (word_addr >> 14) & 0xFFFF


def ddr3_write(xvc, word_addr, data):
    local, hi = ddr3_addr_parts(word_addr)
    st = jwb_wb_write(xvc, local, data, hi)
    require(((st >> 2) & 1) == 1,
            f"write addr=0x{word_addr:08x} did not ack: status=0x{st:08x}")
    require(((st >> 1) & 1) == 0,
            f"write addr=0x{word_addr:08x} reported err: status=0x{st:08x}")


def ddr3_read(xvc, word_addr):
    local, hi = ddr3_addr_parts(word_addr)
    return jwb_wb_read(xvc, local, hi)


def check_cases(xvc, name, cases):
    expected_by_addr = {}
    for addr, data in cases:
        expected_by_addr[addr] = data & 0xFFFFFFFF
        ddr3_write(xvc, addr, data)

    for addr, expected in expected_by_addr.items():
        got = ddr3_read(xvc, addr)
        if got != expected:
            raise RuntimeError(
                f"{name}: addr=0x{addr:08x} got=0x{got:08x} "
                f"expected=0x{expected:08x}")

    print(f"{name}: PASS cases={len(expected_by_addr)}")


def bram_sanity(xvc):
    cases = [
        (0x0000, 0x13579BDF),
        (0x0001, 0x2468ACE0),
        (0x0010, 0xA5A55A5A),
        (0x3FFF, 0x0BADF00D),
    ]
    for addr, data in cases:
        st = jwb_wb_write(xvc, addr, data)
        require(((st >> 2) & 1) == 1,
                f"BRAM write addr=0x{addr:04x} did not ack: status=0x{st:08x}")
        require(((st >> 1) & 1) == 0,
                f"BRAM write addr=0x{addr:04x} reported err: status=0x{st:08x}")
    for addr, expected in cases:
        got = jwb_wb_read(xvc, addr)
        require(got == expected,
                f"BRAM addr=0x{addr:04x} got=0x{got:08x} expected=0x{expected:08x}")
    print(f"bram_sanity: PASS cases={len(cases)}")


def deterministic_cases():
    cases = []
    offsets = [
        0x0000, 0x0001, 0x0002, 0x000F,
        0x0010, 0x0011, 0x00FE, 0x00FF,
        0x0100, 0x0101, 0x07F0, 0x07FF,
        0x0FF0, 0x0FFF,
    ]
    for channel, base in enumerate([0, CH1_BIT]):
        for i, off in enumerate(offsets):
            cases.append((base | off, mix32((channel << 24) ^ off ^ i)))
    return cases


def same_line_cases():
    cases = []
    for channel, base in enumerate([0, CH1_BIT]):
        line_base = base | 0x0180
        for word in range(16):
            addr = line_base | word
            cases.append((addr, mix32(0x5A110000 ^ (channel << 20) ^ word)))
    return cases


def random_cases(count, seed):
    rng = random.Random(seed)
    cases = []
    used = set()
    while len(cases) < count:
        channel = rng.randrange(0, 2)
        word = rng.randrange(0, 4096)
        addr = (CH1_BIT if channel else 0) | word
        if addr in used:
            continue
        used.add(addr)
        cases.append((addr, mix32(addr ^ rng.getrandbits(32))))
    return cases


def wait_for_loopback_ready(xvc, timeout_s=2.0):
    deadline = time.monotonic() + timeout_s
    last = None
    while True:
        status = read_status_reg(xvc, 0x00)
        state = read_status_reg(xvc, 0x01)
        last = status, state
        cal_done = (status >> 15) & 1
        init_done = (status >> 11) & 1
        reset_active = (status >> 3) & 1
        if cal_done and init_done and not reset_active:
            return status, state
        if time.monotonic() >= deadline:
            return last
        time.sleep(0.02)


def validate(args):
    xvc = XVC(args.host, args.port)
    try:
        print(f"connected to {args.host}:{args.port} - {xvc.info}")
        if args.tck_ns is not None:
            actual = xvc.settck(args.tck_ns)
            print(f"settck({args.tck_ns} ns) -> {actual} ns")

        tap_reset_to_rti(xvc)
        select_user1(xvc)

        version = read_status_reg(xvc, 0xFE)
        status, state = wait_for_loopback_ready(xvc)
        clk_sys = read_status_reg(xvc, 0x15)
        clk_ddr = read_status_reg(xvc, 0x16)
        clk_dq = read_status_reg(xvc, 0x17)
        clk_ref = read_status_reg(xvc, 0x18)

        print(f"version=0x{version:08x}")
        print(f"status=0x{status:08x} {decode_status_flags(status)}")
        print(f"state=0x{state:08x}")
        print(f"clk_sys=0x{clk_sys:08x} clk_ddr=0x{clk_ddr:08x} "
              f"clk_dq=0x{clk_dq:08x} clk_ref=0x{clk_ref:08x}")

        require(version == VERSION,
                f"expected controller-loopback version 0x{VERSION:08x}, got 0x{version:08x}")
        require((status >> 16) == 0xB07E,
                f"status magic mismatch: 0x{status:08x}")
        require(((status >> 15) & 1) == 1, "loopback cal_done is not asserted")
        require(((status >> 14) & 1) == 0, "loopback cal_error is asserted")
        require(((status >> 11) & 1) == 1, "DDR3 init_done is not asserted")
        require(((status >> 10) & 1) == 0, "DDR3 init_error is asserted")
        require(((status >> 5) & 1) == 1, "DDR3 PLL is not locked")
        require(((status >> 3) & 1) == 0, "controller reset is still active")

        bram_sanity(xvc)
        check_cases(xvc, "dual_channel_boundary_patterns", deterministic_cases())
        check_cases(xvc, "same_line_partial_writes", same_line_cases())
        check_cases(xvc, "randomized_dual_channel_loopback",
                    random_cases(args.random_count, args.random_seed))

        ch0_wr = read_status_reg(xvc, 0x20)
        ch1_wr = read_status_reg(xvc, 0x21)
        ch0_rd = read_status_reg(xvc, 0x22)
        ch1_rd = read_status_reg(xvc, 0x23)
        last0 = read_status_reg(xvc, 0x24)
        last1 = read_status_reg(xvc, 0x25)
        final_status = read_status_reg(xvc, 0x10)
        print(f"loop_counts ch0_wr={ch0_wr} ch1_wr={ch1_wr} "
              f"ch0_rd={ch0_rd} ch1_rd={ch1_rd}")
        print(f"last_lines ch0=0x{last0:08x} ch1=0x{last1:08x}")
        print(f"final_jwb_status=0x{final_status:08x}")

        require(ch0_wr > 0 and ch1_wr > 0 and ch0_rd > 0 and ch1_rd > 0,
                "loopback did not exercise both channels")
        require(((final_status >> 3) & 1) == 0,
                f"JWB is still busy: 0x{final_status:08x}")
        require(((final_status >> 2) & 1) == 1,
                f"last JWB operation did not ack: 0x{final_status:08x}")
        require(((final_status >> 1) & 1) == 0,
                f"last JWB operation reported err: 0x{final_status:08x}")

        if args.resume:
            jwb_cmd(xvc, JWB_CMD_RESUME)

        print("DDR3_CTRL_LOOPBACK_VALIDATE_SUMMARY ok=1")
    finally:
        xvc.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="localhost")
    parser.add_argument("--port", type=int, default=3721)
    parser.add_argument("--tck-ns", type=int, default=2000)
    parser.add_argument("--random-count", type=int, default=128)
    parser.add_argument("--random-seed", type=lambda s: int(s, 0),
                        default=0xD3D38101)
    parser.add_argument("--resume", action="store_true")
    args = parser.parse_args()
    validate(args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

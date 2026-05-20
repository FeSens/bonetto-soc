#!/usr/bin/env python3
"""Debug-check the DDR3 PHY-clock timing-probe image over XVC/USER1 JTAG.

This gate keeps the line-lane PHY and pin-pair probe in the generated DQ clock
domain behind a dual-clock bridge. The probe intentionally stores only the most
recent line per channel, so this validator uses immediate write/read cases. Use
ddr3_ctrl_loopback_validate.py on the same-clock loopback gates for persistent
multi-address memory semantics.

This is not a DDR3-800 hardware signoff validator unless the corresponding
image meets route timing. The board Makefile refuses to program it by default
because the current soft PHY-clock probe does not meet the 400 MHz clk_dq target.
"""

import argparse
import pathlib
import random
import sys
import time


sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

from ddr3_ctrl_loopback_validate import (  # noqa: E402
    CH1_BIT,
    bram_sanity,
    ddr3_read,
    ddr3_write,
    mix32,
    require,
    wait_for_loopback_ready,
)
from jtag_uart_read import (  # noqa: E402
    JWB_CMD_RESUME,
    XVC,
    decode_status_flags,
    jwb_cmd,
    read_status_reg,
    select_user1,
    tap_reset_to_rti,
)


VERSION = 0xB07E0D88


def immediate_cases():
    cases = []
    offsets = [
        0x0000, 0x0001, 0x0002, 0x000F,
        0x0010, 0x0011, 0x00FE, 0x00FF,
        0x0100, 0x0101, 0x07F0, 0x07FF,
        0x0FF0, 0x0FFF,
    ]
    for channel, base in enumerate([0, CH1_BIT]):
        for i, off in enumerate(offsets):
            cases.append((base | off, mix32(0x88000000 ^
                                            (channel << 24) ^ off ^ i)))
    return cases


def check_immediate_cases(xvc, name, cases):
    for addr, expected in cases:
        ddr3_write(xvc, addr, expected)
        got = ddr3_read(xvc, addr)
        if got != expected:
            raise RuntimeError(
                f"{name}: addr=0x{addr:08x} got=0x{got:08x} "
                f"expected=0x{expected:08x}")
    print(f"{name}: PASS cases={len(cases)}")


def same_line_cases(xvc):
    total = 0
    for channel, base in enumerate([0, CH1_BIT]):
        expected_by_addr = {}
        line_base = base | 0x0180
        for word in range(16):
            addr = line_base | word
            expected = mix32(0x5A880000 ^ (channel << 20) ^ word)
            expected_by_addr[addr] = expected
            ddr3_write(xvc, addr, expected)

        for addr, expected in expected_by_addr.items():
            got = ddr3_read(xvc, addr)
            if got != expected:
                raise RuntimeError(
                    f"same_line_lastline_cache: addr=0x{addr:08x} "
                    f"got=0x{got:08x} expected=0x{expected:08x}")
        total += len(expected_by_addr)

    print(f"same_line_lastline_cache: PASS cases={total}")


def byte_select_cases(xvc):
    cases = [
        (0x00000220, 0x11223344, 0xAABBCCDD, 0x5, 0x11BB33DD),
        (0x00000221, 0x55667788, 0x01020304, 0xA, 0x01660388),
        (CH1_BIT | 0x00000220, 0x89ABCDEF, 0x13579BDF, 0x3, 0x89AB9BDF),
        (CH1_BIT | 0x00000221, 0x76543210, 0xCAFEBABE, 0xC, 0xCAFE3210),
    ]
    for addr, initial, partial, sel, expected in cases:
        ddr3_write(xvc, addr, initial)
        ddr3_write(xvc, addr, partial, sel=sel)
        got = ddr3_read(xvc, addr)
        if got != expected:
            raise RuntimeError(
                f"byte_select_lastline_cache: addr=0x{addr:08x} "
                f"sel=0x{sel:x} got=0x{got:08x} expected=0x{expected:08x}")

    print(f"byte_select_lastline_cache: PASS cases={len(cases)}")


def random_immediate_cases(count, seed):
    rng = random.Random(seed)
    cases = []
    for _ in range(count):
        channel = rng.randrange(0, 2)
        word = rng.randrange(0, 4096)
        addr = (CH1_BIT if channel else 0) | word
        cases.append((addr, mix32(0xD1880000 ^ addr ^ rng.getrandbits(32))))
    return cases


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

        require(version == args.expected_version,
                f"expected {args.gate_name} version "
                f"0x{args.expected_version:08x}, got 0x{version:08x}")
        require((status >> 16) == 0xB07E,
                f"status magic mismatch: 0x{status:08x}")
        require(((status >> 15) & 1) == 1, "probe cal_done is not asserted")
        require(((status >> 14) & 1) == 0, "probe cal_error is asserted")
        require(((status >> 11) & 1) == 1, "DDR3 init_done is not asserted")
        require(((status >> 10) & 1) == 0, "DDR3 init_error is asserted")
        require(((status >> 5) & 1) == 1, "DDR3 PLL is not locked")
        require(((status >> 3) & 1) == 0, "controller reset is still active")

        bram_sanity(xvc)
        check_immediate_cases(xvc, "immediate_dual_channel_patterns",
                              immediate_cases())
        same_line_cases(xvc)
        byte_select_cases(xvc)
        check_immediate_cases(xvc, "randomized_immediate_phyclk_probe",
                              random_immediate_cases(args.random_count,
                                                     args.random_seed))

        time.sleep(0.02)
        ch0_wr = read_status_reg(xvc, 0x20)
        ch1_wr = read_status_reg(xvc, 0x21)
        ch0_rd = read_status_reg(xvc, 0x22)
        ch1_rd = read_status_reg(xvc, 0x23)
        config = read_status_reg(xvc, 0x04)
        final_status = read_status_reg(xvc, 0x10)
        print(f"config=0x{config:08x}")
        print(f"probe_counts ch0_wr={ch0_wr} ch1_wr={ch1_wr} "
              f"ch0_rd={ch0_rd} ch1_rd={ch1_rd}")
        print(f"final_jwb_status=0x{final_status:08x}")

        require((config & 0x10) != 0,
                f"expected pinpair timing probe config bit: 0x{config:08x}")
        require(ch0_wr > 0 and ch1_wr > 0 and ch0_rd > 0 and ch1_rd > 0,
                "probe did not exercise both channels")
        require(((final_status >> 3) & 1) == 0,
                f"JWB is still busy: 0x{final_status:08x}")
        require(((final_status >> 2) & 1) == 1,
                f"last JWB operation did not ack: 0x{final_status:08x}")
        require(((final_status >> 1) & 1) == 0,
                f"last JWB operation reported err: 0x{final_status:08x}")

        if args.resume:
            jwb_cmd(xvc, JWB_CMD_RESUME)

        print(f"{args.gate_name}_VALIDATE_SUMMARY ok=1")
    finally:
        xvc.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="localhost")
    parser.add_argument("--port", type=int, default=3721)
    parser.add_argument("--tck-ns", type=int, default=2000)
    parser.add_argument("--random-count", type=int, default=64)
    parser.add_argument("--random-seed", type=lambda s: int(s, 0),
                        default=0xD3D38801)
    parser.add_argument("--resume", action="store_true")
    parser.add_argument("--expected-version", type=lambda s: int(s, 0),
                        default=VERSION)
    parser.add_argument("--gate-name", default="DDR3_CTRL_LINE_PHYCLKLOOP")
    args = parser.parse_args()
    validate(args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

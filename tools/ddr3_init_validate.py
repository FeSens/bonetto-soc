#!/usr/bin/env python3
"""Validate a DDR3-800 init/status image over XVC/USER1 JTAG.

This is intentionally narrower than full DDR3 memory validation. It checks the
selected image version, PLL lock, generated clock liveness, both channel
init-done bits, and refresh health. DQ/DQS data traffic is not tested here.
"""

import argparse
import pathlib
import sys


sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

from jtag_uart_read import (  # noqa: E402
    XVC,
    read_status_reg,
    select_user1,
    tap_reset_to_rti,
)


PROBE_VERSION = 0xB07E0D80


def require(cond, msg):
    if not cond:
        raise RuntimeError(msg)


def bit(value, index):
    return (value >> index) & 1


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
        status = read_status_reg(xvc, 0x00)
        state = read_status_reg(xvc, 0x01)
        clk_sys = read_status_reg(xvc, 0x15)
        clk_ddr = read_status_reg(xvc, 0x16)
        clk_dq = read_status_reg(xvc, 0x17)
        clk_ref = read_status_reg(xvc, 0x18)
        config = read_status_reg(xvc, 0x04)
        refresh0 = read_status_reg(xvc, 0x20)
        refresh1 = read_status_reg(xvc, 0x21)

        init_done = bit(status, 11)
        pll_locked = bit(status, 5)
        reset_active = bit(status, 3)
        refresh_late = bit(status, 1)
        ch0_state = (state >> 8) & 0x1F
        ch1_state = (state >> 13) & 0x1F

        print(f"version=0x{version:08x}")
        print(f"status=0x{status:08x} init_done={init_done} "
              f"pll_locked={pll_locked} reset_active={reset_active} "
              f"refresh_late={refresh_late}")
        print(f"state=0x{state:08x} ch0_init_state={ch0_state} "
              f"ch1_init_state={ch1_state}")
        print(f"clk_sys=0x{clk_sys:08x} alive={bit(clk_sys, 15)}")
        print(f"clk_ddr=0x{clk_ddr:08x} alive={bit(clk_ddr, 15)}")
        print(f"clk_dq=0x{clk_dq:08x} alive={bit(clk_dq, 15)}")
        print(f"clk_ref=0x{clk_ref:08x} alive={bit(clk_ref, 15)}")
        print(f"config=0x{config:08x}")
        print(f"refresh0=0x{refresh0:08x} refresh1=0x{refresh1:08x}")

        require(version == args.expected_version,
                f"expected {args.gate_name} version 0x{args.expected_version:08x}, "
                f"got 0x{version:08x}")
        require((status >> 16) == 0xB07E,
                f"status magic mismatch: 0x{status:08x}")
        require(pll_locked == 1, "DDR3 PLL is not locked")
        require(reset_active == 0, "DDR3 controller reset is still active")
        require(init_done == 1, "both DDR3 channels did not complete JEDEC init")
        require(refresh_late == 0, "DDR3 refresh scheduler reported late refresh")
        require(bit(clk_sys, 15) == 1, "clk_sys liveness probe is dead")
        require(bit(clk_ddr, 15) == 1, "clk_ddr liveness probe is dead")
        require(bit(clk_dq, 15) == 1, "clk_dq liveness probe is dead")
        require(bit(clk_ref, 15) == 1, "SYS_CLK liveness probe is dead")
        require((refresh0 >> 16) == 0xF0C0,
                f"refresh0 magic mismatch: 0x{refresh0:08x}")
        require((refresh1 >> 16) == 0xF0C1,
                f"refresh1 magic mismatch: 0x{refresh1:08x}")
        if args.require_ddr_wb_blocked:
            require((config >> 16) == 0xAB04,
                    f"config magic mismatch: 0x{config:08x}")
            require(bit(config, 6) == 1,
                    f"DDR Wishbone block bit is not set: 0x{config:08x}")
            require(bit(config, 5) == 1,
                    f"SERDES PHY bit is not set: 0x{config:08x}")
            require(bit(config, 0) == 1,
                    f"DDR command-drive bit is not set: 0x{config:08x}")

        print(f"{args.gate_name}_VALIDATE_SUMMARY ok=1")
    finally:
        xvc.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="localhost")
    parser.add_argument("--port", type=int, default=3721)
    parser.add_argument("--tck-ns", type=int, default=2000)
    parser.add_argument("--expected-version", type=lambda s: int(s, 0),
                        default=PROBE_VERSION)
    parser.add_argument("--gate-name", default="DDR3_INIT")
    parser.add_argument("--require-ddr-wb-blocked", action="store_true")
    args = parser.parse_args()
    validate(args)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

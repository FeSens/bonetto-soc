#!/usr/bin/env python3
"""
jtag_uart_read.py — host-side reader for the bonetto-soc jtag_uart IP.

Talks to openFPGALoader's --xvc server (TCP port 3721 by default), navigates
the YPCB-00338 JTAG chain (Inspur CPLD bypass + xc7k480t USER1), and prints
whatever 32-bit value the FPGA-side `fpga_to_host` register holds.

Companion to:
    openFPGALoader --xvc --port 3721 \\
        --cable xilinxPlatformCableUsb \\
        --probe-firmware boards/ypcb-00338/firmware/xusb_xp2.hex \\
        --misc-device 0x10931093,8,inspur_cpld

Usage:
    python tools/jtag_uart_read.py           # one read
    python tools/jtag_uart_read.py --watch   # poll forever

The XVC protocol is the original Xilinx Virtual Cable v1.0 — three commands:
    getinfo:                       -> "xvcServer_v1.0:NNN\\n"
    settck:<u32_le_period_ns>      -> u32 actual period
    shift:<u32_le_num_bits><tms><tdi>  -> tdo

Where <tms> and <tdi> are ceil(num_bits/8)-byte LSB-first bit streams.

JTAG chain layout on YPCB-00338 (TDI -> ... -> TDO):
    Inspur CPLD  IDCODE 0x10931093  IR_len 8  (BYPASS DR length = 1)
    xc7k480t     IDCODE 0x23751093  IR_len 6  (USER1 DR length = 33 bits)
                                              [32]=write, [31:0]=data
"""

import argparse
import socket
import struct
import sys
import time


# ---------------------------------------------------------------------------
# XVC client
# ---------------------------------------------------------------------------

class XVC:
    def __init__(self, host="localhost", port=3721, timeout=5.0):
        self.sock = socket.create_connection((host, port), timeout=timeout)
        self.sock.sendall(b"getinfo:")
        info = b""
        while not info.endswith(b"\n"):
            chunk = self.sock.recv(64)
            if not chunk:
                raise RuntimeError("XVC server hung up during getinfo")
            info += chunk
        self.info = info.decode().strip()

    def shift(self, n_bits: int, tms: bytes, tdi: bytes) -> bytes:
        assert n_bits > 0
        n_bytes = (n_bits + 7) // 8
        assert len(tms) == n_bytes, f"len(tms)={len(tms)}, expected {n_bytes}"
        assert len(tdi) == n_bytes, f"len(tdi)={len(tdi)}, expected {n_bytes}"
        cmd = b"shift:" + struct.pack("<I", n_bits) + tms + tdi
        self.sock.sendall(cmd)
        out = b""
        while len(out) < n_bytes:
            chunk = self.sock.recv(n_bytes - len(out))
            if not chunk:
                raise RuntimeError("XVC server hung up during shift")
            out += chunk
        return out

    def close(self):
        self.sock.close()


# ---------------------------------------------------------------------------
# Bit-packing helpers (LSB-first byte streams)
# ---------------------------------------------------------------------------

def bits_to_bytes(bits, n_bits=None):
    """Pack a list/sequence of 0/1 bits (LSB first) into bytes."""
    if n_bits is None:
        n_bits = len(bits)
    n_bytes = (n_bits + 7) // 8
    out = bytearray(n_bytes)
    for i in range(n_bits):
        if bits[i]:
            out[i >> 3] |= 1 << (i & 7)
    return bytes(out)


def bytes_to_int(b, n_bits):
    """Unpack the low n_bits of an LSB-first byte stream into a Python int."""
    v = 0
    for i in range(n_bits):
        if b[i >> 3] & (1 << (i & 7)):
            v |= 1 << i
    return v


# ---------------------------------------------------------------------------
# JTAG primitives (TAP state-machine aware)
# ---------------------------------------------------------------------------
#
# TAP state-machine transitions (from RUN-TEST-IDLE):
#   IR scan: TMS = 1,1,0,0 (go to SHIFT-IR)
#            then IR_LEN bits with TMS=0 except last which is TMS=1
#            (exit1-IR) then TMS=1,0 (update-IR -> RTI)
#   DR scan: TMS = 1,0,0   (go to SHIFT-DR)
#            then DR_LEN bits with TMS=0 except last which is TMS=1
#            then TMS=1,0 (update-DR -> RTI)
#
# We bundle a navigation + shift into one XVC shift command.

def tap_reset_to_rti(xvc):
    """Drive TMS=1 five times to force test-logic-reset, then TMS=0 to RTI."""
    tms = bits_to_bytes([1, 1, 1, 1, 1, 0], 6)
    tdi = bits_to_bytes([0] * 6, 6)
    xvc.shift(6, tms, tdi)


def ir_scan(xvc, ir_value: int, ir_len: int) -> int:
    """From RTI: scan IR with ir_value (LSB-first ir_len bits). Returns
    the captured IR (rarely useful for our case; we ignore it)."""
    # Sequence: nav-in (4 TMS bits) + ir_len bits + nav-out (2 TMS bits)
    total = 4 + ir_len + 2

    tms_bits = [1, 1, 0, 0]
    tdi_bits = [0, 0, 0, 0]

    for i in range(ir_len):
        bit = (ir_value >> i) & 1
        is_last = (i == ir_len - 1)
        tms_bits.append(1 if is_last else 0)
        tdi_bits.append(bit)

    # Exit1-IR -> Update-IR -> RTI
    tms_bits += [1, 0]
    tdi_bits += [0, 0]

    tdo = xvc.shift(total, bits_to_bytes(tms_bits, total),
                          bits_to_bytes(tdi_bits, total))
    # Captured IR bits are at TDO positions [4..4+ir_len-1].
    ir_captured_bits = []
    for i in range(ir_len):
        ir_captured_bits.append(tdo[(4 + i) >> 3] >> ((4 + i) & 7) & 1)
    return sum(b << i for i, b in enumerate(ir_captured_bits))


def dr_scan(xvc, dr_tdi: int, dr_len: int) -> int:
    """From RTI: scan DR with dr_tdi (LSB-first dr_len bits). Returns
    the captured DR as a Python int."""
    total = 3 + dr_len + 2

    tms_bits = [1, 0, 0]
    tdi_bits = [0, 0, 0]

    for i in range(dr_len):
        bit = (dr_tdi >> i) & 1
        is_last = (i == dr_len - 1)
        tms_bits.append(1 if is_last else 0)
        tdi_bits.append(bit)

    tms_bits += [1, 0]
    tdi_bits += [0, 0]

    tdo = xvc.shift(total, bits_to_bytes(tms_bits, total),
                          bits_to_bytes(tdi_bits, total))
    dr_bits = []
    for i in range(dr_len):
        dr_bits.append(tdo[(3 + i) >> 3] >> ((3 + i) & 7) & 1)
    return sum(b << i for i, b in enumerate(dr_bits))


# ---------------------------------------------------------------------------
# YPCB-00338-specific chain knowledge
# ---------------------------------------------------------------------------
# Chain: TDI -> Inspur CPLD (IR=8, BYPASS_DR=1) -> xc7k480t (IR=6, USER1_DR=33) -> TDO
#
# FPGA is closest to TDO. When loading IR (LSB-first into TDI), the FIRST bits
# go to the device closest to TDO (FPGA), then CPLD.
# So IR pattern (LSB-first, total 14 bits) = FPGA_IR (6) || CPLD_IR (8).
#
# To select FPGA USER1 (opcode 0x02) + CPLD BYPASS (all 1s):
#   IR_LSBFIRST = (0xFF << 6) | 0x02 = 0x3FC2
#
# When shifting DR through this IR setup, CPLD is in BYPASS (1-bit DR), so
# total DR length = 33 (FPGA USER1) + 1 (CPLD BYPASS) = 34 bits.
# The 33-bit FPGA USER1 data lands at TDO positions [0..32]; the CPLD's BYPASS
# bit is at position 33.

YPCB_00338_IR_PATTERN = (0xFF << 6) | 0x02   # = 0x3FC2
YPCB_00338_IR_LEN     = 14
YPCB_00338_DR_LEN     = 33 + 1               # FPGA USER1 + CPLD BYPASS
YPCB_00338_FPGA_DR_LEN = 33


def select_user1(xvc):
    """Load IR with FPGA=USER1, CPLD=BYPASS."""
    ir_scan(xvc, YPCB_00338_IR_PATTERN, YPCB_00338_IR_LEN)


def read_fpga_to_host(xvc) -> int:
    """Shift 34 bits of 0s through DR; recover the 32 data bits."""
    captured = dr_scan(xvc, 0, YPCB_00338_DR_LEN)
    # FPGA's 33 bits at positions [0..32]; data is bits [0..31] of those.
    fpga_dr = captured & ((1 << YPCB_00338_FPGA_DR_LEN) - 1)
    data = fpga_dr & 0xFFFFFFFF
    direction = (fpga_dr >> 32) & 1
    return data, direction


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="localhost")
    ap.add_argument("--port", type=int, default=3721)
    ap.add_argument("--watch", action="store_true",
                    help="poll once per second forever")
    ap.add_argument("--interval", type=float, default=1.0,
                    help="poll interval in seconds (with --watch)")
    args = ap.parse_args()

    xvc = XVC(args.host, args.port)
    print(f"connected to {args.host}:{args.port} — {xvc.info}")

    tap_reset_to_rti(xvc)
    select_user1(xvc)

    while True:
        data, direction = read_fpga_to_host(xvc)
        print(f"fpga_to_host = 0x{data:08x}  (dir bit: {direction})")
        if not args.watch:
            break
        time.sleep(args.interval)

    xvc.close()


if __name__ == "__main__":
    sys.exit(main())

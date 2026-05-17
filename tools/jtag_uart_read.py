#!/usr/bin/env python3
"""
jtag_uart_read.py — host-side reader for the bonetto-soc jtag_uart IP.

Talks to openFPGALoader's --xvc server (TCP port 3721 by default), navigates
the YPCB-00338 JTAG chain (Inspur CPLD bypass + xc7k480t USER1), and reads
the FPGA's status mux.

Iter-3 host protocol:
  1. Write a 32-bit "register index" (with dir=1) — selects which status word.
  2. Read (dir=0) the resulting 32-bit value.

Companion server:
    openFPGALoader --xvc --port 3721 \\
        --cable xilinxPlatformCableUsb \\
        --probe-firmware boards/ypcb-00338/firmware/xusb_xp2.hex \\
        --misc-device 0x10931093,8,inspur_cpld

Usage:
    python tools/jtag_uart_read.py                # dump all known regs once
    python tools/jtag_uart_read.py --reg 0x03     # read one register
    python tools/jtag_uart_read.py --watch        # dump-all every interval

The XVC protocol is the original Xilinx Virtual Cable v1.0 — three commands:
    getinfo:                       -> "xvcServer_v1.0:NNN\\n"
    settck:<u32_le_period_ns>      -> u32 actual period
    shift:<u32_le_num_bits><tms><tdi>  -> tdo

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

    def settck(self, period_ns: int) -> int:
        cmd = b"settck:" + struct.pack("<I", period_ns)
        self.sock.sendall(cmd)
        out = b""
        while len(out) < 4:
            chunk = self.sock.recv(4 - len(out))
            if not chunk:
                raise RuntimeError("XVC server hung up during settck")
            out += chunk
        return struct.unpack("<I", out)[0]

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
    if n_bits is None:
        n_bits = len(bits)
    n_bytes = (n_bits + 7) // 8
    out = bytearray(n_bytes)
    for i in range(n_bits):
        if bits[i]:
            out[i >> 3] |= 1 << (i & 7)
    return bytes(out)


def bytes_to_int(b, n_bits):
    v = 0
    for i in range(n_bits):
        if b[i >> 3] & (1 << (i & 7)):
            v |= 1 << i
    return v


# ---------------------------------------------------------------------------
# JTAG primitives
# ---------------------------------------------------------------------------

def tap_reset_to_rti(xvc):
    tms = bits_to_bytes([1, 1, 1, 1, 1, 0], 6)
    tdi = bits_to_bytes([0] * 6, 6)
    xvc.shift(6, tms, tdi)


def ir_scan(xvc, ir_value: int, ir_len: int) -> int:
    total = 4 + ir_len + 2
    tms_bits = [1, 1, 0, 0]
    tdi_bits = [0, 0, 0, 0]
    for i in range(ir_len):
        bit = (ir_value >> i) & 1
        is_last = (i == ir_len - 1)
        tms_bits.append(1 if is_last else 0)
        tdi_bits.append(bit)
    tms_bits += [1, 0]
    tdi_bits += [0, 0]
    xvc.shift(total, bits_to_bytes(tms_bits, total),
                     bits_to_bytes(tdi_bits, total))


def dr_scan(xvc, dr_tdi: int, dr_len: int) -> int:
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
# YPCB-00338 chain knowledge
# ---------------------------------------------------------------------------
YPCB_IR_PATTERN = (0xFF << 6) | 0x02  # = 0x3FC2 — FPGA USER1, CPLD BYPASS
YPCB_IR_LEN     = 14
YPCB_DR_LEN     = 33 + 1              # 33-bit FPGA + 1-bit CPLD BYPASS
YPCB_FPGA_DR_LEN = 33


def select_user1(xvc):
    ir_scan(xvc, YPCB_IR_PATTERN, YPCB_IR_LEN)


def write_register_index(xvc, reg_idx: int):
    """Shift in {dir=1, data=reg_idx}. CPLD BYPASS contributes 1 bit at LSB
    side because the CPLD sits closer to TDI than the FPGA.

    Chain order TDI→TDO is CPLD then FPGA, so when we shift dr_len bits LSB-
    first, the FIRST bits we shift in end up closest to TDO. The FPGA captures
    bits at TDO end; therefore the FPGA's 33-bit DR receives bits [0..32] of
    our shifted data, and the CPLD's BYPASS swallows bit [33].
    """
    fpga_dr = (1 << 32) | (reg_idx & 0xFFFFFFFF)   # [32]=1 (write), [31:0]=idx
    full_dr = fpga_dr  # bit 33 (CPLD BYPASS) = 0 — value doesn't matter
    dr_scan(xvc, full_dr, YPCB_DR_LEN)


def read_register(xvc) -> tuple[int, int]:
    captured = dr_scan(xvc, 0, YPCB_DR_LEN)
    fpga_dr = captured & ((1 << YPCB_FPGA_DR_LEN) - 1)
    data = fpga_dr & 0xFFFFFFFF
    direction = (fpga_dr >> 32) & 1
    return data, direction


def read_status_reg(xvc, reg_idx: int) -> int:
    """Write the register index, then read back the selected status word."""
    write_register_index(xvc, reg_idx)
    # The FPGA's host_to_fpga reg updates on JTAG UPDATE-DR, then the mux
    # combinational logic produces the new status_word. A subsequent DR scan
    # captures it on CAPTURE-DR. JTAG already gives us a fresh capture on
    # each scan, so one read suffices.
    data, _ = read_register(xvc)
    return data


# ---------------------------------------------------------------------------
# iter-7: JTAG-driven WB master commands.
#
# All command codes are encoded in host_to_fpga[31:24]; lower bits carry
# payload. The FPGA's jtag_wb_master decodes each command on the UPDATE-DR
# rising edge.
# ---------------------------------------------------------------------------

JWB_CMD_SET_ADDR = 0xE0
JWB_CMD_SET_DLO  = 0xE2
JWB_CMD_SET_DHI  = 0xE3
JWB_CMD_GO_WR    = 0xE4
JWB_CMD_GO_RD    = 0xE5
JWB_CMD_HALT     = 0xE6
JWB_CMD_RESUME   = 0xE7
# iter-10: payload[3:0]=lane, payload[12:8]=tap
JWB_CMD_SET_CAL  = 0xE8
# iter-11: MMCM clk_dq phase shift on CLKOUT2 (DQS-out launch clock).
JWB_CMD_PHASE_INC = 0xE9
JWB_CMD_PHASE_DEC = 0xEA


def jwb_set_idelay(xvc, lane: int, tap: int):
    """Pulse the FPGA's IDELAYE2 load on `lane` with `tap`. lane: 0-8."""
    payload = ((tap & 0x1F) << 8) | (lane & 0xF)
    jwb_cmd(xvc, JWB_CMD_SET_CAL, payload)


def jwb_phase_shift(xvc, n_steps: int):
    """Shift clk_dq's phase by n_steps. Positive = increment (delay DQS),
    negative = decrement (advance DQS). Each step = VCO_period/56 = 22.3ps
    @ 800 MHz VCO. Each pulse waits for the FPGA to drop busy."""
    cmd = JWB_CMD_PHASE_INC if n_steps > 0 else JWB_CMD_PHASE_DEC
    for _ in range(abs(n_steps)):
        jwb_cmd(xvc, cmd, 0)
        # Poll status reg 0x14 until busy=0.
        for _ in range(20):
            st = read_status_reg(xvc, 0x14)
            if ((st >> 8) & 1) == 0:
                break


def jwb_cmd(xvc, cmd_code: int, payload: int = 0):
    """Write a raw 32-bit command word with `cmd_code` in [31:24] and `payload` in lower bits."""
    word = ((cmd_code & 0xFF) << 24) | (payload & 0x00FFFFFF)
    write_register_index(xvc, word)


def jwb_wait_idle(xvc, max_iters=20):
    """Poll status reg 0x10 until JWB_BUSY clears (one round-trip per iter)."""
    for _ in range(max_iters):
        st = read_status_reg(xvc, 0x10)
        busy = (st >> 3) & 1
        if not busy:
            return st
    raise RuntimeError(f"jwb stuck busy: 0x{st:08x}")


def jwb_wb_write(xvc, addr: int, data: int):
    """Halt memtest, write data to addr, leave halt set so caller can probe."""
    jwb_cmd(xvc, JWB_CMD_HALT)
    jwb_cmd(xvc, JWB_CMD_SET_ADDR, addr & 0x7FFF)
    jwb_cmd(xvc, JWB_CMD_SET_DLO, data & 0xFFFF)
    jwb_cmd(xvc, JWB_CMD_SET_DHI, (data >> 16) & 0xFFFF)
    jwb_cmd(xvc, JWB_CMD_GO_WR)
    return jwb_wait_idle(xvc)


def jwb_wb_read(xvc, addr: int) -> int:
    jwb_cmd(xvc, JWB_CMD_HALT)
    jwb_cmd(xvc, JWB_CMD_SET_ADDR, addr & 0x7FFF)
    jwb_cmd(xvc, JWB_CMD_GO_RD)
    jwb_wait_idle(xvc)
    return read_status_reg(xvc, 0x13)


# ---------------------------------------------------------------------------
# Status register decoders
# ---------------------------------------------------------------------------

INIT_STATE_NAMES = {
    0: "PWR_ON",       1: "RESET_HIGH",  2: "CKE_HIGH_NOP",
    3: "MR2",          4: "MR2_WAIT",    5: "MR3",
    6: "MR3_WAIT",     7: "MR1",         8: "MR1_WAIT",
    9: "MR0",         10: "MR0_WAIT",   11: "ZQCL",
    12: "ZQ_WAIT",    13: "DLLK_WAIT",  14: "PRE_ALL",
    15: "PRE_WAIT",   16: "FIRST_REF",  17: "REF_WAIT",
    18: "DONE",       31: "FAIL",
}

CAL_SEQ_STATE_NAMES = {
    0:  "IDLE",         1:  "WAIT_INIT",    2:  "PULSE_WLVL",
    3:  "WAIT_WLVL",    4:  "PULSE_RDLVL",  5:  "WAIT_RDLVL",
    6:  "DONE",         7:  "ERROR",
    8:  "MR3_EN_PULSE", 9:  "MR3_EN_WAIT",  10: "MR3_DIS_PULSE",
    11: "MR3_DIS_WAIT",
}

CAL_ERROR_NAMES = {
    0b00: "no error",
    0b01: "wlvl",
    0b10: "rdlvl",
    0b11: "both?",
}


def decode_status_flags(w: int) -> str:
    magic = (w >> 16) & 0xFFFF
    cal_done   = (w >> 15) & 1
    cal_error  = (w >> 14) & 1
    cal_ecode  = (w >> 12) & 0x3
    init_done  = (w >> 11) & 1
    init_error = (w >> 10) & 1
    init_ecode = (w >> 6) & 0xF
    mmcm_lck   = (w >> 5) & 1
    idel_rdy   = (w >> 4) & 1
    por_rst    = (w >> 3) & 1
    mpr_busy   = (w >> 2) & 1
    any_err    = (w >> 1) & 1
    hb         = w & 1
    return (f"magic=0x{magic:04x} cal_done={cal_done} cal_error={cal_error} "
            f"cal_ecode={cal_ecode}({CAL_ERROR_NAMES.get(cal_ecode,'?')}) "
            f"init_done={init_done} init_error={init_error} "
            f"init_ecode={init_ecode} mmcm_locked={mmcm_lck} "
            f"idelay_ready={idel_rdy} por_rst={por_rst} "
            f"mpr_busy={mpr_busy} mtest_any_err={any_err} hb={hb}")


PATTERN_NAMES = {0: "addr-data", 1: "walking-1", 2: "0xAA", 3: "0x55"}


def decode_state_bits(w: int) -> str:
    init_st  = (w >> 27) & 0x1F
    cal_st   = (w >> 23) & 0xF
    wlvl_st  = (w >> 19) & 0xF
    rdlvl_st = (w >> 15) & 0xF
    patt_idx = (w >> 13) & 0x3
    hb       = w & 0x1FFF
    return (f"init_state={init_st}({INIT_STATE_NAMES.get(init_st,'?')}) "
            f"cal_seq_state={cal_st}({CAL_SEQ_STATE_NAMES.get(cal_st,'?')}) "
            f"cal_wlvl_state={wlvl_st} cal_rdlvl_state={rdlvl_st} "
            f"pattern={patt_idx}({PATTERN_NAMES.get(patt_idx,'?')}) "
            f"hb_low={hb}")


REG_DECODERS = {
    0x00: ("STATUS_FLAGS", decode_status_flags),
    0x01: ("STATE_BITS",   decode_state_bits),
    0x02: ("HEARTBEAT",    lambda w: f"counter=0x{w:06x} ({w} cycles @ 50 MHz ≈ {w/50e6:.3f}s)"),
    0x03: ("MTEST_PASS_CTR",      lambda w: f"{w} ({w:#010x})"),
    0x04: ("MTEST_ERR_CTR",       lambda w: f"{w} ({w:#010x})"),
    0x05: ("MTEST_FIRST_ERR_ADDR",     lambda w: (
        f"addr=0x{w & 0x3FFF:04x} target={(w>>14)&1} pattern={(w>>15)&3}({PATTERN_NAMES.get((w>>15)&3,'?')})"
    )),
    0x06: ("MTEST_FIRST_ERR_EXPECTED", lambda w: f"{w:#010x}"),
    0x07: ("MTEST_FIRST_ERR_GOT",      lambda w: f"{w:#010x}"),
    0x08: ("MTEST_DDR3_PASS_CTR",      lambda w: f"{w} ({w:#010x})"),
    0x10: ("JWB_STATUS", lambda w: (
        f"magic=0x{w>>16:04x} busy={(w>>3)&1} last_ack={(w>>2)&1} "
        f"last_err={(w>>1)&1} halt_others={w&1}"
    )),
    0x11: ("JWB_ADDR",   lambda w: f"{w:#06x}"),
    0x12: ("JWB_DATA",   lambda w: f"{w:#010x}"),
    0x13: ("JWB_RD_DATA",lambda w: f"{w:#010x}"),
    0x14: ("PHASE_STATUS", lambda w: (
        f"magic=0x{w>>16:04x} busy={(w>>8)&1} count={w & 0xFF} "
        f"(signed={(w & 0xFF) if (w & 0xFF) < 0x80 else (w & 0xFF) - 0x100})"
    )),
    0x15: ("CLK_SYS_PROBE", lambda w: (
        f"magic=0x{w>>16:04x} clk_sys_alive={(w>>15)&1} "
        f"sys_hb_bit={(w>>14)&1} sys_hb_ticks_lo={w & 0x3F}"
    )),
    0xFE: ("VERSION",    lambda w: f"magic=0x{w>>16:04x} iter={w & 0xFFFF}"),
    0xFF: ("ECHO",       lambda w: f"{w:#010x}"),
}


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def dump_all(xvc):
    for idx in sorted(REG_DECODERS.keys()):
        name, decoder = REG_DECODERS[idx]
        w = read_status_reg(xvc, idx)
        print(f"  [{idx:#04x}] {name:<26s} = {w:#010x}   {decoder(w)}")


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                  formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="localhost")
    ap.add_argument("--port", type=int, default=3721)
    ap.add_argument("--reg", type=lambda s: int(s, 0),
                    help="read a single register by index (hex/dec ok)")
    ap.add_argument("--watch", action="store_true",
                    help="poll forever")
    ap.add_argument("--interval", type=float, default=1.0,
                    help="poll interval in seconds (with --watch)")
    ap.add_argument("--tck-ns", type=int, default=None,
                    help="set XVC TCK period in ns (default: server default)")
    ap.add_argument("--wb-write", nargs=2, metavar=("ADDR", "DATA"),
                    help="iter-7: WB write via JTAG-WB master (hex/dec ok)")
    ap.add_argument("--wb-read", metavar="ADDR",
                    help="iter-7: WB read via JTAG-WB master (hex/dec ok)")
    ap.add_argument("--wb-resume", action="store_true",
                    help="clear JWB halt_others so memtest_lite resumes")
    args = ap.parse_args()

    xvc = XVC(args.host, args.port)
    print(f"connected to {args.host}:{args.port} — {xvc.info}")

    if args.tck_ns is not None:
        actual = xvc.settck(args.tck_ns)
        print(f"settck({args.tck_ns} ns) -> {actual} ns")

    tap_reset_to_rti(xvc)
    select_user1(xvc)

    if args.wb_write is not None:
        addr = int(args.wb_write[0], 0)
        data = int(args.wb_write[1], 0)
        st = jwb_wb_write(xvc, addr, data)
        print(f"WB write addr={addr:#06x} data={data:#010x} -> status={st:#010x}")
        xvc.close()
        return 0

    if args.wb_read is not None:
        addr = int(args.wb_read, 0)
        d = jwb_wb_read(xvc, addr)
        print(f"WB read addr={addr:#06x} -> data={d:#010x}")
        xvc.close()
        return 0

    if args.wb_resume:
        jwb_cmd(xvc, JWB_CMD_RESUME)
        print("JWB resumed (halt_others cleared)")
        xvc.close()
        return 0

    while True:
        if args.reg is not None:
            w = read_status_reg(xvc, args.reg)
            name, decoder = REG_DECODERS.get(args.reg, (f"REG_{args.reg:#04x}", lambda v: f"{v:#010x}"))
            print(f"  [{args.reg:#04x}] {name:<26s} = {w:#010x}   {decoder(w)}")
        else:
            print(f"--- status dump @ {time.strftime('%H:%M:%S')} ---")
            dump_all(xvc)

        if not args.watch:
            break
        time.sleep(args.interval)

    xvc.close()


if __name__ == "__main__":
    sys.exit(main())

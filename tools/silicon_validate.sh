#!/usr/bin/env bash
# silicon_validate.sh — automated post-flash silicon validation for YPCB-00338.
#
# Brings up the XVC server, polls the status mux, and prints decoded state.
# Intended to run AFTER `make program` has loaded a bitstream. Output is also
# tee'd to /tmp/silicon_validate.log so an interactive operator (or future
# autonomous loop) can grep it for hints.
#
# Usage:
#   nix develop --command bash tools/silicon_validate.sh
set -euo pipefail

cd "$(dirname "$0")/.."
BOARD=boards/ypcb-00338
LOG=/tmp/silicon_validate.log
: > "$LOG"

echo "== starting XVC server on :3721 ==" | tee -a "$LOG"
sleep infinity | openFPGALoader \
    --xvc --port 3721 \
    --cable xilinxPlatformCableUsb \
    --probe-firmware $BOARD/firmware/xusb_xp2.hex \
    --misc-device 0x10931093,8,inspur_cpld \
    > /tmp/xvc.log 2>&1 &
XVC_PID=$!
trap "kill -TERM $XVC_PID 2>/dev/null || true; pkill -P $XVC_PID 2>/dev/null || true" EXIT INT TERM

echo "== waiting for XVC port bind ==" | tee -a "$LOG"
for i in $(seq 1 30); do
    if nc -z localhost 3721 2>/dev/null; then
        echo "   XVC up (after ${i}s)" | tee -a "$LOG"
        break
    fi
    sleep 1
done
if ! nc -z localhost 3721 2>/dev/null; then
    echo "FAIL: XVC server didn't bind in 30s" | tee -a "$LOG"
    echo "==== /tmp/xvc.log ====" | tee -a "$LOG"
    tail -20 /tmp/xvc.log | tee -a "$LOG"
    exit 1
fi

# Reduce XVC TCK to 500k for stable reads (per user guidance).
echo "== full-dump 1 (with default TCK) ==" | tee -a "$LOG"
python3 tools/jtag_uart_read.py 2>&1 | tee -a "$LOG"

echo
echo "== full-dump 2 (TCK=500kHz, i.e. 2000ns period) ==" | tee -a "$LOG"
python3 tools/jtag_uart_read.py --tck-ns 2000 2>&1 | tee -a "$LOG"

# 60s watch loop, dumping every 10s.
echo
echo "== 60s watch (10s polls, looking for progress) ==" | tee -a "$LOG"
for i in $(seq 1 6); do
    sleep 10
    echo "--- t=${i}0s ---" | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x00 2>&1 | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x01 2>&1 | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x02 2>&1 | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x03 2>&1 | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x04 2>&1 | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x05 2>&1 | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x06 2>&1 | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x07 2>&1 | tee -a "$LOG"
    python3 tools/jtag_uart_read.py --tck-ns 2000 --reg 0x08 2>&1 | tee -a "$LOG"
done

# iter-7: direct WB probe via JTAG-WB master. Halts memtest, performs a
# write+read on a known BRAM address and a known DDR3 address, prints
# pass/fail. After probing, resumes memtest so the watch counters can
# tick again.
echo
echo "== iter-7 JTAG-WB probe: BRAM write+read ==" | tee -a "$LOG"
BRAM_ADDR=0x0010
BRAM_PAT=0xABCD1234
python3 tools/jtag_uart_read.py --tck-ns 2000 --wb-write $BRAM_ADDR $BRAM_PAT 2>&1 | tee -a "$LOG"
python3 tools/jtag_uart_read.py --tck-ns 2000 --wb-read $BRAM_ADDR 2>&1 | tee -a "$LOG"

echo
echo "== iter-7 JTAG-WB probe: DDR3 window write+read (only meaningful post-cal) ==" | tee -a "$LOG"
DDR_ADDR=0x4010   # adr[14]=1 -> wb_decode2 routes to ddr3_ctrl
DDR_PAT=0xDEADBEEF
python3 tools/jtag_uart_read.py --tck-ns 2000 --wb-write $DDR_ADDR $DDR_PAT 2>&1 | tee -a "$LOG"
python3 tools/jtag_uart_read.py --tck-ns 2000 --wb-read $DDR_ADDR 2>&1 | tee -a "$LOG"

echo
echo "== resume memtest_lite ==" | tee -a "$LOG"
python3 tools/jtag_uart_read.py --tck-ns 2000 --wb-resume 2>&1 | tee -a "$LOG"

echo
echo "== validation complete — see $LOG ==" | tee -a "$LOG"

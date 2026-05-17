#!/usr/bin/env bash
# auto_flash_validate.sh — when the XPCU cable enumerates, this script:
#   1. Flashes the current bitstream via openFPGALoader.
#   2. Runs silicon_validate.sh (XVC server + status mux dump + 60s watch).
#   3. Greps the validation log for known failure modes and writes a
#      next-steps note.
#
# Designed to run AFTER monitor detects cable re-enumeration. Idempotent.
set -uo pipefail

cd "$(dirname "$0")/.."
BOARD=boards/ypcb-00338
LOG=/tmp/auto_flash_validate.log
NEXT=/tmp/silicon_next_steps.txt
: > "$LOG"
: > "$NEXT"

echo "== auto_flash_validate $(date) ==" | tee -a "$LOG"

# 1. Flash
echo "[1/3] flashing bitstream..." | tee -a "$LOG"
if (cd $BOARD && make program 2>&1 | tail -20 | tee -a "$LOG" | grep -q "Done"); then
    echo "  flash OK" | tee -a "$LOG"
else
    echo "  flash FAILED" | tee -a "$LOG"
    echo "next step: cable still wedged. Physical replug needed." > "$NEXT"
    exit 1
fi

# 2. Validate
echo "[2/3] running silicon_validate.sh..." | tee -a "$LOG"
bash tools/silicon_validate.sh 2>&1 | tee -a "$LOG"

# 3. Grep for failure signatures and write next-steps.
echo "[3/3] post-mortem analysis..." | tee -a "$LOG"
LAST_REG00=$(grep -E '\[0x00\].*STATUS_FLAGS' /tmp/silicon_validate.log | tail -1)
LAST_REG01=$(grep -E '\[0x01\].*STATE_BITS' /tmp/silicon_validate.log | tail -1)
LAST_REG03=$(grep -E '\[0x03\].*MTEST_PASS_CTR' /tmp/silicon_validate.log | tail -1)
LAST_REG08=$(grep -E '\[0x08\].*MTEST_DDR3' /tmp/silicon_validate.log | tail -1)
JWB_BRAM_WRITE=$(grep -A0 'WB write addr=0x0010' /tmp/silicon_validate.log | tail -1)
JWB_BRAM_READ=$(grep -A0 'WB read addr=0x0010'  /tmp/silicon_validate.log | tail -1)
JWB_DDR_WRITE=$(grep -A0 'WB write addr=0x4010' /tmp/silicon_validate.log | tail -1)
JWB_DDR_READ=$(grep -A0 'WB read addr=0x4010'   /tmp/silicon_validate.log | tail -1)

{
  echo "== silicon validation summary $(date) =="
  echo "$LAST_REG00"
  echo "$LAST_REG01"
  echo "$LAST_REG03"
  echo "$LAST_REG08"
  echo "== iter-7 JTAG-WB probe results =="
  echo "$JWB_BRAM_WRITE"
  echo "$JWB_BRAM_READ"
  echo "$JWB_DDR_WRITE"
  echo "$JWB_DDR_READ"
  echo
  echo "== recommended next iteration =="
  if echo "$LAST_REG00" | grep -q "magic=0x0000"; then
      echo "  STATUS MUX NOT RESPONDING. Re-check jtag_uart CAPTURE wiring."
  elif echo "$LAST_REG00" | grep -q "mmcm_locked=0"; then
      echo "  MMCM never locked. Check clk_50 input, MMCM_ADV params."
  elif echo "$LAST_REG00" | grep -q "init_done=0"; then
      echo "  Init never completed. Check init_state in REG 0x01 for where it stuck."
  elif echo "$LAST_REG00" | grep -q "cal_done=0"; then
      echo "  Cal didn't complete. With SKIP_WLVL=SKIP_RDLVL=1 this should be instant."
      echo "  Check cal_seq_state in REG 0x01."
  elif echo "$JWB_BRAM_READ" | grep -q "data=0xabcd1234"; then
      if echo "$JWB_DDR_READ" | grep -q "data=0xdeadbeef"; then
          echo "  BRAM ok + DDR3 round-trip ok via JWB. Resume memtest, watch counters."
      elif echo "$JWB_DDR_READ" | grep -q "data=0x00000000"; then
          echo "  BRAM works; DDR3 reads return 0. Likely WB never acks DDR3 — check"
          echo "  ddr3_ctrl WB front-end + runtime FSM stalling on init_done gate."
      elif echo "$JWB_DDR_READ" | grep -q "data=0xaaaaaaaa"; then
          echo "  BRAM works; DDR3 reads return 0xAAAAAAAA = MPR predefined pattern."
          echo "  Chip is stuck in MR3[2]=1 mode. Need MR3-rewrite path (iter-8)."
      else
          echo "  BRAM works; DDR3 returns wrong data. Likely DQ phase / rdlvl needed."
      fi
  elif echo "$LAST_REG03" | grep -q "0x00000000"; then
      echo "  Memtest pass_ctr is zero AND JWB BRAM probe failed — bus/WB issue."
      echo "  Check rst_sys path and wb_decode2 wiring."
  elif echo "$LAST_REG00" | grep -q "mtest_any_err=1"; then
      echo "  Memtest detected mismatch. Read REG 0x05 (addr), 0x06 (expected), 0x07 (got)."
      echo "  Likely DDR3 read timing — needs rdlvl. Add MR-rewrite + MPR cal sequence."
  else
      echo "  Memtest running cleanly. Watch DDR3_PASS_CTR (0x08) for sustained increments."
  fi
} | tee -a "$NEXT"

echo "== see $NEXT for action items ==" | tee -a "$LOG"

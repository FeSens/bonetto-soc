#!/usr/bin/env bash
# scripts/lint.sh — per-IP contract checks enforcing INVARIANTS #4 and #5.
# Every IP under ip/ must have the same scaffolding.

set -euo pipefail

cd "$(dirname "$0")/.."

ok=0
fail=0

for ip_dir in ip/*/; do
    ip=$(basename "$ip_dir")
    err=""
    for required in \
        "$ip_dir/README.md" \
        "$ip_dir/docs/interface.md" \
        "$ip_dir/Makefile" \
        "$ip_dir/rtl" \
        "$ip_dir/formal" \
        "$ip_dir/sim"; do
        if [[ ! -e "$required" ]]; then
            err+="  missing: $required"$'\n'
        fi
    done

    if [[ -z "$err" ]]; then
        printf "  %-12s OK\n" "$ip"
        ok=$((ok+1))
    else
        printf "  %-12s FAIL\n%s" "$ip" "$err"
        fail=$((fail+1))
    fi
done

echo
echo "lint: $ok ok, $fail fail"
exit $((fail > 0 ? 1 : 0))

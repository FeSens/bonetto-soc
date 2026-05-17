# bonetto-soc top-level Makefile
# Per-IP `make formal-<ip>`, `make sim-<ip>`, plus aggregate targets.
# `make help` for the list.

.PHONY: help all ci lint formal sim fpga program memtest clean \
        formal-wishbone formal-wb-memory formal-jtag-uart formal-ddr3 formal-board \
        sim-wishbone sim-wb-memory sim-jtag-uart sim-ddr3 sim-board

.DEFAULT_GOAL := help

# Default board. Override on the command line: make fpga BOARD=other-board
BOARD ?= ypcb-00338

# --- aggregate ----------------------------------------------------------------

ci: lint formal sim
	@echo "=== CI passed: lint + formal + sim across all IPs ==="

all: ci fpga

formal: formal-wishbone formal-wb-memory formal-jtag-uart formal-ddr3 formal-board

sim:    sim-wishbone    sim-wb-memory    sim-jtag-uart    sim-ddr3    sim-board

# --- lint ---------------------------------------------------------------------

lint:
	@scripts/lint.sh

# --- per-IP formal ------------------------------------------------------------
# Each delegates to the IP's own Makefile / SymbiYosys config.

formal-wishbone:
	$(MAKE) -C ip/wishbone formal

formal-wb-memory:
	$(MAKE) -C ip/wb-memory formal

formal-jtag-uart:
	$(MAKE) -C ip/jtag-uart formal

formal-ddr3:
	$(MAKE) -C ip/ddr3 formal

# Board-level formal: memtest_lite WB-master compliance proof.
formal-board:
	@echo "[board $(BOARD)] formal: memtest_lite against fwb_master"
	cd boards/$(BOARD)/formal && sby -f memtest_lite.sby

# --- per-IP simulation --------------------------------------------------------

sim-wishbone:
	$(MAKE) -C ip/wishbone sim

sim-wb-memory:
	$(MAKE) -C ip/wb-memory sim

sim-jtag-uart:
	$(MAKE) -C ip/jtag-uart sim

sim-ddr3:
	$(MAKE) -C ip/ddr3 sim

# Board-level cocotb: bringup_status_led + clk_liveness + memtest_lite.
sim-board:
	@echo "[board $(BOARD)] sim: bringup_status_led + clk_liveness + memtest_lite"
	-$(MAKE) -C boards/$(BOARD)/sim -f Makefile.cocotb
	-$(MAKE) -C boards/$(BOARD)/sim -f Makefile.clk_liveness
	-$(MAKE) -C boards/$(BOARD)/sim -f Makefile.memtest

# --- board flow ---------------------------------------------------------------

fpga:
	$(MAKE) -C boards/$(BOARD) bitstream

program:
	$(MAKE) -C boards/$(BOARD) program

memtest:
	$(MAKE) -C boards/$(BOARD) memtest

# --- housekeeping -------------------------------------------------------------

clean:
	@for d in ip/*/; do [ -f $$d/Makefile ] && $(MAKE) -C $$d clean || true; done
	@for d in boards/*/; do [ -f $$d/Makefile ] && $(MAKE) -C $$d clean || true; done

# --- help ---------------------------------------------------------------------

help:
	@echo "bonetto-soc — top-level driver"
	@echo ""
	@echo "Aggregate:"
	@echo "  make ci                  lint + formal + sim across every IP"
	@echo "  make all                 ci + fpga"
	@echo ""
	@echo "Per-IP (each runs that IP's own Makefile):"
	@echo "  make formal-<ip>         SymbiYosys for the IP under ip/<ip>/"
	@echo "  make sim-<ip>            Verilator/cocotb for the IP"
	@echo "  Available IPs: wishbone, wb-memory, jtag-uart, ddr3, board"
	@echo "  ('board' covers boards/$(BOARD)/formal/* and boards/$(BOARD)/sim/*)"
	@echo ""
	@echo "Board (default BOARD=$(BOARD); override BOARD=name):"
	@echo "  make fpga BOARD=name     synth + PnR + bitstream"
	@echo "  make program BOARD=name  JTAG-load bitstream"
	@echo "  make memtest BOARD=name  run on-board memory test, results via JTAG UART"
	@echo ""
	@echo "  make lint                lint every IP top against interface.md"
	@echo "  make clean               remove all build artifacts"

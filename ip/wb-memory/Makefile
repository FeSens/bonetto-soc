# wb_memory IP-local Makefile. Driven by top-level make through
# `make formal-wb-memory` / `make sim-wb-memory`.

.PHONY: formal sim clean

formal:
	@echo "[wb-memory] formal"
	cd formal && sby -f wb_memory.sby

sim:
	@echo "[wb-memory] sim (placeholder — fill in iteration 2)"
	@true

clean:
	rm -rf formal/wb_memory_prove formal/wb_memory_cover sim/build

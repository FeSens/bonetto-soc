# jtag-uart

BSCANE2 USER1 bridge used by the board debug path. The host talks to the FPGA
through `openFPGALoader --xvc`, shifts a 33-bit USER1 DR word, and exchanges a
32-bit command/status word with the fabric.

The bridge has two roles:

- expose a status-mux read path for `tools/jtag_uart_read.py`;
- emit a one-cycle `o_host_to_fpga_valid` pulse for command consumers such as
  `jtag_wb_master`.

On hardware, the completed DR word is latched in the JTAG UPDATE domain before
the event crosses into `i_clk`. This avoids sampling the live shift register in
the fabric clock after the host has already started the next scan.

The legacy Wishbone slave port remains for existing simulation tests; board
bring-up should use the XVC/JTAG path.

See `docs/interface.md` for the register map.

{
  description = "bonetto-soc — Wishbone SoC for YPCB-00338 + future 7-series boards. Synth, sim, formal, and JTAG programming on macOS arm64.";

  inputs = {
    # Reuse the openXC7-based toolchain pinned for inspur-adventures.
    # That flake provides nextpnr-xilinx + prjxray + fasm prebuilt for
    # aarch64-darwin and avoids the broken upstream fpga-assembler input.
    openxc7.url    = "git+https://github.com/openXC7/toolchain-nix";
    nixpkgs.follows = "openxc7/nixpkgs";

  };

  outputs = { self, openxc7, nixpkgs, ... }:
    let
      forAllSystems = nixpkgs.lib.genAttrs [
        "aarch64-darwin" "x86_64-darwin" "aarch64-linux" "x86_64-linux"
      ];
    in {
      devShells = forAllSystems (system:
        let
          # allowUnsupportedSystem skips the meta.platforms hard-block on
          # ghdl-mcode (transitively pulled in by pkgs.symbiyosys's VHDL
          # support). ghdl-mcode's JIT backend is x86-only, but we don't
          # use VHDL here — the package just needs to evaluate, not build.
          pkgs = import nixpkgs {
            inherit system;
            config.allowUnsupportedSystem = true;
          };
          ox   = openxc7.packages.${system};
          pyPkg = p: "${p}/lib/python3.12/site-packages/:";

          # Keep all XPCU USB consumers on the same libusb ABI. libusb 1.0.29
          # has newer Darwin backend behavior than the nixpkgs pin's 1.0.27.
          libusb1-xpcu = pkgs.libusb1.overrideAttrs (_old: {
            version = "1.0.29";
            src = pkgs.fetchFromGitHub {
              owner = "libusb";
              repo = "libusb";
              rev = "v1.0.29";
              hash = "sha256-m1w+uF8+2WCn72LvoaGUYa+R0PyXHtFFONQjdRfImYY=";
            };
          });
          libftdi1-xpcu = pkgs.libftdi1.override {
            libusb1 = libusb1-xpcu;
          };

          # openFPGALoader from master with the DLC10/XPCU macOS patches from
          # inspur-adventures plus the XVC hooks used by the JTAG-WB tooling.
          openfpgaloader-xpcu = (pkgs.openfpgaloader.override {
            libftdi1 = libftdi1-xpcu;
            libusb1 = libusb1-xpcu;
          }).overrideAttrs (old: {
            version = "git-be5de3c";
            src = pkgs.fetchFromGitHub {
              owner = "trabucayre";
              repo  = "openFPGALoader";
              rev   = "be5de3c59667a73df810a6791b68ed71ef4a0212";
              hash  = "sha256-F8yddHA4yTGJCMZmtv/Adhts0Dv2yv8yfdI+73dKS1k=";
            };
            patches = (old.patches or []) ++ [
              ./patches/openfpgaloader-fx2-macos-overflow.patch
              ./patches/openfpgaloader-fx2-macos-ctrl-timeout.patch
              ./patches/openfpgaloader-fx2-macos-clear-halt.patch
              ./patches/openfpgaloader-xpcu-skip-missing-alt.patch
              ./patches/openfpgaloader-xvc-xpcu.patch
              ./patches/openfpgaloader-xpcu-writetmstdi.patch
              ./patches/openfpgaloader-xpcu-gpio-timeout-recover.patch
            ];
          });

        in {
          default = pkgs.mkShell {
            buildInputs = [
              # Synth, PnR, bitstream — same as inspur-adventures, known to
              # build on aarch64-darwin via the openXC7-pinned nixpkgs.
              ox.nextpnr-xilinx
              ox.prjxray
              ox.fasm
              pkgs.yosys

              # Programming (XPCU-patched) + host-side JTAG-UART readout.
              # openocd 0.12.0 builds clean on aarch64-darwin in this
              # nixpkgs pin and ships the xilinx-xpcu interface driver.
              openfpgaloader-xpcu
              pkgs.openocd

              # Python ecosystem (used by prjxray's fasm scripts, by the
              # host-side openocd Tcl wrapper, and by cocotb sim later).
              pkgs.pypy310
              pkgs.python312
              pkgs.python312Packages.pyyaml
              pkgs.python312Packages.textx
              pkgs.python312Packages.simplejson
              pkgs.python312Packages.intervaltree
              pkgs.python312Packages.click
            ];

            # Heavier verification tools (verilator, z3, cocotb, symbiyosys)
            # come from PATH (Felipe's oss-cad-suite) — the openXC7-pinned
            # nixpkgs revision has gnat-bootstrap blocked on aarch64-darwin
            # and pulls it into the closure of those packages.

            shellHook = ''
              export NEXTPNR_XILINX_DIR=${ox.nextpnr-xilinx}
              export NEXTPNR_XILINX_PYTHON_DIR=${ox.nextpnr-xilinx}/share/nextpnr/python/
              export PRJXRAY_DB_DIR=${ox.nextpnr-xilinx}/share/nextpnr/external/prjxray-db
              export PRJXRAY_PYTHON_DIR=${ox.prjxray}/usr/share/python3/
              export PYTHONPATH=$PYTHONPATH:$PRJXRAY_PYTHON_DIR:${pyPkg ox.fasm}${pyPkg pkgs.python312Packages.textx}${pyPkg pkgs.python312Packages.arpeggio}${pyPkg pkgs.python312Packages.pyyaml}${pyPkg pkgs.python312Packages.simplejson}${pyPkg pkgs.python312Packages.intervaltree}${pyPkg pkgs.python312Packages.sortedcontainers}${pyPkg pkgs.python312Packages.click}
              export PYPY3=${pkgs.pypy310}/bin/pypy3.10
              echo "bonetto-soc dev shell ready — \`make help\` for targets."
            '';
          };
        });
    };
}

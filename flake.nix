{
  description = "bonetto-soc — Wishbone SoC for YPCB-00338 + future 7-series boards. Synth, sim, formal, and JTAG programming on macOS arm64.";

  inputs = {
    # Reuse the openXC7-based toolchain pinned for inspur-adventures.
    # That flake provides nextpnr-xilinx + prjxray + fasm prebuilt for
    # aarch64-darwin and avoids the broken upstream fpga-assembler input.
    openxc7.url    = "git+https://github.com/openXC7/toolchain-nix";
    nixpkgs.follows = "openxc7/nixpkgs";

    # XPCU patch for openFPGALoader on macOS (LIBUSB_ERROR_OVERFLOW fix).
    # Vendored as a flake so we share the patch with inspur-adventures
    # without copy-pasting it here.
    xpcu-macos = {
      url   = "github:FeSens/xpcu-macos";
      flake = false;
    };
  };

  outputs = { self, openxc7, nixpkgs, xpcu-macos, ... }:
    let
      forAllSystems = nixpkgs.lib.genAttrs [
        "aarch64-darwin" "x86_64-darwin" "aarch64-linux" "x86_64-linux"
      ];
    in {
      devShells = forAllSystems (system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
          ox   = openxc7.packages.${system};
          pyPkg = p: "${p}/lib/python3.12/site-packages/:";

          # openFPGALoader from master with the macOS bulk-read patch.
          openfpgaloader-xpcu = pkgs.openfpgaloader.overrideAttrs (old: {
            version = "git-be5de3c";
            src = pkgs.fetchFromGitHub {
              owner = "trabucayre";
              repo  = "openFPGALoader";
              rev   = "be5de3c59667a73df810a6791b68ed71ef4a0212";
              hash  = "sha256-F8yddHA4yTGJCMZmtv/Adhts0Dv2yv8yfdI+73dKS1k=";
            };
            patches = (old.patches or []) ++ [
              "${xpcu-macos}/openfpgaloader-fx2-macos-overflow.patch"
            ];
          });

        in {
          default = pkgs.mkShell {
            buildInputs = [
              # Synth, PnR, bitstream
              ox.nextpnr-xilinx
              ox.prjxray
              ox.fasm
              pkgs.yosys

              # Programming
              openfpgaloader-xpcu

              # Formal
              pkgs.symbiyosys
              pkgs.bitwuzla
              pkgs.boolector
              pkgs.yices

              # Simulation
              pkgs.verilator
              pkgs.gtkwave

              # Python / cocotb
              pkgs.python312
              pkgs.python312Packages.cocotb
              pkgs.python312Packages.pytest
              pkgs.python312Packages.pyyaml
              pkgs.python312Packages.textx
              pkgs.python312Packages.simplejson
              pkgs.python312Packages.intervaltree

              # pypy for chipdb gen
              pkgs.pypy310

              # General
              pkgs.gnumake
              pkgs.git
            ];

            shellHook = ''
              export NEXTPNR_XILINX_DIR=${ox.nextpnr-xilinx}
              export NEXTPNR_XILINX_PYTHON_DIR=${ox.nextpnr-xilinx}/share/nextpnr/python/
              export PRJXRAY_DB_DIR=${ox.nextpnr-xilinx}/share/nextpnr/external/prjxray-db
              export PRJXRAY_PYTHON_DIR=${ox.prjxray}/usr/share/python3/
              export PYTHONPATH=$PYTHONPATH:$PRJXRAY_PYTHON_DIR:${pyPkg ox.fasm}${pyPkg pkgs.python312Packages.textx}${pyPkg pkgs.python312Packages.arpeggio}${pyPkg pkgs.python312Packages.pyyaml}${pyPkg pkgs.python312Packages.simplejson}${pyPkg pkgs.python312Packages.intervaltree}${pyPkg pkgs.python312Packages.sortedcontainers}
              export PYPY3=${pkgs.pypy310}/bin/pypy3.10
              echo "bonetto-soc dev shell ready — \`make help\` for targets."
            '';
          };
        });
    };
}

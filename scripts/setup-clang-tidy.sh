#!/usr/bin/env bash
set -euo pipefail

echo "=== Clang-Tidy Setup for Competitive Programming ==="
echo ""

# Check if clang-tidy is already available
if command -v clang-tidy >/dev/null 2>&1; then
  echo "✓ clang-tidy is already available in PATH"
  echo "  Location: $(command -v clang-tidy)"
  echo "  Version: $(clang-tidy --version | head -1)"
  exit 0
fi

echo "clang-tidy not found in PATH. Setting up..."
echo ""

# Check for homebrew llvm
if [[ ! -x "/opt/homebrew/opt/llvm/bin/clang-tidy" ]]; then
  echo "✗ LLVM not installed via homebrew"
  echo ""
  echo "Install with:"
  echo "  brew install llvm"
  echo ""
  exit 1
fi

echo "Found: /opt/homebrew/opt/llvm/bin/clang-tidy"

# Create symlink in ~/.local/bin
local_bin="$HOME/.local/bin"
if [[ ! -d "$local_bin" ]]; then
  echo "Creating $local_bin..."
  mkdir -p "$local_bin"
fi

symlink="$local_bin/clang-tidy"
if [[ -e "$symlink" ]]; then
  echo "✓ Symlink already exists: $symlink"
else
  echo "Creating symlink: $symlink"
  ln -s /opt/homebrew/opt/llvm/bin/clang-tidy "$symlink"
fi

echo ""
echo "=== Add to your stow-managed .zprofile ==="
echo ""
echo "Inside the 'if [ -x /opt/homebrew/bin/brew ]' guard, add:"
echo ""
echo "    # LLVM toolchain (default C/C++ compiler)"
echo "    export CC=/opt/homebrew/opt/llvm/bin/clang"
echo "    export CXX=/opt/homebrew/opt/llvm/bin/clang++"
echo "    export SDKROOT=\$(xcrun --show-sdk-path)"
echo ""

# Validate
echo "=== Validation ==="
if command -v clang-tidy >/dev/null 2>&1; then
  echo "✓ clang-tidy is now available"
  clang-tidy --version | head -1
else
  echo "✗ Setup incomplete. Restart your shell or source .zprofile"
  exit 1
fi

echo ""
echo "Setup complete. You can now run:"
echo "  ./scripts/run_clang_tidy_reports.sh"

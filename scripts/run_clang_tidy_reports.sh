#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$repo_root"

if ! command -v clang-tidy >/dev/null 2>&1; then
  echo "Error: clang-tidy not found in PATH" >&2
  echo "Install LLVM/clang toolchain and ensure clang-tidy is available in PATH" >&2
  exit 1
fi

build_dir="build/clang-tidy"
if [[ ! -d "$build_dir" ]]; then
  echo "Error: Missing $build_dir. Run: cmake --preset clang-tidy" >&2
  exit 1
fi

count=0
while IFS= read -r file; do
  dir="$(dirname "$file")"
  out="$dir/clang-tidy.txt"
  clang-tidy "$file" -p "$build_dir" > "$out" 2>&1 || true
  count=$((count + 1))
  echo "Wrote $out"
done < <(find src/cses -mindepth 2 -maxdepth 2 -name '*.cpp' | sort)

if [[ $count -eq 0 ]]; then
  echo "Error: No problem source files found under src/cses" >&2
  exit 1
fi

echo "Generated clang-tidy reports for $count problem(s)."


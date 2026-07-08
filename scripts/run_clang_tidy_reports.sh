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

report_file="$build_dir/clang-tidy-report.txt"
: > "$report_file"  # Clear the report file

count=0
while IFS= read -r file; do
  problem_name="$(basename "$(dirname "$file")")"
  {
    echo "================================================================================"
    echo "Problem: $problem_name"
    echo "File: $file"
    echo "================================================================================"
    clang-tidy "$file" -p "$build_dir" 2>&1 || true
    echo ""
  } >> "$report_file"
  count=$((count + 1))
  echo "Processed $file"
done < <(find src/cses -mindepth 2 -maxdepth 2 -name '*.cpp' | sort)

if [[ $count -eq 0 ]]; then
  echo "Error: No problem source files found under src/cses" >&2
  exit 1
fi

echo "Generated clang-tidy report for $count problem(s) at $report_file"


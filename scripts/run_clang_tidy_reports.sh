#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$repo_root"

if command -v clang-tidy >/dev/null 2>&1; then
  clang_tidy_bin="$(command -v clang-tidy)"
elif [[ -x "/opt/homebrew/opt/llvm/bin/clang-tidy" ]]; then
  clang_tidy_bin="/opt/homebrew/opt/llvm/bin/clang-tidy"
else
  echo "clang-tidy not found in PATH and /opt/homebrew/opt/llvm/bin/clang-tidy is missing" >&2
  exit 1
fi

build_dir="build/clang-tidy"
if [[ ! -d "$build_dir" ]]; then
  echo "Missing $build_dir. Run: cmake --preset clang-tidy" >&2
  exit 1
fi

extra_args=()
if [[ "$(uname -s)" == "Darwin" ]]; then
  if sdk_path="$(xcrun --show-sdk-path 2>/dev/null)"; then
    extra_args+=(--extra-arg=-isysroot --extra-arg="$sdk_path")
  fi
fi

files=()
while IFS= read -r file; do
  files+=("$file")
done < <(find src/cses -mindepth 2 -maxdepth 2 -name '*.cpp' | sort)

if [[ ${#files[@]} -eq 0 ]]; then
  echo "No problem source files found under src/cses" >&2
  exit 1
fi

count=0
for file in "${files[@]}"; do
  dir="$(dirname "$file")"
  out="$dir/clang-tidy.txt"

  "$clang_tidy_bin" "$file" -p "$build_dir" "${extra_args[@]}" > "$out" 2>&1 || true
  count=$((count + 1))
  echo "Wrote $out"
done

echo "Generated clang-tidy reports for $count problem(s)."

#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$repo_root"

usage() {
  cat <<'EOF'
Usage: ./scripts/run_clang_tidy_reports.sh [options]

Modes:
  --all                  Run clang-tidy for all src/cses/*/*.cpp files (default)
  --changed-only         Run clang-tidy only for changed C++ files

Options:
  --base <ref>           Base git ref for changed-only mode
  --head <ref>           Head git ref for changed-only mode (default: HEAD)
  --build-dir <dir>      Build dir containing compile_commands.json (default: build/debug)
  --report-file <path>   Report output path (default: <build-dir>/clang-tidy-report.txt)
  --fail-on-warnings     Exit non-zero if warning/error findings are detected
  --help                 Show this help message
EOF
}

mode="all"
base_ref=""
head_ref="HEAD"
build_dir="build/debug"
report_file=""
fail_on_warnings=0

while [[ $# -gt 0 ]]; do
  case "$1" in
    --all)
      mode="all"
      ;;
    --changed-only)
      mode="changed"
      ;;
    --base)
      base_ref="${2:-}"
      shift
      ;;
    --head)
      head_ref="${2:-}"
      shift
      ;;
    --build-dir)
      build_dir="${2:-}"
      shift
      ;;
    --report-file)
      report_file="${2:-}"
      shift
      ;;
    --fail-on-warnings)
      fail_on_warnings=1
      ;;
    --help)
      usage
      exit 0
      ;;
    *)
      echo "Error: Unknown option '$1'" >&2
      usage
      exit 1
      ;;
  esac
  shift
done

if ! command -v clang-tidy >/dev/null 2>&1; then
  echo "Error: clang-tidy not found in PATH" >&2
  echo "Install LLVM/clang toolchain and ensure clang-tidy is available in PATH" >&2
  exit 1
fi

if [[ ! -d "$build_dir" ]]; then
  echo "Error: Missing $build_dir. Run: cmake --preset debug" >&2
  exit 1
fi

if [[ -z "$report_file" ]]; then
  report_file="$build_dir/clang-tidy-report.txt"
fi

mkdir -p "$(dirname "$report_file")"
: > "$report_file"  # Clear the report file

collect_files() {
  if [[ "$mode" == "all" ]]; then
    find src/cses -mindepth 2 -maxdepth 2 -name '*.cpp' | sort
    return
  fi

  if [[ -z "$base_ref" ]]; then
    if git rev-parse --verify origin/main >/dev/null 2>&1; then
      base_ref="origin/main"
    else
      base_ref="HEAD~1"
    fi
  fi

  git diff --name-only --diff-filter=ACMR "$base_ref" "$head_ref" -- \
    | grep -E '^src/cses/.+\.cpp$' \
    | sort -u || true
}

count=0
issue_count=0
while IFS= read -r file; do
  [[ -n "$file" ]] || continue
  [[ -f "$file" ]] || continue

  problem_name="$(basename "$(dirname "$file")")"
  output="$(clang-tidy "$file" -p "$build_dir" 2>&1 || true)"

  {
    echo "================================================================================"
    echo "Problem: $problem_name"
    echo "File: $file"
    echo "================================================================================"
    echo "$output"
    echo ""
  } >> "$report_file"

  if echo "$output" | grep -Eq 'warning:|error:'; then
    issue_count=$((issue_count + 1))
    echo "Findings in $file"
    echo "$output" | grep -E 'warning:|error:' || true
  fi

  count=$((count + 1))
  echo "Processed $file"
done < <(collect_files)

if [[ $count -eq 0 ]]; then
  echo "No matching C++ files to analyze."
  exit 0
fi

echo "Generated clang-tidy report for $count file(s) at $report_file"

if [[ $fail_on_warnings -eq 1 && $issue_count -gt 0 ]]; then
  echo "clang-tidy reported findings in $issue_count file(s)."
  exit 1
fi


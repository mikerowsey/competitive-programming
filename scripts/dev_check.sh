#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$repo_root"

usage() {
  cat <<'EOF'
Usage: ./scripts/dev_check.sh [options]

Runs the standard local pre-push checks in one command:
  1) configure + build
  2) tests
  3) formatting check
  4) clang-tidy check

Options:
  --preset <name>     Configure/build preset to use (default: debug)
  --all-tidy          Run clang-tidy on all files instead of changed-only
  --skip-tests        Skip test execution
  --skip-format       Skip formatting check
  --skip-tidy         Skip clang-tidy check
  --help              Show this help
EOF
}

preset="debug"
run_tests=1
run_format=1
run_tidy=1
tidy_mode="changed"

while [[ $# -gt 0 ]]; do
  case "$1" in
    --preset)
      preset="${2:-}"
      shift
      ;;
    --all-tidy)
      tidy_mode="all"
      ;;
    --skip-tests)
      run_tests=0
      ;;
    --skip-format)
      run_format=0
      ;;
    --skip-tidy)
      run_tidy=0
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

build_dir="build/${preset}"

echo "==> Configure (${preset})"
cmake --preset "$preset"

echo "==> Build (${preset})"
cmake --build --preset "$preset"

if [[ $run_tests -eq 1 ]]; then
  echo "==> Test (${preset})"
  ctest --test-dir "$build_dir" --output-on-failure
fi

if [[ $run_format -eq 1 ]]; then
  echo "==> Formatting check"
  ./scripts/check_format.sh
fi

if [[ $run_tidy -eq 1 ]]; then
  echo "==> Clang-tidy (${tidy_mode})"
  if [[ "$tidy_mode" == "all" ]]; then
    ./scripts/run_clang_tidy_reports.sh --all --build-dir "$build_dir" --fail-on-warnings
  else
    ./scripts/run_clang_tidy_reports.sh --changed-only --build-dir "$build_dir" --fail-on-warnings
  fi
fi

echo "All requested checks passed."

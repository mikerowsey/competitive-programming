#!/usr/bin/env bash
set -euo pipefail

if ! command -v clang-format >/dev/null 2>&1; then
  echo "clang-format not found in PATH" >&2
  exit 1
fi

repo_root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$repo_root"

collect_files() {
  if [[ "${1:-}" == "--all" ]]; then
    git ls-files '*.cpp' '*.cc' '*.cxx' '*.hpp' '*.hh' '*.hxx'
    return
  fi

  # In CI, prefer branch-aware diffs. Locally, check unstaged+staged changes.
  if [[ -n "${GITHUB_BASE_REF:-}" ]]; then
    git fetch --no-tags --depth=1 origin "$GITHUB_BASE_REF" >/dev/null 2>&1 || true
    git diff --name-only "origin/$GITHUB_BASE_REF...HEAD" -- '*.cpp' '*.cc' '*.cxx' '*.hpp' '*.hh' '*.hxx'
    return
  fi

  if [[ -n "${GITHUB_EVENT_NAME:-}" && "${GITHUB_EVENT_NAME}" == "push" ]]; then
    if git rev-parse HEAD~1 >/dev/null 2>&1; then
      git diff --name-only HEAD~1..HEAD -- '*.cpp' '*.cc' '*.cxx' '*.hpp' '*.hh' '*.hxx'
    else
      git ls-files '*.cpp' '*.cc' '*.cxx' '*.hpp' '*.hh' '*.hxx'
    fi
    return
  fi

  {
    git diff --name-only -- '*.cpp' '*.cc' '*.cxx' '*.hpp' '*.hh' '*.hxx'
    git diff --cached --name-only -- '*.cpp' '*.cc' '*.cxx' '*.hpp' '*.hh' '*.hxx'
  }
}

files="$(collect_files "${1:-}" | awk 'NF' | awk '!seen[$0]++')"

if [[ -z "$files" ]]; then
  echo "No C++ files selected for formatting check."
  exit 0
fi

file_count="$(printf "%s\n" "$files" | wc -l | tr -d ' ')"
printf "%s\n" "$files" | xargs clang-format --dry-run --Werror

echo "Formatting check passed (${file_count} files)."

#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 2 || $# -gt 3 ]]; then
  echo "Usage: $0 <slug> <problem-title> [exact|semantic]" >&2
  echo "Example: $0 raab_game_i 'Raab Game I' semantic" >&2
  exit 1
fi

slug="$1"
problem_title="$2"
test_kind="${3:-exact}"

if [[ ! "$slug" =~ ^[a-z0-9_]+$ ]]; then
  echo "Slug must use lowercase letters, numbers, and underscores." >&2
  exit 1
fi

if [[ "$test_kind" != "exact" && "$test_kind" != "semantic" ]]; then
  echo "Third argument must be 'exact' or 'semantic'." >&2
  exit 1
fi

repo_root="$(cd "$(dirname "$0")/.." && pwd)"
problem_dir="$repo_root/src/cses/$slug"
cmake_registry_file="$repo_root/src/cses/CMakeLists.txt"

if [[ -e "$problem_dir" ]]; then
  echo "Problem directory already exists: $problem_dir" >&2
  exit 1
fi

mkdir -p "$problem_dir"

cat > "$problem_dir/main.cpp" <<EOF2
// Problem: ${problem_title}
//
// Pattern:
// Technique:
//
// Time:
// Space:
//
// Insight:
//

#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    (void)in;
    (void)out;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
EOF2

: > "$problem_dir/test_input.txt"
: > "$problem_dir/test_output.txt"

cat > "$problem_dir/notes.md" <<'EOF2'
# Notes

## Constraints
- Paste official input limits here.

## Complexity Budget
- Target time complexity:
- Target space complexity:

## Edge Cases Checklist
- Minimum n / empty-like cases
- Maximum constraints
- Monotonic or repeated values
- Potential overflow boundaries

## Approach Draft
- Pattern:
- Key invariant:
- Data structures:
EOF2

if [[ "$test_kind" == "semantic" ]]; then
  validator_name="validate_${slug}.cmake"
  validator_path="$repo_root/cmake/$validator_name"

  cat > "$problem_dir/test.config.cmake" <<'EOF2'
# Per-problem test metadata for CMake registration.
set(CP_TEST_KIND "semantic")
set(CP_TEST_TIMEOUT_SECONDS 5)
set(CP_TEST_VALIDATOR "${PROJECT_SOURCE_DIR}/cmake/__VALIDATOR_NAME__")
EOF2

  sed -i.bak "s|__VALIDATOR_NAME__|$validator_name|" "$problem_dir/test.config.cmake" && rm -f "$problem_dir/test.config.cmake.bak"

  cat > "$validator_path" <<'EOF2'
foreach(VAR INPUT OUTPUT)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

message(FATAL_ERROR "Replace this validator with semantic checks that inspect INPUT and OUTPUT.")
EOF2
else
  cat > "$problem_dir/test.config.cmake" <<'EOF2'
# Per-problem test metadata for CMake registration.
set(CP_TEST_KIND "exact")
set(CP_TEST_TIMEOUT_SECONDS 2)

# Optional perf smoke test (enabled with CP_ENABLE_PERF_TESTS).
# set(CP_PERF_ENABLED ON)
# set(CP_PERF_MAX_MS 200)
# set(CP_PERF_RUNS 5)
EOF2
fi

python3 - "$cmake_registry_file" "$slug" <<'PY'
from pathlib import Path
import sys

cmake_path = Path(sys.argv[1])
slug = sys.argv[2]
text = cmake_path.read_text(encoding='utf-8')
lines = text.splitlines()

start = None
end = None
for i, line in enumerate(lines):
    if line.strip() == 'set(CSES_PROBLEMS':
        start = i
        continue
    if start is not None and line.strip() == ')':
        end = i
        break

if start is None or end is None or end <= start:
    raise SystemExit('Could not locate set(CSES_PROBLEMS ...) block in src/cses/CMakeLists.txt')

entries = []
for line in lines[start + 1:end]:
    item = line.strip()
    if item:
        entries.append(item)

if slug not in entries:
    entries.append(slug)
entries = sorted(set(entries))

new_block = ['set(CSES_PROBLEMS'] + [f'    {item}' for item in entries] + [')']
new_lines = lines[:start] + new_block + lines[end + 1:]
cmake_path.write_text('\n'.join(new_lines) + '\n', encoding='utf-8')
PY

echo "Created: $problem_dir"
echo "Updated explicit registry: $cmake_registry_file"
echo "Next:"
echo "  1) Fill in main.cpp algorithm/header fields"
echo "  2) Add sample test_input.txt and test_output.txt"
echo "  3) Update notes.md while solving"
echo "  4) Run: cmake --preset debug && ctest --test-dir build/debug -R '^cses\\.${slug}$' --output-on-failure"

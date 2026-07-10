#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 2 ]]; then
  echo "Usage: $0 <slug> <problem-title>" >&2
  echo "Example: $0 raab_game_i 'Raab Game I'" >&2
  exit 1
fi

slug="$1"
problem_title="$2"

if [[ ! "$slug" =~ ^[a-z0-9_]+$ ]]; then
  echo "Slug must use lowercase letters, numbers, and underscores." >&2
  exit 1
fi

repo_root="$(cd "$(dirname "$0")/.." && pwd)"
problem_dir="$repo_root/src/cses/$slug"
tests_dir="$repo_root/src/cses/tests/$slug"
gtest_cases_dir="$tests_dir/gtest_cases"
cmake_registry_file="$repo_root/src/cses/CMakeLists.txt"
source_file="$problem_dir/$slug.cpp"
gtest_file="$tests_dir/${slug}_gtest.cpp"

if [[ -e "$problem_dir" || -e "$tests_dir" ]]; then
  echo "Problem or test directory already exists for slug: $slug" >&2
  exit 1
fi

mkdir -p "$problem_dir" "$gtest_cases_dir"

cat > "$source_file" <<EOF2
// Problem: ${problem_title}
//
// Pattern: TODO
// Technique: TODO
//
// Time: TODO
// Space: TODO
//
// Insight: TODO

#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    (void)in;
    (void)out;
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
#endif
EOF2

cat > "$gtest_file" <<EOF2
#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(${slug}_test, case_00)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/${slug}/gtest_cases/case_00_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/${slug}/gtest_cases/case_00_output.txt"));
}
EOF2

cat > "$gtest_cases_dir/case_00_input.txt" <<'EOF2'

EOF2

cat > "$gtest_cases_dir/case_00_output.txt" <<'EOF2'

EOF2

cat > "$problem_dir/notes.md" <<EOF2
# Problem: ${problem_title}

CSES URL: [https://cses.fi/problemset/task/TODO](https://cses.fi/problemset/task/TODO)

## Statement

Add a concise paraphrased statement here.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/TODO](https://cses.fi/problemset/task/TODO)

## Solution

Pattern: TODO

Technique: TODO

Time: TODO

Space: TODO

## Insight

Add the key invariant or proof sketch here.

## Edge Cases Checklist

- Minimum input size.
- Maximum constraints.
- Repeated values / ties (if applicable).
- Overflow boundaries (if applicable).
EOF2

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
echo "Created: $tests_dir"
echo "Updated explicit registry: $cmake_registry_file"
echo "Next:"
echo "  1) Fill in ${slug}.cpp algorithm and notes"
echo "  2) Add fixture content in src/cses/tests/${slug}/gtest_cases"
echo "  3) Run: cmake --preset debug-googletest && ctest --preset debug-googletest -R '^gtest\\.cses\\.${slug}\\.' --output-on-failure"

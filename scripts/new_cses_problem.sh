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

if [[ "$test_kind" == "semantic" ]]; then
  validator_name="validate_${slug}.cmake"
  validator_path="$repo_root/cmake/$validator_name"

  cat > "$problem_dir/test.config.cmake" <<'EOF2'
# Per-problem test metadata for CMake registration.
set(CP_TEST_KIND "semantic")
set(CP_TEST_TIMEOUT_SECONDS 5)
set(CP_TEST_VALIDATOR "__VALIDATOR_PATH__")
EOF2

  # Replace placeholder with a literal CMake variable reference.
  sed -i '' 's|__VALIDATOR_PATH__|${PROJECT_SOURCE_DIR}/cmake/'"$validator_name"'|' "$problem_dir/test.config.cmake"

  cat > "$validator_path" <<'EOF2'
foreach(VAR PROGRAM INPUT)
    if(NOT DEFINED ${VAR})
        message(FATAL_ERROR "${VAR} not specified")
    endif()
endforeach()

message(FATAL_ERROR "Replace this validator with semantic checks for the problem.")
EOF2
else
  cat > "$problem_dir/test.config.cmake" <<'EOF2'
# Per-problem test metadata for CMake registration.
set(CP_TEST_KIND "exact")
set(CP_TEST_TIMEOUT_SECONDS 2)
EOF2
fi

echo "Created: $problem_dir"
echo "Next:"
echo "  1) Fill in main.cpp algorithm/header fields"
echo "  2) Add sample test_input.txt and test_output.txt"
echo "  3) Run: cmake --preset debug && ctest --test-dir build/debug -R '^cses\\.${slug}$' --output-on-failure"

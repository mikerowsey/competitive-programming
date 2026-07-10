# Architecture

## Mission Statement

Use competitive programming as a vehicle to build professional software engineering skills.

This repository optimizes for:

- correct and efficient algorithms
- clean, idiomatic C++
- repeatable local verification
- maintainable project structure as the number of solved problems grows

Accepted submissions are required, but engineering quality is the main product.

## Current Structure

```text
competitive-programming/
  CMakeLists.txt
  CMakePresets.json
  cmake/
  docs/
  scripts/
  src/
    cses/
      <problem_slug>/
        <problem_slug>.cpp
      tests/
        gtest_case_utils.hpp
        <problem_slug>/
          <problem_slug>_gtest.cpp
          gtest_cases/
            case_00_input.txt
            case_00_output.txt
```

Each problem directory is an independent executable target.

## Build and Test Model

### Build

- Root CMake config sets global compiler defaults.
- `src/cses/CMakeLists.txt` uses an explicit `CSES_PROBLEMS` registry.
- `.wip` marker excludes unfinished problems from build/test discovery.

### Test

- gtest test targets are generated as `<problem_slug>_gtest` when a wrapper exists.
- CTest test name format is generated through `gtest_discover_tests` with prefix `gtest.cses.<problem_slug>.`.
- Shared assertions and semantic validators live in `src/cses/tests/gtest_case_utils.hpp`.

## Problem Ownership Rules

Each problem folder owns:

- implementation (`<problem_slug>.cpp`)

Each problem test folder owns:

- gtest wrapper (`src/cses/tests/<problem_slug>/<problem_slug>_gtest.cpp`)
- local fixtures (`src/cses/tests/<problem_slug>/gtest_cases/*`)

This keeps problem context local and reduces cross-file coupling.

## Coding Rules (High Level)

- Prefer algorithmic optimality before micro-optimizations.
- Keep code explicit and readable.
- Use fixed-width integer types intentionally.
- Keep CSES assumptions practical (judge input is valid).
- Use dependency-injected solve signatures where practical (`solve(std::istream&, std::ostream&)`).

## Header Convention for Problem Files

Solution headers follow this order:

1. Problem
2. blank line
3. Pattern
4. Technique
5. blank line
6. Time
7. Space
8. blank line
9. Insight

## Why This Design

- One executable per problem avoids hidden coupling.
- Explicit registration keeps build target changes intentional and reviewable.
- gtest + CTest discovery gives immediate correctness feedback.
- Shared semantic validators prevent false failures on multi-answer problems.
- Scripted scaffolding keeps conventions consistent with low friction.

## CI and Quality Gates

- GitHub Actions validates debug-googletest configure/build/test on Ubuntu and macOS.
- Formatting gate runs via `scripts/check_format.sh`.
- ASan/UBSan + googletest job runs on Linux for undefined behavior and memory bugs.

## Near-Term Improvements

- Keep CSES problem index in docs synchronized with solved set and milestones.
- Add optional benchmark harness for selected heavier tasks.
- Add optional sanitizer preset expansion and tuning for macOS/Linux parity.

## Long-Term Goal

A reviewer should see this repository and conclude:
"This developer can write correct algorithms and engineer maintainable systems around them."

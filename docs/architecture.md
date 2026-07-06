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
        main.cpp
        test_input.txt
        test_output.txt
        test.config.cmake (optional)
```

Each problem directory is an independent executable target.

## Build and Test Model

### Build

- Root CMake config sets global compiler defaults.
- `src/cses/CMakeLists.txt` registers one executable per problem directory.
- `.wip` marker excludes unfinished problems from build/test discovery.

### Test

- CTest test name format: `cses.<problem_slug>`.
- Two test kinds are supported via per-problem metadata:
  - `exact`: compare output to fixture with normalized line endings/whitespace
  - `semantic`: run a validator script for multi-answer tasks

Per-problem metadata file (`test.config.cmake`) can define:

- `CP_TEST_KIND`
- `CP_TEST_TIMEOUT_SECONDS`
- `CP_TEST_VALIDATOR`

## Problem Ownership Rules

Each problem folder owns:

- implementation (`main.cpp`)
- local fixtures (`test_input.txt`, `test_output.txt`)
- optional test metadata (`test.config.cmake`)

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
- CTest wiring gives immediate correctness feedback.
- Semantic validators prevent false failures on multi-answer problems.
- Scripted scaffolding keeps conventions consistent with low friction.

## Near-Term Improvements

- Replace glob-based problem discovery with an explicit registry/manifest.
- Add CI to run configure, build, and tests on push/PR.
- Add optional sanitizer preset(s) for infrastructure hardening.

## Long-Term Goal

A reviewer should see this repository and conclude:
"This developer can write correct algorithms and engineer maintainable systems around them."

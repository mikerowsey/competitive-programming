# Competitive Programming Engineering Repo

## Mission Statement

Build professional software engineering habits through competitive programming.

This repository uses CSES problems as a training ground for:

- algorithmic reasoning and complexity discipline
- clean, idiomatic modern C++
- reproducible build and test infrastructure with CMake/CTest
- scalable project conventions that keep many small executables maintainable

The objective is not just to get Accepted submissions.
The objective is to produce solutions and infrastructure that hold up under a professional code review.

## What This Repo Is

- A multi-target C++ project where each problem is its own executable.
- A test-driven workflow using per-problem input/output fixtures.
- A metadata-driven CTest setup that supports both:
  - exact-output validation
  - semantic validation for multi-answer problems

## Milestone Status

- CSES Introductory Problems: complete
- Local verification status: 24/24 tests passing

## Quick Start

1. Configure:

```bash
cmake --preset debug
```

2. Build:

```bash
cmake --build --preset debug
```

3. Run all tests:

```bash
ctest --test-dir build/debug --output-on-failure
```

4. Run one problem test:

```bash
ctest --test-dir build/debug -R '^cses\.weird_algorithm$' --output-on-failure
```

5. Run formatting gate:

```bash
./scripts/check_format.sh
```

6. Run performance smoke tests (selected problems):

```bash
cmake --preset perf
cmake --build --preset perf
ctest --preset perf
```

## Project Docs

- Architecture and standards: [docs/architecture.md](docs/architecture.md)
- CSES coding philosophy: [docs/cses-cpp-philosophy.md](docs/cses-cpp-philosophy.md)
- Solved problem index: [docs/cses-problems.md](docs/cses-problems.md)

## Scaffolding

Use the helper to create a new CSES problem folder and files:

```bash
./scripts/new_cses_problem.sh <slug> "Problem Title" [exact|semantic]
```

The scaffolder now also updates the explicit problem registry in `src/cses/CMakeLists.txt`.

## CI

GitHub Actions runs:

- debug configure/build/test on Ubuntu and macOS
- clang-format gate
- ASan/UBSan test pass
- scheduled/manual perf smoke run

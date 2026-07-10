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
- A gtest-driven workflow using per-problem fixture files under `src/cses/tests/<problem>/gtest_cases`.

## Milestone Status

- CSES Introductory Problems: complete
- Local verification status: 24/24 tests passing

## Quick Start

Daily one-command check (recommended before push):

```bash
./scripts/dev_check.sh
```

1. Configure:

```bash
cmake --preset debug-googletest
```

1. Build:

```bash
cmake --build --preset debug-googletest
```

1. Run all tests:

```bash
ctest --preset debug-googletest --output-on-failure
```

1. Run one problem test:

```bash
ctest --preset debug-googletest -R '^gtest\.cses\.weird_algorithm\.' --output-on-failure
```

1. Run formatting gate:

```bash
./scripts/check_format.sh
```

1. Run clang-tidy on changed files:

```bash
cmake --preset debug-googletest
./scripts/run_clang_tidy_reports.sh --changed-only --fail-on-warnings
```

`dev_check.sh` options:

```bash
./scripts/dev_check.sh --preset debug-googletest
./scripts/dev_check.sh --skip-tidy
./scripts/dev_check.sh --all-tidy
```

## Project Docs

- Architecture and standards: [docs/architecture.md](docs/architecture.md)
- CSES coding philosophy: [docs/cses-cpp-philosophy.md](docs/cses-cpp-philosophy.md)
- Solved problem index: [docs/cses-problems.md](docs/cses-problems.md)

## Scaffolding

Use the helper to create a new CSES problem folder and files:

```bash
./scripts/new_cses_problem.sh <slug> "Problem Title"
```

The scaffolder now also updates the explicit problem registry in `src/cses/CMakeLists.txt`.

## CI

GitHub Actions runs:

- debug-googletest configure/build/test on Ubuntu (push/PR)
- debug-googletest configure/build/test on macOS (weekly/manual)
- clang-format gate
- clang-tidy on changed files for push/PR
- ASan/UBSan + googletest test pass
- scheduled/manual full-repo clang-tidy report

## Advanced Presets (Optional)

Daily local usage does not require platform-specific release presets. Use these only for compiler/toolchain parity when needed.

```bash
cmake --preset release-macos-llvm
cmake --build --preset release-macos-llvm

cmake --preset release-linux-gcc
cmake --build --preset release-linux-gcc
```

## Clang-Tidy Setup

To use clang-tidy on your local machine (macOS with homebrew llvm):

1. Run the setup script once:

```bash
./scripts/macos-setup-clang-tidy.sh
```

This will:

- Create a symlink: `~/.local/bin/clang-tidy`
- Guide you to add env vars to your stow-managed `.zprofile`
- Validate the setup

1. Add this to your `.zprofile` (inside the homebrew guard):

```bash
# LLVM toolchain (default C/C++ compiler)
export CC=/opt/homebrew/opt/llvm/bin/clang
export CXX=/opt/homebrew/opt/llvm/bin/clang++
export SDKROOT=$(xcrun --show-sdk-path)
```

1. Run clang-tidy for changed files (default local loop):

```bash
cmake --preset debug-googletest
./scripts/run_clang_tidy_reports.sh --changed-only --fail-on-warnings
```

1. Generate full-repo clang-tidy report manually:

```bash
cmake --preset clang-tidy
./scripts/run_clang_tidy_reports.sh --all --build-dir build/clang-tidy
```

CI full report path: `build/clang-tidy/clang-tidy-report.txt`.

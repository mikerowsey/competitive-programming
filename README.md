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

Daily one-command check (recommended before push):

```bash
./scripts/dev_check.sh
```

1. Configure:

```bash
cmake --preset debug
```

1. Build:

```bash
cmake --build --preset debug
```

1. Run all tests:

```bash
ctest --test-dir build/debug --output-on-failure
```

1. Run one problem test:

```bash
ctest --test-dir build/debug -R '^cses\.weird_algorithm$' --output-on-failure
```

1. Run formatting gate:

```bash
./scripts/check_format.sh
```

1. Run performance smoke tests (selected problems):

```bash
cmake --preset perf
cmake --build --preset perf
ctest --preset perf
```

1. Run clang-tidy on changed files:

```bash
cmake --preset debug
./scripts/run_clang_tidy_reports.sh --changed-only --fail-on-warnings
```

`dev_check.sh` options:

```bash
./scripts/dev_check.sh --preset debug-macos-llvm
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
./scripts/new_cses_problem.sh <slug> "Problem Title" [exact|semantic]
```

The scaffolder now also updates the explicit problem registry in `src/cses/CMakeLists.txt`.

## CI

GitHub Actions runs:

- debug configure/build/test on Ubuntu (push/PR)
- debug configure/build/test on macOS (weekly/manual)
- clang-format gate
- clang-tidy on changed files for push/PR
- ASan/UBSan test pass
- scheduled/manual perf smoke run
- scheduled/manual full-repo clang-tidy report

## Advanced Presets (Optional)

Daily local usage does not require platform presets. Use these only for compiler parity with CI/toolchains or when troubleshooting platform/compiler-specific behavior.

macOS + Homebrew LLVM:

```bash
cmake --preset debug-macos-llvm
cmake --build --preset debug-macos-llvm

cmake --preset release-macos-llvm
cmake --build --preset release-macos-llvm
```

Linux + GCC:

```bash
cmake --preset debug-linux-gcc
cmake --build --preset debug-linux-gcc

cmake --preset release-linux-gcc
cmake --build --preset release-linux-gcc
```

Clang-tidy platform variants:

```bash
cmake --preset clang-tidy-macos-llvm
cmake --build --preset clang-tidy-macos-llvm

cmake --preset clang-tidy-linux-gcc
cmake --build --preset clang-tidy-linux-gcc
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
cmake --preset debug
./scripts/run_clang_tidy_reports.sh --changed-only --fail-on-warnings
```

Linux VM (preset-specific path):

```bash
cmake --preset clang-tidy-linux-gcc
./scripts/run_clang_tidy_reports.sh --changed-only --build-dir build/clang-tidy-linux-gcc --fail-on-warnings
```

1. Generate full-repo clang-tidy report manually:

```bash
cmake --preset clang-tidy
./scripts/run_clang_tidy_reports.sh --all --build-dir build/clang-tidy
```

Linux CI full report path: `build/clang-tidy-linux-gcc/clang-tidy-report.txt`.

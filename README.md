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
- A CTest-driven test workflow using per-problem fixture files under `tests/<problem>/gtest_cases`.

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
cmake --preset test
```

1. Build:

```bash
cmake --build --preset test
```

1. Run all tests:

```bash
ctest --preset test --output-on-failure
```

1. Run one problem test:

```bash
ctest --preset test -R '^gtest\.cses\.weird_algorithm\.' --output-on-failure
```

Note: current test naming uses the `gtest.cses.<problem>.` prefix.

1. Run formatting gate:

```bash
./scripts/check_format.sh
```

1. Run clang-tidy on changed files:

```bash
cmake --preset tidy
./scripts/run_clang_tidy_reports.sh --changed-only --fail-on-warnings
```

`dev_check.sh` options:

```bash
./scripts/dev_check.sh --preset test
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

- test configure/build/test on Ubuntu (push/PR)
- test configure/build/test on macOS (weekly/manual)
- clang-format gate
- clang-tidy on changed files for push/PR
- ASan/UBSan + test pass
- scheduled/manual full-repo clang-tidy report

## Release Preset (Optional)

The release preset uses whatever compiler and flags your environment is configured to use.

```bash
cmake --preset release
cmake --build --preset release
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

1. Ensure your environment is configured the way you want before running CMake presets.

Example for Homebrew LLVM on macOS:

```bash
export CC=/opt/homebrew/opt/llvm/bin/clang
export CXX=/opt/homebrew/opt/llvm/bin/clang++
export SDKROOT=$(xcrun --show-sdk-path)
```

1. Run clang-tidy for changed files (default local loop):

```bash
cmake --preset tidy
./scripts/run_clang_tidy_reports.sh --changed-only --fail-on-warnings
```

1. Generate full-repo clang-tidy report manually:

```bash
cmake --preset tidy
./scripts/run_clang_tidy_reports.sh --all --build-dir build/tidy
```

CI full report path: `build/tidy/clang-tidy-report.txt`.

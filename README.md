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

## Project Docs
- Architecture and standards: [docs/architecture.md](docs/architecture.md)
- CSES coding philosophy: [docs/cses-cpp-philosophy.md](docs/cses-cpp-philosophy.md)

## Scaffolding
Use the helper to create a new CSES problem folder and files:
```bash
./scripts/new_cses_problem.sh <slug> "Problem Title" [exact|semantic]
```

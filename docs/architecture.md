# Competitive Programming Workshop

## Mission

This repository is **not** primarily a collection of competitive programming solutions.

Its purpose is to develop professional-level C++ engineering skills by solving competitive programming problems.

Each problem serves as a customer of a growing reusable library and build system.

The goals are:

- Learn modern C++
- Learn software architecture
- Learn modern CMake
- Learn reusable library design
- Learn testing and benchmarking
- Learn professional development workflow

The number of solved problems is secondary.

---

# Architectural Principles

## Explicit over implicit

Everything should be explicit.

Examples:

- Explicit directory structure
- Explicit CMake targets
- Explicit includes
- Explicit compiler settings

Avoid automatic discovery such as:

- `file(GLOB ...)`
- hidden dependencies
- implicit include chains

---

## Introduce abstractions only after they are needed

Abstractions should solve existing problems.

Do not build infrastructure for imagined future needs.

Examples:

- Build `Scanner` after repeated parsing code exists.
- Create helper CMake functions only after sufficient duplication exists.
- Add libraries only when they provide measurable value.

---

## Every directory has one responsibility

```
include/    Reusable library
src/        Applications
docs/       Documentation
tests/      Unit tests
scratch/    Experiments
scripts/    Automation
```

---

## Every problem is an application

Each problem is an independent executable.

Current layout:

```
src/
    cses/
        introductory/
            weird_algorithm/
            missing_number/
```

Each problem owns:

- source
- build configuration
- future notes
- future benchmarks

Problems consume the library.

Problems never become part of the library.

---

## The library must remain generic

The reusable library should have no knowledge of:

- CSES
- LeetCode
- Codeforces
- Advent of Code

It should be usable in any C++ project.

Good:

```
io/scanner.hpp
graph/graph.hpp
math/modint.hpp
```

Bad:

```
cses_scanner.hpp
missing_number.hpp
```

---

## Organize by responsibility

Avoid vague names.

Avoid:

```
helpers
utils
misc
common
```

Prefer:

```
core
io
graph
math
containers
algorithm
profiling
```

Each directory should communicate its purpose.

---

# Directory Layout

```
competitive-programming/

    include/

    src/
        cses/
            introductory/

    tests/

    docs/

    scratch/

    scripts/

    CMakeLists.txt
    CMakePresets.json
```

---

# Build System

The project uses recursive CMake.

Responsibilities:

Root
: project configuration

src
: applications

problem groups
: organization

problem
: executable

Each `CMakeLists.txt` should only manage its own level.

---

# Coding Philosophy

Prefer:

- header-only reusable components where appropriate
- modern C++
- RAII
- value semantics
- explicit initialization
- fixed-width integer types
- clean interfaces
- dependency injection (`std::istream`, `std::ostream`)

Avoid:

- unnecessary globals
- premature optimization
- unnecessary inheritance
- `using namespace std`

---

# Evolution

The project should evolve naturally.

Typical progression:

Problem
→ repeated code
→ reusable component
→ library module

Never the reverse.

---

# Current Status

Version 1

Completed:

- recursive CMake
- modern target-based build
- compiler warnings
- C++23
- one executable per problem
- one directory per problem

Current problems:

- Weird Algorithm
- Missing Number

Next milestone:

Create the first reusable library component.
Likely:

```
include/
    core/
        types.hpp
```

followed later by

```
io/
    scanner.hpp
```

only after sufficient repetition exists.

---

# Long-Term Goal

A developer reviewing this repository should conclude:

> "This was built by someone who understands software engineering."

Competitive programming is the vehicle.

Engineering is the destination.

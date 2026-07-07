# CSES C++ Philosophy

## Priorities (in order)

1. Best algorithmic approach first.
2. Idiomatic modern C++ implementation.
3. Clean, descriptive, maintainable code.
4. Fast execution details (constant factors, I/O, memory locality).

## Practical Rules

- Solve for asymptotic complexity before micro-optimizations.
- Use descriptive names for data structures and state.
- Keep functions small and single-purpose when it improves readability.
- Prefer standard library tools over custom low-level code unless constraints justify otherwise.
- Use integer widths intentionally.
- Avoid clever one-liners when they hurt readability.
- Keep memory usage predictable and proportional to constraints.

## CSES-Specific Conventions

- Assume judge input is valid; do not add defensive input guards unless explicitly requested.
- Prefer straightforward, portable constructs over fragile feature usage.
- Avoid unnecessary abstraction in short single-file solutions.
- Prefer problem-name-first communication and references.
- Keep code clang-format clean to pass the style gate.

## Header Template for `notes.md`

Use this exact section order:

1. `// Problem: ...`
2. blank line (`//`)
3. `// Pattern: ...`
4. `// Technique: ...`
5. blank line (`//`)
6. `// Time: ...`
7. `// Space: ...`
8. blank line (`//`)
9. `// Insight:`

Keep `main.cpp` minimal: the top comment should only identify the problem.

## Solution Checklist

- [ ] Time complexity is optimal or near-optimal for constraints.
- [ ] Space complexity is justified.
- [ ] Edge cases are covered.
- [ ] Names are descriptive and code reads top-down.
- [ ] No unnecessary abstractions.
- [ ] Passes local fixture-based tests.
- [ ] Passes optional perf smoke budget when enabled.

## Review Order

1. Confirm algorithmic optimality.
2. Confirm correctness and edge-case behavior.
3. Improve readability and maintainability.
4. Apply micro-optimizations only when useful.

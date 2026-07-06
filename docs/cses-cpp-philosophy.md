# CSES C++ Philosophy

## Priorities (in order)

1. Best algorithmic approach first.
2. Idiomatic modern C++ implementation.
3. Clean, descriptive, maintainable code.
4. Fast execution details (constant factors, I/O, memory locality).

## Practical rules

- Solve for asymptotic complexity before micro-optimizations.
- Use descriptive names for data structures and state (`current_sum`, `max_prefix`, `adjacency_list`).
- Keep functions small and single-purpose when it improves readability.
- Prefer standard library containers and algorithms over custom low-level code unless profiling or constraints justify otherwise.
- Use `const` aggressively for inputs and non-mutating locals.
- Avoid clever one-liners when they reduce clarity.
- Keep I/O setup explicit and fast:
  - `ios::sync_with_stdio(false);`
  - `cin.tie(nullptr);`
- Use integer widths intentionally (`int`, `long long`) based on constraints.
- Keep memory usage predictable and proportional to constraints.

## CSES solution checklist

- [ ] Time complexity is optimal or near-optimal for known CSES constraints.
- [ ] Space complexity is justified and acceptable.
- [ ] Edge cases are handled (empty/smallest/largest/input extremes).
- [ ] Names are descriptive and code reads top-down.
- [ ] No unnecessary abstractions for short competitive solutions.
- [ ] Passes local input/output tests.

## Review rubric for this repo

When reviewing or modifying a solution in this repository:

1. Confirm algorithmic optimality first.
2. Improve correctness and edge-case handling second.
3. Refactor toward idiomatic C++ and readability third.
4. Apply micro-optimizations last, only when measurable or clearly beneficial.

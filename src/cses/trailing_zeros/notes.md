# Notes

## Problem Header

// Problem: Trailing Zeros
//
// Pattern: Mathematical Observation
// Technique: Repeated Division
//
// Time: O(log₅ n)
// Space: O(1)
//
// Insight:
//   Each trailing zero is produced by a factor of 10 = 2 × 5. Since there
//   are always more factors of 2 than 5 in n!, count the number of factors
//   of 5 by repeatedly dividing n by powers of 5.

## Constraints

- Paste official input limits here.

## Complexity Budget

- Target time complexity:
- Target space complexity:

## Edge Cases Checklist

- Minimum n / empty-like cases
- Maximum constraints
- Monotonic or repeated values
- Potential overflow boundaries

## Approach Draft

- Pattern:
- Key invariant:
- Data structures:

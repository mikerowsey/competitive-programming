# Notes

## Problem Header

// Problem: Creating Strings
//
// Pattern: Enumeration
// Technique: Lexicographic permutation generation
//
// Time: O(n! · n)
// Space: O(n)
//
// Insight:
//   Sort the characters first, then repeatedly call std::next_permutation().
//   Starting from the lexicographically smallest arrangement guarantees that
//   every distinct permutation is generated exactly once, even when duplicate
//   characters are present.

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

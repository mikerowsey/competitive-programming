# Notes

## Problem Header

// Problem: Mex Grid Construction
//
// Pattern: Constructive Math
// Technique: Bitwise XOR Table
//
// Time: O(n^2)
// Space: O(1)
//
// Insight:
//   The unique mex-defined grid equals `a[i][j]` = i xor j (0-indexed).
//   For each cell, the union of values to the left in the same row and
//   above in the same column contains every value smaller than (i xor j),
//   while (i xor j) itself is absent, so mex is exactly (i xor j).
//

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

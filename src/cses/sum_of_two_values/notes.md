# Notes

## Problem Header

// Problem: Sum of Two Values
//
// Pattern: Two pointers on sorted data
// Technique: Sort `(index, value)` pairs, then move inward from both ends.
//
// Time: O(n log n).
// Space: O(n).
//
// Insight: After sorting, if the current pair is too small, only the left
// pointer can increase the sum; if it is too large, only the right pointer
// can decrease it.

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

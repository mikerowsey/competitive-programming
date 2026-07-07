# Notes

## Problem Header

// Problem: Apartments
//
// Pattern: Greedy matching
// Technique: Sort both lists and advance two pointers.
//
// Time: O(n log n + m log m).
// Space: O(n + m).
//
// Insight: After sorting, if the current apartment is too small for the
// current applicant even with tolerance, it cannot satisfy any later
// applicant; likewise, if it is too large, the current applicant cannot
// match any later apartment.

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

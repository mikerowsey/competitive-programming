# Notes

## Problem Header

// Problem: Apple Division
//
// Pattern: Depth-First Search
// Technique: Branch and Bound
//
// Time: O(2^n)
// Space: O(n)
//
// Insight:
//   Sort the weights in descending order and assign each apple to one of
//   two groups using DFS. At each step, compare the current weight
//   difference with the total remaining weight. If the remaining apples
//   cannot improve the current best possible difference, prune the branch
//   immediately.

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

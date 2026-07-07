# Notes

## Problem Header

// Problem: Grid Path Description
//
// Pattern: Backtracking Search
// Technique: DFS with Corridor Pruning
//
// Time: O(search states), fast enough with pruning
// Space: O(1) extra (fixed board + recursion depth 48)
//
// Insight:
//   Search all paths on a 7x7 board that match the description string.
//   Prune states that split the unvisited area into disconnected parts and
//   force moves into one-exit neighbors to avoid sealing cells early.
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

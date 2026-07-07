# Notes

## Problem Header

// Problem: Raab Game I
//
// Pattern: Constructive Algorithm
// Technique: Block Permutation Construction
//
// Time: O(n)
// Space: O(n)
//
// Insight:
//   Fix one player's order as 1..n, then build the other order from
//   consecutive blocks. A block of size m can contribute either (m - 1, 1)
//   or (1, m - 1) wins, and size-2 blocks contribute (1, 1). This lets us
//   realize every feasible score pair by combining one larger block, some
//   size-2 blocks, and the remaining ties.

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

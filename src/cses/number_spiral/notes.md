# Notes

## Problem Header

// Problem: Number Spiral
//
// Pattern: Mathematical Observation
// Technique: Layer-Based Coordinate Mapping
//
// Time: O(t)
// Space: O(1)
//
// Insight:
//   Every coordinate lies on a square layer whose side length is max(row,
//   column). The center value of that layer is layer * (layer - 1) + 1.
//   The answer is an offset from the center determined by the parity of the
//   layer.

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

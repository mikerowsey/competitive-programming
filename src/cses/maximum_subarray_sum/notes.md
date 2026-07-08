# Notes

## Problem Header

// Problem: Maximum Subarray Sum
//
// Pattern: Prefix sums with extrema tracking
// Technique: Single pass, track running min and max
//
// Time: O(n)
// Space: O(n)
//
// Insight: Maximum subarray sum = max(prefix[i] - min(prefix[0..i-1]))

## Constraints

- 1 ≤ n ≤ 2·10⁵
- -10⁹ ≤ a_i ≤ 10⁹
- Sum may not fit in 32-bit signed integer; use int64_t

## Complexity Budget

- Target time complexity: O(n)
- Target space complexity: O(n)

## Edge Cases Checklist

- [ ] n = 1 (single element is max subarray)
- [ ] All negative values (take single least negative element)
- [ ] All positive values (take entire array)
- [ ] Overflow: sums can reach ±2·10¹⁴

## Approach Draft

- Pattern: Prefix sum + min tracking
- Key invariant: For each position i, compute sums[i] - minimum prefix seen before i
- Data structures: Vector for prefix sums, scalars for running min/max

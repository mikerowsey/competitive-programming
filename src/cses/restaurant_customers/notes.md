# Notes

## Problem Header

// Problem: Restaurant Customers
//
// Pattern: Sweep line
// Technique: Convert arrivals and departures into signed events, sort them,
// and scan a running count.
//
// Time: O(n log n).
// Space: O(n).
//
// Insight: At equal timestamps, departures must be processed before arrivals
// so customers who leave at time t are not counted together with customers
// who arrive at time t.

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

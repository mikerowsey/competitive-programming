# Problem: Maximum Subarray Sum

CSES URL: [https://cses.fi/problemset/task/1643](https://cses.fi/problemset/task/1643)

## Statement

Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1643](https://cses.fi/problemset/task/1643)

## Solution

Pattern: Prefix sums with extrema tracking

Technique: Single pass, track running min and max

Time: O(n)

Space: O(n)

## Insight

Maximum subarray sum = max(prefix[i] - min(prefix[0..i-1]))

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

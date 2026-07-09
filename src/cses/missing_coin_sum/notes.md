# Problem: Missing Coin Sum

CSES URL: [https://cses.fi/problemset/task/2183](https://cses.fi/problemset/task/2183)

## Statement

Given coin values, find the smallest positive integer that cannot be formed as a sum of some subset of the coins.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/2183](https://cses.fi/problemset/task/2183)

## Solution

Pattern: Greedy after sorting

Technique: Maintain reachable prefix sum range

Time: O(n log n)

Space: O(1) extra (excluding sort)

## Insight

If values up to x are currently constructible, the next coin c can extend this
range only when c <= x + 1. Otherwise x + 1 is the first missing sum.

## Edge Cases Checklist

- n = 1 with coin 1 and with coin > 1.
- Duplicate coin values.
- Early gap after sorting (first coin not equal to 1).
- Large cumulative sums requiring 64-bit integers.

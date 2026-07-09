# Problem: Sum of Two Values

CSES URL: [https://cses.fi/problemset/task/1640](https://cses.fi/problemset/task/1640)

## Statement

You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1640](https://cses.fi/problemset/task/1640)

## Solution

Pattern: Two pointers on sorted data

Technique: Sort `(index, value)` pairs, then move inward from both ends.

Time: O(n log n).

Space: O(n).

## Insight

After sorting, if the current pair is too small, only the left
pointer can increase the sum; if it is too large, only the right pointer
can decrease it.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

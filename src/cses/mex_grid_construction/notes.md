# Problem: Mex Grid Construction

CSES URL: [https://cses.fi/problemset/task/3419](https://cses.fi/problemset/task/3419)

## Statement

Your task is to construct an n imes n grid where each square has the smallest nonnegative integer that does not appear to the left on the same row or above on the same column.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/3419](https://cses.fi/problemset/task/3419)

## Solution

Pattern: Constructive Math

Technique: Bitwise XOR Table

Time: O(n^2)

Space: O(1)

## Insight

The unique mex-defined grid equals `a[i][j]` = i xor j (0-indexed).
For each cell, the union of values to the left in the same row and
above in the same column contains every value smaller than (i xor j),
while (i xor j) itself is absent, so mex is exactly (i xor j).

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

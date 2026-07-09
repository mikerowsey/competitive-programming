# Problem: Collecting Numbers

CSES URL: [https://cses.fi/problemset/task/2216](https://cses.fi/problemset/task/2216)

## Statement

Given a permutation of 1..n, determine how many left-to-right rounds are needed to collect numbers in increasing order.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/2216](https://cses.fi/problemset/task/2216)

## Solution

Pattern: Position-array scan

Technique: Count order breaks between consecutive values

Time: O(n)

Space: O(n)

## Insight

If `pos[x] > pos[x + 1]`, then value `x + 1` must be collected in a later round than `x`. The answer is `1 +` the number of such breaks.

## Edge Cases Checklist

- n = 1.
- Already increasing permutation.
- Strictly decreasing permutation.
- Breaks clustered near ends of the permutation.

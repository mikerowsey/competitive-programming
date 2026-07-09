# Problem: Distinct Numbers

CSES URL: [https://cses.fi/problemset/task/1621](https://cses.fi/problemset/task/1621)

## Statement

You are given a list of n integers, and your task is to calculate the number of distinct values in the list.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1621](https://cses.fi/problemset/task/1621)

## Solution

Pattern: Count unique values in a batch.

Technique: Read all values, sort them, and count changes between neighbors.

Time: O(n log n).

Space: O(n).

## Insight

Sorting groups equal values together, so one linear scan counts
the distinct numbers.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

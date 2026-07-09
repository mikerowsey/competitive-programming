# Problem: Two Sets

CSES URL: [https://cses.fi/problemset/task/1092](https://cses.fi/problemset/task/1092)

## Statement

Your task is to divide the numbers 1,2,\ldots,n into two sets of equal sum.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1092](https://cses.fi/problemset/task/1092)

## Solution

Pattern: Greedy

Technique: Largest-First Partition

Time: O(n)

Space: O(n)

## Insight

If the total sum is odd, no partition exists. Otherwise, repeatedly
take the largest value that does not exceed the remaining target sum.
This greedy strategy constructs one valid partition in a single pass.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

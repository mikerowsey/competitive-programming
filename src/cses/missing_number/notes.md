# Problem: Missing Number

CSES URL: [https://cses.fi/problemset/task/1083](https://cses.fi/problemset/task/1083)

## Statement

You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1083](https://cses.fi/problemset/task/1083)

## Solution

Pattern: Mathematical Formula

Technique: Arithmetic sum comparison

Time: O(n)

Space: O(1)

## Insight

Compute the expected sum of 1..n using the arithmetic series formula,
subtract the actual sum, and the difference is the missing number.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

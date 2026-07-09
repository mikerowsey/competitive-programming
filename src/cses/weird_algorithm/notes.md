# Problem: Weird Algorithm

CSES URL: [https://cses.fi/problemset/task/1068](https://cses.fi/problemset/task/1068)

## Statement

Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the...

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1068](https://cses.fi/problemset/task/1068)

## Solution

Pattern: Simulation

Technique: Iterative State Update

Time: O(k) k = number of terms generated

Space: O(1)

## Insight

Repeatedly apply the Collatz rules until reaching 1. Each iteration updates
the current value in place, so only constant extra memory is required.

## Edge Cases Checklist

- n = 1 should print exactly `1`.
- Very short chains (for example n = 2) should terminate correctly.
- Odd values must use `3n + 1`, then continue with even halving.
- Output must be space-separated values on one line.

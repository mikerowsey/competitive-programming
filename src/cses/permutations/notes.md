# Problem: Permutations

CSES URL: [https://cses.fi/problemset/task/1070](https://cses.fi/problemset/task/1070)

## Statement

A permutation of integers 1,2,\ldots,n is called beautiful if there are no adjacent elements whose difference is 1.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1070](https://cses.fi/problemset/task/1070)

## Solution

Pattern: Constructive Algorithm

Technique: Even-Odd Ordering

Time: O(n)

Space: O(1)

## Insight

Adjacent numbers differ by at least two when all even numbers are listed
first, followed by all odd numbers. The only exceptions are n = 2 and
n = 3, where no valid permutation exists.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

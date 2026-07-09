# Problem: Tower of Hanoi

CSES URL: [https://cses.fi/problemset/task/2165](https://cses.fi/problemset/task/2165)

## Statement

The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/2165](https://cses.fi/problemset/task/2165)

## Solution

Pattern: Recursion

Technique: Divide and Conquer

Time: O(2^n)

Space: O(n)

## Insight

To move n disks from source to destination, first move n - 1 disks to
the auxiliary peg, move the largest disk to the destination, then move
the n - 1 disks from the auxiliary peg to the destination.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

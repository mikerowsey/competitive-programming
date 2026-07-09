# Problem: Gray Code

CSES URL: [https://cses.fi/problemset/task/2205](https://cses.fi/problemset/task/2205)

## Statement

A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/2205](https://cses.fi/problemset/task/2205)

## Solution

Pattern: Bit Manipulation

Technique: Gray Code Formula

Time: O(2ⁿ × n)

Space: O(1)

## Insight

The Gray code corresponding to the binary value i is i ^ (i >> 1).
Compute each Gray code directly, then print its bits from most
significant to least significant.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

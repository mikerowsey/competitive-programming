# Problem: Grid Coloring I

CSES URL: [https://cses.fi/problemset/task/3311](https://cses.fi/problemset/task/3311)

## Statement

You are given an n imes m grid where each cell contains one character A, B, C or D.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/3311](https://cses.fi/problemset/task/3311)

## Solution

Pattern: Constructive Coloring

Technique: Checkerboard Letter Sets

Time: O(nm)

Space: O(1) extra (excluding output)

## Insight

Use disjoint letter sets by parity: {A,B} and {C,D}. Adjacent cells
always have different parity, so they automatically differ. For each
cell, choose any letter from its parity set that is not the original.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

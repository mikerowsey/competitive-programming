# Problem: Collecting Numbers II

CSES URL: [https://cses.fi/problemset/task/2217](https://cses.fi/problemset/task/2217)

## Statement

Maintain the number of collection rounds for a permutation of 1..n while processing swaps of two positions.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/2217](https://cses.fi/problemset/task/2217)

## Solution

Pattern: Local-delta updates on inversion-like adjacencies

Technique: Track positions and update only affected adjacent-value pairs per swap

Time: O((n + m) log 1) effectively O(n + m)

Space: O(n)

## Insight

The rounds count depends only on pairs `(x, x + 1)` where `pos[x] > pos[x + 1]`. A swap changes positions of only two values, so only a constant-size neighborhood of adjacent-value pairs can change.

## Edge Cases Checklist

- Swap same index (no-op).
- Swapped values adjacent in value and/or index.
- Values at boundaries 1 and n.
- Repeated swaps touching same positions.

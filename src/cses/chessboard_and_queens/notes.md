# Problem: Chessboard and Queens

CSES URL: [https://cses.fi/problemset/task/1624](https://cses.fi/problemset/task/1624)

## Statement

Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved...

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1624](https://cses.fi/problemset/task/1624)

## Solution

Pattern: Depth-First Search

Technique: Backtracking

Time: O(8!)

Space: O(8)

## Insight

Place one queen in each row while tracking occupied columns and
diagonals. Skip blocked squares and prune invalid placements
immediately. The search explores only legal partial configurations
and counts all complete arrangements.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

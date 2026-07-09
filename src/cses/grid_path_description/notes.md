# Problem: Grid Path Description

CSES URL: [https://cses.fi/problemset/task/1625](https://cses.fi/problemset/task/1625)

## Statement

There are 88418 paths in a 7 imes 7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1625](https://cses.fi/problemset/task/1625)

## Solution

Pattern: Backtracking Search

Technique: DFS with Corridor Pruning

Time: O(search states), fast enough with pruning

Space: O(1) extra (fixed board + recursion depth 48)

## Insight

Search all paths on a 7x7 board that match the description string.
Prune states that split the unvisited area into disconnected parts and
force moves into one-exit neighbors to avoid sealing cells early.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

# Problem: Knight Moves Grid

CSES URL: [https://cses.fi/problemset/task/3217](https://cses.fi/problemset/task/3217)

## Statement

There is a knight on an n imes n chessboard. For each square, print the minimum number of moves the knight needs to do to reach the top-left corner.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/3217](https://cses.fi/problemset/task/3217)

## Solution

Pattern: Graph Shortest Path

Technique: BFS on Implicit Knight Graph

Time: O(n^2)

Space: O(n^2)

## Insight

Each square is a graph node, and knight moves are unweighted edges.
A single BFS from the top-left corner computes the minimum move count
to every square on the bounded n x n board.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

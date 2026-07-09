# Problem: Two Knights

CSES URL: [https://cses.fi/problemset/task/1072](https://cses.fi/problemset/task/1072)

## Statement

Your task is to count for k=1,2,\ldots,n the number of ways two knights can be placed on a k \times k chessboard so that they do not attack each other.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1072](https://cses.fi/problemset/task/1072)

## Solution

Pattern: Mathematical Derivation

Technique: Closed-Form Formula

Time: O(n)

Space: O(1)

## Insight

For each k × k chessboard, count all unordered pairs of knight
placements, then subtract the pairs where the knights attack each
other. The resulting expression simplifies to the closed-form formula
implemented below.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

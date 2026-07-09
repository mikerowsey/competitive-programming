# Problem: Raab Game I

CSES URL: [https://cses.fi/problemset/task/3399](https://cses.fi/problemset/task/3399)

## Statement

Consider a two player game where each player has n cards numbered 1,2,\dots,n. On each turn both players place one of their cards on the table. The player who placed the higher card gets one point. If the cards are equal, neither player...

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/3399](https://cses.fi/problemset/task/3399)

## Solution

Pattern: Constructive Algorithm

Technique: Block Permutation Construction

Time: O(n)

Space: O(n)

## Insight

Fix one player's order as 1..n, then build the other order from
consecutive blocks. A block of size m can contribute either (m - 1, 1)
or (1, m - 1) wins, and size-2 blocks contribute (1, 1). This lets us
realize every feasible score pair by combining one larger block, some
size-2 blocks, and the remaining ties.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

# Problem: Coin Piles

CSES URL: [https://cses.fi/problemset/task/1754](https://cses.fi/problemset/task/1754)

## Statement

You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1754](https://cses.fi/problemset/task/1754)

## Solution

Pattern: Mathematical Observation

Technique: Necessary and Sufficient Conditions

Time: O(t)

Space: O(1)

## Insight

The larger pile can never contain more than twice as many coins as
the smaller pile. Additionally, the total number of coins must be
divisible by three, since each move removes exactly three coins. Both
conditions are necessary and sufficient.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

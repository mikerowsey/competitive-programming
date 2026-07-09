# Problem: Restaurant Customers

CSES URL: [https://cses.fi/problemset/task/1619](https://cses.fi/problemset/task/1619)

## Statement

You are given the arrival and leaving times of n customers in a restaurant.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1619](https://cses.fi/problemset/task/1619)

## Solution

Pattern: Sweep line

Technique: Convert arrivals and departures into signed events, sort them,

Time: O(n log n).

Space: O(n).

## Insight

At equal timestamps, departures must be processed before arrivals
so customers who leave at time t are not counted together with customers
who arrive at time t.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

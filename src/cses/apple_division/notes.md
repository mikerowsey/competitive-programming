# Problem: Apple Division

CSES URL: [https://cses.fi/problemset/task/1623](https://cses.fi/problemset/task/1623)

## Statement

There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1623](https://cses.fi/problemset/task/1623)

## Solution

Pattern: Depth-First Search

Technique: Branch and Bound

Time: O(2^n)

Space: O(n)

## Insight

Sort the weights in descending order and assign each apple to one of
two groups using DFS. At each step, compare the current weight
difference with the total remaining weight. If the remaining apples
cannot improve the current best possible difference, prune the branch
immediately.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

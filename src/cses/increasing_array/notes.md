# Problem: Increasing Array

CSES URL: [https://cses.fi/problemset/task/1094](https://cses.fi/problemset/task/1094)

## Statement

You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1094](https://cses.fi/problemset/task/1094)

## Solution

Pattern: Linear Scan

Technique: Running maximum

Time: O(n)

Space: O(1)

## Insight

Traverse the array once, keeping track of the minimum allowed value
(the previous element). When a value is too small, add the required
increment; otherwise, update the running maximum.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

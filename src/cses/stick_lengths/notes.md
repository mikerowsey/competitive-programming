# Problem: Stick Lengths

CSES URL: [https://cses.fi/problemset/task/1074](https://cses.fi/problemset/task/1074)

## Statement

There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1074](https://cses.fi/problemset/task/1074)

## Solution

Pattern: Absolute deviation minimization with median selection

Technique: Sort and find median; sum absolute differences

Time: O(n log n) for sorting

Space: O(n) for storing sticks

## Insight

The sum of absolute deviations is minimized at the median, not the mean.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

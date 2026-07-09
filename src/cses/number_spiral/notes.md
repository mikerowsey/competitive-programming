# Problem: Number Spiral

CSES URL: [https://cses.fi/problemset/task/1071](https://cses.fi/problemset/task/1071)

## Statement

A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral: Your task is to find out the number in row y and column x.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1071](https://cses.fi/problemset/task/1071)

## Solution

Pattern: Mathematical Observation

Technique: Layer-Based Coordinate Mapping

Time: O(t)

Space: O(1)

## Insight

Every coordinate lies on a square layer whose side length is max(row,
column). The center value of that layer is layer * (layer - 1) + 1.
The answer is an offset from the center determined by the parity of the
layer.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

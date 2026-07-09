# Problem: Ferris Wheel

CSES URL: [https://cses.fi/problemset/task/1090](https://cses.fi/problemset/task/1090)

## Statement

There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1090](https://cses.fi/problemset/task/1090)

## Solution

Pattern: Greedy pairing

Technique: Sort weights and pair the lightest remaining child with the

Time: O(n log n).

Space: O(n).

## Insight

Once the heaviest child cannot pair with the lightest remaining
child, that heaviest child cannot pair with anyone and must take a gondola
alone.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

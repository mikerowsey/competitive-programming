# Problem: Creating Strings

CSES URL: [https://cses.fi/problemset/task/1622](https://cses.fi/problemset/task/1622)

## Statement

Given a string, your task is to generate all different strings that can be created using its characters.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1622](https://cses.fi/problemset/task/1622)

## Solution

Pattern: Enumeration

Technique: Lexicographic permutation generation

Time: O(n! · n)

Space: O(n)

## Insight

Sort the characters first, then repeatedly call std::next_permutation().
Starting from the lexicographically smallest arrangement guarantees that
every distinct permutation is generated exactly once, even when duplicate
characters are present.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

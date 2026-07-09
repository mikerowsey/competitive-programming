# Problem: String Reorder

CSES URL: [https://cses.fi/problemset/task/1743](https://cses.fi/problemset/task/1743)

## Statement

Your task is to reorder the characters of a string so that no two adjacent characters are the same. What is the lexicographically minimal such string?

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1743](https://cses.fi/problemset/task/1743)

## Solution

Pattern: Greedy Construction

Technique: Lexicographic Choice with Feasibility Check

Time: O(26 * n)

Space: O(n)

## Insight

Build the answer left-to-right. At each position, try letters from A to Z
(excluding previous letter) and pick the first one that keeps the rest
feasible: max remaining frequency <= ceil(remaining_length / 2).

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

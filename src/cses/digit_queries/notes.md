# Problem: Digit Queries

CSES URL: [https://cses.fi/problemset/task/2431](https://cses.fi/problemset/task/2431)

## Statement

Consider an infinite string that consists of all positive integers in increasing order:

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/2431](https://cses.fi/problemset/task/2431)

## Solution

Pattern: Math / Place-Value Blocks

Technique: Block Subtraction + Index in Number

Time: O(q * log10(k))

Space: O(1)

## Insight

Digits appear in blocks by number length: 1-digit, 2-digit, etc.
Subtract whole blocks until the target digit index lands in one block,
then locate the exact number and digit inside it.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

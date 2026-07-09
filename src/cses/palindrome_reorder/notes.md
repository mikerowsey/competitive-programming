# Problem: Palindrome Reorder

CSES URL: [https://cses.fi/problemset/task/1755](https://cses.fi/problemset/task/1755)

## Statement

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1755](https://cses.fi/problemset/task/1755)

## Solution

Pattern: Counting

Technique: Frequency Analysis

Time: O(n)

Space: O(1)

## Insight

Count the occurrences of each character. A palindrome can contain at
most one character with an odd frequency. Print half of each character
in ascending order, the odd-frequency character (if any), then the
remaining halves in reverse order.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

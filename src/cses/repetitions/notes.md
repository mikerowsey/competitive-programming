# Problem: Repetitions

CSES URL: [https://cses.fi/problemset/task/1069](https://cses.fi/problemset/task/1069)

## Statement

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1069](https://cses.fi/problemset/task/1069)

## Solution

Pattern: Linear Scan

Technique: Run-length counting

Time: O(n)

Space: O(1)

## Insight

Traverse the string once, counting consecutive identical characters.
Reset the count when the character changes and track the maximum run
length seen.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

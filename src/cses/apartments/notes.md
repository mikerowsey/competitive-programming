# Problem: Apartments

CSES URL: [https://cses.fi/problemset/task/1084](https://cses.fi/problemset/task/1084)

## Statement

There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1084](https://cses.fi/problemset/task/1084)

## Solution

Pattern: Greedy matching

Technique: Sort both lists and advance two pointers.

Time: O(n log n + m log m).

Space: O(n + m).

## Insight

After sorting, if the current apartment is too small for the
current applicant even with tolerance, it cannot satisfy any later
applicant; likewise, if it is too large, the current applicant cannot
match any later apartment.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

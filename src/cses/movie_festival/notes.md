# Problem: Movie Festival

CSES URL: [https://cses.fi/problemset/task/1629](https://cses.fi/problemset/task/1629)

## Statement

In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1629](https://cses.fi/problemset/task/1629)

## Solution

Pattern: Interval scheduling

Technique: Sort movies by ending time and greedily take the next

Time: O(n log n).

Space: O(n).

## Insight

Choosing the movie that ends earliest leaves the most room for
future selections, so the greedy choice stays optimal.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

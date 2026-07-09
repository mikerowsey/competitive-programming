# Problem: Trailing Zeros

CSES URL: [https://cses.fi/problemset/task/1618](https://cses.fi/problemset/task/1618)

## Statement

Your task is to calculate the number of trailing zeros in the factorial n!.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1618](https://cses.fi/problemset/task/1618)

## Solution

Pattern: Mathematical Observation

Technique: Repeated Division

Time: O(log₅ n)

Space: O(1)

## Insight

Each trailing zero is produced by a factor of 10 = 2 × 5. Since there
are always more factors of 2 than 5 in n!, count the number of factors
of 5 by repeatedly dividing n by powers of 5.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

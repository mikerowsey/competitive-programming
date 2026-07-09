# Problem: Bit Strings

CSES URL: [https://cses.fi/problemset/task/1617](https://cses.fi/problemset/task/1617)

## Statement

Your task is to calculate the number of bit strings of length n.

See the official CSES page for complete details.

Source: [https://cses.fi/problemset/task/1617](https://cses.fi/problemset/task/1617)

## Solution

Pattern: Modular Arithmetic

Technique: Binary Exponentiation (Modular Exponentiation)

Time: O(log n)

Space: O(1)

## Insight

Compute 2^n modulo 1,000,000,007 using exponentiation by squaring.
Repeatedly square the base and multiply it into the result whenever the
current bit of the exponent is set, reducing modulo MOD after each
multiplication to keep the intermediate values bounded.

## Edge Cases Checklist

- Minimum input size and trivial behavior.
- Maximum constraints and performance boundaries.
- Repeated/equal values and ordering corner cases.
- Overflow-prone arithmetic transitions.

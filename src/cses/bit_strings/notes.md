# Notes

## Problem Header

// Problem: Bit Strings
//
// Pattern: Modular Arithmetic
// Technique: Binary Exponentiation (Modular Exponentiation)
//
// Time: O(log n)
// Space: O(1)
//
// Insight:
//   Compute 2^n modulo 1,000,000,007 using exponentiation by squaring.
//   Repeatedly square the base and multiply it into the result whenever the
//   current bit of the exponent is set, reducing modulo MOD after each
//   multiplication to keep the intermediate values bounded.

## Constraints

- Paste official input limits here.

## Complexity Budget

- Target time complexity:
- Target space complexity:

## Edge Cases Checklist

- Minimum n / empty-like cases
- Maximum constraints
- Monotonic or repeated values
- Potential overflow boundaries

## Approach Draft

- Pattern:
- Key invariant:
- Data structures:

// Problem: Bit Strings
//
// Pattern: Modular Arithmetic
// Technique: Binary Exponentiation (Modular Exponentiation)
// Time: O(log n)
// Space: O(1)
// Insight: Compute 2^n modulo 1,000,000,007 using exponentiation by
//          squaring. Repeatedly square the base and multiply it into
//          the result whenever the current bit of the exponent is set,
//          reducing modulo MOD after each multiplication to keep the
//          intermediate values bounded.

#include <iostream>

#include "core/math.hpp"

constexpr u64 MOD{1'000'000'007};

void solve(std::istream& in, std::ostream& out)
{
    u64 n;
    in >> n;
    out << core::mod_pow(2, n, MOD) << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

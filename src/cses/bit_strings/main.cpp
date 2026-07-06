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

#include <cstdint>
#include <iostream>

constexpr std::uint64_t mod_pow(std::uint64_t base, std::uint64_t exp, std::uint64_t mod)
{
    std::uint64_t result{1};

    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

static constexpr std::uint64_t kMod{1'000'000'007};

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t n{};
    in >> n;

    out << mod_pow(2, n, kMod) << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

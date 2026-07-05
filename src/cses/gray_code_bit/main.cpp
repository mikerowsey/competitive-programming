// Problem: Gray Code
//
// Pattern:   Bit Manipulation
// Technique: Gray Code Formula
//
// Time:      O(2ⁿ × n)
// Space:     O(1)
//
// Insight:
//   The Gray code corresponding to the binary value i is
//   i ^ (i >> 1). Compute each Gray code directly, then print
//   its bits from most significant to least significant.

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    uint64_t bits{};
    in >> bits;

    const uint64_t total_codes = 1ULL << bits;

    for (uint64_t value{}; value < total_codes; ++value) {
        const uint64_t gray = value ^ (value >> 1);

        uint64_t bit{bits};

        while (bit > 0) {
            --bit;
            out << ((gray >> bit) & 1);
        }

        out << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}

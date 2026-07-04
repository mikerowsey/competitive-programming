// Problem: Trailing Zeros
//
// Pattern:   Mathematical Observation
// Technique: Repeated Division
//
// Time:      O(log₅ n)
// Space:     O(1)
//
// Insight:
//   Each trailing zero is produced by a factor of 10 = 2 × 5.
//   Since there are always more factors of 2 than 5 in n!, count the
//   number of factors of 5 by repeatedly dividing n by powers of 5.

#include <iostream>

#include "core/types.hpp"

void solve(std::istream& in, std::ostream& out)
{
    u64 n{};
    in >> n;

    u64 trailing_zeros{};

    while (n != 0) {
        n /= 5;
        trailing_zeros += n;
    }

    out << trailing_zeros << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}

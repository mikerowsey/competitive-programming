// Problem: Permutations
//
// Pattern:   Constructive Algorithm
// Technique: Even-Odd Ordering
//
// Time:      O(n)
// Space:     O(1)
//
// Insight:
//   Adjacent numbers differ by at least two when all even numbers are
//   listed first, followed by all odd numbers. The only exceptions are
//   n = 2 and n = 3, where no valid permutation exists.

#include <iostream>

#include "core/types.hpp"

void solve(std::istream& in, std::ostream& out)
{
    u64 n{};
    in >> n;

    if (n == 1) {
        out << 1 << '\n';
        return;
    }

    if (n == 2 || n == 3) {
        out << "NO SOLUTION\n";
        return;
    }

    for (u64 value{2}; value <= n; value += 2) {
        out << value << ' ';
    }

    for (u64 value{1}; value <= n; value += 2) {
        out << value << ' ';
    }

    out << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}

// Problem: Coin Piles
//
// Pattern:   Mathematical Observation
// Technique: Necessary and Sufficient Conditions
//
// Time:      O(t)
// Space:     O(1)
//
// Insight:
//   The larger pile can never contain more than twice as many coins as
//   the smaller pile. Additionally, the total number of coins must be
//   divisible by three, since each move removes exactly three coins.
//   Both conditions are necessary and sufficient.

#include <iostream>

#include "core/types.hpp"


void solve(std::istream& in, std::ostream& out)
{
    u64 test_cases{};
    in >> test_cases;

    for (u64 test{0}; test < test_cases; ++test) {
        u64 first_pile{};
        u64 second_pile{};
        in >> first_pile >> second_pile;

        if (    first_pile > 2 * second_pile ||
                second_pile > 2 * first_pile ||
                (first_pile + second_pile) % 3 != 0) {

            out << "NO" << '\n';
        } else {
            out << "YES" << '\n';
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

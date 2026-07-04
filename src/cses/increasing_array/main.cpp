// Problem: Increasing Array
//
// Pattern: Linear Scan
// Technique: Running maximum
// Time: O(n)
// Space: O(1)
// Insight: Traverse the array once, keeping track of the minimum allowed
//          value (the previous element). When a value is too small, add the
//          required increment; otherwise, update the running maximum.

#include <iostream>

#include "core/types.hpp"

void solve(std::istream& in, std::ostream& out)
{
    u64 count{};
    in >> count;

    u64 previous{};
    in >> previous;

    u64 moves{};

    for (u64 i{1}; i < count; ++i) {
        u64 current{};
        in >> current;

        if (current < previous) {
            moves += previous - current;
        } else {
            previous = current;
        }
    }

    out << moves << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

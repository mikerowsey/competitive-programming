// Problem: Increasing Array
//
// Pattern: Linear Scan
// Technique: Running maximum
// Time: O(n)
// Space: O(1)
// Insight: Traverse the array once, keeping track of the minimum allowed
//          value (the previous element). When a value is too small, add the
//          required increment; otherwise, update the running maximum.

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    uint64_t count{};
    in >> count;

    uint64_t previous{};
    in >> previous;

    uint64_t moves{};

    for (uint64_t i{1}; i < count; ++i) {
        uint64_t current{};
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

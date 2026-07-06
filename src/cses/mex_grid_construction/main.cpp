// Problem: Mex Grid Construction
//
// Pattern: Constructive Math
// Technique: Bitwise XOR Table
//
// Time: O(n^2)
// Space: O(1)
//
// Insight:
//   The unique mex-defined grid equals a[i][j] = i xor j (0-indexed).
//   For each cell, the union of values to the left in the same row and
//   above in the same column contains every value smaller than (i xor j),
//   while (i xor j) itself is absent, so mex is exactly (i xor j).
//

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t n{};
    in >> n;

    for (std::uint64_t row = 0; row < n; ++row) {
        for (std::uint64_t column = 0; column < n; ++column) {
            if (column > 0) {
                out << ' ';
            }
            out << (row ^ column);
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

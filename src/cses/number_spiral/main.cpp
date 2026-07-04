// Problem: Number Spiral
//
// Pattern:   Mathematical Observation
// Technique: Layer-Based Coordinate Mapping
//
// Time:      O(t)
// Space:     O(1)
//
// Insight:
//   Every coordinate lies on a square layer whose side length is
//   max(row, column). The center value of that layer is
//   layer * (layer - 1) + 1. The answer is an offset from the
//   center determined by the parity of the layer.

#include <algorithm>
#include <iostream>

#include "core/types.hpp"

void solve(std::istream& in, std::ostream& out)
{
    u64 test_cases{};
    in >> test_cases;

    for (u64 i{0}; i < test_cases; ++i) {
        i64 row{};
        i64 column{};
        in >> row >> column;

        const i64 layer = std::max(row, column);
        const i64 layer_center = layer * (layer - 1) + 1;

        const i64 offset =
            (layer & 1)
                ? column - row
                : row - column;

        out << layer_center + offset << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

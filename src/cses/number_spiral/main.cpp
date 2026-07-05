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

#include <cstdint>
#include <algorithm>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t test_cases{};
    in >> test_cases;

    for (uint64_t i{0}; i < test_cases; ++i) {
        int64_t row{};
        int64_t column{};
        in >> row >> column;

        const int64_t layer = std::max(row, column);
        const int64_t layer_center = layer * (layer - 1) + 1;

        const int64_t offset =
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

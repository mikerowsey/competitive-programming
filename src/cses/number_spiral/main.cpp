// Problem: Number Spiral

#include <cstdint>
#include <algorithm>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t test_cases{};
    in >> test_cases;

    for (std::uint64_t i{0}; i < test_cases; ++i) {
        std::int64_t row{};
        std::int64_t column{};
        in >> row >> column;

        const std::int64_t layer = std::max(row, column);
        const std::int64_t layer_center = layer * (layer - 1) + 1;

        const std::int64_t offset =
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

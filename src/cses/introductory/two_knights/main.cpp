// Problem: Two Knights
//
// Pattern:   Mathematical Derivation
// Technique: Closed-Form Formula
//
// Time:      O(n)
// Space:     O(1)
//
// Insight:
//   For each k × k chessboard, count all unordered pairs of knight
//   placements, then subtract the pairs where the knights attack
//   each other. The resulting expression simplifies to the closed-
//   form formula implemented below.

#include <iostream>

#include "core/types.hpp"

void solve(std::istream& in, std::ostream& out)
{
    u64 max_board_size{};
    in >> max_board_size;

    out << 0 << '\n';

    for (u64 board_size{2}; board_size <= max_board_size; ++board_size) {
        const u64 total_pairs = board_size * board_size * (board_size * board_size - 1) / 2;
        const u64 attacking_pairs = 4 * (board_size - 1) * (board_size - 2);
        out << total_pairs - attacking_pairs << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

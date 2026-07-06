// Problem: Raab Game I
//
// Pattern: Constructive Algorithm
// Technique: Block Permutation Construction
//
// Time: O(n)
// Space: O(n)
//
// Insight:
//   Fix one player's order as 1..n, then build the other order from
//   consecutive blocks. A block of size m can contribute either (m - 1, 1)
//   or (1, m - 1) wins, and size-2 blocks contribute (1, 1). This lets us
//   realize every feasible score pair by combining one larger block, some
//   size-2 blocks, and the remaining ties.

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

void append_block(std::vector<std::uint64_t>& permutation, std::uint64_t start, std::uint64_t size,
                  bool first_player_heavy)
{
    if (size == 1) {
        permutation.push_back(start);
        return;
    }

    if (first_player_heavy) {
        permutation.push_back(start + size - 1);
        for (std::uint64_t value = 0; value + 1 < size; ++value) {
            permutation.push_back(start + value);
        }
    } else {
        for (std::uint64_t value = 1; value < size; ++value) {
            permutation.push_back(start + value);
        }
        permutation.push_back(start);
    }
}

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t test_cases{};
    in >> test_cases;

    for (std::uint64_t test = 0; test < test_cases; ++test) {
        std::uint64_t n{};
        std::uint64_t a{};
        std::uint64_t b{};
        in >> n >> a >> b;

        if ((a == 0 && b == 0) || (a > 0 && b > 0 && a + b <= n)) {
            out << "YES" << '\n';

            bool swapped = false;
            if (a < b) {
                std::swap(a, b);
                swapped = true;
            }

            std::vector<std::uint64_t> first_player;
            std::vector<std::uint64_t> second_player;
            first_player.reserve(n);
            second_player.reserve(n);

            std::uint64_t current = 1;

            if (a == 0 && b == 0) {
                for (std::uint64_t value = 1; value <= n; ++value) {
                    first_player.push_back(value);
                    second_player.push_back(value);
                }
            } else {
                const std::uint64_t large_block_size = a - b + 2;

                for (std::uint64_t value = 0; value < large_block_size; ++value) {
                    first_player.push_back(current + value);
                }
                append_block(second_player, current, large_block_size, true);
                current += large_block_size;

                for (std::uint64_t block = 0; block + 1 < b; ++block) {
                    first_player.push_back(current);
                    first_player.push_back(current + 1);
                    append_block(second_player, current, 2, true);
                    current += 2;
                }

                while (current <= n) {
                    first_player.push_back(current);
                    second_player.push_back(current);
                    ++current;
                }
            }

            if (swapped) {
                std::swap(first_player, second_player);
            }

            for (std::uint64_t value : first_player) {
                out << value << ' ';
            }
            out << '\n';

            for (std::uint64_t value : second_player) {
                out << value << ' ';
            }
            out << '\n';
        } else {
            out << "NO" << '\n';
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

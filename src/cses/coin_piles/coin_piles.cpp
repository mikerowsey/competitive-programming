// Problem: Coin Piles

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t test_cases{};
    in >> test_cases;

    for (std::uint64_t test{0}; test < test_cases; ++test) {
        std::uint64_t first_pile{};
        std::uint64_t second_pile{};
        in >> first_pile >> second_pile;

        if (first_pile > 2 * second_pile || second_pile > 2 * first_pile ||
            (first_pile + second_pile) % 3 != 0) {
            out << "NO" << '\n';
        } else {
            out << "YES" << '\n';
        }
    }
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
#endif

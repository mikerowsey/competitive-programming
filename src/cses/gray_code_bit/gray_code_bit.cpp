// Problem: Gray Code

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t bits{};
    in >> bits;

    if (bits >= 64) {
        return;
    }

    const std::uint64_t total_codes = (std::uint64_t{1} << bits);

    for (std::uint64_t value{}; value < total_codes; ++value) {
        const std::uint64_t gray = value ^ (value >> 1);

        std::uint64_t bit{bits};

        while (bit > 0) {
            --bit;
            out << ((gray >> bit) & 1);
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

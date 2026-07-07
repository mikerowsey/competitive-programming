// Problem: Increasing Array

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t count{};
    in >> count;

    if (count == 0) {
        out << 0 << '\n';
        return;
    }

    std::uint64_t previous{};
    in >> previous;

    std::uint64_t moves{};

    for (std::uint64_t i{1}; i < count; ++i) {
        std::uint64_t current{};
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

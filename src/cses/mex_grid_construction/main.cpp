// Problem: Mex Grid Construction

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

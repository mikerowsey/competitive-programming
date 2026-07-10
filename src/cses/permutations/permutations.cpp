// Problem: Permutations

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t n{};
    in >> n;

    if (n == 1) {
        out << 1 << '\n';
        return;
    }

    if (n == 2 || n == 3) {
        out << "NO SOLUTION\n";
        return;
    }

    bool first_value = true;
    for (std::uint64_t value{2}; value <= n; value += 2) {
        if (!first_value) {
            out << ' ';
        }
        out << value;
        first_value = false;
    }

    for (std::uint64_t value{1}; value <= n; value += 2) {
        if (!first_value) {
            out << ' ';
        }
        out << value;
        first_value = false;
    }

    out << '\n';
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}
#endif

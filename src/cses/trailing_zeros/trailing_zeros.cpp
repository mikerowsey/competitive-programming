// Problem: Trailing Zeros

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t n{};
    in >> n;

    std::uint64_t trailing_zeros{};

    while (n != 0) {
        n /= 5;
        trailing_zeros += n;
    }

    out << trailing_zeros << '\n';
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}
#endif

// Problem: Weird Algorithm

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t n{};
    in >> n;

    while (true) {
        out << n;
        if (n == 1) {
            break;
        }

        out << ' ';
        if ((n & 1ULL) == 0ULL) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }

    out << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

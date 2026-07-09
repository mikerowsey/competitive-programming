// Problem: Collecting Numbers

#include <iostream>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    int n{};
    in >> n;

    std::vector<int> positions(n + 1, 0);
    for (int index = 0; index < n; ++index) {
        int value{};
        in >> value;
        positions[value] = index;
    }

    int rounds{1};
    for (int value = 1; value <= n; ++value) {
        if (positions[value] < positions[value - 1]) {
            ++rounds;
        }
    }

    out << rounds << '\n';
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
#endif

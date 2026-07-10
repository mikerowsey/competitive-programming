// Problem: Stick Lengths

#include <algorithm>
#include <iostream>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    int n{};
    in >> n;

    std::vector<long long> sticks(n);
    for (int i = 0; i < n; ++i) {
        in >> sticks[i];
    }

    std::sort(sticks.begin(), sticks.end());

    long long median = sticks[n / 2];

    long long result = 0;
    for (long long stick : sticks) {
        result += std::abs(stick - median);
    }

    out << result << '\n';
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
#endif

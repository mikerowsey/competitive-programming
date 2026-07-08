// Problem: Maximum Subarray Sum

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    int n;
    in >> n;

    std::vector<int64_t> input(n);
    for (int i = 0; i < n; i++) {
        in >> input[i];
    }

    std::vector<int64_t> sums(n);
    sums[0] = input[0];
    for (int i = 1; i < n; i++) {
        sums[i] = sums[i - 1] + input[i];
    }

    int64_t mn = 0;
    int64_t mx = std::numeric_limits<int64_t>::min();

    for (int i = 0; i < n; i++) {
        mx = std::max(mx, sums[i] - mn);
        mn = std::min(mn, sums[i]);
    }

    out << mx << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

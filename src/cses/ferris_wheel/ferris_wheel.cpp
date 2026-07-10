// Problem: Ferris Wheel

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    std::size_t children_count = 0;
    std::uint64_t max_weight = 0;
    in >> children_count >> max_weight;

    std::vector<std::uint64_t> weights(children_count);
    for (std::uint64_t& weight : weights) {
        in >> weight;
    }

    std::sort(weights.begin(), weights.end());

    std::size_t left = 0;
    std::size_t right = children_count;
    std::uint64_t gondolas = 0;

    while (left < right) {
        --right;
        if (left < right && weights[left] + weights[right] <= max_weight) {
            ++left;
        }
        ++gondolas;
    }

    out << gondolas << '\n';
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
#endif

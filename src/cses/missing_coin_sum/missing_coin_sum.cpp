// Problem: Missing Coin Sum

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t coin_count{};
    in >> coin_count;

    std::vector<std::uint64_t> coins(coin_count);
    for (std::uint64_t& coin : coins) {
        in >> coin;
    }
    std::sort(coins.begin(), coins.end());

    std::uint64_t smallest_missing_sum{1};

    for (const std::uint64_t coin : coins) {
        if (coin > smallest_missing_sum) {
            break;
        }

        smallest_missing_sum += coin;
    }

    out << smallest_missing_sum << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

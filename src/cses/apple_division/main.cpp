// Problem: Apple Division

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

void dfs(const std::vector<std::int64_t>& weights,
         const std::vector<std::int64_t>& remaining_weight,
         std::size_t index,
         std::int64_t left_weight,
         std::int64_t right_weight,
         std::int64_t& best_difference)
{
    if (index == weights.size()) {
        best_difference = std::min(best_difference, std::abs(left_weight - right_weight));
        return;
    }

    const std::int64_t difference = std::abs(left_weight - right_weight);

    if (difference >= remaining_weight[index]) {
        best_difference = std::min(best_difference, difference - remaining_weight[index]);
        return;
    }

    dfs(weights, remaining_weight, index + 1, left_weight + weights[index], right_weight,
        best_difference);

    dfs(weights, remaining_weight, index + 1, left_weight, right_weight + weights[index],
        best_difference);
}

void solve(std::istream& in, std::ostream& out)
{
    std::int64_t apple_count{};
    in >> apple_count;

    std::vector<std::int64_t> weights;
    weights.reserve(apple_count);

    std::int64_t total_weight{};
    for (std::int64_t i{}; i < apple_count; ++i) {
        std::int64_t weight{};
        in >> weight;
        total_weight += weight;
        weights.push_back(weight);
    }

    std::sort(weights.begin(), weights.end(), std::greater<>{});

    std::vector<std::int64_t> remaining_weight(weights.size());

    std::int64_t remaining{total_weight};
    for (std::size_t i{}; i < weights.size(); ++i) {
        remaining_weight[i] = remaining;
        remaining -= weights[i];
    }

    std::int64_t best_difference{total_weight};

    dfs(weights, remaining_weight, 1, weights.front(), 0, best_difference);

    out << best_difference << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}


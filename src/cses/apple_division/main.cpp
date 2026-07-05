// Problem: Apple Division
//
// Pattern: Depth-First Search
// Technique: Branch and Bound
// Time: O(2^n)
// Space: O(n)
//
// Insight: Sort the weights in descending order and assign each apple
//          to one of two groups using DFS. At each step, compare the
//          current weight difference with the total remaining weight.
//          If the remaining apples cannot improve the current best
//          possible difference, prune the branch immediately.

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

using i64 = std::int64_t;

void dfs(const std::vector<i64>& weights, const std::vector<i64>& remaining_weight,
         std::size_t index, i64 left_weight, i64 right_weight, i64& best_difference)
{
    if (index == weights.size()) {
        best_difference = std::min(best_difference, std::abs(left_weight - right_weight));
        return;
    }

    const i64 difference = std::abs(left_weight - right_weight);

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
    i64 apple_count{};
    in >> apple_count;

    std::vector<i64> weights;
    weights.reserve(apple_count);

    i64 total_weight{};
    for (i64 i{}; i < apple_count; ++i) {
        i64 weight{};
        in >> weight;
        total_weight += weight;
        weights.push_back(weight);
    }

    std::sort(weights.begin(), weights.end(), std::greater<>{});

    std::vector<i64> remaining_weight(weights.size());

    i64 remaining{total_weight};
    for (std::size_t i{}; i < weights.size(); ++i) {
        remaining_weight[i] = remaining;
        remaining -= weights[i];
    }

    i64 best_difference{total_weight};

    dfs(weights, remaining_weight, 1, weights.front(), 0, best_difference);

    out << best_difference << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}


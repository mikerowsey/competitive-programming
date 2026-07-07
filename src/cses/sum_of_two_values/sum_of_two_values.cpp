// Problem: Sum of Two Values

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    std::size_t value_count = 0;
    std::uint32_t target_sum = 0;
    in >> value_count >> target_sum;

    std::vector<std::pair<std::size_t, std::uint32_t>> values(value_count);
    for (std::size_t index = 0; index < value_count; ++index) {
        in >> values[index].second;
        values[index].first = index + 1;
    }

    std::sort(values.begin(), values.end(),
              [](const std::pair<std::size_t, std::uint32_t>& left,
                 const std::pair<std::size_t, std::uint32_t>& right) {
                  return left.second < right.second;
              });

    std::size_t left = 0;
    std::size_t right = value_count - 1;
    while (left < right) {
        const std::uint32_t sum = values[left].second + values[right].second;
        if (sum > target_sum) {
            --right;
        } else if (sum < target_sum) {
            ++left;
        } else {
            out << values[left].first << ' ' << values[right].first << '\n';
            return;
        }
    }

    out << "IMPOSSIBLE\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

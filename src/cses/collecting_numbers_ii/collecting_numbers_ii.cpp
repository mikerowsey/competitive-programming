// Problem: Collecting Numbers II

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    int n{};
    int swap_count{};
    in >> n >> swap_count;

    std::vector<int> values_at_position(n + 1, 0);
    std::vector<int> positions(n + 1, 0);
    for (int position = 1; position <= n; ++position) {
        int value{};
        in >> value;
        values_at_position[position] = value;
        positions[value] = position;
    }

    auto is_break = [&](int value) -> int {
        if (value <= 1 || value > n) {
            return 0;
        }
        return positions[value] < positions[value - 1] ? 1 : 0;
    };

    int rounds{1};
    for (int value = 2; value <= n; ++value) {
        rounds += is_break(value);
    }

    for (int query = 0; query < swap_count; ++query) {
        int left_position{};
        int right_position{};
        in >> left_position >> right_position;

        const int left_value = values_at_position[left_position];
        const int right_value = values_at_position[right_position];

        std::array<int, 4> affected_values{left_value, left_value + 1, right_value,
                                           right_value + 1};
        std::sort(affected_values.begin(), affected_values.end());
        const auto unique_end = std::unique(affected_values.begin(), affected_values.end());

        int breaks_before{0};
        for (auto it = affected_values.begin(); it != unique_end; ++it) {
            breaks_before += is_break(*it);
        }

        std::swap(values_at_position[left_position], values_at_position[right_position]);
        positions[left_value] = right_position;
        positions[right_value] = left_position;

        int breaks_after{0};
        for (auto it = affected_values.begin(); it != unique_end; ++it) {
            breaks_after += is_break(*it);
        }

        rounds += (breaks_after - breaks_before);
        out << rounds << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

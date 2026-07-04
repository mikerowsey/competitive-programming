// Problem: Two Sets
//
// Pattern:   Greedy
// Technique: Largest-First Partition
//
// Time:      O(n)
// Space:     O(n)
//
// Insight:
//   If the total sum is odd, no partition exists. Otherwise, repeatedly
//   take the largest value that does not exceed the remaining target sum.
//   This greedy strategy constructs one valid partition in a single pass.

#include <iostream>
#include <vector>

#include "core/types.hpp"

namespace
{

void print_set(std::ostream& out, const std::vector<u64>& values)
{
    out << values.size() << '\n';

    for (u64 value : values) {
        out << value << ' ';
    }

    out << '\n';
}

} // namespace

void solve(std::istream& in, std::ostream& out)
{
    u64 n{};
    in >> n;

    std::vector<u64> first_set;
    std::vector<u64> second_set;

    u64 remaining_sum = n * (n + 1) / 2;

    if (remaining_sum & 1) {
        out << "NO\n";
        return;
    }

    out << "YES\n";

    remaining_sum /= 2;

    for (u64 value{n}; value > 0; --value) {
        if (value <= remaining_sum) {
            first_set.push_back(value);
            remaining_sum -= value;
        } else {
            second_set.push_back(value);
        }
    }

    print_set(out, first_set);
    print_set(out, second_set);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}

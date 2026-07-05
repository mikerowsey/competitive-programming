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

#include <cstdint>
#include <iostream>
#include <vector>

namespace
{

void print_set(std::ostream& out, const std::vector<uint64_t>& values)
{
    out << values.size() << '\n';

    for (uint64_t value : values) {
        out << value << ' ';
    }

    out << '\n';
}

} // namespace

void solve(std::istream& in, std::ostream& out)
{
    uint64_t n{};
    in >> n;

    std::vector<uint64_t> first_set;
    std::vector<uint64_t> second_set;

    uint64_t remaining_sum = n * (n + 1) / 2;

    if (remaining_sum & 1) {
        out << "NO\n";
        return;
    }

    out << "YES\n";

    remaining_sum /= 2;

    for (uint64_t value{n}; value > 0; --value) {
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

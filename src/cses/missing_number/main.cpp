// Problem: Missing Number
//
// Pattern: Mathematical Formula
// Technique: Arithmetic sum comparison
//
// Time: O(n)
// Space: O(1)
//
// Insight:
//   Compute the expected sum of 1..n using the arithmetic series formula,
//   subtract the actual sum, and the difference is the missing number.

#include <cstdint>
#include <iostream>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t n{};
    in >> n;

    const std::uint64_t expected_value = n * (n + 1) / 2;
    std::uint64_t actual_value{0};
    std::uint64_t value{};

    for (std::uint64_t index = 1; index < n; ++index) {
        in >> value;
        actual_value += value;
    }

    out << expected_value - actual_value << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

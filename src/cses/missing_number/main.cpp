// Problem: Missing Number
//
// Pattern: Mathematical Formula
// Technique: Arithmetic sum comparison
//
// Time: O(n)
// Space: O(1)
//
// Insight: Compute the expected sum of 1..n using the arithmetic series
//          formula, subtract the actual sum, and the difference is the
//          missing number.

#include <cstdint>
#include <iostream>

using u64 = uint64_t;

void solve(std::istream& in, std::ostream& out)
{
    u64 n;
    in >> n;

    u64 expected_value = n * (n + 1) / 2;
    u64 actual_value{0};
    u64 value;

    while (in >> value) {
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

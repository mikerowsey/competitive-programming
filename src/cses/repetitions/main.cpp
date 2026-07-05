// Problem: Repetitions
//
// Pattern: Linear Scan
// Technique: Run-length counting
// Time: O(n)
// Space: O(1)
// Insight: Traverse the string once, counting consecutive identical
//          characters. Reset the count when the character changes and
//          track the maximum run length seen.

#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>


void solve(std::istream& in, std::ostream& out)
{
    std::string s;
    in >> s;

    uint32_t longest{1};
    uint32_t current{1};

    for (std::size_t i{1}; i < s.size(); ++i) {
        current = (s[i] == s[i - 1] ? current + 1: 1);
        longest = std::max(longest, current);
    }

    out << longest << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

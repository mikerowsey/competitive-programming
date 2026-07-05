// Problem: Palindrome Reorder
//
// Pattern:   Counting
// Technique: Frequency Analysis
//
// Time:      O(n)
// Space:     O(1)
//
// Insight:
//   Count the occurrences of each character. A palindrome can contain
//   at most one character with an odd frequency. Print half of each
//   character in ascending order, the odd-frequency character (if any),
//   then the remaining halves in reverse order.

#include <cstdint>
#include <iostream>
#include <ranges>
#include <string_view>

namespace {
constexpr std::string_view alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
}

void solve(std::istream& in, std::ostream& out)
{
    std::array<uint64_t, 26> count{};
    std::string input;
    in >> input;

    for (char ch : input) {
        ++count[ch - 'A'];
    }

    uint64_t odds{0};
    char center{};

    for (char ch : alphabet) {
        if (count[ch - 'A'] & 1) {
            ++odds;
            center = ch;
        }
    }

    if (odds > 1) {
        out << "NO SOLUTION" << '\n';
        return;
    }

    for (char ch : alphabet) {
        out << std::string(count[ch - 'A'] / 2, ch);
    }

    if (odds) {
        out << center;
    }

    for (char ch : std::views::reverse(alphabet)) {
        out << std::string(count[ch - 'A'] / 2, ch);
    }

    out << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

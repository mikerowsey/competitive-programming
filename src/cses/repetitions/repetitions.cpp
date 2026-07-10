// Problem: Repetitions

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

void solve(std::istream& in, std::ostream& out)
{
    std::string s;
    in >> s;

    if (s.empty()) {
        out << 0 << '\n';
        return;
    }

    std::uint32_t longest{1};
    std::uint32_t current{1};

    for (std::size_t i{1}; i < s.size(); ++i) {
        current = (s[i] == s[i - 1] ? current + 1 : 1);
        longest = std::max(longest, current);
    }

    out << longest << '\n';
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
#endif

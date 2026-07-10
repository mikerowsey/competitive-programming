// Problem: Palindrome Reorder

#include <array>
#include <cstdint>
#include <iostream>
#include <string>

void solve(std::istream& in, std::ostream& out)
{
    std::array<std::uint64_t, 26> count{};
    std::string input;
    in >> input;

    for (char ch : input) {
        ++count[ch - 'A'];
    }

    std::uint64_t odds{0};
    char center{};

    for (int index{0}; index < 26; ++index) {
        if (count[index] & 1) {
            ++odds;
            center = static_cast<char>('A' + index);
        }
    }

    if (odds > 1) {
        out << "NO SOLUTION" << '\n';
        return;
    }

    for (int index{0}; index < 26; ++index) {
        out << std::string(count[index] / 2, static_cast<char>('A' + index));
    }

    if (odds) {
        out << center;
    }

    for (int index{25}; index >= 0; --index) {
        out << std::string(count[index] / 2, static_cast<char>('A' + index));
    }

    out << '\n';
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
#endif

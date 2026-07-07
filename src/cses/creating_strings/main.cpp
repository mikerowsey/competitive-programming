// Problem: Creating Strings

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

std::uint64_t factorial(std::uint64_t value)
{
    std::uint64_t result{1};
    for (std::uint64_t current{2}; current <= value; ++current) {
        result *= current;
    }
    return result;
}

std::uint64_t count_unique_permutations(const std::string& letters)
{
    std::array<std::uint64_t, 26> frequency{};
    for (const char ch : letters) {
        ++frequency[ch - 'a'];
    }

    std::uint64_t count = factorial(letters.size());
    for (const std::uint64_t repeats : frequency) {
        count /= factorial(repeats);
    }

    return count;
}

void solve(std::istream& in, std::ostream& out)
{
    std::string letters;
    in >> letters;

    std::sort(letters.begin(), letters.end());

    out << count_unique_permutations(letters) << '\n';

    do {
        out << letters << '\n';
    } while (std::next_permutation(letters.begin(), letters.end()));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

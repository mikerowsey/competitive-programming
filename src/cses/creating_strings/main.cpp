// Problem: Creating Strings
//
// Pattern: Enumeration
// Technique: Lexicographic permutation generation
//
// Time:      O(n! · n)
// Space:     O(n)
//
// Insight:
//   Sort the characters first, then repeatedly call std::next_permutation().
//   Starting from the lexicographically smallest arrangement guarantees that
//   every distinct permutation is generated exactly once, even when duplicate
//   characters are present.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    std::string letters;
    in >> letters;

    std::sort(letters.begin(), letters.end());

    std::vector<std::string> permutations;

    do {
        permutations.push_back(letters);
    } while (std::next_permutation(letters.begin(), letters.end()));

    out << permutations.size() << '\n';

    for (const auto& permutation : permutations) {
        out << permutation << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

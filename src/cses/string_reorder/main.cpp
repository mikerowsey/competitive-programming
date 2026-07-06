// Problem: String Reorder
//
// Pattern: Greedy Construction
// Technique: Lexicographic Choice with Feasibility Check
//
// Time: O(26 * n)
// Space: O(n)
//
// Insight:
//   Build the answer left-to-right. At each position, try letters from A to Z
//   (excluding previous letter) and pick the first one that keeps the rest
//   feasible: max remaining frequency <= ceil(remaining_length / 2).
//

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

void solve(std::istream& in, std::ostream& out)
{
    std::string input;
    in >> input;

    const int n = static_cast<int>(input.size());
    std::array<int, 26> count{};

    for (char ch : input) {
        ++count[static_cast<std::size_t>(ch - 'A')];
    }

    if (*std::max_element(count.begin(), count.end()) > (n + 1) / 2) {
        out << -1 << '\n';
        return;
    }

    std::string answer;
    answer.reserve(static_cast<std::size_t>(n));

    int previous = -1;
    for (int position = 0; position < n; ++position) {
        bool placed = false;

        for (int current = 0; current < 26; ++current) {
            if (current == previous || count[static_cast<std::size_t>(current)] == 0) {
                continue;
            }

            --count[static_cast<std::size_t>(current)];

            const int remaining = n - position - 1;
            const int max_remaining = *std::max_element(count.begin(), count.end());

            if (max_remaining <= (remaining + 1) / 2) {
                answer.push_back(static_cast<char>('A' + current));
                previous = current;
                placed = true;
                break;
            }

            ++count[static_cast<std::size_t>(current)];
        }

        if (!placed) {
            out << -1 << '\n';
            return;
        }
    }

    out << answer << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

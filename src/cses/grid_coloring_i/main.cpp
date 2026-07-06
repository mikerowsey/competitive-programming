// Problem: Grid Coloring I
//
// Pattern: Constructive Coloring
// Technique: Checkerboard Letter Sets
//
// Time: O(nm)
// Space: O(1) extra (excluding output)
//
// Insight:
//   Use disjoint letter sets by parity: {A,B} and {C,D}. Adjacent cells
//   always have different parity, so they automatically differ. For each
//   cell, choose any letter from its parity set that is not the original.
//

#include <iostream>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    int n{};
    int m{};
    in >> n >> m;

    std::vector<std::string> grid(static_cast<std::size_t>(n));
    for (int row = 0; row < n; ++row) {
        in >> grid[static_cast<std::size_t>(row)];
    }

    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < m; ++column) {
            const char first_choice = ((row + column) % 2 == 0) ? 'A' : 'C';
            const char second_choice = ((row + column) % 2 == 0) ? 'B' : 'D';

            if (grid[static_cast<std::size_t>(row)][static_cast<std::size_t>(column)] == first_choice) {
                out << second_choice;
            } else {
                out << first_choice;
            }
        }
        out << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

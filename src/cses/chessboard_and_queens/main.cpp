// Problem: Chessboard and Queens
//
// Pattern: Depth-First Search
// Technique: Backtracking
// Time: O(8!)
// Space: O(8)
//
// Insight: Place one queen in each row while tracking occupied
//          columns and diagonals. Skip blocked squares and prune
//          invalid placements immediately. The search explores only
//          legal partial configurations and counts all complete
//          arrangements.

#include <array>
#include <functional>
#include <iostream>
#include <string>

void solve(std::istream& in, std::ostream& out)
{
    std::array<std::string, 8> board;

    for (auto& row : board) {
        in >> row;
    }

    std::array<bool, 8> col{};
    std::array<bool, 15> diag1{};
    std::array<bool, 15> diag2{};

    std::function<int(int)> search = [&](int row) -> int {
        if (row == 8) {
            return 1;
        }

        int count{0};

        for (int c{0}; c < 8; ++c) {
            if (board[row][c] == '*') {
                continue;
            }

            const int d1{row - c + 7};
            const int d2{row + c};

            if (col[c] || diag1[d1] || diag2[d2]) {
                continue;
            }

            col[c] = diag1[d1] = diag2[d2] = true;

            count += search(row + 1);

            col[c] = diag1[d1] = diag2[d2] = false;
        }

        return count;
    };

    out << search(0) << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}

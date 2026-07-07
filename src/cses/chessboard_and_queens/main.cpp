// Problem: Chessboard and Queens

#include <array>
#include <iostream>
#include <string>

int search_placements(const std::array<std::string, 8>& board,
                      std::array<bool, 8>& columns,
                      std::array<bool, 15>& left_diagonals,
                      std::array<bool, 15>& right_diagonals,
                      int row)
{
    if (row == 8) {
        return 1;
    }

    int count{0};

    for (int column{0}; column < 8; ++column) {
        if (board[row][column] == '*') {
            continue;
        }

        const int left_diagonal{row - column + 7};
        const int right_diagonal{row + column};

        if (columns[column] || left_diagonals[left_diagonal] || right_diagonals[right_diagonal]) {
            continue;
        }

        columns[column] = left_diagonals[left_diagonal] = right_diagonals[right_diagonal] = true;
        count += search_placements(board, columns, left_diagonals, right_diagonals, row + 1);
        columns[column] = left_diagonals[left_diagonal] = right_diagonals[right_diagonal] = false;
    }

    return count;
}

void solve(std::istream& in, std::ostream& out)
{
    std::array<std::string, 8> board;

    for (auto& row : board) {
        in >> row;
    }

    std::array<bool, 8> columns{};
    std::array<bool, 15> left_diagonals{};
    std::array<bool, 15> right_diagonals{};

    out << search_placements(board, columns, left_diagonals, right_diagonals, 0) << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}

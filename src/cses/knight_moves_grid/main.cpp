// Problem: Knight Moves Grid
//
// Pattern: Graph Shortest Path
// Technique: BFS on Implicit Knight Graph
//
// Time: O(n^2)
// Space: O(n^2)
//
// Insight:
//   Each square is a graph node, and knight moves are unweighted edges.
//   A single BFS from the top-left corner computes the minimum move count
//   to every square on the bounded n x n board.
//

#include <array>
#include <iostream>
#include <queue>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    int n{};
    in >> n;

    const std::array<int, 8> dr{-2, -2, -1, -1, 1, 1, 2, 2};
    const std::array<int, 8> dc{-1, 1, -2, 2, -2, 2, -1, 1};

    std::vector<int> distance(static_cast<std::size_t>(n) * static_cast<std::size_t>(n), -1);
    std::queue<int> pending;

    distance[0] = 0;
    pending.push(0);

    while (!pending.empty()) {
        const int index = pending.front();
        pending.pop();

        const int row = index / n;
        const int column = index % n;
        const int current_distance = distance[static_cast<std::size_t>(index)];

        for (int move = 0; move < 8; ++move) {
            const int next_row = row + dr[move];
            const int next_column = column + dc[move];

            if (next_row < 0 || next_row >= n || next_column < 0 || next_column >= n) {
                continue;
            }

            const int next_index = next_row * n + next_column;
            if (distance[static_cast<std::size_t>(next_index)] != -1) {
                continue;
            }

            distance[static_cast<std::size_t>(next_index)] = current_distance + 1;
            pending.push(next_index);
        }
    }

    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < n; ++column) {
            if (column > 0) {
                out << ' ';
            }
            out << distance[static_cast<std::size_t>(row) * static_cast<std::size_t>(n) + static_cast<std::size_t>(column)];
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

// Problem: Grid Path Description

#include <array>
#include <iostream>
#include <string>

namespace {

constexpr int kPathLength = 48;

std::array<std::array<bool, 9>, 9> visited{};
std::array<char, kPathLength> description{};

constexpr std::array<int, 4> dx{-1, 1, 0, 0};
constexpr std::array<int, 4> dy{0, 0, -1, 1};
constexpr std::array<char, 4> dc{'U', 'D', 'L', 'R'};

bool one_way_neighbor(const int x, const int y)
{
    if (x == 7 && y == 1) {
        return false;
    }

    int free_neighbors = 0;
    for (int direction = 0; direction < 4; ++direction) {
        const int nx = x + dx[direction];
        const int ny = y + dy[direction];
        if (!visited[nx][ny]) {
            ++free_neighbors;
        }
    }

    return free_neighbors == 1;
}

int dfs(const int x, const int y, const int step)
{
    if (x == 7 && y == 1) {
        return step == kPathLength ? 1 : 0;
    }

    if (step == kPathLength) {
        return 0;
    }

    // If we are boxed in vertically or horizontally while both side cells are
    // free, the path would split the remaining board into disconnected parts.
    if (visited[x - 1][y] && visited[x + 1][y] && !visited[x][y - 1] && !visited[x][y + 1]) {
        return 0;
    }
    if (visited[x][y - 1] && visited[x][y + 1] && !visited[x - 1][y] && !visited[x + 1][y]) {
        return 0;
    }

    visited[x][y] = true;

    int result = 0;
    const char required = description[step];

    int forced_direction = -1;
    if (required == '?') {
        for (int direction = 0; direction < 4; ++direction) {
            const int nx = x + dx[direction];
            const int ny = y + dy[direction];
            if (visited[nx][ny]) {
                continue;
            }

            if (one_way_neighbor(nx, ny)) {
                if (forced_direction != -1 && forced_direction != direction) {
                    visited[x][y] = false;
                    return 0;
                }
                forced_direction = direction;
            }
        }
    }

    for (int direction = 0; direction < 4; ++direction) {
        if (required != '?' && dc[direction] != required) {
            continue;
        }
        if (forced_direction != -1 && direction != forced_direction) {
            continue;
        }

        const int nx = x + dx[direction];
        const int ny = y + dy[direction];
        if (visited[nx][ny]) {
            continue;
        }

        result += dfs(nx, ny, step + 1);
    }

    visited[x][y] = false;
    return result;
}

} // namespace

void solve(std::istream& in, std::ostream& out)
{
    std::string pattern;
    in >> pattern;

    for (int i = 0; i < kPathLength; ++i) {
        description[i] = pattern[static_cast<std::size_t>(i)];
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            visited[i][j] = (i == 0 || i == 8 || j == 0 || j == 8);
        }
    }

    out << dfs(1, 1, 0) << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

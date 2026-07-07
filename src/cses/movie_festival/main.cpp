// Problem: Movie Festival

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    std::size_t movie_count = 0;
    in >> movie_count;

    std::vector<std::pair<std::uint32_t, std::uint32_t>> movies(movie_count);
    for (auto& [start_time, end_time] : movies) {
        in >> start_time >> end_time;
    }

    std::sort(movies.begin(), movies.end(),
              [](const std::pair<std::uint32_t, std::uint32_t>& left,
                 const std::pair<std::uint32_t, std::uint32_t>& right) {
                  return left.second < right.second;
              });

    std::uint32_t current_end_time = 0;
    std::uint32_t selected_movies = 0;
    for (const auto& [start_time, end_time] : movies) {
        if (start_time >= current_end_time) {
            current_end_time = end_time;
            ++selected_movies;
        }
    }

    out << selected_movies << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

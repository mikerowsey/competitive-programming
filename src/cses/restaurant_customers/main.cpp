// Problem: Restaurant Customers

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    std::size_t customer_count = 0;
    in >> customer_count;

    std::vector<std::pair<std::uint32_t, std::int32_t>> events;
    events.reserve(customer_count * 2);

    for (std::size_t i = 0; i < customer_count; ++i) {
        std::uint32_t arrival = 0;
        std::uint32_t departure = 0;
        in >> arrival >> departure;
        events.emplace_back(arrival, 1);
        events.emplace_back(departure, -1);
    }

    std::sort(events.begin(), events.end(),
              [](const std::pair<std::uint32_t, std::int32_t>& left,
                 const std::pair<std::uint32_t, std::int32_t>& right) {
                  if (left.first != right.first) {
                      return left.first < right.first;
                  }
                  return left.second < right.second;
              });

    std::int32_t current_customers = 0;
    std::int32_t max_customers = 0;
    for (const auto& [time, delta] : events) {
        (void)time;
        current_customers += delta;
        max_customers = std::max(max_customers, current_customers);
    }

    out << max_customers << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

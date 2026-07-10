// Problem: Distinct Numbers

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t n;
    in >> n;

    std::vector<std::uint64_t> numbers;
    numbers.reserve(n);
    for (std::uint64_t i = 0; i < n; ++i) {
        std::uint64_t x;
        in >> x;
        numbers.push_back(x);
    }

    std::sort(numbers.begin(), numbers.end());

    std::uint64_t distinct_count = 0;
    std::uint64_t previous = 0;
    bool first = true;
    for (const std::uint64_t value : numbers) {
        if (first || value != previous) {
            ++distinct_count;
            previous = value;
            first = false;
        }
    }

    out << distinct_count << "\n";
}

#ifndef CP_DISABLE_MAIN
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}
#endif

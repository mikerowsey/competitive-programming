// Problem: Two Sets

#include <cstdint>
#include <iostream>
#include <vector>

void print_set(std::ostream& out, const std::vector<std::uint64_t>& values)
{
    out << values.size() << '\n';

    for (std::size_t index = 0; index < values.size(); ++index) {
        if (index > 0) {
            out << ' ';
        }
        out << values[index];
    }

    out << '\n';
}

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t n{};
    in >> n;

    std::vector<std::uint64_t> first_set;
    std::vector<std::uint64_t> second_set;

    std::uint64_t remaining_sum = n * (n + 1) / 2;

    if (remaining_sum & 1) {
        out << "NO\n";
        return;
    }

    out << "YES\n";

    remaining_sum /= 2;

    for (std::uint64_t value{n}; value > 0; --value) {
        if (value <= remaining_sum) {
            first_set.push_back(value);
            remaining_sum -= value;
        } else {
            second_set.push_back(value);
        }
    }

    print_set(out, first_set);
    print_set(out, second_set);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
}

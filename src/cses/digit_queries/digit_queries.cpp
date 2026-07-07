// Problem: Digit Queries

#include <cstdint>
#include <iostream>
#include <string>

void solve(std::istream& in, std::ostream& out)
{
    std::int64_t queries{};
    in >> queries;

    for (std::int64_t query = 0; query < queries; ++query) {
        std::int64_t index{};
        in >> index;

        std::int64_t digits_per_number = 1;
        std::int64_t block_digit_count = 9;
        std::int64_t block_start = 1;

        while (index > block_digit_count) {
            index -= block_digit_count;
            ++digits_per_number;
            block_start *= 10;
            block_digit_count = 9 * block_start * digits_per_number;
        }

        --index;
        const std::int64_t number = block_start + index / digits_per_number;
        const std::int64_t digit_index = index % digits_per_number;

        const std::string as_text = std::to_string(number);
        out << as_text[static_cast<std::size_t>(digit_index)] << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

// Problem: Apartments

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

void solve(std::istream& in, std::ostream& out)
{
    std::size_t applicants_count = 0;
    std::size_t apartments_count = 0;
    std::int64_t tolerance = 0;
    in >> applicants_count >> apartments_count >> tolerance;

    std::vector<std::int64_t> desired_sizes(applicants_count);
    for (std::int64_t& desired_size : desired_sizes) {
        in >> desired_size;
    }

    std::vector<std::int64_t> apartment_sizes(apartments_count);
    for (std::int64_t& apartment_size : apartment_sizes) {
        in >> apartment_size;
    }

    std::sort(desired_sizes.begin(), desired_sizes.end());
    std::sort(apartment_sizes.begin(), apartment_sizes.end());

    std::size_t applicant_index = 0;
    std::size_t apartment_index = 0;
    std::int64_t matches = 0;

    while (applicant_index < applicants_count && apartment_index < apartments_count) {
        const std::int64_t desired_size = desired_sizes[applicant_index];
        const std::int64_t apartment_size = apartment_sizes[apartment_index];

        if (std::abs(desired_size - apartment_size) <= tolerance) {
            ++applicant_index;
            ++apartment_index;
            ++matches;
        } else if (desired_size - apartment_size > tolerance) {
            ++apartment_index;
        } else {
            ++applicant_index;
        }
    }

    out << matches << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

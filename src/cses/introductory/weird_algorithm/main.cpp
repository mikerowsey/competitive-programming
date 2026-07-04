// Problem: Weird Algorithm
//
// Pattern: Simulation
// Technique: Iterative State Update
//
// Time: O(k)   k = number of terms generated
// Space: O(1)
//
// Insight:
//  Repeatedly apply the Collatz rules until reaching 1.
//  Each iteration updates the current value in place, so only
//  constant extra memory is required.

#include <iostream>

#include "core/types.hpp"

using namespace std;

void solve(std::istream& in, std::ostream& out)
{
    u64 n;
    in >> n;
    while (true) {
        out << n;
        if (n == 1) break;
        out << ' ';
        if ((n & 1) == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }
    out << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

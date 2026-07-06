// Problem: Tower of Hanoi
//
// Pattern: Recursion
// Technique: Divide and Conquer
//
// Time: O(2^n)
// Space: O(n)
//
// Insight:
//   To move n disks from source to destination, first move n - 1 disks to
//   the auxiliary peg, move the largest disk to the destination, then move
//   the n - 1 disks from the auxiliary peg to the destination.

#include <cstdint>
#include <iostream>

void hanoi(std::uint64_t disks,
           std::uint64_t src,
           std::uint64_t aux,
           std::uint64_t dest,
           std::ostream& out)
{
    if (disks == 1) {
        out << src << ' ' << dest << '\n';
        return;
    }

    hanoi(disks - 1, src, dest, aux, out);
    out << src << ' ' << dest << '\n';
    hanoi(disks - 1, aux, src, dest, out);
}

void solve(std::istream& in, std::ostream& out)
{
    std::uint64_t disks{};
    in >> disks;

    const std::uint64_t move_count = (std::uint64_t{1} << disks) - 1;

    out << move_count << '\n';

    hanoi(disks, 1, 2, 3, out);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

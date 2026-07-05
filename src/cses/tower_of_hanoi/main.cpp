// Problem: Tower of Hanoi
//
// Pattern:   Recursion
// Technique: Divide and Conquer
//
// Time:      O(2^n)
// Space:     O(n)
//
// Insight:
//   To move n disks from source to destination, first move n - 1 disks
//   to the auxiliary peg, move the largest disk to the destination,
//   then move the n - 1 disks from the auxiliary peg to the destination.
 
#include <cstdint>
#include <iostream>
 
using u64 = std::uint64_t;
 
void hanoi(u64 disks, u64 src, u64 aux, u64 dest, std::ostream& out)
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
    u64 disks{};
    in >> disks;
 
    out << ((1ULL << disks) - 1) << '\n';
 
    hanoi(disks, 1, 2, 3, out);
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve(std::cin, std::cout);
}

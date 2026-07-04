#pragma once

#include <numeric>

#include "core/types.hpp"

namespace core {

constexpr u64 gcd(u64 a, u64 b)
{
    return std::gcd(a, b);
}

constexpr u64 lcm(u64 a, u64 b)
{
    return std::lcm(a, b);
}

constexpr u64 mod_pow(u64 base, u64 exp, u64 mod)
{
    u64 result{1};

    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

} // namespace core

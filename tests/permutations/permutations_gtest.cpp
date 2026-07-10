#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(permutations_test, case_00)
{
    cses::gtest_case_utils::expect_permutations_case_matches(
        solve, cses::gtest_case_utils::repo_path(
                   "tests/permutations/gtest_cases/case_00_input.txt"));
}

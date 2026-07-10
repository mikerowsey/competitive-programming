#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(two_sets_test, case_00)
{
    cses::gtest_case_utils::expect_two_sets_case_matches(
        solve,
        cses::gtest_case_utils::repo_path("tests/two_sets/gtest_cases/case_00_input.txt"));
}

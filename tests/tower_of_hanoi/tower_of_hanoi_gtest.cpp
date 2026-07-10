#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(tower_of_hanoi_test, case_00)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "tests/tower_of_hanoi/gtest_cases/case_00_input.txt"),
        cses::gtest_case_utils::repo_path(
            "tests/tower_of_hanoi/gtest_cases/case_00_output.txt"));
}

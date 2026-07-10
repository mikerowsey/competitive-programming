#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(grid_path_description_test, case_00)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "tests/grid_path_description/gtest_cases/case_00_input.txt"),
        cses::gtest_case_utils::repo_path(
            "tests/grid_path_description/gtest_cases/case_00_output.txt"));
}

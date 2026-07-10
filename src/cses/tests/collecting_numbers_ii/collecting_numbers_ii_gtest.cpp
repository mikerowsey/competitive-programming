#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(collecting_numbers_ii_test, case_00)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers_ii/gtest_cases/case_00_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers_ii/gtest_cases/case_00_output.txt"));
}

TEST(collecting_numbers_ii_test, case_01)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers_ii/gtest_cases/case_01_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers_ii/gtest_cases/case_01_output.txt"));
}

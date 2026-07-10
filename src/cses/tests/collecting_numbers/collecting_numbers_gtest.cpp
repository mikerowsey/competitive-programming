#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(collecting_numbers_test, case_00)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_00_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_00_output.txt"));
}

TEST(collecting_numbers_test, case_01)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_01_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_01_output.txt"));
}

TEST(collecting_numbers_test, case_02)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_02_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_02_output.txt"));
}

TEST(collecting_numbers_test, case_03)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_03_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_03_output.txt"));
}

TEST(collecting_numbers_test, case_04)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_04_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_04_output.txt"));
}

TEST(collecting_numbers_test, case_05)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_05_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_05_output.txt"));
}

TEST(collecting_numbers_test, case_06)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_06_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/collecting_numbers/gtest_cases/case_06_output.txt"));
}

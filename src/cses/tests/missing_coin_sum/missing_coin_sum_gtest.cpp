#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(missing_coin_sum_test, case_00)
{
    cses::gtest_case_utils::expect_case_matches(
        solve,
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/missing_coin_sum/gtest_cases/case_00_input.txt"),
        cses::gtest_case_utils::repo_path(
            "src/cses/tests/missing_coin_sum/gtest_cases/case_00_output.txt"));
}

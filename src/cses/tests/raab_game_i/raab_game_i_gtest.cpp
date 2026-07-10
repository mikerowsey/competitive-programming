#include <gtest/gtest.h>

#include "../gtest_case_utils.hpp"

void solve(std::istream& in, std::ostream& out);

TEST(raab_game_i_test, case_00)
{
    cses::gtest_case_utils::expect_raab_game_i_case_matches(
        solve, cses::gtest_case_utils::repo_path(
                   "src/cses/tests/raab_game_i/gtest_cases/case_00_input.txt"));
}

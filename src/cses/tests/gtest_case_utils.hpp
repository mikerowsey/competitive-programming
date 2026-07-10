#pragma once

#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace cses::gtest_case_utils {

using SolveFunction = void (*)(std::istream& in, std::ostream& out);

inline std::string read_text_file(const std::filesystem::path& path)
{
    std::ifstream file(path);
    EXPECT_TRUE(file.is_open()) << "Failed to open fixture: " << path.string();
    if (!file.is_open()) {
        return "";
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

inline std::string run_case_from_file(SolveFunction solve, const std::filesystem::path& input_path)
{
    std::ifstream input_file(input_path);
    EXPECT_TRUE(input_file.is_open()) << "Failed to open input fixture: " << input_path.string();
    if (!input_file.is_open()) {
        return "";
    }

    std::ostringstream out;
    solve(input_file, out);
    return out.str();
}

inline void expect_case_matches(SolveFunction solve, const std::filesystem::path& input_path,
                                const std::filesystem::path& output_path)
{
    EXPECT_EQ(run_case_from_file(solve, input_path), read_text_file(output_path))
        << "input=" << input_path.string() << " output=" << output_path.string();
}

inline std::vector<std::string> split_tokens(const std::string& text)
{
    std::istringstream in(text);
    std::vector<std::string> tokens;
    std::string token;
    while (in >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

inline std::vector<std::string> non_empty_lines(const std::string& text)
{
    std::istringstream in(text);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        if (line.find_first_not_of(" \t\r\n") != std::string::npos) {
            lines.push_back(line);
        }
    }
    return lines;
}

inline bool parse_int64(std::string_view token, std::int64_t& value)
{
    if (token.empty()) {
        return false;
    }
    std::size_t parsed = 0;
    try {
        value = std::stoll(std::string(token), &parsed);
    } catch (...) {
        return false;
    }
    return parsed == token.size();
}

inline bool parse_int_line(const std::string& line, std::vector<std::int64_t>& values)
{
    const auto tokens = split_tokens(line);
    values.clear();
    values.reserve(tokens.size());

    for (const std::string& token : tokens) {
        std::int64_t value = 0;
        if (!parse_int64(token, value)) {
            return false;
        }
        values.push_back(value);
    }

    return true;
}

inline bool is_permutation_1_to_n(const std::vector<std::int64_t>& values, std::int64_t n)
{
    if (static_cast<std::int64_t>(values.size()) != n || n < 0) {
        return false;
    }

    std::vector<bool> seen(static_cast<std::size_t>(n) + 1, false);
    for (const std::int64_t value : values) {
        if (value < 1 || value > n || seen[static_cast<std::size_t>(value)]) {
            return false;
        }
        seen[static_cast<std::size_t>(value)] = true;
    }
    return true;
}

inline void expect_permutations_case_matches(SolveFunction solve,
                                             const std::filesystem::path& input_path)
{
    std::ifstream input(input_path);
    ASSERT_TRUE(input.is_open()) << "Failed to open input fixture: " << input_path.string();

    std::int64_t n = 0;
    input >> n;
    ASSERT_TRUE(input.good() || input.eof()) << "Failed to parse n from input";

    const std::string output = run_case_from_file(solve, input_path);
    const auto tokens = split_tokens(output);

    if (n == 1) {
        ASSERT_EQ(tokens.size(), 1U) << "Expected a single value for n=1";
        EXPECT_EQ(tokens[0], "1");
        return;
    }

    if (n <= 3) {
        ASSERT_EQ(tokens.size(), 2U) << "Expected 'NO SOLUTION' for n <= 3";
        EXPECT_EQ(tokens[0], "NO");
        EXPECT_EQ(tokens[1], "SOLUTION");
        return;
    }

    ASSERT_EQ(static_cast<std::int64_t>(tokens.size()), n)
        << "Expected exactly n integers in output";

    std::vector<std::int64_t> permutation;
    permutation.reserve(tokens.size());
    for (const std::string& token : tokens) {
        std::int64_t value = 0;
        ASSERT_TRUE(parse_int64(token, value)) << "Non-integer token in output: " << token;
        permutation.push_back(value);
    }

    ASSERT_TRUE(is_permutation_1_to_n(permutation, n)) << "Output is not a permutation of 1..n";
    for (std::size_t i = 1; i < permutation.size(); ++i) {
        EXPECT_NE(std::llabs(permutation[i] - permutation[i - 1]), 1)
            << "Adjacent values differ by 1 at index " << i;
    }
}

inline void expect_two_sets_case_matches(SolveFunction solve,
                                         const std::filesystem::path& input_path)
{
    std::ifstream input(input_path);
    ASSERT_TRUE(input.is_open()) << "Failed to open input fixture: " << input_path.string();

    std::int64_t n = 0;
    input >> n;
    ASSERT_TRUE(input.good() || input.eof()) << "Failed to parse n from input";

    const std::string output = run_case_from_file(solve, input_path);
    const auto tokens = split_tokens(output);
    ASSERT_FALSE(tokens.empty()) << "Output is empty";

    const bool possible = (n % 4 == 0 || n % 4 == 3);
    if (!possible) {
        ASSERT_EQ(tokens.size(), 1U) << "Expected single NO token for impossible case";
        EXPECT_EQ(tokens[0], "NO");
        return;
    }

    ASSERT_EQ(tokens[0], "YES") << "Expected YES for solvable case";

    auto read_counted_set = [&](std::size_t& index, std::vector<std::int64_t>& values) {
        ASSERT_LT(index, tokens.size()) << "Missing set size token";
        std::int64_t count = 0;
        ASSERT_TRUE(parse_int64(tokens[index], count)) << "Invalid set size token";
        ASSERT_GE(count, 0);
        ++index;

        values.clear();
        values.reserve(static_cast<std::size_t>(count));
        for (std::int64_t i = 0; i < count; ++i) {
            ASSERT_LT(index, tokens.size()) << "Missing set element token";
            std::int64_t value = 0;
            ASSERT_TRUE(parse_int64(tokens[index], value)) << "Invalid set element token";
            values.push_back(value);
            ++index;
        }
    };

    std::size_t index = 1;
    std::vector<std::int64_t> set_a;
    std::vector<std::int64_t> set_b;
    read_counted_set(index, set_a);
    read_counted_set(index, set_b);
    ASSERT_EQ(index, tokens.size()) << "Unexpected extra tokens in output";

    std::vector<bool> seen(static_cast<std::size_t>(n) + 1, false);
    auto mark_seen = [&](const std::vector<std::int64_t>& values, const char* set_name) {
        for (const std::int64_t value : values) {
            ASSERT_GE(value, 1) << set_name << " contains value < 1";
            ASSERT_LE(value, n) << set_name << " contains value > n";
            ASSERT_FALSE(seen[static_cast<std::size_t>(value)])
                << "Duplicate value across sets: " << value;
            seen[static_cast<std::size_t>(value)] = true;
        }
    };

    mark_seen(set_a, "first set");
    mark_seen(set_b, "second set");
    for (std::int64_t value = 1; value <= n; ++value) {
        EXPECT_TRUE(seen[static_cast<std::size_t>(value)])
            << "Missing value in partition: " << value;
    }

    const std::int64_t sum_a = std::accumulate(set_a.begin(), set_a.end(), std::int64_t{0});
    const std::int64_t sum_b = std::accumulate(set_b.begin(), set_b.end(), std::int64_t{0});
    EXPECT_EQ(sum_a, sum_b) << "Partition sums are not equal";
}

inline void expect_raab_game_i_case_matches(SolveFunction solve,
                                            const std::filesystem::path& input_path)
{
    std::ifstream input(input_path);
    ASSERT_TRUE(input.is_open()) << "Failed to open input fixture: " << input_path.string();

    std::int64_t t = 0;
    input >> t;
    ASSERT_TRUE(input.good() || input.eof()) << "Failed to parse test count";

    struct Case {
        std::int64_t n;
        std::int64_t a;
        std::int64_t b;
    };

    std::vector<Case> cases;
    cases.reserve(static_cast<std::size_t>(std::max<std::int64_t>(0, t)));
    for (std::int64_t i = 0; i < t; ++i) {
        Case c{};
        input >> c.n >> c.a >> c.b;
        ASSERT_TRUE(input.good() || input.eof()) << "Invalid case line at index " << i;
        cases.push_back(c);
    }

    const std::string output = run_case_from_file(solve, input_path);
    const auto lines = non_empty_lines(output);

    std::size_t line_index = 0;
    for (std::size_t case_index = 0; case_index < cases.size(); ++case_index) {
        const auto& c = cases[case_index];
        const bool possible = ((c.a == 0 && c.b == 0) || (c.a > 0 && c.b > 0 && c.a + c.b <= c.n));

        ASSERT_LT(line_index, lines.size()) << "Missing YES/NO line at case " << (case_index + 1);
        const std::string ans =
            split_tokens(lines[line_index]).empty() ? "" : split_tokens(lines[line_index]).front();
        ++line_index;

        ASSERT_TRUE(ans == "YES" || ans == "NO")
            << "Invalid answer token at case " << (case_index + 1) << ": " << ans;

        if (ans == "NO") {
            EXPECT_FALSE(possible) << "Case " << (case_index + 1) << " expected YES but got NO";
            continue;
        }

        ASSERT_TRUE(possible) << "Case " << (case_index + 1) << " expected NO but got YES";

        ASSERT_LT(line_index, lines.size())
            << "Missing first permutation at case " << (case_index + 1);
        std::vector<std::int64_t> p1;
        ASSERT_TRUE(parse_int_line(lines[line_index], p1));
        ++line_index;

        ASSERT_LT(line_index, lines.size())
            << "Missing second permutation at case " << (case_index + 1);
        std::vector<std::int64_t> p2;
        ASSERT_TRUE(parse_int_line(lines[line_index], p2));
        ++line_index;

        ASSERT_TRUE(is_permutation_1_to_n(p1, c.n))
            << "Invalid first permutation at case " << (case_index + 1);
        ASSERT_TRUE(is_permutation_1_to_n(p2, c.n))
            << "Invalid second permutation at case " << (case_index + 1);

        std::int64_t score1 = 0;
        std::int64_t score2 = 0;
        for (std::size_t i = 0; i < p1.size(); ++i) {
            if (p1[i] > p2[i]) {
                ++score1;
            }
            if (p1[i] < p2[i]) {
                ++score2;
            }
        }

        EXPECT_EQ(score1, c.a) << "First score mismatch at case " << (case_index + 1);
        EXPECT_EQ(score2, c.b) << "Second score mismatch at case " << (case_index + 1);
    }

    EXPECT_EQ(line_index, lines.size()) << "Unexpected extra output lines after last case";
}

inline std::filesystem::path repo_path(const std::string& relative)
{
    return std::filesystem::path(CP_REPO_ROOT) / relative;
}

inline std::string case_name_for_index(std::size_t case_index)
{
    std::ostringstream name;
    name << "case_" << std::setw(2) << std::setfill('0') << case_index;
    return name.str();
}

inline std::vector<std::filesystem::path> discover_case_inputs(
    const std::filesystem::path& cases_dir)
{
    std::vector<std::filesystem::path> input_files;

    if (!std::filesystem::exists(cases_dir)) {
        return input_files;
    }

    for (const auto& entry : std::filesystem::directory_iterator(cases_dir)) {
        if (!entry.is_regular_file()) {
            continue;
        }

        const auto file_name = entry.path().filename().string();
        if (file_name.size() >= 10 && file_name.ends_with("_input.txt")) {
            input_files.push_back(entry.path());
        }
    }

    std::sort(input_files.begin(), input_files.end());
    return input_files;
}

inline std::filesystem::path expected_output_path_for_input(const std::filesystem::path& input_path)
{
    const auto input_name = input_path.filename().string();
    const auto base_name =
        input_name.substr(0, input_name.size() - std::string("_input.txt").size());
    return input_path.parent_path() / (base_name + "_output.txt");
}

}  // namespace cses::gtest_case_utils

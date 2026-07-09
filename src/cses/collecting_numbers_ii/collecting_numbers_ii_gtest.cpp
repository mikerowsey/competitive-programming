#include <gtest/gtest.h>

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

void solve(std::istream& in, std::ostream& out);

namespace {

std::string read_text_file(const std::filesystem::path& path)
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

std::string run_case_from_file(const std::filesystem::path& input_path)
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

std::filesystem::path repo_path(const std::string& relative)
{
    return std::filesystem::path(CP_REPO_ROOT) / relative;
}

std::string case_name_for_index(std::size_t case_index)
{
    std::ostringstream name;
    name << "case_" << std::setw(2) << std::setfill('0') << case_index;
    return name.str();
}

void expect_case_matches(const std::filesystem::path& input_path,
                         const std::filesystem::path& output_path)
{
    EXPECT_EQ(run_case_from_file(input_path), read_text_file(output_path))
        << "input=" << input_path.string() << " output=" << output_path.string();
}

std::vector<std::filesystem::path> discover_case_inputs(const std::filesystem::path& cases_dir)
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

class CollectingNumbersIICaseTest : public ::testing::Test {
   public:
    CollectingNumbersIICaseTest(std::filesystem::path input_path, std::filesystem::path output_path)
        : input_path_(std::move(input_path)), output_path_(std::move(output_path))
    {
    }

    void TestBody() override { expect_case_matches(input_path_, output_path_); }

   private:
    std::filesystem::path input_path_;
    std::filesystem::path output_path_;
};

void register_case_tests()
{
    const auto cases_dir = repo_path("src/cses/collecting_numbers_ii/gtest_cases");
    const auto input_files = discover_case_inputs(cases_dir);

    ASSERT_FALSE(input_files.empty()) << "No *_input.txt files found in " << cases_dir.string();

    for (std::size_t case_index = 0; case_index < input_files.size(); ++case_index) {
        const auto& input_path = input_files[case_index];
        const auto input_name = input_path.filename().string();
        const auto base_name =
            input_name.substr(0, input_name.size() - std::string("_input.txt").size());
        const auto output_path = input_path.parent_path() / (base_name + "_output.txt");

        ASSERT_TRUE(std::filesystem::exists(output_path))
            << "Missing output fixture for " << input_name << ": " << output_path.string();

        const auto test_name = case_name_for_index(case_index);
        ::testing::RegisterTest("CollectingNumbersIITest", test_name.c_str(), nullptr, nullptr,
                                __FILE__, __LINE__,
                                [input_path, output_path]() -> CollectingNumbersIICaseTest* {
                                    return new CollectingNumbersIICaseTest(input_path, output_path);
                                });
    }
}

const bool registered_cases = (register_case_tests(), true);

}  // namespace

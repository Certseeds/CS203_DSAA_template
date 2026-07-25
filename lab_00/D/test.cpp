// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <gtest_main.hpp>
#include <iostream>
#include <tuple>
#include "main.cpp"

std::string getFilePath() noexcept { return "./../../../lab_00/D/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_00_D {

using std::cin;
using std::cout;
using std::tie;
using std::tuple;
using std::vector;

TEST(lab_00_D, test_case_1) {
    const CS203_redirect cr{"01.data.in"};
    // 重定向开始,开始run
    auto input_data = read();
    cal(input_data);
    // 重定向结束
}

TEST(lab_00_D, test_case_2) {
    {
        const CS203_redirect cr{"01.data.in", "01.test.out"};
        auto input_data = read();
        cal(input_data);
    }
    EXPECT_TRUE(compareFiles("01.test.out", "01.data.out"));
}
} // namespace lab_00_D

#endif // ALGORITHM_TEST_MACRO

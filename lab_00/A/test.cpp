// SPDX-License-Identifier: AGPL-3.0-or-later
// SPDX-FileCopyrightText: 2020-2025 nanoseeds
#ifdef ALGORITHM_TEST_MACRO

#include <gtest_main.hpp>
#include <iostream>
#include <tuple>
#include <vector>
#include <random>

#include "main.cpp"

std::string getFilePath() noexcept { return "./../../../lab_00/lab_00_A/resource/"; }

const std::string CS203_redirect::file_paths = getFilePath();

namespace lab_00_A {
using std::cin;
using std::cout;
using std::tie;
using std::tuple;
using std::vector;

TEST(lab_00_A, test_case_1) {
    const auto output1 = cal(std::make_tuple(0, 0));
    auto output2 = cal(std::make_tuple(100000, 100000));
    EXPECT_FALSE(output1);
    EXPECT_EQ(200000, output2);
}

TEST(lab_00_A, test_case_2) {
    auto output1 = cal(std::make_tuple(0, 100000));
    auto output2 = cal(std::make_tuple(100000, 0));
    EXPECT_EQ(100000, output1);
    EXPECT_EQ(100000, output2);
}

TEST(lab_00_A, test_case_3) {
    std::random_device rd{};
    const auto gen = std::mt19937{rd()};
    const std::uniform_real_distribution<> dis{0, 100000};
    auto randfun = std::bind(dis, gen); // 产生一个函数,返回0-10000的随机数
    for (int i = 0; i < 20; i++) {
        const int a = randfun(), b = randfun();
        EXPECT_EQ(cal(std::make_tuple(a, b)),
                  cal(std::make_tuple(b, a)));          // 确认对偶性
        EXPECT_EQ(a + b, cal(std::make_tuple(a, b))); // 确认正确性
    }
}

TEST(lab_00_A, test_case_4) {
    const auto output = cal(std::make_tuple(100, 1000));
    EXPECT_EQ(1100, output);
}
} // namespace lab_00_A
#endif // ALGORITHM_TEST_MACRO

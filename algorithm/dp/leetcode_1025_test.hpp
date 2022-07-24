// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Tag 位运算
//@Tag 数学归纳法

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1025_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1025_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1025 {
using std::vector;

struct leetcode_1025 {
    static bool divisorGame(int32_t n);

    static bool divisorGame2(int32_t n);
};

TEST_CASE("1 [test_1025]", "[test_1025]") {
    static constexpr const auto input{1};
    CHECK_FALSE(leetcode_1025::divisorGame(input));
    CHECK_FALSE(leetcode_1025::divisorGame2(input));
}

TEST_CASE("2 [test_1025]", "[test_1025]") {
    static constexpr const auto input{2};
    CHECK(leetcode_1025::divisorGame(input));
    CHECK(leetcode_1025::divisorGame2(input));
}

TEST_CASE("3 [test_1025]", "[test_1025]") {
    static constexpr const auto input{11};
    CHECK_FALSE(leetcode_1025::divisorGame(input));
    CHECK_FALSE(leetcode_1025::divisorGame2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1025_TEST_CPP

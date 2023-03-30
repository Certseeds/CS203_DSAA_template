// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 单调栈
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day9

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_42_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_42_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_42 {
using std::vector;

struct leetcode_42 {
    static int32_t trap(const vector<int32_t> &height);

    static int32_t trapDPLoca(const vector<int32_t> &height);

    static int32_t trapDPHeight(const vector<int32_t> &height);
};

TEST_CASE("test case 2 [test _42]", "[test _42]") {
    const vector<int32_t> input{4, 2, 0, 3, 2, 5};
    static constexpr const auto result{9};
    CHECK(result == leetcode_42::trap(input));
    CHECK(result == leetcode_42::trapDPLoca(input));
    CHECK(result == leetcode_42::trapDPHeight(input));
}

TEST_CASE("test case 1 [test _42]", "[test _42]") {
    const vector<int32_t> input{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    static constexpr const auto result{6};
    CHECK(result == leetcode_42::trap(input));
    CHECK(result == leetcode_42::trapDPLoca(input));
    CHECK(result == leetcode_42::trapDPHeight(input));
}

TEST_CASE("test case 3 [test _42]", "[test _42]") {
    const vector<int32_t> input{0, 1, 0, 3, 1, 0, 1, 3, 2, 1, 2, 1};
    static constexpr const auto result{9};
    CHECK(result == leetcode_42::trap(input));
    CHECK(result == leetcode_42::trapDPLoca(input));
    CHECK(result == leetcode_42::trapDPHeight(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_42_TEST_HPP

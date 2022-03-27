// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Tag stack
//@Tag 单调栈
//@Linked 121
//@Plan 动态规划入门 Day7
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_122 {
using std::vector;

struct leetcode_122 final {
    static int32_t maxProfit(const vector<int32_t> &prices);

    static int32_t maxProfit2(const vector<int32_t> &prices);

    static int32_t maxProfit3(const vector<int32_t> &prices);

    static int32_t maxProfit4(const vector<int32_t> &prices);
};


TEST_CASE("1 [test_122]", "[test_122]") {
    const vector<int32_t> input{7, 1, 5, 3, 6, 4};
    static constexpr const auto result{7};
    CHECK(result == leetcode_122::maxProfit(input));
    CHECK(result == leetcode_122::maxProfit2(input));
    CHECK(result == leetcode_122::maxProfit3(input));
    CHECK(result == leetcode_122::maxProfit4(input));
}

TEST_CASE("2 [test_122]", "[test_122]") {
    const vector<int32_t> input{7, 6, 4, 3, 1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_122::maxProfit(input));
    CHECK(result == leetcode_122::maxProfit2(input));
    CHECK(result == leetcode_122::maxProfit3(input));
    CHECK(result == leetcode_122::maxProfit4(input));
}

TEST_CASE("3 [test_122]", "[test_122]") {
    const vector<int32_t> input{1, 2, 3, 4, 5};
    static constexpr const auto result{4};
    CHECK(result == leetcode_122::maxProfit(input));
    CHECK(result == leetcode_122::maxProfit2(input));
    CHECK(result == leetcode_122::maxProfit3(input));
    CHECK(result == leetcode_122::maxProfit4(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP

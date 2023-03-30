// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Tag stack
//@Tag 单调栈
//@Linked 121 122 309
//@Plan 动态规划入门 Day8

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_714_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_714_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_714 {
using std::vector;

struct leetcode_714 final {
    static int32_t maxProfit(const vector<int32_t> &prices, int32_t fee);

    static int32_t maxProfit2(const vector<int32_t> &prices, int32_t fee);
};

TEST_CASE("0 [test_714]", "[test_714]") {
    const vector<int32_t> input{1, 2, 3, 0, 2};
    static constexpr const auto fee{0};
    static constexpr const auto result{4};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("1 [test_714]", "[test_714]") {
    const vector<int32_t> input{7, 1, 5, 3, 6, 4};
    static constexpr const auto fee{0};
    static constexpr const auto result{7};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("2 [test_714]", "[test_714]") {
    const vector<int32_t> input{7, 6, 4, 3, 1};
    static constexpr const auto fee{0};
    static constexpr const auto result{0};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("3 [test_714]", "[test_714]") {
    const vector<int32_t> input{1, 2, 3, 4, 5};
    static constexpr const auto fee{0};
    static constexpr const auto result{4};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("4 [test_714]", "[test_714]") {
    const vector<int32_t> input{1, 3, 2, 8, 4, 9};
    static constexpr const auto fee{2};
    static constexpr const auto result{8};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("5 [test_714]", "[test_714]") {
    const vector<int32_t> input{1, 3, 7, 5, 10, 3};
    static constexpr const auto fee{3};
    static constexpr const auto result{6};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_714_TEST_CPP

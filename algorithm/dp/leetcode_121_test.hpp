// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day7
//@Plan 数据结构入门 Day3
//@Plan 剑指OfferII-I Day08
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_121_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_121_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_121 {
using std::vector;

struct leetcode_121 final {
    static int32_t maxProfit(const vector<int32_t> &prices);

    static int32_t maxProfit2(const vector<int32_t> &prices);
};


TEST_CASE("1 [test_121]", "[test_121]") {
    const vector<int32_t> input{7, 1, 5, 3, 6, 4};
    static constexpr const auto result{5};
    CHECK(result == leetcode_121::maxProfit(input));
    CHECK(result == leetcode_121::maxProfit2(input));
}

TEST_CASE("2 [test_121]", "[test_121]") {
    const vector<int32_t> input{7, 6, 4, 3, 1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_121::maxProfit(input));
    CHECK(result == leetcode_121::maxProfit2(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_121_TEST_CPP

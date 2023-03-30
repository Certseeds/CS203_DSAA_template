// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day6
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1567_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1567_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1567 {
using std::vector;

struct leetcode_1567 {
    static int32_t getMaxLen(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{1, -2, -3, 4};
    static constexpr const auto result{4};
    CHECK(result == leetcode_1567::getMaxLen(input));
}

TEST_CASE("2 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{0, 1, -2, -3, -4};
    static constexpr const auto result{3};
    CHECK(result == leetcode_1567::getMaxLen(input));

}

TEST_CASE("3 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{-1, -2, -3, 0, 1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_1567::getMaxLen(input));
}

TEST_CASE("4 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{-1, 2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_1567::getMaxLen(input));
}

TEST_CASE("5 [test_1567]", "[test_1567]") {
    const vector<int32_t> input{1, 2, 3, 5, -6, 4, 0, 10};
    static constexpr const auto result{4};
    CHECK(result == leetcode_1567::getMaxLen(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1567_TEST_CPP

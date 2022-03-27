// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day18

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_376_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_376_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_376 {
using std::vector;

struct leetcode_376 final {
    static int32_t wiggleMaxLength(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_376]", "[test_376]") {
    const vector<int32_t> input{1, 7, 4, 9, 2, 5};
    static constexpr const auto result{6};
    CHECK(result == leetcode_376::wiggleMaxLength(input));
}

TEST_CASE("2 [test_376]", "[test_376]") {
    const vector<int32_t> input{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    static constexpr const auto result{7};
    CHECK(result == leetcode_376::wiggleMaxLength(input));
}

TEST_CASE("3 [test_376]", "[test_376]") {
    const vector<int32_t> input{1, 2, 3, 4, 5, 6, 7, 8, 9};
    static constexpr const auto result{2};
    CHECK(result == leetcode_376::wiggleMaxLength(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_376_TEST_CPP

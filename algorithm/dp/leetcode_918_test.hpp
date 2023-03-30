// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day5

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_918_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_918_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_918 {
using std::vector;

struct leetcode_918 final {
    static int32_t maxSubarraySumCircular(const vector<int32_t> &nums);
};

TEST_CASE("10 [test_918]", "[test_918]") {
    const vector<int32_t> input{-2, 4, -5, 4, -5, 9, 4};
    static constexpr const auto result{15};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("9 [test_918]", "[test_918]") {
    const vector<int32_t> input{2, -2, 2, 7, 8, 0};
    static constexpr const auto result{19};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("6 [test_918]", "[test_918]") {
    const vector<int32_t> input{-2, 3, 5};
    static constexpr const auto result{8};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("1 [test_918]", "[test_918]") {
    const vector<int32_t> input{1, -2, 3, -2};
    static constexpr const auto result{3};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("2 [test_918]", "[test_918]") {
    const vector<int32_t> input{5, -3, 5};
    static constexpr const auto result{10};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("3 [test_918]", "[test_918]") {
    const vector<int32_t> input{3, -1, 2, -1};
    static constexpr const auto result{4};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("4 [test_918]", "[test_918]") {
    const vector<int32_t> input{3, -2, 2, -3};
    static constexpr const auto result{3};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("5 [test_918]", "[test_918]") {
    const vector<int32_t> input{-2, -3, -1};
    static constexpr const auto result{-1};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}


TEST_CASE("7 [test_918]", "[test_918]") {
    const vector<int32_t> input{3, 1, 3, 2, 6};
    static constexpr const auto result{15};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("8 [test_918]", "[test_918]") {
    const vector<int32_t> input{-7, 1, 2, 7, -2, -5};
    static constexpr const auto result{10};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_918_TEST_CPP

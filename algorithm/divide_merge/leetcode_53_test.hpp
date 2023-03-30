// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag divide_merge
//@Tag 分治
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day5
//@Plan 数据结构入门 Day1
//@Plan 剑指OfferII-I Day09
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_53 {
using std::string;
using std::vector;

struct leetcode_53 {
    static int32_t maxSubArray(const vector<int32_t> &nums);

    static int32_t maxSubArray2(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_53]", "[test_53]") {
    const vector<int32_t> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    static constexpr const int32_t output{6};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("2 [test_53]", "[test_53]") {
    const vector<int32_t> input{1};
    static constexpr const int32_t output{1};
    CHECK(leetcode_53::maxSubArray2(input) == output);
    CHECK(leetcode_53::maxSubArray(input) == output);
}

TEST_CASE("3 [test_53]", "[test_53]") {
    const vector<int32_t> input{0};
    static constexpr const int32_t output{0};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("4 [test_53]", "[test_53]") {
    const vector<int32_t> input{-1};
    static constexpr const int32_t output{-1};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("5 [test_53]", "[test_53]") {
    const vector<int32_t> input{-100000};
    static constexpr const int32_t output{-100000};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("6 [test_53]", "[test_53]") {
    const vector<int32_t> input{-2, -1};
    static constexpr const int32_t output{-1};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("7 [test_53]", "[test_53]") {
    const vector<int32_t> input{5, 4, -1, 7, 8};
    static constexpr const int32_t output{23};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP

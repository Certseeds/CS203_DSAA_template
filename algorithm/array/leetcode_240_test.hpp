// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 二分搜索
//@Plan 剑指OfferII-I Day05
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_240_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_240_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_240 {
using std::vector;

struct leetcode_240 {
    static bool findNumberIn2DArray(const vector<vector<int32_t>> &matrix, int32_t target);
    static bool findNumberIn2DArrayZ(const vector<vector<int32_t>> &matrix, int32_t target);
};

TEST_CASE("test case 1 {test_240}", "{test_240}") {
    const vector<vector<int32_t>> input{
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    static constexpr const auto k{5};
    CHECK(leetcode_240::findNumberIn2DArray(input, k));
    CHECK(leetcode_240::findNumberIn2DArrayZ(input, k));
}

TEST_CASE("test case 2 {test_240}", "{test_240}") {
    const vector<vector<int32_t>> input{
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    static constexpr const auto k{20};
    CHECK_FALSE(leetcode_240::findNumberIn2DArray(input, k));
    CHECK_FALSE(leetcode_240::findNumberIn2DArrayZ(input, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_240_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_807_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_807_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_807 {
using std::vector;
using std::array;

struct leetcode_807 {
    static int maxIncreaseKeepingSkyline(const vector<vector<int32_t>> &grid);
};

TEST_CASE("test case 1 {test_807}", "{test_807}") {
    const vector<vector<int32_t>> heights{
            {3, 0, 8, 4},
            {2, 4, 5, 7},
            {9, 2, 6, 3},
            {0, 3, 1, 0}
    };
    static constexpr const auto result{35};
    CHECK(result == leetcode_807::maxIncreaseKeepingSkyline(heights));
}

TEST_CASE("test case 2 {test_807}", "{test_807}") {
    const vector<vector<int32_t>> heights{
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_807::maxIncreaseKeepingSkyline(heights));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_807_TEST_HPP

// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 不同路径2
//@Plan 动态规划入门 Day15
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_63_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_63_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_63 {
using std::vector;

struct leetcode_63 final {
    static int32_t uniquePathsWithObstacles(const vector<vector<int>> &obstacleGrid);
};

TEST_CASE("1 [test_63]", "[test_63]") {
    const vector<vector<int32_t>> input{{0, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    static constexpr const auto result{2};
    CHECK(result == leetcode_63::uniquePathsWithObstacles(input));
}

TEST_CASE("2 [test_63]", "[test_63]") {
    const vector<vector<int32_t>> input{{0, 1},
                                        {0, 0}};
    static constexpr const auto result{1};
    CHECK(result == leetcode_63::uniquePathsWithObstacles(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_63_TEST_CPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_931 {
using std::vector;

struct leetcode_931 final {
    static int32_t minFallingPathSum(const vector<vector<int32_t>> &matrix);
};

TEST_CASE("1 [test_931]", "[test_931]") {
    const vector<vector<int32_t>> input{
            {2, 1, 3},
            {6, 5, 4},
            {7, 8, 9}
    };
    static constexpr const auto result{13};
    CHECK(result == leetcode_931::minFallingPathSum(input));
}

TEST_CASE("2 [test_931]", "[test_931]") {
    const vector<vector<int32_t>> input{
            {-19, 57},
            {-40, -5},
    };
    static constexpr const auto result{-59};
    CHECK(result == leetcode_931::minFallingPathSum(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP

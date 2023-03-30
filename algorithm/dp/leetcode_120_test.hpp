// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_120_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_120_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <numeric>

namespace leetcode_120 {
using std::vector;

struct leetcode_120 final {
    static int32_t minimumTotal(const vector<vector<int32_t>> &triangle);
};

TEST_CASE("1 [test_120]", "[test_120]") {
    const vector<vector<int32_t>> input{
            {1},
    };
    static constexpr const auto result{1};
    CHECK(result == leetcode_120::minimumTotal(input));
}

TEST_CASE("2 [test_120]", "[test_120]") {
    const vector<vector<int32_t>> input{
            {2},
            {3, 4},
            {5, 6, 7},
            {4, 1, 8, 3},
    };
    static constexpr const auto result{11};
    CHECK(result == leetcode_120::minimumTotal(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_120_TEST_CPP

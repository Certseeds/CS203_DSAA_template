// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 数据结构基础 Day3
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_435_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_435_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_435 {
using std::vector;

struct leetcode_435 final {
    static int32_t eraseOverlapIntervals(const vector<vector<int32_t>> &intervals);
};


TEST_CASE("1 [test_435]", "[test_435]") {
    const vector<vector<int32_t>> input{
            {1, 2},
            {2, 3},
            {3, 4},
            {1, 3},
    };
    static constexpr const auto result{1};
    CHECK(result == leetcode_435::eraseOverlapIntervals(input));
}

TEST_CASE("2 [test_435]", "[test_435]") {
    const vector<vector<int32_t>> input{
            {1, 2},
            {1, 2},
            {1, 2},
    };
    static constexpr const auto result{2};
    CHECK(result == leetcode_435::eraseOverlapIntervals(input));
}

TEST_CASE("3 [test_435]", "[test_435]") {
    const vector<vector<int32_t>> input{
            {1, 2},
            {2, 3},
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_435::eraseOverlapIntervals(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_435_TEST_CPP

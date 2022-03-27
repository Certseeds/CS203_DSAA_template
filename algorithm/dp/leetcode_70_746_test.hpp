// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 斐波那契?
//@Plan 动态规划入门 Day2
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_70_746_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_70_746_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_70 {
using std::vector;

struct leetcode_70 final {
    static int32_t climbStairs(int32_t n);
};

TEST_CASE("1 [test_70]", "[test_70]") {
    static constexpr const auto input{2}, result{2};
    CHECK(result == leetcode_70::climbStairs(input));
}

TEST_CASE("2 [test_70]", "[test_70]") {
    static constexpr const auto input{3}, result{3};
    CHECK(result == leetcode_70::climbStairs(input));
}

TEST_CASE("3 [test_70]", "[test_70]") {
    static constexpr const auto input{4}, result{5};
    CHECK(result == leetcode_70::climbStairs(input));
}

TEST_CASE("4 [test_70]", "[test_70]") {
    static constexpr const auto input{5}, result{8};
    CHECK(result == leetcode_70::climbStairs(input));
}

TEST_CASE("5 [test_70]", "[test_70]") {
    static constexpr const auto input{6}, result{13};
    CHECK(result == leetcode_70::climbStairs(input));
}
}

namespace leetcode_746 {
using std::vector;

struct leetcode_746 final {
    static int32_t minCostClimbingStairs(const vector<int32_t> &cost);

    static int32_t minCostClimbingStairs2(const vector<int32_t> &cost);
};

TEST_CASE("1 [test_746]", "[test_746]") {
    const vector<int32_t> input{10, 15, 20};
    static constexpr const auto output{15};
    CHECK(output == leetcode_746::minCostClimbingStairs(input));
    CHECK(output == leetcode_746::minCostClimbingStairs2(input));
}

TEST_CASE("2 [test_746]", "[test_746]") {
    const vector<int32_t> input{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    static constexpr const auto output{6};
    // 0 -> 2 -> 4 ->6 -> 7 -> 9 -> out六跳,每跳cost 1
    CHECK(output == leetcode_746::minCostClimbingStairs(input));
    CHECK(output == leetcode_746::minCostClimbingStairs2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_70_746_TEST_CPP

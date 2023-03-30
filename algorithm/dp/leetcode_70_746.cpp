// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#include "leetcode_70_746_test.hpp"

namespace leetcode_70 {
int32_t leetcode_70::climbStairs(int32_t n) {
    int32_t b{1};
    for (int32_t a{0}, i{0}, temp{-1}; i < n; i++) {
        temp = a;
        a = b;
        b = temp + a;
    }
    return b;
}
}

namespace leetcode_746 {
int32_t leetcode_746::minCostClimbingStairs(const vector<int32_t> &cost) {
    const auto cost_size{cost.size()}; // always >= 2
    vector<int32_t> dp(cost.size() + 1, 0);
    for (size_t i{2}; i <= cost_size; i++) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp.back();
}

int32_t leetcode_746::minCostClimbingStairs2(const vector<int32_t> &cost) {
    const auto cost_size{cost.size()}; // always >= 2
    std::array<int32_t, 3> dp{0, 0, 0};
    // 滚 动 数 组
    for (size_t i{2}; i <= cost_size; i++) {
        dp[2] = std::min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}
}

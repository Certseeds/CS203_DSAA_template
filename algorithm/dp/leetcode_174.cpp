// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#include "leetcode_174_test.hpp"

namespace leetcode_174 {

int32_t leetcode_174::calculateMinimumHP(const vector<vector<int32_t>> &dungeon) {
    if (dungeon.empty() || dungeon.front().empty()) {
        return 0;
    }
    const auto m{dungeon.size()}, n{dungeon.front().size()};
    vector<vector<int32_t>> dp(m + 1, vector<int32_t>(n + 1, 0));
    for (size_t i{m}; i > 0; i--) {
        for (size_t j{n}; j > 0; j--) {
            dp[i][j] = dungeon[i - 1][j - 1];
        }
    }
    // i,j -> 到i,j点时,可以到达终点的最低血量.
    dp[m][n] = std::max(1 - dp[m][n], 1);
    for (size_t i{m - 1}; i > 0; i--) {
        dp[i].back() = std::max(dp[i + 1].back() - dp[i].back(), 1);
    }
    for (size_t i{n - 1}; i > 0; i--) {
        dp.back()[i] = std::max(dp.back()[i + 1] - dp.back()[i], 1);
    }
    for (size_t i{m - 1}; i > 0; i--) {
        for (size_t j{n - 1}; j > 0; j--) {
            dp[i][j] = std::max(std::min(dp[i + 1][j], dp[i][j + 1]) - dp[i][j], 1);
        }
    }
    return dp[1][1];
}
}

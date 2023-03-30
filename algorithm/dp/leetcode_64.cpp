// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_64_test.hpp"

namespace leetcode_64 {

int32_t leetcode_64::minPathSum(const vector<vector<int32_t>> &grid) {
    vector<vector<int32_t>> dp{grid};
    const auto m{grid.size()}, n{grid.front().size()};
    for (size_t i{1}; i < m; i++) {
        dp[i][0] += dp[i - 1][0];
    }
    for (size_t i{1}; i < n; i++) {
        dp[0][i] += dp[0][i - 1];
    }
    for (size_t i{1}; i < m; i++) {
        for (size_t j{1}; j < n; j++) {
            dp[i][j] += std::min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp.back().back();
}

}

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_62_test.hpp"

namespace leetcode_62 {

int leetcode_62::uniquePaths(size_t m, size_t n) {
    vector<vector<int32_t>> DP(m, vector<int32_t>(n, 1));
    for (size_t i{1}; i < m; i++) {
        for (size_t j{1}; j < n; j++) {
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }
    return DP.back().back();
}

}

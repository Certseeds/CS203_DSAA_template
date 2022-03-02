// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_516_test.hpp"
#include <vector>

namespace leetcode_516 {
using std::vector;

int32_t leetcode_516::longestPalindromeSubseq(const string &s) {
    const auto s_size{s.size()};
    if (s.size() <= 1) {
        return static_cast<int32_t>(s_size);
    }
    vector<vector<int32_t>> dp(s_size, vector<int32_t>(s_size, 0));
    int32_t will_return{0};
    for (size_t i{s_size}; i > 0; i--) {
        dp[i - 1][i - 1] = 1;
        const auto ch1{s[i - 1]};
        for (size_t j{i}; j < s_size; j++) {
            const auto ch2{s[j]};
            if (ch1 == ch2) {
                dp[i - 1][j] = dp[i][j - 1] + 2;
            } else {
                dp[i - 1][j] = std::max(dp[i][j], dp[i - 1][j - 1]);
                // dp[i][j] 指的是 i,j的子序列的最大长度,因此需要在这里递归的去掉左侧或去掉右侧来匹配
            }
            will_return = std::max(will_return, dp[i - 1][j]);
        }
    }

    return will_return;
}

}
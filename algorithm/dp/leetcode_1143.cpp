/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanos
 * @Date: 2021-04-03 10:15:42
 * @LastEditors: nanos
 */
// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_1143_test.hpp"
#include <vector>

namespace leetcode_1143 {
using std::vector;

int32_t leetcode_1143::longestCommonSubsequence2(const string &text1, const string &text2) {
    const auto fst_size{text1.size()}, snd_size{text2.size()};
    vector<vector<int32_t>> dp(fst_size + 1, vector<int32_t>(snd_size + 1, 0));
    // init vector for 0 can except init [0][...],[...][0] to 0
    for (size_t i{1}; i <= fst_size; i++) {
        for (size_t j{1}; j <= snd_size; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp.back().back();
}

int32_t leetcode_1143::longestCommonSubsequence(const string &text1, const string &text2) {
    const auto fst_size{text1.size()}, snd_size{text2.size()};
    vector<int32_t> fst(snd_size + 1, 0), snd(snd_size + 1, 0);
    // init vector for 0 can except init [0][...],[...][0] to 0
    for (size_t i{1}; i <= fst_size; i++) {
        for (size_t j{1}; j <= snd_size; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                snd[j] = fst[j - 1] + 1;
            } else {
                snd[j] = std::max(snd[j - 1], fst[j]);
            }
        }
        std::swap(fst, snd);
    }
    return fst.back();
}
}
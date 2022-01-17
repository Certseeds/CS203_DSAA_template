/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanos
 * @Date: 2021-04-03 10:15:42
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "leetcode_1143_test.hpp"

namespace leetcode_1143 {
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
    vector<int32_t> fst(snd_size + 1, 0),snd(snd_size + 1, 0);
    // init vector for 0 can except init [0][...],[...][0] to 0
    for (size_t i{1}; i <= fst_size; i++) {
        for (size_t j{1}; j <= snd_size; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                snd[j] = fst[j - 1] + 1;
            } else {
                snd[j] = std::max(snd[j - 1], fst[j]);
            }
        }
        std::swap(fst,snd);
    }
    return fst.back();
}
}
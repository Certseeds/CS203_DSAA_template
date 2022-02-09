/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanos

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
#include "leetcode_72_test.hpp"

namespace leetcode_72 {

int32_t leetcode_72::minDistance(const string &word1, const string &word2) {
    const size_t fst_size{word1.size()}, snd_size{word2.size()};
    vector<vector<size_t>> dp(fst_size + 1, vector<size_t>(snd_size + 1, 0));
    // dp[i][j], word1[0~i],word2[0~j]的编辑距离
    // 将增,删,改 规约成
    // A增,B增,A改, 再规约成
    // A最后增, B最后增, A任意改
    for (size_t i{0}; i <= fst_size; i++) {
        dp[i][0] = i;
    }
    for (size_t i{1}; i <= snd_size; i++) {
        dp[0][i] = i;
    }
    for (size_t i{1}; i <= fst_size; i++) {
        for (size_t j{1}; j <= snd_size; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = std::min({dp[i - 1][j - 1], dp[i][j - 1] + 1, dp[i - 1][j] + 1});
                // 分别对应不改,B增,A增
            } else {
                // 分别对应改,B增,A增
                dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }
    return static_cast<int32_t>(dp.back().back());
}

}
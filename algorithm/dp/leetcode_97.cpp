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
#include "leetcode_97_test.hpp"

namespace leetcode_97 {

bool leetcode_97::isInterleave(const string &s1, const string &s2, const string &s3) {
    const auto s1_size{s1.size()}, s2_size{s2.size()}, s3_size{s3.size()};
    if (s1_size + s2_size != s3_size) {
        return false;
    } else if (s1_size == 0) {
        return s2 == s3;
    } else if (s2_size == 0) {
        return s1 == s3;
    }
    vector<vector<uint8_t>> dp(s1_size + 1, vector<uint8_t>(s2_size + 1, false));
    dp[0][0] = true;
    for (size_t i{1}; i <= s1_size && dp[i - 1][0]; i++) {
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    }
    for (size_t i{1}; i <= s2_size && dp[0][i - 1]; i++) {
        dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
    }
    for (size_t i{1}; i <= s1_size; i++) {
        for (size_t j{1}; j <= s2_size; j++) {
            const char &char1{s1[i - 1]}, char2{s2[j - 1]}, char3{s3[i + j - 1]};
            if (char1 == char3) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
            if (char2 == char3) {
                dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }
    return dp.back().back();
}
}
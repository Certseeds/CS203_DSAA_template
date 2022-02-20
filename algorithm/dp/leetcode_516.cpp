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
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
#include "leetcode_32_test.hpp"

namespace leetcode_32 {
int32_t leetcode_32::longestValidParentheses(const string &s) {
    const auto s_size{s.size()};
    if (s_size <= 1) {
        return 0;
    }
    vector<int32_t> DP(s_size, 0);
    for (std::remove_const<decltype(s_size)>::type i{1}; i < s_size; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                DP[i] = 2;
                if (i >= 2) {
                    DP[i] += DP[i - 2];
                }
            } else if (i - DP[i - 1] > 0 && s[i - DP[i - 1] - 1] == '(') {
                DP[i] = DP[i - 1] + 2;
                if (static_cast<int32_t>(i) >= DP[i - 1] + 2) {
                    DP[i] += DP[i - DP[i - 1] - 2];
                }
            }
        }
    }
    // dp[0] is always 0
    return *std::max_element(DP.cbegin() + 1, DP.cend());
}

}
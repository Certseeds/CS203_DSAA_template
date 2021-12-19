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
#include "leetcode_5_test.hpp"

namespace lcs_5 {

string leetcode_5::longestPalindrome(const string &s) {
    const size_t s_size = s.size();
    if (s_size <= 1) {
        return s;
    } else if (s_size == 2) {
        if (s[0] == s[1]) {
            return s;
        } else {
            return s.substr(0, 1);
        }
    }
    vector<vector<uint8_t>> dp(s_size, vector<uint8_t>(s_size, false));
    std::pair<size_t, size_t> begin_end{0, 1};
    size_t max_size = 1;
    for (size_t i{0}; i < s_size; i++) {
        dp[i][i] = true;
    }
    for (size_t i{0}; i < s_size - 1; i++) {
        dp[i][i + 1] = (s[i] == s[i + 1]);
        if (dp[i][i + 1]) {
            max_size = 2;
            begin_end = {i, max_size};
        }
    }
    for (size_t i{s_size}; i > 0; i--) {
        for (size_t j{i + 1}; j < s_size; j++) {
            dp[i - 1][j] = ((s[i - 1] == s[j]) && dp[i][j - 1]);
            if (j - i + 2 > max_size && dp[i - 1][j]) {
                max_size = j - i + 2;
                begin_end = {i - 1, max_size};
            }
        }
    }
    return s.substr(begin_end.first, begin_end.second);
}
}
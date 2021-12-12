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
#include "leetcode_91_test.hpp"

namespace leetcode_91 {

int32_t leetcode_91::numDecodings(const string &str) {
    const auto str_size{str.size()};
    if (str_size == 1) {
        return '1' <= str[0] && str[0] <= '9';
    }
    vector<int32_t> dp(str_size + 1, 0);
    dp[0] = 1; // 前0个字符 有且只有一种编码方式
    dp[1] = '1' <= str[0] && str[0] <= '9'; // 第一个字符需要在[1,9]
    for (size_t i{2}; i <= str_size; i++) {
        const auto nowChar{str[i - 1]};
        const auto lastChar{str[i - 2]};
        if ('1' <= nowChar && nowChar <= '9') {
            dp[i] += dp[i - 1];
        }
        const auto combine{(lastChar - '0') * 10 + (nowChar - '0')};
        if (10 <= combine && combine <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp.back();
}

}
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
#include "leetcode_343_test.hpp"

namespace leetcode_343 {


int32_t leetcode_343::integerBreak(int32_t n) {
    if (n <= 3) {
        return n - 1;
    }
    vector<int32_t> dp{0, 1, 2, 3};
    dp.resize(n + 4);
    for (int32_t i{4}; i <= n; i++) {
        dp[i] = std::max(2 * dp[i - 2], 3 * dp[i - 3]);
        // 根源在于要用接近e(2.71828)的那一个
        // 理论上拆分成e的和之后乘积最大化
    }
    return dp[n];
}

int64_t leetcode_343::integerBreak(int64_t n) {
    if (n <= 3) {
        return n - 1;
    }
    vector<int64_t> dp{0, 1, 2, 3};
    dp.resize(n + 4);
    for (int64_t i{4}; i <= n; i++) {
        dp[i] = std::max(2 * dp[i - 2], 3 * dp[i - 3]);
        // 根源在于要用接近e(2.71828)的那一个
        // 理论上拆分成e的和之后乘积最大化
    }
    return dp[n];
}

}
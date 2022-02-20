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
#include "leetcode_264_test.hpp"

namespace leetcode_264 {

int32_t leetcode_264::nthUglyNumber(int32_t n) {
    vector<int32_t> dp(n + 1, 0);
    dp[0] = 1;
    const auto search = [&dp](int32_t range, double v) {
        int32_t begin{0}, middle{0}, end{range};
        while (begin < end) {
            middle = (end - begin) / 2 + begin;
            const double dpV = dp[middle];
            if (dpV <= v) {
                begin = middle + 1;
            } else if (dpV > v) {
                end = middle;
            }
        }
        return begin;
    };
    for (int32_t i{1}; i < n; i++) {
        const double last = dp[i - 1];
        const auto div2{static_cast<int32_t>(last / 2)}, div3{
                static_cast<int32_t>(last / 3)}, div5{static_cast<int32_t>(last / 5)};
        int32_t maxDiv2{dp[search(i, div2)] * 2}, maxDiv3{dp[search(i, div3)] * 3}, maxDiv5{dp[search(i, div5)] * 5};
        maxDiv2 = maxDiv2 > dp[i - 1] ? maxDiv2 : 0x3f3f3f3f;
        maxDiv3 = maxDiv3 > dp[i - 1] ? maxDiv3 : 0x3f3f3f3f;
        maxDiv5 = maxDiv5 > dp[i - 1] ? maxDiv5 : 0x3f3f3f3f;
        dp[i] = std::min({maxDiv2, maxDiv3, maxDiv5});
    }
    // 不想用O(n)的方式,log_2^(2000)也不过20左右
    return dp[n - 1];
}

}
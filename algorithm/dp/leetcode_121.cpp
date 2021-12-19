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
#include "leetcode_121_test.hpp"

namespace leetcode_121 {

int32_t leetcode_121::maxProfit(const vector<int32_t> &prices) {
    const auto p_size{prices.size()};
    if (p_size <= 1) {
        return 0;
    }
    vector<int32_t> dp(p_size + 1, 0);
    // dp[i] 当天之前的最低价格
    dp[0] = 0; // in the 0th day, nothing happen
    dp[1] = prices[0]; // buy and sell, do not earn
    int32_t will_return{0};
    for (size_t i{2}; i <= p_size; i++) {
        will_return = std::max(prices[i - 1] - dp[i - 1], will_return);
        dp[i] = std::min(dp[i - 1], prices[i - 1]);
    }
    return will_return;
}

int32_t leetcode_121::maxProfit2(const vector<int32_t> &prices) {
    const auto p_size{prices.size()};
    if (p_size <= 1) {
        return 0;
    }
    // dpLast 包括前一天的最低价格
    int32_t dpLast{prices[0]}, will_return{0};
    for (size_t i{2}; i <= p_size; i++) {
        will_return = std::max(prices[i - 1] - dpLast, will_return);
        dpLast = std::min(dpLast, prices[i - 1]);
    }
    return will_return;
}
}
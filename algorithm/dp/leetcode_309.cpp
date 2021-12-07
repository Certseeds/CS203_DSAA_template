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
#include "leetcode_309_test.hpp"

namespace leetcode_309 {

int32_t leetcode_309::maxProfit(const vector<int32_t> &prices) {
    const auto p_size{prices.size()};
    if (p_size <= 1) {
        return 0;
    }
    vector<int32_t> dpBuy(p_size + 1, 0), dpSell(p_size + 1, 0);
    dpBuy[0] = 0; // 0 day之前无法有任何操作
    dpSell[0] = 0; // 0 day之前无法有任何操作
    dpBuy[1] = -prices[0]; // 1 day 购入
    dpSell[1] = 0; // 无法sell,没东西
    for (size_t i{2}; i <= p_size; i++) {
        const auto price{prices[i - 1]};
        dpBuy[i] = std::max(dpBuy[i - 1], dpSell[i - 2] - price); // 只有卖出后有冷冻期,买入时没有
        dpSell[i] = std::max(dpSell[i - 1], dpBuy[i - 1] + price);
    }
    return dpSell.back();
}

int32_t leetcode_309::maxProfit2(const vector<int32_t> &prices) {
    const auto p_size{prices.size()};
    if (p_size <= 1) {
        return 0;
    }
    int32_t buy1{-prices[0]}, buy2{0};
    int32_t sell0{0}, sell1{0}, sell2{0};
    for (size_t i{1}; i < p_size; i++, buy1 = buy2, sell1 = sell2) {
        const auto price{prices[i]};
        buy2 = std::max(buy1, sell0 - price); //
        sell2 = std::max(sell1, buy1 + price);
        sell0 = sell1;
    }
    return sell2;
}
}
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
#include "leetcode_518_test.hpp"

namespace leetcode_518 {

int32_t leetcode_518::change(int32_t amount, const vector<int32_t> &coins) {
    if (amount == 0) {
        return coins.empty() ? 0 : 1;
    }
    const auto coins_size{coins.size()}, amount_size{static_cast<size_t>(amount)};
    // dp[i][j]代表使用前i种硬币,在j金额下能够凑出的硬币组合数
    vector<vector<int32_t>> dp(coins_size + 1, vector<int32_t>(amount_size + 1, 0));
    dp[0][0] = 0; // 没有硬币,也没有金额,无法做任何事
    for (size_t i{1}; i <= coins_size; i++) {
        dp[i][0] = 0; // 世界上没有空硬币,因此完全无法拼凑出来
    }
    for (int32_t i{1}; i <= amount; i++) {
        dp[0][i] = 0; // 没有硬币,无法拼出任何金额
    }
    for (size_t i{1}; i <= coins_size; i++) {
        const auto coin{coins[i - 1]};
        for (int32_t j{1}; j <= amount; j++) {
            dp[i][j] = dp[i - 1][j]; // 不使用当前硬币情况下的默认值
        }
        for (size_t coinNum{1}; coinNum * coin <= amount_size; coinNum++) {
            const auto coinSum{coinNum * coin};
            dp[i][coinSum] += 1;// 只使用了当前硬币情况下, 多一种情况
            for (size_t j{coinSum + 1}; j <= amount_size; j++) {
                dp[i][j] += dp[i - 1][j - coinSum];
            }
        }
    }
    return dp.back().back();
}

int32_t leetcode_518::change2(int32_t amount, const vector<int32_t> &coins) {
    const auto coins_size{coins.size()}, amount_size{static_cast<size_t>(amount)};
    // ~dp[i][j]代表使用前i种硬币,在j金额下能够凑出的硬币组合数~
    // dp[j]代表j金额下凑出的硬币组合数
    vector<int32_t> dp(amount_size + 1, 0);
    dp[0] = 1; // 只有没有金额才能不用硬币拼凑出
    for (size_t i{1}; i <= coins_size; i++) {
        const auto coin{coins[i - 1]}; // i代表使用前i种硬币
        for (int32_t j = coin; j <= amount; j++) {
            dp[j] += dp[j - coin];
        }
    }
    return dp.back();
}

}
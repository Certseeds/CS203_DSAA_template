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
#include "leetcode_322_test.hpp"

namespace leetcode_322 {

int32_t leetcode_322::coinChange(const vector<int32_t> &coins, int32_t amount) {
    vector<int32_t> input{};
    for (const auto coinNum: coins) {
        if (coinNum <= amount) {
            input.push_back(coinNum);
        }
    }
    std::sort(input.begin(), input.end());
    // dp[i][j]代表 使用前i种硬币,组合出j面值需要的最小数量
    vector<vector<int32_t>> dp(input.size() + 1, vector<int32_t>(amount + 1, 0x3f3f3f3f));
    dp[0][0] = 0;
    for (int32_t i{1}; i <= amount; i++) {
        dp[0][i] = 0x3f3f3f3f; // 无论怎样, 前0种无法搭配出任何面值
    }
    for (size_t i{1}; i <= input.size(); i++) {
        dp[i][0] = 0; // 无论怎样,0面值可以被0个组合出来
    }
    for (size_t i{1}; i <= input.size(); i++) {
        const auto coin{input[i - 1]};
        for (int32_t j{1}; j <= amount; j++) {
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
            if (j >= coin) {
                // 此处因为是完全背包,所以可以用循环取值的方法求,O(n)
                // 优化一下 就变成了dp[i][j-coin], 由本行上一个组成
                // 简化重复计算,因为计算[i][j]的[i-1][j-coin],[i-1][j-2coin]的话,
                // 实际上[i][j-coin]已经计算了 [i-1][j-2coin],[i-1][j-3coin]...等等,所以只需要对比一次就ok
                dp[i][j] = std::min(dp[i][j], dp[i][j - coin] + 1);
            }
            //for (int32_t k{j}, count{0}; k >= 0; k -= coin, count++) {
            //    dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + count);
            //}
        }
    }
    return dp.back().back() >= 0x3f3f3f3f ? -1 : dp.back().back();
}

}
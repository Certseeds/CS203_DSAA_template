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
#include "leetcode_377_test.hpp"
#include <algorithm>

namespace leetcode_377 {

int32_t leetcode_377::combinationSum4(const vector<int32_t> &nums, int32_t target) {
    const auto nums_size{nums.size()};
    vector<int32_t> numArray{nums};
    std::sort(std::begin(numArray), std::end(numArray));
    // dp[i] 金额为i情况下的组合个数
    vector<int32_t> dp(target + 1, 0);
    dp[0] = 1;// {}, 零只有空能够拼凑出
    // 子问题构造: 去掉最后一个的值,则将其规约成子问题
    for (int32_t i{1}; i <= target; i++) {
        // 确定某个金额的组成
        for (size_t j{0}; j < nums_size && numArray[j] <= i; j++) {
            const auto num{numArray[j]}; // 本次将使用的数字
            dp[i] += dp[i - num];
        }
    }
    return dp.back();
}

}
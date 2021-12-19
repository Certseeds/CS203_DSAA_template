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
#include "leetcode_300_test.hpp"

namespace leetcode_300 {

int32_t leetcode_300::lengthOfLIS(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size <= 1) {
        return static_cast<int32_t>(nums_size);
    }
    vector<int32_t> dp(nums_size, 1);
    // 难点在DP定义上, 如何定义子问题,让问题能够连接起来
    // [j] 以j为结尾的最长严格递增子序列
    int32_t will_return{1};
    for (size_t i{1}; i < nums_size; i++) {
        for (size_t j{0}; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
            will_return = std::max(will_return, dp[i]);
        }
    }
    return will_return;
}

}
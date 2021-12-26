/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanos
 * @Date: 2021-04-03 10:15:42
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
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
#include "leetcode_1014_test.hpp"

namespace leetcode_1014 {

int32_t leetcode_1014::maxScoreSightseeingPair(const vector<int32_t> &nums) noexcept {
    const int32_t nums_size = nums.size();
    if (nums_size <= 1) {
        return 0x3f3f3f3f;
    }
    vector<int32_t> dp(nums_size + 1, 0);
    // dp[i] => 前个里哪一个充当 values[i]+i里的i
    dp[0] = 0; // can not match pair
    dp[1] = 0; // 还没成对
    dp[2] = 0; // 第二个(1th)之前的i序号为0
    int32_t maxDiff{nums[0] + 0 + nums[1] - 1};
    for (int32_t j{3}; j <= nums_size; j++) {
        const auto i = dp[j - 1];
        const int32_t base = nums[j - 1] - j + 1;
        const int32_t diff1 = base + nums[i] + i;
        const int32_t diff2 = base + nums[j - 2] + j - 2;
        if (diff2 > diff1) {
            dp[j] = j - 2;
        } else {
            dp[j] = i;
        }
        maxDiff = std::max({maxDiff, diff1, diff2});
    }
    return maxDiff;
}

}
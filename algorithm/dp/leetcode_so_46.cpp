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
#include "leetcode_so_46_test.hpp"
#include <vector>

namespace leetcode_so_46 {
using std::vector;

int32_t leetcode_so_46::translateNum(int32_t num) {
    if (num < 10) {
        return 1;
    }
    vector<int32_t> nums{};
    while (num > 0) {
        nums.push_back(num % 10);
        num /= 10;
    }
    vector<int32_t> numbers{nums.rbegin(), nums.rend()};
    const auto nums_size{numbers.size()}; // 此时至少为2
    vector<int32_t> dp(nums_size + 1);
    dp[0] = 1;// 空白只有一种可能
    dp[1] = 1; // 一位只有一种可能
    for (size_t i{2}; i <= nums_size; ++i) { // 滚动数组不进行优化
        const auto two{numbers[i - 2] * 10 + numbers[i - 1]};
        if (10 <= two && two <= 25) {
            dp[i] += dp[i - 2];
        }
        dp[i] += dp[i - 1];
    }
    return dp.back();
}

}
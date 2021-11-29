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
#include "leetcode_416_test.hpp"

namespace leetcode_416 {

bool leetcode_416::canPartition(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size <= 1) {
        return false;
    }
    const int32_t sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
    if (sum % 2 == 1) {
        return false;
    }
    const auto target = sum / 2;
    vector<vector<uint8_t>> dp(nums_size + 1, vector<uint8_t>(target + 1, false));
    dp[0][0] = true;
    for (int32_t i{1}; i <= target; i++) {
        dp[0][i] = false; // 无论怎样, 前0种无法装满任何有量的背包
    }
    for (size_t i{1}; i <= nums_size; i++) {
        dp[i][0] = true; // 无论怎样,0量的背包可以被0个物体组合装满
    }
    for (size_t i{1}; i <= nums_size; i++) {
        for (int32_t j{1}; j <= target; j++) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp.back().back();
}

bool leetcode_416::canPartition2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size <= 1) {
        return false;
    }
    const int32_t sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
    if (sum % 2 == 1) {
        return false;
    }
    const auto target = sum / 2;
    vector<uint8_t> last(target + 1, false), now(target + 1, false);
    last[0] = true;
    for (size_t i{1}; i <= nums_size; i++) {
        now[0] = true;
        for (int32_t j{1}; j <= target; j++) {
            now[j] = now[j] || last[j];
            if (j >= nums[i - 1]) {
                now[j] = now[j] || last[j - nums[i - 1]];
            }
        }
        std::swap(last, now);
    }
    return last.back();
}
}
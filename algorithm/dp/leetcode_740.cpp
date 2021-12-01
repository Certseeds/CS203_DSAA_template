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
#include "leetcode_740_test.hpp"

namespace leetcode_740 {

int leetcode_740::deleteAndEarn(const vector<int> &nums) {
    vector<int32_t> values(nums);
    std::sort(std::begin(values), std::end(values));
    const auto maxV{values.back()};
    vector<int32_t> arr(maxV + 1, 0);
    vector<int32_t> dp(maxV + 2, 0);
    for (const auto value: values) {
        arr[value]++;
    }
    dp[0] = 0; // 只选前0个肯定只能得到0的点数
    dp[1] = arr[0]; // 只选第一个 只能得到1的点数
    for (int32_t i{2}; i <= maxV + 1; i++) {
        dp[i] = std::max(dp[i - 2] + arr[i - 1] * (i - 1), dp[i - 1]);
        // 因为排了序,所以考虑的时候后面那个根本还没有, 所以不需要考虑
        // 只需要考虑是 要 i-2并且去掉i-1 还是要i-1
    }
    return dp.back();
}
}
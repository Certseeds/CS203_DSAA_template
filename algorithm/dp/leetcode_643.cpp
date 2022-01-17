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
#include "leetcode_643_test.hpp"

namespace leetcode_643 {

double leetcode_643::findMaxAverage(const vector<int32_t> &nums, int32_t k) {
    const auto nums_size{nums.size()};
    if (nums_size <= static_cast<size_t>(k)) {
        return double(std::accumulate(nums.begin(), nums.end(), 0)) /
               static_cast<double>(nums_size);
    }
    vector<int32_t> DP(nums_size - k + 1);
    DP[0] = std::accumulate(nums.begin(), nums.begin() + k, 0);
    int willreturn = DP[0];
    for (size_t i{1}; i + k <= nums_size; i++) {
        DP[i] = DP[i - 1] - nums[i - 1] + nums[k + i - 1];
        willreturn = std::max(willreturn, DP[i]);
    }
    return willreturn / double(k);
}

}
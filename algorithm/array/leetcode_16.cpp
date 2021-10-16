/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
#include "leetcode_16_test.hpp"

namespace leetcode_16 {
int leetcode_16::threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int32_t mindiff{std::numeric_limits<int32_t>::max()}, will_return{0};
    const auto nums_size = nums.size();
    for (size_t i{0}; i < nums_size; i++) {
        const auto target_diff = target - nums[i];
        size_t left{i + 1}, right{nums_size - 1};
        while (left < right) {
            const auto sum = nums[left] + nums[right];
            const auto diff = target_diff - sum;
            if (diff < 0) {
                right--;
            } else {
                left++;
            }
            if (mindiff > std::abs(diff)) {
                mindiff = std::abs(diff);
                will_return = sum + nums[i];
            }
        }
    }
    return will_return;
}
}
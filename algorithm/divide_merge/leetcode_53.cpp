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
#include "leetcode_53_test.hpp"

namespace leetcode_53 {
// [begin,end)
int32_t maxSubArray(const vector<int32_t> &nums, size_t begin, size_t end) {
    if (begin + 1 == end) {
        return nums[begin];
    }
    const auto half{begin + (end - begin) / 2};
    const auto left{maxSubArray(nums, begin, half)},
            right{maxSubArray(nums, half, end)};
    int32_t max_left{-0x3f3f3f3f}, left_sum{0}, max_right{-0x3f3f3f3f}, right_sum{0};
    for (size_t left_order{half}; left_order >= begin + 1; left_order--) {
        left_sum += nums[left_order - 1];
        max_left = std::max(max_left, left_sum);
    }
    for (size_t right_order{half}; right_order < end; right_order++) {
        right_sum += nums[right_order];
        max_right = std::max(max_right, right_sum);
    }
    return std::max(std::max(left, right), max_left + max_right);
}

int leetcode_53::maxSubArray(const vector<int> &nums) {
    return ::leetcode_53::maxSubArray(nums, 0, nums.size());
}
}
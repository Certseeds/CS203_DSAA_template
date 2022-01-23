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
#include "leetcode_581_test.hpp"

namespace leetcode_581 {

int32_t leetcode_581::findUnsortedSubarray(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    vector<int32_t> nums2{nums};
    std::sort(nums2.begin(), nums2.end());
    size_t left{0}, right{nums.size()};
    for (size_t i{0}; i < nums_size && nums2[i] == nums[i]; i++, left++) {}
    for (size_t i{nums_size}; i > 0 && nums2[i - 1] == nums[i - 1]; i--, right--) {}
    return std::max(0, static_cast<int32_t>(right - left));
}

int32_t leetcode_581::findUnsortedSubarray2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    size_t left{nums.size() - 1}, right{0};
    int32_t maxV{std::numeric_limits<int32_t>::min()}, minV{std::numeric_limits<int32_t>::max()};
    for (size_t i{0}; i < nums_size; i++) {
        if (nums[i] >= maxV) {
            maxV = nums[i];
        } else {
            right = i;
        }
    }
    for (size_t i{nums_size}; i > 0; i--) {
        if (nums[i - 1] <= minV) {
            minV = nums[i - 1];
        } else {
            left = i - 1;
        }
    }
    return right == 0 ? 0 : right - left + 1;
}
}

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
#include "leetcode_152_test.hpp"

namespace leetcode_152 {

int32_t leetcode_152::maxProduct(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 0) {
        return 0;
    } else if (nums_size == 1) {
        return nums[0];
    }
    vector<int32_t> dpMax(nums_size + 1, 0), dpMin(nums_size + 1, 0);
    dpMax[0] = 0; // 以第0个结尾的一定是0
    dpMin[0] = 0; // 以第0个结尾的一定是0
    dpMax[1] = nums[0]; // 以第一个结尾的一定是nums[0]
    dpMin[1] = nums[0]; // 以第一个结尾的一定是nums[0]
    int32_t maxV{nums[0]};
    for (size_t i{2}; i <= nums_size; i++) {
        if (nums[i - 1] > 0) {
            dpMax[i] = std::max(dpMax[i - 1] * nums[i - 1], nums[i - 1]);
            dpMin[i] = std::min(dpMin[i - 1] * nums[i - 1], nums[i - 1]);
        } else if (nums[i - 1] == 0) {
            dpMax[i] = 0;
            dpMin[i] = 0;
        } else {
            dpMax[i] = std::max(dpMin[i - 1] * nums[i - 1], nums[i - 1]);
            dpMin[i] = std::min(dpMax[i - 1] * nums[i - 1], nums[i - 1]);
            // 这里其实考虑到了对称性, 先确认了dpMax,再确认的dpMin
        }
        maxV = std::max(maxV, dpMax[i]);
    }
    return maxV;
}

int32_t leetcode_152::maxProduct2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 0) {
        return 0;
    } else if (nums_size == 1) {
        return nums[0];
    }
    int32_t aMax{nums[0]}, bMax, maxV{nums[0]};
    int32_t aMin{nums[0]}, bMin;
    // 滚 动 数 组
    for (size_t i{2}; i <= nums_size; maxV = std::max(maxV, bMax), i++, aMax = bMax, aMin = bMin) {
        if (nums[i - 1] > 0) {
            bMax = std::max(aMax * nums[i - 1], nums[i - 1]);
            bMin = std::min(aMin * nums[i - 1], nums[i - 1]);
        } else if (nums[i - 1] == 0) {
            bMax = 0;
            bMin = 0;
        } else {
            bMax = std::max(aMin * nums[i - 1], nums[i - 1]);
            bMin = std::min(aMax * nums[i - 1], nums[i - 1]);
        }
    }
    return maxV;
}
}
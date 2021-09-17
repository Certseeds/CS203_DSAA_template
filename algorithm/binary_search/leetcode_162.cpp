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
#include "leetcode_162_test.hpp"

namespace leetcode_162 {

int leetcode_162::findPeakElement(const vector<int> &nums) {
    const auto nums_size = nums.size();
    if (nums_size == 1 || nums.front() > nums[1]) {
        return 0;
    }
    if (nums[nums_size - 2] < nums.back()) {
        return static_cast<int32_t>(nums_size - 1);
    }
    size_t left{0}, step{[nums_size] {
        size_t step{1};
        while (step < nums_size) {
            step *= 2;
        }
        return step / 2;
    }()};
    const auto judge = [nums, nums_size](size_t order) {
        if (order == 0 || order == nums_size - 1) {
            return -1;
        }
        return (nums[order] > nums[order - 1] && nums[order] > nums[order + 1]) ? static_cast<int32_t>(order)
                                                                                : -1;
    };
    while (left < nums_size && step > 0) {
        if (judge(left) != -1) {
            return static_cast<int32_t>(left);
        }
        if (left + step  >= 1 && left + step < nums_size && nums[left + step - 1] < nums[left + step]
            && left + step + 1 < nums_size && nums[left + step] < nums[left + step + 1]) {
            left += step;
        } else {
            step /= 2;
        }// 核心思想,找一个最后一个处于 "上升状态" 的节点
    }
    return static_cast<int32_t>(left) + 1;
}

int32_t leetcode_162::findPeakElement2(const vector<int> &nums) {
    constexpr const static auto nege1{static_cast<int32_t>(-1)};
    const auto nums_size = nums.size();
    if (nums_size == 1) {
        return 0;
    }
    if (nums.front() > nums[1]) {
        return 0;
    }
    if (nums[nums_size - 2] < nums.back()) {
        return static_cast<int32_t>(nums_size - 1);
    }
    size_t left{0}, right{nums_size - 1}, mid;
    const auto judge = [nums, nums_size](size_t order) {
        if (order == 0 || order == nums_size - 1) {
            return nege1;
        }
        return (nums[order] > nums[order - 1] && nums[order] > nums[order + 1]) ? static_cast<int32_t>(order)
                                                                                : nege1;
    };
    while (left < right) {
        mid = (right - left) / 2 + left;
        if (judge(mid) != -1) {
            return judge(mid);
        } else if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    } // 核心思想,先排除边界条件
    // 之后 寻找第一个
    return static_cast<int32_t>(left);
}
}
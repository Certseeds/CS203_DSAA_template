/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanos
 * @Date: 2021-09-07 00:08:19
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
#include "leetcode_35_test.hpp"

// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一
namespace binary_search::leetcode_35 {

int32_t leetcode_35::searchInsert(const vector<int> &nums, int32_t target) {
    const auto n_size = static_cast<int32_t>(nums.size());
    if (nums.empty() || target < nums.front()) {
        return 0; // 放到第一个
    } else if (nums.back() < target) {
        return n_size; // 放到最后一个
    }
    int32_t left{0}, right{n_size - 1}, middle{0};
    while (left < right) {
        if (middle = (right - left) / 2 + left; nums[middle] > target) {// 避免溢出
            right = middle;
        } else if (nums[middle] < target) {
            left = middle + 1;// 只有一处+1
        } else {
            return middle;
        }
    }
    return left;
}

int32_t leetcode_35::searchInsert2(const vector<int32_t> &nums, int32_t target) {
    const auto diff = std::lower_bound(nums.begin(), nums.end(), target);
    return static_cast<int32_t>(distance(nums.begin(), diff));
}

}
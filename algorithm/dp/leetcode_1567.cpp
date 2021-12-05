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
#include "leetcode_1567_test.hpp"

namespace leetcode_1567 {

int32_t leetcode_1567::getMaxLen(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 0) {
        return 0;
    } else if (nums_size == 1) {
        return nums[0] > 0 ? 1 : 0;
    }
    vector<int32_t> dpPos(nums_size + 1, 0), dpNeg(nums_size + 1, 0);
    dpPos[0] = 0, dpNeg[0] = 0;// 以第0个结尾一定是0
    dpPos[1] = nums[0] > 0 ? 1 : 0; // 第一个结尾的话,正则1,否则0
    dpNeg[1] = nums[0] < 0 ? 1 : 0; // 第一个结尾的话,正则1,否则0
    for (size_t i{2}; i <= nums_size; i++) {
        if (nums[i - 1] == 0) {
            dpPos[i] = 0;
            dpNeg[i] = 0;
        } else if (nums[i - 1] > 0) {
            // 这个是正数,则取决于上一个结尾的最大正乘积长度
            dpPos[i] = dpPos[i - 1] + 1;
            // 这种情况下,上一个结尾的最大负乘积长度得先存在才能+1
            if (dpNeg[i - 1] > 0) {
                dpNeg[i] = dpNeg[i - 1] + 1;
            }
        } else if (nums[i - 1] < 0) {
            if (dpNeg[i - 1] > 0) {
                dpPos[i] = dpNeg[i - 1] + 1;
            }
            dpNeg[i] = dpPos[i - 1] + 1;
        }
    }
    return *std::max_element(dpPos.cbegin(), dpPos.cend());
}

}
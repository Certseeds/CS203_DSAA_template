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
#include "leetcode_45_test.hpp"

namespace leetcode_45 {

int32_t leetcode_45::jump(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 1) {
        return 0;
    }
    int32_t times{0};
    // 每次移动一个"范围"
    // 范围内从左到右依次更新右边界
    // 一旦右边界移动出界,则返回
    for (size_t start{0}, end{1}; end < nums_size; times++) {
        size_t max{end + 1};
        for (size_t begin{start}; begin < end; begin++) {
            max = std::max(max, begin + nums[begin] + 1);
        }
        start = end;
        end = max;
    }
    return times;
}

int32_t leetcode_45::jump2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 1) {
        return 0;
    }
    vector<int32_t> steps(nums_size, 0x3f3f3f3f);
    steps[0] = 0;
    for (size_t i{0}; i < nums_size; i++) {
        for (int32_t step{1}; step <= nums[i] && (i + step) < nums_size; step++) {
            steps[i + step] = std::min(steps[i + step], steps[i] + 1);
            if (i + step + 1 == nums_size) {
                return steps.back();
            }
        }
    }
    return steps.back();
}
}
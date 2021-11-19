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
#include "leetcode_56_test.hpp"

namespace leetcode_56 {

vector<vector<int32_t>> leetcode_56::merge(const vector<vector<int32_t>> &intervals) {
    vector<vector<int32_t>> nums{intervals};
    const size_t nums_size{nums.size()};
    if (nums_size <= 1) {
        return nums;
    }
    std::sort(std::begin(nums), std::end(nums), [](const auto &v1, const auto &v2) {
        return v1[0] < v2[0];
    });
    vector<vector<int32_t>> will_return;
    int32_t begin{nums[0][0]}, end{nums[0][1]};
    for (size_t order{1}; order < nums_size; order++) {
        if (end >= nums[order][0]) {
            end = std::max(end, nums[order][1]);
        } else {
            will_return.push_back({begin, end});
            begin = nums[order][0];
            end = nums[order][1];
        }
    }
    will_return.push_back({begin, end});
    return will_return;
}
}

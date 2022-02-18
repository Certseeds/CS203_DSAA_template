/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
#include "leetcode_so_21_test.hpp"

namespace leetcode_so_21 {

vector<int32_t> leetcode_so_21::exchange(const vector<int32_t> &nums_const) {
    if (nums_const.empty()) {
        return {};
    }
    vector<int32_t> nums{nums_const};
    static constexpr const auto judge = [](const auto num) -> bool { return num % 2 == 0; };
    // 实际上完全可以是左边模三余1,右边余0,2
    const auto nums_size{nums.size()};
    for (size_t left{0}, right{nums_size - 1}; left < right;) {
        for (; left < right && !judge(nums[left]); ++left) {}
        for (; left < right && judge(nums[right]); --right) {}
        if (left >= right) { return nums; }
        std::swap(nums[left], nums[right]);
    }
    return nums;
}
}

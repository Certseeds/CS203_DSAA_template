
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
#include "leetcode_724_test.hpp"

namespace leetcode_724 {
int32_t leetcode_724::pivotIndex(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    vector<int32_t> accu(nums_size + 2, 0);
    for (size_t i{1}; i <= nums_size; ++i) {
        accu[i] = nums[i - 1];
        accu[i] += accu[i - 1];
    }
    accu[nums_size + 1] = accu[nums_size];
    for (size_t i{1}; i <= nums_size; ++i) {
        if (accu[i - 1] + accu[i] == accu.back()) { // 可见此处可优化
            return static_cast<int32_t>(i) - 1;
        }
    }
    return -1;
}

}

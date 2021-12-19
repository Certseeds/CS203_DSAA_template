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
#include "leetcode_413_test.hpp"

namespace leetcode_413 {

int32_t leetcode_413::numberOfArithmeticSlices(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums.size() <= 2) {
        return 0;
    }
    static constexpr const auto func = [](int32_t x) {
        return (x - 1) * (x - 2) / 2;
    };// 完全不必要嗯算, 有连续段落的总长度即可
    int32_t sums{0}, lastDiff{nums[1] - nums[0]}, len{1};
    for (size_t i{2}; i < nums_size; i++) {
        const int32_t nowDiff{nums[i] - nums[i - 1]};
        if (nowDiff != lastDiff) {
            sums += func(len + 1);
            len = 1;
            lastDiff = nowDiff;
        } else {
            len++;
        }
    }
    sums += func(len + 1);
    return sums;
}

}
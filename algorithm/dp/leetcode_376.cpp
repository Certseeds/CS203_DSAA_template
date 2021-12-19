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
#include "leetcode_376_test.hpp"

namespace leetcode_376 {

int32_t leetcode_376::wiggleMaxLength(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size <= 1) {
        return static_cast<int32_t>(nums_size);
    }
    vector<int32_t> dpInc(nums_size, 1), dpDec(nums_size, 1);
    for (size_t i{1}; i < nums_size; i++) {
        for (size_t j{0}; j < i; j++) {
            if (nums[i] > nums[j]) {
                dpInc[i] = std::max(dpInc[i], dpDec[j] + 1);
            } else if (nums[i] < nums[j]) {
                dpDec[i] = std::max(dpDec[i], dpInc[j] + 1);
            }
        }
    }
    return std::max(
            *std::max_element(std::cbegin(dpInc), std::cend(dpInc)),
            *std::max_element(std::cbegin(dpDec), std::cend(dpDec))
    );
}


}
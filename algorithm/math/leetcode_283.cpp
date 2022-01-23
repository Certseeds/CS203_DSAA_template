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
#include "leetcode_283_test.hpp"

namespace leetcode_283 {

void leetcode_283::moveZeroes(vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    int64_t fill{0};
    for (size_t i{0}; i < nums_size; i++) {
        if (nums[i] != 0) {
            nums[fill] = nums[i];
            fill++;
        }
    }
    std::fill(nums.begin() + fill, nums.end(), 0);
}

void leetcode_283::moveZeroes2(vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    for (size_t left{0}, right{0}; right < nums_size; right++) {
        if (nums[right] != 0) {
            std::swap(nums[left], nums[right]);
            left++;
        }
    }
}

}
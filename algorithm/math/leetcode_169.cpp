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
#include "leetcode_169_test.hpp"

namespace leetcode_169 {

int32_t leetcode_169::majorityElement(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 1) {
        return nums[0];
    }
    unordered_map<int32_t, int32_t> umaps{};
    int32_t val{std::numeric_limits<int32_t>::min()}, count{0};
    for (const auto i: nums) {
        umaps[i]++;
        if (umaps[i] > count) {
            count = umaps[i];
            val = i;
        }
    }
    return val;
}

int32_t leetcode_169::majorityElement2(const vector<int32_t> &nums) {
    const auto nums_size{nums.size()};
    if (nums_size == 0) {
        return -1;
    } else if (nums_size == 1) {
        return nums.front();
    }
    int32_t val{std::numeric_limits<int32_t>::min()}, count{0};
    for (const auto i: nums) {
        if (count > 0) {
            if (val == i) {
                count++;
            } else {
                count--;
            }
        } else {
            count = 1;
            val = i;
        }
    }
    return val;
}
}
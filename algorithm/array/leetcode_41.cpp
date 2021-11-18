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
#include "leetcode_41_test.hpp"

namespace leetcode_41 {

int leetcode_41::firstMissingPositive(vector<int32_t> &nums) {
    const auto nums_size{static_cast<int32_t>(nums.size())};
    for (auto &value: nums) {
        if (value <= 0) {
            value = nums_size + 1;
        }
    }
    for (const auto &value: nums) {
        const auto absV{std::abs(value) - 1};
        if (0 <= absV && absV < nums_size) {
            nums[absV] = -1 * std::abs(nums[absV]);
        }
    }
    nums.push_back(nums_size + 1);
    for (int32_t i{0}; i < nums_size + 1; i++) {
        if (0 < nums[i]) {
            return (i + 1);
        }
    }
    return -1;
}

int leetcode_41::firstMissingPositive2(vector<int32_t> &nums) {
    const size_t maxv{nums.size()};
    vector<int32_t> num(nums.size() + 1, 0);
    for (size_t i{0}; i < nums.size(); i++) {
        if (0 < nums[i] && nums[i] <= static_cast<int32_t>(maxv)) {
            num[nums[i] - 1] = nums[i];
        }
    }
    for (size_t i{0}; i < num.size(); i++) {
        if (num[i] == 0) {
            return static_cast<int32_t>(i + 1);
        }
    }
    return -1;
}

}
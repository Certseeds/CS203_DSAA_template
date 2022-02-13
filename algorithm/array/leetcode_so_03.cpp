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
#include "leetcode_so_03_test.hpp"
#include <unordered_map>

namespace leetcode_so_03 {
using std::unordered_map;

int32_t leetcode_so_03::findRepeatNumber(const vector<int32_t> &nums_) {
    vector<int32_t> nums{nums_};
    std::sort(nums.begin(), nums.end());
    for (size_t i{0}, size{nums.size()}; i + 1 < size; ++i) {
        if (nums[i] == nums[i + 1]) {
            return nums[i];
        }
    }
    return 0;
}

int32_t leetcode_so_03::findRepeatNumber2(const vector<int32_t> &nums) {
    unordered_map<int32_t, size_t> umap;
    for (size_t i{0}, size{nums.size()}; i < size; ++i) {
        ++umap[nums[i]];
        if (umap[nums[i]] == 2) {
            return nums[i];
        }
    }
    return -1;
}

int32_t leetcode_so_03::findRepeatNumber3(const vector<int32_t> &nums_) {
    vector<int32_t> nums{nums_};
    for (size_t i{0}, size{nums.size()}; i < size; ++i) {
        const auto num = [](const auto i) {
            return i >= 0 ? i : -i - 1;
        }(nums[i]);
        if (nums[num] < 0) {
            return num;
        }
        nums[num] = -nums[num] - 1;
    }
    return -1;
}

}

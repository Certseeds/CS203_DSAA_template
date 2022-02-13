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
#include "leetcode_so_53ii_test.hpp"

namespace leetcode_so_53ii {

int32_t leetcode_so_53ii::missingNumber(const vector<int32_t> &nums) {
    if (nums.empty()) {
        return 0;
    }
    const int32_t size{static_cast<int32_t>(nums.size())};
    if (nums.back() + 1 == size) {
        return size;
    }
    for (int32_t fst{0}, last{size - 1}; fst < last;) {
        if (const int32_t mid{fst + (last - fst) / 2}; nums[mid] == mid) {
            fst = mid + 1;
            if (nums[mid + 1] - nums[mid] == 2) {
                return mid + 1;
            }
        } else {
            last = mid;
        }
    }
    return 0;
}
}

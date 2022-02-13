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
#include "leetcode_697_test.hpp"
#include <unordered_map>

namespace leetcode_697 {
using std::unordered_map;

int32_t leetcode_697::findShortestSubArray(const vector<int32_t> &nums) {
    if (nums.empty()) {
        return 0;
    }
    unordered_map<int, int> times, begin;
    int32_t max{0},will_return{0};
    const auto nums_size{static_cast<int32_t>(nums.size())};
    for (int32_t i{0}; i < nums_size; i++) {
        const auto num{nums[i]};
        ++times[num];
        if (times[num] == 1) {
            begin[num] = i;
        } else {
            if (times[num] > max) {
                max = times[num];
                will_return = i - begin[num];
            } else if (times[num] == max) {
                will_return = std::min(will_return, i - begin[num]);
            }
        }
    }
    return will_return + 1;
}
}

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
#include "leetcode_665_test.hpp"

namespace leetcode_665 {

bool leetcode_665::checkPossibility(const vector<int32_t> &nums) {
    int count{0};
    size_t position{0};
    for (size_t i{0}; i < nums.size() - 1; i++) {
        if (nums[i] - nums[i + 1] > 0) {
            count++;
            position = i;
        }
    }
    if (count > 1) {
        return false;
    }
    if (position == 0 || position == nums.size() - 1) {
        return true;
    }
    bool first{true}, second{true};
    if (nums[position - 1] > nums[position + 1]) {
        first = false;
    }
    for (size_t i = position + 1; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            first = false;
        }
    }
    if (position < nums.size() - 2) {
        if (nums[position] > nums[position + 2]) {
            return first;
        }
        for (size_t i = position + 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return first;
            }
        }
    }
    return first || second;
}
}

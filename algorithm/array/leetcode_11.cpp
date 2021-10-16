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
#include "leetcode_11_test.hpp"

namespace leetcode_11 {

int leetcode_11::maxArea(const vector<int32_t> &height) {
    int32_t left{0},
            right = static_cast<int32_t>(height.size() - 1);
    const auto water = [& height](const auto lhs, const auto rhs) {
        return (rhs - lhs) * std::min(height[lhs], height[rhs]);
    };
    int32_t will_return = water(left, right);
    while (left < right) {
        if (height[left] >= height[right]) {
            right--;
        } else {
            left++;
        }
        will_return = std::max(will_return, water(left, right));
    }
    return will_return;
}

}
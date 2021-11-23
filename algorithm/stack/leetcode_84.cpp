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
#include "leetcode_84_test.hpp"

namespace leetcode_84 {

int32_t leetcode_84::largestRectangleArea(const vector<int32_t> &heights) {
    const auto height_size{static_cast<int32_t>(heights.size())};
    // 我们要找到 左侧最近的 小于当前高度的 坐标
    // 极限模型: 一个从左到右单调增的序列,全部都是 i-1
    // 因此使用递增栈
    stack<int32_t> staL;
    vector<int32_t> left(height_size);
    for (int32_t i{0}; i < height_size; i++) {
        while (!staL.empty() && heights[i] <= heights[staL.top()]) {
            staL.pop();
        }
        left[i] = staL.empty() ? -1 : staL.top();
        staL.push(i);
    }
    stack<int32_t> staR;
    vector<int32_t> right(height_size);
    for (int32_t i{height_size - 1}; i >= 0; i--) {
        while (!staR.empty() && heights[i] <= heights[staR.top()]) {
            staR.pop();
        }
        right[i] = staR.empty() ? height_size : staR.top();
        staR.push(i);
    }
    int32_t will_return{-1};
    for (int32_t i{0}; i < height_size; i++) {
        will_return = std::max(will_return, (right[i] - left[i] - 1) * heights[i]);
    }
    return will_return;
}
}
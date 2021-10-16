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
#include "leetcode_42_test.hpp"

namespace leetcode_42 {
int leetcode_42::trap(const vector<int> &height) {
    int32_t will_return{0};
    stack<size_t> sta;
    const auto height_size{height.size()};
    for (size_t i{0}; i < height_size; i++) {
        // 取得其左侧, 小于等于当前高度 的坐标
        // 单调栈,形象地说,水位是 一层一层 向上加的
        while (!sta.empty() && height[i] > height[sta.top()]) {
            const auto top{sta.top()};
            sta.pop();
            if (sta.empty()) {
                break;
            }
            const auto left{sta.top()};
            const auto width{i - left - 1};
            const auto h{std::min(height.at(left), height.at(i)) - height.at(top)};
            will_return += static_cast<int32_t>(h * width);
        }
        sta.push(i);
    }
    return will_return;
}
}
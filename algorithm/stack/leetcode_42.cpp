// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_42_test.hpp"
#include <stack>

namespace leetcode_42 {
using std::stack;

int32_t leetcode_42::trap(const vector<int32_t> &height) {
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

int32_t leetcode_42::trapDPLoca(const vector<int32_t> &height) {

    // 水位为其 min(左侧最高值,水位最高值) - 本身的值
    const auto height_size{height.size()};
    vector<size_t> left(height_size + 1, 0), right(height_size + 1, 0);
    // 对左侧来说,其左侧为无限低, so do 右侧
    left[0] = 0;
    right[height_size] = height_size - 1;
    for (size_t i{1}; i < height_size; i++) {
        if (height[i] <= height[left[i - 1]]) {
            left[i] = left[i - 1];
        } else {
            left[i] = i;
        }
    }
    for (size_t i{height_size - 1}; i > 0; i--) {
        if (height[i] <= height[right[i + 1]]) {
            right[i] = right[i + 1];
        } else {
            right[i] = i;
        }
    }
    int32_t will_return{0};
    for (size_t i{0}; i < height_size; i++) {
        will_return += std::max(0, std::min(height[left[i]], height[right[i + 1]]) - height[i]);
    }
    return will_return;
}

int32_t leetcode_42::trapDPHeight(const vector<int32_t> &height) {
    // 水位为其 min(左侧最高值,水位最高值) - 本身的值
    const auto height_size{height.size()};
    vector<int32_t> left(height_size + 1, 0), right(height_size + 1, 0);
    // 对左侧来说,其左侧为无限低, so do 右侧
    left[0] = height[0];
    right[height_size] = height[height_size - 1];
    for (size_t i{1}; i < height_size; i++) {
        if (height[i] <= left[i - 1]) {
            left[i] = left[i - 1];
        } else {
            left[i] = height[i];
        }
    }
    for (size_t i{height_size - 1}; i > 0; i--) {
        if (height[i] <= right[i + 1]) {
            right[i] = right[i + 1];
        } else {
            right[i] = height[i];
        }
    }
    int32_t will_return{0};
    for (size_t i{0}; i < height_size; i++) {
        will_return += std::max(0, std::min(left[i], right[i + 1]) - height[i]);
    }
    return will_return;
}
}
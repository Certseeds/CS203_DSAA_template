// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

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

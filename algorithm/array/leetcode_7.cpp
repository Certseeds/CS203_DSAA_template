// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_7_test.hpp"
#include <array>
#include <vector>
#include <limits>

namespace leetcode_7 {
using std::vector;
using std::array;

int leetcode_7::reverse(int32_t x) {
    if (x == std::numeric_limits<int32_t>::min()) {
        return 0;
    } else if (x < 0) {
        return -reverse3(-x);
    }
    std::array<uint8_t, 10> nums{0};
    int32_t count{0};
    while (x > 0) {
        nums[count] = x % 10;
        x /= 10;
        count++;
    }
    int32_t i{0};
    while (i < count && nums[i] == 0) {
        i++;
    }
    int32_t will_return = 0;
    for (; i < count; i++) {
        if (will_return > (std::numeric_limits<int32_t>::max() - nums[i]) / 10) {
            return 0;
        }
        will_return = will_return * 10 + nums[i];
    }
    return static_cast<int32_t>(will_return);
    // 不用64bit版
}


int leetcode_7::reverse2(int x) {
    if (x == std::numeric_limits<int32_t>::min()) {
        return 0;
    } else if (x < 0) {
        return -1 * reverse3(-x);
    }
    vector<int> nums;
    while (x > 0) {
        nums.push_back(x % 10);
        x /= 10;
    }
    int32_t i{0};
    while (i < static_cast<int>(nums.size()) && nums[i] == 0) {
        i++;
    }
    long will_return = 0;
    for (; i < static_cast<int>(nums.size()); i++) {
        will_return = will_return * 10 + nums[i];
        if (will_return > std::numeric_limits<int32_t>::max()) {
            return 0;
        }
    }
    return static_cast<int32_t>(will_return);
}


int leetcode_7::reverse3(int x) {
    if (x == std::numeric_limits<int32_t>::min()) {
        return 0;
    } else if (x < 0) {
        return -reverse3(-x);
    }
    vector<uint8_t> vec;
    vec.reserve(32);
    while (x > 0) {
        vec.push_back(x % 10);
        x /= 10;
    }
    int32_t will_return = 0;
    for (const auto &i: vec) {
        if (will_return > std::numeric_limits<int32_t>::max() / 10) {
            return 0;
        }
        will_return = 10 * will_return + i;
    }
    return will_return;
}
}
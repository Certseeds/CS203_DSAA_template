// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023  nanoseeds

*/
#include "leetcode_1371_test.hpp"

namespace leetcode_1371 {
// 把寻找最长字串的问题, 转化成在[0,i)之间寻找一个点, [0,point), [0,i)上, 元音字母的odd/even相同
// 经典的把O(N^2)的组合问题 拆分成O(N)的(0,N)之后两者作差
int32_t leetcode_1371::findTheLongestSubstring(const string &s) {
    constexpr const auto chnums{26};
    constexpr const std::array<int32_t, chnums> nums{
            0b1, 0, 0, 0, 0b10,
            0, 0, 0, 0b100, 0,
            0, 0, 0, 0, 0b1000,
            0, 0, 0, 0, 0,
            0b10000, 0, 0, 0, 0,
            0
    };
    constexpr const auto specials{5};
    std::array<int32_t, (1 << specials)> map{-1,}; // key, even-odd值
    for (size_t i{1}; i < (1 << specials); ++i) {
        map[i] = 0x3f3f3f3f;
    }
    // value latest prefix
    int32_t distance{0};
    for (int32_t i{0}, count_num{0}; i < static_cast<int32_t>(s.size()); ++i) {
        const auto ch{s[i]};
        count_num ^= (nums[ch - 'a']);
        map[count_num] = std::min(map[count_num], i); // 把值赋给最早的
        if (map[count_num] != 0x3f3f3f3f) {
            distance = std::max(distance, i - map[count_num]);
        }
    }
    return distance;
}

}

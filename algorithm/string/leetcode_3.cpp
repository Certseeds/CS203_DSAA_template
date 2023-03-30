// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_3_test.hpp"
#include <array>
#include <bitset>
/*
Given a string,
find the length of the longest substring without repeating characters.
greedy to get the max-length,if meet a repeat character,then throw the last one.
*/

namespace leetcode_3 {
using std::array;
using std::bitset;

int32_t leetcode_3::lengthOfLongestSubstring(const string &s) {
    const auto s_size{s.size()};
    size_t fst{0};
    int32_t maxLength{0};
    std::bitset<256> uarray{false};
    // std::array<int8_t,256> uarray{false};
    for (size_t i{0}; i < s_size; i++) {
        if (!uarray[s[i]]) {
            uarray[s[i]] = true;
            maxLength = std::max(static_cast<int32_t>(1 + i - fst), maxLength);
        } else {
            for (size_t j{static_cast<size_t>(fst)}; j < i; j++) {
                fst++;
                if (s[j] == s[i]) {
                    break;
                }
                uarray[s[j]] = false;
            }
        }
    }
    return maxLength;
}

int32_t leetcode_3::lengthOfLongestSubstring2(const string &s) {
    int32_t maxv{std::numeric_limits<int16_t>::min()}, len{0}, begin{0};
    const auto s_size = static_cast<int32_t>(s.size());
    std::array<uint8_t, 128> umap{0};
    for (int32_t i{0}; i < s_size; i++) {
        len++;
        if (umap[s[i]] != 0 && umap[s[i]] > begin) {
            len += (begin - umap[s[i]]);
            begin = umap[s[i]];
        }
        maxv = std::max(len, maxv);
        umap[s[i]] = i + 1;
    }
    return std::max(len, maxv);
}

int32_t leetcode_3::lengthOfLongestSubstring3(const string &s) {
    const auto s_size = static_cast<int32_t>(s.size());
    if (s_size <= 1) {
        return s_size;
    }
    std::array<uint8_t, 256> uarray = {false};
    int32_t left{0}, right{1}, diff{0};
    uarray[s[left]] = 1;
    while (right < s_size) {
        if (!uarray[s[right]]) {
            uarray[s[right]] = true;
            right++;
        } else {
            uarray[s[left]] = false;
            left++;
        }
        diff = std::max(diff, right - left);
    }
    return diff;
}
}

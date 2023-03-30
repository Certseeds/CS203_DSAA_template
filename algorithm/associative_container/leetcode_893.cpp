// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_893_test.hpp"
#include <array>
#include <unordered_set>

namespace leetcode_893 {
using std::array;
using std::unordered_set;

struct hasher {
    size_t operator()(const std::array<int32_t, 52> &p) const {
        size_t i{0};
        for (auto t: p) {
            i = 31 * i + std::hash<int32_t>()(t);
        }
        return i;
    }
};

int32_t leetcode_893::numSpecialEquivGroups(const vector<string> &words) {
    const auto words_size{words.size()};
    if (words_size == 0) {
        return 0;
    }
    unordered_set<array<int32_t, 52>, hasher> will_return{};
    const auto word_size{words.front().size()};
    for (size_t i{0}; i < words_size; ++i) {
        array<int32_t, 52> charElement{0};
        const auto &word = words[i];
        for (size_t j{0}; j < word_size; ++j) {
            charElement[((j % 2) ? 0 : 26) + word[j] - 'a']++;
        }
        will_return.insert(charElement);
    }
    return static_cast<int32_t>(will_return.size());
}
}

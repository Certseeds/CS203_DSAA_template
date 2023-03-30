// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_383_test.hpp"
#include <array>

namespace leetcode_383 {
using std::array;

bool leetcode_383::canConstruct(const string &ransomNote, const string &magazine) {
    if (ransomNote.size() > magazine.size()) {
        return false;
    }
    std::array<int64_t, std::numeric_limits<char>::max() + 1> base{0};
    for (const auto ch: magazine) {
        ++base[ch];
    }
    for (const auto ch: ransomNote) {
        --base[ch];
        if (base[ch] < 0) {
            return false;
        }
    }
    return true;
}
}

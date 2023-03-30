// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1160_test.hpp"
#include <array>

namespace leetcode_1160 {
using std::array;

int32_t leetcode_1160::countCharacters(const vector<string> &words, std::string_view chars) {
    array<int32_t, 26> sizes{0};
    for (const auto ch: chars) {
        sizes[ch - 'a'] += 1;
    }
    int32_t will_return{0};
    for (const auto &word: words) {
        array<int32_t, 26> useable{sizes};
        will_return += word.size();
        for (const auto wor: word) {
            if (useable[wor - 'a'] == 0) {
                will_return -= word.size();
                break;
            }
            useable[wor - 'a'] -= 1;
        }
    }
    return will_return;
}

}

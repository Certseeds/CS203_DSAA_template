// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_17_test.hpp"

namespace leetcode_17 {
vector<string> leetcode_17::letterCombinations(const string &digits) {
    if (digits.empty()) {
        return {};
    }
    const vector<vector<char>> chars{
            {},
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
    };
    vector<string> will_return = {""};
    for (const char &digit: digits) {
        vector<string> temp;
        for (const string &temp_str: will_return) {
            for (const char &k: chars[digit - '1']) {
                temp.emplace_back(temp_str + k);
            }
        }
        will_return = temp;
    }
    return will_return;
}
}

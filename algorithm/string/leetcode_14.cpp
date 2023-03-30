// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_14_test.hpp"

namespace leetcode_14 {
string leetcode_14::longestCommonPrefix(const vector<string> &strs) {
    if (strs.empty()) {
        return "";
    }
    auto length = std::min_element(std::begin(strs), std::end(strs),
                                   [](const string &s1, const string &s2) {
                                       return s1.size() < s2.size();
                                   })->size();
    string will_return = "";
    will_return.reserve(10000);
    for (size_t i = 0; i < length; i++) {
        char judge = strs[0][i];
        for (const auto &item: strs) {
            if (item[i] != judge) {
                return will_return;
            }
        }
        will_return += judge;
    }
    return will_return;
}

}

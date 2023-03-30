// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_so_58_test.hpp"

namespace leetcode_so_58 {

string leetcode_so_58::reverseLeftWords(const string &s, int32_t n) {
    const auto s_size{s.size()};
    const auto mid{s_size - n};
    string will_reutrn(s_size, ' ');
    for (size_t i = n; i < s_size; ++i) {
        will_reutrn[i - n] = s[i];
    }
    for (int32_t i{0}; i < n; ++i) {
        will_reutrn[mid + i] = s[i];
    }
    return will_reutrn;
}

string leetcode_so_58::reverseWords(const string &s) {
    const auto s_size{s.size()};
    vector<string> strs;
    string str{};
    str.reserve(s_size);
    for (size_t left{0}; left < s_size; ++left, str.clear()) {
        for (; left < s_size && s[left] == ' '; ++left) {}
        for (; left < s_size && s[left] != ' '; ++left) { str += s[left]; }
        if (!str.empty()) {
            strs.push_back(str);
        }
    }
    if (strs.empty()) {
        return {};
    }
    string will_return{};
    will_return = strs.back();
    for (auto iter = strs.rbegin() + 1; iter != strs.rend(); ++iter) {
        //will_return =  will_return + *iter;
        will_return += ' ' + *iter;
    }
    return will_return;
}
}

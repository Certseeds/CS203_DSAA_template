// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_929_test.hpp"
#include <unordered_set>

namespace leetcode_929 {
using std::unordered_set;

string transfer(const string &str) {
    string re{};
    const auto str_size{str.size()};
    re.resize(str_size);
    for (size_t i{0}, count{0}; i < str_size; ++i) {
        switch (str[i]) {
            case '.': {
                continue;
            }
            case '+': {
                for (; i < str_size && str[i] != '@'; ++i) {}
                --i;
                break;
            }
            case '@': {
                for (; i < str_size; ++i, ++count) { re[count] = str[i]; }
                re.resize(count);
                return re;
            }
            default: {
                re[count] = str[i];
                ++count;
            }
        }
    }
    return "";
}

int32_t leetcode_929::numUniqueEmails(const vector<string> &emails) {
    unordered_set<string> uset;
    for (const auto &email: emails) {
        uset.insert(transfer(email));
    }
    return uset.size();
}

}

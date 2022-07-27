// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag stack
//@Tag 栈
//@Tag 输入保证合法
#include "leetcode_1047_test.hpp"
#include <stack>

namespace leetcode_1047 {
using std::stack;

string leetcode_1047::removeDuplicates(const string &s) {
    stack<char> sta;
    for (const auto ch: s) {
        if (sta.empty()) {
            sta.push(ch);
        } else {
            const auto top{sta.top()};
            if (top == ch) {
                sta.pop();
            } else {
                sta.push(ch);
            }
        }
    }
    std::vector<char> cache(sta.size());
    for (auto iter = cache.begin(); iter != cache.end(); ++iter, sta.pop()) {
        (*iter) = sta.top();
    }
    return std::string(cache.crbegin(), cache.crend());
}

}
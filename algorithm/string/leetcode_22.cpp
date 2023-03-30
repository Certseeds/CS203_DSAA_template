// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_22_test.hpp"
#include <unordered_set>

namespace leetcode_22 {
using std::unordered_set;

vector<string> leetcode_22::generateParenthesis(int n) {
    if (n == 1) {
        return vector<string>{"()"};
    }
    vector<string> will_return{generateParenthesis(n - 1)};
    unordered_set<string> uset{};
    for (const auto &i: will_return) {
        for (int32_t j{0}; j < n; j++) {
            uset.insert(string(i).insert(j, "()"));
        }
    }
    will_return.clear();
    will_return.reserve(uset.size());
    will_return.insert(will_return.end(), uset.begin(), uset.end());
    return will_return;
}
}

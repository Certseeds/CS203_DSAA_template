// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_20_test.hpp"
#include <array>
#include <stack>

namespace leetcode_20 {
using std::array;
using std::stack;

bool leetcode_20::isValid(const string &s) {
    std::stack<uint8_t> stk{{'?'}};
    std::array<uint8_t, 256> umap{};
    umap['('] = ')';
    umap['['] = ']';
    umap['{'] = '}';
    for (const auto i: s) {
        if (umap[stk.top()] == i) {
            stk.pop();
        } else {
            stk.push(i);
        }
    }
    stk.pop();
    return stk.empty();
}

}

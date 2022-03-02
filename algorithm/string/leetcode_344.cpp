// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_344_test.hpp"

namespace leetcode_344 {

void leetcode_344::reverseString(vector<char> &s) {
    for (size_t left{0}, right{s.size() - 1}; left < right; left++, right--) {
        std::swap(s[left], s[right]);
    }
}
}
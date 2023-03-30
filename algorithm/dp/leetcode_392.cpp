// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanos

*/
#include "leetcode_392_test.hpp"

namespace leetcode_392 {

bool leetcode_392::isSubsequence(const string &s, const string &t) {
    const auto tSize{t.size()}, sSize{s.size()};
    if (tSize < sSize) {
        return false;
    }
    size_t sNum{0};
    for (size_t i{0}; i < tSize && sNum != sSize; i++) {
        if (t[i] == s[sNum]) {
            sNum++;
        }
    }
    return sNum == sSize;
}
}

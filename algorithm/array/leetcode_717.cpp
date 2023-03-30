// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_717_test.hpp"

namespace leetcode_717 {

bool leetcode_717::isOneBitCharacter(const vector<int32_t> &bits) {
    const size_t size{bits.size()};
    if (size < 2 || bits[size - 2] == 0) {
        return true;
    }
    // sizes == 2 is the same with sizes >2
    // it means, test the string before the last one is over or not
    size_t i{0};
    for (; i + 1 < size; ++i) {
        i += bits[i];
    }
    return i + 1 == size;
}
}

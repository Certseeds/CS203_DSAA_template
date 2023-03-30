// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_461_test.hpp"

namespace leetcode_461 {

int32_t leetcode_461::hammingDistance(int32_t x, int32_t y) {
    int32_t count{0};
    for (int32_t temp{x ^ y}; temp != 0; temp = temp >> 1) {
        count += (temp & 1);
    }
    return count;
}

}

// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#include "leetcode_1025_test.hpp"

namespace leetcode_1025 {

bool leetcode_1025::divisorGame(int32_t n) {
    vector<uint8_t> status(n + 3, false);
    status[1] = false;
    status[2] = true;
    for (size_t i{3}; i < n + 3; ++i) {
        for (size_t j{1}; j < i; ++j) {
            if (i % j == 0 && status[i - j] == false) {
                status[i] = true;
                break;
            }
        }
    }
    return status[n];
}

bool leetcode_1025::divisorGame2(int32_t n) {
    return !(n & 1);
}

}
// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1010_test.hpp"
#include <array>

namespace leetcode_1010 {
using std::array;

int32_t leetcode_1010::numPairsDivisibleBy60(const vector<int32_t> &time) {
    array<int32_t, 60> uses{0};
    int32_t willreturn{0};
    for (const int32_t i: time) {
        uses[i % 60]++;
        willreturn += uses[(60 - i % 60) % 60];
    }
    return willreturn - uses[30] - uses[0];
}

}

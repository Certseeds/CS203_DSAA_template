// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_485_test.hpp"

namespace leetcode_485 {

int32_t leetcode_485::findMaxConsecutiveOnes(const vector<int32_t> &nums) {
    int32_t val{0}, willreturn{-1};
    for (const auto i: nums) {
        if (i != 0) {
            val++;
        } else {
            willreturn = std::max(val, willreturn);
            val = 0;
        }
    }
    return std::max(val, willreturn);;
}

}

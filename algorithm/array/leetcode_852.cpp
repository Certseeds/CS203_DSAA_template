// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_852_test.hpp"

namespace leetcode_852 {

int32_t leetcode_852::peakIndexInMountainArray(const vector<int32_t> &A) {
    int x1{0}, x4 = static_cast<int32_t>(A.size() - 1);
    for (int x2{x1 + (x4 - x1) / 3}, x3{x1 + (x4 - x1) * 2 / 3}; x1 < x4;) {
        int temp1 = A[x2], temp2 = A[x3];
        if (temp1 > temp2) {
            x4 = x3;
        } else {
            x1 = x2 + 1;
        }
        x2 = x1 + (x4 - x1) / 3;
        x3 = x1 + (x4 - x1) * 2 / 3;
    }
    return x1 - 1;
}
}

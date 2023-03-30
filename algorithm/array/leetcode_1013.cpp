// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
#include "leetcode_1013_test.hpp"
#include <numeric>

namespace leetcode_1013 {

bool leetcode_1013::canThreePartsEqualSum(const vector<int32_t> &arr) {
    const int32_t sums = std::accumulate(arr.begin(), arr.end(), 0);
    if (sums % 3 != 0) {
        return false;
    }
    const int32_t divide = sums / 3;
    for (int x{1}, y = arr.size() - 2, sum_x{arr.front()}, sum_y{arr.back()}; x < y;) {
        if (sum_x != divide) {
            sum_x += arr[x];
            x++;
        }
        if (sum_y != divide) {
            sum_y += arr[y];
            y--;
        }
        if (sum_x == divide && sum_y == divide && x <= y) {
            return true;
        }
    }
    return false;
}
}

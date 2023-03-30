// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
#include "leetcode_1217_test.hpp"

namespace leetcode_1217 {

int32_t leetcode_1217::minCostToMoveChips(const vector<int32_t> &position) {
    if (position.empty() || position.size() == 1) {
        return 0;
    }
    int32_t odd{0}, even{0};
    for (const auto num: position) {
        if (num % 2 == 0) {
            odd++;
        } else {
            even++;
        }
    }
    return std::min(even, odd);
}

}

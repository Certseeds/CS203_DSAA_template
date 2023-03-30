// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_728_test.hpp"

namespace leetcode_728 {
vector<int32_t> leetcode_728::selfDividingNumbers(int32_t left, int32_t right) {
    vector<int32_t> will_return{};
    for (; left <= right; ++left) {
        int32_t now{left};
        while (now > 0) {
            const auto ten = now % 10;
            now /= 10;
            if (ten == 0 || left % ten != 0) {
                now = -1;
                break;
            }
        }
        if (now == 0) {
            will_return.push_back(left);
        }
    }
    return will_return;
}


}

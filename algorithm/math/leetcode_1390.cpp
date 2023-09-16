

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_1390_test.hpp"
#include <cmath>

namespace leetcode_1390 {

int32_t leetcode_1390::sumFourDivisors(const vector<int32_t> &nums) {
    int32_t will_return{0};
    for (const auto &num: nums) {
        int32_t count{0}, sum{0};
        for (int32_t i{1}; i <= std::sqrt(num) && count <= 4; ++i) {
            if (num % i == 0) {
                count += 1;
                sum += i;
                if (i * i != num) {
                    count += 1;
                    sum += num / i;
                }
            }
        }
        if (count == 4) {
            will_return += sum;
        }
    }
    return will_return;
}

}

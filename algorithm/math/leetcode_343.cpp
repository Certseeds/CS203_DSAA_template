// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#include "leetcode_343_test.hpp"

namespace leetcode_343 {

template<typename T>
T leetcode_343::integerBreak(T n) {
    if (n <= 3) {
        return n - 1;
    }
    vector<T> dp{0, 1, 2, 3};
    dp.resize(n + 4);
    for (T i{4}; i <= n; i++) {
        dp[i] = std::max(2 * dp[i - 2], 3 * dp[i - 3]);
        // 根源在于要用接近e(2.71828)的那一个
        // 理论上拆分成e的和之后乘积最大化
    }
    return dp[n];
}

}

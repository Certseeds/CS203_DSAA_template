// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanos

*/
#include "leetcode_279_test.hpp"
#include <numeric>

namespace leetcode_279 {

vector<int32_t> getSquList(int32_t x) {
    vector<int32_t> will_return{};
    for (int32_t i{1}; i * i <= x; i++) {
        will_return.push_back(i * i);
    }
    return will_return;
}

static constexpr const auto maxNum{10000};

int32_t leetcode_279::numSquares(int32_t n) {
    const auto squList{getSquList(maxNum)};
    const auto squ_list_size{squList.size()};
    vector<int32_t> dp(n + 1);
    std::iota(std::begin(dp), std::end(dp), 0); // 只有1组成
    for (size_t j{0}; j < squ_list_size && squList[j] <= n; j++) {
        dp[squList[j]] = 1; // 本身就是平方数
    }
    for (int32_t i{1}; i <= n; i++) {
        for (size_t j{0}; j < squ_list_size && squList[j] <= i; j++) {
            dp[i] = std::min(dp[i], dp[i - squList[j]] + 1); // 寻找子问题
        }
    }
    return dp.back();
}

}

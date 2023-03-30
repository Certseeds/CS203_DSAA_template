// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
#include "leetcode_121_test.hpp"

namespace leetcode_121 {

int32_t leetcode_121::maxProfit(const vector<int32_t> &prices) {
    const auto p_size{prices.size()};
    if (p_size <= 1) {
        return 0;
    }
    vector<int32_t> dp(p_size + 1, 0);
    // dp[i] 当天之前的最低价格
    dp[0] = 0; // in the 0th day, nothing happen
    dp[1] = prices[0]; // buy and sell, do not earn
    int32_t will_return{0};
    for (size_t i{2}; i <= p_size; i++) {
        will_return = std::max(prices[i - 1] - dp[i - 1], will_return);
        dp[i] = std::min(dp[i - 1], prices[i - 1]);
    }
    return will_return;
}

int32_t leetcode_121::maxProfit2(const vector<int32_t> &prices) {
    const auto p_size{prices.size()};
    if (p_size <= 1) {
        return 0;
    }
    // dpLast 包括前一天的最低价格
    int32_t dpLast{prices[0]}, will_return{0};
    for (size_t i{2}; i <= p_size; i++) {
        will_return = std::max(prices[i - 1] - dpLast, will_return);
        dpLast = std::min(dpLast, prices[i - 1]);
    }
    return will_return;
}
}

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#include "leetcode_32_test.hpp"
#include <stack>
#include <vector>

namespace leetcode_32 {
using std::stack;
using std::vector;

int32_t leetcode_32::longestValidParentheses(const string &s) {
    const auto s_size{s.size()};
    if (s_size <= 1) {
        return 0;
    }
    vector<int32_t> DP(s_size, 0);
    for (std::remove_const<decltype(s_size)>::type i{1}; i < s_size; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                DP[i] = 2;
                if (i >= 2) {
                    DP[i] += DP[i - 2];
                }
            } else if (i - DP[i - 1] > 0 && s[i - DP[i - 1] - 1] == '(') {
                DP[i] = DP[i - 1] + 2;
                if (static_cast<int32_t>(i) >= DP[i - 1] + 2) {
                    DP[i] += DP[i - DP[i - 1] - 2];
                }
            }
        }
    }
    // dp[0] is always 0
    return *std::max_element(DP.cbegin() + 1, DP.cend());
}

}

// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag DP
//@Tag 动态规划
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_10_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_10_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace lcs_10 {
using std::string;

struct leetcode_10 {
    static bool isMatch(const string &s, const string &p);
};

TEST_CASE("test case 1", "[test_10]") {
    CHECK_FALSE(leetcode_10::isMatch("aa", "a"));
    CHECK(leetcode_10::isMatch("aa", "a*"));
    CHECK(leetcode_10::isMatch("ab", ".*"));
    CHECK(leetcode_10::isMatch("aab", "c*a*b"));
    CHECK_FALSE(leetcode_10::isMatch("mississippi", "mis*is*p*."));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_10_TEST_CPP

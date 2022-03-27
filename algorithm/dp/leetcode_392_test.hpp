// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanos

*/
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day19

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_392 {
using std::vector;

struct leetcode_392 final {
    static bool isSubsequence(const string &s, const string &t);
};

TEST_CASE("1 [test_392]", "[test_392]") {
    static constexpr const char *const s{"abc"}, *const t{"ahbgdc"};
    CHECK(leetcode_392::isSubsequence(s, t));
}

TEST_CASE("2 [test_392]", "[test_392]") {
    static constexpr const char *const s{"axc"}, *const t{"ahbgdc"};
    CHECK_FALSE(leetcode_392::isSubsequence(s, t));
}

TEST_CASE("3 [test_392]", "[test_392]") {
    static constexpr const char *const s{"114514"}, *const t{"1919810"};
    CHECK_FALSE(leetcode_392::isSubsequence(s, t));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP

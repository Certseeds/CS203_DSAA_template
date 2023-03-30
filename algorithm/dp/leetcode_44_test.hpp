// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_44 {
using std::string;

struct leetcode_44 {
    static bool isMatch(const string &s, const string &p);
};


TEST_CASE("double empty [test_44]", "[test_44]") {
    CHECK(leetcode_44::isMatch("", "*"));
}

TEST_CASE("test 1 [test_44]", "[test_44]") {
    CHECK_FALSE(leetcode_44::isMatch("aa", "a"));
}


TEST_CASE("test 2 [test_44]", "[test_44]") {
    CHECK(leetcode_44::isMatch("aa", "*"));
}

TEST_CASE("? [test_44]", "[test_44]") {
    CHECK_FALSE(leetcode_44::isMatch("cb", "*a"));
}


TEST_CASE("* can match '' or any string [test_44]", "[test_44]") {
    CHECK(leetcode_44::isMatch("adceb", "a*b"));
}

TEST_CASE("both * and ? [test_44]", "[test_44]") {
    CHECK_FALSE(leetcode_44::isMatch("acdcb", "a*c?b"));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP

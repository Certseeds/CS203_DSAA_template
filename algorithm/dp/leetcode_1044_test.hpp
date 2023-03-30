// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag DP
//@Tag 动态规划
//@Description 最长公共字串

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1044_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1044_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_1044 {
using std::string;

namespace leetcode_1044 {
string longestDupSubstring(const string &s);
}

TEST_CASE("3 [test_1044]", "[test_1044]") {
    constexpr const char *const input{"banana"};
    constexpr const char *const output{"ana"};
    const string result{leetcode_1044::longestDupSubstring(input)};
    CHECK(result == output);
}

TEST_CASE("2 [test_1044]", "[test_1044]") {
    constexpr const char *const input{"abcd"};
    constexpr const char *const output{""};
    const string result{leetcode_1044::longestDupSubstring(input)};
    CHECK(result == output);
}

TEST_CASE("1 [test_1044]", "[test_1044]") {
    constexpr const char *const input{"efg"};
    constexpr const char *const output{""};
    const string result{leetcode_1044::longestDupSubstring(input)};
    CHECK(result == output);
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1044_TEST_CPP

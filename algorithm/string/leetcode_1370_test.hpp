// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1370_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1370_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_1370 {
using std::string;

namespace leetcode_1370 {
string sortString(const string &s);
}

TEST_CASE("1 [test_1370]", "[test_1370]") {
    constexpr const char *const input{"aaaabbbbcccc"};
    constexpr const char *const result{"abccbaabccba"};
    CHECK(result == leetcode_1370::sortString(input));
}

TEST_CASE("2 [test_1370]", "[test_1370]") {
    constexpr const char *const input{"youknowtherulesandsodoi"};
    constexpr const char *const result{"adehiklnorstuwyusonedoo"};
    CHECK(result == leetcode_1370::sortString(input));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1370_TEST_HPP

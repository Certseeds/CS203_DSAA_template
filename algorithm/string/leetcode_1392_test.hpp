// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1392_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1392_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_1392 {
using std::string;

namespace leetcode_1392 {
string longestPrefix(const string &s);
}

TEST_CASE("1 [test_1392]", "[test_1392]") {
    constexpr const char *const input{"abababab"};
    constexpr const char *const result{"ababab"};
    CHECK(result == leetcode_1392::longestPrefix(input));
}

TEST_CASE("2 [test_1392]", "[test_1392]") {
    constexpr const char *const input{"longestPrefix"};
    constexpr const char *const result{""};
    CHECK(result == leetcode_1392::longestPrefix(input));
}

TEST_CASE("3 [test_1392]", "[test_1392]") {
    const string input(98001, 'a');
    const string result(98000, 'a');
    CHECK(result == leetcode_1392::longestPrefix(input));
}
TEST_CASE("4 [test_1392]", "[test_1392]") {
    constexpr const char *const input{"vwantmbocxcwrqtvgzuvgrmdltfiglltaxkjfajxthcppcatddcunpkqsgpnjjgqanrwabgrtwuqbrfl"};
    constexpr const char *const result{""};
    CHECK(result == leetcode_1392::longestPrefix(input));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1392_TEST_HPP

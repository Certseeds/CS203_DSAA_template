// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1328_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1328_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_1328 {
using std::string;

namespace leetcode_1328 {
string breakPalindrome(const string &palindrome);
}

TEST_CASE("1 [test_1328]", "[test_1328]") {
    constexpr const char *const input{"abccba"};
    constexpr const char *const result{"aaccba"};
    const auto output = leetcode_1328::breakPalindrome(input);
    CHECK(result == output);
}

TEST_CASE("2 [test_1328]", "[test_1328]") {
    constexpr const char *const input{"aa"};
    constexpr const char *const result{"ab"};
    const auto output = leetcode_1328::breakPalindrome(input);
    CHECK(result == output);
}

TEST_CASE("3 [test_1328]", "[test_1328]") {
    constexpr const char *const input{"aba"};
    constexpr const char *const result{"abb"};
    const auto output = leetcode_1328::breakPalindrome(input);
    CHECK(result == output);
}

TEST_CASE("4 [test_1328]", "[test_1328]") {
    constexpr const char *const input{"aabaa"};
    constexpr const char *const result{"aabab"};
    const auto output = leetcode_1328::breakPalindrome(input);
    CHECK(result == output);
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1328_TEST_HPP

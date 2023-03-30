// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1324_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1324_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_1324 {
using std::string;

namespace leetcode_1324 {
vector<string> printVertically(const string &S);
}

using Catch::Matchers::Equals;

TEST_CASE("1 [test_1324]", "[test_1324]") {
    constexpr const char *const input{"HOW ARE YOU INDIAN MI FANS"};
    constexpr const std::array<const char *const, 6> arr{"HAYIMF",
                                                         "ORONIA",
                                                         "WEUD N",
                                                         "   I S",
                                                         "   A",
                                                         "   N"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(output, Equals(leetcode_1324::printVertically(input)));
}

TEST_CASE("2 [test_1324]", "[test_1324]") {
    constexpr const char *const input{"3z4"};
    constexpr const std::array<const char *const, 3> arr{"3", "z", "4"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(output, Equals(leetcode_1324::printVertically(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_1324_TEST_HPP

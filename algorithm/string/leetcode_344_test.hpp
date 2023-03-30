// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag string
//@Tag 字符串
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_344 {
using std::string;

struct leetcode_344 {
    static void reverseString(vector<char> &s);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_344]", "[test_344]") {
    static constexpr const char input[]{"hello"};
    vector<char> vInput{std::cbegin(input), std::cend(input)};
    const vector<char> result{std::crbegin(input), std::crend(input)};
    leetcode_344::reverseString(vInput);
    CHECK_THAT(result, Equals(vInput));
}

TEST_CASE("2 [test_344]", "[test_344]") {
    static constexpr const char input[]{"hannah"};
    vector<char> vInput{std::cbegin(input), std::cend(input)};
    const vector<char> result{std::crbegin(input), std::crend(input)};
    leetcode_344::reverseString(vInput);
    CHECK_THAT(result, Equals(vInput));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_TEST_HPP

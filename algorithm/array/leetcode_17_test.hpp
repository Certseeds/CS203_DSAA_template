// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_17_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_17_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

namespace leetcode_17 {
using std::vector;
using std::string;

struct leetcode_17 {
    static vector<string> letterCombinations(const string &digits);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 1 [test_17]", "[test_17]") {
    CHECK_THAT(leetcode_17::letterCombinations("23"),
               UnorderedEquals<string>({"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
}

TEST_CASE("test case 2 [test_17]", "[test_17]") {
    CHECK_THAT(leetcode_17::letterCombinations(""),
               UnorderedEquals<string>({}));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_17_TEST_HPP

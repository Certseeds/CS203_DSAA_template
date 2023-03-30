// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Plan 数据结构入门 Day6

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_383_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_383_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_383 {

using std::string;

struct leetcode_383 {
    static bool canConstruct(const string &ransomNote, const string &magazine);
};

TEST_CASE("1 [test_383]", "[test_383]") {
    static constexpr const char *const inputR{"UD"}, *const inputM{"AUOKD"};
    CHECK(leetcode_383::canConstruct(inputR, inputM));
}

TEST_CASE("2 [test_383]", "[test_383]") {
    static constexpr const char *const inputR{"a"}, *const inputM{"b"};
    CHECK_FALSE(leetcode_383::canConstruct(inputR, inputM));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_383_TEST_HPP

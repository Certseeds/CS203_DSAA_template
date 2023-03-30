// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Plan 数据结构入门 Day6

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_242_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_242_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <string>

namespace leetcode_242 {

using std::string;

struct leetcode_242 {
    static bool isAnagram(const string &s, const string &t);
};

TEST_CASE("1 [test_242]", "[test_242]") {
    static constexpr const char *const s{"anagram"}, *const t{"nagaram"};
    CHECK(leetcode_242::isAnagram(s, t));
}

TEST_CASE("2 [test_242]", "[test_242]") {
    static constexpr const char *const s{"rat"}, *const t{"cat"};
    CHECK_FALSE(leetcode_242::isAnagram(s, t));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_242_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag string
//@Tag 字符串]
//@Sword-Offer 50
//@Plan 数据结构入门 Day6
//@Plan 剑指OfferII-I Day05
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_387 {

using std::string;

struct leetcode_387 {
    static int32_t firstUniqChar(const string &s); // better for short str

    static int32_t firstUniqChar2(const string &s); // better for long str
};

TEST_CASE("1 [test_387]", "[test_387]") {
    static constexpr const char *const input{"UD"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_387::firstUniqChar(input));
    CHECK(result == leetcode_387::firstUniqChar2(input));
}

TEST_CASE("2 [test_387]", "[test_387]") {
    static constexpr const char *const input{"leetcode"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_387::firstUniqChar(input));
    CHECK(result == leetcode_387::firstUniqChar2(input));
}

TEST_CASE("3 [test_387]", "[test_387]") {
    static constexpr const char *const input{"loveleetcode"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_387::firstUniqChar(input));
    CHECK(result == leetcode_387::firstUniqChar2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_387_TEST_HPP

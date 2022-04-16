// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag string
//@Tag 字符串
//@Plan 剑指OfferII-I Day03
//@Plan 剑指OfferII-I Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_58_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_58_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_so_58 {

using std::string;

struct leetcode_so_58 {
    static string reverseLeftWords(const string &s, int32_t n);

    static string reverseWords(const string &s);
};

using Catch::Matchers::Equals;

TEST_CASE("2 [test_so_58 i]", "[test_so_58]") {
    static constexpr const char *const input{"  hello world!  "}, *const result{"world! hello"};
    CHECK_THAT(result, Equals(leetcode_so_58::reverseWords(input)));
}

TEST_CASE("1 [test_so_58 i]", "[test_so_58]") {
    static constexpr const char *const input{"I am a aritist."}, *const result{"aritist. a am I"};
    CHECK_THAT(result, Equals(leetcode_so_58::reverseWords(input)));
}

TEST_CASE("1 [test_so_58 ii]", "[test_so_58]") {
    static constexpr const char *const input{"We are happy."}, *const result{"are happy.We "};
    static constexpr const auto n{3};
    CHECK_THAT(result, Equals(leetcode_so_58::reverseLeftWords(input, n)));
}

TEST_CASE("2 [test_so_58 ii]", "[test_so_58]") {
    static constexpr const char *const input{"We%20are%20happy."}, *const result{"20are%20happy.We%"};
    static constexpr const auto n{3};
    CHECK_THAT(result, Equals(leetcode_so_58::reverseLeftWords(input, n)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_SO_58_TEST_HPP

// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_316 {
using std::string;
using std::string_view;

struct leetcode_316 {
    static string removeDuplicateLetters(string_view s);
};

TEST_CASE("2 [test_316]", "[test_316]") {
    static constexpr const char *const input{"cbacdcbc"}, *const output{"acdb"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("1 [test_316]", "[test_316]") {
    static constexpr const char *const input{"bcabc"}, *const output{"abc"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("3 [test_316]", "[test_316]") {
    static constexpr const char *const input{"cdadabcc"}, *const output{"adbc"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("4 [test_316]", "[test_316]") {
    static constexpr const char *const input{"abcd"}, *const output{"abcd"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("5 [test_316]", "[test_316]") {
    static constexpr const char *const input{"bddbccd"}, *const output{"bcd"};
    CHECK(output == leetcode_316::removeDuplicateLetters(input));
}

TEST_CASE("6 [test_316]", "[test_316]") {
    static constexpr const char *const input{"thesqtitxyetpxloeevdeqifkz"};
    leetcode_316::removeDuplicateLetters(input);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_316_TEST_HPP

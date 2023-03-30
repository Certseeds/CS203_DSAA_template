// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_678 {
using std::string;

struct leetcode_678 {
    static bool checkValidString(const string &s);

    static bool checkValidString2(const string &s);
};

TEST_CASE("1 [test_678]", "[test_678]") {
    CHECK(leetcode_678::checkValidString("()"));
    CHECK(leetcode_678::checkValidString("(*)"));
    CHECK(leetcode_678::checkValidString("(*))"));
}

TEST_CASE("2 [test_678]", "[test_678]") {
    CHECK_FALSE(leetcode_678::checkValidString(
            "(((((*(((((*((**(((*)*((((**))*)*)))))))))((*(((((**(**)"));
    CHECK_FALSE(leetcode_678::checkValidString(
            "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"));
}

TEST_CASE("2-1 [test_678]", "[test_678]") {
    CHECK(leetcode_678::checkValidString2("()"));
    CHECK(leetcode_678::checkValidString2("(*)"));
    CHECK(leetcode_678::checkValidString2("(*))"));
}

TEST_CASE("2-2 [test_678]", "[test_678]") {
    CHECK_FALSE(leetcode_678::checkValidString2(
            "(((((*(((((*((**(((*)*((((**))*)*)))))))))((*(((((**(**)"));
    CHECK_FALSE(leetcode_678::checkValidString2(
            "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"));

}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_TEST_HPP

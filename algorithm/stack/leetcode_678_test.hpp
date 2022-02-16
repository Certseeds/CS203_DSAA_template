/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_HPP

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_678_HPP

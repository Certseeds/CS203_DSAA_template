/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
//@Tag stack
//@Tag 栈
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_HPP

#include <catch_main.hpp>
#include <stack>
#include <string>


namespace leetcode_20 {
using std::stack;
using std::string;

struct leetcode_20 {
    static bool isValid(const string &s);
};

TEST_CASE("test case 1 [test 20]", "[test 20]") {
    CHECK(leetcode_20::isValid("()"));
    CHECK(leetcode_20::isValid("()[]{}"));
    CHECK(leetcode_20::isValid("(()[]{})[()[]{}]{()[]{}}"));
    CHECK(leetcode_20::isValid("(((()[]{})[()[]{}]{()[]{}})[]{})[()[]{}]{()[]{}}"));
}

TEST_CASE("test case 0 [test 20]", "[test 20]") {
    CHECK_FALSE(leetcode_20::isValid("(]"));
    CHECK_FALSE(leetcode_20::isValid("(}"));
    CHECK_FALSE(leetcode_20::isValid("[}"));
    CHECK_FALSE(leetcode_20::isValid("[)"));
    CHECK_FALSE(leetcode_20::isValid("{)"));
    CHECK_FALSE(leetcode_20::isValid("{]"));
    CHECK_FALSE(leetcode_20::isValid("([)]"));
    CHECK_FALSE(leetcode_20::isValid("(((()[]{})[()[]{}]{()[]{}})[]{))[()[]{}]{()[]{}}"));
}

TEST_CASE("test case 2-2 [test 20]", "[test 20]") {
    CHECK_FALSE(leetcode_20::isValid("([)]"));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_20_HPP

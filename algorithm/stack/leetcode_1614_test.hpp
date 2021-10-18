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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_HPP

#include <catch_main.hpp>
#include <array>
#include <stack>
#include <limits>
#include <string>


namespace leetcode_1614 {
using std::array;
using std::stack;
using std::string;

struct leetcode_1614 {
    static int maxDepth(const string &s);
};

TEST_CASE("1 [test 1614]", "[test 1614]") {
    CHECK(1 == leetcode_1614::maxDepth("()"));
    CHECK(1 == leetcode_1614::maxDepth("(*)"));
    CHECK(2 == leetcode_1614::maxDepth("((*))"));
}

TEST_CASE("2 [test 1614]", "[test 1614]") {
    CHECK(3 == leetcode_1614::maxDepth("(1+(2*3)+((8)/4))+1"));
    CHECK(3 == leetcode_1614::maxDepth("(1)+((2))+(((3)))"));
    CHECK(1 == leetcode_1614::maxDepth("1+(2*3)/(2-1)"));
    CHECK(0 == leetcode_1614::maxDepth("1"));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_1614_HPP

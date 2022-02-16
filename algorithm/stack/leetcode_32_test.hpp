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
//@Tag stack
//@Tag 栈
//@Tag 动态规划
//@Tag DP
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_32 {
using std::string;

struct leetcode_32 {
    static int32_t longestValidParentheses(const string &s);
};

TEST_CASE("test case 1 [test_32]", "[test_32]") {
    CHECK(0 == leetcode_32::longestValidParentheses(""));
    CHECK(2 == leetcode_32::longestValidParentheses("(()"));
    CHECK(2 == leetcode_32::longestValidParentheses("())"));
    CHECK(4 == leetcode_32::longestValidParentheses(")()())"));
    CHECK(6 == leetcode_32::longestValidParentheses("()(())"));
    CHECK(2 == leetcode_32::longestValidParentheses("()(()"));
    CHECK(6 == leetcode_32::longestValidParentheses("(()())"));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_32_HPP

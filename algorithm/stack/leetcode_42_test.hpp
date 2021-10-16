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
//@Tag 单调栈
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_42_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_42_HPP

#include <catch_main.hpp>
#include <stack>

namespace leetcode_42 {
using std::stack;

struct leetcode_42 {
    static int trap(const vector<int> &height);
};


TEST_CASE("test case 1 [test _42]", "[test _42]") {
    const vector<int32_t> input{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    CHECK(6 == leetcode_42::trap(input));
}

TEST_CASE("test case 2 [test _42]", "[test _42]") {
    const vector<int32_t> input{4, 2, 0, 3, 2, 5};
    CHECK(9 == leetcode_42::trap(input));
}

TEST_CASE("test case 3 [test _42]", "[test _42]") {
    const vector<int32_t> input{0, 1, 0, 3, 1, 0, 1, 3, 2, 1, 2, 1};
    CHECK(9 == leetcode_42::trap(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STACK_LEETCODE_42_HPP

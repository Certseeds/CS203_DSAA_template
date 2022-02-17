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
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_43 {
struct leetcode_43 {
    static string multiply(const string &num1, const string &num2);
};

TEST_CASE("1 [test _43]", "[test _43]") {
    const string num1{"9"};
    const string num2{"9"};
    const string result{"81"};
    CHECK(result == leetcode_43::multiply(num1, num2));
}

TEST_CASE("2 [test _43]", "[test _43]") {
    const string num1{"2"};
    const string num2{"3"};
    const string result{"6"};
    CHECK(result == leetcode_43::multiply(num1, num2));
}

TEST_CASE("3 [test _43]", "[test _43]") {
    const string num1{"123"};
    const string num2{"456"};
    const string result{"56088"};
    CHECK(result == leetcode_43::multiply(num1, num2));
}

TEST_CASE("4 [test _43]", "[test _43]") {
    const string num1{"114514"};
    const string num2{"1919810"};
    const string result{"219845122340"};
    CHECK(result == leetcode_43::multiply(num1, num2));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_HPP

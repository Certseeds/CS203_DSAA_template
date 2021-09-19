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
//@Tag string
//@Tag 字符串
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_8_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_8_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_8 {
using std::string;

struct leetcode_8 {
    static int myAtoi(const string &str);
};

TEST_CASE("1 [test 8]", "[test 8]") {
    CHECK(leetcode_8::myAtoi("42") == 42);
    CHECK(leetcode_8::myAtoi("65537") == 65537);
    CHECK(leetcode_8::myAtoi("114514") == 114514);
    CHECK(leetcode_8::myAtoi("1919810") == 1919810);
}

TEST_CASE("2 [test 8]", "[test 8]") {
    CHECK(leetcode_8::myAtoi("+42") == 42);
    CHECK(leetcode_8::myAtoi("+65537") == 65537);
    CHECK(leetcode_8::myAtoi("+114514") == 114514);
    CHECK(leetcode_8::myAtoi("+1919810") == 1919810);
}

TEST_CASE("3 [test 8]", "[test 8]") {
    CHECK(leetcode_8::myAtoi("-42") == -42);
    CHECK(leetcode_8::myAtoi("-65537") == -65537);
    CHECK(leetcode_8::myAtoi("-114514") == -114514);
    CHECK(leetcode_8::myAtoi("-1919810") == -1919810);
}

TEST_CASE("4 [test 8]", "[test 8]") {
    CHECK(leetcode_8::myAtoi("  -42") == -42);
    CHECK(leetcode_8::myAtoi("  -65537") == -65537);
    CHECK(leetcode_8::myAtoi("    -114514") == -114514);
    CHECK(leetcode_8::myAtoi("     -1919810") == -1919810);
}

TEST_CASE("5 [test 8]", "[test 8]") {
    CHECK(leetcode_8::myAtoi("114514 with meaningless words") == 114514);
    CHECK(leetcode_8::myAtoi("meaningless words with -65537") == 0);
    CHECK(leetcode_8::myAtoi("2147483647") == std::numeric_limits<int32_t>::max());
    CHECK(leetcode_8::myAtoi("-2147483648") == std::numeric_limits<int32_t>::min());
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_8_HPP

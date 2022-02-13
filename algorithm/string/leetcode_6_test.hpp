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
//@Tag string
//@Tag 字符串
//@Tag 模仿
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <string>

namespace leetcode_6 {
using std::string;

struct leetcode_6 {
    static string convert(const string &s, int32_t numRows);
};


TEST_CASE("test basic [test_6]", "[test_6]") {
    CHECK(leetcode_6::convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    CHECK(leetcode_6::convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    CHECK(leetcode_6::convert("A", 1) == "A");
    CHECK(leetcode_6::convert("AB", 2) == "AB");
    CHECK(leetcode_6::convert("ABC", 3) == "ABC");
    CHECK(leetcode_6::convert("ABCD", 4) == "ABCD");
    CHECK(leetcode_6::convert("ABCDE", 4) == "ABCED");
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_6_HPP

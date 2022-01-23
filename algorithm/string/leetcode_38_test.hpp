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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <string>

namespace leetcode_38 {

using std::array;
using std::string;

struct leetcode_38 {
    static string countAndSay(int n);
};

TEST_CASE("1 [test_38]", "[test_38]") {
    CHECK(leetcode_38::countAndSay(1) == "1");
    CHECK(leetcode_38::countAndSay(2) == "11");
    CHECK(leetcode_38::countAndSay(3) == "21");
    CHECK(leetcode_38::countAndSay(4) == "1211");
    CHECK(leetcode_38::countAndSay(5) == "111221");
    CHECK(leetcode_38::countAndSay(6) == "312211");
    CHECK(leetcode_38::countAndSay(7) == "13112221");
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_38_HPP

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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_HPP

#include <catch_main.hpp>
#include <array>
#include <string>
#include <vector>

namespace leetcode_12 {

using std::array;
using std::string;
using std::vector;

struct leetcode_12 {
    static string intToRoman(int num);

    static string intToRoman_2(int num);
};


using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("test case 1 [test 12", "[test 12]") {
    CHECK(leetcode_12::intToRoman(3) == "III");
    CHECK(leetcode_12::intToRoman_2(3) == "III");
}

TEST_CASE("test case 2 [test 12", "[test 12]") {
    CHECK(leetcode_12::intToRoman(4) == "IV");
    CHECK(leetcode_12::intToRoman_2(4) == "IV");
}

TEST_CASE("test case 3 [test 12", "[test 12]") {
    CHECK(leetcode_12::intToRoman(9) == "IX");
    CHECK(leetcode_12::intToRoman_2(9) == "IX");
}

TEST_CASE("test case 4 [test 12", "[test 12]") {
    CHECK(leetcode_12::intToRoman(58) == "LVIII");
    CHECK(leetcode_12::intToRoman_2(58) == "LVIII");
}

TEST_CASE("test case 5 [test 12", "[test 12]") {
    CHECK(leetcode_12::intToRoman(1994) == "MCMXCIV");
    CHECK(leetcode_12::intToRoman_2(1994) == "MCMXCIV");
}

TEST_CASE("test case 6 [test 12", "[test 12]") {
    CHECK(leetcode_12::intToRoman(114514) ==
          "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV");
    CHECK(leetcode_12::intToRoman_2(114514) ==
          "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV");
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_HPP

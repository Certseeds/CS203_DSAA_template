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
//@Tag 模拟
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_TEST_HPP

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

TEST_CASE("test case 1 [test_12]", "[test_12]") {
    static constexpr const auto input{3};
    static constexpr const char *const result{"III"};
    CHECK(result == leetcode_12::intToRoman(input));
    CHECK(result == leetcode_12::intToRoman_2(input));
}

TEST_CASE("test case 2 [test_12]", "[test_12]") {
    static constexpr const auto input{4};
    static constexpr const char *const result{"IV"};
    CHECK(result == leetcode_12::intToRoman(input));
    CHECK(result == leetcode_12::intToRoman_2(input));
}

TEST_CASE("test case 3 [test_12]", "[test_12]") {
    static constexpr const auto input{9};
    static constexpr const char *const result{"IX"};
    CHECK(result == leetcode_12::intToRoman(input));
    CHECK(result == leetcode_12::intToRoman_2(input));
}

TEST_CASE("test case 4 [test_12]", "[test_12]") {
    static constexpr const auto input{58};
    static constexpr const char *const result{"LVIII"};
    CHECK(result == leetcode_12::intToRoman(input));
    CHECK(result == leetcode_12::intToRoman_2(input));
}

TEST_CASE("test case 5 [test_12]", "[test_12]") {
    static constexpr const auto input{1994};
    static constexpr const char *const result{"MCMXCIV"};
    CHECK(result == leetcode_12::intToRoman(input));
    CHECK(result == leetcode_12::intToRoman_2(input));
}

TEST_CASE("test case 6 [test_12]", "[test_12]") {
    static constexpr const auto input{114514};
    static constexpr const char *const result{
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV"};
    CHECK(result == leetcode_12::intToRoman(input));
    CHECK(result == leetcode_12::intToRoman_2(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_12_TEST_HPP

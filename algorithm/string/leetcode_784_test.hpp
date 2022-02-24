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
//@Description 非常简单
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_784 {
using std::string;

struct leetcode_784 {
    static vector<string> letterCasePermutation(const string &S);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_784]", "[test_784]") {
    static constexpr const char *const input{"a1b2"};
    static constexpr const std::array<const char *const, 4> arr{"a1b2", "a1B2", "A1b2", "A1B2"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(output, UnorderedEquals(leetcode_784::letterCasePermutation(input)));
}

TEST_CASE("2 [test_784]", "[test_784]") {
    static constexpr const char *const input{"3z4"};
    static constexpr const std::array<const char *const, 2> arr{"3z4", "3Z4"};
    const vector<string> output{arr.cbegin(), arr.cend()};
    CHECK_THAT(output, UnorderedEquals(leetcode_784::letterCasePermutation(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_784_TEST_HPP

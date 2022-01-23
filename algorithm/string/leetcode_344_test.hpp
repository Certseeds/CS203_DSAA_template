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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_HPP

#include <catch_main.hpp>
#include <string>

namespace leetcode_344 {

using std::array;
using std::string;

struct leetcode_344 {
    static void reverseString(vector<char> &s);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_344]", "[test_344]") {
    static constexpr const char input[]{"hello"};
    vector<char> vInput{std::cbegin(input), std::cend(input)};
    const vector<char> result{std::crbegin(input), std::crend(input)};
    leetcode_344::reverseString(vInput);
    CHECK_THAT(result, Equals(vInput));
}

TEST_CASE("2 [test_344]", "[test_344]") {
    static constexpr const char input[]{"hannah"};
    vector<char> vInput{std::cbegin(input), std::cend(input)};
    const vector<char> result{std::crbegin(input), std::crend(input)};
    leetcode_344::reverseString(vInput);
    CHECK_THAT(result, Equals(vInput));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_344_HPP

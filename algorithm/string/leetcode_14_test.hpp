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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_HPP

#include <catch_main.hpp>
#include <array>
#include <string>
#include <vector>

namespace leetcode_14 {

using std::array;
using std::string;
using std::vector;

struct leetcode_14 {
    static string longestCommonPrefix(const vector<string> &strs);
};

TEST_CASE("test case 1 [test 14]", "[test 14]") {
    const vector<string> strs = {"flower", "flow", "flight"};
    CHECK(leetcode_14::longestCommonPrefix(strs) == "fl");
}

TEST_CASE("test case 2 [test 14]", "[test 14]") {
    const vector<string> strs = {
            "dog", "racecar", "car"
    };
    CHECK(leetcode_14::longestCommonPrefix(strs).empty());

}

TEST_CASE("test case 3 [test 14]", "[test 14]") {
    const vector<string> strs = {
    };
    CHECK(leetcode_14::longestCommonPrefix(strs).empty());
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_14_HPP

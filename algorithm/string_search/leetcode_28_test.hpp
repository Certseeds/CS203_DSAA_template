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
//@Tag 烤馍片
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP

#include <catch_main.hpp>
#include <string>
#include <vector>
#include <unordered_set>

namespace leetcode_28 {

using std::array;
using std::string;
using std::vector;
using std::unordered_set;

struct leetcode_28 {
    static int strStr(const string &haystack, const string &needle);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_28]", "[test_28]") {
    CHECK(leetcode_28::strStr("hello", "ll") == 2);
    CHECK(leetcode_28::strStr("aaaaa", "bba") == -1);
    CHECK(leetcode_28::strStr("aaaaa", "") == 0);
    CHECK(leetcode_28::strStr("a", "a") == 0);
    CHECK(leetcode_28::strStr("mississippi", "issi") == 1);
    CHECK(leetcode_28::strStr("mississippi", "issip") == 4);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_STRING_LEETCODE_28_TEST_HPP

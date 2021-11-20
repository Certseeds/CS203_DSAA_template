/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
//@Tag DP
//@Tag 动态规划
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP

#include <catch_main.hpp>
#include <vector>
#include <string>

namespace leetcode_44 {
using std::string;
using std::vector;

struct leetcode_44 {
    static bool isMatch(const string &s, const string &p);
};


TEST_CASE("double empty [test_44]", "[test_44]") {
    CHECK(leetcode_44::isMatch("", "*"));
}

TEST_CASE("test 1 [test_44]", "[test_44]") {
    CHECK_FALSE(leetcode_44::isMatch("aa", "a"));
}


TEST_CASE("test 2 [test_44]", "[test_44]") {
    CHECK(leetcode_44::isMatch("aa", "*"));
}

TEST_CASE("? [test_44]", "[test_44]") {
    CHECK_FALSE(leetcode_44::isMatch("cb", "*a"));
}


TEST_CASE("* can match '' or any string [test_44]", "[test_44]") {
    CHECK(leetcode_44::isMatch("adceb", "a*b"));
}

TEST_CASE("both * and ? [test_44]", "[test_44]") {
    CHECK_FALSE(leetcode_44::isMatch("acdcb", "a*c?b"));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_44_TEST_CPP

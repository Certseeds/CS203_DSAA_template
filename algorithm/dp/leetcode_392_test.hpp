/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanos

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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <vector>

namespace leetcode_392 {
using std::vector;

struct leetcode_392 final {
    static bool isSubsequence(const string &s, const string &t);
};

TEST_CASE("1 [test_392]", "[test_392]") {
    static constexpr const char *const s{"abc"}, *const t{"ahbgdc"};
    CHECK(leetcode_392::isSubsequence(s, t));
}

TEST_CASE("2 [test_392]", "[test_392]") {
    static constexpr const char *const s{"axc"}, *const t{"ahbgdc"};
    CHECK_FALSE(leetcode_392::isSubsequence(s, t));
}

TEST_CASE("3 [test_392]", "[test_392]") {
    static constexpr const char *const s{"114514"}, *const t{"1919810"};
    CHECK_FALSE(leetcode_392::isSubsequence(s, t));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_392_TEST_CPP

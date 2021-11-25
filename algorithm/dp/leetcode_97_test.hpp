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
//@Description 斐波那契?

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <vector>
#include <unordered_map>

namespace leetcode_97 {
using std::vector;
using std::unordered_map;
struct leetcode_97 final {
    static bool isInterleave(const string &s1, const string &s2, const string &s3);
};

TEST_CASE("1 [test_97]", "[test_97]") {
    static constexpr const auto s1{"aabcc"}, s2{"dbbca"}, s3{"aadbbcbcac"};
    CHECK(leetcode_97::isInterleave(s1, s2, s3));
}

TEST_CASE("2 [test_97]", "[test_97]") {
    static constexpr const auto s1{"aabcc"}, s2{"dbbca"}, s3{"aadbbbaccc"};
    CHECK_FALSE(leetcode_97::isInterleave(s1, s2, s3));
}

TEST_CASE("3 [test_97]", "[test_97]") {
    static constexpr const auto s1{""}, s2{""}, s3{""};
    CHECK(leetcode_97::isInterleave(s1, s2, s3));
}

TEST_CASE("4 [test_97]", "[test_97]") {
    static constexpr const auto s1{
            "abababababababababababababababababababababababababababababababababababababababababababababababababbb"},
            s2{"babababababababababababababababababababababababababababababababababababababababababababababababaaaba"},
            s3{
            "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb"};
    CHECK_FALSE(leetcode_97::isInterleave(s1, s2, s3));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_97_TEST_CPP
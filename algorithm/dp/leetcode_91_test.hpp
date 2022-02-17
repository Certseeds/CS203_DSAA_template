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


#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_91_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_91_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_91 {
using std::vector;

struct leetcode_91 final {
    static int32_t numDecodings(const string &s);
};

TEST_CASE("1 [test_91]", "[test_91]") {
    static constexpr const char *const str{"12"};
    static constexpr const auto result{2};
    CHECK(result == leetcode_91::numDecodings(str));
}

TEST_CASE("2 [test_91]", "[test_91]") {
    static constexpr const char *const str{"226"};
    static constexpr const auto result{3};
    CHECK(result == leetcode_91::numDecodings(str));
}

TEST_CASE("3 [test_91]", "[test_91]") {
    static constexpr const char *const str{"0"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_91::numDecodings(str));
}

TEST_CASE("4 [test_91]", "[test_91]") {
    static constexpr const char *const str{"06"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_91::numDecodings(str));
}

TEST_CASE("5 [test_91]", "[test_91]") {
    static constexpr const char *const str{"10"};
    static constexpr const auto result{1};
    CHECK(result == leetcode_91::numDecodings(str));
}

TEST_CASE("6 [test_91]", "[test_91]") {
    static constexpr const char *const str{"10011"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_91::numDecodings(str));
}

TEST_CASE("7 [test_91]", "[test_91]") {
    static constexpr const char *const str{"012"};
    static constexpr const auto result{0};
    CHECK(result == leetcode_91::numDecodings(str));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_91_TEST_CPP

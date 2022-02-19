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
//@Tag divide_merge
//@Tag 分治
//@Tag DP
//@Tag 动态规划
//@Plan 动态规划入门 Day5
//@Plan 数据结构入门 Day1
//@Plan 剑指OfferII-I Day09
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_53 {
using std::string;
using std::vector;

struct leetcode_53 {
    static int32_t maxSubArray(const vector<int32_t> &nums);

    static int32_t maxSubArray2(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_53]", "[test_53]") {
    const vector<int32_t> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    static constexpr const int32_t output{6};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("2 [test_53]", "[test_53]") {
    const vector<int32_t> input{1};
    static constexpr const int32_t output{1};
    CHECK(leetcode_53::maxSubArray2(input) == output);
    CHECK(leetcode_53::maxSubArray(input) == output);
}

TEST_CASE("3 [test_53]", "[test_53]") {
    const vector<int32_t> input{0};
    static constexpr const int32_t output{0};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("4 [test_53]", "[test_53]") {
    const vector<int32_t> input{-1};
    static constexpr const int32_t output{-1};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("5 [test_53]", "[test_53]") {
    const vector<int32_t> input{-100000};
    static constexpr const int32_t output{-100000};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("6 [test_53]", "[test_53]") {
    const vector<int32_t> input{-2, -1};
    static constexpr const int32_t output{-1};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}

TEST_CASE("7 [test_53]", "[test_53]") {
    const vector<int32_t> input{5, 4, -1, 7, 8};
    static constexpr const int32_t output{23};
    CHECK(leetcode_53::maxSubArray(input) == output);
    CHECK(leetcode_53::maxSubArray2(input) == output);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DIVIDE_MERGE_LEETCODE_53_TEST_CPP

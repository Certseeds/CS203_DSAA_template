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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_918_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_918_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <numeric>

namespace leetcode_918 {
using std::vector;

struct leetcode_918 final {
    static int32_t maxSubarraySumCircular(const vector<int32_t> &nums);
};

TEST_CASE("10 [test_918]", "[test_918]") {
    const vector<int32_t> input{-2, 4, -5, 4, -5, 9, 4};
    static constexpr const auto result{15};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("9 [test_918]", "[test_918]") {
    const vector<int32_t> input{2, -2, 2, 7, 8, 0};
    static constexpr const auto result{19};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("6 [test_918]", "[test_918]") {
    const vector<int32_t> input{-2, 3, 5};
    static constexpr const auto result{8};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("1 [test_918]", "[test_918]") {
    const vector<int32_t> input{1, -2, 3, -2};
    static constexpr const auto result{3};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("2 [test_918]", "[test_918]") {
    const vector<int32_t> input{5, -3, 5};
    static constexpr const auto result{10};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("3 [test_918]", "[test_918]") {
    const vector<int32_t> input{3, -1, 2, -1};
    static constexpr const auto result{4};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("4 [test_918]", "[test_918]") {
    const vector<int32_t> input{3, -2, 2, -3};
    static constexpr const auto result{3};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("5 [test_918]", "[test_918]") {
    const vector<int32_t> input{-2, -3, -1};
    static constexpr const auto result{-1};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}


TEST_CASE("7 [test_918]", "[test_918]") {
    const vector<int32_t> input{3, 1, 3, 2, 6};
    static constexpr const auto result{15};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}

TEST_CASE("8 [test_918]", "[test_918]") {
    const vector<int32_t> input{-7, 1, 2, 7, -2, -5};
    static constexpr const auto result{10};
    CHECK(result == leetcode_918::maxSubarraySumCircular(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_918_TEST_CPP

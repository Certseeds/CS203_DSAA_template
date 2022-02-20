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
//@Tag stack
//@Tag 单调栈
//@Linked 121 122 309
//@Plan 动态规划入门 Day8

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_714_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_714_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_714 {
using std::vector;

struct leetcode_714 final {
    static int32_t maxProfit(const vector<int32_t> &prices, int32_t fee);

    static int32_t maxProfit2(const vector<int32_t> &prices, int32_t fee);
};

TEST_CASE("0 [test_714]", "[test_714]") {
    const vector<int32_t> input{1, 2, 3, 0, 2};
    static constexpr const auto fee{0};
    static constexpr const auto result{4};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("1 [test_714]", "[test_714]") {
    const vector<int32_t> input{7, 1, 5, 3, 6, 4};
    static constexpr const auto fee{0};
    static constexpr const auto result{7};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("2 [test_714]", "[test_714]") {
    const vector<int32_t> input{7, 6, 4, 3, 1};
    static constexpr const auto fee{0};
    static constexpr const auto result{0};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("3 [test_714]", "[test_714]") {
    const vector<int32_t> input{1, 2, 3, 4, 5};
    static constexpr const auto fee{0};
    static constexpr const auto result{4};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("4 [test_714]", "[test_714]") {
    const vector<int32_t> input{1, 3, 2, 8, 4, 9};
    static constexpr const auto fee{2};
    static constexpr const auto result{8};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}

TEST_CASE("5 [test_714]", "[test_714]") {
    const vector<int32_t> input{1, 3, 7, 5, 10, 3};
    static constexpr const auto fee{3};
    static constexpr const auto result{6};
    CHECK(result == leetcode_714::maxProfit(input, fee));
    CHECK(result == leetcode_714::maxProfit2(input, fee));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_714_TEST_CPP

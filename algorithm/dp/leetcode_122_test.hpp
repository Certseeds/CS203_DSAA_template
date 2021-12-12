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
//@Linked 121

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <stack>
#include <vector>

namespace leetcode_122 {
using std::stack;
using std::vector;

struct leetcode_122 final {
    static int32_t maxProfit(const vector<int32_t> &prices);

    static int32_t maxProfit2(const vector<int32_t> &prices);

    static int32_t maxProfit3(const vector<int32_t> &prices);

    static int32_t maxProfit4(const vector<int32_t> &prices);
};


TEST_CASE("1 [test_122]", "[test_122]") {
    const vector<int32_t> input{7, 1, 5, 3, 6, 4};
    static constexpr const auto result{7};
    CHECK(result == leetcode_122::maxProfit(input));
    CHECK(result == leetcode_122::maxProfit2(input));
    CHECK(result == leetcode_122::maxProfit3(input));
    CHECK(result == leetcode_122::maxProfit4(input));
}

TEST_CASE("2 [test_122]", "[test_122]") {
    const vector<int32_t> input{7, 6, 4, 3, 1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_122::maxProfit(input));
    CHECK(result == leetcode_122::maxProfit2(input));
    CHECK(result == leetcode_122::maxProfit3(input));
    CHECK(result == leetcode_122::maxProfit4(input));
}

TEST_CASE("3 [test_122]", "[test_122]") {
    const vector<int32_t> input{1, 2, 3, 4, 5};
    static constexpr const auto result{4};
    CHECK(result == leetcode_122::maxProfit(input));
    CHECK(result == leetcode_122::maxProfit2(input));
    CHECK(result == leetcode_122::maxProfit3(input));
    CHECK(result == leetcode_122::maxProfit4(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_122_TEST_CPP
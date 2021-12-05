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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_121_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_121_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <numeric>

namespace leetcode_121 {
using std::vector;
using std::unordered_map;

struct leetcode_121 final {
    static int32_t maxProfit(const vector<int32_t> &prices);

    static int32_t maxProfit2(const vector<int32_t> &prices);
};


TEST_CASE("1 [test_121]", "[test_121]") {
    const vector<int32_t> input{7, 1, 5, 3, 6, 4};
    static constexpr const auto result{5};
    CHECK(result == leetcode_121::maxProfit(input));
    CHECK(result == leetcode_121::maxProfit2(input));
}

TEST_CASE("2 [test_121]", "[test_121]") {
    const vector<int32_t> input{7, 6, 4, 3, 1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_121::maxProfit(input));
    CHECK(result == leetcode_121::maxProfit2(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_121_TEST_CPP

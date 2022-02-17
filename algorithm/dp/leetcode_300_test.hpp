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
//@Linked 121 122
//@Plan 动态规划入门 Day18
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_300_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_300_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_300 {
using std::vector;

struct leetcode_300 final {
    static int32_t lengthOfLIS(const vector<int32_t> &nums);
};


TEST_CASE("0 [test_300]", "[test_300]") {
    const vector<int32_t> input{10, 9, 2, 5, 3, 7, 101, 18};
    static constexpr const auto result{4};
    CHECK(result == leetcode_300::lengthOfLIS(input));
}

TEST_CASE("1 [test_300]", "[test_300]") {
    const vector<int32_t> input{4, 10, 4, 3, 8, 9};
    static constexpr const auto result{3};
    CHECK(result == leetcode_300::lengthOfLIS(input));
}

TEST_CASE("2 [test_300]", "[test_300]") {
    const vector<int32_t> input{0, 1, 0, 3, 2, 3};
    static constexpr const auto result{4};
    CHECK(result == leetcode_300::lengthOfLIS(input));
}

TEST_CASE("3 [test_300]", "[test_300]") {
    const vector<int32_t> input{7, 7, 7, 7, 7, 7, 7};
    static constexpr const auto result{1};
    CHECK(result == leetcode_300::lengthOfLIS(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_300_TEST_CPP

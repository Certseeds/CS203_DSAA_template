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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_931 {
using std::vector;

struct leetcode_931 final {
    static int32_t minFallingPathSum(const vector<vector<int32_t>> &matrix);
};

TEST_CASE("1 [test_931]", "[test_931]") {
    const vector<vector<int32_t>> input{
            {2, 1, 3},
            {6, 5, 4},
            {7, 8, 9}
    };
    static constexpr const auto result{13};
    CHECK(result == leetcode_931::minFallingPathSum(input));
}

TEST_CASE("2 [test_931]", "[test_931]") {
    const vector<vector<int32_t>> input{
            {-19, 57},
            {-40, -5},
    };
    static constexpr const auto result{-59};
    CHECK(result == leetcode_931::minFallingPathSum(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_931_TEST_CPP

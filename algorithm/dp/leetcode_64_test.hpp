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
//@Description 最小路径和

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_64_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_64_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <vector>

namespace leetcode_64 {
using std::vector;

struct leetcode_64 final{
    static int32_t minPathSum(const vector<vector<int32_t>> &grid);
};

TEST_CASE("1 [test_64]", "[test_64]") {
    const vector<vector<int32_t>> input{{1, 3, 1},
                                        {1, 5, 1},
                                        {4, 2, 1}};
    static constexpr const auto result{7};
    CHECK(result == leetcode_64::minPathSum(input));
}

TEST_CASE("2 [test_64]", "[test_64]") {
    const vector<vector<int32_t>> input{{1, 2, 3},
                                        {4, 5, 6}};
    static constexpr const auto result{12};
    CHECK(result == leetcode_64::minPathSum(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_64_TEST_CPP

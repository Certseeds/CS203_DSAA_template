/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2021-04-03 10:15:42
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
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
//@Description 经典小学数学题,交叉部分算面积
//@Plan 动态规划入门 Day14
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1314_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1314_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1314 {
using std::vector;

struct leetcode_1314 {
    static vector<vector<int32_t>> matrixBlockSum(const vector<vector<int32_t>> &mat, int32_t K);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_1314]", "[test_1314]") {
    const vector<vector<int32_t>> input{{1, 2, 3},
                                        {4, 5, 6},
                                        {7, 8, 9}};
    static constexpr const auto k1{1};
    const vector<vector<int32_t>> result1{{12, 21, 16},
                                          {27, 45, 33,},
                                          {24, 39, 28}};
    CHECK_THAT(result1, Equals(leetcode_1314::matrixBlockSum(input, k1)));
    static constexpr const auto k2{2};
    const vector<vector<int32_t>> result2{{45, 45, 45},
                                          {45, 45, 45,},
                                          {45, 45, 45}};
    CHECK_THAT(result2, Equals(leetcode_1314::matrixBlockSum(input, k2)));
}

TEST_CASE("2 [test_1314]", "[test_1314]") {
    const vector<vector<int32_t>> input{{67, 64, 78},
                                        {99, 98, 38},
                                        {82, 46, 46},
                                        {6,  52, 55},
                                        {55, 99, 45}};
    static constexpr const auto k{1};
    const vector<vector<int32_t>> result{{328, 444, 278},
                                         {456, 618, 370},
                                         {383, 522, 335},
                                         {340, 486, 343},
                                         {212, 312, 251}};
    CHECK_THAT(result, Equals(leetcode_1314::matrixBlockSum(input, k)));
}

}

namespace leetcode_304 {
class NumMatrix : private nonCopyMoveAble {
private:
    const vector<vector<int32_t>> sumRange;
public:
    explicit NumMatrix(const vector<vector<int32_t>> &matrix);

    int32_t sumRegion(int32_t row1, int32_t col1, int32_t row2, int32_t col2) const;
};

TEST_CASE("1 [test_304]", "[test_304]") {
    const vector<vector<int32_t>> input{
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}};
    const auto matrix{std::make_unique<NumMatrix>(input)};
    static constexpr const auto result1{8}, result2{11}, result3{12};
    CHECK(result1 == matrix->sumRegion(2, 1, 4, 3));
    CHECK(result2 == matrix->sumRegion(1, 1, 2, 2));
    CHECK(result3 == matrix->sumRegion(1, 2, 2, 4));
}

}

#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_1314_TEST_CPP

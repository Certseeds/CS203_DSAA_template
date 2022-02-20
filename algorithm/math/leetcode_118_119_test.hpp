/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
//@Tag list
//@Tag 数学问题
//@Plan 动态规划入门 Day12
//@Plan 数据结构入门 Day4
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_118 {
using std::vector;

struct leetcode_118 {
    static vector<vector<int32_t>> generate(int32_t numRows);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_118]", "[test_118]") {
    static constexpr const auto input{5};
    const vector<vector<int32_t>> result{
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1},
    };
    CHECK_THAT(result, Equals(leetcode_118::generate(input)));
}


TEST_CASE("2 [test_118]", "[test_118]") {
    static constexpr const auto input{1};
    const vector<vector<int32_t>> result{
            {1},
    };
    CHECK_THAT(result, Equals(leetcode_118::generate(input)));
}
}
namespace leetcode_119 {
using std::vector;

struct leetcode_119 {
    static vector<int32_t> getRow(int32_t rowIndex);

    static vector<int32_t> getRowN(int32_t rowIndex);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_119]", "[test_119]") {
    static constexpr const auto input{3};
    const vector<int32_t> result{1, 3, 3, 1};
    CHECK_THAT(result, Equals(leetcode_119::getRow(input)));
    CHECK_THAT(result, Equals(leetcode_119::getRowN(input)));
}


TEST_CASE("2 [test_119]", "[test_119]") {
    static constexpr const auto input{1};
    const vector<int32_t> result{1, 1};
    CHECK_THAT(result, Equals(leetcode_119::getRow(input)));
    CHECK_THAT(result, Equals(leetcode_119::getRowN(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_118_119_TEST_HPP

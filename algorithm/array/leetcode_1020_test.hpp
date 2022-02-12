/*
MIT License

CS203_DSAA_template

Copyright (C) 2022  nanoseeds

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
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1020 {
using std::vector;

struct leetcode_1020 {
    static int32_t numEnclaves(const vector<vector<int32_t>> &grid);
};

TEST_CASE("test case 4 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0},
            {1},
            {1},
            {0},
            {0}
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 6 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{{0, 1, 1, 0, 0}};
    static constexpr const auto result{0};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 3 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0},
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 2 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 1, 1, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 0},
    };
    static constexpr const auto result{0};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 1 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{
            {0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
    };
    static constexpr const auto result{3};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

TEST_CASE("test case 5 {test_1020}", "{test_1020}") {
    const vector<vector<int32_t>> input{{0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                                        {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0},
                                        {0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0},
                                        {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                                        {0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0},
                                        {1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1},
                                        {0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                                        {0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0},
                                        {1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                                        {1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1}};
    static constexpr const auto result{7};
    CHECK(result == leetcode_1020::numEnclaves(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1020_HPP

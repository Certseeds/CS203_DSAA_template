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
//@Tag array
//@Tag 数组
//@Tag 暴力枚举
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <numeric>
#include <vector>
#include <unordered_map>

namespace leetcode_532 {
using std::unordered_map;
using std::vector;

struct leetcode_532 {
    static int32_t findPairs(const vector<int32_t> &nums, int32_t k);
};

TEST_CASE("test case 1 [test_532]", "[test_532]") {
    const vector<int32_t> input{3, 1, 4, 1, 5};
    static constexpr const auto k{2}, result{2};
    CHECK(result == leetcode_532::findPairs(input, k));
}

TEST_CASE("test case 2 [test_532]", "[test_532]") {
    const vector<int32_t> input{3, 1, 4, 2, 5};
    static constexpr const auto k{1}, result{4};
    CHECK(result == leetcode_532::findPairs(input, k));
}

TEST_CASE("test case 3 [test_532]", "[test_532]") {
    const vector<int32_t> input{1, 3, 1, 5, 4};
    static constexpr const auto k{0}, result{1};
    CHECK(result == leetcode_532::findPairs(input, k));
}

TEST_CASE("test case 4 [test_532]", "[test_532]") {
    const vector<int32_t> input{1, 2, 4, 4, 3, 3, 0, 9, 2, 3};
    static constexpr const auto k{3}, result{2};
    CHECK(result == leetcode_532::findPairs(input, k));
}

TEST_CASE("test case 5 [test_532]", "[test_532]") {
    const vector<int32_t> input{-1, -2, -3};
    static constexpr const auto k{1}, result{2};
    CHECK(result == leetcode_532::findPairs(input, k));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_532_HPP

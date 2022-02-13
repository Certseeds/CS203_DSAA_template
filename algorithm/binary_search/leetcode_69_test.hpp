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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_69_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_69_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一

namespace leetcode_69 {
struct leetcode_69 final {
    static int32_t mySqrt(int32_t x);
};

TEST_CASE("test case 0", "[test leetcode_69]") {
    CHECK(0 == leetcode_69::mySqrt(0));
    CHECK(1 == leetcode_69::mySqrt(1));
    CHECK(1 == leetcode_69::mySqrt(1));
    CHECK(1 == leetcode_69::mySqrt(1));
}

TEST_CASE("test case 1", "[test leetcode_69]") {
    static constexpr const auto input{4}, result{2};
    CHECK(result == leetcode_69::mySqrt(input));
}

TEST_CASE("test case 2", "[test leetcode_69]") {
    static constexpr const auto input{8}, result{2};
    CHECK(result == leetcode_69::mySqrt(input));
}

TEST_CASE("test case 3", "[test leetcode_69]") {
    static constexpr const auto input{9}, result{3};
    CHECK(result == leetcode_69::mySqrt(input));
}

TEST_CASE("test case 4", "[test leetcode_69]") {
    static constexpr const auto input{6}, result{2};
    CHECK(result == leetcode_69::mySqrt(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_69_HPP


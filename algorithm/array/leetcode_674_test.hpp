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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_674 {
using std::vector;

struct leetcode_674 {
    static int findLengthOfLCIS(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_674]", "[test_674]") {
    const vector<int32_t> input{4, 2, 3};
    static constexpr const auto result{2};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}

TEST_CASE("test case 2 [test_674]", "[test_674]") {
    const vector<int32_t> input{1, 3, 5, 4, 7};
    static constexpr const auto result{3};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}

TEST_CASE("test case 3 [test_674]", "[test_674]") {
    const vector<int32_t> input{2, 2, 2, 2, 2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}

TEST_CASE("test case 4 [test_674]", "[test_674]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}

TEST_CASE("test case 5 [test_674]", "[test_674]") {
    const vector<int32_t> input{};
    static constexpr const auto result{0};
    CHECK(result == leetcode_674::findLengthOfLCIS(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_674_HPP

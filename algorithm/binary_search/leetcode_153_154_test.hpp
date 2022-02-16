/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanos

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
//@Tag binary search
//@Tag 二分
//@Level Mid
//@Sword-Offer 11
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_HPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_153 {
using std::vector;

struct leetcode_153 final {
    static int32_t findMin(const vector<int32_t> &nums);
};
}
namespace leetcode_154 {
using std::vector;

struct leetcode_154 final {
    static int32_t findMin(const vector<int32_t> &nums);
};

using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;

TEST_CASE("test case 2 [test_154]", "[test_154]") {
    const vector<int32_t> input{2, 2, 2, 0, 1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_154::findMin(input));
}
}
namespace leetcode_153_154 {

using leetcode_153::leetcode_153;
using leetcode_154::leetcode_154;
using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test_153]", "[test_153]") {
    const vector<int32_t> input{3, 4, 5, 1, 2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}

TEST_CASE("2 [test_153]", "[test_153]") {
    const vector<int32_t> input{4, 5, 6, 7, 0, 1, 2};
    static constexpr const auto result{0};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}

TEST_CASE("3 [test_153]", "[test_153]") {
    const vector<int32_t> input{11, 13, 15, 17};
    static constexpr const auto result{11};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}


TEST_CASE("test case 4 [test_153]", "[test_153]") {
    const vector<int32_t> input{1, 2, 5};
    static constexpr const auto result{1};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}

TEST_CASE("test case 5 [test_153]", "[test_153]") {
    const vector<int32_t> input{2, 114, 514, 0, 1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_HPP

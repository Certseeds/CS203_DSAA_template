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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_41 {
using std::vector;

struct leetcode_41 {
    static int firstMissingPositive(vector<int32_t> &nums);

    static int firstMissingPositive2(vector<int32_t> &nums);
};

TEST_CASE("basic test [test_41]", "[test_41]") {
    const vector<int32_t> cinput{1, 2, 0};
    vector<int32_t> input{cinput};
    vector<int32_t> input2{cinput};
    const static constexpr auto result{3};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}

TEST_CASE("basic test 2 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{3, 4, -1, 1};
    vector<int32_t> input{cinput};
    vector<int32_t> input2{cinput};
    const static constexpr auto result{2};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}

TEST_CASE("basic test 3 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{7, 8, 9, 11, 12};
    vector<int32_t> input{cinput};
    vector<int32_t> input2{cinput};
    const static constexpr auto result{1};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}

TEST_CASE("basic test 4 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{1};
    vector<int32_t> input{cinput};
    vector<int32_t> input2{cinput};
    const static constexpr auto result{2};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}

TEST_CASE("basic test 6 [test_41]", "[test_41]") {
    const vector<int32_t> cinput{0, 1, 2};
    vector<int32_t> input{cinput};
    vector<int32_t> input2{cinput};
    const static constexpr auto result{3};
    CHECK(result == leetcode_41::firstMissingPositive(input));
    CHECK(result == leetcode_41::firstMissingPositive2(input2));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_41_HPP

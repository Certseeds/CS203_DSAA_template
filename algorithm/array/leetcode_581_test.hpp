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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_581 {
using std::vector;

struct leetcode_581 {
    static int32_t findUnsortedSubarray(const vector<int32_t> &nums);

    static int32_t findUnsortedSubarray2(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_581]", "[test_581]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    static constexpr const auto result{4};
    CHECK(result == leetcode_581::findUnsortedSubarray(input));
    CHECK(result == leetcode_581::findUnsortedSubarray2(input));
}

TEST_CASE("test case 2 [test_581]", "[test_581]") {
    const vector<int32_t> input{2, 6, 4, 8, 10, 9, 15};
    static constexpr const auto result{5};
    CHECK(result == leetcode_581::findUnsortedSubarray(input));
    CHECK(result == leetcode_581::findUnsortedSubarray2(input));
}

TEST_CASE("test case 3 [test_581]", "[test_581]") {
    const vector<int32_t> input{1, 2, 3, 4};
    static constexpr const auto result{0};
    CHECK(result == leetcode_581::findUnsortedSubarray(input));
    CHECK(result == leetcode_581::findUnsortedSubarray2(input));
}

TEST_CASE("test case 4 [test_581]", "[test_581]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_581::findUnsortedSubarray(input));
    CHECK(result == leetcode_581::findUnsortedSubarray2(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_581_TEST_HPP

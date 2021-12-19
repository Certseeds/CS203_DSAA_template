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
//@Tag 哈希表
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_map>

namespace leetcode_219 {
using std::vector;
using std::unordered_map;

struct leetcode_219 {
    static bool containsNearbyDuplicate(const vector <int32_t> &nums, int32_t k);
};

TEST_CASE("test case 1 [test_219]", "[test_219]") {
    const vector <int32_t> input{1, 2, 3, 1};
    static constexpr const auto k{3};
    CHECK(leetcode_219::containsNearbyDuplicate(input, k));
}

TEST_CASE("test case 2 [test_219]", "[test_219]") {
    const vector <int32_t> input{1, 0, 1, 1};
    static constexpr const auto k{1};
    CHECK(leetcode_219::containsNearbyDuplicate(input, k));
}

TEST_CASE("test case 3 [test_219]", "[test_219]") {
    const vector <int32_t> input{1, 2, 3, 1, 2, 3};
    static constexpr const auto k{2};
    CHECK_FALSE(leetcode_219::containsNearbyDuplicate(input, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_219_HPP
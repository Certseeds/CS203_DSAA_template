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

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_15_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_15_HPP

#include <catch_main.hpp>
#include <vector>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>

namespace leetcode_15 {
using std::vector;
using std::unordered_set;
using std::unordered_map;

struct leetcode_15 {
    static vector<vector<int32_t>> threeSum(vector<int32_t> &nums);
};

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("1 [test_15]", "[test_15]") {
    vector<int32_t> nums{-4, -1, -1, 0, 1, 2};
    auto output = leetcode_15::threeSum(nums);
    const vector<vector<int32_t>> results{{-1, 0,  1},
                                          {-1, -1, 2}};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("2 [test_15]", "[test_15]") {
    vector<int32_t> nums{};
    auto output = leetcode_15::threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("3 [test_15]", "[test_15]") {
    vector<int32_t> nums{0};
    auto output = leetcode_15::threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("8 [test_15]", "[test_15]") {
    vector<int32_t> nums{0, 0, 0};
    auto output = leetcode_15::threeSum(nums);
    const vector<vector<int32_t>> results{{0, 0, 0}};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("4 [test_15]", "[test_15]") {
    vector<int32_t> nums{-1, 0, 1, 2, -1, -4};
    auto output = leetcode_15::threeSum(nums);
    const vector<vector<int32_t>> results{{-1, 0,  1},
                                          {-1, -1, 2}};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("5 [test_15]", "[test_15]") {
    vector<int32_t> nums{};
    auto output = leetcode_15::threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("6 [test_15]", "[test_15]") {
    vector<int32_t> nums{0};
    auto output = leetcode_15::threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(output, UnorderedEquals(results));
}

TEST_CASE("7 [test_15]", "[test_15]") {
    vector<int32_t> nums{0, 0, 0};
    auto output = leetcode_15::threeSum(nums);
    const vector<vector<int32_t>> results{{0, 0, 0}};
    CHECK_THAT(output, UnorderedEquals(results));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_15_HPP

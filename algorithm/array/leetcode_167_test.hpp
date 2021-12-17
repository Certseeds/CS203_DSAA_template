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
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_map>

namespace leetcode_167 {
using std::vector;
using std::unordered_map;

struct leetcode_167 {
    static vector<int32_t> twoSum(const vector<int32_t> &numbers, int32_t target);

    static vector<int32_t> twoSum2(const vector<int32_t> &numbers, int32_t target);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test 167]", "[test 167]") {
    const vector<int32_t> input{2, 7, 11, 15};
    static constexpr const auto target{9};
    const vector<int32_t> result{1, 2};
    CHECK_THAT(leetcode_167::twoSum(input, target), Equals(result));
    CHECK_THAT(leetcode_167::twoSum2(input, target), Equals(result));
}

TEST_CASE("test case 2 [test 167]", "[test 167]") {
    const vector<int32_t> input{2, 3, 4};
    static constexpr const auto target{6};
    const vector<int32_t> result{1, 3};
    CHECK_THAT(leetcode_167::twoSum(input, target), Equals(result));
    CHECK_THAT(leetcode_167::twoSum2(input, target), Equals(result));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_167_HPP

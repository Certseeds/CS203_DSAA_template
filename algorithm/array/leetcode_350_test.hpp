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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <unordered_map>

namespace leetcode_350 {
using std::vector;
using std::unordered_map;

struct leetcode_350 {
    static vector<int32_t> intersect(const vector<int32_t> &nums1, const vector<int32_t> &nums2);
};

using Catch::Matchers::UnorderedEquals;
TEST_CASE("test case 1 [test_350]", "[test_350]") {
    const vector<int32_t> input1{1, 2, 2, 1}, input2{2, 2};
    const vector<int32_t> result{2, 2};
    CHECK_THAT(result, UnorderedEquals(leetcode_350::intersect(input1, input2)));
}

TEST_CASE("test case 2 [test_350]", "[test_350]") {
    const vector<int32_t> input1{4, 9, 5}, input2{9, 4, 9, 8, 4};
    const vector<int32_t> result{4, 9};
    CHECK_THAT(result, UnorderedEquals(leetcode_350::intersect(input1, input2)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_350_HPP

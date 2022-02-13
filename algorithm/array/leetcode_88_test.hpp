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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_88_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_88_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_88 {
using std::vector;

struct leetcode_88 {
    static void merge(vector<int32_t> &nums1, int32_t m,const vector<int32_t> &nums2, int32_t n);
};

using Catch::Matchers::Equals;

TEST_CASE("cases [test_88]", "[test_88]") {
    vector<int32_t> vec1{};
    vector<int32_t> vec2{};
    vector<int32_t> result{};
    GIVEN("given [test_88]") {
        THEN("test_case 1 [test_88]") {
            vec1 = {4, 5, 6, 0, 0, 0};
            vec2 = {1, 2, 3};
            result = {1, 2, 3, 4, 5, 6};
        }THEN("test_case 2 [test_88]") {
            vec1 = {1, 2, 3, 0, 0, 0};
            vec2 = {2, 5, 6};
            result = {1, 2, 2, 3, 5, 6};
        }THEN("test_case 3 [test_88]") {
            vec1 = {2, 0};
            vec2 = {1};
            result = {1, 2};
        }THEN("test_case 4 [test_88]") {
            vec1 = {0};
            vec2 = {1};
            result = {1};
        }THEN("test_case 5 [test_88]") {
            vec1 = {1};
            result = {1};
        }
        leetcode_88::merge(vec1, vec1.size() - vec2.size(), vec2, vec2.size());
        CHECK_THAT(vec1, Equals(result));
    }
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_88_HPP

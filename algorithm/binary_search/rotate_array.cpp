/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-08-01 17:39:45 
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template 

Copyright (C) 2020  nanoseeds

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
// refer https://leetcode-cn.com/problems/rotate-array/
// 189
#include <algorithm>
#include <vector>

#include "catch_main.hpp"

using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using std::tie;
using std::tuple;
using std::vector;

// nums 一个有序数组, 集体右移k个位置(k>=0)
// [first,last] !!
int rorate_array_min(vector<int32_t> &nums, int32_t first, int32_t last) {
    while (first < last) {
        int middle = (last - first) / 2 + first;
        if (nums[middle] > nums[last]) {
            first = middle + 1;
        } else if (nums[middle] < nums[last]) {
            last = middle;
        } else {
            last--;
        }
    }
    return nums[first];
}

TEST_CASE("test case 1", "[test binary search - rotate_array_min]") {
    vector<int32_t> vec{3, 4, 5, 1, 2};
    CHECK(*std::min_element(std::begin(vec), std::end(vec)) == rorate_array_min(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 2", "[test binary search - rotate_array_min]") {
    vector<int32_t> vec{2, 2, 2, 0, 1};
    CHECK(*std::min_element(std::begin(vec), std::end(vec)) == rorate_array_min(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 3", "[test binary search - rotate_array_min]") {
    vector<int32_t> vec{1, 3, 5};
    CHECK(*std::min_element(std::begin(vec), std::end(vec)) == rorate_array_min(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 4", "[test binary search - rotate_array_min]") {
    vector<int32_t> vec{3, 3, 1, 3};
    CHECK(*std::min_element(std::begin(vec), std::end(vec)) == rorate_array_min(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 5", "[test binary search - rotate_array_min]") {
    vector<int32_t> vec{3, 1};
    CHECK(*std::min_element(std::begin(vec), std::end(vec)) == rorate_array_min(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 6", "[test binary search - rotate_array_min]") {
    vector<int32_t> vec{3, 1, 3};
    CHECK(*std::min_element(std::begin(vec), std::end(vec)) == rorate_array_min(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 7", "[test binary search - rotate_array_min]") {
    vector<int32_t> vec{5, 6, 7, 1, 2, 3, 4};
    CHECK(*std::min_element(std::begin(vec), std::end(vec)) == rorate_array_min(vec, 0, vec.size() - 1));
}

TEST_CASE("test case 8", "[test binary search - rotate_array_min]") {
    vector<int32_t> vec{-1, -100, 3, 99};
    CHECK(*std::min_element(std::begin(vec), std::end(vec)) == rorate_array_min(vec, 0, vec.size() - 1));
}
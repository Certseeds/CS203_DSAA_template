/*
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanoseeds
 * @Date: 2020-08-01 17:39:45
 * @LastEditors: nanoseeds
 * @LICENSE: MIT
 */
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
// refer https://leetcode-cn.com/problems/rotate-array/
// 189
#include <catch_main.hpp>
#include <algorithm>
#include <vector>


using Catch::Matchers::Contains;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using std::tie;
using std::tuple;
using std::vector;
using num_t = int32_t;

// nums 一个有序数组, 集体右移k个位置(k>=0)
// [first,last] !!
void reserve(vector<num_t> &nums, num_t first, num_t last) {
    while (first <= last) {
        std::swap(nums[first], nums[last]);
        first++;
        last--;
    }
}

void rorate_array_min(vector<num_t> &nums, num_t k) {
    if (0 == k) {
        return;
    }
    k = k % nums.size();
    const auto nums_size = nums.size();
    reserve(nums, 0, nums_size - 1);
    reserve(nums, 0, k - 1);
    reserve(nums, k, nums_size - 1);
}

void brute_force(vector<num_t> &nums, num_t k) {
    if (0 == k) {
        return;
    }
    k = k % nums.size();
    vector<num_t> backend(k, 0);
    for (auto i = 0; i < k; i++) {
        backend[k - i - 1] = nums.back();
        nums.pop_back();
    }
    for (auto iter = backend.rbegin(); iter != backend.rend(); iter++) {
        nums.insert(nums.begin(), *iter);
    }
}

TEST_CASE("test case `for`", "[test binary search - rotate_array_min]") {
    vector<vector<num_t>> vec_list{
            {3,  1},
            {1,  3,    5},
            {3,  1,    3},
            {3,  3,    1, 3},
            {3,  4,    5, 1, 2},
            {2,  2,    2, 0, 1},
            {5,  6,    7, 1, 2, 3, 4},
            {-1, -100, 3, 99},
    };
    for (auto &vec: vec_list) {
        for (auto i = 0u; i < vec.size() * 2 + 1; i++) {
            vector<num_t> vec_2{vec};
            brute_force(vec, i);
            rorate_array_min(vec_2, i);
            CHECK_THAT(vec, Equals(vec_2));
        }
    }
}
/**
 * @Github: https://github.com/Certseeds/CS203_DSAA_template
 * @Author: nanos
 * @Date: 2021-09-07 00:08:19
 * @LastEditors: nanos
 * @LICENSE: MIT
 */
/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanos

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
// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一
namespace binary_search::lc35 {
int searchInsert(const vector<int> &nums, int target) {
    const auto n_size = static_cast<int32_t>(nums.size());
    if (nums.empty() || target < nums.front()) {
        return 0; // 放到第一个
    } else if (nums.back() < target) {
        return n_size; // 放到最后一个
    }
    int32_t left{0}, right{n_size - 1}, middle{0};
    while (left < right) {
        middle = (right - left) / 2 + left; // 避免溢出
        if (nums[middle] > target) {
            right = middle;
        } else if (nums[middle] < target) {
            left = middle + 1;// 只有一处+1
        } else {
            return middle;
        }
    }
    return left;
}

}
namespace binary_search::lc35 {
TEST_CASE("test case 1", "[test lc35]") {
    CHECK(2 == searchInsert(vector<int32_t>{1, 3, 5, 6}, 5));
}

TEST_CASE("test case 2", "[test lc35]") {
    CHECK(1 == searchInsert(vector<int32_t>{1, 3, 5, 6}, 2));
}

TEST_CASE("test case 3", "[test lc35]") {
    CHECK(4 == searchInsert(vector<int32_t>{1, 3, 5, 6}, 7));
}

TEST_CASE("test case 4", "[test lc35]") {
    CHECK(0 == searchInsert(vector<int32_t>{1, 3, 5, 6}, 0));
}

TEST_CASE("test case 5", "[test lc35]") {
    CHECK(0 == searchInsert(vector<int32_t>{1}, 0));
}
}
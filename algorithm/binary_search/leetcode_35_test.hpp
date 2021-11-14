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
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_HPP

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

namespace binary_search::leetcode_35 {
struct leetcode_35 final {
    static int searchInsert(const vector<int> &nums, int target);

    static int searchInsert2(const vector<int> &nums, int target);
};

TEST_CASE("test case 1", "[test leetcode_35]") {
    const vector<int32_t> input{1, 3, 5, 6};
    static constexpr const auto target{5}, result{2};
    CHECK(result == leetcode_35::searchInsert(input, target));
    CHECK(result == leetcode_35::searchInsert2(input, target));
}

TEST_CASE("test case 2", "[test leetcode_35]") {
    const vector<int32_t> input{1, 3, 5, 6};
    static constexpr const auto target{2}, result{1};
    CHECK(result == leetcode_35::searchInsert(input, target));
    CHECK(result == leetcode_35::searchInsert2(input, target));
}

TEST_CASE("test case 3", "[test leetcode_35]") {
    const vector<int32_t> input{1, 3, 5, 6};
    static constexpr const auto target{7}, result{4};
    CHECK(result == leetcode_35::searchInsert(input, target));
    CHECK(result == leetcode_35::searchInsert2(input, target));
}

TEST_CASE("test case 4", "[test leetcode_35]") {
    const vector<int32_t> input{1, 3, 5, 6};
    static constexpr const auto target{0}, result{0};
    CHECK(result == leetcode_35::searchInsert(input, target));
    CHECK(result == leetcode_35::searchInsert2(input, target));
}

TEST_CASE("test case 5", "[test leetcode_35]") {
    const vector<int32_t> input{1};
    static constexpr const auto target{0}, result{0};
    CHECK(result == leetcode_35::searchInsert(input, target));
    CHECK(result == leetcode_35::searchInsert2(input, target));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_HPP


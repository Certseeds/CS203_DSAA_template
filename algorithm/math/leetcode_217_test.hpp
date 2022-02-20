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
//@Tag list
//@Tag 链表
//@Plan 数据结构入门 Day1
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_217_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_217_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>
#include <vector>

namespace leetcode_217 {
using std::vector;

struct leetcode_217 {
    static bool containsDuplicate(const vector<int32_t> &nums);
};

TEST_CASE("1 [test_217]", "[test_217]") {
    const vector<int32_t> input{3, 4, 3};
    CHECK(leetcode_217::containsDuplicate(input));
}

TEST_CASE("2 [test_217]", "[test_217]") {
    const vector<int32_t> input{1, 0, 1, 1, 0, 1};
    CHECK(leetcode_217::containsDuplicate(input));
}

TEST_CASE("3 [test_217]", "[test_217]") {
    const vector<int32_t> input{1};
    CHECK_FALSE(leetcode_217::containsDuplicate(input));
}

TEST_CASE("4 [test_217]", "[test_217]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4, 1, 9, 1};
    CHECK(leetcode_217::containsDuplicate(input));
}

TEST_CASE("5 [test_217]", "[test_217]") {
    const vector<int32_t> input{2, 2, 1, 1, 1, 2, 2};
    CHECK(leetcode_217::containsDuplicate(input));
}

TEST_CASE("6 [test_217]", "[test_217]") {
    const vector<int32_t> input{1, 2, 3, 4};
    CHECK_FALSE(leetcode_217::containsDuplicate(input));
}

TEST_CASE("7 [test_217]", "[test_217]") {
    const vector<int32_t> input{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    CHECK(leetcode_217::containsDuplicate(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_217_TEST_HPP


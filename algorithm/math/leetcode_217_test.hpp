// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

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


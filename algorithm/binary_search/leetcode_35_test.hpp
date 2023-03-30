// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
// 实质上是寻找第一个大于等于target的数字的下标
// 如果目标不存在,则返回第一个大于其的位置减一

namespace binary_search::leetcode_35 {
using std::vector;
using num_t = int32_t;

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_35_TEST_HPP


// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanos

*/
//@Tag array
//@Tag 数组
//@Tag binary search
//@Tag 二分
//@Level Mid
//@Sword-Offer 11
//@Plan 剑指OfferII-I Day05
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_TEST_HPP

#include <catch_main.hpp>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode_153 {
using std::vector;

struct leetcode_153 final {
    static int32_t findMin(const vector<int32_t> &nums);
};
}
namespace leetcode_154 {
using std::vector;

struct leetcode_154 final {
    static int32_t findMin(const vector<int32_t> &nums);
};

TEST_CASE("test case 2 [test_154]", "[test_154]") {
    const vector<int32_t> input{2, 2, 2, 0, 1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_154::findMin(input));
}
}
namespace leetcode_153_154 {
using std::vector;
using leetcode_153::leetcode_153;
using leetcode_154::leetcode_154;

TEST_CASE("1 [test_153]", "[test_153]") {
    const vector<int32_t> input{3, 4, 5, 1, 2};
    static constexpr const auto result{1};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}

TEST_CASE("2 [test_153]", "[test_153]") {
    const vector<int32_t> input{4, 5, 6, 7, 0, 1, 2};
    static constexpr const auto result{0};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}

TEST_CASE("3 [test_153]", "[test_153]") {
    const vector<int32_t> input{11, 13, 15, 17};
    static constexpr const auto result{11};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}


TEST_CASE("test case 4 [test_153]", "[test_153]") {
    const vector<int32_t> input{1, 2, 5};
    static constexpr const auto result{1};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}

TEST_CASE("test case 5 [test_153]", "[test_153]") {
    const vector<int32_t> input{2, 114, 514, 0, 1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_153::findMin(input));
    CHECK(result == leetcode_154::findMin(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_BINARY_SEARCH_LEETCODE_TEST_153_TEST_HPP

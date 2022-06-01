// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container
//@Tag arrays as hashmap
//@Tag 自定义hash函数
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_893_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_893_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_893 {
using std::vector;

struct leetcode_893 {
    static int32_t numSpecialEquivGroups(const vector<string> &words);
};

TEST_CASE("test case 1 {test_893}", "{test_893}") {
    static constexpr const std::array<const char *const, 6> input{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    static constexpr const auto result{6};
    CHECK(result == leetcode_893::numSpecialEquivGroups({input.cbegin(), input.cend()}));
}

TEST_CASE("test case 2 {test_893}", "{test_893}") {
    static constexpr const std::array<const char *const, 6> input{"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"};
    static constexpr const auto result{3};
    CHECK(result == leetcode_893::numSpecialEquivGroups({input.cbegin(), input.cend()}));
}

TEST_CASE("test case 3 {test_893}", "{test_893}") {
    static constexpr const std::array<const char *const, 6> input{"abc", "acb", "bac", "bca", "cab", "cba"};
    static constexpr const auto result{3};
    CHECK(result == leetcode_893::numSpecialEquivGroups({input.cbegin(), input.cend()}));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_893_TEST_HPP

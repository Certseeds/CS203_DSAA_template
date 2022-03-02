// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Description 自定义比较函数
//@Plan 剑指OfferII-I Day16
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_45_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_45_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_so_45 {
using std::vector;
using std::string;

struct leetcode_so_45 {
    static string minNumber(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_so_45]", "[test_so_45]") {
    const vector<int32_t> input{10, 2};
    static constexpr const char *const output{"102"};
    CHECK(output == leetcode_so_45::minNumber(input));
}

TEST_CASE("test case 2 [test_so_45]", "[test_so_45]") {
    const vector<int32_t> input{3, 30, 34, 5, 9};
    static constexpr const char *const output{"3033459"};
    CHECK(output == leetcode_so_45::minNumber(input));
}

TEST_CASE("test case 3 [test_so_45]", "[test_so_45]") {
    const vector<int32_t> input{12, 121};
    static constexpr const char *const output{"12112"};
    CHECK(output == leetcode_so_45::minNumber(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_45_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container
//@Tag arrays as hashmap
//@Tag 自定义hash函数
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_914_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_914_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_914 {
using std::vector;

struct leetcode_914 {
    static bool hasGroupsSizeX(const vector<int32_t> &deck);
};


TEST_CASE("test case 1 {test_914}", "{test_914}") {
    const vector<int32_t> input{1, 2, 3, 4, 4, 3, 2, 1};
    CHECK(leetcode_914::hasGroupsSizeX(input));
}

TEST_CASE("test case 2 {test_914}", "{test_914}") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    CHECK_FALSE(leetcode_914::hasGroupsSizeX(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_914_TEST_HPP

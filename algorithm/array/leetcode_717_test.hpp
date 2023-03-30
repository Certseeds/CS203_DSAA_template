// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_717 {
using std::vector;

struct leetcode_717 {
    static bool isOneBitCharacter(const vector<int32_t> &bits);
};

TEST_CASE("test case 1 [test_717]", "[test_717]") {
    const vector<int32_t> input{1, 0, 0};
    CHECK(leetcode_717::isOneBitCharacter(input));
}

TEST_CASE("test case 2 [test_717]", "[test_717]") {
    const vector<int32_t> input{1, 1, 1, 0};
    CHECK_FALSE(leetcode_717::isOneBitCharacter(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_717_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_665_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_665_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_665 {
using std::vector;

struct leetcode_665 {
    static bool checkPossibility(const vector<int32_t> &nums);
};


using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_665]", "[test_665]") {
    const vector<int32_t> input{4, 2, 3};
    CHECK(leetcode_665::checkPossibility(input));
}

TEST_CASE("test case 2 [test_665]", "[test_665]") {
    const vector<int32_t> input{4, 2, 1};
    CHECK_FALSE(leetcode_665::checkPossibility(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_665_TEST_HPP

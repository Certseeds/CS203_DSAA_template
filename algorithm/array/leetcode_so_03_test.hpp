// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
//@Tag 暴力解法
//@Plan 剑指OfferII-I Day04
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_so_03 {
using std::vector;

struct leetcode_so_03 {
    static int32_t findRepeatNumber(const vector<int32_t> &nums);

    static int32_t findRepeatNumber2(const vector<int32_t> &nums);

    static int32_t findRepeatNumber3(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 [test_so_03]", "[test_so_03]") {
    const vector<int32_t> input{1, 2, 2, 3, 1};
    static constexpr const auto resultOne{1}, resultTwo{2};
    CHECK(resultOne == leetcode_so_03::findRepeatNumber(input));
    CHECK(resultTwo == leetcode_so_03::findRepeatNumber2(input));
    CHECK(resultTwo == leetcode_so_03::findRepeatNumber3(input));
}

TEST_CASE("test case 2 [test_so_03]", "[test_so_03]") {
    const vector<int32_t> input{2, 3, 1, 0, 2, 5, 3};
    static constexpr const auto resultOne{2}
    //, resultTwo{3}
    ;
    CHECK(resultOne == leetcode_so_03::findRepeatNumber(input));
    CHECK(resultOne == leetcode_so_03::findRepeatNumber2(input));
    CHECK(resultOne == leetcode_so_03::findRepeatNumber3(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_SO_03_TEST_HPP

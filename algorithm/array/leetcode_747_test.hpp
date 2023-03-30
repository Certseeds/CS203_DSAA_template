// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_747_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_747_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_747 {
using std::vector;

struct leetcode_747 {
    static int32_t dominantIndex(const vector<int32_t> &nums);
};

TEST_CASE("test case 2 [test_747]", "[test_747]") {
    const vector<int32_t> input{1, 2, 3, 4};
    static constexpr const auto result{-1};
    CHECK(result == leetcode_747::dominantIndex(input));
}
TEST_CASE("test case 1 [test_747]", "[test_747]") {
    const vector<int32_t> input{3, 6, 1, 0};
    static constexpr const auto result{1};
    CHECK(result == leetcode_747::dominantIndex(input));
}


TEST_CASE("test case 3 [test_747]", "[test_747]") {
    const vector<int32_t> input{1};
    static constexpr const auto result{0};
    CHECK(result == leetcode_747::dominantIndex(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_747_TEST_HPP

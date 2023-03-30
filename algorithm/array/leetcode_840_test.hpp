// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_840_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_840_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_840 {
using std::vector;

struct leetcode_840 {
    static int numMagicSquaresInside(const vector<vector<int>> &grid);
};

TEST_CASE("test case 1 [test_840]", "[test_840]") {
    const vector<vector<int32_t>> inputs{{4, 3, 8, 4},
                                         {9, 5, 1, 9},
                                         {2, 7, 6, 2}};
    static constexpr const auto result{1};
    CHECK(result == leetcode_840::numMagicSquaresInside(inputs));
}

TEST_CASE("test case 2 [test_840]", "[test_840]") {
    const vector<vector<int32_t>> inputs{{8}};
    static constexpr const auto result{0};
    CHECK(result == leetcode_840::numMagicSquaresInside(inputs));
}

TEST_CASE("test case 3 [test_840]", "[test_840]") {
    const vector<vector<int32_t>> inputs{{1, 1, 4},
                                         {5, 1, 4}};
    static constexpr const auto result{0};
    CHECK(result == leetcode_840::numMagicSquaresInside(inputs));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_840_TEST_HPP

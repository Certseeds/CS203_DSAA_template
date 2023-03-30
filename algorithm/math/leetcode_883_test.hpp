// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_883_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_883_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_883 {
using std::vector;

struct leetcode_883 {
    static int32_t projectionArea(const vector<vector<int32_t>> &grid);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_883]", "[test_883]") {
    const vector<vector<int32_t>> input{{1, 2}, {3, 4}};
    static constexpr const auto output{17};
    CHECK(output == leetcode_883::projectionArea(input));
}

TEST_CASE("2 [test_883]", "[test_883]") {
    const vector<vector<int32_t>> input{{2}};
    static constexpr const auto output{5};
    CHECK(output == leetcode_883::projectionArea(input));
}

TEST_CASE("3 [test_883]", "[test_883]") {
    const vector<vector<int32_t>> input{{1, 0}, {0, 2}};
    static constexpr const auto output{8};
    CHECK(output == leetcode_883::projectionArea(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_883_TEST_HPP


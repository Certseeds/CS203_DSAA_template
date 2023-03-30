// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag DFS
//@Tag 深度优先遍历
//@Plan 剑指OfferII-I Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_so_13 {

struct leetcode_so_13 {
    static int32_t movingCount(int32_t m, int32_t n, int32_t k);
};

TEST_CASE("basic tests [test_so_13]", "[test_so_13]") {
    static constexpr const auto m{2}, n{3}, k{1};
    static constexpr const auto result{3};
    CHECK(result == leetcode_so_13::movingCount(m, n, k));
}

TEST_CASE("basic tests 2 [test_so_13]", "[test_so_13]") {
    static constexpr const auto m{3}, n{1}, k{0};
    static constexpr const auto result{1};
    CHECK(result == leetcode_so_13::movingCount(m, n, k));
}

TEST_CASE("basic tests 3 [test_so_13]", "[test_so_13]") {
    static constexpr const auto m{1}, n{2}, k{1};
    static constexpr const auto result{2};
    CHECK(result == leetcode_so_13::movingCount(m, n, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_13_TEST_HPP

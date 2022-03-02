// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_743 {
using std::vector;

struct leetcode_743 {
    static int32_t networkDelayTime(const vector<vector<int32_t>> &times, int32_t n, int32_t k);
};

TEST_CASE("basic tests [test_743]", "[test_743]") {
    const vector<vector<int32_t>> input{
            {2, 1, 1},
            {2, 3, 1},
            {3, 4, 1}
    };
    static constexpr const auto n{4}, k{2};
    static constexpr const auto result{2};
    CHECK(result == leetcode_743::networkDelayTime(input, n, k));
}

TEST_CASE("basic tests 2[test_743]", "[test_743]") {
    const vector<vector<int32_t>> input{
            {1, 2, 1},
    };
    static constexpr const auto n{2}, k{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_743::networkDelayTime(input, n, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_743_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag disjoint_set
//@Tag 深度优先搜索
//@Tag DFS
//@Tag 广度优先搜索
//@Tag BFS

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_130 {
using std::vector;
enum GRID : char {
    WATER = 'X',
    LAND = 'O',
    KEEP_LAND = 'K',
};

struct leetcode_130 {
    static void solve(vector<vector<char>> &board);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_130]", "[test_130]") {
    vector<vector<char>> edges{
            {WATER, WATER, WATER, WATER},
            {WATER, LAND,  LAND,  WATER},
            {WATER, WATER, LAND,  WATER},
            {WATER, LAND,  WATER, WATER},
    };
    const vector<vector<char>> results{
            {WATER, WATER, WATER, WATER},
            {WATER, WATER, WATER, WATER},
            {WATER, WATER, WATER, WATER},
            {WATER, LAND,  WATER, WATER},
    };
    leetcode_130::solve(edges);
    CHECK_THAT(results, Equals(edges));
}

TEST_CASE("2 [test_130]", "[test_130]") {
    vector<vector<char>> edges{
            {WATER}
    };
    const vector<vector<char>> results{
            {WATER}
    };
    leetcode_130::solve(edges);
    CHECK_THAT(results, Equals(edges));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_130_TEST_CPP

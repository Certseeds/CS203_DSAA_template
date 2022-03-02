// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag disjoint_set
//@Tag 并查集
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_200_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_200_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_200 {
using std::vector;
enum GRID : char {
    WATER = '0',
    LAND = '1'
};

struct leetcode_200 {
    static int numIslands(const vector<vector<char>> &grid);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_200]", "[test_200]") {
    vector<vector<char>> edges{
            {LAND,  LAND,  LAND,  LAND,  WATER},
            {LAND,  LAND,  WATER, LAND,  WATER},
            {LAND,  LAND,  WATER, WATER, WATER},
            {WATER, WATER, WATER, WATER, WATER},
    };
    static constexpr const auto result{1};
    CHECK(result == leetcode_200::numIslands(edges));

}

TEST_CASE("2 [test_200]", "[test_200]") {
    const vector<vector<char>> edges{
            {LAND,  LAND,  WATER, WATER, WATER},
            {LAND,  LAND,  WATER, WATER, WATER},
            {WATER, WATER, LAND,  WATER, WATER},
            {WATER, WATER, WATER, LAND,  LAND}
    };
    static constexpr const auto result{3};
    CHECK(result == leetcode_200::numIslands(edges));
}

TEST_CASE("3 [test_200]", "[test_200]") {
    const vector<vector<char>> edges{
            {LAND,  WATER, WATER},
            {WATER, WATER, WATER},
            {WATER, WATER, LAND}
    };
    static constexpr const auto result{2};
    CHECK(result == leetcode_200::numIslands(edges));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_200_TEST_CPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_797_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_797_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_797 {
using std::vector;

struct leetcode_797 {
    static vector<vector<int32_t>> allPathsSourceTarget(const vector<vector<int32_t>> &graph);

    static vector<vector<int32_t>> allPathsSourceTarget2(const vector<vector<int32_t>> &graph);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic tests [test_797]", "[test_797]") {
    const vector<vector<int32_t>> input{
            {4, 3, 1},
            {3, 2, 4},
            {3},
            {4},
            {}
    };
    const vector<vector<int32_t>> result{
            {0, 4},
            {0, 3, 4},
            {0, 1, 3, 4},
            {0, 1, 2, 3, 4},
            {0, 1, 4}
    };
    CHECK_THAT(result, UnorderedEquals(leetcode_797::allPathsSourceTarget(input)));
    CHECK_THAT(result, UnorderedEquals(leetcode_797::allPathsSourceTarget2(input)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_797_TEST_HPP

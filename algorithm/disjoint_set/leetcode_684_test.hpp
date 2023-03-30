// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanos

*/
//@Tag disjoint_set
//@Tag 并查集
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_684 {
using std::vector;

struct leetcode_684 {
    static vector<int> findRedundantConnection(const vector<vector<int>> &edges);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_684]", "[test_684]") {
    const vector<vector<int32_t>> edges{{1, 2},
                                        {1, 3},
                                        {2, 3}};
    const vector<int32_t> results{2, 3};
    CHECK_THAT(leetcode_684::findRedundantConnection(edges), Equals(results));
}

TEST_CASE("2 [test_684]", "[test_684]") {
    const vector<vector<int32_t>> edges{{1, 2},
                                        {2, 3},
                                        {3, 4},
                                        {1, 4},
                                        {1, 5}};
    const vector<int32_t> results{1, 4};
    CHECK_THAT(leetcode_684::findRedundantConnection(edges), Equals(results));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_DP_LEETCODE_684_TEST_CPP

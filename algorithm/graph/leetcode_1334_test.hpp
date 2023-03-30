// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_1334_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_1334_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1334 {
using std::vector;

namespace leetcode_1334 {
int32_t findTheCity(int32_t n, const vector<vector<int32_t>> &edges, int32_t distanceThreshold);
}

using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic tests [test_1334]", "[test_1334]") {
    const vector<vector<int32_t>> vec{
            {0, 1, 3},
            {1, 2, 1},
            {1, 3, 4},
            {2, 3, 1},
    };
    constexpr const auto n{4}, distanceThreshold{4};
    CHECK(3 == leetcode_1334::findTheCity(n, vec, distanceThreshold));
}

TEST_CASE("basic tests 2 [test_1334]", "[test_1334]") {
    const vector<vector<int32_t>> vec{
            {0, 1, 2},
            {0, 4, 8},
            {1, 2, 3},
            {1, 4, 2},
            {2, 3, 1},
            {3, 4, 1},
    };
    constexpr const auto n{5}, distanceThreshold{2};
    CHECK(0 == leetcode_1334::findTheCity(n, vec, distanceThreshold));
}

TEST_CASE("basic tests 3 [test_1334]", "[test_1334]") {
    const vector<vector<int32_t>> vec{
            {0, 2, 3996},
            {0, 3, 7495},
            {0, 4, 5966},
            {0, 5, 3399},
            {0, 6, 6},
            {0, 7, 2904},
            {1, 2, 1079},
            {1, 4, 2262},
            {1, 5, 6327},
            {1, 6, 2458},
            {1, 7, 7782},
            {2, 6, 1390},
            {3, 4, 7284},
            {3, 7, 2336},
            {4, 5, 5055},
            {4, 6, 2857},
            {4, 7, 7558},
            {5, 7, 2870},
            {6, 7, 2202},
    };
    constexpr const auto n{8}, distanceThreshold{7937};
    CHECK(7 == leetcode_1334::findTheCity(n, vec, distanceThreshold));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_1334_TEST_HPP

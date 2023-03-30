// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag associative_container

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1128 {
using std::vector;

struct leetcode_1128 {
    static int32_t numEquivDominoPairs(const vector<vector<int32_t>> &dominoes);
};

TEST_CASE("test case 1 {test_1128}", "{test_1128}") {
    const vector<vector<int32_t>> input{{1, 2},
                                        {2, 1},
                                        {3, 4},
                                        {5, 6}};
    CHECK(1 == leetcode_1128::numEquivDominoPairs(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_1128_TEST_HPP

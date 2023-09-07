// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1391_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1391_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_1371 {
using std::vector;

namespace leetcode_1371 {
bool hasValidPath(vector<vector<int32_t>> &grid);
}

TEST_CASE("test case 1-1 {test_1371}", "{test_1371}") {
    vector<vector<int32_t>> input{
            {2, 4, 3},
            {6, 5, 2},
    };
    CHECK(leetcode_1371::hasValidPath(input));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1391_TEST_HPP

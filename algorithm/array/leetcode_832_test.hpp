// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_832_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_832_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_832 {
using std::vector;

struct leetcode_832 {
    static vector<vector<int32_t>> flipAndInvertImageConst(const vector<vector<int32_t>> &image);

};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_832]", "[test_832]") {
    const vector<vector<int32_t>> inputs{{1, 1, 0},
                                         {1, 0, 1},
                                         {0, 0, 0}};
    const vector<vector<int32_t>> result{
            {1, 0, 0},
            {0, 1, 0},
            {1, 1, 1},
    };
    CHECK_THAT(result, Equals(leetcode_832::flipAndInvertImageConst(inputs)));
}

TEST_CASE("test case 2 [test_832]", "[test_832]") {
    const vector<vector<int32_t>> inputs{{1, 1, 0, 0},
                                         {1, 0, 0, 1},
                                         {0, 1, 1, 1},
                                         {1, 0, 1, 0}
    };
    const vector<vector<int32_t>> result{
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {1, 0, 1, 0}
    };
    CHECK_THAT(result, Equals(leetcode_832::flipAndInvertImageConst(inputs)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_832_TEST_HPP

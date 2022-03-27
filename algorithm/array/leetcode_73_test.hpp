// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组
//@Plan 数据结构入门 Day5

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_73_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_73_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_73 {
using std::vector;

struct leetcode_73 {
    static void setZeroes(vector<vector<int32_t>> &matrix);

    static vector<vector<int32_t>> getZeroes(const vector<vector<int32_t>> &matrix) {
        vector<vector<int32_t>> will_return{matrix};
        setZeroes(will_return);
        return will_return;
    }
};

using Catch::Matchers::Equals;

TEST_CASE("basic test 3 [test_73]") {
    const vector<vector<int32_t>> vec1{
            {1,  2,  3,  4},
            {5,  0,  7,  8},
            {0,  10, 11, 12},
            {13, 14, 15, 0}
    };
    const vector<vector<int32_t>> result{
            {0, 0, 3, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
    };
    CHECK_THAT(result, Equals(leetcode_73::getZeroes(vec1)));
}

TEST_CASE("basic test [test_73]", "[test_73]") {
    const vector<vector<int32_t>> vec1{
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1},
    };
    const vector<vector<int32_t>> result{
            {1, 0, 1},
            {0, 0, 0},
            {1, 0, 1},
    };
    CHECK_THAT(result, Equals(leetcode_73::getZeroes(vec1)));
}

TEST_CASE("basic test 2[test_73]", "[test_73]") {
    const vector<vector<int32_t>> vec1{
            {0, 1, 2, 0},
            {1, 1, 4, 5},
            {1, 3, 1, 5},
    };
    const vector<vector<int32_t>> result{
            {0, 0, 0, 0},
            {0, 1, 4, 0},
            {0, 3, 1, 0},
    };
    CHECK_THAT(result, Equals(leetcode_73::getZeroes(vec1)));
}

TEST_CASE("basic test 4[test_73]", "[test_73]") {
    const vector<vector<int32_t>> vec1{
            {-4,         std::numeric_limits<int32_t>::min(), 6,  -7, 0},
            {-8,         6,                                   -8, -6, 0},
            {2147483647, 2,                                   -9, -6, -10}
    };
    const vector<vector<int32_t>> result{
            {0,          0, 0,  0,  0},
            {0,          0, 0,  0,  0},
            {2147483647, 2, -9, -6, 0}
    };
    CHECK_THAT(result, Equals(leetcode_73::getZeroes(vec1)));
}


}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_73_TEST_HPP

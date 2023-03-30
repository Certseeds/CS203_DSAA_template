// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_985_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_985_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_985 {
using std::vector;

struct leetcode_985 {
    static vector<int32_t> sumEvenAfterQueries(const vector<int32_t> &nums, const vector<vector<int32_t>> &queries);
};


using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_985}", "{test_985}") {
    const vector<int32_t> input{1, 2, 3, 4};
    const vector<vector<int32_t>> queries{
            {1, 0},
            {-3, 1},
            {-4, 0},
            {2, 3},
    };
    const vector<int32_t> result{8, 6, 2, 4};
    CHECK_THAT(result, Equals(leetcode_985::sumEvenAfterQueries(input, queries)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_985_TEST_HPP

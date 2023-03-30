// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_40_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_40_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_40 {
using std::vector;

struct leetcode_40 {
    static vector<vector<int32_t>> combinationSum2(const vector<int32_t> &candidates, int target);
};


using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("basic test [test_40]", "[test_40]") {
    const vector<int32_t> candidates{10, 1, 2, 7, 6, 1, 5};
    const static constexpr auto target{8};
    const vector<vector<int32_t>> results{{1, 1, 6},
                                          {1, 2, 5},
                                          {1, 7},
                                          {2, 6}};
    CHECK_THAT(results, UnorderedEquals(leetcode_40::combinationSum2(candidates, target)));
}

TEST_CASE("basic test 2[test_40]", "[test_40]") {
    const vector<int32_t> candidates{2, 5, 2, 1, 2};
    const static constexpr auto target{5};
    const vector<vector<int32_t>> results{{1, 2, 2},
                                          {5}};
    CHECK_THAT(results, UnorderedEquals(leetcode_40::combinationSum2(candidates, target)));
}

TEST_CASE("basic test 3[test_40]", "[test_40]") {
    const vector<int32_t> candidates{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    const static constexpr auto target{30};
    const vector<vector<int32_t>> results{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,}};
    CHECK_THAT(results, UnorderedEquals(leetcode_40::combinationSum2(candidates, target)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_40_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag array
//@Tag 数组

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_39 {
using std::vector;

struct leetcode_39 {
    static vector<vector<int32_t>> combinationSum(const vector<int32_t> &candidates, int target);
};

using Catch::Matchers::UnorderedEquals;

TEST_CASE("basic test [test_39]", "[test_39]") {
    const vector<int32_t> candidates{2, 3, 6, 7};
    const static constexpr auto target{7};
    const vector<vector<int32_t>> results{{7},
                                          {2, 2, 3}};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

TEST_CASE("basic test 2[test_39]", "[test_39]") {
    const vector<int32_t> candidates{2, 3, 5};
    const static constexpr auto target{8};
    const vector<vector<int32_t>> results{{2, 3, 3},
                                          {2, 2, 2, 2},
                                          {3, 5}};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

TEST_CASE("basic test 3[test_39]", "[test_39]") {
    const vector<int32_t> candidates{2};
    const static constexpr auto target{1};
    const vector<vector<int32_t>> results{};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

TEST_CASE("basic test 4[test_39]", "[test_39]") {
    const vector<int32_t> candidates{1};
    const static constexpr auto target{1};
    const vector<vector<int32_t>> results{{1}};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

TEST_CASE("basic test 5[test_39]", "[test_39]") {
    const vector<int32_t> candidates{1};
    const static constexpr auto target{2};
    const vector<vector<int32_t>> results{{1, 1}};
    CHECK_THAT(results, UnorderedEquals(leetcode_39::combinationSum(candidates, target)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_39_TEST_HPP

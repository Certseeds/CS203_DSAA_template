// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 双指针
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_989_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_989_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_989 {
using std::vector;

struct leetcode_989 {
    static vector<int32_t> addToArrayForm(const vector<int32_t> &num, int32_t k);
};

using Catch::Matchers::Equals;

TEST_CASE("test case 1 {test_989}", "{test_989}") {
    const vector<int32_t> fst{1, 3, 2, 1};
    static constexpr const auto k{34};
    const vector<int32_t> result{1, 3, 5, 5};
    CHECK_THAT(result, Equals(leetcode_989::addToArrayForm(fst, k)));
}

TEST_CASE("test case 2 {test_989}", "{test_989}") {
    const vector<int32_t> fst{2, 7, 4};
    static constexpr const auto k{181};
    const vector<int32_t> result{4, 5, 5};
    CHECK_THAT(result, Equals(leetcode_989::addToArrayForm(fst, k)));
}

TEST_CASE("test case 3 {test_989}", "{test_989}") {
    const vector<int32_t> fst{2, 1, 5};
    static constexpr const auto k{806};
    const vector<int32_t> result{1, 0, 2, 1};
    CHECK_THAT(result, Equals(leetcode_989::addToArrayForm(fst, k)));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_989_TEST_HPP

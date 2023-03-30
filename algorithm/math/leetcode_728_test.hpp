// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag Math
//@Tag 数学

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_728_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_728_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_728 {

struct leetcode_728 {
    static vector<int32_t> selfDividingNumbers(int32_t left, int32_t right);
};

using Catch::Matchers::Equals;

TEST_CASE("1 [test_728]", "[test_728]") {
    static constexpr const auto left{1}, right{22};
    const vector<int32_t> results{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
    CHECK_THAT(results, Equals(leetcode_728::selfDividingNumbers(left, right)));
}

TEST_CASE("2 [test_728]", "[test_728]") {
    static constexpr const auto left{47}, right{85};
    const vector<int32_t> results{48, 55, 66, 77};
    CHECK_THAT(results, Equals(leetcode_728::selfDividingNumbers(left, right)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_728_TEST_HPP




// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 数学
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1390_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1390_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1390 {

namespace leetcode_1390 {
int32_t sumFourDivisors(const vector<int32_t> &nums);
}

using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1390]", "[test_1390]") {
    const vector<int32_t> input{1, 1, 4, 5, 1, 4};
    constexpr const auto result{0};
    CHECK(result == leetcode_1390::sumFourDivisors(input));
}

TEST_CASE("1-2 [test_1390]", "[test_1390]") {
    const vector<int32_t> input{21, 4, 7};
    constexpr const auto result{32};
    CHECK(result == leetcode_1390::sumFourDivisors(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1390_TEST_HPP


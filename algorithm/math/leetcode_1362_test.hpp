// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 数学
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1362_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1362_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_1362 {
using std::vector;
using std::array;

namespace leetcode_1362 {
array<int64_t, 2> closetDivisors(int64_t num);
}

using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1362]", "[test_1362]") {
    constexpr const auto input{8};
    constexpr const auto m{3}, n{3};
    const std::array<int64_t, 2> result = leetcode_1362::closetDivisors(input);
    constexpr const std::array<int64_t, 2> correct{m, n};
    CHECK(result[0] == m);
    CHECK(result[1] == n);
}
TEST_CASE("1-2 [test_1362]", "[test_1362]") {
    constexpr const auto input{123};
    constexpr const auto m{5}, n{25};
    const std::array<int64_t, 2> result = leetcode_1362::closetDivisors(input);
    constexpr const std::array<int64_t, 2> correct{m, n};
    CHECK(result[0] == m);
    CHECK(result[1] == n);
}
TEST_CASE("1-3 [test_1362]", "[test_1362]") {
    constexpr const auto input{999};
    constexpr const auto m{25}, n{40};
    const std::array<int64_t, 2> result = leetcode_1362::closetDivisors(input);
    constexpr const std::array<int64_t, 2> correct{m, n};
    CHECK(result[0] == m);
    CHECK(result[1] == n);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1362_TEST_HPP


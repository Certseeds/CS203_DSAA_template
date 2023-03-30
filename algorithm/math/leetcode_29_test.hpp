// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_29 {
struct leetcode_29 {
    static int divide(int dividend, int divisor);
};

TEST_CASE("1 [test _29]", "[test _29]") {
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), -1) == std::numeric_limits<int32_t>::max());
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), 1) == std::numeric_limits<int32_t>::min());
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), 2) == -1073741824);
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), -2) == 1073741824);
    CHECK(leetcode_29::divide(10, 3) == 3);
    CHECK(leetcode_29::divide(7, -3) == -2);
    CHECK(leetcode_29::divide(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min()) == 1);
    CHECK(leetcode_29::divide(-1010369383, -2147483648) == 0);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_29_TEST_HPP

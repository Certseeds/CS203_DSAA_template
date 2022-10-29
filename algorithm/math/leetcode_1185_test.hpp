// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022 nanoseeds

*/
//@Tag 常识
//@Tag 暴力
//@Tag 先验知识
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1185_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1185_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_1185 {
using std::vector;

struct leetcode_1185 {
    static string dayOfTheWeek(int32_t day, int32_t month, int32_t year);
};

inline constexpr const std::array<const char *const, 7> weekStrs
        {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

using Catch::Matchers::Equals;

TEST_CASE("1-1 [test_1185]", "[test_1185]") {
    CHECK(weekStrs[5] == leetcode_1185::dayOfTheWeek(1, 1, 1971));
}

TEST_CASE("1-2 [test_1185]", "[test_1185]") {
    CHECK(weekStrs[5] == leetcode_1185::dayOfTheWeek(15, 1, 1971));
}

TEST_CASE("1-3 [test_1185]", "[test_1185]") {
    CHECK(weekStrs[1] == leetcode_1185::dayOfTheWeek(1, 2, 1971));
}

TEST_CASE("2-1 [test_1185]", "[test_1185]") {
    CHECK(weekStrs[6] == leetcode_1185::dayOfTheWeek(31, 8, 2019));
}

TEST_CASE("2-2 [test_1185]", "[test_1185]") {
    CHECK(weekStrs[0] == leetcode_1185::dayOfTheWeek(18, 7, 1999));
}

TEST_CASE("2-3 [test_1185]", "[test_1185]") {
    CHECK(weekStrs[0] == leetcode_1185::dayOfTheWeek(15, 8, 1993));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_1185_TEST_HPP


// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1360_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1360_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_1360 {
using std::vector;
using std::string;

namespace leetcode_1360 {
int32_t daysBetweenDates(const string &date1, const string &date2);
}

using Catch::Matchers::Equals;

TEST_CASE("test case 1-1 {test_1360}", "{test_1360}") {
    constexpr const char *const begin{"2019-06-29"};
    constexpr const char *const end{"2019-06-30"};
    constexpr const int32_t value{1};
    CHECK(value == leetcode_1360::daysBetweenDates(begin, end));
}

TEST_CASE("test case 1-2 {test_1360}", "{test_1360}") {
    constexpr const char *const begin{"2020-01-15"};
    constexpr const char *const end{"2019-12-31"};
    constexpr const int32_t value{15};
    CHECK(value == leetcode_1360::daysBetweenDates(begin, end));
}

TEST_CASE("test case 1-3 {test_1360}", "{test_1360}") {
    constexpr const char *const begin{"1971-06-29"};
    constexpr const char *const end{"2010-09-23"};
    constexpr const int32_t value{14331};
    CHECK(value == leetcode_1360::daysBetweenDates(begin, end));
}

TEST_CASE("test case 1-4 {test_1360}", "{test_1360}") {
    constexpr const char *const begin{"2009-08-18"};
    constexpr const char *const end{"2080-08-08"};
    constexpr const int32_t value{25923};
    CHECK(value == leetcode_1360::daysBetweenDates(begin, end));
}



}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1360_TEST_HPP

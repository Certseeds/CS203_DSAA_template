// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1184_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1184_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_1184 {
using std::vector;
using std::string;

struct leetcode_1184 final {
    static int32_t distanceBetweenBusStops(const vector<int32_t> &distance, int32_t start, int32_t destination);
};

TEST_CASE("test case 1-1 {test_1184}", "{test_1184}") {
    const vector<int32_t> distance{1, 2, 3, 4};
    static constexpr const auto from{0}, to{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_1184::distanceBetweenBusStops(distance, from, to));
}

TEST_CASE("test case 1-2 {test_1184}", "{test_1184}") {
    const vector<int32_t> distance{2, 2, 2, 2, 2};
    static constexpr const auto from{0}, to{2};
    static constexpr const auto result{4};
    CHECK(result == leetcode_1184::distanceBetweenBusStops(distance, from, to));
}

TEST_CASE("test case 1-3 {test_1184}", "{test_1184}") {
    const vector<int32_t> distance{0, 0, 0, 0, 1};
    static constexpr const auto from{0}, to{4};
    static constexpr const auto result{0};
    CHECK(result == leetcode_1184::distanceBetweenBusStops(distance, from, to));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1184_TEST_HPP

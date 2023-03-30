// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag associative_container
//@Tag xor
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_961_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_961_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_961 {
using std::array;
using std::vector;

struct leetcode_961 {
    static int32_t repeatedNTimes(const vector<int32_t> &nums);
};

TEST_CASE("test case 1 {test_961}", "{test_961}") {
    static constexpr const std::array<int32_t, 4> arr{
            1, 2, 3, 3
    };
    static constexpr const auto result{3};
    CHECK(result == leetcode_961::repeatedNTimes({arr.cbegin(), arr.cend()}));
}

TEST_CASE("test case 2 {test_961}", "{test_961}") {
    static constexpr const std::array<int32_t, 10> arr{
            1, 0, 4, 4, 4, 4, 4, 5, 1, 4
    };
    static constexpr const auto result{4};
    CHECK(result == leetcode_961::repeatedNTimes({arr.cbegin(), arr.cend()}));
}

TEST_CASE("test case 3 {test_961}", "{test_961}") {
    static constexpr const std::array<int32_t, 10> arr{
            1, 9, 2, 9, 8, 9, 3, 9, 0, 9
    };
    static constexpr const auto result{9};
    CHECK(result == leetcode_961::repeatedNTimes({arr.cbegin(), arr.cend()}));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ASSOCIATIVE_CONTAINER_LEETCODE_961_TEST_HPP

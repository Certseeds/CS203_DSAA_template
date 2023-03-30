// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_944_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_944_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

namespace leetcode_944 {
using std::vector;
using std::string;

struct leetcode_944 {
    static int minDeletionSize(const vector<string> &A);
};

TEST_CASE("test case 1 {test_944}", "{test_944}") {
    static constexpr const std::array<const char *const, 3> input{
            "abc", "bce", "cae"
    };
    static constexpr const auto result{1};
    CHECK(result == leetcode_944::minDeletionSize({input.begin(), input.end()}));
}

TEST_CASE("test case 2 {test_944}", "{test_944}") {
    static constexpr const std::array<const char *const, 2> input{
            "a", "b"
    };
    static constexpr const auto result{0};
    CHECK(result  == leetcode_944::minDeletionSize({input.begin(), input.end()}));
}
TEST_CASE("test case 3 {test_944}", "{test_944}") {
    static constexpr const std::array<const char *const, 3> input{
            "zyx", "wvu", "tsr"
    };
    static constexpr const auto result{3};
    CHECK(result == leetcode_944::minDeletionSize({input.begin(), input.end()}));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_944_TEST_HPP

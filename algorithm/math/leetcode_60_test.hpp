// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_TEST_HPP

#include <catch_main.hpp>
#include <cassert>
#include <cstdint>

namespace leetcode_60 {
struct leetcode_60 {
    static string getPermutation(int32_t n, int32_t k);

    static string getPermutation_rec_out(int32_t n, int32_t k);
};

TEST_CASE("1 [test_60]", "[test_60]") {
    static constexpr const auto n{3}, k{3};
    static constexpr const char *const result{"213"};
    CHECK(result == leetcode_60::getPermutation(n, k));
    CHECK(result == leetcode_60::getPermutation_rec_out(n, k));
}

TEST_CASE("2 [test_60]", "[test_60]") {
    static constexpr const auto n{4}, k{9};
    static constexpr const char *const result{"2314"};
    CHECK(result == leetcode_60::getPermutation(n, k));
    CHECK(result == leetcode_60::getPermutation_rec_out(n, k));
}

TEST_CASE("3 [test_60]", "[test_60]") {
    static constexpr const auto n{3}, k{1};
    static constexpr const char *const result{"123"};
    CHECK(result == leetcode_60::getPermutation(n, k));
    CHECK(result == leetcode_60::getPermutation_rec_out(n, k));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_60_TEST_HPP


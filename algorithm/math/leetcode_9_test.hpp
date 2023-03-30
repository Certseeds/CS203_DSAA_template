// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_9_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_9_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_9 {
struct leetcode_9 {
    static bool isPalindrome(int32_t x);
};


TEST_CASE("test case 1 [test_9]", "[test_9]") {
    static constexpr const auto input{121};
    CHECK(leetcode_9::isPalindrome(input));
}

TEST_CASE("test case 2 [test_9]", "[test_9]") {
    static constexpr const auto input{-121};
    CHECK_FALSE(leetcode_9::isPalindrome(input));
}

TEST_CASE("test case 3 [test_9]", "[test_9]") {
    static constexpr const auto input{120};
    CHECK_FALSE(leetcode_9::isPalindrome(input));
}

TEST_CASE("test case 4 [test_9]", "[test_9]") {
    static constexpr const auto input{10};
    CHECK_FALSE(leetcode_9::isPalindrome(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_9_TEST_HPP

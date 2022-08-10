// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1108_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1108_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>

namespace leetcode_1108 {

struct leetcode_1108 final {
    static string defangIPaddr(const string &address);
};

TEST_CASE("test case 1-1 {test_1108}", "{test_1108}") {
    static constexpr const char *const input{"1.1.1.1"};
    static constexpr const char *const result{"1[.]1[.]1[.]1"};
    CHECK(result == leetcode_1108::defangIPaddr(input));
}

TEST_CASE("test case 1-2 {test_1108}", "{test_1108}") {
    static constexpr const char *const input{"255.100.50.0"};
    static constexpr const char *const result{"255[.]100[.]50[.]0"};
    CHECK(result == leetcode_1108::defangIPaddr(input));
}

TEST_CASE("test case 1-3 {test_1108}", "{test_1108}") {
    static constexpr const char *const input{"114.141.91.8"};
    static constexpr const char *const result{"114[.]141[.]91[.]8"};
    CHECK(result == leetcode_1108::defangIPaddr(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_1108_TEST_HPP

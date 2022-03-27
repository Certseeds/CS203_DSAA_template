// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag list
//@Tag 链表

#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <string>

namespace leetcode_43 {
struct leetcode_43 {
    static string multiply(const string &num1, const string &num2);
};

TEST_CASE("1 [test _43]", "[test _43]") {
    const string num1{"9"};
    const string num2{"9"};
    const string result{"81"};
    CHECK(result == leetcode_43::multiply(num1, num2));
}

TEST_CASE("2 [test _43]", "[test _43]") {
    const string num1{"2"};
    const string num2{"3"};
    const string result{"6"};
    CHECK(result == leetcode_43::multiply(num1, num2));
}

TEST_CASE("3 [test _43]", "[test _43]") {
    const string num1{"123"};
    const string num2{"456"};
    const string result{"56088"};
    CHECK(result == leetcode_43::multiply(num1, num2));
}

TEST_CASE("4 [test _43]", "[test _43]") {
    const string num1{"114514"};
    const string num2{"1919810"};
    const string result{"219845122340"};
    CHECK(result == leetcode_43::multiply(num1, num2));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_43_TEST_HPP

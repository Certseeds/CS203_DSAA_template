// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag array
//@Tag 数组
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_806_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_806_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <array>

namespace leetcode_806 {
using std::vector;
using std::array;

struct leetcode_806 {
    static vector<int32_t> numberOfLines(const vector<int32_t> &widths, const string &s);
};
using Catch::Matchers::Equals;

TEST_CASE("test case 1 [test_806]", "[test_806]") {
    static constexpr const std::array<int32_t, 26> inputs{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                                          10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                                          10, 10, 10};
    static constexpr const char *const str{"abcdefghijklmnopqrstuvwxyz"};
    static constexpr const auto begin{3}, end{60};
    CHECK_THAT(
            (vector<int32_t>{begin, end}),
            Equals(leetcode_806::numberOfLines({inputs.begin(), inputs.end()}, str))
    );
}

TEST_CASE("test case 2 [test_806]", "[test_806]") {
    static constexpr const std::array<int32_t, 26> inputs{4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                                                          10, 10, 10};
    static constexpr const char *const str{"bbbcccdddaaa"};
    static constexpr const auto begin{2}, end{4};
    CHECK_THAT(
            (vector<int32_t>{begin, end}),
            Equals(leetcode_806::numberOfLines({inputs.begin(), inputs.end()}, str))
    );
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_ARRAY_LEETCODE_806_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 动态规划入门 Day11
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_TEST_HPP

#include <catch_main.hpp>
#include <unordered_map>

namespace leetcode_96 {

using std::unordered_map;

struct leetcode_96 {
    static int32_t numTrees(int32_t n);

    static int32_t numTreesConstexpr(int32_t n);
};


TEST_CASE("test_case 1 [test_96]", "[test_96]") {
    static constexpr const auto input{1};
    static constexpr const auto result{1};
    CHECK(result == leetcode_96::numTrees(input));
    CHECK(result == leetcode_96::numTreesConstexpr(input));
}

TEST_CASE("test_case 2 [test_96]", "[test_96]") {
    static constexpr const auto input{3};
    static constexpr const auto result{5};
    CHECK(result == leetcode_96::numTrees(input));
    CHECK(result == leetcode_96::numTreesConstexpr(input));
}

TEST_CASE("test_case 3 [test_96]", "[test_96]") {
    static constexpr const auto input{19};
    static constexpr const auto result{1767263190};
    CHECK(result == leetcode_96::numTrees(input));
    CHECK(result == leetcode_96::numTreesConstexpr(input));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_96_TEST_HPP

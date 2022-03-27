// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag DFS
//@Tag 深度优先遍历
//@Plan 剑指OfferII-I Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_12_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_12_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <vector>

namespace leetcode_so_12 {
using std::vector;

struct leetcode_so_12 {
    static bool exist(const vector<vector<char>> &board, const string &word);
};

TEST_CASE("basic tests [test_so_12]", "[test_so_12]") {
    const vector<vector<char>> input{
            {'a', 'b', 'c', 'e'},
            {'s', 'f', 'c', 's'},
            {'a', 'd', 'e', 'e'},
    };
    static constexpr const char *const word{"abcced"};
    CHECK(leetcode_so_12::exist(input, word));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_GRAPH_LEETCODE_SO_12_TEST_HPP

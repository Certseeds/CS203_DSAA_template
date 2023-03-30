// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1104_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1104_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_1104 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_1104 final {
    static vector<int32_t> pathInZigZagTree(int32_t label);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_1104]", "[test_1104]") {
    static constexpr const auto input{14};
    const vector<int32_t> output{1, 3, 4, 14};
    CHECK_THAT(output, Equals(leetcode_1104::pathInZigZagTree(input)));
}

TEST_CASE("test_case 2 [test_1104]", "[test_1104]") {
    static constexpr const auto input{26};
    const vector<int32_t> output{1, 2, 6, 10, 26};
    CHECK_THAT(output, Equals(leetcode_1104::pathInZigZagTree(input)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1104_TEST_HPP

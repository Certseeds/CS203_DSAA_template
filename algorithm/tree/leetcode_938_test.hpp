// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_938_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_938_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_938 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_938 final {
    static int32_t rangeSumBST(TreeNode *root, int32_t low, int32_t high);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_938]", "[test_938]") {
    const TreeNodeLink input{
            10,
            5, 15,
            3, 7, TreeNode::No, 18
    };
    static constexpr const auto low{7}, high{15};
    static constexpr const auto result{32};
    CHECK(result == leetcode_938::rangeSumBST(input[0], low, high));
}

TEST_CASE("test_case 2 [test_938]", "[test_938]") {
    const TreeNodeLink input{
            10,
            5, 15,
            3, 7, 13, 18,
            1, TreeNode::No, 6
    };
    static constexpr const auto low{6}, high{10};
    static constexpr const auto result{23};
    CHECK(result == leetcode_938::rangeSumBST(input[0], low, high));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_938_TEST_HPP

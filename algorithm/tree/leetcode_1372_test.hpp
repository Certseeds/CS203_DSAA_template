// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1372_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1372_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_1372 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;


namespace leetcode_1372 {
int32_t longestZigZag(TreeNode *root);
}

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_1372]", "[test_1372]") {
    const TreeNodeLink vec2{
            1,
            TreeNode::No, 1,
            TreeNode::No, TreeNode::No, 1, 1,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 1,
    };
    TreeNode node2{1}, node3{1};
    vec2[13]->right = &node2;
    node2.right = &node3;
    CHECK(3 == leetcode_1372::longestZigZag(vec2[0]));
}

TEST_CASE("test_case 2 [test_1372]", "[test_1372]") {
    const TreeNodeLink vec2{1};
    CHECK(0 == leetcode_1372::longestZigZag(vec2[0]));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1372_TEST_HPP

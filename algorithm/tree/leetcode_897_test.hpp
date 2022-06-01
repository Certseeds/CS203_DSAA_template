// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_897_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_897_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_897 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_897 final {
    static TreeNode *increasingBST(TreeNode *root);
};


using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_897]", "[test_897]") {
    const TreeNodeLink input{
            5,
            3, 6,
            2, 4, TreeNode::No, 8,
            1, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 7, 9
    };
    const auto *node = leetcode_897::increasingBST(input[0]);
    const vector<int32_t> nodes{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (const auto va: nodes) {
        CHECK(node->val == va);
        CHECK(node->left == nullptr);
        node = node->right;
    }
}

TEST_CASE("test_case 2 [test_897]", "[test_897]") {
    const TreeNodeLink input{
            5,
            1, 7
    };
    const auto *node = leetcode_897::increasingBST(input[0]);
    const vector<int32_t> nodes{1, 5, 7};
    for (const auto va: nodes) {
        CHECK(node->val == va);
        CHECK(node->left == nullptr);
        node = node->right;
    }
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_897_TEST_HPP

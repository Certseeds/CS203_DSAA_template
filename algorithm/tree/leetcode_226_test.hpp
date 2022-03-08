// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Sword-Offer 27
//@Plan 数据结构入门 Day12
//@Plan 剑指OfferII-I Day07
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_226_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_226_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_226 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_226 {
    static TreeNode *invertTree(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_226]", "[test_226]") {
    const vector<int32_t> input{4, 2, 7, 1, 3, 6, 9};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    leetcode_226::invertTree(numVecInput[0]);
    const vector<int32_t> result{4, 7, 2, 9, 6, 3, 1, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
                                 TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No};
    CHECK(TREE_NODE::judge_equal(numVecInput.front(), result));
    const TreeNodeLink link{numVecInput.front()};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_226_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1325_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1325_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_1325 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

namespace leetcode_1325 {
TreeNode *removeLeafNodesRec(TreeNode *root, int32_t target);


TreeNode *removeLeafNodesIter(TreeNode *root, int32_t target);
}

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_1325]", "[test_1325]") {
    const TreeNodeLink input{
            1,
            1, 4,
            5, 1, TreeNode::No, 4,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 9,
    };
    const auto root{input[0]};
    constexpr const auto target{1};
    const auto outputRec = leetcode_1325::removeLeafNodesRec(root, target);
    const vector<int32_t> result{
            1,
            1, 4,
            5, TreeNode::No, TreeNode::No, 4,
            TreeNode::No, TreeNode::No,/*TreeNode::No, TreeNode::No,TreeNode::No, TreeNode::No,*/ TreeNode::No, 9,
            TreeNode::No, TreeNode::No,
    };
    CHECK(TREE_NODE::judge_equal(outputRec, result));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1325_TEST_HPP

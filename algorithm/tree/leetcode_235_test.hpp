// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day14
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_235_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_235_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_235 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_235 {
    static bool findTarget(TreeNode *root, int k);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_235]", "[test_235]") {
    const vector<int32_t> input{5,
                                3, 6,
                                2, 4, TreeNode::No, 7,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
                                TreeNode::No, TreeNode::No};
    vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput.front()};
    static constexpr const auto target{9};
    CHECK(leetcode_235::findTarget(numVecInput.front(), target));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_235_TEST_HPP

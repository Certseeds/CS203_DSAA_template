// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day11
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <stack>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_104 {

using std::stack;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

struct leetcode_104 {
    static int32_t maxDepth(TreeNode *root);
};

TEST_CASE("test_case 1 [test_104]", "[test_104]") {
    const vector<int32_t> vec{3, 9, 20, TreeNode::No, TreeNode::No, 15, 7};
    static constexpr const auto result{3};
    vector<TreeNode *> numVec = numToTree<int32_t>(vec);
    CHECK(result == leetcode_104::maxDepth(numVec[0]));
    const TreeNodeLink link{numVec[0]};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_104_TEST_HPP

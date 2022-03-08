// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_236_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_236_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_236 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_236 {
    static const TreeNode *lowestCommonAncestor(const TreeNode *root, const TreeNode *p, const TreeNode *q);
};


using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_236]", "[test_236]") {
    const vector<int32_t> input{3,
                                5, 1,
                                6, 2, 0, 8,
                                TreeNode::No, TreeNode::No, 7, 4};
    const TreeNode p{5}, q{1};
    static constexpr const auto result{3};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput.front()};
    CHECK(result == leetcode_236::lowestCommonAncestor(numVecInput.front(), &p, &q)->val);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_236_TEST_HPP

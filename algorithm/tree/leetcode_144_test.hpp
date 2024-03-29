// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
//@description 中序遍历
//@Plan 数据结构入门 Day10
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_144_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_144_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_144 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_144 {
    static vector<int32_t> preorderTraversal(TreeNode *root);

    static vector<int32_t> preorderTraversalIter(TreeNode *root);
};

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_144]", "[test_144]") {
    const TreeNodeLink input{4,
                                2, 7,
                                1, 3, TreeNode::No, TreeNode::No,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<int32_t> result{4, 2, 1, 3, 7};
    CHECK_THAT(result, Equals(leetcode_144::preorderTraversal(input[0])));
    CHECK_THAT(result, Equals(leetcode_144::preorderTraversalIter(input[0])));
}

TEST_CASE("test_case 2 [test_144]", "[test_144]") {
    const TreeNodeLink input{4,
                                2, 7,
                                1, 3, 5, TreeNode::No,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<int32_t> result{4, 2, 1, 3, 7, 5};
    CHECK_THAT(result, Equals(leetcode_144::preorderTraversal(input[0])));
    CHECK_THAT(result, Equals(leetcode_144::preorderTraversalIter(input[0])));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_144_TEST_HPP

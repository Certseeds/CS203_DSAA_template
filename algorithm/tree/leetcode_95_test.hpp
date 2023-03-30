// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_TEST_HPP

#include <catch_main.hpp>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>
#include <stack>

namespace leetcode_95 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

struct leetcode_95 {
    static vector<TreeNode *> generateTrees(int32_t n);
};

TEST_CASE("test_case 1 [test_95]", "[test_95]") {
    const auto three = leetcode_95::generateTrees(0);
    CHECK_THAT(three, Equals<TreeNode *>({}));
    const TreeNodeLink link1{three};
}

TEST_CASE("test_case 2 [test_95]", "[test_95]") {
    const vector<vector<int32_t>> result{
            {1, TreeNode::No, 2,            TreeNode::No, 3,            TreeNode::No, TreeNode::No},
            {1, TreeNode::No, 3,            2,            TreeNode::No, TreeNode::No, TreeNode::No},
            {2, 1,            3,            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No},
            {3, 1,            TreeNode::No, TreeNode::No, 2,            TreeNode::No, TreeNode::No},
            {3, 2,            TreeNode::No, 1,            TreeNode::No, TreeNode::No, TreeNode::No},
    };
    const auto three = leetcode_95::generateTrees(3);
    static constexpr const auto length{5};
    CHECK(length == three.size());
    for (int32_t i{0}; i < length; ++i) {
        CHECK(TREE_NODE::judge_equal(three[i], result[i]));
    }
    for (const auto &node: three) {
        TreeNodeLink{node}; // just for invoke ~
    }
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_95_TEST_HPP

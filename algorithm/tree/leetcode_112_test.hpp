// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
//@description 中序遍历
//@Plan 数据结构入门 Day12
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_112_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_112_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_112 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_112 {
    static bool hasPathSum(TreeNode *root, int targetSum);
};

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_112]", "[test_112]") {
    const vector<int32_t> input{5,
                                4, 8,
                                11, TreeNode::No, 13, 4,
                                7, 2, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1
    };
    static constexpr const auto target{22};
    const vector<TreeNode *> numVecInput = TREE_NODE::numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput[0]};
    CHECK(leetcode_112::hasPathSum(numVecInput[0], target));
}

TEST_CASE("test_case 2 [test_112]", "[test_112]") {
    const vector<int32_t> input{1,
                                2, 3};
    static constexpr const auto target{5};
    const vector<TreeNode *> numVecInput = TREE_NODE::numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput[0]};
    CHECK_FALSE(leetcode_112::hasPathSum(numVecInput[0], target));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_112_TEST_HPP

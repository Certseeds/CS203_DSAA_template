// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_872_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_872_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_872 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_872 final {
    static bool leafSimilar(TreeNode *root1, TreeNode *root2);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_872]", "[test_872]") {
    const TreeNodeLink input1{3,
                              5, 1,
                              6, 2, 9, 8,
                              TreeNode::No, TreeNode::No, 7, 4
    };
    const TreeNodeLink input2{3,
                              5, 1,
                              6, 7, 4, 2,
                              TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 9, 8
    };
    CHECK(leetcode_872::leafSimilar(input1[0], input2[0]));
}

TEST_CASE("test_case 2 [test_872]", "[test_872]") {
    const TreeNodeLink input1{1, 2, 3};
    const TreeNodeLink input2{1, 3, 2};
    CHECK_FALSE(leetcode_872::leafSimilar(input1[0], input2[0]));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_872_TEST_HPP

// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Tag in-traverse
//@Tag 中序遍历二叉树
//@Same 783
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_530 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_530 {
    static int32_t getMinimumDifference(TreeNode *root);

    static int32_t getMinimumDifference2(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_530]", "[test_530]") {
    const TreeNodeLink input{4, 2, 6, 1, 3};
    static constexpr const auto result{1};
    THEN("case 1") {
        CHECK(result == leetcode_530::getMinimumDifference(input[0]));
    }THEN("case 2") {
        CHECK(result == leetcode_530::getMinimumDifference2(input[0]));
    }
}

TEST_CASE("test_case 2 [test_530]", "[test_530]") {
    const TreeNodeLink input{1, 0, 48, TreeNode::No, TreeNode::No, 12, 49};
    static constexpr const auto result{1};
    THEN("case 1") {
        CHECK(result == leetcode_530::getMinimumDifference(input[0]));
    }THEN("case 2") {
        CHECK(result == leetcode_530::getMinimumDifference2(input[0]));
    }
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP

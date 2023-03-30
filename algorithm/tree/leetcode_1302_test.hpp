// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1302_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1302_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <memory>

namespace leetcode_1302 {
using TreeNode = TREE_NODE::TreeNode<int32_t>;

namespace leetcode_1302 {
int32_t deepestLeavesSumRec(TreeNode *root);
int32_t deepestLeavesSumIter(TreeNode *root);
}

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1 [test_1302]", "[test_1302]") {
    const TreeNodeLink input{
            1,
            1, 4,
            5, 1, TreeNode::No, 4,
            TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 1, 9
    };
    const auto root{input[0]};
    const auto outputRec = leetcode_1302::deepestLeavesSumRec(root);
    const auto outputIter = leetcode_1302::deepestLeavesSumRec(root);
    constexpr const auto result{10};
    CHECK(outputRec == result);
    CHECK(outputIter == result);
}

TEST_CASE("test_cas 2 [test_1302]", "[test_1302]") {
    const TreeNodeLink input{
            1,
            1, 4,
            5, 1, TreeNode::No, 4,
            1, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, 9
    };
    const auto root{input[0]};
    const auto outputRec = leetcode_1302::deepestLeavesSumRec(root);
    const auto outputIter = leetcode_1302::deepestLeavesSumIter(root);
    constexpr const auto result{10};
    CHECK(outputRec == result);
    CHECK(outputIter == result);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_1302_TEST_HPP

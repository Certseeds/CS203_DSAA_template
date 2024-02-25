// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag tree
//@Tag 树
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
namespace leetcode_235 {
    const TreeNode *lowestCommonAncestor(const TreeNode *root, const TreeNode *p, const TreeNode *q);
    const TreeNode *lowestCommonAncestorV2(TreeNode *root, TreeNode *p, TreeNode *q);
};


using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_235]", "[test_235]") {
    const TreeNodeLink input{6,
                             2, 8,
                             0, 4, 7, 9,
                             TreeNode::No, TreeNode::No, 3, 5};
    const TreeNode p{2}, q{8};
    static constexpr const auto result{6};
    CHECK(result == leetcode_235::lowestCommonAncestor(input[0], &p, &q)->val);
    CHECK(result == leetcode_235::lowestCommonAncestorV2(input[0], input[1], input[2])->val);
}
TEST_CASE("test_case 2 [test_235]", "[test_235]") {
    const TreeNodeLink input{2,
                             1};
    const TreeNode p{1}, q{2};
    static constexpr const auto result{2};
    CHECK(result == leetcode_235::lowestCommonAncestor(input[0], &p, &q)->val);
    CHECK(result == leetcode_235::lowestCommonAncestorV2(input[0], input[0], input[1])->val);
}

TEST_CASE("test_case 3 [test_235]", "[test_235]") {
    const TreeNodeLink input{6,
                             2, 8,
                             0, 4, 7, 9,
                             TreeNode::No, TreeNode::No, 3, 5};
    TreeNode p{2}, q{4};
    static constexpr const auto result{2};
    CHECK(result == leetcode_235::lowestCommonAncestor(input[0], &p, &q)->val);
    CHECK(result == leetcode_235::lowestCommonAncestorV2(input[0], input[1], input[4])->val);
}
TEST_CASE("test_case 4 [test_235]", "[test_235]") {
    const TreeNodeLink input{5,
                             3, 6,
                             2, 4,TreeNode::No, TreeNode::No,
                             1};
    TreeNode p{1}, q{3};
    static constexpr const auto result{3};
    CHECK(result == leetcode_235::lowestCommonAncestor(input[0], &p, &q)->val);
    CHECK(result == leetcode_235::lowestCommonAncestorV2(input[0], input[7], input[1])->val);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_235_TEST_HPP

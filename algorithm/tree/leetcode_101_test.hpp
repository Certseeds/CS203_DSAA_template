// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Sword-Offer 28
//@Plan 数据结构入门 Day11
//@Plan 剑指OfferII-I Day07
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_101_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_101_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_101 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_101 {
    static bool isSymmetric(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_101]", "[test_101]") {
    const TreeNodeLink vec{1,
                           2, 2,
                           3, 4, 4, 3};
    CHECK(leetcode_101::isSymmetric(vec[0]));
}

TEST_CASE("test_case 2 [test_101]", "[test_101]") {
    const TreeNodeLink vec{1,
                           2, 2,
                           TreeNode::No, 3, TreeNode::No, 3};
    CHECK_FALSE(leetcode_101::isSymmetric(vec[0]));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_101_TEST_HPP

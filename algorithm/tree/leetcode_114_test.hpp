// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
//@description 先序遍历
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_114_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_114_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_114 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_114 {
    static void flatten(TreeNode *root);
};

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_114]", "[test_114]") {
    const TreeNodeLink input{1,
                             2, 5,
                             3, 4, TreeNode::No, 6
    };
    leetcode_114::flatten(input[0]);
    CHECK(1 == input[0]->val);
    CHECK(2 == input[0]->right->val);
    CHECK(3 == input[0]->right->right->val);
    CHECK(4 == input[0]->right->right->right->val);
    CHECK(5 == input[0]->right->right->right->right->val);
    CHECK(6 == input[0]->right->right->right->right->right->val);
}

TEST_CASE("test_case 2 [test_114]", "[test_114]") {
    leetcode_114::flatten(nullptr);
}

TEST_CASE("test_case 3 [test_114]", "[test_114]") {
    const TreeNodeLink input{0};
    leetcode_114::flatten(input[0]);
    CHECK(0 == input[0]->val);
    CHECK(nullptr == input[0]->right);
    CHECK(nullptr == input[0]->left);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_114_TEST_HPP

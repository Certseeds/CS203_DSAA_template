// SPDX-License-Identifier: MIT
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
    const vector<int32_t> input{1,
                                2, 5,
                                3, 4, TreeNode::No, 6
    };
    const vector<TreeNode *> numVecInput = TREE_NODE::numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput};
    leetcode_114::flatten(numVecInput.front());
    CHECK(1 == numVecInput[0]->val);
    CHECK(2 == numVecInput[0]->right->val);
    CHECK(3 == numVecInput[0]->right->right->val);
    CHECK(4 == numVecInput[0]->right->right->right->val);
    CHECK(5 == numVecInput[0]->right->right->right->right->val);
    CHECK(6 == numVecInput[0]->right->right->right->right->right->val);
}

TEST_CASE("test_case 2 [test_114]", "[test_114]") {
    leetcode_114::flatten(nullptr);
}

TEST_CASE("test_case 3 [test_114]", "[test_114]") {
    const vector<int32_t> input{0};
    const vector<TreeNode *> numVecInput = TREE_NODE::numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput};
    leetcode_114::flatten(numVecInput.front());
    CHECK(0 == numVecInput[0]->val);
    CHECK(nullptr == numVecInput[0]->right);
    CHECK(nullptr == numVecInput[0]->left);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_114_TEST_HPP

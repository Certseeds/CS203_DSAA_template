// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_543_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_543_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_543 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_543 {
    static int32_t diameterOfBinaryTree(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_543]", "[test_543]") {
    const vector<int32_t> input{4, 2, 6, 1, 3};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    static constexpr const auto result{3};
    const TreeNodeLink link{numVecInput.front()};
    CHECK(result == leetcode_543::diameterOfBinaryTree(numVecInput.front()));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_543_TEST_HPP

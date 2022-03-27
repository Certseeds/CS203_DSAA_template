// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 剑指OfferII-I Day06
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_32_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_32_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_so_32 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_so_32 final {
    static vector<int32_t> levelOrderFst(TreeNode *root);

    // static vector<int> levelOrderSnd(TreeNode *root); // same with 102
    static vector<vector<int32_t>> levelOrderTrd(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;
using Catch::Matchers::Equals;

TEST_CASE("test_case 1-1 [test_so_32]", "[test_so_32]") {
    const TreeNodeLink input{3,
                                9, 20,
                                TreeNode::No, TreeNode::No, 15, 7,};
    const vector<int32_t> results{3, 9, 20, 15, 7};
    CHECK_THAT(results, Equals(leetcode_so_32::levelOrderFst(input[0])));
}

TEST_CASE("test_case 3-1 [test_so_32]", "[test_so_32]") {
    const TreeNodeLink input{3,
                                9, 20,
                                TreeNode::No, TreeNode::No, 15, 7,};
    const vector<vector<int32_t>> results{{3},
                                          {20, 9},
                                          {15, 7}};
    CHECK_THAT(results, Equals(leetcode_so_32::levelOrderTrd(input[0])));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_SO_32_TEST_HPP

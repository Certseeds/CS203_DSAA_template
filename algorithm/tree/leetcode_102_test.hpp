// SPDX-License-Identifier: MIT
/*
CS203_DSAA_template

Copyright (C) 2020-2022 nanoseeds

*/
//@Tag tree
//@Tag 树
//@Sword-Offer 32-II
//@Plan 数据结构入门 Day11
//@Plan 剑指OfferII-I Day06
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_102 {

using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_102 {
    static vector<vector<int>> levelOrder(TreeNode *root);
};

using Catch::Matchers::Equals;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("test_case 1 [test_102]", "[test_102]") {
    const TreeNodeLink vec{3,
                           9, 20,
                           TreeNode::No, TreeNode::No, 15, 7};
    const vector<vector<int32_t>> result{{3},
                                         {9,  20},
                                         {15, 7}};
    CHECK_THAT(result, Equals(leetcode_102::levelOrder(vec[0])));
}

TEST_CASE("test_case 2 [test_102]", "[test_102]") {
    const TreeNodeLink vec{1};
    const vector<vector<int32_t>> result{{1},};
    CHECK_THAT(result, Equals(leetcode_102::levelOrder(vec[0])));
}

TEST_CASE("test_case 3 [test_102]", "[test_102]") {
    const vector<vector<int32_t>> result{};
    CHECK_THAT(result, Equals(leetcode_102::levelOrder(nullptr)));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_102_TEST_HPP

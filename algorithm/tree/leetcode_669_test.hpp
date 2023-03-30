// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022  nanoseeds

*/
//@Tag tree
//@Tag 树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_669_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_669_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_669 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_669 final {
    static TreeNode *trimBST(TreeNode *root, int L, int R);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_669]", "[test_669]") {
    const TreeNodeLink input{1, 0, 2};
    const vector<int32_t> result{1,
                                 TreeNode::No, 2,
                                 TreeNode::No, TreeNode::No
    };
    auto *const resultPtr = leetcode_669::trimBST(input[0], 1, 2);
    CHECK(TREE_NODE::judge_equal(resultPtr, result));
}

}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_669_TEST_HPP

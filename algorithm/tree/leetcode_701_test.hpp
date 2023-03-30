// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2022-2023  nanoseeds

*/
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day13
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_701_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_701_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_701 {
using std::vector;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_701 final {
    static TreeNode *insertIntoBST(TreeNode *root, int32_t val);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_701]", "[test_701]") {
    const vector<int32_t> input{4,
                                2, 7,
                                1, 3, TreeNode::No, TreeNode::No,
                                TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    static constexpr const auto newV{5};
    const vector<int32_t> result{4,
                                 2, 7,
                                 1, 3, 5, TreeNode::No,
                                 TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No,
    };
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput[0]};
    CHECK(TREE_NODE::judge_equal(leetcode_701::insertIntoBST(numVecInput[0], newV), result));
}

TEST_CASE("test_case 2 [test_701]", "[test_701]") {
    static constexpr const auto newV{5};
    const vector<int32_t> output{5, TreeNode::No, TreeNode::No};
    const TreeNode *const result = leetcode_701::insertIntoBST(nullptr, newV);
    const TreeNodeLink link{const_cast<TreeNode *>(result)};
    CHECK(TREE_NODE::judge_equal(const_cast<TreeNode *>(result), output));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_701_TEST_HPP

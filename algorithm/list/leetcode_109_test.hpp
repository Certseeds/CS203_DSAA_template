// SPDX-License-Identifier: AGPL-3.0-or-later
/*
CS203_DSAA_template

Copyright (C) 2020-2023 nanoseeds

*/
//@Tag list
//@Tag 链表
//@Tag 二叉树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_109_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_109_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <list/listnode.hpp>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_109 {
using LISTNODE::ListNode;
using TreeNode = TREE_NODE::TreeNode<int32_t>;

struct leetcode_109 {
    static TreeNode *sortedListToBST(ListNode *head);
};

using LISTNODE::ListNodeLink;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

TEST_CASE("-1 [test _109]", "[test _109]") {
    const ListNodeLink vec1{-10, -3, 0, 5, 9};
    const vector<int32_t> output{0,
                                 -3, 9,
                                 -10, TreeNode::No, 5, TreeNode::No,
                                 TreeNode::No, TreeNode::No, TreeNode::No, TreeNode::No};
    const TreeNode *const result = leetcode_109::sortedListToBST(vec1[0]);
    const TreeNodeLink link{const_cast<TreeNode *>(result)};
    CHECK(TREE_NODE::judge_equal(const_cast<TreeNode *>(result), output));
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_109_TEST_HPP

/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2022  nanoseeds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//@Tag list
//@Tag 链表
//@Tag 二叉树
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_109_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_109_HPP

#include <catch_main.hpp>
#include <list/ListNode.hpp>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>

namespace leetcode_109 {
using LISTNODE::ListNode;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;

struct leetcode_109 {
    static TreeNode *sortedListToBST(ListNode *head);
};

using LISTNODE::ListNodeLink;

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
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_109_HPP

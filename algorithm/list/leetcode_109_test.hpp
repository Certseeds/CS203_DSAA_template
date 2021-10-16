/*
MIT License

CS203_DSAA_template

Copyright (C) 2020-2021  nanoseeds

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
#include <ListNode.hpp>
#include <TreeNode.hpp>

namespace leetcode_109 {
using LISTNODE::ListNode;
using TreeNode = TREE_NODE::TreeNode<int32_t>;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

struct leetcode_109 {
    static TreeNode *sortedListToBST(ListNode *head);
};

using LISTNODE::ListNodeLink;

TEST_CASE("-1 [test _109]", "[test _109]") {
    const ListNodeLink vec1{-10, -3, 0, 5, 9};
    const TreeNode *const result = leetcode_109::sortedListToBST(vec1[0]);
    CHECK(result->val == 0);
    CHECK(result->left->val == -3);
    CHECK(result->right->val == 9);
    CHECK(result->left->left->val == -10);
    CHECK(result->right->left->val == 5);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_LIST_LEETCODE_109_HPP

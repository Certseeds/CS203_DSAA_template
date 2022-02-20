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
//@Tag tree
//@Tag 树
//@Plan 数据结构入门 Day14
//@Plan 剑指OfferII-I Day15
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_426_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_426_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <vector>

namespace leetcode_426 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;
using Node = TreeNode;

struct leetcode_426 {
    static Node *treeToDoublyList(Node *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_426]", "[test_426]") {
    const vector<int32_t> input{4, 2, 5, 1, 3};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    const TreeNodeLink link{numVecInput};
    leetcode_426::treeToDoublyList(numVecInput.front());
    CHECK(3 == numVecInput[0]->left->val);
    CHECK(5 == numVecInput[0]->right->val);
    CHECK(1 == numVecInput[1]->left->val);
    CHECK(3 == numVecInput[1]->right->val);
    CHECK(4 == numVecInput[2]->left->val);
    CHECK(1 == numVecInput[2]->right->val);
    CHECK(5 == numVecInput[3]->left->val);
    CHECK(2 == numVecInput[3]->right->val);
    CHECK(2 == numVecInput[4]->left->val);
    CHECK(4 == numVecInput[4]->right->val);
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_426_TEST_HPP

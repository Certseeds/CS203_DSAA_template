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
//@Tag in-traverse
//@Tag 中序遍历二叉树
//@Same 783
#ifndef CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP
#define CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP

#include <catch_main.hpp>
#include <cstdint>
#include <cstddef>
#include <tree/treenode.hpp>
#include <tree/treenode_link.hpp>
#include <stack>

namespace leetcode_530 {

using TreeNode = TREE_NODE::TreeNode<int32_t>;
using std::stack;

struct leetcode_530 {
    static int32_t getMinimumDifference(TreeNode *root);

    static int32_t getMinimumDifference2(TreeNode *root);
};

using TreeNodeLink = TREE_NODE::TreeNodeLink<int32_t>;
using TREE_NODE::numToTree;

TEST_CASE("test_case 1 [test_530]", "[test_530]") {
    const vector<int32_t> input{4, 2, 6, 1, 3};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    static constexpr const auto result{1};
    THEN("case 1") {
        CHECK(result == leetcode_530::getMinimumDifference(numVecInput[0]));
    }THEN("case 2") {
        CHECK(result == leetcode_530::getMinimumDifference2(numVecInput[0]));
    }
    const TreeNodeLink link{numVecInput.front()};
}

TEST_CASE("test_case 2 [test_530]", "[test_530]") {
    const vector<int32_t> input{1, 0, 48, TreeNode::No, TreeNode::No, 12, 49};
    const vector<TreeNode *> numVecInput = numToTree<int32_t>(input);
    static constexpr const auto result{1};
    THEN("case 1") {
        CHECK(result == leetcode_530::getMinimumDifference(numVecInput[0]));
    }THEN("case 2") {
        CHECK(result == leetcode_530::getMinimumDifference2(numVecInput[0]));
    }
    const TreeNodeLink link{numVecInput.front()};
}
}
#endif //CS203_DSAA_TEMPLATE_ALGORITHM_TREE_LEETCODE_530_TEST_HPP
